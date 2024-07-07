#define _CRT_SECURE_NO_WARNINGS

////函数练习
////交换两个数
//
//#include<stdio.h>
//
//void swap(int* pa, int* pb)			//函数形式参数不能用表达式, 赋值符号 = 
//{
//	int z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	printf(" 交换前: a = %d; b = %d\n", a, b);
//	//交换函数
//	swap(&a, &b);
//	//交换后
//	printf("交换后: a = %d; b = %d\n",a, b);
//
//	return 0;
//}


////max 函数
//#include<stdio.h>
//
//int max(int x, int y)
//{
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//	return z;
//}
//
//int main()
//{
//	int a = 150;
//	int b = 20;
//	//求max
//	int c = max(a, b);
//	printf("%d", c);
//	return 0;
//}