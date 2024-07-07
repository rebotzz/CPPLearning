#pragma once
#include <cstdio>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>//控制台输入输出头文件
#include <windows.h>
using namespace std;

//光标移动		光标移动后的打印,效果是打印覆盖
inline void gotoxy(int x, int y)
{
	// windows默认: 横x, 竖y  -- 与数组不同: 横y, 竖x
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//彩色打印函数
//格式 \033[输入属性m    代码属性;前景色;后景色
// 0 重置 1 高亮
//前景色 31 红 32 绿 33 黄 34 蓝
//后景色 40 黑 41 红
inline void printf_red(char* s)
{
	printf("\033[0m\033[1;31m%s\033[0m", s);
}



inline void printf_yellow(char* s)
{
	printf("\033[0m\033[1;33m%s\033[0m", s);
}

inline void printf_blue(char* s)
{
	printf("\033[0m\033[1;34m%s\033[0m", s);
}

///////////
inline void printf_green(int x)
{
	printf("\033[0m\033[1;32m%2d\033[0m", x);
}

// 每一滴单独的雨
class Rain
{
public:
	Rain(int x, int len = 10, int ground = 30, string colour = "blue")
		:_x(x)
		,_ground(ground)
		,_colour(colour)
	{
		_y = rand() % 10;
		_begin = _y;	// 制造出雨从天而降，先后不一
		_len = rand() % 11 + 3;
	}
	
	void drop()
	{
		// 尾部消失
		if (_y - _len >= 0)
		{
			gotoxy(_x, _y - _len);
			printf("  ");
			//cout << "尾部消失" << endl;
		}

		// 落地消失
		if (_y < _ground)
		{
			int y = _y;
			if (_begin >= 0)
				y = _y - _begin;

			gotoxy(_x, y);
			_val = rand() % 2;	// 只打印0 1
			printf_green(_val);
		}
		_y++;
		_begin--;
	}

	bool death()
	{
		return (_y - _len) > _ground;
	}


private:
	int _x;		// 位置
	int _y;
	int _begin;
	int _val;
	int _len;	// 数字雨长度
	int _ground;//地面：消失的位置
	string _colour;
};


void simple_rain()
{
	int begin = 500;
	// 快速启动铺满屏幕
	while (begin--)
	{
		printf("\033[0m\033[1;32m %d \033[0m", rand() % 2);
		int n = rand() % 7;
		while (n--) printf(" ");
		this_thread::sleep_for(chrono::nanoseconds(40));
	}

	while (true)
	{
		printf("\033[0m\033[1;32m %d \033[0m", rand()%2);
		int n = rand() % 7;
		while(n--) printf(" ");
		this_thread::sleep_for(chrono::nanoseconds(500));
	}
}


