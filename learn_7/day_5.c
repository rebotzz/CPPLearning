//#define _CRT_SECURE_NO_WARNINGS
//
//
////20. ��Ч������
////����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
////��Ч�ַ��������㣺
////�����ű�������ͬ���͵������űպϡ�
////�����ű�������ȷ��˳��պϡ�
////ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
//
//// ����ƥ�����⡣
//// ˼·����:����ջ����ȳ����ص�,ƥ��������ڷ���
//// 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
////ջ
//// last in first out 
//// ����ȳ�,�Ƚ����
////��̬,����
//typedef int STDatatype;
//typedef struct stack
//{
//	STDatatype* data;
//	int size;
//	int capacity;
//}stack;
//
//
////��ʼ��
//void StackInit(stack* ps)
//{
//	assert(ps);
//	ps->data = (STDatatype*)malloc(4 * sizeof(STDatatype));
//	if (ps->data == NULL)
//	{
//		perror("stackInit");
//		exit(-1);
//	}
//	//ps->size ���Գ�ʼ��Ϊ-1����0;-1ʱ��ʾps->size����ջ��,0ʱ��ʾps->size��ջ������һ��Ԫ��;
//	ps->size = 0;
//	ps->capacity = 4;
//}
//
////��ջ
//void StackPush(stack* ps, STDatatype x)
//{
//	assert(ps);
//	//�����ж�
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
//	//ps->size��ʾջ������һ��
//	ps->data[ps->size] = x;
//	ps->size++;
//}
//
////��ջ
//void StackPop(stack* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//	ps->size--;
//}
////��ȡ,��Ҫ��?
//STDatatype StackTop(stack* ps)
//{
//	assert(ps);
//	assert(ps->size > 0);
//	return ps->data[ps->size - 1];
//}
////����
//void StackDestroy(stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->capacity = ps->size = 0;
//
//}
////�Ƿ�Ϊ��
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
////��С
//int StackSize(stack* ps)
//{
//	return ps->size;
//}
//
////����ջʵ��
//bool isValid(char* s) {
//	//����ջ
//	stack st;
//	StackInit(&st);
//
//
//	while (*s)
//	{
//		//��������ջ
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//		}
//		//��ʼ���������
//		else if ((*s == ']' || *s == ')' || *s == '}') && StackEmpty(&st))
//		{
//			return false;
//		}
//		//�������ж��Ƿ��ջ��ƥ��
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
//			//����ƥ��,��ջ
//			StackPop(&st);
//		}
//		//s++
//		s++;
//	}
//
//	//��ȷ����:ջΪ��,S����ͷ
//	if (StackEmpty(&st) && *s == '\0')
//	{
//		return true;
//	}
//	return false;
//}




//2.0	ϸ΢�Ż�
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//ջ
// last in first out 
// ����ȳ�,�Ƚ����
//��̬,����
typedef int STDatatype;
typedef struct stack
{
	STDatatype* data;
	int size;
	int capacity;
}stack;


//��ʼ��
void StackInit(stack* ps)
{
	assert(ps);
	ps->data = (STDatatype*)malloc(4 * sizeof(STDatatype));
	if (ps->data == NULL)
	{
		perror("stackInit");
		exit(-1);
	}
	//ps->size ���Գ�ʼ��Ϊ-1����0;-1ʱ��ʾps->size����ջ��,0ʱ��ʾps->size��ջ������һ��Ԫ��;
	ps->size = 0;
	ps->capacity = 4;
}

//��ջ
void StackPush(stack* ps, STDatatype x)
{
	assert(ps);
	//�����ж�
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

	//ps->size��ʾջ������һ��
	ps->data[ps->size] = x;
	ps->size++;
}

//��ջ
void StackPop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//��ȡ,��Ҫ��?
STDatatype StackTop(stack* ps)
{
	assert(ps);
	assert(ps->size > 0);
	return ps->data[ps->size - 1];
}
//����
void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->size = 0;

}
//�Ƿ�Ϊ��
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
//��С
int StackSize(stack* ps)
{
	return ps->size;
}

//����ջʵ��
bool isValid(char* s) {
	//����ջ
	stack st;
	StackInit(&st);

	bool ret = false;
	while (*s)
	{
		//��������ջ
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		//��ʼ���������
		else if ((*s == ']' || *s == ')' || *s == '}') && StackEmpty(&st))
		{
			ret = false;
			break;
		}
		//�������ж��Ƿ��ջ��ƥ��
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
			//����ƥ��,��ջ
			StackPop(&st);
		}
		//s++
		s++;
	}

	//��ȷ����:ջΪ��,S����ͷ
	//���ջ
	if (StackEmpty(&st) && *s == '\0')
	{
		ret = true;
	}
	StackDestroy(&st);
	return ret;
}