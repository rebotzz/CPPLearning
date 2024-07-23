#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//单链表

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;


////初始化		似乎不用初始化
//新建节点
SListNode* BuySListNode(SLDataType x);
//前插
void SListPushFront(SListNode** pphead, SLDataType x);
//前删
void SListPopFront(SListNode** pphead);
//后插
void SListPushBack(SListNode** pphead, SLDataType x);
//后删
void SListPopBack(SListNode** pphead);
//打印
void SListPrint(SListNode* phead);
//pos之后插
void SListInsertAfter(SListNode* pos, SLDataType x);
//pos之前插
void SListInsertFront(SListNode** pphead,SListNode* pos, SLDataType x);
//pos之后删
void SListEraseAfter(SListNode* pos);
//pos之前删
void SListEraseFront(SListNode** pphead,SListNode* pos);
//查找
SListNode* SListFind(SListNode* phead, SLDataType x);
//替换	==> 配合查找就能实现替换
//销毁空间
void SListDestory(SListNode** pphead);