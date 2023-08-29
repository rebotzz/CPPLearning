#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
using namespace std;

//void test1()
//{
//	cout << "common:a:" << &a << " " << a << endl;
//}


////类的作用域,声明和定义分离
//void PART::print()
//{
//	cout << _year << "-" << _month << "-" << _date << endl;
//}


////运算符重载 ==> 全局
////全局	==> 需要访问类成员变量,取消访问限定
//bool operator == (const Date& d1, const Date& d2)
//{
//	return d1._day == d2._day
//		&& d1._month == d2._month
//		&& d1._year == d2._year;
//}


//日期==日期
bool Date::operator == (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//日期=日期
Date& Date::operator=(Date& d)
{
	//跳过自己给自己赋值情况
	if (this != &d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
	}

	return *this;
}

//++日期
Date& Date::operator++()
{
	if (this != nullptr)
	{
		this->_day++;
	}
	return *this;
}

//日期++
Date Date::operator++(int)
{
	Date tmp(*this);
	this->_day++;
	return tmp;
}

//成员函数定义和声明分离
// 日期+=天数
// d1 += 15;
Date& Date::operator+=(int day)
{
	//修改d1,返回d1
	this->_day += day;
	CheckValidDay(*this);
	return *this;
}
// 日期+天数
// d2 = d1 + 200;
//tmp临时变量会销毁,所以返回值
Date Date::operator+(int day)
{
	//原来的d1不变,返回计算后结果给d2
	Date tmp(*this);
	tmp._day += day;
	CheckValidDay(tmp);
	return tmp;

}

//日期-天数
//d2 = d1 - 15
Date Date::operator-(int day)
{
	//d1不变,即this不变,返回修改后结果
	Date tmp(*this);
	tmp._day -= day;
	CheckValidDay(tmp);
	return tmp;
}
// 日期-=天数
// d1 -=15;
Date& Date::operator-=(int day)
{
	//在d1(this指针)上修改,返回d1
	this->_day -= day;
	CheckValidDay(*this);
	return *this;
}

// 后置--
//d1--
Date Date::operator--(int)
{
	//this,返回修改前的值
	Date tmp(*this);
	this->_day--;
	CheckValidDay(*this);
	return tmp;
}

// 前置--
//--d1
Date& Date::operator--()
{
	//this,返回修改后的值
	--(this->_day);
	CheckValidDay(*this);
	return *this;
}

// >运算符重载
// d2 > d1
bool Date::operator>(const Date& d)
{
	//this > d
	//年 
	if (this->_year > d._year)
	{
		return true;
	}
	else if (this->_year < d._year)
	{
		return false;
	}
	else	//年相等
	{
		//月 
		if (this->_month > d._month)
		{
			return true;
		}
		else if (this->_month < d._month)
		{
			return false;
		}
		else	//月相等
		{
			//日
			if (this->_day > d._day)
			{
				return true;
			}
			else if (this->_day < d._day)
			{
				return false;
			}
			else  //年月日都相等
			{
				return false;
			}
		}
	}
}

// >=运算符重载
// d1 >= d2
bool Date::operator >= (const Date& d)
{
	//this >= d  ==>  this > d 或 this == d
	return (*this == d) || (*this > d);
}

// <运算符重载
//d1 < d2
bool Date::operator < (const Date& d)
{
	//this 不>= d
	return !(*this >= d);
}

// <=运算符重载
//d1 <= d2
bool Date::operator <= (const Date& d)
{
	//this <= d	==> this < d 或 this == d
	return (*this < d) || (*this == d);
}
// !=运算符重载
//d1 != d2
bool Date::operator != (const Date& d)
{
	//this != d
	return !(*this == d);
}

// 日期-日期 返回天数
// day = d2 - d1	默认d2大于d1
// 15 = 2023-5-30 - 2023-5-15
int Date::operator-(const Date& d)
{
	//this - d
	int day = GetSumDay(*this) - GetSumDay(d);
	return day;
}

//获取当前时间相对0/0/0公元0年的天数
int Date::GetSumDay(const Date& d)	//bug:闰年多的一天没有计入
{
	Date tmp(d);
	int sumday = tmp._day;
	tmp._day = 0;
	while (tmp._year >= 0)
	{
		//上一月天数:前移一个月,日期格式合法化,加和此月天数
		tmp._month--;
		if (tmp._month <= 0)	//没有0月
		{
			tmp._year--;
			tmp._month = 12;
		}
		if (tmp._year >= 0)
		{
			sumday += GetMonthDay(tmp._year, tmp._month);
		}
	}
	return sumday;
}