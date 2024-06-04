#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


////数9的个数
////编写程序数一下 1到 100 的所有整数中出现多少个数字9

//int main()
//{
//	int num = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9)
//			num++;
//		if (i % 10 == 9)
//			num++;
//	}
//	printf("%d", num);
//	return 0;
//}


////【题目名称】
////分数求和
////计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
//
//int main()
//{
//	float sum = 0;
//	int a = 1;
//	int i = 1;
//	for (i = 1; i <= 100000; i++)
//	{
//		if (i % 2 == 0)
//			a = -1;
//		else
//			a = 1;
//		sum = sum + a * (1.0 / i);
//	}
//	printf("sum = %f", sum);	//如果我数学没计算错的话,无穷级数, i->无穷时, sum = ln2;约等于0.69314718
//
//	return 0;
//}


////【题目名称】
////求最大值
////【题目内容】
////求10 个整数中最大值
//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("输入10个整数\n");
//	int i = 0;
//	for (int j = 0; j < 10; j++)
//	{
//		scanf("%d", &arr[j]);
//	}
//	//scanf("%d %d %d %d %d %d%d%d%d%d",&arr);		这样写有问题?	和字符串数组不一样?
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] >= arr[i + 1])
//		{
//			if( max <= arr[i] )
//			max = arr[i];
//		}
//		else
//		{
//			if ( max <= arr[i + 1] )
//				max = arr[i + 1];
//		}
//
//	}
//	printf("max = %d", max);
//	
//	return 0;
//}


//【题目名称】
//乘法口诀表
//【题目内容】
//在屏幕上输出9 * 9乘法口诀表

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		for (j = 0; j <= 9; j++)
//		{
//			printf("%d * %d = %d   ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////乘法口诀表
////在屏幕上输出9 * 9乘法口诀表			代码优化1.0
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}