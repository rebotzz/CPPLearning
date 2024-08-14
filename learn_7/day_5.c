//#define _CRT_SECURE_NO_WARNINGS
//
//
////20. 有效的括号
////给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
////有效字符串需满足：
////左括号必须用相同类型的右括号闭合。
////左括号必须以正确的顺序闭合。
////每个右括号都有一个对应的相同类型的左括号。
//
//// 括号匹配问题。
//// 思路分析:利用栈后进先出的特点,匹配最近相邻符号
//// 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
////栈
//// last in first out 
//// 后进先出,先进后出
////动态,数组
//typedef int STDatatype;
//typedef struct stack
//{
//	STDatatype* data;
//	int size;
//	int capacity;
//}stack;
//
//
////初始化
//void StackInit(stack* ps)
//{
//	assert(ps);
//	ps->data = (STDatatype*)malloc(4 * sizeof(STDatatype));
//	if (ps->data == NULL)
//	{
//		perror("stackInit");
//		exit(-1);
//	}
//	//ps->size 可以初始化为-1或者0;-1时表示ps->size就是栈顶,0时表示ps->size是栈顶的下一个元素;
//	ps->size = 0;
//	ps->capacity = 4;
//}
//
////入栈
//void StackPush(stack* ps, STDatatype x)
//{
//	assert(ps);
//	//容量判断
//	if (ps->size == ps->capacity)
//	{
//		ps->capacity *= 2;
//		STDatatype* tmp = (STDatatype*)realloc(ps->data, ps->capacity * sizeof(STDatatype));
//		if (tmp == NULL)
//		{
//			perror("realloc");
//			exit(-1);
//		}
//		else
//		{
//			ps->data = tmp;
//			tmp = NULL;
//		}
//	}
//
//	//ps->size表示栈顶的下一个
//	ps->data[ps->size] = x;
//	ps->size++;
//}
//
////出栈
//void StackPop(stack* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//	ps->size--;
//}
////读取,需要吗?
//STDatatype StackTop(stack* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//	return ps->data[ps->size - 1];
//}
////销毁
//void StackDestroy(stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->capacity = ps->size = 0;
//
//}
////是否为空
//bool StackEmpty(stack* ps)
//{
//	assert(ps);
//	if (ps->size == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
////大小
//int StackSize(stack* ps)
//{
//	return ps->size;
//}
//
////利用栈实现
//bool isValid(char* s) {
//	//创建栈
//	stack st;
//	StackInit(&st);
//
//
//	while (*s)
//	{
//		//左括号入栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//		}
//		//初始右括号情况
//		else if ((*s == ']' || *s == ')' || *s == '}') && StackEmpty(&st))
//		{
//			return false;
//		}
//		//右括号判断是否和栈顶匹配
//		else
//		{
//			if (StackTop(&st) == '(' && *s != ')')
//			{
//				return false;
//			}
//			if (StackTop(&st) == '[' && *s != ']')
//			{
//				return false;
//			}
//			if (StackTop(&st) == '{' && *s != '}')
//			{
//				return false;
//			}
//			//括号匹配,出栈
//			StackPop(&st);
//		}
//		//s++
//		s++;
//	}
//
//	//正确条件:栈为空,S到尽头
//	if (StackEmpty(&st) && *s == '\0')
//	{
//		return true;
//	}
//	return false;
//}




//2.0	细微优化
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//栈
// last in first out 
// 后进先出,先进后出
//动态,数组
typedef int STDatatype;
typedef struct stack
{
	STDatatype* data;
	int size;
	int capacity;
}stack;


//初始化
void StackInit(stack* ps)
{
	assert(ps);
	ps->data = (STDatatype*)malloc(4 * sizeof(STDatatype));
	if (ps->data == NULL)
	{
		perror("stackInit");
		exit(-1);
	}
	//ps->size 可以初始化为-1或者0;-1时表示ps->size就是栈顶,0时表示ps->size是栈顶的下一个元素;
	ps->size = 0;
	ps->capacity = 4;
}

//入栈
void StackPush(stack* ps, STDatatype x)
{
	assert(ps);
	//容量判断
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		STDatatype* tmp = (STDatatype*)realloc(ps->data, ps->capacity * sizeof(STDatatype));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		else
		{
			ps->data = tmp;
			tmp = NULL;
		}
	}

	//ps->size表示栈顶的下一个
	ps->data[ps->size] = x;
	ps->size++;
}

//出栈
void StackPop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//读取,需要吗?
STDatatype StackTop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	return ps->data[ps->size - 1];
}
//销毁
void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->size = 0;

}
//是否为空
bool StackEmpty(stack* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//大小
int StackSize(stack* ps)
{
	return ps->size;
}

//利用栈实现
bool isValid(char* s) {
	//创建栈
	stack st;
	StackInit(&st);

	bool ret = false;
	while (*s)
	{
		//左括号入栈
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		//初始右括号情况
		else if ((*s == ']' || *s == ')' || *s == '}') && StackEmpty(&st))
		{
			ret = false;
			break;
		}
		//右括号判断是否和栈顶匹配
		else
		{
			if (StackTop(&st) == '(' && *s != ')')
			{
				ret = false;
				break;
			}
			if (StackTop(&st) == '[' && *s != ']')
			{
				ret = false;
				break;
			}
			if (StackTop(&st) == '{' && *s != '}')
			{
				ret = false;
				break;
			}
			//括号匹配,出栈
			StackPop(&st);
		}
		//s++
		s++;
	}

	//正确条件:栈为空,S到尽头
	//清空栈
	if (StackEmpty(&st) && *s == '\0')
	{
		ret = true;
	}
	StackDestroy(&st);
	return ret;
}