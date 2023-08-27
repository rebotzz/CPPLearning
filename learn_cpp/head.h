#pragma once
#include <iostream>
#include <assert.h>

extern int size;	//声明
static int a = 2;	//定义,仅当前文件可见,不会放入符号表,不同文件下调用地址不同,各自有一个


//缺省参数在声明处缺省
void func(int a, int b = 3);


void test1();

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

	//构造函数,对象实例化时自动调用,初始化成员
	//可以构成重载
	//默认构造函数:1.不定义,编译器自动生成;2.自定义无参构造函数;3.自定义全缺省构造函数;
	//自定义全缺省构造函数 -> 更加方便
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
	//日期类不用,未定义时编译器自动生成的就够用 ==> 浅拷贝
	//自己实现 ==> 深拷贝 避免:1.指针指向同一地址 2.重复free
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//打印日期
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}

private:
	int _year;
	int _month;
	int _day;
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

	//析构函数销毁栈
	~Stack()
	{
		std::cout << "~Stack" << std::endl;
		assert(_a);
		free(_a);
		//下面随对象销毁而销毁,可以不用清理
		_a = nullptr;
		_capacity = _top = 0;
	}

	//入栈
	void Push(StData x)
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