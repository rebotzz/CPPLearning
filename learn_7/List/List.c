#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

//��ʼ��
ListNode* ListInit()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//�½��ڵ�
ListNode* BuyListNode(ListDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//β��
void ListPushBack(ListNode* phead, ListDataType x)
{
	//assert(phead != NULL);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* tail = phead->prev;
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;

	ListInsert(phead, phead, x);
}
//ͷ��
void ListPushFront(ListNode* phead, ListDataType x)
{
	//ListNode* newnode = BuyListNode(x);
	//ListNode* next = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = next;
	//next->prev = newnode;

	ListInsert(phead, phead->next, x);
}
//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//ListNode* tail, *prev;
	//tail = phead->prev;
	//prev = tail->prev;
	//
	//prev->next = phead;
	//phead->prev = prev;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}
//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//ListNode* prev = phead->next;
	//ListNode* next = prev->next;
	//phead->next = next;
	//next->prev = phead;
	//free(prev);
	//prev = NULL;

	ListErase(phead->next);
}
//��ӡ
void ListPrint(ListNode* phead)
{
	assert(phead != NULL);
	//assert(phead->next != phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//�м��
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x)
{
	assert(phead != NULL);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//�м�ɾ
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
//����
ListNode* ListFind(ListNode* phead,ListDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//����
void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}