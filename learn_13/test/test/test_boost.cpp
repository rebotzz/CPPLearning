#include <boost/lambda/lambda.hpp>
#include <boost/math/quadrature/gauss_kronrod.hpp>
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <easyx.h>
using namespace std;

#define M_PI 3.14159265358979323846

vector<pair<double, double>> arr_relerr;	// 自变量和相对误差映射
constexpr int length = 800;

// // 1.0 使用直线斜率迭代: 缺点,不好控制速率
//		auto getLineCircle = [=]() ->std::pair<double, double>{
//			double A = k, B = -1, C = b1; // 直线方程的系数
//			double k = r2y, R = r2;    // 圆的y坐标和半径
//			double h1, h2;  // 圆的x坐标
//
//			// 计算直线到圆心的距离
//			double sqrt_A2_B2 = std::sqrt(A * A + B * B);
//			double R_sqrt_A2_B2 = R * sqrt_A2_B2;
//
//			// 计算圆的x坐标
//			h1 = (R_sqrt_A2_B2 - B * k - C) / A;
//			h2 = (-R_sqrt_A2_B2 - B * k - C) / A;
//
//			// 输出结果
//			return { h1, h2 };
//			};


// 2.0 使用R2圆心坐标r2x迭代
void cal()
{
	// 绘制坐标轴
	setorigin(length / 2, length / 2);

	// 初始化变量
	double b1 = 0.1e-3;		   // 直线L5与y轴截距    喷孔直径?
	double lw = 108e-3;		   // 碗口径
	double h = 23.9e-3;		   // 凹坑深度
	double r2 = 19e-3;		   // 凹坑半径
	double volume_set = 4.3747866256303e-4;   // 给定体积

	// 迭代步长, 迭代初值, 要求精度
	double step = 1e-3;
	double begin_val = 15e-3;
	double precision = 0.01;

	printf("输入(国际单位):\n直线L5与y轴截距, 碗口径, 凹坑深度, 凹坑半径, 给定体积: ");
	cin >> b1 >> lw >> h >> r2 >> volume_set;
	printf("以R2圆心坐标x作为迭代变量\n输入(国际单位):\n迭代步长, 迭代初值, 要求精度(误差百分比):");
	cin >> step >> begin_val >> precision;

	

	// 圆R2方程f2 = Eq((x - r2x) * *2 + (y - r2y) * *2 - r2 * *2, 0) -> 未知:r2x
	double r2x = 0, r2y = h - r2;	  // 凹坑圆心纵坐标

	// 圆R1方程f3 = Eq((x - r1x) * *2 + (y - r1y) * *2 - r1 * *2, 0) -> 未知:r1
	double r1 = 0;		 // 圆R1半径   
	double& r1y = r1;	 //   r1y,r1两者相等
	double r1x = lw;     // 圆R1圆心横坐标, 纵坐标


	//迭代
	double inter12 = 0, inter23 = 0;	// f1和f2的交点,f2和f3的交点
	double volume_cal = 0;
	for (r2x = begin_val; r2x < r1x; r2x += step)
	{
		// 直线L4方程f1: y = x * k - b1;	凹坑 -> f2: 
		// 直线与圆相切: 计算f2方程 r2x, f1和f2的交点 inter12, 两个解,取上相切点
		double k = 0;
		auto getK = [=]() -> pair<double, double> {
			double x1 = r2x, y1 = r2y, b = b1, R = r2;

			// 设定二次方程的系数
			double A = x1 * x1 - R * R;
			double B = -2 * x1 * y1 + 2 * b * x1;
			double C = y1 * y1 - 2 * b * y1 + b * b - R * R;

			// 计算判别式
			double discriminant = B * B - 4 * A * C;

			if (discriminant < 0) {
				printf("没有实数解\n");
				return { 0, 0 };
			}
			else {
				// 计算两个解
				double m1 = (-B + sqrt(discriminant)) / (2 * A);
				double m2 = (-B - sqrt(discriminant)) / (2 * A);

				//std::cout << "可能的斜率是: " << m1 << " 或 " << m2 << std::endl;
				return { m1, m2 };
			}
			};
		auto ret = getK();
		k = max(ret.first, ret.second);		// 取较大的斜率,与上半圆相切
		if (k == 0.0) {
			continue;
		}

		double beta = atan(k);				// 弧度制
		inter12 = r2x - r2 * sin(beta);


		// 两圆相切: 计算f3方程 r1, f2和f3的交点 inter23
		auto getCCircle = [=]() {
			double x1 = r2x, y1 = r2y, R1 = r2; // 圆1的圆心和半径
			double x2 = r1x;         // 圆2的x坐标
			double R2, y2;     // 圆2的半径和y坐标

			// 计算圆2的半径 R2
			double numerator = (x2 - x1) * (x2 - x1) + y1 * y1 - R1 * R1;
			double denominator = 2 * (y1 + R1);
			R2 = numerator / denominator;

			// 圆2的y坐标 k2 等于其半径 R2
			y2 = R2;
			return y2;
			};
		r1 = getCCircle();
		if (r1 < 0) {		// 舍弃半径为负
			continue;
		}
		inter23 = r2x + r2 * (r1x - r2x) / (r1 + r2);

		// 曲线f(x): 为了计算面积分
		auto f1 = [](double x, double _beta, double _b1) {return x * tan(_beta) + _b1; };
		auto f2 = [](double x, double _r2, double _r2x, double _r2y) {return sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y; };
		auto f3 = [](double x, double _r1, double _r1x, double _r1y) {return -sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y; };
		function<double(double)> func1 = bind(f1, placeholders::_1, beta, b1);
		function<double(double)> func2 = bind(f2, placeholders::_1, r2, r2x, r2y);
		function<double(double)> func3 = bind(f3, placeholders::_1, r1, r1x, r1y);

		// 曲线f(x): 为了计算体积分	面积分 -> 体积分: f(x)乘以2*PI*x
		auto ff1 = [](double x, double _beta, double _b1) {return 2 * M_PI * x * (x * tan(_beta) + _b1); };
		auto ff2 = [](double x, double _r2, double _r2x, double _r2y) {return 2 * M_PI * x * (sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y); };
		auto ff3 = [](double x, double _r1, double _r1x, double _r1y) {return 2 * M_PI * x * (-sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y); };
		function<double(double)> fff1 = bind(ff1, placeholders::_1, beta, b1);
		function<double(double)> fff2 = bind(ff2, placeholders::_1, r2, r2x, r2y);
		function<double(double)> fff3 = bind(ff3, placeholders::_1, r1, r1x, r1y);

		// 积分得到体积
		using namespace boost;
		using namespace boost::math::quadrature;
		boost::math::quadrature::gauss_kronrod<double, 10> integrator;
		auto result1 = integrator.integrate(fff1, 0, inter12);
		auto result2 = integrator.integrate(fff2, inter12, inter23);
		auto result3 = integrator.integrate(fff3, inter23, r1x);
		if (result1 < 0 || result2 < 0 || result3 < 0) { // 如果积分有负数
			printf("error, 积分有负数\n");
			continue;
		}
		volume_cal = result1 + result2 + result3;
		auto relerr = abs(volume_set - volume_cal) / volume_set;	   // 相对误差


		// 查看三条曲线
		printf("\n\nr2x: %lf\n", r2x);
		printf("beta: %lf°斜率: %lf\n", (beta * 180 / M_PI), k);
		printf("[直线L4] f1: y = %lf * x + %lf\n", k, b1);
		printf("[圆R2] f2: (y - %lf)^2 + (x - %lf)^2 = (%lf)^2\n", r2y, r2x, r2);
		printf("[圆R1] f3: (y - %lf)^2 + (x - %lf)^2 = (%lf)^2\n", r1y, r1x, r1);
		printf("积分区间: [%lf, %lf] [%lf, %lf] [%lf, %lf]\n", 0, inter12, inter12, inter23, inter23, r1x);
		printf("对应y值: [%lf, %lf] [%lf, %lf] [%lf, %lf]\n", func1(0), func1(inter12), func2(inter12), func2(inter23), func3(inter23), func3(r1x));
		cout << "面积分: " << integrator.integrate(func1, 0, inter12)<<" " << integrator.integrate(func2, inter12, inter23) << " " << integrator.integrate(func3, inter23, r1x) << endl;
		cout << "体积分: " << result1 << " " << result2 << " " << result3 << endl;
		cout << "计算体积: " << volume_cal << " 设计体积: " << volume_set << " 相对误差: " << relerr << endl << endl;;

		if(relerr < 5 * precision)
		{
			// 绘制坐标轴
			cleardevice();
			line(-length / 2, 0, length / 2, 0);
			line(0, -length / 2, 0, length / 2);
			outtextxy(0, length / 2 - 20, _T("Y"));
			outtextxy(length / 2 - 20, 0, _T("X"));

			// 绘制积分分段
			int scale = 2e3;
			setlinecolor(RGB(255, 0, 0));
			line(inter12 * scale, 0, inter12* scale, 50);
			line(inter23 * scale, 0, inter23* scale, 50);
			line(r1x * scale, 0, r1x * scale, 50);
			setlinecolor(RGB(255, 0, 0));

			setlinecolor(RGB(0, 255, 0));
			double x1 = 0, y1 = func1(x1), x2 = scale * inter12, y2 = func1(x2);
			line(x1, y1, x2, y2);
			outtextxy(x2, y2, _T("L4"));
			solidcircle(x2, y2, 3);
			line(x2, y2, length / 2, func1(length / 2));

			x1 = scale * r1x, y1 = scale * r1y, x2 = scale * r2x, y2 = scale * r2y;
			circle(x2, y2, scale * r2);
			outtextxy(x2, y2, _T("R2"));
			solidcircle(x2, y2, 3);

			circle(x1, y1, scale * r1);
			outtextxy(x1, y1, _T("R1"));
			solidcircle(x1, y1, 3);

			setlinecolor(RGB(255, 255, 255));
		}


		if (relerr < 100 * precision)
			arr_relerr.push_back({ r2x, relerr });

		if (relerr < precision)
		{
			break; // 迭代判断条件: 面积在精度内
			system("pause");
		}
	}
}


void graphErr()
{
	// 绘制坐标轴
	line(-length / 2, 0, length / 2, 0);
	line(0, -length / 2, 0, length / 2);
	outtextxy(0, length / 2 - 20, _T("Y"));
	outtextxy(length / 2 - 20, 0, _T("X"));

	printf("\n误差曲线采样数据个数: %d\n", arr_relerr.size());
	double scale_x = 2e3, scale_y = 5e2;
	double prex = 0, prey = 0;
	double minx = INT_MAX, miny = INT_MAX;
	setlinecolor(RGB(0, 150, 150));
	outtextxy(0, length / 4, _T("相对误差曲线"));
	for (auto kv : arr_relerr)
	{
		if (kv.second < miny) {
			minx = kv.first, miny = kv.second;
		}
		printf("[%lf, %lf] ", kv.first, kv.second);
		double x = kv.first * scale_x, y = kv.second * scale_y;
		solidcircle(x, y, 2);
		if (prex == 0 && 0 == prey)
		{
			prex = x, prey = y;
			continue;
		}
		line(prex, prey, x, y);
		prex = x, prey = y;
	}
	setlinecolor(RGB(255, 255, 255));

	printf("\n误差最小值点: [r2x: %lf, error: %lf]\n", minx, miny);
	system("pause");
}




//int main()
//{
//	initgraph(length, length);
//	setorigin(length / 2, length / 2);
//
//	// 绘制坐标轴
//	line(-length / 2, 0, length / 2, 0);
//	line(0, -length / 2, 0, length / 2);
//	outtextxy(0, length / 2 - 20, _T("Y"));
//	outtextxy(length / 2 - 20, 0, _T("X"));
//
//	cal();
//	graphErr();
//
//	system("pause");
//	closegraph();
//
//	return 0;
//}