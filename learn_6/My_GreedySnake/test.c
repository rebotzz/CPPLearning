//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>//控制台输入输出头文件
//
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
//
//
//
//////1、使用getch读取字符时，读取一次就行
//////2、而读取方向键和功能键是，需要读取两次
//////（第一次的返回值为0或者224（方向键））
//////getch函数在读取一个功能键或者箭头（方向）键盘时，函数会返回两次，第一次调用返回0或者0xE0，第二次调用返回实际的键值。
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



//kbhit()是一个C和C++函数，用于非阻塞地响应键盘输入事件。
//函数名：kbhit()
//功能及返回值： 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0。
//用 法：int kbhit(void);
//C++语言包含头文件： include <conio.h>。
//C语言不需包含额外头文件。
//在VC++6.0下为_kbhit()
//功能及返回值同上；
//For example(若无键盘输入将一直输出 helloworld)

//#include<stdio.h>
//#include<stdlib.h>
//int main(void)
//{
//    while (1)
//    {
//        printf("HelloWorld\n");
//        if (kbhit())
//        {
//            break;
//        }
//    }
//    printf("End!\n");
//    system("pause");
//    return 0;
//}