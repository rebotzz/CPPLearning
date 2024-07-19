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

vector<pair<double, double>> arr_relerr;	// �Ա�����������ӳ��
constexpr int length = 800;

// // 1.0 ʹ��ֱ��б�ʵ���: ȱ��,���ÿ�������
//		auto getLineCircle = [=]() ->std::pair<double, double>{
//			double A = k, B = -1, C = b1; // ֱ�߷��̵�ϵ��
//			double k = r2y, R = r2;    // Բ��y����Ͱ뾶
//			double h1, h2;  // Բ��x����
//
//			// ����ֱ�ߵ�Բ�ĵľ���
//			double sqrt_A2_B2 = std::sqrt(A * A + B * B);
//			double R_sqrt_A2_B2 = R * sqrt_A2_B2;
//
//			// ����Բ��x����
//			h1 = (R_sqrt_A2_B2 - B * k - C) / A;
//			h2 = (-R_sqrt_A2_B2 - B * k - C) / A;
//
//			// ������
//			return { h1, h2 };
//			};


// 2.0 ʹ��R2Բ������r2x����
void cal()
{
	// ����������
	setorigin(length / 2, length / 2);

	// ��ʼ������
	double b1 = 0.1e-3;		   // ֱ��L5��y��ؾ�    ���ֱ��?
	double lw = 108e-3;		   // ��ھ�
	double h = 23.9e-3;		   // �������
	double r2 = 19e-3;		   // ���Ӱ뾶
	double volume_set = 4.3747866256303e-4;   // �������

	// ��������, ������ֵ, Ҫ�󾫶�
	double step = 1e-3;
	double begin_val = 15e-3;
	double precision = 0.01;

	printf("����(���ʵ�λ):\nֱ��L5��y��ؾ�, ��ھ�, �������, ���Ӱ뾶, �������: ");
	cin >> b1 >> lw >> h >> r2 >> volume_set;
	printf("��R2Բ������x��Ϊ��������\n����(���ʵ�λ):\n��������, ������ֵ, Ҫ�󾫶�(���ٷֱ�):");
	cin >> step >> begin_val >> precision;

	

	// ԲR2����f2 = Eq((x - r2x) * *2 + (y - r2y) * *2 - r2 * *2, 0) -> δ֪:r2x
	double r2x = 0, r2y = h - r2;	  // ����Բ��������

	// ԲR1����f3 = Eq((x - r1x) * *2 + (y - r1y) * *2 - r1 * *2, 0) -> δ֪:r1
	double r1 = 0;		 // ԲR1�뾶   
	double& r1y = r1;	 //   r1y,r1�������
	double r1x = lw;     // ԲR1Բ�ĺ�����, ������


	//����
	double inter12 = 0, inter23 = 0;	// f1��f2�Ľ���,f2��f3�Ľ���
	double volume_cal = 0;
	for (r2x = begin_val; r2x < r1x; r2x += step)
	{
		// ֱ��L4����f1: y = x * k - b1;	���� -> f2: 
		// ֱ����Բ����: ����f2���� r2x, f1��f2�Ľ��� inter12, ������,ȡ�����е�
		double k = 0;
		auto getK = [=]() -> pair<double, double> {
			double x1 = r2x, y1 = r2y, b = b1, R = r2;

			// �趨���η��̵�ϵ��
			double A = x1 * x1 - R * R;
			double B = -2 * x1 * y1 + 2 * b * x1;
			double C = y1 * y1 - 2 * b * y1 + b * b - R * R;

			// �����б�ʽ
			double discriminant = B * B - 4 * A * C;

			if (discriminant < 0) {
				printf("û��ʵ����\n");
				return { 0, 0 };
			}
			else {
				// ����������
				double m1 = (-B + sqrt(discriminant)) / (2 * A);
				double m2 = (-B - sqrt(discriminant)) / (2 * A);

				//std::cout << "���ܵ�б����: " << m1 << " �� " << m2 << std::endl;
				return { m1, m2 };
			}
			};
		auto ret = getK();
		k = max(ret.first, ret.second);		// ȡ�ϴ��б��,���ϰ�Բ����
		if (k == 0.0) {
			continue;
		}

		double beta = atan(k);				// ������
		inter12 = r2x - r2 * sin(beta);


		// ��Բ����: ����f3���� r1, f2��f3�Ľ��� inter23
		auto getCCircle = [=]() {
			double x1 = r2x, y1 = r2y, R1 = r2; // Բ1��Բ�ĺͰ뾶
			double x2 = r1x;         // Բ2��x����
			double R2, y2;     // Բ2�İ뾶��y����

			// ����Բ2�İ뾶 R2
			double numerator = (x2 - x1) * (x2 - x1) + y1 * y1 - R1 * R1;
			double denominator = 2 * (y1 + R1);
			R2 = numerator / denominator;

			// Բ2��y���� k2 ������뾶 R2
			y2 = R2;
			return y2;
			};
		r1 = getCCircle();
		if (r1 < 0) {		// �����뾶Ϊ��
			continue;
		}
		inter23 = r2x + r2 * (r1x - r2x) / (r1 + r2);

		// ����f(x): Ϊ�˼��������
		auto f1 = [](double x, double _beta, double _b1) {return x * tan(_beta) + _b1; };
		auto f2 = [](double x, double _r2, double _r2x, double _r2y) {return sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y; };
		auto f3 = [](double x, double _r1, double _r1x, double _r1y) {return -sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y; };
		function<double(double)> func1 = bind(f1, placeholders::_1, beta, b1);
		function<double(double)> func2 = bind(f2, placeholders::_1, r2, r2x, r2y);
		function<double(double)> func3 = bind(f3, placeholders::_1, r1, r1x, r1y);

		// ����f(x): Ϊ�˼��������	����� -> �����: f(x)����2*PI*x
		auto ff1 = [](double x, double _beta, double _b1) {return 2 * M_PI * x * (x * tan(_beta) + _b1); };
		auto ff2 = [](double x, double _r2, double _r2x, double _r2y) {return 2 * M_PI * x * (sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y); };
		auto ff3 = [](double x, double _r1, double _r1x, double _r1y) {return 2 * M_PI * x * (-sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y); };
		function<double(double)> fff1 = bind(ff1, placeholders::_1, beta, b1);
		function<double(double)> fff2 = bind(ff2, placeholders::_1, r2, r2x, r2y);
		function<double(double)> fff3 = bind(ff3, placeholders::_1, r1, r1x, r1y);

		// ���ֵõ����
		using namespace boost;
		using namespace boost::math::quadrature;
		boost::math::quadrature::gauss_kronrod<double, 10> integrator;
		auto result1 = integrator.integrate(fff1, 0, inter12);
		auto result2 = integrator.integrate(fff2, inter12, inter23);
		auto result3 = integrator.integrate(fff3, inter23, r1x);
		if (result1 < 0 || result2 < 0 || result3 < 0) { // ��������и���
			printf("error, �����и���\n");
			continue;
		}
		volume_cal = result1 + result2 + result3;
		auto relerr = abs(volume_set - volume_cal) / volume_set;	   // ������


		// �鿴��������
		printf("\n\nr2x: %lf\n", r2x);
		printf("beta: %lf��б��: %lf\n", (beta * 180 / M_PI), k);
		printf("[ֱ��L4] f1: y = %lf * x + %lf\n", k, b1);
		printf("[ԲR2] f2: (y - %lf)^2 + (x - %lf)^2 = (%lf)^2\n", r2y, r2x, r2);
		printf("[ԲR1] f3: (y - %lf)^2 + (x - %lf)^2 = (%lf)^2\n", r1y, r1x, r1);
		printf("��������: [%lf, %lf] [%lf, %lf] [%lf, %lf]\n", 0, inter12, inter12, inter23, inter23, r1x);
		printf("��Ӧyֵ: [%lf, %lf] [%lf, %lf] [%lf, %lf]\n", func1(0), func1(inter12), func2(inter12), func2(inter23), func3(inter23), func3(r1x));
		cout << "�����: " << integrator.integrate(func1, 0, inter12)<<" " << integrator.integrate(func2, inter12, inter23) << " " << integrator.integrate(func3, inter23, r1x) << endl;
		cout << "�����: " << result1 << " " << result2 << " " << result3 << endl;
		cout << "�������: " << volume_cal << " ������: " << volume_set << " ������: " << relerr << endl << endl;;

		if(relerr < 5 * precision)
		{
			// ����������
			cleardevice();
			line(-length / 2, 0, length / 2, 0);
			line(0, -length / 2, 0, length / 2);
			outtextxy(0, length / 2 - 20, _T("Y"));
			outtextxy(length / 2 - 20, 0, _T("X"));

			// ���ƻ��ֶַ�
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
			break; // �����ж�����: ����ھ�����
			system("pause");
		}
	}
}


void graphErr()
{
	// ����������
	line(-length / 2, 0, length / 2, 0);
	line(0, -length / 2, 0, length / 2);
	outtextxy(0, length / 2 - 20, _T("Y"));
	outtextxy(length / 2 - 20, 0, _T("X"));

	printf("\n������߲������ݸ���: %d\n", arr_relerr.size());
	double scale_x = 2e3, scale_y = 5e2;
	double prex = 0, prey = 0;
	double minx = INT_MAX, miny = INT_MAX;
	setlinecolor(RGB(0, 150, 150));
	outtextxy(0, length / 4, _T("����������"));
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

	printf("\n�����Сֵ��: [r2x: %lf, error: %lf]\n", minx, miny);
	system("pause");
}




//int main()
//{
//	initgraph(length, length);
//	setorigin(length / 2, length / 2);
//
//	// ����������
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