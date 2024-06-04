//#include<iostream>
//using namespace std;
#pragma once
#include <stdio.h>

//条件编译,CPP的宏,C不进行编译
#ifdef __cplusplus
extern "C"
{
#endif

	void print_hello();

#ifdef __cplusplus
}
#endif

