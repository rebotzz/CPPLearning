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
//}



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
//}

