#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
using namespace std;

void test1()
{
	Date d1(2023, 5, 2);
	Date d2(2023, 5, 2);
	cout << (d1 == d2) << endl;
	Date d3 = d1;
	d3.print();

	//默认生成的只能浅拷贝
	Stack s1;
	s1.Push(1);
	s1.Push(2);

	////注意：如果类中未涉及到资源管理，赋值运算符是否实现都可以；
	////	一旦涉及到资源管理则必须要实现。
	Stack s2;
	s2 = s1;	//main函数结束,对象销毁,调用析构,重复free

	Stack s3(s1);
}

void test2()
{
	Date d1(2023, 5, 6);
	d1.print();
	++d1;
	d1.print();

	d1++.print();
	d1.print();
	Date d2 = d1;
	cout << (d2 == d1) << endl;
	cout << "d2:";
	d2.print();

	d1 += 31;
	d1.print();

	Date d3 = (d1 + 60);
	cout << "d3:";
	d3.print();
	cout << "d1:";
	d1.print();

	Date d4 = d1 - 365;
	cout << "d4:";
	d4.print();

	//d4 -= 50;
	//cout << "d4:";
	//d4.print();

	//cout << "d4:";
	//d4--.print();
	//d4.print();

	//--d4;
	//cout << "d4:";
	//d4.print();

	Date d5(1000, 1, 1);
	cout << "d5:";
	d5.print();
	//(--d5);
	//d5.print();

	//d2 = d1;
	cout << (d1 != d2) << endl;

	Date d6(2001,1,1);
	Date d7(2000,1,1);
	d7.print();
	int day = d6 - d7;
	cout << "day:" << day << endl;


	Date t1(2000, 3, 1);
	Date t2(2000, 2, 1);
	cout << "day:" << (t1 - t2) << endl;

}

int main()
{
	//test1();
	test2();

	return 0;
}

