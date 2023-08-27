#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
using namespace std;

void test1()
{
	cout << "common:a:" << &a << " " << a << endl;
}


//类的作用域,声明和定义分离
void PART::print()
{
	cout << _year << "-" << _month << "-" << _date << endl;
}


