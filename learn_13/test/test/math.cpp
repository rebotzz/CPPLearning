#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

//Romberg积分算法	
//Function积分函数(函数对象)，Type数据类型
template<class Function, class Type = double>
class RombergIntegration
{
private:
	Type _a;
	Type _b;				//积分区间[_a,_b]
	Type _accy;				//精度
	Function& _func;			//被积函数，使用仿函数定义
	int K = 4;				//初始二分次数
	size_t _maxSize;
	//Type _table[30][30];	//1.0数据存储在栈上
	Type** _table;			//2.0数据存储在堆上  3.0使用vector,待续。。。
public:
	//积分区间a,b,积分精度accuracy,表格最大容量MaxSize
	RombergIntegration(Function& func, Type a, Type b, Type accuracy, size_t MaxSize = 30)
		: _a(a)
		, _func(func)
		, _b(b)
		, _accy(accuracy)
		, _maxSize(MaxSize)
	{
		//开辟二维数组，申请内存空间	MaxSize * MaxSize
		_table = new Type * [MaxSize];
		for (int i = 0; i < MaxSize; ++i)
		{
			_table[i] = new Type[MaxSize];
		}
	}

	~RombergIntegration()
	{
		//释放内存空间
		for (int i = 0; i < _maxSize; ++i)
		{
			delete[] _table[i];
		}
		delete[] _table;
	}

	Type integral()
	{
		//1.计算T0(h)
		Type h = _b - _a;		//初始步长,二分次数0
		Type T0 = h * (_func(_a) + _func(_b)) / 2;
		_table[0][0] = T0;
		//2.计算Tk((b-a)/2^k) 递推公式:Tk = 0.5*T(k-1)+新步长*新节点函数值
		for (int i = 1; i <= K; i++)
		{
			_table[i][0] = getIntegralValue(_table[i - 1][0], pow(2, i));
		}


		//3.求加速值Tk_m(h)，即：Sk,Ck,Rk。。。 理查德森外推法
		for (int mi = 1; mi <= K; mi++)			//列
		{
			for (int ki = mi; ki <= K; ki++)	//行
			{
				Type index = pow(4, mi);
				_table[ki][mi] = _table[ki][mi - 1] * index / (index - 1) - _table[ki - 1][mi - 1] / (index - 1);
			}
		}

		//4.精度检验
		//Type gap = _table[K][K] - _table[K - 1][K - 1];
		Type gap = _table[K][K] - _table[K][K - 1];
		if (gap < 0)
			gap *= -1;
		if (gap <= _accy)
		{
			return _table[K][K];
		}

		//如果误差限不满足要求，则继续更新table表
		else
		{
			//i代表行，j代表列
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
				Type gap = _table[i][i] - _table[i][i - 1];		//两种误差估计方法都可以
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

	//复化梯形求积	2.0
	Type getIntegralValue(Type preT, int newN)
	{
		Type sum = 0;
		Type h = (_b - _a) / newN;			//二分后新的步长
		int preN = newN / 2;
		for (int i = 1; i <= preN; ++i)
		{
			sum += h * _func(_a + (2 * i - 1) * h);
		}
		Type value = 0.5 * preT + sum;
		return value;
	}

	//输出table
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
	// 初始化变量
	double delta_l = 0.5;   // 直线L5与水平方向的距离    喷孔直径
	double lw = 108e-3;   // 碗口径
	double h = 23.9e-3;   // 凹坑深度
	double r2 = 19e-3;   // 凹坑半径
	double area_set = 4.3747866256303E-04;   // 给定面积

	// 圆R2方程f2 = Eq((x - r2x) * *2 + (y - r2y) * *2 - r2 * *2, 0) -> 未知:r2x
	double r2x = 0, r2y = h - r2;	  // 凹坑圆心纵坐标
    
	// 圆R1方程f3 = Eq((x - r1x) * *2 + (y - r1y) * *2 - r1 * *2, 0) -> 未知:r1
    double r1 = 0    ;		 // 圆R1半径   
    double r1x = lw, r1y = r1; // 圆R1圆心横坐标, 纵坐标


	//迭代直线L4的斜率: 倾斜角度
	double beta = 1.0;	//度°
	double inter12 = 0, inter23 = 0;	// f1和f2的交点,f2和f3的交点
	double area_todo = 0;
	for (; beta < 90.0; beta += 1.0)
	{
		// 直线L4方程f1: y = x * k - delta_l;	凹坑 -> f2: 
		// 直线与圆相切: 计算f2方程 r2x, f1和f2的交点 inter12		
		double tmp_x = (r2y + delta_l) / tan(beta * PI / 180);
		r2x = tmp_x + r2 / sin(beta * PI / 180);
		inter12 = r2x - r2 * sin(beta * PI / 180);

		// 两圆相切: 计算f3方程 r1, f2和f3的交点 inter23
		r1 = 0.5 * ((r1x - r2x) * (r1x - r2x) / (r2 + r2y) - r2 + r2y);
		double alpha = atan((r1y - r2y) / (r1x - r2x));
		inter23 = r2x + r2 * cos(alpha);

		// 求积分计算面积
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

	//	if (abs(area_set - area_todo) / area_set < 0.1) break; // 迭代判断条件: 面积在精度内
	//}
	}
}

//int main()
//{
//
//	return 0;
//}
