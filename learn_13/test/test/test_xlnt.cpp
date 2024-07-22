#include <xlnt/xlnt.hpp>

#if 0

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include <functional>
#include <boost/math/interpolators/barycentric_rational.hpp>
#include <boost/math/tools/roots.hpp>
#include <easyx.h>

enum Color
{
	IndianRed1 = 0xFF6A6A,
	DeepSkyBlue = 0x00BFFF,
	Blue = 0x0000FF,			// (0, 0,255)
	Yellow = 0xFFFF00,			// (255,255, 0)
	Blue_Water = 0x00FFFF,		// (0,255,255)
	Magenta_magenta = 0xFF00FF,	// (255, 0,255)
	Silver = 0xC0C0C0,			// (192,192,192)
	Grey = 0x808080,			// (128,128,128)
	Yellow2 = 0xEEEE00,
	Olive = 0x808000,			// (128,128, 0)
	Green = 0x008000,			// (0,128, 0)
	Purple = 0x800080,			// (128,0,128)
	Blue_Green = 0x008080,		// (0,128,128)
	Navy = 0x000080				// (0, 0128)
};

// 绘制坐标系
struct Coordinate
{
public:
	double _length = 0;					// 绘图边框长度
	int _margin = 0;					// 页边距
	int _originX = 0, _originY = 0;		// 原点
	double _minX = 0, _maxX = 0;		// x∈[minX, maxX]
	double _minY = 0, _maxY = 0;
	double _scaleX = 0, _scaleY = 0;	//绘图缩放比例

	std::vector<Color> _colors;
	int _colorID = 0;
public:
	// 初始化
	Coordinate(double length) : _length(length), _margin(length * 0.05)
	{
		_colors = { IndianRed1 ,DeepSkyBlue,Blue,Yellow,Blue_Water,Magenta_magenta,Silver,Grey,Yellow2,Olive,Green,Purple,Blue_Green,Navy };
	}
	void setOrigin(int x = 0, int y = 0) {
		if (0 == x && 0 == y) {
			_originX = _margin, _originY = _length - _margin;
		}
		else {	// easyX y轴与数学常规坐标轴相反
			_originX = x, _originY = y;
		}
		setorigin(_originX, _originY);
	}
	void setxScope(double min, double max) { _minX = min, _maxX = max; }
	void setyScope(double min, double max) { _minY = min, _maxY = max; }
	void setColor(Color col)
	{
		setlinecolor(col);
		settextcolor(col);
	}
	void setScale(double scaleX = 0.0, double scaleY = 0.0)
	{
		if (0 == scaleX || 0 == scaleY) {		// 如果默认
			_scaleX = (_length - _margin) / (_maxX - _minX);
			_scaleY = (_length - _margin) / (_maxY - _minY);
		}
		else {
			_scaleX = scaleX, _scaleY = scaleY;
		}
	}

	// 绘图
	void initGraph()
	{
		initgraph(_length, _length);	// 先init
		setorigin(_originX, _originY);
	}

	void drawCoordinate(int scaleNum = 10)	// 刻度个数
	{
		// 绘制坐标轴		easyX的y轴与数学上的y轴正好相反
		double xyLength = _length - _margin;
		line(0, 0, xyLength, 0);
		line(0, 0, 0, -xyLength);
		outtextxy(0, -xyLength, _T("Y"));
		outtextxy(xyLength - _margin, 5, _T("X"));

		// 绘制坐标轴刻度
		if (_scaleX == 0 && _scaleY == 0) setScale();
		if (_originX == 0 && _originY == 0) setOrigin();
		for (int i = 1; i < scaleNum; ++i) {
			double x = xyLength * i / scaleNum;
			double actualX = x / _scaleX + _minX;
			line(x, 0, x, -10);
			TCHAR s[16] = { 0 };
			_stprintf_s(s, _T("%.0f"), actualX);
			outtextxy(x, 10, s);

			double y = xyLength * i / scaleNum;
			double actualY = y / _scaleY + _minY;
			line(0, -y, 10, -y);
			_stprintf_s(s, _T("%.1f"), actualY);
			outtextxy(-_margin + 5, -y, s);
		}
	}

	void drawLine(const std::vector<double>& arrx, const std::vector<double>& arry, TCHAR s[])
	{
		// 绘制y=f(x)线
		double prex = 0, prey = 0;
		int size = arrx.size();
		for (int i = 1; i < size; ++i) {
			double x = (arrx[i] - _minX) * _scaleX, y = (arry[i] - _minY) * _scaleY;
			solidcircle(x, -y, 2);
			if (0 == prex && 0 == prey) {
				prex = x, prey = y;
				continue;
			}
			line(prex, -prey, x, -y);
			prex = x, prey = y;
		}

		// 关于曲线描述信息
		double xyLength = _length - _margin;
		if (_colorID % 2 == 0) {
			outtextxy(40, -xyLength + _colorID * 10, s);
		}
		else {
			outtextxy(140, -xyLength + (_colorID - 1) * 10, s);
		}

		// 改变下一条线的颜色
		if (_colorID < _colors.size()) {
			setColor(_colors[_colorID++]);
		}
	}

	void clearGraph() { cleardevice(); }
	void closeGraph() { closegraph(); }
};




#undef max
#undef min

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::move;

#define M_PI 3.14159265358979323846
static const double PI = acos(-1.0);		// 圆周率Π
static const double g_adiabaticIndex = 1.4;	// 绝热指数 暂定1.4


// 转速为speed的特性线
class TurbineCharLine
{
public:
	vector<double> _flows;				// 流量
	vector<double> _efficiencies;		// 效率
	vector<double> _pressure_ratios;	// 压比
	double _speed = 0.0;				// 转速
	double _surge_flow = 0.0;			// 喘震流量
	double _surge_efficiencies = 0.0;	// 喘震效率
	double _surge_pressure_ratio = 0.0; // 喘震压比
};

//// 压气机喘震流量计算	bug: 不正确, 弃用
//inline double getSurgeFlow(double speed_operating, double speed_design)
//{
//	return 1.225 * pow(((1 - (0.1576 * PI - 0.1418) * (1 - speed_operating / speed_design)) / (1 - 1.4805 * PI + 0.5854 * PI * PI)), 2);
//}

// 不同转速speed的特性线
class MultiTurbineCharLine
{
private:
	typedef boost::math::interpolators::barycentric_rational<double> Interpolator;
public:
	// todo待优化: 每个特性线自变量都是flows, 都一样,数据冗余
	vector<TurbineCharLine> _tclines;							// 已知数据,已有的特性线
	double _speed_design = 0.0;									// 设计转速

	std::shared_ptr<Interpolator> _surge_speedRatio_flow_ptr;	// 插值得到:(运行速度/设计速度)-喘震流量
	std::shared_ptr<Interpolator> _surge_flow_pressRatio_ptr;	// 插值得到:喘震流量-喘震压比
	std::shared_ptr<Interpolator> _surge_flow_efficiency_ptr;	// 插值得到:喘震流量-喘震效率
	vector<TurbineCharLine> _tclines_new;						// 插值推演:新的特性线

public:
	MultiTurbineCharLine(double speed_design, int length = 800) : _speed_design(speed_design)
	{}

	void readData(string filename)
	{
		std::ifstream input(filename);
		if (!input.is_open()) {
			cerr << "open failed" << endl;
		}

		string beginLine, tmp;
		while (std::getline(input, beginLine))	// 规定只要还有新的一行,那么就有完整的数据
		{
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
			for (auto& e : flows) {
				input >> e;
			}
			input >> tmp;
			for (auto& e : efficiencies) {
				input >> e;
			}
			input >> tmp;
			for (auto& e : pressure_ratios) {
				input >> e;
			}
			std::getline(input, beginLine);		// 读取剩余的 "\n"

			// 检查读取
			cout << "转速: " << speed << endl;
			cout << "流量: ";
			for (auto x : flows) cout << x << " ";
			cout << endl;
			cout << "效率: ";
			for (auto x : efficiencies) cout << x << " ";
			cout << endl;
			cout << "压比: ";
			for (auto x : pressure_ratios) cout << x << " ";
			cout << endl;
			cout << endl << "------------------------------" << endl;
			//system("pause");
		}
		cout << endl << endl << endl;
		input.close();
	}

	// 求解堵塞(喘震)边界线
	void getSurgeLine()
	{
		// 求解不同转速的特性线喘震点
		vector<double> surge_flows, surge_press_ratios, surge_efficiencies, surge_speedRatio;
		for (auto& charline : _tclines) {
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
					printf("speed: %lf, root: %lf %lf\n", charline._speed, root.first, root.second);
				}
				catch (const std::exception&)
				{
					printf("charline [speed]: %lf, not find root!\n", charline._speed);
					return 0.0;
				}
				catch (...)
				{
					throw;
				}

				// 这里df单调,只有一个根
				return root.first;
				};

			// 插值得到流量-压比,流量-效率关系 f(x)
			// 似乎只用流量-压比就够了, 得到喘震流量, 然后插值得到喘震效率
			Interpolator interPress(x_values.begin(), x_values.end(), y_values_press.begin());
			Interpolator interEff(x_values.begin(), x_values.end(), y_values_eff.begin());

			// 流量-压比:斜率为零的点  喘震点
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
	TurbineCharLine& extraplotion(double speed_new)
	{
		// 初始化
		_tclines_new.push_back(TurbineCharLine());
		auto& tcline = _tclines_new.back();	// 需要外推的特性线
		int mid = _tclines.size() / 2;
		size_t size = _tclines[mid]._flows.size();
		tcline._flows.resize(size);
		tcline._pressure_ratios.resize(size);
		tcline._efficiencies.resize(size);
		tcline._speed = speed_new;

		// 暂定使用中间一个特性线作为基准
		auto& tcline_ref = _tclines[mid];
		double speed_ref = tcline_ref._speed;
		double surge_pressure_ratio_ref = tcline_ref._surge_pressure_ratio;
		double surge_flow_ref = tcline_ref._surge_flow;
		double surge_efficiency_ref = tcline_ref._surge_efficiencies;
		double adiabaticIndex = g_adiabaticIndex;	// 绝热指数

		// todo: 验证这里正确性
		// 假定利用喘震点插值得到的关系:
		// f(x): (运行速度/设计速度)速比-喘震流量 喘震流量-喘震压比 喘震流量-喘震效率
		// 插值得到新的转速speed_new对应的喘震点参数:
		// 流量flows,压比pressure_ratio,效率efficiencies 
		double surge_flow_new = _surge_speedRatio_flow_ptr->operator()(speed_new / speed_ref);
		double surge_pressure_ratio_new = _surge_flow_pressRatio_ptr->operator()(surge_flow_new);
		double surge_efficiency_new = _surge_flow_efficiency_ptr->operator()(surge_efficiency_ref);

		// 求插值的比例系数
		double speed_ratio = speed_new / speed_ref;
		double indexPressureRatio = getIndexPressureRatio(surge_pressure_ratio_new, surge_pressure_ratio_ref, speed_ratio, adiabaticIndex);
		double indexFlow = getIndexFlow(surge_flow_new, surge_flow_ref, speed_ratio);
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

	// 流量的相似关系系数
	double getIndexFlow(double flow_new, double flow_ref, double speed_ratio)
	{
		return log(flow_new / flow_ref) / log(speed_ratio);
	}

	// 压比的相似关系系数
	double getIndexPressureRatio(double pressure_ratio_new, double pressure_ratio_ref, double speed_ratio, double adiabaticIndex)
	{
		double k = (adiabaticIndex - 1) / adiabaticIndex;
		return log(pow(pressure_ratio_new, k) / pow(pressure_ratio_ref, k)) / log(speed_ratio);
	}

	// 效率的相似关系系数
	double getIndexEfficiency(double efficiency_new, double efficiency_ref, double speed_ratio)
	{
		return log(efficiency_new / efficiency_ref) / log(speed_ratio);
	}

	void drawGraph(int length = 800)
	{
		// 绘制曲线
		Coordinate _coord(length);

		// 绘制原本的特性线
		_coord.initGraph();
		int margin = length * 0.05;
		_coord.setOrigin(margin, length - margin);
		_coord.setxScope(_tclines[0]._flows[0], _tclines[0]._flows.back());
		_coord.setyScope(1, 3);	// 压比范围大概 1 ~ 3
		_coord.drawCoordinate();
		for (auto& charline : _tclines) {
			TCHAR s[32] = { 0 };
			_stprintf_s(s, _T("速度:%.0lf"), charline._speed);
			_coord.drawLine(charline._flows, charline._pressure_ratios, s);
		}

		// 绘制喘震边界线
		vector<double> surgeX(_tclines.size()), surgeY(_tclines.size());
		for (int i = 0; i < surgeX.size(); ++i) {
			surgeX[i] = _tclines[i]._surge_flow;
			surgeY[i] = _tclines[i]._surge_pressure_ratio;
		}
		TCHAR s[32] = { 0 };
		_stprintf_s(s, _T("喘震边界线"));
		_coord.drawLine(surgeX, surgeY, s);


		system("pause");

		// 绘制相似理论外推特性线
		for (auto& charline : _tclines_new) {
			TCHAR s[32] = { 0 };
			_stprintf_s(s, _T("外推速度:%.0lf"), charline._speed);
			_coord.drawLine(charline._flows, charline._pressure_ratios, s);
		}

		system("pause");
		_coord.closeGraph();
	}

	void saveFile(string filename = "outcome.txt")
	{
		std::ofstream output(filename, std::ios::out | std::ios::trunc);
		if (!output.is_open()) {
			cerr << "文件打开失败: " << filename << endl;
			return;
		}

		output << "求极值点失败的曲线: 喘震流量为0, 舍弃" << endl;
		output << "喘震流量: ";
		for (auto& e : _tclines) output << e._surge_flow << " "; cout << endl;

		output << "\n\n外推结果:\n";
		for (auto& charline : _tclines_new) {
			output << "速度:\t" << charline._speed << endl;
			output << "流量:\t" << endl;
			for (auto& flow : charline._flows) cout << flow << "\t"; cout << endl;
			output << "效率:\t" << endl;
			for (auto& eff : charline._efficiencies) cout << eff << "\t"; cout << endl;
			output << "压比:\t" << endl;
			for (auto& pres : charline._pressure_ratios) cout << pres << "\t"; cout << endl;
		}
		output.close();
	}

	void saveExcelFile()
	{

	}

private:

};


int main()
{
	try
	{
		MultiTurbineCharLine mtl(8000);
		mtl.readData("data.txt");
		mtl.getSurgeLine();

		cout << "喘震流量: ";
		for (auto& e : mtl._tclines) cout << e._surge_flow << " "; cout << endl;
		
		cout << "\n\n开始外推:\n";
		for (int speed = 2800; speed >= 2500; speed -= 100) {
			auto& charline =  mtl.extraplotion(speed);
			cout << "速度:\t" << speed << endl;
			cout << "流量:\t" << endl;
			for (auto& flow : charline._flows) cout << flow << "\t"; cout << endl;
			cout << "效率:\t" << endl;
			for (auto& eff : charline._efficiencies) cout << eff << "\t"; cout << endl;
			cout << "压比:\t" << endl;
			for (auto& pres : charline._pressure_ratios) cout << pres << "\t"; cout << endl;
		}

		mtl.drawGraph();
		mtl.saveExcelFile();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	return 0;
}

#endif


#pragma execution_character_set("utf-8")
#include <iostream>
#include <string>
#include <xlnt/xlnt.hpp>
using namespace std;

//int main()
//{
//	wstring str = L"你好";
//	xlnt::workbook wb;
//	xlnt::worksheet ws1 = wb.active_sheet();
//	xlnt::worksheet ws2 = wb.active_sheet();
//
//	string s = "你好";
//	ws1.cell(1, 1).value(s);
//	ws2.cell(2, 2).value("哈喽123abc");
//	ws2.cell(3, 3).value(13215);
//	ws2.cell(4, 3).value("423cs");
//	wb.save(L"测试.xlsx");
//
//	return 0;
//}