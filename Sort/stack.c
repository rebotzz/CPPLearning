#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

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
		STDatatype* tmp = (STDatatype*)realloc(ps->data,ps->capacity * sizeof(STDatatype));
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