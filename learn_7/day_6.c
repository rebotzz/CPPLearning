//#define _CRT_SECURE_NO_WARNINGS
//
//
////225. �ö���ʵ��ջ
////�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
////ʵ�� MyStack �ࣺ
////void push(int x) ��Ԫ�� x ѹ��ջ����
////int pop() �Ƴ�������ջ��Ԫ�ء�
////int top() ����ջ��Ԫ�ء�
////boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
//
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//
////����
//// first in first out
//// �Ƚ��ȳ�,��β��������,��ͷ������
//// ���Զ�ȡ��ͷ�Ͷ�β������
//// ���õ�����ʵ��,ͷɾ,β��
//// �õ������ṹ��,һ���Ƕ��нڵ�,��һ���Ƕ���ͷ,βָ��
//// ����:���ö���ָ��,���÷���ֵ
//// ָ���ָ��
////
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//
////����
//// first in first out
//// �Ƚ��ȳ�,��β��������,��ͷ������
//// ���Զ�ȡ��ͷ�Ͷ�β������
//// ���õ�����ʵ��,ͷɾ,β��
//// �õ������ṹ��,һ���Ƕ��нڵ�,��һ���Ƕ���ͷ,βָ��
//// ����:���ö���ָ��,���÷���ֵ
//// ָ���ָ��
////
//
//#define QueueDatatype int
////���нڵ�
//typedef struct queuenode
//{
//	//_�������ֽṹ���Ա�����ͱ�ı���
//	QueueDatatype* _data;
//	struct queue* _next;
//}queuenode;
////��������ͷ,βָ��
//typedef struct queue
//{
//	//�е�����ΪFront,Rear
//	queuenode* _head;
//	queuenode* _tail;
//}queue;
//
////��ʼ��
//void QueueInit(queue* pq)
//{
//	assert(pq);
//	pq->_head = pq->_tail = NULL;
//}
//
////���,β��
//void QueuePush(queue* pq, QueueDatatype x)
//{
//	assert(pq);
//	queuenode* newnode = (queuenode*)malloc(sizeof(queuenode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//
//	//�ж�_head�Ƿ�Ϊ��
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
////��ȡ,front
//QueueDatatype QueueFront(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	return pq->_head->_data;
//}
////��ȡ,back
//QueueDatatype QueueBack(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	return pq->_tail->_data;
//}
////����,ͷɾ
//void QueuePop(queue* pq)
//{
//	assert(pq);
//	assert(pq->_head);
//	queue* next = pq->_head->_next;
//	free(pq->_head);
//	pq->_head = next;
//}
////����
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
////�п�
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
////��С
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
//	//static���������򲻱�,����ͨ��ָ����ʸõ�ַ��?
//	static MyStack s;
//	QueueInit(&(s.q1));
//	QueueInit(&(s.q2));
//	return &s;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//	//���뵽��Ϊ�յĶ���
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
//	//�ҵ���Ϊ�յ�,����Ϊ�յ����һ��Ԫ��֮ǰ��ת�Ƶ���һ���ն���
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




//2.0	malloc���static
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



