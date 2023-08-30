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

int main()
{
	//int i;
	//cout << typeid(i).name() << endl;

	test1();

	return 0;
}