#define _CRT_SECURE_NO_WARNINGS

#include "Slist.h"


//新建节点
SListNode* BuySListNode(SLDataType x)
{
	//建立新节点,存储数据
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//打印
void SListPrint(SListNode* phead)
{
	//phead为Null
	//1.0
	if (phead == NULL)
	{
		printf("->NULL\n");
		return;
	}
	////2.0
	//assert(phead != NULL);

	SListNode* cur = phead;
	while (cur->next != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("%d->NULL\n", cur->data);
}

//后插
void SListPushBack(SListNode** pphead, SLDataType x)
{
	SListNode* newnode =  BuySListNode(x);

	//无节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//有节点
	//找到尾节点
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//后删
void SListPopBack(SListNode** pphead)
{
	//NULL
	////1.0
	//if ((*pphead) == NULL)
	//{
	//	return;
	//}
	//2.0
	assert(*pphead != NULL);

	//不为空,只有一个
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//多个
	else
	{
		SListNode* prev = *pphead;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}

//前插
void SListPushFront(SListNode** pphead, SLDataType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//前删
void SListPopFront(SListNode** pphead)
{
	assert(*pphead != NULL);
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
SListNode* SListFind(SListNode* phead, SLDataType x)
{
	assert(phead != NULL);
	SListNode* cur = phead;
	while (cur->next != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (cur->data == x)//最后一个元素判断
	{
		return cur;
	}
	return NULL;
}

//销毁空间
void SListDestory(SListNode** pphead)
{
	while (*pphead != NULL)
	{
		SListPopFront(pphead);
	}
}

//pos之后插
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos != NULL);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//pos之后删
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL);
	SListNode* newnext = pos->next->next;
	free(pos->next);
	pos->next = newnext;
}

//pos之前插
void SListInsertFront(SListNode** pphead,SListNode* pos, SLDataType x)
{
	assert(pos != NULL && *pphead != NULL);
	SListNode* newnode = BuySListNode(x);
	SListNode* prev = *pphead;
	if (prev == pos)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

//pos之前删
void SListEraseFront(SListNode** pphead,SListNode* pos)
{
	assert(pos != NULL && *pphead != NULL);
	assert(*pphead != pos);//pos之前0个
	SListNode* pprev = *pphead;
	if (pprev->next == pos)//pos之前1个
	{
		free(*pphead);
		*pphead = pos;
	}
	else
	{
		while (pprev->next->next != pos)
		{
			pprev = pprev->next;
		}
		free(pprev->next);
		pprev->next = pos;
	}
}