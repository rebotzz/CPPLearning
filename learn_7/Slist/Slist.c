#define _CRT_SECURE_NO_WARNINGS

#include "Slist.h"


//�½��ڵ�
SListNode* BuySListNode(SLDataType x)
{
	//�����½ڵ�,�洢����
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//��ӡ
void SListPrint(SListNode* phead)
{
	//pheadΪNull
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

//���
void SListPushBack(SListNode** pphead, SLDataType x)
{
	SListNode* newnode =  BuySListNode(x);

	//�޽ڵ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//�нڵ�
	//�ҵ�β�ڵ�
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


//��ɾ
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

	//��Ϊ��,ֻ��һ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//���
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

//ǰ��
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

//ǰɾ
void SListPopFront(SListNode** pphead)
{
	assert(*pphead != NULL);
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����
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
	if (cur->data == x)//���һ��Ԫ���ж�
	{
		return cur;
	}
	return NULL;
}

//���ٿռ�
void SListDestory(SListNode** pphead)
{
	while (*pphead != NULL)
	{
		SListPopFront(pphead);
	}
}

//pos֮���
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos != NULL);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//pos֮��ɾ
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL);
	SListNode* newnext = pos->next->next;
	free(pos->next);
	pos->next = newnext;
}

//pos֮ǰ��
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

//pos֮ǰɾ
void SListEraseFront(SListNode** pphead,SListNode* pos)
{
	assert(pos != NULL && *pphead != NULL);
	assert(*pphead != pos);//pos֮ǰ0��
	SListNode* pprev = *pphead;
	if (pprev->next == pos)//pos֮ǰ1��
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