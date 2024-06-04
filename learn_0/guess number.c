#define _CRT_SECURE_NO_WARNINGS

//猜数字游戏		现存在bug,不输入数字输入字符程序似乎死循环		版本更新3.0
//要求:1.生成一个1-100之间的随机数
//	   2.告诉你猜测大了还是小了
//	   3.有个菜单界面
#include <stdio.h>			//别忘了
#include <stdlib.h>			//rand	srand
#include <time.h>			//time
#include <string.h>			//strlen 函数调用库
#include <windows.h>		//Sleep  system("cls") 函数调用

int ret = 0;			//全局变量
int enter = 0;
int choose2 = 0;
int m = 0;

//动态封面,多个字符从两端移动，向中间汇聚。
void cover()
{
	char arr1[] = "welcome to this little game!";
	char arr2[] = "############################";
	int left = 0;
	int right = strlen(arr1) - 1;

	//展示效果优化
	printf("%s\n", arr2);
	printf("按回车键继续:>");
	getchar();
	system("cls");	//清空屏幕


	//封面主体
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);

		//展示效果优化
		Sleep(300);		//延时 单位 毫秒
		system("cls");	//清空屏幕

	}
	printf("%s", arr1);
	Sleep(1000);
	getchar();
	system("cls");
}


//菜单1
void menu1()
{
	printf("#########猜数字3.0#########\n");
	printf("###########################\n");
	printf("#########0.  exit##########\n");
	printf("#########1.  play##########\n");
	printf("#########2. others#########\n");
	printf("###########################\n");
}

//菜单2
void menu2()
{
	printf("########请选择难度########\n");
	printf("#########0. 简单##########\n");
	printf("#########1. 较难##########\n");
	printf("#########2. 困难##########\n");
	printf("#########3. 地狱##########\n");
	printf("##########################\n");
}

//游戏本体
void game()
{
	printf("游戏开始\n");
	printf("你总共可以猜测 %d 次\n", m);
	printf("请输入你猜测的数字:\n");
	int i = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &enter);
		if (enter < ret)
		{
			printf("猜小了\n");
		}
		else if (enter > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜对了!\n");
			Sleep(1000);
			getchar();
			system("cls");
			break;
		}

	}
	if (i == m)
	{
		printf("游戏失败\n");
		if (choose2 == 3)
		{
			printf("选择地狱难度,你很勇嘛!\n");
			printf("但是,你失败了,接受惩罚吧!\n");
			printf("你的电脑将会在60秒内关机,拜拜了你呢\(￣︶￣*\))");
			system("shutdown -s -t 60");
		}
	}

}

int main()
{
	int choose1 = 0;
	//生成一个伪随机数  0 - 100
	srand((unsigned int)time(NULL));			//利用时间 伪随机数初始化

	cover();

	do
	{
		menu1();
		scanf("%d", &choose1);
		ret = rand() % 100 + 1;					//rand() 生成范围 0 - 32767  ---->映射为 0 - 100
		switch (choose1)
		{
		case 1:
			menu2();
			scanf("%d", &choose2);
			switch (choose2)
			{
			case 0:
				m = 20;
				game();
				break;
			case 1:
				m = 10;
				game();
				break;
			case 2:
				m = 6;
				game();
				break;
			case 3:
				m = 6;
				printf("注意:这个模式有惩罚机制.\n");
				game();
				break;
			default:
				printf("输入错误,请重新输入!\n");
				while (1)
				{
					int abd = 0;
					if ((abd = getchar()) != '\n')
						;
					else
						break;
				}
				break;
			}
			break;
		case 0:
			printf("退出游戏\n");
			break;
		case 2:
			printf("以下是制作者的一些话:\n");
			getchar();
			printf("这个小游戏我曾经在一款galgame中玩过,和女主无聊的猜数字.\n");
			printf("不算有趣的游戏,但简单,适合学习.\n");
			printf("最后,希望你能享受这短暂的游戏,谢谢.\n");
			getchar();
			printf("小技巧:在地狱难度快要输掉时,关闭程序,就不会执行关机代码.（￣︶￣）↗　");
			getchar();
			system("cls");
			break;
		default:
			printf("输入错误,请重新输入!\n");
			while (1)
			{
				int abd = 0;
				if ((abd = getchar()) != '\n')
					;
				else
					break;
			}
			break;
		}

	} while (choose1);


	return 0;
}