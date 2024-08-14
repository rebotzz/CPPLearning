#pragma once

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>//windows编程头文件
#include <time.h>
#include <conio.h>//控制台输入输出头文件

//宏定义
#define SNAKESIZE 100//蛇的身体最大节数
#define MAPWIDTH 118 //宽度
#define MAPHEIGHT 29//高度

//全局变量声明
extern int key;
extern int changeFlag;
extern int sorce;

//变量类型定义
//
//食物的坐标
struct {
	int x;
	int y;
}food;

//蛇的相关属性
struct {
	int speed;//蛇移动的速度
	int len;//蛇的长度
	int x[SNAKESIZE];//组成蛇身的每一个小方块中x的坐标
	int y[SNAKESIZE];//组成蛇身的每一个小方块中y的坐标

}snake;


//函数声明
//
//菜单
void meum();
//绘制游戏边框
void drawMap();
//随机生成食物
void createFood();
//按键操作
void keyDown();
//蛇的状态
int snakeStatus();
//从控制台移动光标
void gotoxy(int x, int y);