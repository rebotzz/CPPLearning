#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//队列
// first in first out
// 先进先出,队尾插入数据,队头出数据
// 可以读取队头和队尾的数据
// 利用单链表实现,头删,尾插
// 用到两个结构体,一个是队列节点,另一个是队列头,尾指针
// 优势:不用二级指针,不用返回值
// 指针的指针
//

extern struct TreeNode;
typedef struct TreeNode* QueueDatatype;
//队列节点
typedef struct queuenode
{
	//_用于区分结构体成员变量和别的变量
	QueueDatatype* _data;
	struct queue* _next;
}queuenode;
//队列链表头,尾指针
typedef struct queue
{
	//有的命名为Front,Rear
	queuenode* _head;
	queuenode* _tail;
}queue;

//初始化
void QueueInit(queue* pq);

//入队,尾插
void QueuePush(queue* pq, QueueDatatype x);
//读取,front	
QueueDatatype QueueFront(queue* pq);
//读取,back		也可以命名为QueueRear
QueueDatatype QueueBack(queue* pq);
//出队,头删
void QueuePop(queue* pq);
//销毁
void QueueDestroy(queue* pq);
//判空
bool QueueEmpty(queue* pq);
//大小
int QueueSize(queue* pq);
