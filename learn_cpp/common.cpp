#define _CRT_SECURE_NO_WARNINGS
#include"head.h"


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
Date& Date::operator=(const Date& d)	//const,增加接受范围:比如临时的变量,具有常数性
{
	cout << "Date& operator=(Date& d)" << endl;
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

//获取当前时间相对0/1/1公元0年的天数 ==> 优化:相对2000/1/1
//画图:时间轴,2月分界
int Date::GetSumDay(const Date& d)	//bug:闰年多的一天没有计入 ==> 已修复
{
	Date tmp(d);
	int sumday = 0;

	//1.0	逐月累计天数+剩余零散天数
	//int sumday += tmp._day;
	//while (tmp._year >= 0)
	//{
	//	//上一月天数:前移一个月,日期格式合法化,加和此月天数
	//  
	//	tmp._month--;
	//	if (tmp._month <= 0)	//没有0月
	//	{
	//		tmp._year--;
	//		tmp._month = 12;
	//	}
	//	if (tmp._year >= 0)
	//	{
	//		sumday += GetMonthDay(tmp._year, tmp._month);
	//	}
	//}

	//2.0	逐年累计天数+剩余月份天数+剩余零散天数
	//相对2000/1/1
	while (tmp._year > 2000)
	{
		//从2000年后向前
		//月份小于等于2月:前年可能跨闰年	月份大于二月:今天可能跨闰年
		if (tmp._month <= 2)
		{
			if (((tmp._year - 1) % 4 == 0) && ((tmp._year - 1) % 100 != 0) || ((tmp._year - 1) % 400 == 0))
			{
				sumday += 366;
			}
			else
			{
				sumday += 365;
			}
		}

		if (tmp._month > 2)
		{
			if ((tmp._year % 4 == 0) && (tmp._year % 100 != 0) || (tmp._year % 400 == 0))
			{
				sumday += 366;
			}
			else
			{
				sumday += 365;
			}
		}

		tmp._year--;
	}

	while (tmp._year < 2000)
	{
		//从2000年向前走
		//月份小于等于2月:今天可能跨闰年	月份大于二月:明年可能跨闰年
		if (tmp._month <= 2)
		{
			if ((tmp._year % 4 == 0) && (tmp._year % 100 != 0) || (tmp._year % 400 == 0))
			{
				sumday -= 366;
			}
			else
			{
				sumday -= 365;
			}
		}

		if (tmp._month > 2)
		{
			if (((tmp._year + 1) % 4 == 0) && ((tmp._year + 1) % 100 != 0) || ((tmp._year + 1) % 400 == 0))
			{
				sumday -= 366;
			}
			else
			{
				sumday -= 365;
			}
		}

		tmp._year++;
	}

	if (tmp._year == 2000)
	{
		//+剩余零散天数
		sumday += tmp._day;
		tmp._month--;
		//+剩余月份天数
		while (tmp._month >= 1)
		{
			sumday += GetMonthDay(tmp._year, tmp._month);
			tmp._month--;
		}
	}

	return sumday;
}




//判断天数是否合法,是否需要进位:如需要,则进位
//注意区分this-> 和 d.
void Date::CheckValidDay(Date & d)
{
	int day = GetMonthDay(d._year, d._month);
	//合法
	if (d._day <= day && d._day > 0)	//日期天数没有0
	{
		return;
	}
	else
	{
		//调整,直到日期合法
		while (d._day > day)//想的是继续条件,写的是结束条件
		{
			//天
			d._day -= day;
			d._month++;
			//月
			if (d._month > 12)
			{
				d._month -= 12;
				d._year++;
			}
			day = GetMonthDay(d._year, d._month);
		}

		while (d._day <= 0)
		{
			//月
			d._month--;
			if (d._month <= 0)	//没有0月,这里之所以少"="能编译成功,
			{					//是因为每月天数的数组中0月对应0天,所以对天数没影响
				d._year--;
				d._month = 12;
			}
			//日
			day = GetMonthDay(d._year, d._month);
			d._day += day;	// (-15) + 30 = 15
		}
	}
}