#define _CRT_SECURE_NO_WARNINGS

//局部变量与全局变量冲突时,局部变量优先.	比如有两个 int a = 1;一个全局,一个局部

//int main()//位置可以任意
//{
//	printf("s\n");
//	return 0;
//}
//#include <stdio.h>


//求最小公倍数
#include <stdio.h>

//1.0
//int min_muitiple(int x, int y)//求最小公倍数
//{
//	int i = x * y;
//	int min = 0;
//	//以下为优化
//	int min_unit = x > y ? y : x;
//	for (i = x * y; (i >= x) && (i >= y);i = i - min_unit)
//	{
//		if ((i % x == 0) && (i % y == 0))
//		{
//			min = i;
//		}
//	}
//	return min;
//}

//2.0
//int min_muitiple(int x, int y)//求最小公倍数
//{
//	int i = 1;
//	for (i = 1; ; i++)
//	{
//		if (x*i%y == 0)
//		{
//			break;
//		}
//	}
//	return x*i;
//}

////3.0
//int min_muitiple(int x, int y)//辗转相除得最大公约数, 最小公倍数 = x*y / 最大公约数
//{
//	int m = x * y;
//	int max = x > y ? x : y;
//	int n = x % y;//余数
//	while (n)
//	{
//		x = y;
//		y = n;
//		n = x % y;//辗转相除
//	}
//	//最大公约数 y
//	m = m / y;//最大公约数
//	return m;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = min_muitiple(a, b);//求最小公倍数
//	printf("%d\n", ret);
//	return 0;
//}


//题目描述
//将一句话的单词进行倒置，标点不倒置。比如l like beijing.经过函数后变为: beijing.like l
//输入描述 :
//每个测试输入包含1个测试用例: 工 like beijing．输入用例长度不超过100
//输出描述 :
//依次输出倒置之后的字符串，以空格分割
#include <stdio.h>
#include <string.h>

//未实现
//void reverse(char* str)
//{
//	int sz = strlen(str) - 1;
//	int i = sz;
//	char* start = str;
//	char* end = str + sz;
//	char arr[20] = "  ";
//	int count = 0;
//	while (end >= start)
//	{
//		count++;
//		if (*end == ' ')
//		{
//			for (int j = 0; j < count; j++)
//			{
//				arr[sz-i] = str[i];
//				i--;
//			}
//		}
//		end--;
//	}
//	arr[i] = str[i];// '\0'
//	strcpy(str, arr);
//}

//想了好久,一直调试,勉强达到
void reverse(char* str)
{
	char tmp[110] = " ";
	strcpy((tmp+1), str);//前面制造一个 空格
	int sz = strlen(tmp);
	char* p = tmp + sz;
	char* p1 = tmp + sz;
	char* p2 = tmp + sz;
	char arr[110] = " ";
	char* pa1 = arr;
	char* pa2 = arr;
	while (p >= p1 - sz)
	{
		if (*(p - 1) == ' ')
		{
			strcpy(pa1, p);
			pa1 = pa1 + (p2 - p);
			*pa1 = ' ';//最后一次多了一个 空格
			pa1++;
			p2 = p-1;
			*(p-1) = '\0';
		}
		p--;
	}
	strcpy(str, pa2);
}
int main()
{
	char arr1[110] = "I like beijing.";
	//scanf("%s", arr1);//scanf()遇到 空格 就停止读取,不行
	gets(arr1);
	//倒置
	reverse(arr1);
	printf("%s\n", arr1);
	return 0;
}

//2.0	代码优化