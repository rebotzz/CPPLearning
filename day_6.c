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

////1.5
//int judge_rotate(const char* s1, const char* s2)
//{
//	int sz1 = strlen(s1);
//	int sz2 = strlen(s2);
//	char tmp[50];
//	strcpy(tmp, s1);
//	if (sz1 == sz2)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < sz1; i++)
//		{
//			for (j = 0; j < sz1 - 1; j++)
//			{
//				char t = tmp[j];
//				tmp[j] = tmp[j + 1];
//				tmp[j + 1] = t;
//			}
//			//判断
//			if (strcmp(tmp, s2) == 0)
//				return 1;
//		}
//	}
//	return 0;
//}

////2.0		全用库函数实现,简洁,省时间
//#include <assert.h>
//int judge_rotate(char* s1,char* s2)
//{
//	assert(s1);
//	assert(s2);
//	//判断s1 s2长度是否一样
//	if (strlen(s1) != strlen(s2))
//	{
//		return 0;
//	}
//	//1. s1:  AABCD 加长为 AABCDAABCD
//	strncat(s1, s1, strlen(s1));//后端加上 strlen(s1) 个字符串
//	//2. 判断s2是否是s1的子串
//	char* ret = strstr(s1, s2);//不是子串,返回NULL,是子串返回对应地址
//	return ret != NULL;
//}
//
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
//#include <assert.h>
//
//void reverse(char* start, char* end)
//{
//	assert(start);
//	assert(end);
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
//	assert(s1);
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



//杨氏矩阵
//题目内容:
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
//请编写程序在这样的矩阵中查找某个数字是否存在.
//要求:时间复杂度小于o(N)；


//1 2 3 4 
//2 3 4 5
//3 4 5 6
#include <stdio.h>
#define ROW 5
#define COL 5

//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int a = 1;
//	//初始化
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			//arr[i][j] = i+j +1;
//			arr[i][j] =a++;
//		}
//	}
//	//打印
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()函数格式要一致
//
//	////查找n		1.0
//	//for (i = 0; i < ROW; i++)
//	//{
//	//	for (j = 0; j < COL; j++)
//	//	{
//	//		if (arr[ROW - 1][j] < n)//这一列中没有
//	//		{
//	//			continue;
//	//		}
//	//		if (arr[i][COL - 1] >= n)//这一行中可能存在
//	//		{
//	//			if (n == arr[i][j])
//	//			{
//	//				printf("存在,arr[%d][%d] = %d\n", i, j, n);
//	//				return 0;
//	//			}
//	//		}
//	//		else
//	//			break;
//	//	}
//	//}
//
//	//查找n		2.0
//	int count = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = COL -1; j >=0; j--)
//		{
//			count++;
//			if (arr[i][COL - 1] >= n)//这一行中可能存在
//			{
//				if (n == arr[i][j])
//				{
//					printf("存在,arr[%d][%d] = %d\n", i, j, n);
//					printf("查找次数count = %d\n", count);
//					return 0;
//				}
//			}
//			else
//				break;
//		}
//	}
//	printf("不存在.\n");
//	return 0;
//}


////2.0	参考后自己写

//int find_n(int arr[ROW][COL], int* px, int* py, int n)
//{
//	int x = 0;
//	int y = *py - 1;//末尾列
//	while (x < *px && y >= 0)//&& 优先级低于 < >=
//	{
//		if (arr[x][y] < n)//x行最大值小于 n
//		{
//			x++;
//		}
//		else if (arr[x][y] > n)//在x行及以后行,第y列,arr[x][y]是这一列中最小的值.arr[x][y]也是 arr[x+i][y+i]之后的最小值
//		{
//			y--;
//		}
//		else	//不需要判断是否相等.==> 上面的arr[x][y] < n 和 arr[x][y] > n 排除了其他情况,只剩下arr[x][y] == n
//		{
//			*px = x;
//			*py = y;
//			return 1;//找到 return 1
//		}
//	}
//	
//	return 0;//找不到 return 0
//}
//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int a = 1;
//	//初始化
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (i == ROW - 1 && j == 0)
//			{
//				a = a + COL;
//			}
//			arr[i][j] =a++;
//		}
//	}
//	//打印
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()函数格式要一致
//	//查找
//	int x = ROW;
//	int y = COL;
//	int ret = find_n(arr, &x, &y, n);
//	if (ret == 1)
//	{
//		printf("找到了,坐标x = %d,y = %d\n", x, y);
//	}
//	else
//		printf("找不到.\n");
//	return 0;
//}