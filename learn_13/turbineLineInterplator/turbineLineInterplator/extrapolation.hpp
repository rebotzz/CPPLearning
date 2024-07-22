//#pragma execution_character_set("utf-8")	// 麻烦,算了
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
//#include <locale>
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

	// 转速为speed的特性线
	class TurbineCharLine
	{
	public:
		vector<double> _flows;						// 流量	
		vector<double> _efficiencies;				// 效率
		vector<double> _pressure_ratios;			// 压比
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

		// 求解堵塞(喘震)边界线
		void getSurgeLine()
		{
			// 求解不同转速的特性线喘震点
			vector<double> surge_flows, surge_press_ratios, surge_efficiencies, surge_speedRatio;
			for (auto& charline : _tclines) {
				// 理论来自:[径流式叶轮机械理论及设计-杨策]:P223
				// 假定喘震流量为:压比-流量线斜率为零的点 
				// 对每一条特性线插值,求斜率为0的点
				auto& x_values = charline._flows;
				auto& y_values_press = charline._pressure_ratios;
				auto& y_values_eff = charline._efficiencies;

				auto getdfRoots = [&charline](Interpolator& inter)->double {
					// 二分查找根 f`(x)的根
					auto df = [&inter](double x) {return inter.prime(x); };
					// 因为这里流量(自变量)单调递增
					double min = charline._flows[0], max = charline._flows.back();
					// 这里需要小心给定区间没有根,或者精度问题
					auto tol = [](double left, double right) { return abs(left - right) < 1e-4; }; // 精度
					std::pair<double, double> root;
					try
					{
						root = boost::math::tools::bisect(df, min, max, tol);
					}
					catch (const std::exception& e)
					{
						LOG("求根出错, 速度: " + std::to_string(charline._speed));
						cout << e.what() << endl;
						return 0.0;
					}
					catch (...)
					{
						LOG("求根出错");
						throw;
					}

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
		TurbineCharLine& extrapolation(double speed_new, bool setbase = false, double usersest_speed_ref = 0.0)
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
			if (setbase) {
				double gap = abs(_tclines[0]._speed - _tclines.back()._speed + 1);
				for (int i = 0; i < _tclines.size(); ++i) {
					if (abs(usersest_speed_ref - _tclines[i]._speed) < gap && _tclines[i]._surge_flow != 0) {
						gap = abs(usersest_speed_ref - _tclines[i]._speed);
						ref = i;
					}
				}
			}

			cout << "待求速度: " << speed_new << "-->外推基准特性线速度: " << _tclines[ref]._speed << endl;

			// 初始化
			_tclines_new.push_back(TurbineCharLine());
			auto& tcline = _tclines_new.back();	// 需要外推的特性线
			size_t size = _tclines[ref]._flows.size();
			tcline._flows.resize(size);
			tcline._pressure_ratios.resize(size);
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
			double pressure_ratios_similar = pow(speed_ratio, indexPressureRatio);
			double efficiencie_similar = pow(speed_ratio, indexEfficient);
			double ks = (adiabaticIndex - 1) / adiabaticIndex, kb = adiabaticIndex / (adiabaticIndex - 1);
			for (int i = 0; i < size; ++i) {
				tcline._flows[i] = tcline_ref._flows[i] * flow_similar;
				tcline._pressure_ratios[i] = pow(1 + (pow(tcline_ref._pressure_ratios[i], ks) - 1) * pressure_ratios_similar, kb);
				tcline._efficiencies[i] = tcline_ref._efficiencies[i] * efficiencie_similar;
			}

			return tcline;
		}

		// 其余曲线绘制: x-y关系曲线
		static void drawGraphLine(const vector<double>& arrx, const vector<double>& arry, wstring comment, bool save = false, int length = 800)
		{
			// 绘制曲线
			Coordinate _coord(length);
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			double minx = arrx[0], miny = arry[0];
			double maxx = minx, maxy = miny;
			for (const auto& e : arrx) {
				minx = std::min(e, minx);
				maxx = std::max(e, maxx);
			}
			for (const auto& e : arry) {
				miny = std::min(e, miny);
				maxy = std::max(e, maxy);
			}

			_coord.setxScope(minx, maxx);
			_coord.setyScope(miny, maxy);
			_coord.drawCoordinate();
			_coord.drawLine(arrx, arry, comment);

			if (save) {
				std::wstring buff(comment);
				buff += L".jpg";
				saveimage(buff.c_str());
				_coord.closeGraph();
			}
		}

		// 流量-压比 or 流量-效率
		void drawGraph(DrawGraphOption coordx = FLOW, DrawGraphOption coordy = PRESS, std::wstring filename = L"", bool pause = false, int length = 800)
		{
			// 绘制曲线
			Coordinate _coord(length);

			// 绘制原本的特性线
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			_coord.setxScope(_tclines[0]._flows[0], _tclines[0]._flows.back());

			bool press = false, effi = false;
			std::wstring imagename = L"./outdata/image/";
			imagename += filename;

			switch (coordx) {
			case FLOW: 
				break;
			case PRESS:
				break;
			case EFFICIENT:
				break;
			default:
				break;
			}

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
				LOG("选项错误");
				throw std::invalid_argument("选项错误, 示范:todo...");
			}

			_coord.drawCoordinate();
			for (auto& charline : _tclines) {
				std::wstring s = L"速度:";
				s += std::to_wstring(int(charline._speed));
				if (press) _coord.drawLine(charline._flows, charline._pressure_ratios, s);
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
				if (press) _coord.drawLine(charline._flows, charline._pressure_ratios, s);
				if (effi) _coord.drawLine(charline._flows, charline._efficiencies, s);
			}

			if (pause) system("pause");
			saveimage(imagename.c_str());
			LOG("保存图片: " + wstring2string(imagename));
			_coord.closeGraph();
		}



		void readDataFromFile(std::ifstream& input, bool check = false, bool isturb = false)
		{
			if (!input.is_open()) {
				LOG("文件打开失败");
				return;
			}
			string beginLine, tmp;
			while (std::getline(input, beginLine))	// 规定只要还有新的一行,那么就有完整的数据: 小心多余回车
			{
				if (beginLine[0] == '\t') {	// 结尾标志,为了兼容excel粘贴到记事本
					break;
				}

				// 插入新的一组数据
				_tclines.push_back(TurbineCharLine());
				auto& flows = _tclines.back()._flows;
				auto& efficiencies = _tclines.back()._efficiencies;
				auto& pressure_ratios = _tclines.back()._pressure_ratios;
				auto& speed = _tclines.back()._speed;

				std::istringstream issbegin(beginLine);
				issbegin >> speed;

				// 开辟空间
				int count = 0;
				for (char ch : beginLine) {
					if (ch == '\t') count++;
				}
				flows.resize(count);
				efficiencies.resize(count);
				pressure_ratios.resize(count);

				// 读取数据
				input >> tmp;
				for (auto& e : flows) input >> e;
				input >> tmp;
				for (auto& e : efficiencies) input >> e;
				input >> tmp;
				for (auto& e : pressure_ratios) input >> e;
				if (isturb) {	// 涡轮数据读取单独处理	->临时方案; todo: 数据格式修改;协议定制
					input >> tmp;
					for (auto& e : flows) input >> e;
				}
				std::getline(input, beginLine);		// 读取剩余的 "\n"

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
					for (auto x : pressure_ratios) cout << x << " ";
					cout << endl;
					cout << endl << "------------------------------" << endl;
				}
			}
			cout << endl << endl << endl;
		}

		void saveFile(std::ofstream& output)
		{
			if (!output.is_open()) {
				LOG("文件打开失败");
				return;
			}

			output << _preRotation << endl;
			output << "原始数据计算[喘震点]: " << endl;
			output << "转速:\t";
			for (auto& e : _tclines) output << e._speed << "\t"; output << endl;
			output << "喘震流量:\t";
			for (auto& e : _tclines) output << e._surge_flow << "\t"; output << endl;
			output << "喘震压比: ";
			for (auto& e : _tclines) output << e._surge_pressure_ratio << "\t"; output << endl;
			output << "喘震效率: ";
			for (auto& e : _tclines) output << e._surge_efficiencies << "\t"; output << endl;
			output << "tip:舍弃喘震流量为0的点" << endl;
			output << "\n";

			output << "\n外推结果[喘震点]:\n";
			output << "转速: ";
			for (auto& charline : _tclines_new) output << charline._speed << "\t"; output << endl;
			output << "喘震流量: ";
			for (auto& charline : _tclines_new) output << charline._surge_flow << "\t"; output << endl;
			output << "喘震压比: ";
			for (auto& charline : _tclines_new) output << charline._surge_pressure_ratio << "\t"; output << endl;
			output << "喘震效率: ";
			for (auto& charline : _tclines_new) output << charline._surge_efficiencies << "\t"; output << endl;

			output << "\n外推结果[特性线]:\n";
			for (auto& charline : _tclines_new) {
				output << "转速: " << charline._speed << endl;
				output << "流量: ";
				for (auto& e : charline._flows) output << e << "\t"; output << endl;
				output << "压比: ";
				for (auto& e : charline._pressure_ratios) output << e << "\t"; output << endl;
				output << "效率: ";
				for (auto& e : charline._efficiencies) output << e << "\t"; output << endl;
			}
			output << "\n\n";
		}

		int saveExcelFile(xlnt::workbook& wb, int beginrow = 1, bool save = false, string filename = "outcome.xlsx")
		{
			xlnt::worksheet ws = wb.active_sheet();
			int row = beginrow;
			for (auto& charline : _tclines_new) {
				int n = charline._flows.size();
				string str = "speed:" + std::to_string(int(charline._speed));
				ws.cell(1, row).value(str);
				// 中文需要设置utf8编码
				ws.cell(1, row + 1).value("flow");				// ("流量");
				ws.cell(1, row + 2).value("efficiency");		// ("效率");
				ws.cell(1, row + 3).value("presure_ratio");		// ("压比");

				for (int col = 0; col < n; ++col) {
					ws.cell(col + 2, row + 1).value(charline._flows[col]);	// [列, 行]
					ws.cell(col + 2, row + 2).value(charline._efficiencies[col]);
					ws.cell(col + 2, row + 3).value(charline._pressure_ratios[col]);
				}
				row += 4;
			}

			if (save) wb.save(filename);
			return row;		// 下一次存储数据起始行
		}

	public:
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

		// todo 使用不同sheet区分不同预旋; 然后定义不同分割符号	使用cells.front.to_string.find关键字来区分数据
		// 这个方案弃用, 三方库数据读取不方便
		// 目前只支持一组预旋读取: 一组4行数据 2900speed flow efficiency pressRatio 多组间不带空行
		// 为了兼容为了excel高版本,可以将数据拷贝到xlnt生成的表格下, 且不要图片,只要存粹数据; 为了避免乱码,使用英文
		void readDataFromExcel(xlnt::workbook& wb)
		{
			xlnt::worksheet ws = wb.active_sheet();
			for (const xlnt::cell_vector& cells : ws) {
				int row = cells.front().row();
				if (row % 5 == 0) {
					_tclines.push_back(TurbineCharLine());
				}
				if (row % 5 == 1) {
					std::stringstream ss(cells.front().to_string());
					ss >> _tclines.back()._speed;
				}
				else if (row % 5 == 2) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++ == 0) continue;
						_tclines.back()._flows.push_back(atoi(cell.to_string().c_str()));
					}
				}
				else if (row % 5 == 3) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++ == 0) continue;
						_tclines.back()._efficiencies.push_back(atoi(cell.to_string().c_str()));
					}
				}
				else if (row % 5 == 4) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++ == 0) continue;
						_tclines.back()._pressure_ratios.push_back(atoi(cell.to_string().c_str()));
					}
				}
			}
		}
	};


	class MultiTurbineCharLine_PreRotations
	{
	private:
		vector<MultiTurbineCharLine> _mtcls;
		double _speed_design = 0.0;
	public:
		MultiTurbineCharLine_PreRotations(double speed_design) :_speed_design(speed_design)
		{
			for (auto& tclines : _mtcls) tclines.setSpeedDesign(speed_design);
		}
		vector<MultiTurbineCharLine>& getMultiTurbineCharLines() { return _mtcls; }

		// 读取数据文件 待外推速度
		void solution(vector<double> speeds = vector<double>(), string outfile = "./outdata/outcome")
		{
			cout << _mtcls.size() << endl;
			std::ofstream output(outfile + ".txt", std::ios::trunc);
			xlnt::workbook wb;
			int beginrow = 1;
			for (auto& mtl : _mtcls) {
				mtl.getSurgeLine();

				cout << endl << endl;
				cout << "转速: ";
				for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
				cout << "喘震流量: ";
				for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
				cout << "喘震压比: ";
				for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
				cout << "喘震效率: ";
				for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;

				// 带入原有特性线验证,最好 7:3, 一开始用7层样本外推, 最后3层样本验证
				for (auto speed : speeds) {
					mtl.extrapolation(speed);
				}

				wstring img = string2wstring(mtl.preRotation());
				mtl.drawGraph(3, img);	// 流量-压比
				mtl.drawGraph(5, img);	// 流量-效率
				//system("pause");

				xlnt::worksheet ws = wb.active_sheet();
				ws.cell(1, beginrow++).value(mtl.preRotation());
				beginrow = mtl.saveExcelFile(wb, beginrow) + 1;
				mtl.saveFile(output);
			}
			output.close();
			wb.save(outfile + ".xlsx");
		}

		// todo: 去掉isturb, 统一数据格式,通过文件字符确定数组, string.find()
		void readDataFromFile(string file, bool check = false, bool isturb = false)
		{
			std::ifstream input(file.c_str());
			string tmp;
			while (std::getline(input, tmp)) {
				// todo待解决读取utf8编码的文本乱码: 
				// 临时方案1-> 预旋转: 数据, 不保存字符串
				// 临时方案2-> txt文本文件默认utf8编码，可以将该文件另存为ansi编码
				// 临时方案3-> 摆烂,使用英文
				cout << "--------------------------预旋转: " << tmp << endl;
				//system("pause");

				_mtcls.push_back(MultiTurbineCharLine());
				auto& tclines = _mtcls.back();
				auto pos = tmp.find("\t");
				tclines.preRotation() = tmp.substr(0, pos);
				tclines.readDataFromFile(input, check, isturb);
			}
			input.close();
		}

	private:
		// todo...
	};
}

