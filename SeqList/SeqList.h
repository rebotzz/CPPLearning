#pragma once

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//��
#define SLDataType int	//���������ݵ�����,���ں����޸�
#define PRINTTYPE "%d " //��ӡ����,���ں����޸�
#define SCANFTYPE "%d"  //��������

#if 0
#define SLCapacity 1000
#endif
////��̬˳���
//// ������������޸�,������
//// �������Ͷ���
//typedef struct SeqList
//{
//	int size;
//	SLDataType arr[SLCapacity];
//}SeqListInfo;

//���Ͷ���
//��̬˳���	������Ҫ���ٿռ�
typedef struct SeqList
{
	int size;	//��ǰ�洢���ݸ���
	int SLCapacity;	//����
	SLDataType* arr;	//ָ�����洢�������ݵ�ָ��
}SeqListInfo;
//�˵�ѡ�����
enum meun_choice				//1.ǰ��     2.ǰɾ    
{								//3.���     4.��ɾ    
	EXIT_SAVE,					//5.�м��   6.�м�ɾ  
	PUSHFRONT,					//7.�м��   0.�����˳�
	POPFRONT,					//8.��ӡ	 9.��ȡ
	PUSHBACK,					//10.����
	POPBACK,
	PUSHMIDDLE,
	POPMIDDLE,
	REVISEMIDDLE,
	PRINT,
	GETDATA,
	FIND
};

//��������
SeqListInfo SLData;

//�������� �ӿں���
// ��ʼ��
void SeqListInit(SeqListInfo* ps);
//���
void SeqListPushBack(SeqListInfo* ps, SLDataType x);
//��ɾ
void SeqListPopBack(SeqListInfo* ps);
//ǰ����
void SeqListPushFront(SeqListInfo* ps, SLDataType x);
//ǰɾ
void SeqlistPopFront(SeqListInfo* ps);
//�м����
void SeqListInsert(SeqListInfo* ps,int pos, SLDataType x);
//�м��޸�	����,ɾ��,�޸����ʹ��
void SeqListReviseMiddle(SeqListInfo* ps, int pos, SLDataType x);
//�м�ɾ��
void SeqListErase(SeqListInfo* ps,int pos);
// ˳������
int SeqListFind(SeqListInfo* ps, SLDataType x);
//�˵�
void menu();
//��ӡ����
void SeqListPrint(SeqListInfo* ps);
//��ȡ�ļ�
void GetData(SeqListInfo* ps);
//�˳������ļ�
void ExitSave(SeqListInfo* ps);
//���ٿռ�
void SeqListDestory(SeqListInfo* ps);