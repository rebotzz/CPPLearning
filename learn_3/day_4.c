#define _CRT_SECURE_NO_WARNINGS

//递归问题求解

//1.汉诺塔问题
//问题分析:3个盘子可以看作 > 2个盘子 + 3号 
//2个盘子先挪到一个柱子上,第一次排序,改变 3号 的位置,重复 前2个盘子的排序,这次放置于 3号 .
//如果是 n 个盘子,依次简化 n-1 > n - 2 .... > 2 > 1
//然后逆转,实现目标.
//递归思路:大问题化为小问题

//#include<stdio.h>
//
////求汉诺塔步数函数
//int res_num(int x)
//{
//	if (x == 1)
//		return 1;
//	if (x == 2)
//		return 3;
//	if (x > 2)
//		return  1 + 2 * res_num(x - 1);
//}
//
//int main()
//{
//	int a = 3;
//	scanf("%d", &a);//输入盘子层数
//	//求汉诺塔步数函数
//	printf("%d\n", res_num(a));
//	return 0;
//}


//2.青蛙跳台阶问题
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
// n > n-1 > n-2 >.... 2 > 1 
// n级,第一次两种情况:1 or 2,所以结果为 "n-1种"+"n-2种"
//即: res_n(x) = res_n(x - 1) + res_n(x - 2);
//缺点:至上而下,求解重复,效率底下

//#include<stdio.h>
//
////求解跳法种类数量
//int res_n(int x)
//{
//	if (x == 1)
//		return 1;
//	if (x == 2)
//		return 2;
//	////假如最后一级可以用 1级跳 和 2级跳 .不过从结果来说,无论最后怎么跳,都可以归类为 1级跳
//	//if (x == 1)
//	//	return 2;
//	//if (x == 2)
//		//return 3;
//	if (x > 2)
//		return res_n(x - 1) + res_n(x - 2);
//}
//
//int main()
//{
//	int n = 1;
//	//输入 n 级台阶
//	scanf("%d", &n);
//	//打印结果,跳法种类数量
//	printf("%d\n", res_n(n));
//	return 0;
//}

////扩展:如果一次还能跳3个呢
//#include<stdio.h>
//
////求解跳法种类数量
//int res_n(int x)
//{
//	if (x == 1)
//		return 1;
//	if (x == 2)
//		return 2;
//	if (x == 3)
//		return 4;
//	if (x > 3)
//		return res_n(x - 1) + res_n(x - 2) + res_n(x - 3);
//}
//
//int main()
//{
//	int n = 1;
//	//输入 n 级台阶
//	scanf("%d", &n);
//	//打印结果,跳法种类数量
//	printf("%d\n", res_n(n));
//	return 0;
//}