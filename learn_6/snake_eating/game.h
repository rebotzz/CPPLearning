#pragma once

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>//windows���ͷ�ļ�
#include <time.h>
#include <conio.h>//����̨�������ͷ�ļ�

//�궨��
#define SNAKESIZE 100//�ߵ�����������
#define MAPWIDTH 118 //���
#define MAPHEIGHT 29//�߶�

//ȫ�ֱ�������
extern int key;
extern int changeFlag;
extern int sorce;

//�������Ͷ���
//
//ʳ�������
struct {
	int x;
	int y;
}food;

//�ߵ��������
struct {
	int speed;//���ƶ����ٶ�
	int len;//�ߵĳ���
	int x[SNAKESIZE];//��������ÿһ��С������x������
	int y[SNAKESIZE];//��������ÿһ��С������y������

}snake;


//��������
//
//�˵�
void meum();
//������Ϸ�߿�
void drawMap();
//�������ʳ��
void createFood();
//��������
void keyDown();
//�ߵ�״̬
int snakeStatus();
//�ӿ���̨�ƶ����
void gotoxy(int x, int y);