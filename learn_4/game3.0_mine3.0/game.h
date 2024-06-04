#pragma once

//宏定义
//棋盘数量
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
//地雷数量
#define easy_count 10

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//变量声明
//雷布置
char mine[ROWS][COLS];
//扫雷展示界面
char show[ROWS][COLS];
//时间记录
time_t start, end;
//存储标记坐标
int mark[60][2];
int mark_;

//函数声明

//菜单
void menu();
//游戏
void game();
//棋盘初始化
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row,int col);//就算打印也是拓展数组,只不过打印部分
//布置地雷
void SetMine(char board[ROWS][COLS],int row,int col);//保证棋盘大小的一致性
//扫雷
void FindMine(char board[ROWS][COLS],int row,int col);
//显示附近的雷
void CountMine(char board[ROWS][COLS], int x, int y, int row, int col);
//检查非雷格子数目
int CheckMine(char board[ROWS][COLS], int row, int col);
//彩色打印函数
void printf_red(char* s);
void printf_green(char* s);
void printf_yellow(char* s);
void printf_blue(char* s);
//清空缓存区无用输入
void clear();
