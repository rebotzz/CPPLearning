#define _CRT_SECURE_NO_WARNINGS

//判断瑞年,调用函数
#include <stdio.h>
//判断瑞年函数,是 返回1 ;不是 返回0		返回类型 int 不能忘记	默认是int
int is_leap_year(int n)
{
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int y = 0;
	int count = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if (is_leap_year(y) == 1)
		{
			count++;
			printf("%d  ", y);
		}
	}
	printf("\ncount = %d", count);
	return 0;
}
