<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS

//ָ�����ѧϰ 3


//����Ŀ���ơ�
//�ַ�����ת���
//����Ŀ���ݡ�
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

//����:����������,ѭ��,����˳��,���εõ���ת��ý��,���бȽ�
//���� ���� ���� ��һһ��ֻҪѡ�������п�����,�Ͱ�����һ��ѡ��Ŀ�����
#include <stdio.h>
#include <string.h>

////1.0
//void rotate(char* s1)
//{
//	//�����������ݷ��Ľ�������
//	int sz = strlen(s1);
//	//�������ѭ��,һ��ֻ��ת1��Ԫ��
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
//			//����,�ⲻ�ǵ����Ľ���,��������ƶ�
//			//rotate(s1);//����֮��,�ı���s1ԭ�е�ֵ
//			rotate(tmp);//���ı�s1ԭ�е�ֵ
//
//			//�ж�
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
//	gets(s1);//gets()������char*
//	//getchar();
//	gets(s2);
//	//�ж��Ƿ���ת
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
//			//�ж�
//			if (strcmp(tmp, s2) == 0)
//				return 1;
//		}
//	}
//	return 0;
//}

////2.0		ȫ�ÿ⺯��ʵ��,���,ʡʱ��
//#include <assert.h>
//int judge_rotate(char* s1,char* s2)
//{
//	assert(s1);
//	assert(s2);
//	//�ж�s1 s2�����Ƿ�һ��
//	if (strlen(s1) != strlen(s2))
//	{
//		return 0;
//	}
//	//1. s1:  AABCD �ӳ�Ϊ AABCDAABCD
//	strncat(s1, s1, strlen(s1));//��˼��� strlen(s1) ���ַ���
//	//2. �ж�s2�Ƿ���s1���Ӵ�
//	char* ret = strstr(s1, s2);//�����Ӵ�,����NULL,���Ӵ����ض�Ӧ��ַ
//	return ret != NULL;
//}
//
//int main()
//{
//	char s1[20] = "hello world.";
//	char s2[20] = "hello siri.";
//	gets(s1);//gets()������char*
//	//getchar();
//	gets(s2);
//	//�ж��Ƿ���ת
//	int ret = judge_rotate(s1, s2);
//	printf("%d\n", ret);
//
//	return 0;
//}


//�ο�����
#include<stdio.h>
#include<string.h>

//int judge(const char* str1, const char* str2)
//{
//	char str3[200] = { 0 };
//	strcpy(str3, str1);//����str1�ַ�����str3����	//AABCD
//	strcat(str3, str1);//��str1���ַ������ӵ�str3����	//AABCDAABCD
//	return strstr(str3, str2) != NULL;//����str3�����Ƿ���str2�ַ����ĳ���,�оͷ���1	//AABCDAABCD �������Ƿ��� BCDAA,�оͷ�����ʼ��ַ
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
=======
﻿#define _CRT_SECURE_NO_WARNINGS

//数据结构学习
//时间复杂度&空间复杂度







//// 计算BinarySearch的时间复杂度？
////二分查找
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);//二进制右移一位 ==> 除以2
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
>>>>>>> w6/main
//}



<<<<<<< HEAD
//����Ŀ���ơ�
//�ַ�������
//����Ŀ���ݡ�
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include <stdio.h>

////1.0
////����numλ
//void rotate_num_L(char* s1,int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//�����Ż�
//	for (j = 0; j < num; j++)
//	{
//		for (i = 0; i < sz - 1; i++)//��������,�����ƶ���ĩ��
//		{
//			char tmp = s1[i];
//			s1[i] = s1[i + 1];
//			s1[i + 1] = tmp;
//		}
//	}
//}

////2.0	�����Ż�
////void rotate_num_L(char* s1,int num)
////{
////	int i = 0;
////	int sz = strlen(s1);
////	int j = 0;
////	num = num % sz;//�����Ż�
////	for (j = 0; j < num; j++)
////	{
////		char tmp = s1[0];
////		for (i = 0; i < sz - 1; i++)//��������,�����ƶ���ĩ��
////		{
////			s1[i] = s1[i + 1];
////		}
////		s1[sz -1] = tmp;
////	}
////}

////3.0	�����Ż�
//void rotate_num_L(char* s1, int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//�����Ż�
//	for (j = 0; j < num; j++)
//	{
//		char tmp = s1[0];
//		for (i = 0; i < sz - 1; i++)//��������,�����ƶ���ĩ��
//		{
//			s1[i] = s1[i + 1];
//		}
//		s1[sz - 1] = tmp;//ֻ�ý�����ĩ�˾���
//	}
//}

////4.0	�����Ż�	strcat �ڸ���һ�ݷ��ں���
//void rotate_num_L(char* s1, int num)
//{
//	int sz = strlen(s1);
//	num = num % sz;
//	char tmp[100];
//	strcpy(tmp, s1 + num);//����ת����ĸ��Ƶ�tmp,
//	strcat(tmp, s1);//����תǰ��Ĳ������ӵ�tmp,
//	tmp[sz] = '\0';
//	strcpy(s1,tmp);
//}

////5.0	�����Ż�	���η�ת��
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
//	//���η�ת��		abcde
//	//1�η�ת
//	reverse(s1, s1 + num -1);//cba de	num = 3, s1 +2 ==> 'c'
//	//2�η�ת
//	reverse(s1 + num, s1 + sz - 1);//cba ed
//	//3�η�ת
//	reverse(s1, s1 + sz - 1);//de abc
//}
//
//int main()
//{
//	char s1[50] = "hello";
//	gets(s1);
//	int num = 0;
//	scanf("%d", &num);
//	//����numλ
//	rotate_num_L(s1,num);
//	//��ӡ
//	printf("%s\n", s1);
//	return 0;
=======















//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//注意：本题相对书上原题稍作改动
//示例 1：
//输入：[3, 0, 1]
//输出：2
//示例 2：
//输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
//输出：8
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/missing-number-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <stdio.h>

////1.0
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int sum = 0;
//    //两两异或
//    for (i = 0; i <= numsSize; i++)
//    {
//        sum ^= i;
//    }
//    for (i = 0; i < numsSize; ++i)
//    {
//        sum ^= nums[i];
//
//    }
//    return sum;
//}


////2.0
//int missingNumber(int* nums, int numsSize) {
//    // 存放到数组
//    int i = 0;
//    //开辟空间,数组
//    int* tmp = (int*)calloc(numsSize + 1, sizeof(int));
//    if (tmp == NULL)
//    {
//        return 1;
//    }
//    //初始化为-1
//    for (i = 0; i <= numsSize; i++)
//    {
//        tmp[i] = -1;
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//
//        tmp[nums[i]] = nums[i];
//
//
//    }
//    //其中一个元素没有存入
//    for (i = 0; i <= numsSize; i++)
//    {
//        //初始化 0,排除 i = 0
//        //解决方法,改变初始化值 -1
//        if (tmp[i] != i)
//        {
//            break;
//        }
//    }
//
//    //释放空间
//    free(tmp);
//    tmp = NULL;
//    return i;
//}
//
//
////3.0
//int missingNumber(int* nums, int numsSize) {
//    //加和0~ n,在减去数组
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i <= numsSize; i++)
//    {
//        if (i < numsSize)
//        {
//            sum = sum + i - nums[i];
//        }
//        else
//        {
//            sum += i;
//        }
//
//    }
//    return sum;
>>>>>>> w6/main
//}



<<<<<<< HEAD
//���Ͼ���
//��Ŀ����:
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ����.
//Ҫ��:ʱ�临�Ӷ�С��o(N)��


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
//	//��ʼ��
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			//arr[i][j] = i+j +1;
//			arr[i][j] =a++;
//		}
//	}
//	//��ӡ
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()������ʽҪһ��
//
//	////����n		1.0
//	//for (i = 0; i < ROW; i++)
//	//{
//	//	for (j = 0; j < COL; j++)
//	//	{
//	//		if (arr[ROW - 1][j] < n)//��һ����û��
//	//		{
//	//			continue;
//	//		}
//	//		if (arr[i][COL - 1] >= n)//��һ���п��ܴ���
//	//		{
//	//			if (n == arr[i][j])
//	//			{
//	//				printf("����,arr[%d][%d] = %d\n", i, j, n);
//	//				return 0;
//	//			}
//	//		}
//	//		else
//	//			break;
//	//	}
//	//}
//
//	//����n		2.0
//	int count = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = COL -1; j >=0; j--)
//		{
//			count++;
//			if (arr[i][COL - 1] >= n)//��һ���п��ܴ���
//			{
//				if (n == arr[i][j])
//				{
//					printf("����,arr[%d][%d] = %d\n", i, j, n);
//					printf("���Ҵ���count = %d\n", count);
//					return 0;
//				}
//			}
//			else
//				break;
//		}
//	}
//	printf("������.\n");
//	return 0;
//}


////2.0	�ο����Լ�д

//int find_n(int arr[ROW][COL], int* px, int* py, int n)
//{
//	int x = 0;
//	int y = *py - 1;//ĩβ��
//	while (x < *px && y >= 0)//&& ���ȼ����� < >=
//	{
//		if (arr[x][y] < n)//x�����ֵС�� n
//		{
//			x++;
//		}
//		else if (arr[x][y] > n)//��x�м��Ժ���,��y��,arr[x][y]����һ������С��ֵ.arr[x][y]Ҳ�� arr[x+i][y+i]֮�����Сֵ
//		{
//			y--;
//		}
//		else	//����Ҫ�ж��Ƿ����.==> �����arr[x][y] < n �� arr[x][y] > n �ų����������,ֻʣ��arr[x][y] == n
//		{
//			*px = x;
//			*py = y;
//			return 1;//�ҵ� return 1
//		}
//	}
//	
//	return 0;//�Ҳ��� return 0
//}
//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int a = 1;
//	//��ʼ��
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
//	//��ӡ
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()������ʽҪһ��
//	//����
//	int x = ROW;
//	int y = COL;
//	int ret = find_n(arr, &x, &y, n);
//	if (ret == 1)
//	{
//		printf("�ҵ���,����x = %d,y = %d\n", x, y);
//	}
//	else
//		printf("�Ҳ���.\n");
//	return 0;
=======

//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//示例 1:
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//    向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//    向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//    向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//    示例 2 :
//    输入：nums = [-1, -100, 3, 99], k = 2
//    输出：[3, 99, -1, -100]
//    解释 :
//    向右轮转 1 步 : [99, -1, -100, 3]
//    向右轮转 2 步 : [3, 99, -1, -100]
//    提示：
//    1 <= nums.length <= 105
//    - 231 <= nums[i] <= 231 - 1
//    0 <= k <= 105
//    进阶：
//    尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
//    你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//    来源：力扣（LeetCode）
//    链接：https ://leetcode.cn/problems/rotate-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <stdio.h>

//1.0
//void rotate(int* nums, int numsSize, int k) {
//    //memmove
//    int n = numsSize;
//    int* arr = (int*)malloc(numsSize * sizeof(int));
//    //拷贝nums 到 arr
//    memcpy(arr, nums, n * sizeof(int));
//    k %= numsSize;
//    //n - k 位置开始的k个元素移动到首位
//    memmove(nums, nums + n - k, k * sizeof(int));
//    //n - k -1 ~ n -1的 n - k个元素移动到 n + k位置
//    memmove(nums + k, arr, (n - k) * sizeof(int));
//
//    free(arr);
//    arr = NULL;
//
//}

////2.0
//void rotate(int* nums, int numsSize, int k) {
//    //接长数组,截取
//    int n = numsSize;
//    k %= n;
//    int* tmp = (int*)malloc(2 * n * sizeof(int));
//    memcpy(tmp, nums, n * sizeof(int));
//    memcpy(tmp + n, nums, n * sizeof(int));
//    //截取,tmp + n - k 位置开始,n个元素
//    memcpy(nums, tmp + n - k, n * sizeof(int));
//
//
//    free(tmp);
//    tmp = NULL;
//}

//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
////3.0
//void rotate(int* nums, int numsSize, int k) {
//    //三次翻转法
//    //前部分翻转,0 ~ n - k -1
//    int n = numsSize;
//    k %= n;
//    reverse(nums, 0, n - k - 1);
//    //后部分翻转,n - k ~ n - 1
//    reverse(nums, n - k, n - 1);
//    //整体翻转,0 ~ n - 1
//    reverse(nums, 0, n - 1);
//
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    rotate(arr, sz, 14);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    return 0;
>>>>>>> w6/main
//}