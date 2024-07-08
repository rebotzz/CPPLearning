#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

////将光标移动到控制台的(x,y)坐标点处
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
//	gotoxy(30, 15);//将光标移动到控制台的(50,15)处
//	printf("Hello World\n");
//	//system("pause");
//	return 0;
//}



////1、使用getch读取字符时，读取一次就行
////2、而读取方向键和功能键是，需要读取两次
////（第一次的返回值为0或者224（方向键））
////getch函数在读取一个功能键或者箭头（方向）键盘时，函数会返回两次，第一次调用返回0或者0xE0，第二次调用返回实际的键值。
//#include<stdio.h>
//#include <conio.h>
//
//int main()
//{    //实现读入一个字符，输出getch的返回值码
//    int ch;
//    while (1)
//    {
//        while (ch = _getch()) //把得到的值赋值给ch
//        {
//            printf("%d\n", ch); //依次输入 a b c d ↑↓ ← →
//        }
//    }
//    return 0;
//}