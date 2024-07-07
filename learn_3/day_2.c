#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////判断闰年函数
//int is_leap_year(int x)
//{
//	//这里不能用 && ,|| ,这个不是逻辑运算符吗,???   单个的 & | 不是按位与,按位或吗?
//	//这是这样能行,不这样反而错??
//	//1. & 和 && 的区别
//	//相同点：
//	//	最终得到的boolean值结果一样，都是“并且and”的意思
//
//	//	不同点：
//	//	& 既是逻辑运算符也是位运算符；&& 只是逻辑运算符
//	//	& 不具有短路效果，即左边false，右边还会执行；&& 具有短路效果，左边为false，右边则不执行
//
//	//2. | 和 || 的区别
//	//	相同点：
//	//	最终得到的boolean值结果一样，都是“或者or”的意思
//
//	//	不同点：
//	//	| 既是逻辑运算符也是位运算符； || 只是逻辑运算符
//	//	| 不具有短路效果，即左边true，右边还会执行； || 具有短路效果，左边为true，右边则不执行
//	//	3.结论
//	//	开发中常用 && 和 || 做逻辑运算，因为具有短路效果，可以提升程序的运行效率，优化了程序。
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
//		//判断是否为闰年函数
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}




////这里用 && || 又可以了,是编译器出问题了吗?
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
//		//判断是否为闰年函数
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}


////方法二,代码优化
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
//		//判断是否为闰年函数
//		if (is_leap_year(y))
//		{
//			printf("%d  ", y);
//			count++;
//		}
//	}
//	printf("\ncount = %d", count);
//	return 0;
//}


//函数练习
////判断一个数是否为素数
//
//#include<math.h>
////判断函数
//int is_prime(int x)
//{
//	int i = 0;
//	float m = sqrt(x);
//	int n = 0;
//	//判据: 不能被 2 和 它自己的平方根 整除
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
//		//scanf 函数需要取地址 & ,将输入值存入所选变量地址中
//		scanf("%d", &a);
//		if (is_prime(a))
//			printf("%d is prime.\n",a);
//		else
//			printf("not.\n");
//	}
//	return 0;
//}


//
////函数练习
////有序数组的二分查找
//
////查找函数
////数组传递的是地址,第一个元素的地址
//// int search(int arr[], int x, int y) 等效于 int search(int* arr, int x, int y)
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
//			//返回查找到的下标
//			return mid;
//	}
//			//查找不到,返回 -1
//		return -1;
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,15,17,19 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	printf("二分法查找有序数组下标.\n");
//	while (1)
//	{
//		scanf("%d", &a);
//		//输入想查找的数字,返回对应下标
//		//传递参数
//		int ret = search(arr, a, sz);
//		if (ret != -1)
//			printf("找到了:   ret = %d\n", ret);
//		else
//			printf("找不到. error\n");
//	}
//
//	return 0;
//}



//函数练习
// 写一个函数，每调用一次这个函数，就会将 num 的值增加1。


//void print_()
//{
//	//静态变量
//	static int num = 0;
//	printf("hello.\n");
//	num++;
//}
//
//int main()
//{
//	//函数调用次数
//	int a = 7;
//	for (int i = 0; i < 7; i++)
//	{
//		//调用函数
//		print_();
//	}
//	//存在问题, 虽然 num 被定义为 static int ,生命周期变长了,但是作用范围没有改变,仍是函数局部.
//	// 无法被函数外调用
//	//printf("num = %d\n", num);
//	return 0;
//}

////方法二		也可以使用全局变量,此处选择更优解
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
//	//记录的次数
//	int num = 0;
//	for (int i = 0; i < a; i++)
//	{
//		//调用函数
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


////方法三		传址调用,利用指针改变函数外变量
//void print_(int* pn)
//{
//	printf("hello.\n");
//	*pn = *pn + 1;
// //运算符号的优先级. 如果是 *pn ++ , 那么 ++ 优先于 * ,所以地址先+1,然后再解引用
//}
//
//int main()
//{
//
//	
//	int a = 7;
//	//记录的次数
//	int num = 0;
//	for (int i = 0; i < a; i++)
//	{
//		//调用函数
//		if (i % 2 == 0)
//		{
//			print_(&num);
//		}
//
//	}
//	printf("num = %d\n", num);
//	return 0;
//}




////函数练习
////判断一个数是否为素数
////实现一个函数，判断一个数是不是素数。
////利用上面实现的函数打印100到200之间的素数。
//
//#include<math.h>
////判断函数
//int is_prime(int x)
//{
//	int i = 0;
//	float m = sqrt(x);	//sqrt 返回类型是 double
//	int n = 0;
//	//判据: 不能被 2 和 它自己的平方根 整除
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



////实现函数判断year是不是润年。
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
//		//判断是否为闰年函数
//		if (is_leap_year(y))
//			printf("%d-->YES\n", y);
//		else
//			printf("NO\n");
//	}
//	return 0;
//}



