#define _CRT_SECURE_NO_WARNINGS
#include"cpp.h"
#include<iostream>
using namespace std;

void print_hello()
{
	//printf("hello world\n");
	cout << "hello world" << endl;
	int a[] = { 1,2,3,4,5 };
	for (auto& e : a)
	{
		e++;
	}
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

