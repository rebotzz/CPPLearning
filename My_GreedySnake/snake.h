#pragma once

//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>//����̨�������ͷ�ļ�


//�����
#define MAPHIGHT 24	//��ͼ�߶�
#define MAPWIDTH 90	//��ͼ���
#define MAX_SNAKE_LEN 100	//����߳�
#define MAX_SCORE_LINE 6	//���а��������


//�����Ķ���
// 
//��ʼ�˵�
enum meum_choice
{
	EXIT,//0
	PLAY, //1
	TIPS, //2
	OTHERS //3
};
//���״̬
enum live_status
{
	DIE, //0
	LIVE //1
};
//�ߵĲ���
typedef struct SNAKE
{
	int len;//����
	int speed;//�ٶ�,����ʱ��ʾ,speedԽС,�ٶ�Խ��
	int x[MAX_SNAKE_LEN];//����
	int y[MAX_SNAKE_LEN];
}snake_info;
//ʳ�����
typedef struct FOOD
{
	int x;
	int y;
}food_info;



//ȫ�ֱ�������	�ƺ�����externҲ��,�Ͼ���ͷ�ļ�����
extern snake_info snake;
extern int liveflag;
extern int score;
int score_list[MAX_SCORE_LINE];



//��������
//
//����ƶ�
void gotoxy(int x, int y);
//��ӡ�˵�
void meum();
//��Ϸ��ʼ��: ��ͼ����,��ʼ������,��ʼʳ������
void InitGame();
//����������,�ı�ǰ������
void KeyInput();
//����Ƿ�Ե�ʳ��,�Ƿ���Ҫ����ʳ��
void IsGetFood();
//����ʳ��
void CreatFood();
//����Ƿ���
int IsLive();
//������ְ�,����
void score_sort(int* arr,int sz);
//��ӡ�������а�
void print_score();
//���ļ�,��ȡ���ּ�¼
void read_file();
//�˳���Ϸ,������ּ�¼
void exit_save();
//��ʾ
void tips();
//����,���ߵĻ�
void others();