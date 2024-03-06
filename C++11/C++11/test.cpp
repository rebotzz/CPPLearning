#include <iostream>

using namespace std;

class A
{
public:
	void f()
	{
		cout << "A" << endl;
	}

	A(int a = 10):_a(a)
	{}

	int _a;
};

//使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public
class B : A	// 这里默认private继承
//class B : public A	
{
public:
	void f(int)	// 函数名相同，继承，-- 隐藏
	{
		cout << "B" << endl;
	}

	void test()
	{
		cout << _a << " " << _b << endl;
	}

	// 先调用A构造
	B(int b = 11, int a = 102) :_b(b)//,A(a)	
	{}

	int _b;
};

class C
{

};

class D : public C
{

};


//int main()
//{
//	B b;
//	b.test();
//	//b.f();
//	//b.f(1);
//	//b.A::f();	// 会先隐藏
//	return 0;
//}