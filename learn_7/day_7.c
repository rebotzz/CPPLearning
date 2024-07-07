#define _CRT_SECURE_NO_WARNINGS

//622. 设计循环队列
//设计你的循环队列实现。 循环队列是一种线性数据结构，
//其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了,
//我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//你的实现应该支持如下操作：
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//这里是静态的队列,用数组实现
//当数组下标越界时,取模回到起始下标,实现循环效果

typedef struct {
    int* _data;
    int _front;//队头
    int _rear;//队尾的下一个
    int _capacity;//容量

    // int _size;
    // int _capacity;//似乎没有增容的必要
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //创建一个K+1大小的数组,空一格用于判断队列是否满了
    //接口函数,所以为了避免局部变量销毁,使用static 或者 malloc
    //结构体
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (NULL == pq)
    {
        printf("malloc");
        exit(-1);
    }
    //数组k+1大小
    pq->_data = (int*)malloc((k + 1) * sizeof(int));
    if (NULL == pq->_data)//注意两个==,不是=
    {
        printf("malloc");
        exit(-1);
    }
    pq->_front = pq->_rear = 0;
    pq->_capacity = k + 1;
    return pq;
}

//入队,尾插
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //队列不满,则插入
    if (!myCircularQueueIsFull(obj))
    {
        obj->_data[obj->_rear] = value;//->优先级更高
        // printf("%d ", obj->_data[obj->_rear]);
        (obj->_rear)++;
        obj->_rear %= obj->_capacity;
        return true;
    }
    //满了,插入失败,返回假
    else
    {
        return false;
    }
}

//出队,头删,等价于头指针向前移动
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    //队列不为空,出队,返回真
    if (!myCircularQueueIsEmpty(obj))
    {
        obj->_front = (obj->_front + 1) % obj->_capacity;
        return true;
    }
    //队列为空,返回假
    else
    {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    //获取队头元素
    assert(obj);
    if (obj->_front == obj->_rear)//如果没有值,队头队尾相同
    {
        return -1;
    }
    return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    //获取队尾数据
    assert(obj);
    // assert(obj->_front != obj->_rear);
    if (obj->_front == obj->_rear)//如果没有值,队头队尾相同
    {
        return -1;
    }
    if (0 == obj->_rear)//小心向前越界
    {
        return obj->_data[obj->_capacity - 1];
    }
    else
    {
        return obj->_data[obj->_rear - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->_rear + 1) % obj->_capacity == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    //注意先后,有两次malloc
    assert(obj);
    free(obj->_data);
    free(obj);
    obj = NULL;
}

void test()
{
    MyCircularQueue* obj = myCircularQueueCreate(3);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 4);


    myCircularQueueFront(obj);
    myCircularQueueRear(obj);
    myCircularQueueIsEmpty(obj);
    myCircularQueueIsFull(obj);
    myCircularQueueDeQueue(obj);
    myCircularQueueFree(obj);
}

int main()
{
    test();
    return 0;
}