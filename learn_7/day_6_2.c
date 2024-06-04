#define _CRT_SECURE_NO_WARNINGS

//232. 用栈实现队列
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

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




typedef struct {
    //两个栈
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
    //两个栈都为空,直接插入
    if (StackEmpty(&(obj->s1)) && StackEmpty(&(obj->s2)))
    {
        StackPush(&(obj->s1), x);
    }
    //一个为空,一个不为空;逆序后再插入,然后在逆序回来
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
        //逆序
        while (!StackEmpty(full))
        {
            StackPush(empty, StackTop(full));
            StackPop(full);
        }
        //插入
        StackPush(empty, x);
        //再次逆序
        while (!StackEmpty(empty))
        {
            StackPush(full, StackTop(empty));
            StackPop(empty);
        }
    }
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //找到非空的栈
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
    //找到非空的栈
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








//2.0   代码优化
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




typedef struct {
    //两个栈
    stack empty;
    stack full;//或者   nonempty
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
    //都插入到empty,需要用的时候逆序到full
    StackPush(&(obj->empty), x);
}

int myQueuePeek(MyQueue* obj);

int myQueuePop(MyQueue* obj) {
    assert(obj);
    //复用myQueuePeek,实现逆序,确保full中的数据符合队列顺序
    int ret = myQueuePeek(obj);
    StackPop(&(obj->full));
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);

    //如果full不为空,那么就找full中的数据
    //如果full被pop空了,把empty中还未逆序的数据逆序存入到full
    if (StackEmpty(&(obj->full)))
    {
        //逆序,把插入到empty的数值存到full
        //逆序后,full中的数值顺序就符合队列的顺序,FIFO
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