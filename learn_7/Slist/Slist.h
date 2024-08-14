#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;


////��ʼ��		�ƺ����ó�ʼ��
//�½��ڵ�
SListNode* BuySListNode(SLDataType x);
//ǰ��
void SListPushFront(SListNode** pphead, SLDataType x);
//ǰɾ
void SListPopFront(SListNode** pphead);
//���
void SListPushBack(SListNode** pphead, SLDataType x);
//��ɾ
void SListPopBack(SListNode** pphead);
//��ӡ
void SListPrint(SListNode* phead);
//pos֮���
void SListInsertAfter(SListNode* pos, SLDataType x);
//pos֮ǰ��
void SListInsertFront(SListNode** pphead,SListNode* pos, SLDataType x);
//pos֮��ɾ
void SListEraseAfter(SListNode* pos);
//pos֮ǰɾ
void SListEraseFront(SListNode** pphead,SListNode* pos);
//����
SListNode* SListFind(SListNode* phead, SLDataType x);
//�滻	==> ��ϲ��Ҿ���ʵ���滻
//���ٿռ�
void SListDestory(SListNode** pphead);