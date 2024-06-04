#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////上周写的代码，可以优化
////编写代码，演示多个字符从两端移动，向中间汇聚。
//int main()
//{
//	char arr1[] = "welcome to night city";
//	char arr2[] = "#####################";
//	int lenth = sizeof(arr1) / sizeof(arr1[0]);
//	float mid = (lenth - 1) / 2.0;
//	int left = 0;
//	int right = lenth - 2;
//	printf("%s\n", arr2);
//	printf("按下回车查看以上内容:>");
//	getchar();						//按回车后才继续
//
//	for (int i = left; i < mid; i = i + 1)
//	{
//		//打印左端
//		int a = 0;
//		while (a <= i)
//		{
//			printf("%c", arr1[a]);
//			a++;
//		}
//		//打印中间
//		for (int j = i + 1; j < right - i; j++)
//		{
//			printf("%c", arr2[j]);
//		}
//		//打印右端
//		a = i;						//初始化与上面不同，确保打印字母顺序
//		while (a >= 0)
//		{
//			printf("%c", arr1[right - a]);
//			if (i == right - a)		//解决最后一行中间字符重复打印
//				printf("\b");
//			a--;
//		}
//		//printf("\n");
//		getchar();					//按回车后才继续
//
//	}
//	return 0;


	
////编写代码，演示多个字符从两端移动，向中间汇聚。	代码优化1.0		动态代码！！！好耶
//#include <string.h>			//strlen 函数调用库
//#include <windows.h>		//Sleep  system("cls") 函数调用
//int main()
//{
//	char arr1[] = "welcome to night city.";
//	char arr2[] = "######################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	//展示效果优化
//	printf("%s", arr2);
//	getchar();
//	system("cls");	//清空屏幕
//
//
//	//主体
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//
//		//展示效果优化
//		Sleep(500);		//延时 单位 毫秒
//		system("cls");	//清空屏幕
//
//
//	}
//	return 0;
//}



////编写代码实现，模拟用户登录情景，并且只能登录三次。
////只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。
//int main()
//{
//	char password1[20] = { 0 };		//输入密码
//
//	//char password2[] = { '1','2','3','4','5','6' };
//	//int right = sizeof(password2)/sizeof(password2[0]) - 1;		
//	////个人总结
//	////这里求长度不能用 strlen ,因为这里不是用 " " 写的字符串，而是用 {'',''} 写的
//
//	//试验
//	char password2[] = "123456";	//真实密码
//	int right = strlen(password2) - 1;
//
//	//结论， strlen 求 "" 字符长度； sizeof(数组)/sizeof(元素) 求  {''} 数组长度；
//	//或许差异与 结束符‘\0’ 有关；""其末尾默认添加’\0’;
//
//	int times = 3;
//
//
//	printf("请输入密码:>");
//	scanf("%s", password1);			//数组名本来就是地址，不用 &
//	
//
//	int i = 0;
//	while (i <= right )
//	{
//		if (password1[i] == password2[i])
//		{
//			i++;
//			if (i > right)
//			{
//				printf("密码输入成功！\n");
//				break;
//			}
//		}
//		else
//		{
//			times--;
//			printf("密码输入错误，剩余次数：%d\n",times );
//			if (times == 0)
//			{
//				printf("你已经输错3次，程序退出！");
//				break;
//			}
//			scanf("%s", password1);
//			
//		}
//		
//	}
//
//
//
//	return 0;
//}


////编写代码实现，模拟用户登录情景，并且只能登录三次。
////只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。
////程序优化1.0			   strcmp(  ,  ) 字符串比较函数,返回值为 int
//#include <string.h>		//strcmp 库函数
//
//int main()
//{
//	int password[20] = { 0 };
//	printf("请输入密码:>");
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		//假设正确密码为123456
//		if (strcmp(password, "123456") == 0)	//若相同,返回值为 0
//		{
//			printf("密码输入正确,登录成功!\n");
//			break;
//		}
//		else
//		{
//			printf("密码输入错误,请重新输入:\n");
//		}
//	}
//	if (3 == i)
//	{
//		printf("输入错误3次,程序退出!");
//	}
//	return 0;
//}


////猜数字游戏
////要求:1.生成一个1-100之间的随机数
////	   2.告诉你猜测大了还是小了
////	   3.有个菜单界面
//#include <stdlib.h>		//rand	srand
//#include <time.h>		//time
//
//int ret = 0;			//全局变量
//int enter = 0;
//
//
//void menu()
//{
//	printf("######### 猜数字 #########\n");
//	printf("##########################\n");
//	printf("#########1. play##########\n");
//	printf("#########0. exit##########\n");
//	printf("##########################\n");
//}
//
//
//void game()
//{
//	printf("游戏开始\n");
//	printf("请输入你猜测的数字:");
//
//	while (1)
//	{
//		scanf("%d", &enter);
//		if (enter < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (enter > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了!\n");
//			break;
//		}
//
//	}
//
//}
//
//int main()
//{
//	int choose = 0;
//	//生成一个伪随机数  0 - 100
//	srand((unsigned int)time(NULL));			//利用时间 伪随机数初始化
//	
//	do
//	{
//		menu();
//		scanf("%d", &choose);
//		ret = rand() % 100 + 1;					//rand() 生成范围 0 - 32767  ---->映射为 0 - 100
//		switch (choose)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误,请重新输入!\n");
//			break;
//		}
//
//	} while (choose);
//	
//
//	return 0;
//}


////猜数字游戏							版本更新2.0
////要求:1.生成一个1-100之间的随机数
////	   2.告诉你猜测大了还是小了
////	   3.有个菜单界面
//#include <stdlib.h>		//rand	srand
//#include <time.h>		//time
//
//int ret = 0;			//全局变量
//int enter = 0;
//int choose2 = 0;
//int m = 0;
//
//void menu1()
//{
//	printf("#########猜数字2.0#########\n");
//	printf("###########################\n");
//	printf("#########1.  play##########\n");
//	printf("#########0.  exit##########\n");
//	printf("###########################\n");
//}
//
//void menu2()
//{
//	printf("########请选择难度########\n");
//	printf("#########0. 简单##########\n");
//	printf("#########1. 困难##########\n");
//	printf("#########2. 地狱##########\n");
//	printf("##########################\n");
//}
//
//
//void game()
//{
//	printf("游戏开始\n");
//	printf("你总共可以猜测 %d 次\n",m);
//	printf("请输入你猜测的数字:");
//	int i = 0;
//	for(i = 0; i <m; i++)
//	{
//		scanf("%d", &enter);
//		if (enter < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (enter > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了!\n");
//			break;
//		}
//
//	}
//	if(i == m)
//		printf("游戏失败\n");
//
//}
//
//int main()
//{
//	int choose1 = 0;
//
//	//生成一个伪随机数  0 - 100
//	srand((unsigned int)time(NULL));			//利用时间 伪随机数初始化
//
//	do
//	{
//		menu1();
//		scanf("%d", &choose1);
//		ret = rand() % 100 + 1;					//rand() 生成范围 0 - 32767  ---->映射为 0 - 100
//		switch (choose1)
//		{
//		case 1:
//			menu2();
//			scanf("%d", &choose2);
//			switch (choose2)
//			{
//			case 0:
//				m = 20;
//				game();
//				break;
//			case 1:
//				m = 10;
//				game();
//				break;
//			case 2:
//				m = 6;
//				game();
//				break;
//			default:
//				printf("输入错误,请重新输入!\n");
//				break;
//			}
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误,请重新输入!\n");
//			break;
//		}
//
//	} while (choose1);
//
//
//	return 0;
//}

//你好

//git 上传到厂库暂时有点问题?	失败,网络?