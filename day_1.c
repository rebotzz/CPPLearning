#define _CRT_SECURE_NO_WARNINGS

//const 修饰指针
//#include <stdio.h>
//#include <assert.h>
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	//const int* pa = &a;	//const在 * 左边 和 右边 分别修饰 *p 和 p
//	//int const* pb = &b;	//指向内容 和 指针变量存储值
//	//*pa = 1;
//	//*pb = 2;
//	//pa = &b;
//
//	//int* const pa = &a;
//	//int* const pb = &b;
//	//*pa = 3;
//	//pa = &b;
//
//	//const int a = 0;	//const 修饰后 常变量
//	//int const b = 1;
//	const int* const pa = &a;
//	int const* const pb = &b;
//	//pa = &b;
//	//*pa = b;
//	a = 10;
//	b = 20;
//
//	//assert(a != 10);//断言	值为假 触发assert
//	int** ppa = &pa;//二级指针
//	const int* const* const ppb = &pb;
//
//	return 0;
//}


//模拟 strlen
#include <stdio.h>
#include <assert.h>

//1.0
//size_t my_strlen(const char* str)//优化,长度不为负数	size_t  ->  unsigned int
//{
//	assert(str != NULL);//断言
//	//assert(str); //空指针 值为0 假
//	size_t count = 0;
//	//while (*str++ != '\0')//while(*str++)
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}

////2.0
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);//断言
//	char* start = str;
//	while (*str++)
//	{
//	}
//	return str - start - 1;//指针相减,所含元素个数
//}
//int main()
//{
//	char arr[] = "12345678";
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}


//模拟 strcpy
#include <stdio.h>
#include <assert.h>

//1.0
//void my_strcpy(char* dest, char* src)
//{
//	assert(src != NULL);//断言
//	assert(dest != NULL);
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}

////2.0
//char* my_strcpy(char* dest,const char* src)//consr 限定 *src不能改
//{
//	assert(src != NULL);//断言
//	assert(dest != NULL);
//	char* start = dest;
//	while (*dest++ = *src++)//'\0' ASCCI码值 为0
//	{
//		;
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[30] = "xxxxxxxxxxxxxxxxxxxxxxxx";
//	char arr2[] = "12345678hello";
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

//【题目名称】
//统计二进制中1的个数
//【题目内容】
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
#include <stdio.h>

//1.0
//int NumberOf1(int n)
//{
//    // write code here
//    int i = 0;
//    int count = 0;
//    for (i = 31; i >= 0; i--)
//    {
//        if (((n >> i) & 1))
//        {
//            count++;
//        }
//    }
//    return count;
//}

//2.0
//int NumberOf1(unsigned int n)
//{
//    // write code here
//    int i = 0;
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n /= 2; //除2 等价于 二进制右移一位
//    }
//    return count;
//}

//3.0
//int NumberOf1(int n)//二进制中 1 的个数
//{
//    // write code here
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n = n & (n - 1);//每次少一个 1
//    }
//    return count;
//}
//
//int main()
//{
//    int a = 0;
//    scanf("%d", &a);
//    int ret = NumberOf1(a);
//    printf("%d\n", ret);
//    return 0;
//}


//【题目名称】
//求两个数二进制中不同位的个数
//【题目内容】
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
#include <stdio.h>

//1.0
//size_t diff(int x, int y)//二进制不同位的个数
//{
//	int i = 0;
//	size_t count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((x >> i) & 1) != (((y >> i) & 1)))
//			count++;
//	}
//	return count;
//}

//2.0
//int NumberOf1(int n)
//{
//     write code here
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n = n & (n - 1);//每次少一个 1
//    }
//    return count;
//}
//size_t diff(int x, int y)
//{
//	size_t count = 0;
//	int n = x ^ y;
//	count = (unsigned int)NumberOf1(n);
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	size_t ret = diff(a, b);
//	printf("%d\n", ret);
//	return 0;
//}


////【题目名称】
////打印整数二进制的奇数位和偶数位
////【题目内容】
////获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 31; i >= 1; i -=2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	return 0;
//}


////判断一个数是否为 2 的几次方
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//二进制中只有一个1;而且这个 1 可以放在末尾 ,2^0 =1;不能全是0
//	int n = a;
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	if (count == 1)
//		printf("%d 是2的正整数次方\n",a);
//	return 0;
//}

////关于 栈 造成的死循环
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//这里在内存中,先创建arr[],随着下标增加,地址有低到高
//    int i = 0;                           //在vs2022版本,内存空了5个int*指针空间,然后创建了 i
//    for (i = 0; i <= 15; i++)            //当数组越界访问,到了第6次越界访问的地址,正好是i 的地址
//    {
//        arr[i] = 0;                      //i的值从15被修改为0;陷入死循环;系统无法报错
//        printf("hello bit\n");
//    }
//    return 0;
//}

//
////【题目名称】
////调整奇数偶数顺序
////【题目内容】
////调整数组使奇数全部都位于偶数前面。
////题目：
////输入一个整数数组，实现一个函数，
////来调整该数组中数字的顺序使得数组中所有的奇数 位于数组的前半部分，
////所有偶数 位于数组的后半部分。
#include <stdio.h>

//对奇偶部分 分别 按照大小排序
void sort_part(int* arr, int left, int right)
{
	int i = 0;
	int tmp = 0;
	for (i = left - 1; i > 0; i--)//奇数部分排序
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])//两两排序
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = right - 1; i > left; i--)//偶数部分排序
	{
		int j = left;
		for (j = left; j < i; j++)
		{
			if (arr[j] > arr[j + 1])//两两排序
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
////奇偶排序函数 1.0
//int sort_parity(int arr[], int sz)
//{
//	int i = 0;
//	int left = 0;//端点
//	int tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] % 2)//奇数
//		{
//			//将奇数位向前交换,当奇数位都在前面,那么后面只有偶数位了
//			tmp = arr[left];
//			arr[left] = arr[i];
//			arr[i] = tmp;
//			left++;
//		}
//	}
//	return left;//返回最后一个奇数序号的下一位,即第一个偶数序号
//}

////奇偶排序函数	2.0
//int sort_parity(int arr[], int sz)
//{
//	int left = 0;//端点
//	int right = sz - 1;
//	int tmp = 0;
//	//left 对应如果有偶数 与 right 如果对应的奇数交换
//	while (left < right)
//	{
//		while (((arr[left] % 2) == 1) && (left < right))//遇到偶数停止
//		{
//			left++;
//		}
//		while (((arr[right] % 2) == 0) && (left < right))//遇到奇数停止
//		{
//			right--;
//		}
//		if (left < right)//交换
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//	return left+1;//返回最后一个奇数序号的下一位,即第一个偶数序号
//}
//
//int main()
//{
//	int arr[41] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//初始化
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//	//arr[2] = 91;//验证奇数排序
//	//打印
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//排列奇偶顺序
//	int start_2 = sort_parity(arr,sz);//偶数位起始位置
//	//对奇偶部分 分别 按照大小排序
//	sort_part(arr, start_2, sz);
//	//打印
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}