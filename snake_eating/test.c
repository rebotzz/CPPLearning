#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

////������ƶ�������̨��(x,y)����㴦
//void gotoxy(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//int main()
//{
//	gotoxy(30, 15);//������ƶ�������̨��(50,15)��
//	printf("Hello World\n");
//	//system("pause");
//	return 0;
//}



////1��ʹ��getch��ȡ�ַ�ʱ����ȡһ�ξ���
////2������ȡ������͹��ܼ��ǣ���Ҫ��ȡ����
////����һ�εķ���ֵΪ0����224�����������
////getch�����ڶ�ȡһ�����ܼ����߼�ͷ�����򣩼���ʱ�������᷵�����Σ���һ�ε��÷���0����0xE0���ڶ��ε��÷���ʵ�ʵļ�ֵ��
//#include<stdio.h>
//#include <conio.h>
//
//int main()
//{    //ʵ�ֶ���һ���ַ������getch�ķ���ֵ��
//    int ch;
//    while (1)
//    {
//        while (ch = _getch()) //�ѵõ���ֵ��ֵ��ch
//        {
//            printf("%d\n", ch); //�������� a b c d ���� �� ��
//        }
//    }
//    return 0;
//}