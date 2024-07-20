#pragma once

//#include <xlnt/xlnt.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <easyx.h>
#include <boost/math/interpolators/barycentric_rational.hpp>

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
static const double PI = acos(-1.0);

// 转速为speed的特性线
class TurbineCharLine
{
public:
	vector<double> _flows;
	vector<double> _efficiencies;
	vector<double> _pressure_ratios;
	double _speed = 0.0;		// 转速
	double _surge_flow = 0.0;	// 喘震流量

	//TurbineCharLine() = default;

};

enum Color
{
	Red = 0xFF0000,	// (255, 0, 0)
	Lime = 0x00FF00,	// (0255, 0)
	Blue = 0x0000FF,	// (0, 0,255)
	Yellow = 0xFFFF00,	// (255,255, 0)
	Blue_Water = 0x00FFFF,	// (0,255,255)
	Magenta_magenta = 0xFF00FF,	// (255, 0,255)
	Silver = 0xC0C0C0,	// (192,192,192)
	Grey = 0x808080,	// (128,128,128)
	Chestnut = 0x800000,	// (128, 0, 0)
	Olive = 0x808000,	// (128,128, 0)
	Green = 0x008000,	// (0,128, 0)
	Purple = 0x800080,	// (128,0,128)
	Blue_Green = 0x008080,	// (0,128,128)
	Navy = 0x000080	// (0, 0128)
};

// 压气机喘震流量计算	bug: 不正确,需要修改
inline double getSurgeFlow(double speed_operating, double speed_design)
{
	return 1.225 * pow(((1 - (0.1576 * PI - 0.1418) * (1 - speed_operating / speed_design)) / (1 - 1.4805 * PI + 0.5854 * PI * PI)), 2);
}

// 不同转速speed的特性线
class MultiTurbineCharLine
{
private:
	vector<TurbineCharLine> _tclines;
	double _speed_design = 0.0;		// 设计转速

	vector<Color> _color;

public:
	MultiTurbineCharLine(double speed_design) : _speed_design(speed_design)
	{
		_color = { Red ,Lime,Blue,Yellow,Blue_Water,Magenta_magenta,Silver,Grey,Chestnut,Olive,Green,Purple,Blue_Green,Navy };
	}

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
		input.close();
	}

	// 求解堵塞边界线
	void getgetSurgeLine()
	{
		for (auto& line : _tclines) {
			line._surge_flow = getSurgeFlow(line._speed, _speed_design);
		}
	}


	void drawGraph(int length = 800)
	{
		initgraph(length, length);
		int margin = length * 0.05;
		setorigin(margin, length - margin);

		// 绘制坐标轴		easyX的y轴与数学上的y轴正好相反
		line(0, 0, length - margin, 0);
		line(0, 0, 0, -(length - margin));
		outtextxy(0, -(length - margin), _T("Y"));
		outtextxy(length - margin, 0, _T("X"));

		// 先绘制流量-压比
		// 绘图缩放比例
		double scaleX = 0, scaleY = 0;
		double minX = _tclines[0]._flows[0], maxX = 0;
		for (const auto& e : _tclines[0]._flows) {
			minX = std::min(minX, e);
			maxX = std::max(maxX, e);
		}
		scaleX = (length - margin - length / 3) / (maxX - minX);

		//double minY = _tclines[0]._pressure_ratios[0], maxY = 0.0;
		//for (const auto& e : _tclines[0]._pressure_ratios) {
		//	minY = std::min(minY, e);
		//	maxY = std::max(maxY, e);
		//}
		//scaleY = (length - margin) / (maxY - minY);
		double minY = 0.0;
		scaleY = (length - margin) / 4;

		// 绘制曲线(点)
		int color = 0;
		for (const auto& charline : _tclines) {

			// 绘制速度为speed的特性线
			double prex = 0, prey = 0;
			int size = charline._flows.size();
			for (int i = 0; i < size; ++i) {
				double x = (charline._flows[i] - minX) * scaleX, y = (charline._pressure_ratios[i] - minY) * scaleY;
				solidcircle(x, -y, 2);
				if (0 == prex && 0 == prey) {
					prex = x, prey = y;
					continue;
				}
				line(prex, -prey, x, -y);

				if (i % 3 == 0)
				{
					line(x, 0, x, -10);
					TCHAR s[16] = { 0 };
					_stprintf_s(s, _T("%.0f"), x);
					outtextxy(x, 10, s);

					line(0, -y, 10, -y);
					_stprintf_s(s, _T("%.0f"), y);
					outtextxy(-10, -y, s);
				}

				prex = x, prey = y;
			}

			TCHAR s[16] = { 0 };
			_stprintf_s(s, _T("速度:%.0f"), charline._speed);
			if (color < 4)
				outtextxy(40, -(length - margin) + color * 30, s);
			else
				outtextxy(90, -(length - margin) + color * 30, s);

			if (color < _color.size()) {	// 设置线颜色
				setlinecolor(_color[color]);
				settextcolor(_color[color]);
				color++;
			}
		}

		// 喘震动边界线
		double surge_prex = 0.0, surge_prey = 0.0;
		for (auto& charline : _tclines) {
			// 定义控制点
			auto& x_values = charline._flows;
			auto& y_values = charline._pressure_ratios;

			// 创建插值器对象
			boost::math::interpolators::barycentric_rational<double> interpolator(x_values.begin(), x_values.end(), y_values.begin());
			// 插值
			double x = charline._surge_flow;		// bug: 这里_surge_flow不对, 需改getSurgeFlow 函数
			double y = interpolator(x);

			// 初始化起点
			if (surge_prex == 0 && surge_prey == 0) {
				surge_prex = x;
				surge_prey = y;
				continue;
			}

			circle(x, y, 40);

			// 绘制连线
			line((surge_prex - minX) * scaleX, -(surge_prey - minY) * scaleY, (x - minX) * scaleX, -(y - minY) * scaleY);
			surge_prex = charline._surge_flow;
			surge_prey = interpolator(surge_prex);
		}
	}

	void closeGraph()
	{
		closegraph();
	}

};

//int main()
//{
//	//MultiTurbineCharLine mtl(8000);
//	//mtl.readData("data.txt");
//	//mtl.getgetSurgeLine();
//	//mtl.drawGraph();
//
//
//	//system("pause");
//	//mtl.closeGraph();
//
//
//
//	return 0;
//}