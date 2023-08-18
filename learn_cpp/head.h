#pragma once
#include <iostream>

extern int size;	//声明
static int a = 2;	//定义,仅当前文件可见,不会放入符号表,不同文件下调用地址不同,各自有一个


//缺省参数在声明处缺省
void func(int a, int b = 3);


void test1();