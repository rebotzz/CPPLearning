#define _CRT_SECURE_NO_WARNINGS

//【题目名称】
//打印一个数的每一位
//【题目内容】
//递归方式实现打印一个整数的每一位

//分析:1234    拆分问题
//1234  > 1  234   >1  2  34  >   1  2  3  4

//#include<stdio.h>
//
////打印函数
//void print(int x)
//{
//	if (x / 10 != 0)
//	{
//		print(x / 10);
//	}
//	printf("%d  ", x % 10);
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//打印函数
//	print(a);
//	return 0;
//}


//【题目名称】
//求阶乘
//【题目内容】
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）

////1.0非递归
//#include<stdio.h>
//
////阶乘函数
//int res(int x)
//{
//	int i = 1;
//	int n = 1;
//	for (i = 1; i <= x; i++)
//	{
//		n = n * i;
//	}
//	return n;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//阶乘函数
//	printf("%d\n",res(a));
//	return 0;
//}


////2.0递归
//// n! = n*(n-1)!
//#include<stdio.h>
//
////阶乘函数
//int res(int x)
//{
//	if (x > 1)
//	{
//		return x * res(x - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//阶乘函数
//	printf("%d\n", res(a));
//	return 0;
//}


//【题目名称】
//strlen的模拟（递归实现）
//【题目内容】
//递归和非递归分别实现strlen   >   求字符串长度

////1.0 strlen 使用
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	char arr2[20] = { 0 };
//	printf("%s\n", arr2);
//	printf("%u\n", strlen(arr2));
//
//	strcpy(arr2, arr1);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	printf("%u\n", strlen(arr1));
//	return 0;
//}


//
////2.0   strlen 模拟  非递归
//#include<stdio.h>
//#include<string.h>
//
////求字符串长度
//int strlen1(char* arr)
//{
//	int i = 0;
//	while (1)
//	{
//		if (*arr != '\0')
//		{
//			i++;
//			arr++;
//		}
//		else
//			break;
//	}
//	return i;
//
//}
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	//求字符串长度
//	printf("%d", strlen1(&arr1));
//	return 0;
//}



////3.0   strlen 模拟  递归
//#include<stdio.h>
//
////求字符串长度
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//
//}
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	//求字符串长度
//	printf("%d", strlen1(&arr1));
//	return 0;
//}


//【题目名称】
//字符串逆序（递归实现）
//【题目内容】
//编写一个函数 reverse_string(char* string)（递归实现）
//实现：将参数字符串中的字符反向排列，不是逆序打印。
//要求：不能使用C函数库中的字符串操作函数。
//比如 :
//char arr[] = "abcdef";
//逆序之后数组的内容变成：fedcba

////1.0   非递归
//#include<stdio.h>
//
////abcdef  >   fedcba
//// t = arr[i]; arr[i] = arr[n-i]  ; arr[n-i] = t;
////   0 1 2 3 .... n 
////逆序函数
//void reverse_string(char* string)
//{
//	int i = 0;
//	int t = 1;
//	int n = strlen1(string);
//	for (i = 0; i < n - i; i++)
//	{
//		t = *(string + i);
//		*(string + i) = *(string + n - 1 - i);
//		*(string + n - 1 - i) = t;
//	}
//}
//
////求字符串长度
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdefghijklmnopqrstuvwxyz";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//逆序函数
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}

////1.1   非递归  代码优化
//#include<stdio.h>
//
////逆序函数
//void reverse_string(char* string)
//{
//	int left = 0;
//	int right = strlen1(string)-1;
//	int tmp = 1;
//	while (left < right)
//	{
//		tmp = string[left];
//		string[left] = string[right];
//		string[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
////求字符串长度
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdefghijklmnopqrstuvwxyz";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//逆序函数
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////2.0  递归实现
//#include<stdio.h>
//
////逆序函数
//void reverse_string(char* string)
//{
//	//定义参数
//	int static i = 0;
//	int n = strlen1(string);
//	int t = 1;
//	//交换
//	t = *(string);
//	*(string) = *(string + n - 1 - i);
//	*(string + n - 1 - i) = t;
//	
//	//递归,结束条件
//	//注意,字符串长度分为: 奇偶. n - 1 - i变化规律不同. 奇数时:2 -> 0;  偶数时:3 -> 1
//	if (n - 1 - i > 1)
//	{
//		i++;
//		reverse_string(string + 1);
//	}
//
//}
//
////求字符串长度
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdef123456789";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//逆序函数
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////3.0  递归实现  代码优化
//#include<stdio.h>
//
////逆序函数
//void reverse_string(char* string)
//{
//	//定义参数
//	int n = my_strlen(string);
//	int t = 1;
//	//交换
//	t = *string;//可以写为string[0]
//	*(string) = *(string + n - 1);//可以写为string[n-1]
//	*(string + n - 1) = '\0';//改变末尾,缩短对齐
//
//	//递归,结束条件
//	if (string +1 < string +n -1)//等价于: if(my_strlen(string+1) >= 2)
//	{
//		reverse_string(string + 1);
//	}
//	*(string + n - 1) = t;
//}
//
////求字符串长度
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + my_strlen(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdef1";
//	printf("%s\n", arr);
//	printf("%d\n", my_strlen(arr));
//	//逆序函数
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////【题目名称】
////计算一个数的每位之和（递归实现）
////【题目内容】
////写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
////输入：1729，输出：19
//
////1729  >  1 729  >  1 7 29
//
//#include<stdio.h>
//
////位加和函数
//int DigitSum(int x)
//{
//	if (x / 10 != 0)
//	{
//		return x % 10 + DigitSum(x / 10);
//	}
//	else
//		return x % 10;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//位加和函数
//	printf("%d", DigitSum(a));
//	return 0;
//}



////【题目名称】
////递归实现n的k次方
////【题目内容】
////编写一个函数实现n的k次方，使用递归实现。
//
////1.0  思路:  n^k = n*n^(k-1) = n*n*n....*n	假设 n 和 k 都是正整数
//
//#include<stdio.h>
//
////n的k次方函数
//int resnk(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * resnk(n, k - 1);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	int k = 1;
//	scanf("%d%d", &n, &k);
//	//n的k次方函数
//	printf("%d", resnk(n, k));
//	return 0;
//}

////2.0  实现负数次幂
//#include<stdio.h>
//
////n的k次方函数
//float resnk(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * resnk(n, k - 1);
//	}
//	else if (0 == k)
//	{
//		return 1;
//	}
//	if(k < 0)
//	{
//		return 1/resnk(n, -k);
//	}
//}
//
//int main()
//{
//	int n = 1;
//	int k = 1;
//	scanf("%d%d", &n, &k);
//	//n的k次方函数
//	printf("%f", resnk(n, k));
//	return 0;
//}


//【题目名称】
//计算斐波那契数
//【题目内容】
//递归和非递归分别实现求第n个斐波那契数
//例如：
//输入：5  输出：5
//输入：10， 输出：55
//输入：2， 输出：1

//思路: 1 1 2 3 5 8 13 21 34 55 89
//		f(n) = f(n-1) + f(n-2)

////1.0 非递归
//#include<stdio.h>
//
////斐波那契函数
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int i = 1;
//	if (n >= 3)
//	{
//		for (i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	scanf("%d", &n);
//	//斐波那契函数
//	printf("%d", fib(n));
//	return 0;
//}

////2.0 递归
//#include<stdio.h>
//
////斐波那契函数
//int fib(int n)
//{
//	if (n >= 3)
//	{
//		return fib(n-1)+fib(n-2);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	scanf("%d", &n);
//	//斐波那契函数
//	printf("%d", fib(n));
//	return 0;
//}

