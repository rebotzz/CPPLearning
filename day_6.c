#define _CRT_SECURE_NO_WARNINGS

//指针进阶学习 3


//【题目名称】
//字符串旋转结果
//【题目内容】
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//分析:分左旋右旋,循环,交换顺序,依次得到旋转后得结果,进行比较
//左旋 或者 右旋 任一一种只要选择了所有可能性,就包含另一种选择的可能性
#include <stdio.h>
#include <string.h>

////1.0
//void rotate(char* s1)
//{
//	//可以利用起泡法的交换方法
//	int sz = strlen(s1);
//	//不用外层循环,一次只旋转1个元素
//	int j = 0;
//	for (j = 0; j < sz - 1 ; j++)
//	{
//		char tmp = s1[j];
//		s1[j] = s1[j+1];
//		s1[j+1] = tmp;
//	}
//}
//
//int judge_rotate(const char* s1,const char* s2)
//{
//	int sz1 = strlen(s1);
//	int sz2 = strlen(s2);
//	char tmp[50];
//	strcpy(tmp, s1);
//	if (sz1 == sz2)
//	{
//		int i = 0;
//		for (i = 0; i < sz1 - 1; i++)
//		{
//			//左旋,这不是单纯的交换,是整体的移动
//			//rotate(s1);//不足之处,改变了s1原有的值
//			rotate(tmp);//不改变s1原有的值
//
//			//判断
//			if (strcmp(tmp, s2) == 0)
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char s1[20] = "hello world.";
//	char s2[20] = "hello siri.";
//	gets(s1);//gets()参数是char*
//	//getchar();
//	gets(s2);
//	//判断是否旋转
//	int ret = judge_rotate(s1, s2);
//	printf("%d\n", ret);
//
//	return 0;
//}

//参考代码
#include<stdio.h>
#include<string.h>

//int judge(const char* str1, const char* str2)
//{
//	char str3[200] = { 0 };
//	strcpy(str3, str1);//拷贝str1字符串到str3里面	//AABCD
//	strcat(str3, str1);//把str1的字符串连接到str3里面	//AABCDAABCD
//	return strstr(str3, str2) != NULL;//搜索str3里面是否有str2字符串的出现,有就返回1	//AABCDAABCD 从中找是否有 BCDAA,有就返回起始地址
//}
//
//int main()
//{
//	char s1[200] = { 0 };//AABCD
//	char s2[200] = { 0 };//BCDAA
//	scanf("%s %s", s1, s2);
//	if (judge(s1, s2) && (strlen(s1) == strlen(s2)))
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//
//	return 0;
//}



//【题目名称】
//字符串左旋
//【题目内容】
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include <stdio.h>

////1.0
////左旋num位
//void rotate_num_L(char* s1,int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//代码优化
//	for (j = 0; j < num; j++)
//	{
//		for (i = 0; i < sz - 1; i++)//两两交换,依次移动到末端
//		{
//			char tmp = s1[i];
//			s1[i] = s1[i + 1];
//			s1[i + 1] = tmp;
//		}
//	}
//}

////2.0	代码优化
////void rotate_num_L(char* s1,int num)
////{
////	int i = 0;
////	int sz = strlen(s1);
////	int j = 0;
////	num = num % sz;//代码优化
////	for (j = 0; j < num; j++)
////	{
////		char tmp = s1[0];
////		for (i = 0; i < sz - 1; i++)//两两交换,依次移动到末端
////		{
////			s1[i] = s1[i + 1];
////		}
////		s1[sz -1] = tmp;
////	}
////}

////3.0	代码优化
//void rotate_num_L(char* s1, int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//代码优化
//	for (j = 0; j < num; j++)
//	{
//		char tmp = s1[0];
//		for (i = 0; i < sz - 1; i++)//两两交换,依次移动到末端
//		{
//			s1[i] = s1[i + 1];
//		}
//		s1[sz - 1] = tmp;//只用交换到末端就行
//	}
//}

////4.0	代码优化	strcat 在复制一份放在后面
//void rotate_num_L(char* s1, int num)
//{
//	int sz = strlen(s1);
//	num = num % sz;
//	char tmp[100];
//	strcpy(tmp, s1 + num);//将旋转后面的复制到tmp,
//	strcat(tmp, s1);//将旋转前面的部分连接到tmp,
//	tmp[sz] = '\0';
//	strcpy(s1,tmp);
//}

////5.0	代码优化	三次翻转法
//void reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void rotate_num_L(char* s1, int num)
//{
//	int sz = strlen(s1);
//	num = num % sz;
//	//三次翻转法		abcde
//	//1次翻转
//	reverse(s1, s1 + num -1);//cba de	num = 3, s1 +2 ==> 'c'
//	//2次翻转
//	reverse(s1 + num, s1 + sz - 1);//cba ed
//	//3次翻转
//	reverse(s1, s1 + sz - 1);//de abc
//}
//
//int main()
//{
//	char s1[50] = "hello";
//	gets(s1);
//	int num = 0;
//	scanf("%d", &num);
//	//左旋num位
//	rotate_num_L(s1,num);
//	//打印
//	printf("%s\n", s1);
//	return 0;
//}

