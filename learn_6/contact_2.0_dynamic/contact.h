#pragma once

//ͷ�ļ�,�궨��,����

#define MAX_PEO 3//��ʼ�����ϵ����
#define MAX_LIST 20 //��ʼ����ظ�������ѯ�����������
#define INC_SZ 2	//ÿ��������

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

//��������	

enum choice //�˵�ѡ��
{
	EXIT,//0
	ADD,//1
	DIV,
	FIND,
	CHANGE,
	DISPLAY
};
typedef struct people	//ÿ������Ϣ.��������
{
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char addr[20];
}peo_info;
typedef struct contact		//����ϵ����Ϣ.��������
{
	struct people* p;
	int sz;//���,������
}s_con;


//�˵�
void meun();
//��ʼ��
void init();
//������ϵ��
void add();
//ɾ����ϵ��
void delete();
//��ʾ��ϵ��
void display();
//������ϵ��
int* find();
//�޸���ϵ��
void change();
//������������
void sort_name();
