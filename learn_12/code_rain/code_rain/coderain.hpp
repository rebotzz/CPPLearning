#pragma once
#include <cstdio>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>//����̨�������ͷ�ļ�
#include <windows.h>
using namespace std;

//����ƶ�		����ƶ���Ĵ�ӡ,Ч���Ǵ�ӡ����
inline void gotoxy(int x, int y)
{
	// windowsĬ��: ��x, ��y  -- �����鲻ͬ: ��y, ��x
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//��ɫ��ӡ����
//��ʽ \033[��������m    ��������;ǰ��ɫ;��ɫ
// 0 ���� 1 ����
//ǰ��ɫ 31 �� 32 �� 33 �� 34 ��
//��ɫ 40 �� 41 ��
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

// ÿһ�ε�������
class Rain
{
public:
	Rain(int x, int len = 10, int ground = 30, string colour = "blue")
		:_x(x)
		,_ground(ground)
		,_colour(colour)
	{
		_y = rand() % 10;
		_begin = _y;	// ����������������Ⱥ�һ
		_len = rand() % 11 + 3;
	}
	
	void drop()
	{
		// β����ʧ
		if (_y - _len >= 0)
		{
			gotoxy(_x, _y - _len);
			printf("  ");
			//cout << "β����ʧ" << endl;
		}

		// �����ʧ
		if (_y < _ground)
		{
			int y = _y;
			if (_begin >= 0)
				y = _y - _begin;

			gotoxy(_x, y);
			_val = rand() % 2;	// ֻ��ӡ0 1
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
	int _x;		// λ��
	int _y;
	int _begin;
	int _val;
	int _len;	// �����곤��
	int _ground;//���棺��ʧ��λ��
	string _colour;
};


void simple_rain()
{
	int begin = 500;
	// ��������������Ļ
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


