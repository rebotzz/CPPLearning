#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ͷ˫��ѭ������

typedef int ListDataType;

typedef struct ListNode
{
	ListDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//��ʼ��
ListNode* ListInit();
//β��
void ListPushBack(ListNode* phead, ListDataType x);
//ͷ��
void ListPushFront(ListNode* phead, ListDataType x);
//βɾ
void ListPopBack(ListNode* phead);
//ͷɾ
void ListPopFront(ListNode* phead);
//��ӡ
void ListPrint(ListNode* phead);
//�м��
void ListInsert(ListNode* phead, ListNode* pos, ListDataType x);
//�м�ɾ
void ListErase(ListNode* pos);
//����	���Һ���Ը���
ListNode* ListFind(ListNode* phead,ListDataType x);
//����
void ListDestroy(ListNode* phead);