#define _CRT_SECURE_NO_WARNINGS


////传址调用,利用指针改变函数外变量
//#include<stdio.h>
//
//void print_(int* pn)
//{
//	printf("hello.\n");
//	*pn = *pn + 1;		//运算符号的优先级
//	//如果是 *pn ++ , 那么 ++ 优先于 * ,所以地址先+1,然后再解引用
//}
//
//int main()
//{
//
//	
//	int a = 7;
//	//记录的次数
//	int num = 0;
//	for (int i = 0; i < a; i++)
//	{
//		//调用函数
//		//if (i % 2 == 0)
//		{
//			print_(&num);
//		}
//
//	}
//	printf("num = %d\n", num);
//	return 0;
//}


////【题目名称】
////交换两个整数
////【题目内容】
////实现一个函数来交换两个整数的内容。
////思路,改变函数外的值,需要 传址调用 .指针
//#include<stdio.h>
//int swap(int* x, int* y)
//{
//	int z = *x;
//	*x = *y;
//	*y = z;
//	return 0;
//}
//int main()
//{
//	int a = 45;
//	int b = 32;
//	printf("before:%d  %d\n", a, b);
//	swap(&a, &b);
//	printf("after:%d  %d\n", a, b);
//	return 0;
//}



////【题目名称】
////乘法口诀表
////【题目内容】
////实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
////如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
////思路,传统乘法口诀表只有 9*9 ,用两个 for循环 , i <= 9 ,j <= i
////这里将 9 改为 由输入变量 n 决定 : i <= n , j <= i
////然后将以上部分封装为一个函数
//#include<stdio.h>
//
//void mul_print(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d = %d   ",j, i, j * i);
//		}
//		printf("\n");
//	}
//	
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//打印乘法口诀表
//	mul_print(n);
//	return 0;
//}
