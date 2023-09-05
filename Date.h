#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//日期类
class Date
{
public:

	//构造函数,对象实例化时自动调用,初始化成员
	Date(int year = 1, int month = 1, int day = 1)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;

		//检查日期合法性
		if (!CheckDate())
		{
			cout << "所构造日期非法" << endl;
		}
		assert(CheckDate());
	}

	//拷贝构造函数		默认浅拷贝够用
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//析构函数		无资源需要释放,默认够用
	//~Date()
	//{

	//}

	//打印日期
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;

	}

	//成员函数定义和声明分离
	//日期==日期
	bool operator == (const Date& d);

	//日期 = 日期
	Date& operator=(const Date& d);

	//++日期
	Date& operator++();

	//日期++
	Date operator++(int);

	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);

	// 日期--
	Date operator--(int);
	// --日期
	Date& operator--();

	// 日期>日期
	bool operator>(const Date& d);

	// 日期>=日期
	bool operator >= (const Date& d);

	// 日期<日期
	bool operator < (const Date& d);
	// 日期<=日期
	bool operator <= (const Date& d);
	// 日期!=日期
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);


protected:
	//获取某年某月的天数
	//频繁调用,inline
	int GetMonthDay(int year, int month)
	{
		//每月天数,常用,static
		static int mday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//判断时候是闰年2月:闰年%4,!%100,或 %400
		if (month == 2
			&& ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))	//注意条件
		{
			//std::cout << "闰年二月:" << std::endl;
			return 29;
		}
		else
		{

			return mday[month];
		}
	}

	//检查日期合法性
	bool CheckDate()
	{
		if(_year > 0 
			&& (_month > 0 && _month < 13)
			&& (_day > 0 && _day <= GetMonthDay(_year, _month)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	//内置类型
	int _year;
	int _month;
	int _day;
};