#define _CRT_SECURE_NO_WARNINGS

//ָ����� ��ҵ

//����ṹ�� ָ��
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b, * p = &b;
//	//�ȼ���
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


//����Ŀ���ơ�
//����ˮ����
//����Ŀ���ݡ�
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���

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

////2.0	�����Ż�
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
//		//�����˼·
//		count += leave/2;
//		leave = leave / 2 + leave % 2;
//	}
//	printf("%d \n", count);
//	return 0;
//}

////3.0	�����Ż�
//#include <stdio.h>
//
//int main()
//{
//	int money = 20;
//	scanf("%d", &money);
//	//��ѧ������ �Ȳ����� an = 2*n -1
//	printf("%d \n", 2 * money - 1);
//	return 0;
//}


//����Ŀ���ơ�
//��ӡ����
//����Ŀ���ݡ�
//��C��������Ļ���������ͼ����13�� 13��

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

////2.0  �����Ż�
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int line = 13;
//	scanf("%d", &line);//����һ��������Ϊ �� ��,��������Ҳ��
//	//��ӡ�ϰ벿��
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
//	//��ӡ�°ಿ��
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

//3.0	���˵Ĵ���,�����ο�
/*
˼·��
��ϸ�۲�ͼ�Σ����Է��֣���ͼ�������ɿո��*���ղ�ͬ�����������ɵġ�
�����ǣ�������ո񣬺����*��ÿ����
  �ո񣺴������£�һ�м���һ��
  *��2*i+1�ķ�ʽ����

�����ǣ�������ո񣬺����*��ÿ����
  �ո񣺴������£�ÿ�ж�һ���ո�
  *�� �������£�����2*(line-1-i)-1�ķ�ʽ���٣����У�line��ʾ�ܹ��ж�����
����������ʽ���������Ǻ��������еĿո��*�ֱ�������ɡ�
*/

//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	int i = 0;
//	scanf("%d", &line);//7
//	//��ӡ�ϰ벿��
//	for (i = 0; i < line; i++)
//	{
//		//��ӡһ��
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//
//	//��ӡ�°벿��
//	for (i = 0; i < line - 1; i++)
//	{
//		//��ӡһ��
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


//����Ŀ���ơ�
//�ַ�������
//����Ŀ���ݡ�
//дһ����������������һ���ַ��������ݡ�

//1.0
//#include <stdio.h>
//#include <string.h>
//
////������
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
//	//��ӡ
//	printf("%s\n", str);
//	int sz = strlen(str);
//	//������
//	reverse(str,sz);
//	//��ӡ
//	printf("%s\n", str);
//	return 0;
//}

////2.0	������	�ݹ�ʵ��
//#include <stdio.h>
//#include <string.h>
//
////������
//void reverse(char* str)
//{
//	char tmp = 0;
//	int left = 0;
//	int right = strlen(str)-1;//strlen() �������ַ����������� '\0' ,������������Ԫ�ص�ַ
//	//����
//	tmp = str[left];
//	str[left] = str[right];
//	str[right] = '\0';
//	if (right > 1)
//		reverse(str + 1);//�ݹ�
//	str[right] = tmp;
//}
//
//int main()
//{
//	char str[100] = "this is a c code.";
//	scanf("%s", &str);
//	//��ӡ
//	printf("%s\n", str);
//	//������
//	reverse(str);
//	//��ӡ
//	printf("%s\n", str);
//	return 0;
//}