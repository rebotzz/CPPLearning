#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//带头双向循环链表

typedef int ListDataType;

typedef struct ListNode
{
	ListDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//初始化
ListNode* ListInit();
//尾插
void ListPushBack(ListNode* phead, ListDataType x);
//头插
void ListPushFront(ListNode* phead, ListDataType x);
//尾删
void ListPopBack(ListNode* phead);
//头删
void ListPopFront(ListNode* phead);
//打印
void ListPrint(ListNode* phead);
//中间插
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x);
//中间删
void ListErase(ListNode* pos);
//查找	查找后可以更改
ListNode* ListFind(ListNode* phead,ListDataType x);
//销毁
void ListDestroy(ListNode* phead);