#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////�ж����꺯��
//int is_leap_year(int x)
//{
//	//���ﲻ���� && ,|| ,��������߼��������,???   ������ & | ���ǰ�λ��,��λ����?
//	//������������,������������??
//	//1. & �� && ������
//	//��ͬ�㣺
//	//	���յõ���booleanֵ���һ�������ǡ�����and������˼
//
//	//	��ͬ�㣺
//	//	& �����߼������Ҳ��λ�������&& ֻ���߼������
//	//	& �����ж�·Ч���������false���ұ߻���ִ�У�&& ���ж�·Ч�������Ϊfalse���ұ���ִ��
//
//	//2. | �� || ������
//	//	��ͬ�㣺
//	//	���յõ���booleanֵ���һ�������ǡ�����or������˼
//
//	//	��ͬ�㣺
//	//	| �����߼������Ҳ��λ������� || ֻ���߼������
//	//	| �����ж�·Ч���������true���ұ߻���ִ�У� || ���ж�·Ч�������Ϊtrue���ұ���ִ��
//	//	3.����
//	//	�����г��� && �� || ���߼����㣬��Ϊ���ж�·Ч���������������������Ч�ʣ��Ż��˳���
//		
//	if (x % 4 == 0 & x % 100 != 0 | x % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int y = 1000;
//	int count = 0;
//	for (int y = 1000; y <= 2000; y++)
//	{
//		//�ж��Ƿ�Ϊ���꺯��
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}




////������ && || �ֿ�����,�Ǳ���������������?
//int is_leap_year(int x)
//{
//	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
//	return 1;
//	else
//	return 0;
//}
//
//int main()
//{
//	int y = 1000;
//	int count = 0;
//	for (int y = 1000; y <= 2000; y++)
//	{
//		//�ж��Ƿ�Ϊ���꺯��
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}


////������,�����Ż�
//int is_leap_year(int x)
//{
//	return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
//}
//
//int main()
//{
//	int y = 1000;
//	int count = 0;
//	for (int y = 1000; y <= 2000; y++)
//	{
//		//�ж��Ƿ�Ϊ���꺯��
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}


//������ϰ
////�ж�һ�����Ƿ�Ϊ����
//
//#include<math.h>
////�жϺ���
//int is_prime(int x)
//{
//	int i = 0;
//	float m = sqrt(x);
//	int n = 0;
//	//�о�: ���ܱ� 2 �� ���Լ���ƽ���� ����
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			break;
//	}
//	if (i > sqrt(x))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int a = 0;
//	printf("is prime?  YES/NO \n");
//	printf("please enter a number.\n");
//	while (1)
//	{
//		//scanf ������Ҫȡ��ַ & ,������ֵ������ѡ������ַ��
//		scanf("%d", &a);
//		if (is_prime(a))
//			printf("%d is prime.\n",a);
//		else
//			printf("not.\n");
//	}
//	return 0;
//}


//
////������ϰ
////��������Ķ��ֲ���
//
////���Һ���
////���鴫�ݵ��ǵ�ַ,��һ��Ԫ�صĵ�ַ
//// int search(int arr[], int x, int y) ��Ч�� int search(int* arr, int x, int y)
//int search(int* arr, int x, int y)
//{
//	int left = 0;
//	int right = y-1;
//	
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] < x)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > x)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] == x)
//			//���ز��ҵ����±�
//			return mid;
//	}
//			//���Ҳ���,���� -1
//		return -1;
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,15,17,19 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	printf("���ַ��������������±�.\n");
//	while (1)
//	{
//		scanf("%d", &a);
//		//��������ҵ�����,���ض�Ӧ�±�
//		//���ݲ���
//		int ret = search(arr, a, sz);
//		if (ret != -1)
//			printf("�ҵ���:   ret = %d\n", ret);
//		else
//			printf("�Ҳ���. error\n");
//	}
//
//	return 0;
//}



//������ϰ
// дһ��������ÿ����һ������������ͻὫ num ��ֵ����1��


//void print_()
//{
//	//��̬����
//	static int num = 0;
//	printf("hello.\n");
//	num++;
//}
//
//int main()
//{
//	//�������ô���
//	int a = 7;
//	for (int i = 0; i < 7; i++)
//	{
//		//���ú���
//		print_();
//	}
//	//��������, ��Ȼ num ������Ϊ static int ,�������ڱ䳤��,�������÷�Χû�иı�,���Ǻ����ֲ�.
//	// �޷������������
//	//printf("num = %d\n", num);
//	return 0;
//}

////������		Ҳ����ʹ��ȫ�ֱ���,�˴�ѡ����Ž�
//void print_()
//{
//	printf("hello.\n");
//}
//
//int main()
//{
//
//	
//	int a = 7;
//	//��¼�Ĵ���
//	int num = 0;
//	for (int i = 0; i < a; i++)
//	{
//		//���ú���
//		if (i % 2 == 0)
//		{
//			print_();
//			num++;
//		}
//
//	}
//	printf("num = %d\n", num);
//	return 0;
//}


////������		��ַ����,����ָ��ı亯�������
//void print_(int* pn)
//{
//	printf("hello.\n");
//	*pn = *pn + 1;
// //������ŵ����ȼ�. ����� *pn ++ , ��ô ++ ������ * ,���Ե�ַ��+1,Ȼ���ٽ�����
//}
//
//int main()
//{
//
//	
//	int a = 7;
//	//��¼�Ĵ���
//	int num = 0;
//	for (int i = 0; i < a; i++)
//	{
//		//���ú���
//		if (i % 2 == 0)
//		{
//			print_(&num);
//		}
//
//	}
//	printf("num = %d\n", num);
//	return 0;
//}




////������ϰ
////�ж�һ�����Ƿ�Ϊ����
////ʵ��һ���������ж�һ�����ǲ���������
////��������ʵ�ֵĺ�����ӡ100��200֮���������
//
//#include<math.h>
////�жϺ���
//int is_prime(int x)
//{
//	int i = 0;
//	float m = sqrt(x);	//sqrt ���������� double
//	int n = 0;
//	//�о�: ���ܱ� 2 �� ���Լ���ƽ���� ����
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			break;
//	}
//	if (i > sqrt(x))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int a = 0;
//	for(a = 100; a<= 200;a++)
//	{
//		if (is_prime(a))
//			printf("%d  ",a);
//	}
//	return 0;
//}



////ʵ�ֺ����ж�year�ǲ������ꡣ
//int is_leap_year(int x)
//{
//	return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
//}
//
//int main()
//{
//	int y = 0;
//	while(1)
//	{
//		scanf("%d", &y);
//		//�ж��Ƿ�Ϊ���꺯��
//		if (is_leap_year(y))
//			printf("%d-->YES\n", y);
//		else
//			printf("NO\n");
//	}
//	return 0;
//}



