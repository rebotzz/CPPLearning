#include <iostream>
#include <string>
using namespace std;

//class Time
//{
//public:
//	//Time(int hour = 0)
//	Time(int hour)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// 要初始化_t 对象，必须通过初始化列表
//	Date(int year, int hour)
//		:_t(hour)
//	{
//		// 函数体内初始化
//		_year = year;
//		//Time t(hour);
//		//_t = t;
//	}
//private:
//	int _year;
//	Time _t;
//};
//
//int main()
//{
//	Date d(2022, 1);
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// 要初始化_t 对象，可以再函数体内赋值，但是还是会走初始化列表调用Time的默认构造
//	//Date(int year, int hour)
//	//{
//	//	// 函数体内初始化
//	//	_year = year;
//	//	Time t(hour);
//	//	_t = t;
//	//}
//
//
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		, _N(10)
//		, _ref(x)
//	{
//		// 函数体内初始化
//		_year = year;
//		_ref++;
//	}
//private:
//	int _year;
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//// 结论：自定义类型成员，推荐用初始化列表初始化
//// 初始化列表可以认为是成员变量定义的地方
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//	//const int N; // const必须在定义的地方初始化，只有一次机会
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////
//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//
//// 结论：自定义类型成员，推荐用初始化列表初始化
//// 初始化列表可以认为是成员变量定义的地方
//
//class Date
//{
//public:
//	//Date(int year, int hour, int& x)
//	//	: _N(10)
//	//	, _ref(x)
//	//{
//	//	// 函数体内初始化
//	//	_year = year;
//	//	_ref++;
//	//}
//	Date(int year, int hour, int& x)
//		:_year(year)
//		, _t(hour)
//		,_N(10)
//		, _ref(x)
//	{
//		_ref++;
//	}
//private:
//	// 声明
//	int _year = 0;  // C++11  缺省值-- 初始化时没有显示给值就会用这个缺省值
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	/*A(int N)
//		:_a((int*)malloc(sizeof(int)*N))
//		, _N(N)
//	{
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}*/
//
//	// 有些初始化工作还是必须在函数体内完成
//	A(int N)
//		:_N(N)
//	{
//		_a = (int*)malloc(sizeof(int)*N);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}
//private:
//	// 声明
//	int* _a;
//	int _N;
//};
//
//int main()
//{
//	A aa(10);
//
//	return 0;
//}

// 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//class A
//{
//public:
//	// 初始化按声明顺序初始化
//	A(int a)
//	// 成员变量定义
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	// 成员变量声明
//	int _a2;
//	int _a1;
//};
//
////A.输出1  1
////B.程序崩溃
////C.编译不通过
////D.输出1  随机值
//
//int main() {
//	// D
//	// 对象定义
//	A aa1(1);
//	aa1.Print();
//
//	A aa2(2);
//
//}

//////////////////////////////////////////////////////////////////////////
// explicit关键字 + 匿名对象
//class Date
//{
//public:
//	//explicit Date(int year)
//	Date(int year)
//		:_year(year)
//	{
//		cout << "	Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//};
//
////string(const char* str)
////{}
//
//void func(const string& s)
//{}
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		// ...
//		return 0;
//	}
//};
//
//int main()
//{
//	Date d1(2022);  // 直接调用构造
//	Date d2 = 2022; // 隐式类型转换：构造 + 拷贝构造 + 编译器优化 -》直接调用构造 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//
//	// 匿名对象 -- 声明周期只有这一行
//	Date(2000);
//
//	Date d4(2000);
//
//	// 匿名对象 一些使用场景
//	Solution slt;
//	slt.Sum_Solution(10);
//	Solution().Sum_Solution(10);
//
//	string s1("hello");
//	string s2 = "hello";
//
//	string str("insert");
//	func(str);
//	func("insert");
//
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////

//class A
//{
//public:
//	A() 
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//	// 静态成员函数 --  没有this指针
//	static int GetCount()
//	{
//		//_a = 1;
//
//		return _scount;
//	}
//
//private:
//	int _a;
//	// 静态成员变量，属于整个类，生命周期整个程序运行期间，存在静态取
//	static int _scount;  // 声明
//};
//
//// 类外面定义初始化
//int A::_scount = 0;
//
////int main()
////{
////	A a1;
////	A a2;
////	A a3(a2);
////
////	//cout << a1._scount << endl;
////	//cout << a2._scount << endl;
////	//cout << A::_scount << endl;
////
////	cout <<A::GetCount() << endl;
////
////	return 0;
////}
//
//// 设计一个只能在栈上定义对象的类
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		StackOnly so;
//		return so;
//	}
//
//private:
//	StackOnly(int x = 0, int y = 0)
//		:_x(x)
//		, _y(0)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//
//int main()
//{
//	//StackOnly so1; // 栈
//	//static StackOnly so2; // 静态区
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// 内部类
//class A
//{
//private:
//	int _h;
//	static int k;
//public:
//	// B定义在A的里面
//	// 1、受A的类域限制，访问限定符
//	// 2、B天生是A的友元
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._h << endl;//OK -- 友元
//		}
//	private:
//		int _b;
//	};
//};
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl; // 4
//	A a;
//	A::B b;
//
//	return 0;
//}
//

class W
{
public:
	W(int x = 0)
	{
		cout << "W()" << endl;
	}

	W(const W& w)
	{
		cout << "W(const W& w)" << endl;
	}

	W& operator=(const W& w)
	{
		cout << "W& operator=(const W& w)" << endl;
		return *this;
	}

	~W()
	{
		cout << "~W()" << endl;
	}
};

void f1(W w)
{

}

void f2(const W& w)
{

}

//int main()
//{
//	W w1;
//	f1(w1);
//	f2(w1);
//	cout << endl << endl;
//
//	f1(W()); // 本来构造+拷贝构造--编译器的优化--直接构造
//	// 结论：连续一个表达式步骤中，连续构造一般都会优化 -- 合二为一
//
//	W w2 = 1;
//
//	return 0;
//}

W f3()
{
	W ret;
	return ret;
}

// 《深度探索C++对象模型》
//int main()
//{
//	f3(); // 1次构造  1次拷贝
//	cout << endl << endl;
//
//	W w1 = f3(); // 本来：1次构造  2次拷贝 -- 优化：1次构造  1次拷贝
//
//	cout << endl << endl;
//
//	W w2;
//	w2 = f3(); // 本来：1次构造  1次拷贝 1次赋值
//
//	return 0;
//}

//W f(W u)
//{
//	//cout << "--------" << endl;
//	W v(u);
//	W w = v;
//	//cout << "--------" << endl;
//	return w;
//}
//
//int main()
//{
//	W x;
//	W y = f(f(x)); // 1次构造  7次拷贝  or  1次构造  5次拷贝
//
//	return 0;
//}

//int main()
//{
//	W x;
//	W y = f(x); // 1次构造  4次拷贝
//
//	return 0;
//}