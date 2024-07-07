#define _CRT_SECURE_NO_WARNINGS

//函数递归练习
//接受一个整型值（无符号），按照顺序打印它的每一位。
//例如：
//输入：1234，输出 1 2 3 4.

//#include<stdio.h>
//
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);//1234
//	//打印1 2 3 4
//	print(a);
//	return 0;
//}


////递归练习
//
//#include<stdio.h>
//
//void print(int x)
//{
//	if (x > 1)
//	{
//		x--;
//		print(x);
//	}
//	printf("hehe.\n");
//}
//
//int main()
//{
//	int a = 0;//当心栈溢出
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}

//编写函数不允许创建临时变量，求字符串的长度。
//先实现功能,然后在按照题目要求优化
// 1.0
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr[] = "ada";
//	printf("%d",(int) strlen(arr));		//类型强制转换
//	return 0;
//}

//2.0
//#include<stdio.h>
//
//int str_len(char* parr)		//数组传递的是首元素的地址
//{
//	int i = 0;
//	while (1)
//	{
//		if (*parr != '\0')
//		{
//			i++;
//			parr++;
//		}
//		else
//			break;
//	}
//	return i;
//}
//
//int main()
//{
//	char arr[] = "leon";
//	//自定义函数求字符串长度
//	printf("%d", str_len(&arr));
//	return 0;
//}

//3.0	不创建临时变量求解
//思路 直接 return 递归
//递归的核心:  大事化小,大问题拆分为小问题
//"leon\0"
//1 + "eon\0"
//1+1+"on\0"
//1+1+1+"n\0"
//1+1+1+1+"\0"
//"\0"  ---->   0
// 
//#include<stdio.h>
//
//int str_len(char* parr)		//数组传递的是首元素的地址
//{
//		if (*parr != '\0')
//			return 1 + str_len(parr + 1);
//		else 
//			return 0;
//}
//
//int main()
//{
//	char arr[] = "leon";
//	//自定义函数求字符串长度
//	printf("%d", str_len(&arr));
//	return 0;
//}

//求n的阶乘。（不考虑溢出)
//n! = 1*2*3*…*n
//n! = n*(n-1)*(n-2)*……*2*1

////1.0
//#include<stdio.h>
//
//long long int factorial(int n)		//21!会溢出
//{
//	int i = 0;
//	long long ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//阶乘函数
//	printf("%lld", factorial(n));
//	return 0;
//}

////2.0 递归求解
//#include<stdio.h>
//
//long long int factorial(int n)		//21!会溢出
//{
//	if (n > 1)						//结束递归条件
//		return n * factorial(n - 1);//每次逼近结束递归条件
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//阶乘函数
//	printf("%lld", factorial(n));
//	return 0;
//}



//求第n个斐波那契数。（不考虑溢出）
//1 1 2 3 5 8 13 21 34 55 89 144
// F(n) = F(n-1) + F(n-2)

//1.0	递归	可以实现,但是重复计算多,效率底下		自上而下
//#include<stdio.h>
//int m = 0;
//int fib(int n)
//{
//	if (n == 5)		//注意 == ,不是 = ,否则死循环,栈溢出
//		m++;
//	if (n > 2)
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//第n个斐波那契数列
//	printf("%d\n", fib(n));
//	printf("%d\n", m);
//	return 0;
//}


//2.0		循环		自下而上,减少求解量,本次运算结果可用到下次运算
//#include<stdio.h>
//
//int fib(int n)
//{
//	int i = 0;
//	int ret = 1;
//	//用 ret_0 和 ret_1 来存储 f(n - 1)  f(n - 2) 的值,因为 F(n) = F(n-1) + F(n-2)
//	int ret_0 = 1;		
//	int ret_1 = 1;		 
//	//1 1 2 3 5 8 13 21 34 55 89 144
//	for (i = 3; i <= n; i++)
//	{
//		if (i % 2 == 1)
//			ret_0 = ret;
//		if (i % 2 == 0)
//			ret_1 = ret;
//		ret = ret_0 + ret_1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//第n个斐波那契数列
//	printf("%d\n", fib(n));
//	return 0;
//}