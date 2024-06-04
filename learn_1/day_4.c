#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//练习1：
//实现功能，判断一个数的奇偶性
//思路，if语句，一个数对2求余数，%2.

////绝对值函数
//int abs_val(int x)
//{
//	if (x >= 0)
//	{
//		return x;
//	}
//	else
//	{
//		return -x;
//	}
//}
//
//int main()
//{
//	int n = -57;
//	int a = 0;
//	int b = 0;
//	//scanf("%d",&n);
//	a = abs_val(n);
//	b = a % 2;
//	if (0 == b)
//	{
//		printf("偶数");
//	}
//	else
//	{
//		printf("奇数");
//
//	}
//
//	return 0;
//}


////思路简化
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d",&n);
//	a = n % 2;
//	//if只要非零就为真，不论正负。
//	//if和else就近原则，为了不误解，用大括号
//	//if判断，以防 == 忘写为 = ，常数项放左边
//	if (0 == a)
//	{
//		printf("偶数");
//	}
//	else
//	{
//		printf("奇数");
//	}
//	return 0;
//}


//练习2：
//输出1-100之间的奇数
//思路，需要应用到循环，数组?不用，每次+1，从1开始，if（n%2） ;else 输出

//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100; i++)
//	{
//		//如果i%2不为0，if为真，执行
//		if (i % 2)
//		{
//			printf("%d\n", i);
//		}
//		
//	}
//	return 0;
//}

////用while循环试试
//int main()
//{
//	int i = 0;
//	while (i <= 100)
//	{
//		if (i % 2)
//		{
//			printf("%d\n",i);
//		}
//		i++;
//	}
//	return 0;
//}

////方法3：
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100; i = i + 2)
//	{
//			printf("%d ", i);
//	}
//	return 0;
//}


////if 多分支练习
//int main()
//{
//	int n = 48;
//	if (n < 0) 
//	{
//		printf("n为负数\n");
//	}
//	else if (n >= 0 && n < 30)
//	{
//		printf("0<= n < 30\n");
//	}
//	else if (n >= 30 && n < 50)
//	{
//		printf("n在30和50之间\n");
//	}
//	else if (n >= 50 && n < 80)
//	{
//		printf("n在50和80之间\n");
//	}
//	else if (n >= 80 )
//	{
//		printf("n大于等于80\n");
//	}
//	return 0;
//}
