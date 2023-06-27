#define _CRT_SECURE_NO_WARNINGS

//【题目名称】
//杨辉三角
//【题目内容】
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
#include <stdio.h>

////1.0
//void init(int arr[],int tmp[], int line)
//{
//	arr[0] = 1;
//	arr[line - 1] = 1;
//	int i = 0;
//	for (i = 1; i < line - 1; i++)
//	{
//		arr[i] = tmp[i - 1] + tmp[i];
//	}
//
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[100] = { 0 };
//	int tmp[100] = { 0 };
//	int* parr = arr;
//	int* ptmp = tmp;
//	int line = 0;
//	scanf("%d", &line);//打印多少行
//	for (i = 0; i <= line; i++)
//	{
//		//存储上一次的值
//		for (int n = 0; n < line; n++)
//		{
//			tmp[n] = arr[n];
//		}
//		for (int j = 0; j < i; j++)
//		{
//
//			init(arr, tmp, line);//初始化arr
//			//打印前置空格
//
//			//打印杨辉三角数字
//			printf("%2d ", arr[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//2.0	代码优化
void init(int arr[], int line)
{

}




//【题目名称】
//猜凶手
//【题目内容】
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include <stdio.h>

//1.0
////四个人
//int a = 0;
//int b = 1;
//int c = 2;
//int d = 3;
//
////结果真假数量
//int anwser(int arr[])
//{
//	int yes = 0;
//	if (arr[a] == 0)//A真
//		yes++;
//	if (arr[c] == 1)//B真
//		yes++;
//	if (arr[d] == 1)//C真
//		yes++;
//	if (arr[d] != 1)//D真
//		yes++;
//	return yes;
//}
//int main()
//{
//
//	int arr[4] = { 0 };
//	int truth = 0;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		arr[i] = 1;
//		
//		//结果真假数量
//		truth = anwser(arr);
//		if (truth == 3)//总数为4,有三个真,必有一个假.
//		{
//			switch (i)
//			{
//			case 0:
//				printf("A是凶手.\n");
//				break;
//			case 1:
//				printf("B是凶手.\n");
//				break;
//			case 2:
//				printf("C是凶手.\n");
//				break;
//			case 3:
//				printf("D是凶手.\n");
//				break;
//			}
//
//		}
//		//置为0
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			arr[j] = 0;
//		}
//	}
//	return 0;
//}

//2.0	代码优化
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)//结果为真,返回1,为假返回0
//			printf("%c 是凶手\n", killer);
//	}
//}