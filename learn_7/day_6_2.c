#define _CRT_SECURE_NO_WARNINGS

//232. ��ջʵ�ֶ���
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//ʵ�� MyQueue �ࣺ
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//˵����
//�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//ջ
// last in first out 
// ����ȳ�,�Ƚ����
////��̬
//#define MAX 100
//typedef struct stack
//{
//	STDatatype _data[MAX];
//	int _size;
//	int _capacity;
//}stack;
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




typedef struct {
    //����ջ
    stack s1;
    stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    static MyQueue q;
    StackInit(&(q.s1));
    StackInit(&(q.s2));
    return &q;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    stack* empty = NULL;
    stack* full = NULL;
    //����ջ��Ϊ��,ֱ�Ӳ���
    if (StackEmpty(&(obj->s1)) && StackEmpty(&(obj->s2)))
    {
        StackPush(&(obj->s1), x);
    }
    //һ��Ϊ��,һ����Ϊ��;������ٲ���,Ȼ�����������
    else
    {
        if (StackEmpty(&(obj->s1)))
        {
            empty = &(obj->s1);
            full = &(obj->s2);
        }
        else
        {
            empty = &(obj->s2);
            full = &(obj->s1);
        }
        //����
        while (!StackEmpty(full))
        {
            StackPush(empty, StackTop(full));
            StackPop(full);
        }
        //����
        StackPush(empty, x);
        //�ٴ�����
        while (!StackEmpty(empty))
        {
            StackPush(full, StackTop(empty));
            StackPop(empty);
        }
    }
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //�ҵ��ǿյ�ջ
    stack* s1 = &(obj->s1);
    stack* s2 = &(obj->s2);
    int ret = 0;
    if (!StackEmpty(s1))
    {
        ret = StackTop(s1);
        StackPop(s1);
    }
    else
    {
        ret = StackTop(s2);
        StackPop(s2);
    }
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    //�ҵ��ǿյ�ջ
    stack* s1 = &(obj->s1);
    stack* s2 = &(obj->s2);
    int ret = 0;
    if (!StackEmpty(s1))
    {
        ret = StackTop(s1);
    }
    else
    {
        ret = StackTop(s2);
    }
    return ret;
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    stack* s1 = &(obj->s1);
    stack* s2 = &(obj->s2);
    if (StackEmpty(s1) && StackEmpty(s2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    stack* s1 = &(obj->s1);
    stack* s2 = &(obj->s2);
    StackDestroy(s1);
    StackDestroy(s2);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/


//void test()
//{
//    MyQueue* obj = myQueueCreate();
//    myQueuePush(obj, 1);
//    myQueuePush(obj, 2);
//    printf("%d ", myQueuePeek(obj));
//    myQueuePop(obj);
//    myQueuePush(obj, 3);
//    myQueuePush(obj, 4);
//
//    while (!myQueueEmpty(obj))
//    {
//        printf("%d ", myQueuePeek(obj));
//        myQueuePop(obj);
//    }
//    printf("\n");
//
//    myQueueFree(obj);
//}
//
//int main()
//{
//    test();
//    return 0;
//}








//2.0   �����Ż�
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//ջ
// last in first out 
// ����ȳ�,�Ƚ����
////��̬
//#define MAX 100
//typedef struct stack
//{
//	STDatatype _data[MAX];
//	int _size;
//	int _capacity;
//}stack;
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




typedef struct {
    //����ջ
    stack empty;
    stack full;//����   nonempty
} MyQueue;


MyQueue* myQueueCreate() {
    //2.0   malloc
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&(q->empty));
    StackInit(&(q->full));
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    //�����뵽empty,��Ҫ�õ�ʱ������full
    StackPush(&(obj->empty), x);
}

int myQueuePeek(MyQueue* obj);

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //����myQueuePeek,ʵ������,ȷ��full�е����ݷ��϶���˳��
    int ret = myQueuePeek(obj);
    StackPop(&(obj->full));
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);

    //���full��Ϊ��,��ô����full�е�����
    //���full��pop����,��empty�л�δ���������������뵽full
    if (StackEmpty(&(obj->full)))
    {
        //����,�Ѳ��뵽empty����ֵ�浽full
        //�����,full�е���ֵ˳��ͷ��϶��е�˳��,FIFO
        while (!StackEmpty(&(obj->empty)))
        {
            StackPush(&(obj->full), StackTop(&(obj->empty)));
            StackPop(&(obj->empty));
        }
    }
    int ret = StackTop(&(obj->full));
    return ret;
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    return StackEmpty(&(obj->empty)) && StackEmpty(&(obj->full));
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    StackDestroy(&(obj->empty));
    StackDestroy(&(obj->full));
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/