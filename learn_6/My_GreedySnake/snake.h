#pragma once

//头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>//控制台输入输出头文件


//定义宏
#define MAPHIGHT 24	//地图高度
#define MAPWIDTH 90	//地图宽度
#define MAX_SNAKE_LEN 100	//最大蛇长
#define MAX_SCORE_LINE 6	//排行榜最大数量


//变量的定义
// 
//开始菜单
enum meum_choice
{
	EXIT,//0
	PLAY, //1
	TIPS, //2
	OTHERS //3
};
//存活状态
enum live_status
{
	DIE, //0
	LIVE //1
};
//蛇的参数
typedef struct SNAKE
{
	int len;//长度
	int speed;//速度,用延时表示,speed越小,速度越快
	int x[MAX_SNAKE_LEN];//坐标
	int y[MAX_SNAKE_LEN];
}snake_info;
//食物参数
typedef struct FOOD
{
	int x;
	int y;
}food_info;



//全局变量声明	似乎不用extern也行,毕竟是头文件包含
extern snake_info snake;
extern int liveflag;
extern int score;
int score_list[MAX_SCORE_LINE];



//函数声明
//
//光标移动
void gotoxy(int x, int y);
//打印菜单
void meum();
//游戏初始化: 地图创建,初始蛇生成,初始食物生成
void InitGame();
//检查键盘输入,改变前进方向
void KeyInput();
//检查是否吃到食物,是否需要生成食物
void IsGetFood();
//生成食物
void CreatFood();
//检查是否存活
int IsLive();
//排序积分榜,降序
void score_sort(int* arr,int sz);
//打印积分排行榜
void print_score();
//打开文件,读取积分记录
void read_file();
//退出游戏,保存积分记录
void exit_save();
//提示
void tips();
//其他,作者的话
void others();