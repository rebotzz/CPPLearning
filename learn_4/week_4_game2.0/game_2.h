#pragma once

//��������,��.
#define ROW 5
#define COL 5


//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//��������

//��Ϸ����
void game_2();
//���� -��ʼ��
void init_board2(char board[ROW][COL], int row, int col);
//��ӡ����
void Display_board2(char board[ROW][COL], int row, int col);
//�����
void player_do2(char board[][COL], int row, int col);
//������
void computer_do2(char board[][COL], int row, int col);
//�ж���Ӯ - ֻ�ж�Ӯ
char Is_Win2(char board[ROW][COL], int row, int col, char who);
//�ж���Ӯ - �������
char IsWin_Fail2(char board[ROW][COL], int row, int col);

//��̬����
void cover2();