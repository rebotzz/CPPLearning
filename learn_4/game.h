#pragma once

//��������,��.
#define ROW 3
#define COL 3


//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//��������

//��Ϸ����
void game();
//���� -��ʼ��
void init_board(char board[ROW][COL], int row, int col);
//��ӡ����
void Display_board(char board[ROW][COL], int row, int col);
//�����
void player_do(char board[][COL], int row, int col);
//������
void computer_do(char board[][COL], int row, int col);
//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

//��̬����
void cover();