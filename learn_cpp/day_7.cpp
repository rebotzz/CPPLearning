#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "head.h"
using namespace std;


void test1()
{
	Date d1(2023, 1, 1);
	Date d2;
	d2 = d1;
	d1.print();
	d2.print();

	Date d3(2023, 8, 30);
	d2 = d3;
	d2.print();

	Date d4(d1);
	Date d5 = d1;	//拷贝构造
	d5.print();

	d5 = d1 + 3;	//d1 + 3 的结果是一个临时的变量,具有常数性
	d5.print();
}

void test2()
{
	Date d1(2023, 8, 31);
	Date d2;
	d2 = d1;	//d2.operator=(d1);	this指针隐藏
	(++d2).print();
	//(d2++).print();
	(--d2).print();
	//(d2--).print();

	//cout << (d1 >= d2) << endl;


	(d2 + 50).print();
	(d2 + 500).print();
	(d2 + 5000).print();
	(d2 + 50000).print();

	cout << endl;
	d2 -= 50;
	d2.print();
	d2 -= 500;
	d2.print();
	d2 -= 5000;
	d2.print();
	d2 -= 50000;
	d2.print();
	cout << endl;

	d2 = d1;
	(d2 - 50).print();
	(d2 - 500).print();
	(d2 - 5000).print();
	(d2 - 50000).print();
	cout << endl;

	d2 += 5087640;
	d2.print();
	cout << (d1 - d2) << endl;

	cout << endl;
	Date d3(1999, 3, 7);
	cout << (d1 - d3) << endl;
	d3.operator+=(1);
	d3.print();
}


int main()
{
	//int i;
	//cout << typeid(i).name() << endl;

	//test1();
	test2();

	return 0;
}