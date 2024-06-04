//#define _CRT_SECURE_NO_WARNINGS
//
//
////225. 用队列实现栈
////请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
////实现 MyStack 类：
////void push(int x) 将元素 x 压入栈顶。
////int pop() 移除并返回栈顶元素。
////int top() 返回栈顶元素。
////boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//
////队列
//// first in first out
//// 先进先出,队尾插入数据,队头出数据
//// 可以读取队头和队尾的数据
//// 利用单链表实现,头删,尾插
//// 用到两个结构体,一个是队列节点,另一个是队列头,尾指针
//// 优势:不用二级指针,不用返回值
//// 指针的指针
////
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//
////队列
//// first in first out
//// 先进先出,队尾插入数据,队头出数据
//// 可以读取队头和队尾的数据
//// 利用单链表实现,头删,尾插
//// 用到两个结构体,一个是队列节点,另一个是队列头,尾指针
//// 优势:不用二级指针,不用返回值
//// 指针的指针
////
//
//#define QueueDatatype int
////队列节点
//typedef struct queuenode
//{
//	//_用于区分结构体成员变量和别的变量
//	QueueDatatype* _data;
//	struct queue* _next;
//}queuenode;
////队列链表头,尾指针
//typedef struct queue
//{
//	//有的命名为Front,Rear
//	queuenode* _head;
//	queuenode* _tail;
//}queue;
//
////初始化
//void QueueInit(queue* pq)
//{
//	assert(pq);
//	pq->_head = pq->_tail = NULL;
//}
//
////入队,尾插
//void QueuePush(queue* pq, QueueDatatype x)
//{
//	assert(pq);
//	queuenode* newnode = (queuenode*)malloc(sizeof(queuenode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//
//	//判断_head是否为空
//	if (pq->_head == NULL)
//	{
//		pq->_head = pq->_tail = newnode;
//	}
//	else
//	{
//		pq->_tail->_next = newnode;
//		pq->_tail = newnode;
//	}
//}
////读取,front
//QueueDatatype QueueFront(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	return pq->_head->_data;
//}
////读取,back
//QueueDatatype QueueBack(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	return pq->_tail->_data;
//}
////出队,头删
//void QueuePop(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	queue* next = pq->_head->_next;
//	free(pq->_head);
//	pq->_head = next;
//}
////销毁
//void QueueDestroy(queue* pq)
//{
//	assert(pq);
//	queuenode* cur = pq->_head;
//	while (cur)
//	{
//		queuenode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	pq->_head = pq->_tail = NULL;
//}
////判空
//bool QueueEmpty(queue* pq)
//{
//	assert(pq);
//	if (pq->_head == NULL)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
////大小
//int QueueSize(queue* pq)
//{
//	assert(pq);
//	queuenode* cur = pq->_head;
//	int count = 0;
//	while (cur)
//	{
//		count++;
//		cur = cur->_next;
//	}
//	return count;
//}
//
//
//
//typedef struct {
//	// int* _data;
//	// int _size;
//	// int _capacity;
//	queue q1;
//	queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	//static修饰作用域不变,但是通过指针访问该地址呢?
//	static MyStack s;
//	QueueInit(&(s.q1));
//	QueueInit(&(s.q2));
//	return &s;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//	//插入到不为空的队列
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		QueuePush(&(obj->q1), x);
//	}
//	else
//	{
//		QueuePush(&(obj->q2), x);
//	}
//}
//
//int myStackPop(MyStack* obj)
//{
//	//找到不为空的,将不为空的最后一个元素之前都转移到另一个空队列
//	queue* old = NULL;
//	queue* new = NULL;
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		old = &(obj->q1);
//		new = &(obj->q2);
//	}
//	else
//	{
//		old = &(obj->q2);
//		new = &(obj->q1);
//	}
//	while (QueueSize(old) > 1)
//	{
//		QueuePush(new, QueueFront(old));
//		QueuePop(old);
//	}
//	int ret = QueueFront(old);
//	QueuePop(old);
//	return ret;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!QueueEmpty(&(obj->q1)))
//	{
//		return QueueBack(&(obj->q1));
//	}
//	else
//	{
//		return QueueBack(&(obj->q2));
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	assert(obj);
//	if (QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2)))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void myStackFree(MyStack* obj) {
//	assert(obj);
//	QueueDestroy(&(obj->q1));
//	QueueDestroy(&(obj->q2));
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
//
//void test()
//{
//	MyStack* obj =  myStackCreate();
//	printf("%d\n", myStackEmpty(obj));
//	myStackPush(obj, 1);
//	myStackPush(obj, 2);
//	printf("%d ", myStackTop(obj));
//	myStackPop(obj);
//	myStackPush(obj, 3);
//	
//	while (!myStackEmpty(obj))
//	{
//		printf("%d ", myStackTop(obj));
//		myStackPop(obj);
//	}
//
//	myStackFree(obj);
//}
//
////int main()
////{
////	test();
////	return 0;
////}




//2.0	malloc替代static
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



