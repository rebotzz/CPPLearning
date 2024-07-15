#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

//Romberg�����㷨	
//Function���ֺ���(��������)��Type��������
template<class Function, class Type = double>
class RombergIntegration
{
private:
	Type _a;
	Type _b;				//��������[_a,_b]
	Type _accy;				//����
	Function& _func;			//����������ʹ�÷º�������
	int K = 4;				//��ʼ���ִ���
	size_t _maxSize;
	//Type _table[30][30];	//1.0���ݴ洢��ջ��
	Type** _table;			//2.0���ݴ洢�ڶ���  3.0ʹ��vector,����������
public:
	//��������a,b,���־���accuracy,����������MaxSize
	RombergIntegration(Function& func, Type a, Type b, Type accuracy, size_t MaxSize = 30)
		: _a(a)
		, _func(func)
		, _b(b)
		, _accy(accuracy)
		, _maxSize(MaxSize)
	{
		//���ٶ�ά���飬�����ڴ�ռ�	MaxSize * MaxSize
		_table = new Type * [MaxSize];
		for (int i = 0; i < MaxSize; ++i)
		{
			_table[i] = new Type[MaxSize];
		}
	}

	~RombergIntegration()
	{
		//�ͷ��ڴ�ռ�
		for (int i = 0; i < _maxSize; ++i)
		{
			delete[] _table[i];
		}
		delete[] _table;
	}

	Type integral()
	{
		//1.����T0(h)
		Type h = _b - _a;		//��ʼ����,���ִ���0
		Type T0 = h * (_func(_a) + _func(_b)) / 2;
		_table[0][0] = T0;
		//2.����Tk((b-a)/2^k) ���ƹ�ʽ:Tk = 0.5*T(k-1)+�²���*�½ڵ㺯��ֵ
		for (int i = 1; i <= K; i++)
		{
			_table[i][0] = getIntegralValue(_table[i - 1][0], pow(2, i));
		}


		//3.�����ֵTk_m(h)������Sk,Ck,Rk������ ����ɭ���Ʒ�
		for (int mi = 1; mi <= K; mi++)			//��
		{
			for (int ki = mi; ki <= K; ki++)	//��
			{
				Type index = pow(4, mi);
				_table[ki][mi] = _table[ki][mi - 1] * index / (index - 1) - _table[ki - 1][mi - 1] / (index - 1);
			}
		}

		//4.���ȼ���
		//Type gap = _table[K][K] - _table[K - 1][K - 1];
		Type gap = _table[K][K] - _table[K][K - 1];
		if (gap < 0)
			gap *= -1;
		if (gap <= _accy)
		{
			return _table[K][K];
		}

		//�������޲�����Ҫ�����������table��
		else
		{
			//i�����У�j������
			int i = K + 1;
			while (gap > _accy)
			{
				_table[i][0] = getIntegralValue(_table[i - 1][0], pow(2, i));
				for (int j = 1; j <= i; j++)
				{
					Type index = pow(4, j);
					_table[i][j] = _table[i][j - 1] * index / (index - 1) - _table[i - 1][j - 1] / (index - 1);
				}

				//Type gap = _table[i][i] - _table[i - 1][i - 1];
				Type gap = _table[i][i] - _table[i][i - 1];		//���������Ʒ���������
				if (gap < 0)
					gap *= -1;
				if (gap <= _accy)
				{
					K = i;
					return _table[i][i];
				}
			}
		}
	}

	//�����������	2.0
	Type getIntegralValue(Type preT, int newN)
	{
		Type sum = 0;
		Type h = (_b - _a) / newN;			//���ֺ��µĲ���
		int preN = newN / 2;
		for (int i = 1; i <= preN; ++i)
		{
			sum += h * _func(_a + (2 * i - 1) * h);
		}
		Type value = 0.5 * preT + sum;
		return value;
	}

	//���table
	void print()
	{
		cout << "------------------------------------------------------------------" << endl;
		cout << "k " << "   T     " << "    S     " << "   C     " << "    R    " << endl;
		for (int i = 0; i <= K; i++)
		{
			cout << i << " ";
			for (int j = 0; j <= i; j++)
			{
				//if (j <= 3)
				{
					cout << _table[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "------------------------------------------------------------------" << endl;
		cout << "this is result: " << _table[K][K] << endl;
	}
};

void calculate()
{
#define PI 3.14159265
	// ��ʼ������
	double delta_l = 0.5;   // ֱ��L5��ˮƽ����ľ���    ���ֱ��
	double lw = 108e-3;   // ��ھ�
	double h = 23.9e-3;   // �������
	double r2 = 19e-3;   // ���Ӱ뾶
	double area_set = 4.3747866256303E-04;   // �������

	// ԲR2����f2 = Eq((x - r2x) * *2 + (y - r2y) * *2 - r2 * *2, 0) -> δ֪:r2x
	double r2x = 0, r2y = h - r2;	  // ����Բ��������
    
	// ԲR1����f3 = Eq((x - r1x) * *2 + (y - r1y) * *2 - r1 * *2, 0) -> δ֪:r1
    double r1 = 0    ;		 // ԲR1�뾶   
    double r1x = lw, r1y = r1; // ԲR1Բ�ĺ�����, ������


	//����ֱ��L4��б��: ��б�Ƕ�
	double beta = 1.0;	//�ȡ�
	double inter12 = 0, inter23 = 0;	// f1��f2�Ľ���,f2��f3�Ľ���
	double area_todo = 0;
	for (; beta < 90.0; beta += 1.0)
	{
		// ֱ��L4����f1: y = x * k - delta_l;	���� -> f2: 
		// ֱ����Բ����: ����f2���� r2x, f1��f2�Ľ��� inter12		
		double tmp_x = (r2y + delta_l) / tan(beta * PI / 180);
		r2x = tmp_x + r2 / sin(beta * PI / 180);
		inter12 = r2x - r2 * sin(beta * PI / 180);

		// ��Բ����: ����f3���� r1, f2��f3�Ľ��� inter23
		r1 = 0.5 * ((r1x - r2x) * (r1x - r2x) / (r2 + r2y) - r2 + r2y);
		double alpha = atan((r1y - r2y) / (r1x - r2x));
		inter23 = r2x + r2 * cos(alpha);

		// ����ּ������
		auto f1 = [](double x, double _beta, double _delta_l) {return x * tan(_beta * PI / 180) - _delta_l; };
		auto f2 = [](double x, double _r2, double _r2x, double _r2y) {return sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y; };
		auto f3 = [](double x, double _r1, double _r1x, double _r1y) {return -sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y; };
		//struct f1 {
		//	double operator()(double x, double _beta, double delta_l) 
		//	{ return x * tan(_beta * PI / 180) - delta_l; }
		//};
		//struct f2 {
		//	double operator()(double x, double _r2, double _r2x, double _r2y) 
		//	{ return sqrt(_r2 * _r2 - (x - _r2x) * (x - _r2x)) + _r2y; }
		//};
		//struct f3 {
		//	double operator()(double x, double _r1, double _r1x, double _r1y) 
		//	{ return -sqrt(_r1 * _r1 - (x - _r1x) * (x - _r1x)) + _r1y; }
		//};


	//	using namespace placeholders;
	//	function<double(double)> func1 = bind(f1, placeholders::_1, beta, delta_l);
	//	function<double(double)> func2 = bind(f2, placeholders::_1, r2, r2x, r2y);
	//	function<double(double)> func3 = bind(f3, placeholders::_1, r1, r1x, r1y);
	//	
	//	using Type = double(*)(double);
	//	area_todo = RombergIntegration<Type, double>(func1, 0, inter12).integral();

	//	if (abs(area_set - area_todo) / area_set < 0.1) break; // �����ж�����: ����ھ�����
	//}
	}
}

//int main()
//{
//
//	return 0;
//}
