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
//
//}

////1.0  想了好久,一直调试,勉强达到
//void reverse(char* str)
//{
//	char tmp[110] = " ";
//	strcpy((tmp+1), str);//前面制造一个 空格
//	int sz = strlen(tmp);
//	char* p = tmp + sz;
//	char* p1 = tmp + sz;
//	char* p2 = tmp + sz;
//	char arr[110] = " ";
//	char* pa1 = arr;
//	char* pa2 = arr;
//	while (p >= p1 - sz)
//	{
//		if (*(p - 1) == ' ')
//		{
//			strcpy(pa1, p);
//			pa1 = pa1 + (p2 - p);
//			*pa1 = ' ';//最后一次多了一个 空格	影响似乎不大
//			pa1++;
//			p2 = p-1;
//			*(p-1) = '\0';
//		}
//		p--;
//	}
//	strcpy(str, pa2);
//}
//int main()
//{
//	char arr1[110] = "I like beijing.";
//	//scanf("%s", arr1);//scanf()遇到 空格 就停止读取,不行
//	gets(arr1);
//	//倒置
//	reverse(arr1);
//	printf("%s\n", arr1);
//	return 0;
//}

////2.0	代码优化
//void reverse(char* start,char* end)//倒置 start 到 end之间的字母
//{
//	int left = 0;
//	int right = end - start;
//	char tmp = '0';
//	while (left < right)
//	{
//		tmp = start[left];
//		start[left] = start[right];
//		start[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr1[110] = "I like beijing.";
//	//scanf("%s", arr1);//scanf()遇到 空格 就停止读取,不行
//	gets(arr1);//读取一行,存入字符串
//	char* start = arr1;
//	char* end = arr1 + strlen(arr1) - 1;
//	//两次翻转法
//	reverse(start,end);//整体倒置
//	//局部倒置,倒置每个单词
//	end = start;
//	while (*end != '\0')
//	{
//		if (*(end+1) == ' ' || *(end + 1 ) == '\0') //每个单词间以空格隔断
//		{
//			reverse(start, end);//倒置单词
//			start = end + 2;//空格的下一位,即单词的首字母位
//		}
//		end++;
//	}
//
//	printf("%s\n", arr1);
//	return 0;
//}
//总结:
//写代码思路比写更重要,思路不清晰,写出的代码需要漫长的调试理清思路.
//写之前先分析一下问题,指定大体框架,写就是填补完善框架.

