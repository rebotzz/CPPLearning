#pragma once

//ͷ�ļ�,�궨��,����

#define MAX_PEO 1000//�����ϵ����
#define MAX_LIST 20 //����ظ�������ѯ�����������


#include <stdio.h>
#include <string.h>
#include <assert.h>


//��������	
//ȫ�ֱ�����������ݶ�,����ջ�� ==> ���ǲ���,
//��Ϊ"contact.h"��contact.c �� test.c ��������һ��,�����൱���ظ�����
//�������,�� contact.c �д���ȫ�ֱ���,����ֻ����
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
void div();
//��ʾ��ϵ��
void display();
//������ϵ��
int* find();
//�޸���ϵ��
void change();
//������������
void sort_name();
