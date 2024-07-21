#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <easyx.h>

// RGB颜色
enum Color
{
	IndianRed1 = 0xFF6A6A,
	DeepSkyBlue = 0x00BFFF,
	Blue = 0x0000FF,
	Yellow = 0xFFFF00,
	Blue_Water = 0x00FFFF,
	Magenta_magenta = 0xFF00FF,
	Silver = 0xC0C0C0,
	Grey = 0x808080,
	Yellow2 = 0xEEEE00,
	Olive = 0x808000,
	Green = 0x008000,
	Purple = 0x800080,
	Blue_Green = 0x008080,
	Navy = 0x000080,
	Orange = 0xFFA500,
	LawnGreen = 0x7CFC00,
	Coral = 0xFF7F50,
	Gainsboro = 0xDCDCDC,
	SaddleBrown = 0x8B4513,
	Cyan = 0x00FFFF,
	DarkOrchid = 0x9932CC,
	SlateBlue = 0x6A5ACD
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
		_colors = { IndianRed1 ,DeepSkyBlue,Blue,Yellow,Blue_Water,Magenta_magenta,Silver,Grey,
			Yellow2,Olive,Green,Purple,Blue_Green,Navy,Orange,LawnGreen,Coral,Gainsboro,
			SaddleBrown,Cyan,DarkOrchid,SlateBlue };
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
			_stprintf_s(s, _T("%.2f"), actualX);
			outtextxy(x, 10, s);

			double y = xyLength * i / scaleNum;
			double actualY = y / _scaleY + _minY;
			line(0, -y, 10, -y);
			_stprintf_s(s, _T("%.2f"), actualY);
			outtextxy(-_margin + 5, -y, s);
		}
	}

	//void drawLine(const std::vector<double>& arrx, const std::vector<double>& arry, TCHAR s[])
	void drawLine(const std::vector<double>& arrx, const std::vector<double>& arry, std::wstring str)
	{
		// 绘制y=f(x)线
		double prex = 0, prey = 0;
		int size = arrx.size();
		for (int i = 0; i < size; ++i) {
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
			outtextxy(40, -xyLength + _colorID * 10, str.c_str());
		}
		else {
			outtextxy(150, -xyLength + (_colorID - 1) * 10, str.c_str());
		}

		// 改变下一条线的颜色
		if (_colorID < _colors.size()) {
			setColor(_colors[_colorID++]);
		}
	}

	void clearGraph() { cleardevice(); }
	void closeGraph() { closegraph(); }
};