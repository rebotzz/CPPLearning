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
	PUSHBACK,
	POPBACK,
	PUSHMIDDLE,
	POPMIDDLE,
	REVISEMIDDLE,
	PRINT,
	GETDATA
};

//��������
SeqListInfo SLData;

//�������� �ӿں���
// ��ʼ��
void SeqListInit(SeqListInfo* ps);
//���
void SeqListPushBack(SeqListInfo* ps,int x);
//��ɾ
void SeqListPopBack(SeqListInfo* ps);
//ǰ����
void SeqListPushFront(SeqListInfo* ps, int x);
//ǰɾ
void SeqlistPopFront(SeqListInfo* ps);
//�м����
void SeqListPushMiddle(SeqListInfo* ps,int pos, int x);
//�м��޸�
void SeqListReviseMiddle(SeqListInfo* ps, int pos, int x);
//�м�ɾ��
void SeqListPopMiddle(SeqListInfo* ps,int pos);
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