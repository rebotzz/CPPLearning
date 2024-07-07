#define _CRT_SECURE_NO_WARNINGS



//【题目名称】
//求两个数二进制中不同位的个数
//【题目内容】
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7

//#include <stdio.h>
//
////判断c的二进制中有几个 1
//int count(int x)
//{
//	int num = 0;
//	//类比于10进制求位数
//	while (x > 0)
//	{
//		if (x % 2 == 1)
//			num++;
//		x = x >> 1;
//		//等价于  (类比于10进制)
//		//x = x / 2;
//	}
//	return num;
//}
//
// //方法二
////int calc_diff_bit(int m, int n)
////{
////	int tmp = m ^ n;
////	int count = 0;
////	while (tmp)
////	{
////		tmp = tmp & (tmp - 1);
////		count++;
////	}
////	return count;
////}
// 
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;//按位异或
//	//判断c的二进制中有几个 1
//	printf("%d\n", count(c));
//	//int m = -1;
//	//printf("%d", m >> 1);//执行算数右移,高位补符号位 1
//	return 0;
//}


//【题目名称】
//打印整数二进制的奇数位和偶数位
//【题目内容】
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//1.0 方法一
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	
//	if (set == 0)//偶数
//	{
//		static int times = sizeof(int) * 8;//static 修饰,生命周期改变,作用域不变
//		if (times == sizeof(int) * 8)
//		{
//			x = x >> 1;
//			times--;
//			printf("\n偶数位:");
//		}	
//		while (times > 0)
//		{
//			my_print(x >> 2, (times -= 2,0));
//			printf("%d ", x % 2);
//		}
//	}
//
//	if (set == 1)//奇数
//	{
//		static int times = sizeof(int) * 8;//static 修饰,生命周期改变,作用域不变
//		if (times == sizeof(int) * 8)
//		{
//			printf("\n奇数位:");
//		}
//		while (times > 0)
//		{
//			my_print(x >> 2, (times -= 2,1));
//			printf("%d ", x % 2);
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//分别打印  偶数位和奇数位
//	my_print(a, 0);//偶数位
//	my_print(a, 1);//奇数位
//	return 0;
//}

//2.0 代码优化
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	int i = 32;
//	if (set == 0)//偶数
//	{
//		x >>= 1;
//		for (i = 31; i > 0; i = i - 2)
//		{
//			printf("%d ", x & 1);
//			x = x >> 2;
//		}
//	}
//
//	if (set == 1)//奇数
//	{
//		for (i = 32; i > 0; i -= 2)
//		{
//			printf("%d ", x & 1);
//			x = x >> 2;
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//分别打印  偶数位和奇数位
//	my_print(a, 0);//偶数位
//	my_print(a, 1);//奇数位
//	return 0;
//}

//3.0 代码优化
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	int i = 32;
//	if (set == 0)//偶数
//	{
//		for (i = 31; i > 0; i = i - 2)
//		{
//			printf("%d ",(x>>i) & 1);
//		}
//	}
//
//	if (set == 1)//奇数
//	{
//		for (i = 30; i >= 0; i -= 2)
//		{
//			printf("%d ",( x>>i ) & 1);
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//分别打印  偶数位和奇数位
//	my_print(a, 0);//偶数位
//	my_print(a, 1);//奇数位
//	return 0;
//}


//【题目名称】
//统计二进制中1的个数
//【题目内容】
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1

//#include <stdio.h>
//
////二进制中1个数函数
//int count(int x)
//{
//	int i = 31;
//	int sum = 0;
//	for (i = 31; i >= 0; i--)
//	{
//		if ((x >> i) & 1)
//		{
//			sum++;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//二进制中1个数函数
//	printf("%d \n",count(a));
//	return 0;
//}


//【题目名称】
//交换两个变量（不创建临时变量）
//【题目内容】
//不允许创建临时变量，交换两个整数的内容

//#include <stdio.h>
//
//int main()
//{
//	int a = 4;
//	int b = 5;
//	printf("%d %d \n", a, b);
//	a = a ^ b;
//	b = a ^ b;  // <==>  (a^b)^b <==>  a^(b^b)  <==>  a ^ 0  -> a
//	a = a ^ b;  // <==>  (a^b)^a <==> a^a^b  <==>  b
//	printf("%d %d \n", a, b);
//	return 0;
//}

//运算中的  ->  整形提升 和 类型转换
//#include <stdio.h>
//int i;//全局变量不赋值,默认为 0
//int main()
//{
//    i--;
//    //unsigned int b = i;   等价于 if(b > sizeof(i))
//    if (i > sizeof(i))//sizeof(i) 返回值为 unsigned int ,关系表达式要运算,就得把左端 i 类型强制转化 -> unsigned int 
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}


//【题目名称】
//计算求和
//【题目内容】
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//1.0
//#include <stdio.h>
//#include <math.h>
//
//int Sn(int x,int n)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		for (int j = i; j >= 0; j--)
//		{
//			//tmp = tmp + x * (10 ^ j);//error: 这不是MATLAB, ^ 不是求幂函数,而是 按位异或
//			tmp = tmp + x * pow(10, j);//用 math.h 库中的幂函数求 10^j 
//
//		}
//		sum = sum + tmp;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a,&n);
//	//求和函数
//	printf("%d\n",Sn(a,n));
//	return 0;
//}

////2.0   代码优化
//#include <stdio.h>
//
//int Sn(int x, int n)
//{
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//	for (i = 0; i < n; i++)
//	{
//		tmp = x + tmp*10;
//		sum = sum + tmp;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//求和函数
//	printf("%d\n", Sn(a, n));
//	return 0;
//}

////3.0	代码优化
//#include <stdio.h>
//
//int Sn(int x, int n)
//{
//	int sum = 0;
//	int tmp = 0;
//	while(n--)
//	{
//		tmp = x + tmp * 10;
//		sum = sum + tmp;
//	}
//	return sum ;
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//求和函数
//	printf("%d\n", Sn(a, n));
//	return 0;
//	return 0;
//}

////3.0	递归实现
//#include <stdio.h>
//#include <math.h>
//
//int Sn(int x, int n)
//{
//	int tmp = 0;
//	int i = n;
//	if (n == 1)
//		return x;
//	while (i--)
//	{
//		tmp += x * pow(10, i);
//	}
//	return tmp + Sn(x, n - 1);
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//求和函数
//	printf("%d\n", Sn(a, n));
//	return 0;
//	return 0;
//}


//【题目名称】
//打印水仙花数
//【题目内容】
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//1.0
//#include <stdio.h>
//#include <math.h>
//
////i 的次方和
//int sum_pow(int x,int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	int n = 1;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//求位数 n
//		for (int j = 0; j <= 5; j++)
//		{
//			if ((i >= pow(10, j)) && (i < pow(10,j+1)))//0^0 = 1 10^0 = 1
//			{
//				n = j + 1;
//				break;
//			}
//			if (i == 0)
//				break;
//		}
//
//		//i 的次方和
//		if (sum_pow(i, n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}

////2.0  代码优化
//#include <stdio.h>
//#include <math.h>
//
////i 的次方和
//int sum_pow(int x,int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
////求位数 n
//int nit(int x)
//{
//	if (x < 10)
//	{
//		return 1;
//	}
//	return 1 + nit(x / 10);
//}
//
//int main()
//{
//	int i = 0;
//	int n = 1;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//求位数 n
//		n = nit(i);
//
//		//i 的次方和
//		if (sum_pow(i,n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}


//3.0  代码优化
//#include <stdio.h>
//#include <math.h>
//
////i 的次方和
//int sum_pow(int x, int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//求位数 n
//		int n = 1;
//		tmp = i;
//		while (tmp / 10)	//一种不错的求位数的方法
//		{
//			n++;
//			tmp /= 10;
//		}
//
//		//i 的次方和
//		if (sum_pow(i, n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}


//【题目名称】
//使用指针打印数组内容
//【题目内容】
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。

//#include <stdio.h>
////打印数组
//void print(int * p,int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,100,7,8,9,10 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);//int * ptr = arr ; *ptr
//	int sz = sizeof(arr) / sizeof(*arr);
//	//打印数组
//	print(&arr[0],sz);
//	return 0;
//}