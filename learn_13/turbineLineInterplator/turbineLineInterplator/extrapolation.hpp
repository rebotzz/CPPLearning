#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <unordered_map>
#include <iomanip>
//#include <locale>							// 编码问题,windows默认使用ANSI编码,与UTF8转化
#include <xlnt/xlnt.hpp>					// 这个会与别的头文件(第三方库)冲突,放在最开始
#include <boost/math/interpolators/barycentric_rational.hpp>
#include <boost/math/tools/roots.hpp>
#include "mytools.hpp"

#undef max
#undef min
using std::cin;
using std::cout;
using std::cerr;
using std::wcout;
using std::endl;
using std::vector;
using std::string;
using std::wstring;
using std::move;

namespace TCLExtra
{
	// 常数定义
	#define M_PI 3.14159265358979323846
	static const double PI = acos(-1.0);			// 圆周率Π
	static const double g_adiabaticIndex = 1.667;	// 绝热指数 暂定1.667
	static size_t g_precision = 10;					// 输出数据保留精度

	// 转速为speed的特性线
	class TurbineCharLine
	{
	public:
		vector<double> _flows;						// 流量	
		vector<double> _efficiencies;				// 效率
		vector<double> _pressRatios;				// 压比
		double _speed = 0.0;						// 转速
		double _surge_flow = 0.0;					// 喘震流量
		double _surge_efficiencies = 0.0;			// 喘震效率
		double _surge_pressure_ratio = 0.0;			// 喘震压比
	};

	// 不同转速speed的特性线
	class MultiTurbineCharLine
	{
	private:
		typedef boost::math::interpolators::barycentric_rational<double> Interpolator;
	private:
		//public:
			// todo待优化: 每个特性线自变量都是flows, 都一样,数据冗余
		vector<TurbineCharLine> _tclines;							// 已知数据,已有的特性线
		double _speed_design = 0.0;									// 设计转速
		string _preRotation = "预旋";

		std::shared_ptr<Interpolator> _surge_speedRatio_flow_ptr;	// 插值得到:(运行速度/设计速度)-喘震流量
		std::shared_ptr<Interpolator> _surge_flow_pressRatio_ptr;	// 插值得到:喘震流量-喘震压比
		std::shared_ptr<Interpolator> _surge_flow_efficiency_ptr;	// 插值得到:喘震流量-喘震效率
		vector<TurbineCharLine> _tclines_new;						// 插值推演:新的特性线

	public:
		enum DrawGraphOption
		{
			FLOW = 1,
			PRESS = 2,
			EFFICIENT = 4
		};

	public:
		MultiTurbineCharLine(double speed_design = 8000, int length = 800) : _speed_design(speed_design)
		{}

		void setSpeedDesign(double speed_design) { _speed_design = speed_design; }
		vector<TurbineCharLine>& getTClines() { return _tclines; }
		vector<TurbineCharLine>& getTClinesNew() { return _tclines_new; }
		string& preRotation() { return _preRotation; }


		// todo: 求解堵塞(喘震)边界线 涡轮部分; 搁浅...,没有理论指导
		void getSurgeLineT()
		{}

		// 求解堵塞(喘震)边界线	压气机部分
		void getSurgeLineP()
		{
			// 求解不同转速的特性线喘震点
			vector<double> surge_flows, surge_press_ratios, surge_efficiencies, surge_speedRatio;
			for (auto& charline : _tclines) {
				// 理论来自:[径流式叶轮机械理论及设计-杨策]:P223
				// 假定喘震流量为:压比-流量线斜率为零的点 
				// 对每一条特性线插值,求斜率为0的点
				auto& x_values = charline._flows;
				auto& y_values_press = charline._pressRatios;
				auto& y_values_eff = charline._efficiencies;

				auto getdfRoots = [&charline](Interpolator& inter)->double {
					// 二分查找根 f`(x)的根
					auto df = [&inter](double x) {return inter.prime(x); };
					// 因为这里流量(自变量)单调递增
					double min = charline._flows[0], max = charline._flows.back();
					// 这里需要小心给定区间没有根,或者精度问题
					auto tol = [](double left, double right) { return abs(left - right) < 1e-4; }; // 精度
					std::pair<double, double> root;
					try { root = boost::math::tools::bisect(df, min, max, tol); }
					catch (const std::exception& e) {
						LOG(WARING, "求根出错, 速度: " + std::to_string(charline._speed) + "\n" + e.what() + "\n");
						return 0.0;
					}
					catch (...) { LOG(WARING, "求根出错"); return 0.0;}

					// 这里df单调,只有一个根
					return root.first;
					};

				// 插值得到流量-压比,流量-效率关系 f(x)
				Interpolator interPress(x_values.begin(), x_values.end(), y_values_press.begin());
				Interpolator interEff(x_values.begin(), x_values.end(), y_values_eff.begin());

				// 流量-压比:斜率为零的点->喘震点
				// 暂定:只用求流量-压比极值点就够了, 得到喘震流量, 然后插值得到喘震效率; 如果求流量-效率极值点,可能流量不匹配
				charline._surge_flow = getdfRoots(interPress);	// 给定区间找不到根,则为0
				if (charline._surge_flow != 0) {
					charline._surge_pressure_ratio = interPress(charline._surge_flow);
					charline._surge_efficiencies = interEff(charline._surge_flow);
				}

				// 剔除无效点
				if (charline._surge_flow != 0) {
					surge_flows.push_back(charline._surge_flow);
					surge_press_ratios.push_back(charline._surge_pressure_ratio);
					surge_efficiencies.push_back(charline._surge_efficiencies);
					surge_speedRatio.push_back(charline._speed / _speed_design);
				}
			}

			// 插值得到喘震线上: 喘震流量-喘震压比, 喘震流量-喘震效率, 速比(运行速度/设计速度)-喘震流量
			std::shared_ptr<Interpolator> surge_flow_press(new Interpolator(surge_flows.begin(), surge_flows.end(), surge_press_ratios.begin()));
			std::shared_ptr<Interpolator> surge_flow_efficiency(new Interpolator(surge_flows.begin(), surge_flows.end(), surge_efficiencies.begin()));
			std::shared_ptr<Interpolator> surge_speedRatio_flow(new Interpolator(surge_speedRatio.begin(), surge_speedRatio.end(), surge_flows.begin()));
			_surge_flow_pressRatio_ptr = surge_flow_press;
			_surge_flow_efficiency_ptr = surge_flow_efficiency;
			_surge_speedRatio_flow_ptr = surge_speedRatio_flow;
		}

		// 外推转速speed_new对应的特性线
		// 理论: [航空发动机高精度建模及起动性能仿真研究-高楚铭]:P45
		TurbineCharLine& extrapolation(double speed_new, double usersest_speed_ref = 0.0)
		{
			// 选那个转速特性线作为基准?
			// plan: 1.设计转速特性线(舍弃)  2.以速度最邻近的特性线
			int ref = _tclines.size() / 2;
			double gap = abs(_tclines[0]._speed - _tclines.back()._speed + 1);
			for (int i = 0; i < _tclines.size(); ++i) {
				if (abs(speed_new - _tclines[i]._speed) < gap && _tclines[i]._surge_flow != 0) {
					gap = abs(speed_new - _tclines[i]._speed);
					ref = i;
				}
			}

			// 用户自定义基准线
			if (usersest_speed_ref != 0.0) {
				double gap = abs(_tclines[0]._speed - _tclines.back()._speed + 1);
				for (int i = 0; i < _tclines.size(); ++i) {
					if (abs(usersest_speed_ref - _tclines[i]._speed) < gap && _tclines[i]._surge_flow != 0) {
						gap = abs(usersest_speed_ref - _tclines[i]._speed);
						ref = i;
					}
				}
			}

			LOG(NOTICE, "待求速度: " + std::to_string(int(speed_new)) + "-->外推基准特性线速度: " + std::to_string(int(_tclines[ref]._speed)));

			// 初始化
			_tclines_new.push_back(TurbineCharLine());
			auto& tcline = _tclines_new.back();	// 需要外推的特性线
			size_t size = _tclines[ref]._flows.size();
			tcline._flows.resize(size);
			tcline._pressRatios.resize(size);
			tcline._efficiencies.resize(size);
			tcline._speed = speed_new;

			auto& tcline_ref = _tclines[ref];
			double speed_ref = tcline_ref._speed;
			double surge_pressure_ratio_ref = tcline_ref._surge_pressure_ratio;
			double surge_flow_ref = tcline_ref._surge_flow;
			double surge_efficiency_ref = tcline_ref._surge_efficiencies;
			double adiabaticIndex = g_adiabaticIndex;	// 绝热指数

			// todo: 验证这里正确性
			// 利用喘震点插值得到的关系 -> 求新的转速对应的喘震点
			// f(x): (运行速度/设计速度)速比-喘震流量 喘震流量-喘震压比 喘震流量-喘震效率
			// 流量flows, 压比pressure_ratio, 效率efficiencies 
			double surge_flow_new = _surge_speedRatio_flow_ptr->operator()(speed_new / _speed_design);	// debug: 这里速比是new/design
			double surge_pressure_ratio_new = _surge_flow_pressRatio_ptr->operator()(surge_flow_new);
			double surge_efficiency_new = _surge_flow_efficiency_ptr->operator()(surge_efficiency_ref);
			tcline._surge_flow = surge_flow_new;
			tcline._surge_pressure_ratio = surge_pressure_ratio_new;
			tcline._surge_efficiencies = surge_efficiency_new;

			// 求插值的比例系数
			double speed_ratio = speed_new / speed_ref;		// 这里是与参数速度(基准)之比
			double indexFlow = getIndexFlow(surge_flow_new, surge_flow_ref, speed_ratio);
			double indexPressureRatio = getIndexPressureRatio(surge_pressure_ratio_new, surge_pressure_ratio_ref, speed_ratio, adiabaticIndex);
			double indexEfficient = getIndexEfficiency(surge_efficiency_new, surge_efficiency_ref, speed_ratio);

			// 相似理论外推转速speed_new对应的特性线
			double flow_similar = pow(speed_ratio, indexFlow);
			double pressRatio_similar = pow(speed_ratio, indexPressureRatio);
			double efficiencie_similar = pow(speed_ratio, indexEfficient);
			double ks = (adiabaticIndex - 1) / adiabaticIndex, kb = adiabaticIndex / (adiabaticIndex - 1);
			for (int i = 0; i < size; ++i) {
				tcline._flows[i] = tcline_ref._flows[i] * flow_similar;
				tcline._pressRatios[i] = pow(1 + (pow(tcline_ref._pressRatios[i], ks) - 1) * pressRatio_similar, kb);
				tcline._efficiencies[i] = tcline_ref._efficiencies[i] * efficiencie_similar;
			}

			return tcline;
		}

		// 其余曲线绘制: x-y关系曲线
		static void drawGraph(const vector<vector<double>>& arrxs, const vector<vector<double>>& arrys, const vector<wstring>& comment, wstring outfile, int length = 800)
		{
			// 绘制曲线
			Coordinate _coord(length);
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			double minx = arrxs[0][0], miny = arrys[0][0];
			double maxx = minx, maxy = miny;
			for (const auto& arr : arrxs) {
				for (const auto& e : arr) {
					minx = std::min(e, minx);
					maxx = std::max(e, maxx);
				}
			}
			for (const auto& arr : arrys) {
				for (const auto& e : arr) {
					miny = std::min(e, miny);
					maxy = std::max(e, maxy);
				}
			}

			_coord.setxScope(minx, maxx);
			_coord.setyScope(miny, maxy);
			_coord.drawCoordinate();
			int n = arrxs.size();
			for (int i = 0; i < n; ++i) {
				_coord.drawLine(arrxs[i], arrys[i], comment[i]);
			}

			if (outfile.find(L"./outdata/") == wstring::npos) outfile = L"./outdata/" + outfile;
			if (outfile.find(L".jpg") == wstring::npos) outfile += L".jpg";
			saveimage(outfile.c_str());
			LOG(NOTICE, "保存图片: " + wstring2string(outfile));
			_coord.closeGraph();
		}

		// 流量-压比 or 流量-效率
		void drawGraph(int option = FLOW | PRESS, std::wstring outfile = L"", bool pause = false, int length = 800)
		{
			// 绘制曲线
			Coordinate _coord(length);

			// 绘制原本的特性线
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			double minx = _tclines[0]._flows[0], maxx = _tclines[0]._flows[0];
			for (auto& charline : _tclines) {
				minx = std::min(minx, charline._flows[0]);
				maxx = std::max(maxx, charline._flows.back());
			}
			_coord.setxScope(minx, maxx);

			bool press = false, effi = false;

			if (outfile.find(L"./outdata/image/") == wstring::npos) outfile = L"./outdata/image/" + outfile;
			std::wstring imagename = outfile;

			if ((option & FLOW) && (option & PRESS)) {
				_coord.setyScope(1, 3);	// 压比范围大概 1 ~ 3	
				press = true;
				imagename += L"流量-压比.jpg";
			}
			else if ((option & FLOW) && (option & EFFICIENT)) {
				_coord.setyScope(0, 1);	// 效率范围大概 0 ~ 1
				effi = true;
				imagename += L"流量-效率.jpg";
			}
			else {
				LOG(WARING, "选项错误");
				throw std::invalid_argument("选项错误, 示范:todo...");
			}

			_coord.drawCoordinate();
			for (auto& charline : _tclines) {
				std::wstring s = L"速度:";
				s += std::to_wstring(int(charline._speed));
				if (press) _coord.drawLine(charline._flows, charline._pressRatios, s);
				if (effi) _coord.drawLine(charline._flows, charline._efficiencies, s);
			}

			// 绘制喘震边界线
			vector<double> surgeX, surgeY;
			for (auto& charline : _tclines) {
				if (charline._surge_flow != 0) {	// 跳过没找到的喘震点
					surgeX.push_back(charline._surge_flow);
					if (press) surgeY.push_back(charline._surge_pressure_ratio);
					if (effi) surgeY.push_back(charline._surge_efficiencies);
				}
			}
			_coord.drawLine(surgeX, surgeY, L"喘震边界线");

			if (pause) system("pause");
			// 绘制相似理论外推特性线
			for (auto& charline : _tclines_new) {
				std::wstring s = L"外推速度:";
				s += std::to_wstring(int(charline._speed));
				if (press) _coord.drawLine(charline._flows, charline._pressRatios, s);
				if (effi) _coord.drawLine(charline._flows, charline._efficiencies, s);
			}

			if (pause) system("pause");
			saveimage(imagename.c_str());
			LOG(NOTICE, "保存图片: " + wstring2string(imagename));
			_coord.closeGraph();
		}

		// 检查误差
		void checkExtraError(string outfile = "")
		{
			// todo:剔除待验证速度拟合的喘震点
			getSurgeLineP();

			// 抽查一半, 用相邻上一个转速外推 
			vector<int> checkarr;
			for (int i = 0; i < _tclines.size() - 1; i += 2) {
				double speed_new = _tclines[i]._speed;
				double speed_ref = _tclines[i + 1]._speed;
				extrapolation(speed_new, speed_ref);
				checkarr.push_back(i);
			}

			// 检验误差
			struct ERR {
				vector<double> _errp;
				vector<double> _erre;
				vector<double> _arrx;
				double _id;
			};
			vector<ERR> errs;
			int extraid = 0;
			for (auto i : checkarr) {
				errs.push_back(ERR());
				auto& err = errs.back();				// 误差
				auto& extra = _tclines_new[extraid++];	// 外推的
				auto& origin = _tclines[i];				// 原来的
				err._id = origin._speed;
				// 因为外推的流量与原始不同,所以需要插值
				Interpolator interp(extra._flows.begin(), extra._flows.end(), extra._pressRatios.begin());
				Interpolator intere(extra._flows.begin(), extra._flows.end(), extra._efficiencies.begin());
				err._arrx = extra._flows;
				size_t n = err._arrx.size();
				err._errp.resize(n);
				err._erre.resize(n);
				for (int j = 0; j < n; ++j) {
					double x = origin._flows[j];
					double yp = origin._pressRatios[j], ye = origin._pressRatios[j];
					err._errp[j] = abs(interp(x) - yp) / yp;
					err._erre[j] = abs(intere(x) - ye) / ye;
				}
			}

			// 数据持久化
			string oldname = outfile;
			if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
			std::ofstream output(outfile + "误差校验.txt", std::ios::trunc | std::ios::binary);
			output << u8"外插原有数据校验误差\n";
			if (output.is_open()) {
				for (auto& err : errs) {
					output << u8"外插速度: " << err._id << endl;
					output << u8"流量:\n";
					for (auto x : err._arrx) output << std::setprecision(g_precision) << x << "\t"; output << endl;
					output << u8"压比相对误差:\n";
					for (auto y : err._errp) output << std::setprecision(g_precision) << y << "\t"; output << endl;
					output << u8"效率相对误差:\n";
					for (auto y : err._erre) output << std::setprecision(g_precision) << y << "\t"; output << endl;
					output << "\n";
				}
				output.close();
				LOG(NOTICE, "保存文件: " + outfile + "误差校验.txt");
			}

			// 图片持久化
			vector<vector<double>> arrxs, arryes, arryps;
			vector<wstring> msg;
			for (auto& err : errs) {
				arrxs.push_back(std::move(err._arrx));
				arryes.push_back(std::move(err._erre));
				arryps.push_back(std::move(err._errp));
				msg.push_back(L"转速:" + std::to_wstring(err._id));
			}

			outfile = oldname;
			if (outfile.find("./outdata/image/") == string::npos) outfile = "./outdata/image/" + outfile;
			std::wstring file = string2wstring(outfile);
			drawGraph(arrxs, arryps, msg, file + L"流量-压比相对误差.jpg");
			drawGraph(arrxs, arryes, msg, file + L"流量-效率相对误差.jpg");
			LOG(NOTICE, "校验误差完成,数据持久化完成.");
			// 清除校验数据
			_tclines_new.clear();
		}

		void readDataFromFile(std::ifstream& input, bool check = false)
		{
			if (!input.is_open()) {
				LOG(FATAL, "文件打开失败");
				return;
			}
			string beginLine, tmp;
			while (std::getline(input, beginLine))	// 规定只要还有新的一行,那么就有完整的数据: 小心多余回车
			{
				if (beginLine[0] == '\t') {			// 结尾标志,为了兼容excel粘贴到记事本
					break;
				}

				// 插入新的一组数据
				_tclines.push_back(TurbineCharLine());
				auto& flows = _tclines.back()._flows;
				auto& efficiencies = _tclines.back()._efficiencies;
				auto& pressRatios = _tclines.back()._pressRatios;
				auto& speed = _tclines.back()._speed;
				std::istringstream issbegin(beginLine);
				issbegin >> speed;

				// 开辟空间
				int count = 0;
				for (char ch : beginLine) {
					if (ch == '\t') count++;
				}
				vector<double> arr1(count), arr2(count), arr3(count);
				std::unordered_map<std::string, std::vector<double>*> hash;

				// 读取数据
				// 协议定制: 质量流量,效率和压比(膨胀比)使用区分"flow","efficiency","pressRatio"
				input >> tmp;
				for (auto& e : arr1) input >> e;
				hash[tmp] = &arr1;
				input >> tmp;
				for (auto& e : arr2) input >> e;
				hash[tmp] = &arr2;
				input >> tmp;
				for (auto& e : arr3) input >> e;
				hash[tmp] = &arr3;
				std::getline(input, beginLine);		// 读取剩余的 "\n"

				if (hash.count("flow") && hash.count("efficiency") && hash.count("pressRatio")) {
					flows.swap(*hash["flow"]);
					efficiencies.swap(*hash["efficiency"]);
					pressRatios.swap(*hash["pressRatio"]);
				}
				else {
					LOG(FATAL, "质量流量,效率和压比命名不对.正确协议名: flow,efficiency,pressRatio");
					return;
				}

				// 检查读取
				if (check) {
					cout << "转速: " << speed << endl;
					cout << "流量: ";
					for (auto x : flows) cout << x << " ";
					cout << endl;
					cout << "效率: ";
					for (auto x : efficiencies) cout << x << " ";
					cout << endl;
					cout << "压比/膨胀比: ";
					for (auto x : pressRatios) cout << x << " ";
					cout << endl;
					cout << endl << "------------------------------" << endl;
				}
			}
			if(check) cout << "\n\n";
		}

		void saveFile(std::ofstream& output)
		{
			if (!output.is_open()) {
				LOG(ERR, "文件打开失败");
				return;
			}

			output << _preRotation << endl;
			output << u8"原始数据计算[喘震点]: " << endl;
			output << u8"转速:\t";
			for (auto& e : _tclines) output << e._speed << "\t"; output << endl;
			output << u8"喘震流量:\t";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_flow << "\t"; output << endl;
			output << u8"喘震压比: ";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_pressure_ratio << "\t"; output << endl;
			output << u8"喘震效率: ";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_efficiencies << "\t"; output << endl;
			output << u8"tip:舍弃喘震流量为0的点" << endl;
			output << "\n";

			output << u8"\n外推结果[喘震点]:\n";
			output << u8"转速: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._speed << "\t"; output << endl;
			output << u8"喘震流量: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_flow << "\t"; output << endl;
			output << u8"喘震压比: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_pressure_ratio << "\t"; output << endl;
			output << u8"喘震效率: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_efficiencies << "\t"; output << endl;

			output << u8"\n外推结果[特性线]:\n";
			for (auto& charline : _tclines_new) {
				output << u8"转速: " << charline._speed << endl;
				output << u8"流量: ";
				for (auto& e : charline._flows) output << std::setprecision(g_precision) << e << "\t"; output << endl;
				output << u8"压比: ";
				for (auto& e : charline._pressRatios) output << std::setprecision(g_precision) << e << "\t"; output << endl;
				output << u8"效率: ";
				for (auto& e : charline._efficiencies) output << std::setprecision(g_precision) << e << "\t"; output << endl;
			}
			output << "\n\n";
		}

		int saveExcelFile(xlnt::workbook& wb, int beginRow = 1, bool save = false, string outfile = "./outdata/outcome.xlsx")
		{
			xlnt::worksheet ws = wb.active_sheet();
			int row = std::max(beginRow, 1);
			for (auto& charline : _tclines_new) {
				int n = charline._flows.size();
				string str = "speed:" + std::to_string(int(charline._speed));
				ws.cell(1, row).value(str);
				// 中文需要设置utf8编码
				ws.cell(1, row + 1).value(u8"流量");		// "flow"
				ws.cell(1, row + 2).value(u8"效率");		// "efficiency"
				ws.cell(1, row + 3).value(u8"压比");		// "pressRatio"

				for (int col = 0; col < n; ++col) {
					ws.cell(col + 2, row + 1).value(charline._flows[col]);	// [列, 行]
					ws.cell(col + 2, row + 2).value(charline._efficiencies[col]);
					ws.cell(col + 2, row + 3).value(charline._pressRatios[col]);
				}
				row += 4;
			}

			if (save) {
				if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
				wb.save(outfile);
				LOG(NOTICE, "保存文件: " + outfile);
			}
			return row;		// 下一次存储数据起始行
		}

		// 协议:一组4行数据 speed flow efficiency pressRatio 多组间不带空行; 不同预旋用不同sheet区分,sheet命名为预旋大小
		// 为了兼容为了excel高版本,可以将数据拷贝到xlnt生成的表格下, 且不要图片,只要存粹数据; 
		// 为了避免乱码,使用英文; 新增:中文支持
		void readDataFromExcel(string file, bool check = false)
		{
			xlnt::workbook wb;
			try { wb.load(file); }
			catch (const std::exception&) { LOG(FATAL, "遵守协议:使用纯净的excel表格,参考example.xlsx"); throw; }
			catch (...) { throw; }
			xlnt::worksheet ws = wb.active_sheet();
			readDataFromExcel(ws, check);
		}
		void readDataFromExcel(xlnt::workbook& wb, bool check = false)
		{
			xlnt::worksheet ws = wb.active_sheet();
			readDataFromExcel(ws, check);
		}
		void readDataFromExcel(const xlnt::worksheet& ws, bool check = false)
		{
			_preRotation = ws.title();
			for (const xlnt::cell_vector& cells : ws) {
				auto itcell = cells.begin();
				auto& cellbegin = *itcell;
				if (cellbegin.has_value() == false) break;	// 空,结束

				TurbineCharLine* charline = nullptr;
				if (_tclines.size() != 0) charline = &_tclines.back();
				string tmp = cellbegin.to_string();
				if (tmp.find("speed") != string::npos || tmp.find(u8"转速") != string::npos) {
					// 有一组数据,开辟空间
					_tclines.push_back(TurbineCharLine());
					std::stringstream ss(tmp);
					ss >> _tclines.back()._speed;
					continue;
				}
				else if (tmp.find("flow") != string::npos || tmp.find(u8"流量") != string::npos) {
					int i = 0;	// 跳过首个标记字符
					for (auto& cell : cells) {
						if (i++) charline->_flows.push_back(std::stod(cell.to_string()));
					}
				}
				else if (tmp.find("efficiency") != string::npos || tmp.find(u8"效率") != string::npos) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++) charline->_efficiencies.push_back(std::stod(cell.to_string()));
					}
				}
				else if (tmp.find("pressRatio") != string::npos || tmp.find(u8"压比") != string::npos) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++) charline->_pressRatios.push_back(std::stod(cell.to_string()));
					}
				}
				else {
					LOG(FATAL, "格式错误, 遵守协议,参考example.xlsx");
					return;
				}
			}

			if (check) {
				for (auto& tcline : _tclines) {
					cout << "转速: " << tcline._speed << endl;
					cout << "流量: ";
					for (auto x : tcline._flows) cout << x << " ";
					cout << endl;
					cout << "效率: ";
					for (auto x : tcline._efficiencies) cout << x << " ";
					cout << endl;
					cout << "压比/膨胀比: ";
					for (auto x : tcline._pressRatios) cout << x << " "; /*printf("%.7lf ", x);*/
					cout << endl;
					cout << endl << "------------------------------" << endl;
				}
			}
		}

	private:
		// 流量的相似关系系数
		double getIndexFlow(double flow_new, double flow_ref, double speed_ratio)
		{
			return log(flow_new / flow_ref) / log(speed_ratio);
		}

		// 压比的相似关系系数
		double getIndexPressureRatio(double pressure_ratio_new, double pressure_ratio_ref, double speed_ratio, double adiabaticIndex)
		{
			double k = (adiabaticIndex - 1) / adiabaticIndex;
			double tmp1 = pow(pressure_ratio_new, k) - 1;
			double tmp2 = pow(pressure_ratio_ref, k) - 1;
			return log(tmp1 / tmp2) / log(speed_ratio);
		}

		// 效率的相似关系系数
		double getIndexEfficiency(double efficiency_new, double efficiency_ref, double speed_ratio)
		{
			return log(efficiency_new / efficiency_ref) / log(speed_ratio);
		}
	};


	class MultiTurbineCharLine_PreRotations
	{
	private:
		vector<MultiTurbineCharLine> _mtcls;
		double _speed_design = 0.0;
	public:
		MultiTurbineCharLine_PreRotations(double speed_design) :_speed_design(speed_design)
		{}
		vector<MultiTurbineCharLine>& getMultiTurbineCharLines() { return _mtcls; }

		// 待外推速度
		void solution(vector<double> speeds = vector<double>(), string outfile = "./outdata/outcome", bool check = false)
		{
			if (check) cout << "不同预选组数:" << _mtcls.size() << endl;
			if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
			std::ofstream output(outfile + ".txt", std::ios::trunc | std::ios::binary);
			xlnt::workbook wb;
			int beginrow = 1;
			for (auto& mtl : _mtcls) {
				mtl.getSurgeLineP();

				if (check) {
					cout << endl << endl;
					cout << "转速: ";
					for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
					cout << "喘震流量: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
					cout << "喘震压比: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
					cout << "喘震效率: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;
				}

				// 外推新转速的特性线
				for (auto speed : speeds) {
					mtl.extrapolation(speed);
				}

				wstring img = utf8_to_wstring(mtl.preRotation());
				mtl.drawGraph(3, img);	// 流量-压比
				mtl.drawGraph(5, img);	// 流量-效率
				//system("pause");

				xlnt::worksheet ws = wb.active_sheet();
				ws.cell(1, beginrow++).value(mtl.preRotation());
				beginrow = mtl.saveExcelFile(wb, beginrow) + 1;
				mtl.saveFile(output);
				cout << endl;
			}
			output.close();
			wb.save(outfile + ".xlsx");
			LOG(NOTICE, "保存文件: " + outfile);
		}

		void readDataFromFile(string file, bool check = false)
		{
			std::ifstream input(file.c_str());
			string tmp;
			while (std::getline(input, tmp)) {
				if (check) cout << "----预旋转: " << utf8_to_ansi(tmp) << endl;

				_mtcls.push_back(MultiTurbineCharLine(_speed_design));
				auto& tclines = _mtcls.back();
				auto pos = tmp.find("\t");
				tclines.preRotation() = tmp.substr(0, pos);
				tclines.readDataFromFile(input, check);
			}
			input.close();
		}

		void readDataFromExcel(string file, bool check = false)
		{
			xlnt::workbook wb;
			try { wb.load(file); }
			catch (const std::exception&) { LOG(FATAL, "遵守协议:使用纯净的excel表格,参考example.xlsx"); throw; }
			catch (...) {throw;}

			for (const xlnt::worksheet& ws : wb)
			{
				_mtcls.push_back(MultiTurbineCharLine(_speed_design));
				auto& tclines = _mtcls.back();
				tclines.preRotation() = ws.title();
				if (check) cout << "----预旋转: " << utf8_to_ansi(ws.title()) << endl;
				tclines.readDataFromExcel(ws, check);
			}
		}

		void checkExtraError()
		{
			for (auto& tclines : _mtcls) {
				tclines.checkExtraError(tclines.preRotation());
				cout << endl;
			}
		}

	private:
		// todo...
	};
}

