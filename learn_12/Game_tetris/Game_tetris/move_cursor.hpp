#define _CRT_SECURE_NO_WARNINGS
#pragma once 
#include <conio.h>//����̨�������ͷ�ļ�
#include <windows.h>


//����ƶ�		����ƶ���Ĵ�ӡ,Ч���Ǵ�ӡ����
void gotoxy(int x, int y)
{
	// windowsĬ��: ��x, ��y  -- �����鲻ͬ: ��y, ��x
	// Ϊ�˷��㴦��,ͳһʹ�������ʾ
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	// ������궨���ض���Դ�����ݽṹ�����磺�ļ�������
}