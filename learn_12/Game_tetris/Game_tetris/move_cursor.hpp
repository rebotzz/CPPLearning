#define _CRT_SECURE_NO_WARNINGS
#pragma once 
#include <conio.h>//控制台输入输出头文件
#include <windows.h>


//光标移动		光标移动后的打印,效果是打印覆盖
void gotoxy(int x, int y)
{
	// windows默认: 横x, 竖y  -- 与数组不同: 横y, 竖x
	// 为了方便处理,统一使用数组表示
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	// 句柄，标定这特定资源的数据结构，例如：文件描述符
}