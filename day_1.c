#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
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
=======

//自定义类型学习:结构体,枚举,联合体	1


//#define执行的是查找替换
//#define A_B 2 + 3
#include <stdio.h>

//int main()
//{
//	int c = 2 * A_B;//2*2 + 3 =7		2*(2 + 3 ) = 10
//	printf("%d\n", c);//输出结果为 7,说明#define只是单纯的替换,不做任何更改,比如加括号结合为一个整体
//	return 0;
//}
//
//#define INT_PTR int*//#define执行的是查找替换,不作为整体
//typedef int* int_ptr;//类型重定义,int* 为一个整体 被替换为 int_ptr
//
//int main()
//{
//	INT_PTR a, b;//等价于 ==> int* a,b; ==> int *a,b; ==>int *a;int *b; *会和其中一个变量结合,正确定义为: int *a,*b;
//	int_ptr c, d;//类型重定义,int* 为一个整体 被替换为 int_ptr,所以 c,d都是int*类型.
>>>>>>> w6/main
//
//	return 0;
//}


<<<<<<< HEAD
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
=======

//描述
//KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“* ”组成的X形图案。
//输入描述：
//多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
//输出描述：
//针对每行输入，输出用“ * ”组成的X形图案。
#include <stdio.h>

//1.0
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF)//多组数输入
//    {
//        int i = 0;
//        //上半
//        int up_line = a / 2 + a % 2;
//        for (i = 0; i < up_line; i++)
//        {
//            if (i < up_line - 1)
//            {
//                int j = 0;
//                for (j = 0; j < i; j++) {
//                    printf(" ");
//                }
//                printf("*");
//                if (a % 2 == 1)
//                {
//                    for (j = 2 * (up_line - i - 1) - 1; j > 0; j--) {
//                        printf(" ");
//                    }
//                }
//                else
//                {
//                    for (j = 2 * (up_line - i - 1); j > 0; j--) {
//                        printf(" ");
//                    }
//                }
//                printf("*\n");
//            }
//            else
//            {
//                int j = 0;
//                for (j = 0; j < i; j++)
//                {
//                    printf(" ");
//                }
//                if (a % 2 == 1)
//                {
//                    printf("*\n");
//                }
//                else
//                {
//                    printf("**\n");
//                    for (j = 0; j < i; j++)
//                    {
//                        printf(" ");
//                    }
//                    printf("**\n");
//                }
//            }
//        }
//
//        //下半
//        int down_line = a / 2;
//        int mark = 0;
//        for (i = 0; i < down_line; i++)
//        {
//            if ((a % 2 == 0) && (i == 0) && (mark == 0))
//            {
//                mark = 1;
//                continue;
//            }
//            int j = 0;
//            for (j = 0; j < down_line - i - 1; j++)
//            {
//                printf(" ");
//            }
//            printf("*");
//            for (j = 0; j < 2 * (i + 1) - 1 - mark; j++)
//            {
//                printf(" ");
//            }
//            printf("*\n");
//        }
//    }
//    return 0;
//}

////2.0		代码优化
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		//主对角,坐标(x,x);次对角线,坐标(x,n-1-x);每行有n个打印,总共有n行.
//		int x = 0;
//		for (x = 0; x < n; x++)
//		{
//			int y = 0;
//			for (y = 0; y < n; y++)
//			{
//				if (x == y)//主对角,坐标(x,x)
//					printf("*");
//				else if (y == n - 1 - x)//次对角线,坐标(x,n-1-x)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}






//描述
//公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
//（注：本题有多组输入）
//输入描述：
//每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
//输出描述：
//每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
#include <stdio.h>

//1.0	复杂度 O(N*N)
//int main() {
//    int s[7] = { 0 };
//    while (scanf("%d %d %d %d %d %d %d", &s[0], &s[1], &s[2], &s[3], &s[4], &s[5],
//        &s[6]) != EOF) {
//        int i = 0;
//        //排序
//        for (i = 0; i < 7 - 1; i++) {
//            int j = 0;
//            for (j = 0; j < 7 - 1 - i; j++) {
//                if (s[j] > s[j + 1]) {
//                    int tmp = s[j];
//                    s[j] = s[j + 1];
//                    s[j + 1] = tmp;
//                }
//            }
//
//        }
//        //去除
//        s[0] = 0;
//        s[6] = 0;
//        int sum = 0;
//        for (i = 0; i < 7; i++) {
//            sum += s[i];
//        }
//        float ave = sum / 5.0;
//        printf("%.2f\n", ave);
//    }
//
//
//    return 0;
//}

////2.0	代码优化	复杂度0(n)
//int main()
//{
//	int score = 0;
//	int sum = 0;
//	int min = 100;
//	int max = 0;
//	//输入7个数
//	int i = 0;
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &score);//求和
//		sum += score;
//		if (score < min)//取最大值
//			min = score;
//		if (score > max)//取最小值
//			max = score;
//	}
//	sum = sum - min - max;
//	printf("%.2f\n", sum / 5.0);
//
//	return 0;
//}



//描述
//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
//输入：
//2008 2
//输出：
//29
#include <stdio.h>

//1.0
//int main()
//{
//    int y = 0, m = 0;
//    while (scanf("%d %d", &y, &m) != EOF)
//    {
//        //是否闰年
//        int is_y = 0;
//        if ((y % 4 == 0) && (y % 100 != 0) || (y % 1000 == 0))
//        {
//            is_y = 1;
//        }
//        //月份,奇偶
//        int day = 0;
//        if (0 < m && m <= 7)
//        {
//            day = 30 + m % 2;
//        }
//        if (7 < m && m <= 12)
//        {
//            day = 31 - m % 2;
//        }
//        //瑞年2月
//        if (is_y == 1 && m == 2)
//        {
//            day = 29;
//        }
//        else if (m == 2)
//        {
//            day = 28;
//        }
//        printf("%d\n", day);
//
>>>>>>> w6/main
//    }
//    return 0;
//}

<<<<<<< HEAD
//
////【题目名称】
////调整奇数偶数顺序
////【题目内容】
////调整数组使奇数全部都位于偶数前面。
////题目：
////输入一个整数数组，实现一个函数，
////来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
////所有偶数位于数组的后半部分。
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

////奇偶排序函数 1.5
//int sort_parity(int arr[], int sz)
//{
//	int i = 0;
//	int left = 0;//端点
//	int tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		
//		if ((arr[i] % 2))//奇数 , && (left < sz)防止栈溢出可以不加,外层的i < sz限制了内层left < sz
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
//
////奇偶排序函数	2.0
//int sort_parity(int arr[], int sz)
//{
//	int left = 0;//端点
//	int right = sz - 1;
//	int tmp = 0;
//	//left 对应如果有偶数 与 right 如果对应的奇数交换
//	while (left < right)
//	{
//		while (((arr[left] % 2) == 1) && (left < right))//遇到偶数停止, (left < right)为了防止数组越界访问
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
=======
////2.0
//int main()
//{
//	//非润年,月份天数固定
//	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	//输入年,月
//	int y = 0;
//	int m = 0;
//	while (scanf("%d %d", &y, &m) != EOF)
//	{
//		//判断瑞年,2月
//		if (((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) && m == 2)
//			days[2] = 29;
//		printf("%d\n", days[m]);
//		days[2] = 28;//初始化
//	}
//	return 0;
//}







//描述
//有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列仍然是升序。
//输入描述：
//第一行输入一个整数N(0≤N≤50)。
//第二行输入N个升序排列的整数，输入用空格分隔的N个整数。
//第三行输入想要进行插入的一个整数。
//输出描述：
//输出为一行，N + 1个有序排列的整数。
//输入：
//5
//1 6 9 22 30
//8
//输出：
//1 6 8 9 22 30
#include <stdio.h>
#include <stdlib.h>

//1.0
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    //动态内存开辟
//    int* p = (int*)malloc((n + 1) * sizeof(int));
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", (p + i));
//    }
//    int a = 0;
//    scanf("%d", (p + n));
//    //排序
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n - i; j++)
//        {
//            if (*(p + j) > *(p + j + 1))
//            {
//                int tmp = p[j];
//                p[j] = p[j + 1];
//                p[j + 1] = tmp;
//            }
//        }
//    }
//    //打印
//    for (i = 0; i < n + 1; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    printf("\n");
//
//    //free,NULL
//    free(p);
//    p = NULL;
//    return 0;
//}

////2.0
//#include <string.h>
//    int main()
//    {
//        int n = 0;
//        scanf("%d", &n);
//        //动态内存开辟
//        int* p = (int*)malloc((n + 2) * sizeof(int));
//        if (p == NULL)
//        {
//            perror("malloc");
//            return 1;
//        }
//        int i = 0;
//        //输入有序数组
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", (p + i));
//        }
//        //插入值
//        int a = 0;
//        scanf("%d", &a);
//        //排序
//        for (i = 0; i < n; i++)
//        {
//            if (a < p[0])//首位
//                break;
//            if ((a >= p[i]) && (a <= p[i + 1]))//中间
//                break;
//        }
//        //内存拷贝/移动
//        if (i == 0)
//        {
//            memmove(p + 1, p , (n - i) * sizeof(int));
//            p[0] = a;
//        }
//        else if (i < n)//避免向后移动 0 字节情况
//        {
//            memmove(p + i + 2, p + i + 1, (n - i) * sizeof(int));
//            p[i + 1] = a;
//        }
//        else
//        {
//            p[n] = a;//末尾
//        }
//
//
//        //打印
//        for (i = 0; i < n + 1; i++)
//        {
//            printf("%d ", p[i]);
//        }
//        printf("\n");
//
//        //free,NULL
//        free(p);
//        p = NULL;
//        return 0;
//    }

////3.0
//int main()
//{
//	//N+1个整数,N<= 50
//	int arr[51] = { 0 };
//	//输入n个升序数字
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//输入第n+1个数
//	int a = 0;
//	scanf("%d", &a);
//	//排序,从后向前,arr[i]>a,则arr[i]向后挪动
//	for (i = n - 1; i >= 0; i--)//i = 0,arr[0]也要比较
//	{
//		//n在中间,或者n在末尾
//		if (arr[i] > a)
//			arr[i + 1] = arr[i];
//		else
//			break;
//
//		//n在首位,i = -1, arr[i+1] ==> arr[0] ==>首位
//	}
//	arr[i + 1] = a;
//	//打印
//	for (i = 0; i < n + 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
>>>>>>> w6/main
//	return 0;
//}