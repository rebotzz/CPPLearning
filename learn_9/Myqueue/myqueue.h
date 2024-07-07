#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;


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
typedef int Qdata;
class MyQueue
{
public:
	//构造,析构,拷贝构造,复制重载都用默认生成的==>调用Stack的


	//入队
	void Push(Qdata x)
	{
		sPush.Push(x);
	}
	//出队
	void Pop()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//两个栈不全为空
		check();

		//spop栈不为空
		sPop.Pop();
	}

	//front元素
	Qdata Front()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//两个栈不全为空
		check();
		return sPop.Top();
	}
	//tail元素
	Qdata Tail()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//两个栈不全为空
		assert(!sPush.IsEmpty());
		return sPush.Top();
	}

	//元素个数
	int Size()
	{
		return sPush.Size() + sPop.Size();
	}

	//是否为空
	bool IsEmpty()
	{
		return sPush.IsEmpty() && sPop.IsEmpty();
	}

protected:
	//检查sPop栈是否为空,为空:将push传递到pop
	void check()
	{
		//判断spop栈是否为空
		if (sPop.IsEmpty())
		{
			//空,将spush栈内容传递到spop
			while (!sPush.IsEmpty())
			{
				sPop.Push(sPush.Top());
				sPush.Pop();
			}
		}
	}

private:
	Stack sPush;
	Stack sPop;
};