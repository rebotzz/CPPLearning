#define _CRT_SECURE_NO_WARNINGS

//�����ݹ���ϰ
//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ��
//���磺
//���룺1234����� 1 2 3 4.

//#include<stdio.h>
//
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);//1234
//	//��ӡ1 2 3 4
//	print(a);
//	return 0;
//}


////�ݹ���ϰ
//
//#include<stdio.h>
//
//void print(int x)
//{
//	if (x > 1)
//	{
//		x--;
//		print(x);
//	}
//	printf("hehe.\n");
//}
//
//int main()
//{
//	int a = 0;//����ջ���
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}

//��д��������������ʱ���������ַ����ĳ��ȡ�
//��ʵ�ֹ���,Ȼ���ڰ�����ĿҪ���Ż�
// 1.0
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr[] = "ada";
//	printf("%d",(int) strlen(arr));		//����ǿ��ת��
//	return 0;
//}

//2.0
//#include<stdio.h>
//
//int str_len(char* parr)		//���鴫�ݵ�����Ԫ�صĵ�ַ
//{
//	int i = 0;
//	while (1)
//	{
//		if (*parr != '\0')
//		{
//			i++;
//			parr++;
//		}
//		else
//			break;
//	}
//	return i;
//}
//
//int main()
//{
//	char arr[] = "leon";
//	//�Զ��庯�����ַ�������
//	printf("%d", str_len(&arr));
//	return 0;
//}

//3.0	��������ʱ�������
//˼· ֱ�� return �ݹ�
//�ݹ�ĺ���:  ���»�С,��������ΪС����
//"leon\0"
//1 + "eon\0"
//1+1+"on\0"
//1+1+1+"n\0"
//1+1+1+1+"\0"
//"\0"  ---->   0
// 
//#include<stdio.h>
//
//int str_len(char* parr)		//���鴫�ݵ�����Ԫ�صĵ�ַ
//{
//		if (*parr != '\0')
//			return 1 + str_len(parr + 1);
//		else 
//			return 0;
//}
//
//int main()
//{
//	char arr[] = "leon";
//	//�Զ��庯�����ַ�������
//	printf("%d", str_len(&arr));
//	return 0;
//}

//��n�Ľ׳ˡ������������)
//n! = 1*2*3*��*n
//n! = n*(n-1)*(n-2)*����*2*1

////1.0
//#include<stdio.h>
//
//long long int factorial(int n)		//21!�����
//{
//	int i = 0;
//	long long ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//�׳˺���
//	printf("%lld", factorial(n));
//	return 0;
//}

////2.0 �ݹ����
//#include<stdio.h>
//
//long long int factorial(int n)		//21!�����
//{
//	if (n > 1)						//�����ݹ�����
//		return n * factorial(n - 1);//ÿ�αƽ������ݹ�����
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//�׳˺���
//	printf("%lld", factorial(n));
//	return 0;
//}



//���n��쳲����������������������
//1 1 2 3 5 8 13 21 34 55 89 144
// F(n) = F(n-1) + F(n-2)

//1.0	�ݹ�	����ʵ��,�����ظ������,Ч�ʵ���		���϶���
//#include<stdio.h>
//int m = 0;
//int fib(int n)
//{
//	if (n == 5)		//ע�� == ,���� = ,������ѭ��,ջ���
//		m++;
//	if (n > 2)
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//��n��쳲���������
//	printf("%d\n", fib(n));
//	printf("%d\n", m);
//	return 0;
//}


//2.0		ѭ��		���¶���,���������,�������������õ��´�����
//#include<stdio.h>
//
//int fib(int n)
//{
//	int i = 0;
//	int ret = 1;
//	//�� ret_0 �� ret_1 ���洢 f(n - 1)  f(n - 2) ��ֵ,��Ϊ F(n) = F(n-1) + F(n-2)
//	int ret_0 = 1;		
//	int ret_1 = 1;		 
//	//1 1 2 3 5 8 13 21 34 55 89 144
//	for (i = 3; i <= n; i++)
//	{
//		if (i % 2 == 1)
//			ret_0 = ret;
//		if (i % 2 == 0)
//			ret_1 = ret;
//		ret = ret_0 + ret_1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//��n��쳲���������
//	printf("%d\n", fib(n));
//	return 0;
//}