//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
////
////class A
////{
////public:
////	A(int a = 1)
////		:_a1(a)
////		, _a2(_a1)  //按照声明顺序初始化
////	{}
////
////	void Print() {
////		cout << _a1 << " " << _a2 << endl;
////	}
////private:
////	int _a2;
////	int _a1;
////};
////
//////int main() {
//////    A aa(1);
//////    aa.Print();
//////}
////
////
////
//class Date
//{
//
//public:
//	//Date(int year = 1,int test = 0)
//	//Date(int year, int test = 0)
//	//explicit Date(int year = 1)     //explicit 修饰,不能发生隐式类型转化
//	Date(int year = 1)
//		:_year(year)
//	{
//		cout << "Date(int year = 10 )" << endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		cout << "Date& operator=(const Date& d)" << endl;
//		_year = d._year;
//		return *this;
//	}
//
//	void print()
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date d(0);
//	//Date d1(123);
//
//	d.print();
//	d = 120;    //隐式类型转化(构造函数单参数,或者可以只用输入一个参数):构造 + 赋值重载
//	d.print();
//
//	return 0;
//}
//
//
//
////友元类
//
//class Time
//{
//	friend class Date;		//友元类可以访问私有,不受到访问限定
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour*2 +5)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		//这里没有显示写,但是编译定义了_t,初始化
//	{}
//
//	void chTime(int hour = 0, int minute = 0, int second = 0)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << "  ";
//		cout << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
//	}
//
//	static void hello()
//	{
//		cout << "hello" << endl;
//	}
//	static int hehe;
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int Date::hehe = 13;
//
//
////int main()
////{
////	Date d1(2023, 5, 7);
////	
////	d1.print();
////
////	d1.chTime(15, 56, 20);
////	d1.print();
////
////	Date::hello();
////	cout << Date::hehe << endl;
////
////	Date().print();		//匿名对象
////
////	return 0;
////}
//
//
////内部类
//class Tree
//{
//
//public:
//	class SubTree	//收到访问限定符约束	内部类与外部类大小没有关系	内部是外部的友元类
//	{
//	public:
//		void print(const Tree& t)
//		{
//			cout << "Tree: " << t._high << " " << t._circle << endl;
//		}
//	private:
//		int _num;
//	};
//
//private:
//	int _high = 20;
//	int _circle = 5;
//};
//
//
////int main()
////{
////	cout << sizeof(Tree) << "  " << sizeof(Tree::SubTree) << endl;
////
////	int i = 0;
////	cout << typeid(i).name() << endl;
////
////	Tree t;
////	Tree::SubTree st;
////	st.print(t);
////}
//
//
////匿名对象
//#include <vector>
//
//class Sum
//{
//public:
//	Sum()
//	{
//		count += i;
//		++i;
//	}
//
//	static int count;
//private:
//	static int i;
//};
//int Sum::count = 0;
//int Sum::i = 1;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum arr[n];		//变长数组
//
//		//不使用变长数组的替代方案
//		for (int i = 1; i <= n; ++i)
//		{
//			Sum();		//匿名对象,生命周期只有这一行;
//		}
//		return Sum::count;
//	}
//};
//
////int main()
////{
////	cout << Solution().Sum_Solution(100);
////	return 0;
////}
//
//
//
