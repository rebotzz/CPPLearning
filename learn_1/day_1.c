# test_1
日常练习
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	//指针 就是 地址
//	int a = 15;
//	printf("%p\n", &a);   //%p打印地址
//	int* pa = &a;         //*存指针地址，存的类型为int      pa存储了变量a的地址，pa是指针变量
//	printf("%p\n",pa);
//	*pa = 16;              //解引用操作符，通过地址改变在地址中存储的数值
//	printf("%d\n",a);
//	printf("%d\n",sizeof(int*));
//
//	return 0;
//}

//
//int main()
//{
//	int arry[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i =0;i<10;i++)
//	{
//		printf("%d",arry[i]);
//	}
//
//	return 0;
//}

//typedef unsigned long long un_l_l;            //类型重定义
//int main()
//{
//	unsigned long long a = 10;
//	un_l_l b = 7;
//	printf("%d\n",sizeof(a));
//	printf("%d\n", sizeof(b));
//
//	return 0;
//}

//int main()
//{
//	extern num1;
//	int b = num1;
//	printf("%d",b);
//	return 0;
//}

//void qte()
//{
//	static int a = 1;         //static 改变了变量的生命周期，及存储变量的位置改变了
//	int b = 1;
//	printf("%d",a);
//	a++;
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		qte();
//		i++;
//	}
//	return 0;
//}

//extern max();
int main()
{
	int num3 = max(8,10);
	printf("%d",num3);
	return 0;
}


//#define phi 3.14
////#include <stdio.h>
//
//int main()
//{
//	printf("%0.3f",phi);
//	return 0;
//}
//
//#define dev(x,y) ((x)-(y))       //宏
//
//int main()
//{
//	int a = 10;
//	int b = 2;
//	int num2 = dev(a + 1, b * 2);
//	printf("%d",num2);
//	return 0;
//}


int num1 = 10;

int max(int a, int b)          //static 改变了函数或者全局变量的外部链接属性
{
	int z = a >= b ? a : b;
	return z;
}
