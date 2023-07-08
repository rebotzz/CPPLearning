#define _CRT_SECURE_NO_WARNINGS


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
//
//	return 0;
//}



//描述
//KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“* ”组成的X形图案。
//输入描述：
//多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
//输出描述：
//针对每行输入，输出用“ * ”组成的X形图案。
#include <stdio.h>

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








//描述
//公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
//（注：本题有多组输入）
//输入描述：
//每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
//输出描述：
//每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
#include <stdio.h>

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
//    }
//    return 0;
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

//2.0
#include <string.h>
    int main()
    {
        int n = 0;
        scanf("%d", &n);
        //动态内存开辟
        int* p = (int*)malloc((n + 2) * sizeof(int));
        if (p == NULL)
        {
            perror("malloc");
            return 1;
        }
        int i = 0;
        //输入有序数组
        for (i = 0; i < n; i++)
        {
            scanf("%d", (p + i));
        }
        //插入值
        int a = 0;
        scanf("%d", &a);
        //排序
        for (i = 0; i < n; i++)
        {
            if (a < p[0])//首位
                break;
            if ((a >= p[i]) && (a <= p[i + 1]))//中间
                break;
        }
        //内存拷贝/移动
        if (i == 0)
        {
            memmove(p + 1, p , (n - i) * sizeof(int));
            p[0] = a;
        }
        else if (i < n)//避免向后移动 0 字节情况
        {
            memmove(p + i + 2, p + i + 1, (n - i) * sizeof(int));
            p[i + 1] = a;
        }
        else
        {
            p[n] = a;//末尾
        }


        //打印
        for (i = 0; i < n + 1; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");

        //free,NULL
        free(p);
        p = NULL;
        return 0;
    }

