#include <iostream>
#include <assert.h>
using namespace std;

class Time
{
	friend class Date;	//友元类
public:
	Time(int hour)
		:_hour(hour)
	{
	}
private:
	int _hour;
};

//日期类
class Date
{

public:

	//构造函数,对象实例化时自动调用,初始化成员
	Date(int year = 1, int month = 1, int day = 1,int hour = 1)
		:_year(year)	//初始化列表
		,_month(month)
		,_day(day)
		,_time(hour)
		,_cn(0)
	{
		//Time tmp(15);
		//_time = tmp;

		count++;
	}

	//void print(const Date* this) 
	void print() const
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
		cout << _time._hour << endl;

	}


	//static成员变量
	static int count;

	//static成员函数
	static int sum()
	{
		return num;	//不能访问成员,没有this 指针
	}

private:
	//内置类型
	int _year;
	int _month;
	int _day;
	const int _cn;

	//自定义
	Time _time;	

	//受到访问限定
	static int num;
};

//只能在类外面初始化
int Date::count = 0;
int Date::num = 1;

class A
{
public:
	A(int& a,int b = 0)
		:_a(a)
		,_b(b)
	{
		_a = 10;
		cout << _a << endl;
	}
private:
	int& _a;
	int _b;
};


//int main()
//{
//	Date d1, d2, d3, d4;
//	cout << Date::count << endl;
//	//cout << Date::num;
//
//	Date d5;
//	d5.print();
//
//	int a = 3;
//	int b = 2;
//	A aa(a, 2);
//	cout << a << endl;
//
//	return 0;
//}