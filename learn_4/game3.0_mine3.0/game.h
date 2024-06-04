#pragma once

//�궨��
//��������
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//��������
#define easy_count 10

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//��������
//�ײ���
char mine[ROWS][COLS];
//ɨ��չʾ����
char show[ROWS][COLS];
//ʱ���¼
time_t start, end;
//�洢�������
int mark[60][2];
int mark_;

//��������

//�˵�
void menu();
//��Ϸ
void game();
//���̳�ʼ��
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row,int col);//�����ӡҲ����չ����,ֻ������ӡ����
//���õ���
void SetMine(char board[ROWS][COLS],int row,int col);//��֤���̴�С��һ����
//ɨ��
void FindMine(char board[ROWS][COLS],int row,int col);
//��ʾ��������
void CountMine(char board[ROWS][COLS], int x, int y, int row, int col);
//�����׸�����Ŀ
int CheckMine(char board[ROWS][COLS], int row, int col);
//��ɫ��ӡ����
void printf_red(char* s);
void printf_green(char* s);
void printf_yellow(char* s);
void printf_blue(char* s);
//��ջ�������������
void clear();
