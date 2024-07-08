#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

extern int size;	//声明
static int a = 2;	//定义,仅当前文件可见,不会放入符号表,不同文件下调用地址不同,各自有一个


////缺省参数在声明处缺省
//void func(int a, int b = 3);
//
//
//void test1();

//作用域:局部优先,如果局部没有,再到全局寻找
//类的作用域,声明和定义分离
class PART
{
public:
	void print();

private:
	//不是定义,是声明,后面是缺省值,由默认构造函数使用
	int _year = 2023;
	int _month = 7;
	int _date = 7;

};

//时间类
class Time
{
public:
	//默认构造函数(初始化)
	Time()
	{
		_hour = 0;
		_minute = 0;
		_second = 0;
	}

	//赋值运算符=
	Time& operator=(const Time& t)
	{
		if (this != &t)
		{
			_hour = t._hour;
			_minute = t._minute;
			_second = t._second;
		}
		//std::cout << "Time& operator=(Time& t)" << std::endl;

		return *this;
	}

private:
	//声明,缺省值(默认值)
	//int _hour = 0;
	//int _minute = 0;
	//int _second = 0;
	int _hour;
	int _minute;
	int _second;
};

//日期类
class Date
{
public:
	//初始化	->	缺点,容易忘记使用 -> 解决:构造函数
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date()//不行,编译失败,与全缺省冲突 ==>都算是默认构造函数
	//{
	//}

	//构造函数,对象实例化时自动调用,初始化成员
	//可以构成重载
	//默认构造函数:1.不定义,编译器自动生成;2.自定义无参构造函数;3.自定义全缺省构造函数;
	//自定义全缺省构造函数 -> 更加方便
	//频繁调用,放在类里定义:inline内联
	Date(int year = 0, int month = 0, int day = 0)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	//析构函数,对象销毁时自动调用,完成资源的释放
	//不能重载
	//可以自定义,不定义编译器自动生成:1.内置类型(基础类型)不做处理;2.自定义类型调用它对应的析构函数
	~Date()
	{
		//日期类可不用
	}

	//拷贝构造函数
	//是构造函数的重载
	//不能传值,只能传引用,不然会发生无穷递归
	//Date(Date d)	//error
	// 不用返回类型,对象创建时this指针解决
	//日期类不用,未定义时编译器自动生成的就够用 ==> 浅拷贝
	//自己实现 ==> 深拷贝 避免:1.指针指向同一地址 2.重复free
	Date(const Date& d)
	{
		cout << "Date(const Date& d)" << endl;
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//打印日期
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;

	}

	

	//成员函数定义和声明分离
	// 
	//==运算符重载 ==>成员函数
	//类作用域:这里类成员变量私有也可以访问
	//bool operator == (Date* const this, const Date& d)
	bool operator == (const Date& d);

	//赋值= 运算符重载
	//赋值运算符如果不显式实现，编译器会生成一个默认的 ==>浅拷贝
	Date& operator=(const Date& d);

	//运算符重载	前置++
	//Date& const this指针
	//不销毁,传递引用返回,提高效率
	Date& operator++();

	//运算符重载	后置++	用(int)区分前后++
	//Date& const this指针
	//tmp,栈上局部变量,函数结束销毁,所以传值返回
	Date operator++(int);

	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);

	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// >=运算符重载
	bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
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

	//判断天数是否合法,是否需要进位:如需要,则进位
	//注意区分this-> 和 d.
	void CheckValidDay(Date& d);

	//获取当前时间相对0/0/0公元0年的天数
	int GetSumDay(const Date& d);

private:
	//内置类型
	int _year;
	int _month;
	int _day;
	//自定义类型
	Time _t;	//自定义类型作为类成员时:编译器生成的默认构造函数调用它的默认构造函数
};




//类: 栈
typedef int StData;
class Stack
{
public:
	//接口函数
	// 
	//构造函数初始化
	Stack(int capacity = 3)
	{
		std::cout << "Stack" << std::endl;
		StData* tmp = (StData*)malloc(sizeof(StData) * capacity);
		if (nullptr == tmp)
		{
			perror("malloc error");
			exit(-1);
		}
		_a = tmp;
		_capacity = capacity;
		_top = 0;
	}

	//拷贝构造函数	==> 深拷贝
	Stack(const Stack& s)
	{
		StData* tmp = (StData*)realloc(this->_a, sizeof(StData) * s._capacity);//realloc会销毁原空间
		if (nullptr == tmp)
		{
			perror("Stack(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
	}

	//析构函数销毁栈
	~Stack()
	{
		std::cout << "~Stack:" << this << std::endl;
		assert(_a);
		free(_a);
		//下面随对象销毁而销毁,可以不用清理
		_a = nullptr;
		_capacity = _top = 0;
	}

	//入栈
	void Push(const StData& x)	//优化:StData x ==> const StData& x
	{
		//虽然我觉的似乎不用assert也行,实例化对象就会创建_a,除非没有实例化
		assert(_a);
		//检查空间是否足够,不够就增容
		Cheak();
		_a[_top] = x;
		_top++;
	}

	//出栈
	void Pop()
	{
		assert(_a);
		assert(_top > 0);
		_top--;
	}
	//判空
	bool IsEmpty()
	{
		assert(_a);
		return _top == 0;
	}

	//大小
	int Size()
	{
		assert(_a);
		return _top;
	}
	//读取Top
	StData Top()
	{
		assert(_a);
		assert(_top > 0);
		return _a[_top - 1];
	}

	//有资源管理(申请资源malloc),需要自定义赋值运算符重载
	Stack& operator=(const Stack& s)
	{
		StData* tmp = (StData*)realloc(_a, sizeof(StData) * s._capacity);//realloc会销毁原空间
		if (nullptr == tmp)
		{
			perror("Stack& operator=(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			//std::cout << "_a:" << _a << std::endl;
			//free(_a);//realloc会销毁原空间
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
	}

protected:
	//检查空间是否足够,不够就增容
	void Cheak()
	{
		if (_capacity == _top)
		{
			_capacity *= 2;
			StData* tmp = (StData*)realloc(_a, sizeof(StData) * _capacity);//别忘了乘sizeof(StData)
			if (nullptr == tmp)
			{
				perror("realloc error");
				exit(-1);
			}
			_a = tmp;
			tmp = nullptr;
		}
	}

private:
	//动态数值实现
	StData* _a;
	int _capacity;
	int _top;
};



//类: 队列(两个栈实现队列)
class MyQueue
{
public:
	void print()
	{
		s1.Push(1);
		std::cout << s1.Size() << std::endl;
	}
private:
	Stack s1;
	Stack s2;
};


//全局
//bool operator == (const Date& d1, const Date& d2);