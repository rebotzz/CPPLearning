#define _CRT_SECURE_NO_WARNINGS

//指针初阶 作业

//试验结构体 指针
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b, * p = &b;
//	//等价于
//	//int b;
//	//int* p = &b;
//
//	struct stu
//	{
//		int x;
//		int y;
//	}s1;
//	struct stu s2, * p2 = &s2;
//	struct stu* p1 = &s1;
//	(*p1).x = 1;
//	s1.y = 2;
//	return 0;
//}


//【题目名称】
//喝汽水问题
//【题目内容】
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。

//1.0
//#include <stdio.h>
//
//int main()
//{
//	int money = 20;
//	int i = 0;
//	int count = 0;
//	int leave = 0;
//
//	for (i = money; i >= 1; )
//	{
//		count += i;
//		if (i % 2 == 0 && i != 1)
//		{
//			i /= 2;
//		}
//		else
//		{
//			i /= 2;
//			leave++;
//		}
//		if (leave % 2 == 0 && leave != 0)
//		{
//			i =i + leave/2;
//			leave = 0;
//		}
//	}
//	printf("%d \n", count);
//	return 0;
//}

////2.0	代码优化
//#include <stdio.h>
//
//int main()
//{
//	int money = 20;
//	scanf("%d", & money);
//	int count = money;
//	int leave = money;
//	while (leave > 1)
//	{
//		//不错的思路
//		count += leave/2;
//		leave = leave / 2 + leave % 2;
//	}
//	printf("%d \n", count);
//	return 0;
//}

////3.0	代码优化
//#include <stdio.h>
//
//int main()
//{
//	int money = 20;
//	scanf("%d", &money);
//	//数学分析后 等差数列 an = 2*n -1
//	printf("%d \n", 2 * money - 1);
//	return 0;
//}


//【题目名称】
//打印菱形
//【题目内容】
//用C语言在屏幕上输出以下图案：13行 13列

//1.0
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 7; i++)
//	{
//		j = 6 - i;
//		while (j)
//		{
//			printf(" ");
//			j = j--;
//		}
//		j = 2 * i +1;
//		while (j)
//		{
//			printf("*");
//			j--;
//		}
//		printf("\n");
//	}
//	for (i = 5; i >= 0; i--)
//	{
//		j = 6 - i;
//		while (j)
//		{
//			printf(" ");
//			j = j--;
//		}
//		j = 2 * i + 1 ;
//		while (j)
//		{
//			printf("*");
//			j--;
//		}
//		printf("\n");
//	}
//	return 0;
//}

////2.0  代码优化
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int line = 13;
//	scanf("%d", &line);//输入一个奇数作为 行 列,不用奇数也行
//	//打印上半部分
//	for (i = 0; i <= line/2; i++)
//	{
//		j = line/2 - i;
//		while (j)
//		{
//			printf(" ");
//			j = j--;
//		}
//		j = 2 * i + 1;
//		while (j)
//		{
//			printf("*");
//			j--;
//		}
//		printf("\n");
//	}
//	//打印下班部分
//	for (i = line/2-1; i >= 0; i--)
//	{
//		j = line/2 - i;
//		while (j)
//		{
//			printf(" ");
//			j = j--;
//		}
//		j = 2 * i + 1;
//		while (j)
//		{
//			printf("*");
//			j--;
//		}
//		printf("\n");
//	}
//	return 0;
//}

//3.0	别人的代码,仅供参考
/*
思路：
仔细观察图形，可以发现，此图形中是由空格和*按照不同个数的输出组成的。
上三角：先输出空格，后输出*，每行中
  空格：从上往下，一行减少一个
  *：2*i+1的方式递增

下三角：先输出空格，后输出*，每行中
  空格：从上往下，每行多一个空格
  *： 从上往下，按照2*(line-1-i)-1的方式减少，其中：line表示总共有多少行
按照上述方式，将上三角和下三角中的空格和*分别输出即可。
*/

//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	int i = 0;
//	scanf("%d", &line);//7
//	//打印上半部分
//	for (i = 0; i < line; i++)
//	{
//		//打印一行
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//
//	//打印下半部分
//	for (i = 0; i < line - 1; i++)
//	{
//		//打印一行
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//【题目名称】
//字符串逆序
//【题目内容】
//写一个函数，可以逆序一个字符串的内容。

//1.0
//#include <stdio.h>
//#include <string.h>
//
////逆序函数
//void reverse(char* str,int sz)
//{
//	char tmp = 0;
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[] = "this is a c code.";
//	//打印
//	printf("%s\n", str);
//	int sz = strlen(str);
//	//逆序函数
//	reverse(str,sz);
//	//打印
//	printf("%s\n", str);
//	return 0;
//}

////2.0	方法二	递归实现
//#include <stdio.h>
//#include <string.h>
//
////逆序函数
//void reverse(char* str)
//{
//	char tmp = 0;
//	int left = 0;
//	int right = strlen(str)-1;//strlen() 检测的是字符串数组最后的 '\0' ,参数是数组首元素地址
//	//交换
//	tmp = str[left];
//	str[left] = str[right];
//	str[right] = '\0';
//	if (right > 1)
//		reverse(str + 1);//递归
//	str[right] = tmp;
//}
//
//int main()
//{
//	char str[100] = "this is a c code.";
//	scanf("%s", &str);
//	//打印
//	printf("%s\n", str);
//	//逆序函数
//	reverse(str);
//	//打印
//	printf("%s\n", str);
//	return 0;
//}