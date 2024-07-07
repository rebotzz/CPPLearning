#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//栈
// last in first out 
// 后进先出,先进后出
////静态
//#define MAX 100
//typedef struct stack
//{
//	STDatatype _data[MAX];
//	int _size;
//	int _capacity;
//}stack;
//动态,数组
typedef int STDatatype;
typedef struct stack
{
	STDatatype* data;
	int size;
	int capacity;
}stack;

//初始化
void StackInit(stack* ps);

//入栈
void StackPush(stack* ps, STDatatype x);

//出栈
void StackPop(stack* ps);
//读取,需要,不直接操作栈,通过接口函数
STDatatype StackTop(stack* ps);
//销毁
void StackDestroy(stack* ps);
//是否为空
bool StackEmpty(stack* ps);
//大小
int StackSize(stack* ps);
