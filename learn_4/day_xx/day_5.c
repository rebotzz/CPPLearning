#define _CRT_SECURE_NO_WARNINGS

//【题目名称】
//冒泡排序
//【题目内容】
//实现一个对整形数组的冒泡排序

//两个数比较大小,交换
//大事化小
//大的向后交换,每一次都会把一个相对大的放在最后面,所以每一次少比较最后一个数
//两层循环,
//#include <stdio.h>
//
////排序函数
//void order_arr(int arr[],int num)	//int* arr
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < num - i - 1; j++)	//num - i - 1 当心数组访问越界
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
//	//排序函数
//	order_arr(arr,num);	//&arr[0]
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}


//【题目名称】
//数组操作
//【题目内容】
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。

//1.0 int型 数组

//#include <stdio.h>
//
////初始化函数
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
////打印数组的每个元素
//void print(int arr[], int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

////函数完成数组元素的逆置  方法一
//void reverse(int arr[],int num)
//{
//	//两端
//	int left = 0;
//	int right = num - 1;
//	//判断条件
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}

////函数完成数组元素的逆置  方法二
//void reverse(int arr[], int num)
//{
//	//两端
//	int left = 0;
//	int right = num - 1;
//	while (arr[right] == '\0')
//	{
//		right--;
//	}
//	//判断条件
//	if (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = '\0';
//		reverse(arr + 1,num-1);//num-1 不然数组越界访问
//		arr[right] = tmp;
//
//	}
//}
//
//int main()
//{
//	int arr[11] = {0,1};//不完全初始化
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	//初始化函数 0
//	init(arr,num,0);
//	//打印数组的每个元素
//	print(arr, num);
//	//初始化函数 1
//	init(arr, num, 1);
//	print(arr, num);
//
//	//数组元素的逆置
//	reverse(&arr,num);
//	print(arr, num);
//
//	return 0;
//}

//2.0 char型 数组

//#include <stdio.h>
//
////初始化函数
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
////打印数组的每个元素
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
////函数完成数组元素的逆置  
//void reverse(char arr[], int num)
//{
//	//两端
//	int left = 0;
//	int right = num - 1;
//	while (arr[right] == '\0')
//	{
//		right--;
//	}
//	//判断条件
//	if (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = '\0';
//		reverse(arr + 1, num - 1);//num-1 不然数组越界访问
//		arr[right] = tmp;
//
//	}
//}
//
//int main()
//{
//	char arr[9] = "01";//不完全初始化
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	//初始化函数 0
//	init(arr, num, 0);
//	//打印数组的每个元素
//	print(arr, num);
//	//初始化函数 1
//	init(arr, num, 1);
//	print(arr, num);
//
//	//数组元素的逆置
//	reverse(&arr, num);
//	print(arr, num);
//
//	return 0;
//}



//【题目名称】
//交换数组
//【题目内容】
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//
////1.0 字符型数组
#include <stdio.h>
#include <string.h>

//交换内容 方法一
//void swap(char arr1[],char arr2[])
//{
//	char tmp[50] = { 0 };//有局限
//	strcpy(tmp, arr1);
//	strcpy(arr1, arr2);
//	strcpy(arr2, tmp);
//}

////方法二
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
//	//交换内容
//	swap(&arr1, &arr2,sz);
//	printf("arr1:%s\n", arr1);
//	printf("arr2:%s\n", arr2);
//
//	return 0;
//}


////2.0 非字符型数组
//#include <stdio.h>
//#include <string.h>
//
////交换内容
//void swap(int arr1[], int arr2[],int num)
//{
//	//char tmp[50] = { 0 };//不需要,有局限
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
////打印
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
//	//交换内容
//	swap(&arr1, &arr2,num);
//	print(arr1,num);
//	print(arr2,num);
//
//	return 0;
//}