#pragma once

//参数定义,宏.
#define ROW 3
#define COL 3


//头文件引用
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//函数声明

//游戏本体
void game();
//棋盘 -初始化
void init_board(char board[ROW][COL], int row, int col);
//打印棋盘
void Display_board(char board[ROW][COL], int row, int col);
//玩家走
void player_do(char board[][COL], int row, int col);
//电脑走
void computer_do(char board[][COL], int row, int col);
//判断输赢
char IsWin(char board[ROW][COL], int row, int col);

//动态封面
void cover();