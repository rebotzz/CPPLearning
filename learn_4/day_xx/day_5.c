#define _CRT_SECURE_NO_WARNINGS

//����Ŀ���ơ�
//ð������
//����Ŀ���ݡ�
//ʵ��һ�������������ð������

//�������Ƚϴ�С,����
//���»�С
//�����󽻻�,ÿһ�ζ����һ����Դ�ķ��������,����ÿһ���ٱȽ����һ����
//����ѭ��,
//#include <stdio.h>
//
////������
//void order_arr(int arr[],int num)	//int* arr
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < num - i - 1; j++)	//num - i - 1 �����������Խ��
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 8,1,9,7,3,9,4,5,7,3,6,5,2 };
//	int num = sizeof arr / sizeof(arr[0]);
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//������
//	order_arr(arr,num);	//&arr[0]
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//����Ŀ���ơ�
//�������
//����Ŀ���ݡ�
//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��

//1.0 int�� ����

//#include <stdio.h>
//
////��ʼ������
//void init(int * arr,int num,int x)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		if (x == 0)
//		{
//			*(arr) = 0;
//			arr++;
//		}
//		if (x == 1)
//		{
//			arr[i] = i;
//		}
//		//*(arr+i) = 0;
//		//arr[i] = 0;
//	}
//}
//
////��ӡ�����ÿ��Ԫ��
//void print(int arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

////�����������Ԫ�ص�����  ����һ
//void reverse(int arr[],int num)
//{
//	//����
//	int left = 0;
//	int right = num - 1;
//	//�ж�����
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}

////�����������Ԫ�ص�����  ������
//void reverse(int arr[], int num)
//{
//	//����
//	int left = 0;
//	int right = num - 1;
//	while (arr[right] == '\0')
//	{
//		right--;
//	}
//	//�ж�����
//	if (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = '\0';
//		reverse(arr + 1,num-1);//num-1 ��Ȼ����Խ�����
//		arr[right] = tmp;
//
//	}
//}
//
//int main()
//{
//	int arr[11] = {0,1};//����ȫ��ʼ��
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	//��ʼ������ 0
//	init(arr,num,0);
//	//��ӡ�����ÿ��Ԫ��
//	print(arr, num);
//	//��ʼ������ 1
//	init(arr, num, 1);
//	print(arr, num);
//
//	//����Ԫ�ص�����
//	reverse(&arr,num);
//	print(arr, num);
//
//	return 0;
//}

//2.0 char�� ����

//#include <stdio.h>
//
////��ʼ������
//void init(char* arr, int num, int x)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		if (x == 0)
//		{
//			*(arr) = 0 + '0';
//			arr++;
//		}
//		if (x == 1)
//		{
//			arr[i] = i + '0';
//		}
//		//*(arr+i) = 0;
//		//arr[i] = 0;
//	}
//}
//
////��ӡ�����ÿ��Ԫ��
//void print(char arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//}
//
//
////�����������Ԫ�ص�����  
//void reverse(char arr[], int num)
//{
//	//����
//	int left = 0;
//	int right = num - 1;
//	while (arr[right] == '\0')
//	{
//		right--;
//	}
//	//�ж�����
//	if (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = '\0';
//		reverse(arr + 1, num - 1);//num-1 ��Ȼ����Խ�����
//		arr[right] = tmp;
//
//	}
//}
//
//int main()
//{
//	char arr[9] = "01";//����ȫ��ʼ��
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	//��ʼ������ 0
//	init(arr, num, 0);
//	//��ӡ�����ÿ��Ԫ��
//	print(arr, num);
//	//��ʼ������ 1
//	init(arr, num, 1);
//	print(arr, num);
//
//	//����Ԫ�ص�����
//	reverse(&arr, num);
//	print(arr, num);
//
//	return 0;
//}



//����Ŀ���ơ�
//��������
//����Ŀ���ݡ�
//������A�е����ݺ�����B�е����ݽ��н�����������һ����
//
////1.0 �ַ�������
#include <stdio.h>
#include <string.h>

//�������� ����һ
//void swap(char arr1[],char arr2[])
//{
//	char tmp[50] = { 0 };//�о���
//	strcpy(tmp, arr1);
//	strcpy(arr1, arr2);
//	strcpy(arr2, tmp);
//}

////������
//void swap(char arr1[], char arr2[],int sz)
//{
//	char tmp = 0 ;
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "gfdecba";
//	int sz = strlen(arr1);
//	printf("arr1:%s\n", arr1);
//	printf("arr2:%s\n", arr2);
//	//��������
//	swap(&arr1, &arr2,sz);
//	printf("arr1:%s\n", arr1);
//	printf("arr2:%s\n", arr2);
//
//	return 0;
//}


////2.0 ���ַ�������
//#include <stdio.h>
//#include <string.h>
//
////��������
//void swap(int arr1[], int arr2[],int num)
//{
//	//char tmp[50] = { 0 };//����Ҫ,�о���
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
////��ӡ
//void print(int arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = {6,7,8,9,10000};
//	int num = sizeof(arr1) / sizeof(arr1[0]);
//	print(arr1,num);
//	print(arr2,num);
//	//��������
//	swap(&arr1, &arr2,num);
//	print(arr1,num);
//	print(arr2,num);
//
//	return 0;
//}