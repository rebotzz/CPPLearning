#pragma once

//参数定义,宏.
#define ROW 5
#define COL 5


//头文件引用
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//函数声明

//游戏本体
void game_2();
//棋盘 -初始化
void init_board2(char board[ROW][COL], int row, int col);
//打印棋盘
void Display_board2(char board[ROW][COL], int row, int col);
//玩家走
void player_do2(char board[][COL], int row, int col);
//电脑走
void computer_do2(char board[][COL], int row, int col);
//判断输赢 - 只判断赢
char Is_Win2(char board[ROW][COL], int row, int col, char who);
//判断输赢 - 分析情况
char IsWin_Fail2(char board[ROW][COL], int row, int col);

//动态封面
void cover2();