#define _CRT_SECURE_NO_WARNINGS

//动态内存分配学习













//作业

//模拟实现 atoi()
//int atoi(const char *str)
//C 标准库 - <stdlib.h>
//C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）
//atoi的规则是：跳过不可见字符，碰到负号或者数字开始转换，转换到非数字字符为止。

//使用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//int main()
//{
//	int val;
//	char str[20];
//
//	strcpy(str, "98993489");
//	val = atoi(str);
//	printf("字符串值 = %s, 整型值 = %d\n", str, val);
//
//	strcpy(str, "a48runoob.com");
//	val = atoi(str);
//	printf("字符串值 = %s, 整型值 = %d\n", str, val);
//
//	return(0);
//}

////模拟实现1.0	功能不完善
//int my_atoi(const char* str)
//{
//	assert(str != NULL);
//	int ret = 0;
//	char* p = str;
//	while ((*p >= '0') && (*p <= '9'))
//	{
//		ret = ret * 10 + *p - '0';
//		p++;
//	}
//	if (p > str)
//		return ret;
//	else
//		return 0;
//}

////模拟实现2.0
//int my_atoi(const char* str)
//{
//	assert(str != NULL);
//	long long int ret = 0;
//	int flag = 1;
//	char* p = (char*)str;
//	//跳过不可见字符 ' ' '\t' '\n' '\v'  '\f'  '\r''
//	while (isspace(*p))
//	{
//		p++;
//	}
//	//跳过正负号
//	while (*p == '+' || *p == '-')
//	{
//		if (*p == '+')
//			flag = 1;
//		else
//			flag = -1;
//		p++;
//	}
//	str = p;//记录数字可能的起始位置
//	while (isdigit(*p))//如果是数字
//	{
//		ret = ret * 10 + *p - '0';
//		//判断是否超过最大存储范围
//		if ((ret < INT_MIN) || (ret > INT_MAX))//算数类型转换
//		{
//			return 0;
//		}
//		p++;
//	}
//	ret = flag * ret;
//	if (p > str)
//		return (int)ret;
//	else
//		return 0;
//}
//
//int main()
//{
//	char str[50] = { 0 };
//	strcpy(str, "\t\f\v\r+-12345678AAA");
//	//int a = atoi(str);
//	int a = my_atoi(str);
//
//	printf("原字符串:%s\t对应整数值:%d\n", str, a);
//
//	return 0;
//}



//【题目名称】
//找单身狗
//【题目内容】
//一个数组中只有 两个数字 是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
#include <stdio.h>
#include <string.h>

//void check_solo(int arr[],int sz)
//{
//	//排序
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	//对两个相邻的数比较
//	int n = 0;//计数器,只有两个单身狗
//	for (i = 0; i < sz - 1; )
//	{
//
//		if (arr[i] != arr[i + 1])
//		{
//
//			arr[n] = arr[i];
//			n++;
//			if (n == 2)
//			{
//				break;
//			}
//			if (i == sz - 2 && n == 1)//防止越界,单身数在最后两位情况, AABBCCDDEF
//			{
//				arr[n] = arr[i + 1];
//				return;
//			}
//			//对应三种不同情况
//			if (arr[i + 1] != arr[i + 2])//ABCCEE ==> BCCEE
//			{
//				i++;
//			}
//			else						 //ABBCCEDD ==> CCEDD
//			{
//				i += 3;
//			}
//		}
//		else				//跳过前面相同的数,如AABBCCDEE ==> DEE
//			i += 2;
//
//	}
//
//}
//
////参考代码思路:
////找出一个只出现过一次的数字的问题处理方法就是找一个数字把里面所有的数字都异或一遍，
////利用异或两次等于没异或的特点来处理。那么如果有两个数字都只出现了一次，
////那么如此得到的应该是两个数异或的结果。首先这个结果肯定不是0（要不然就全都配对了），
////所以里面一定至少一位是一。找出值为1的一位，以这一位的值将结果分为两组。例如1 2 3 4 1 2，
////异或完的结果应该是3 ^ 4得到的111，那么随便找一位就行了。例如找最低位，那么这一位是1的有1 3 1，是0的有2 4 2，
////由于是利用异或结果为1的某一位分的组，所以两个待查询数字一定分别在两组中。
////所以再找两个变量，分别异或两组数，即可找到这两个数。
//
////2.0	参考后自己写
//void check_solo2(int arr[], int sz, int* pa, int* pb)
//{
//	//假设两个单身数为 a b
//	//所有数相异或	==> 相同数异或抵消,得到两个单身数异或结果 sum = a^b
//	int sum = arr[0];
//	int i = 0;
//	for (i = 1; i < sz; i++)
//	{
//		sum ^= arr[i];
//	}
//		//找到a和b二进制不同位置,int ==> 32 bit
//		int pos = 0;
//		for (i = 0; i < 32; i++)
//		{
//			if (sum & (1 << i))
//			{
//				pos = i;
//				break;
//			}
//		}
//	//假设在二进制pos位置上,a是0,b是1;那么,在这个位置上分别为0 , 1的数也是两两一组,同样可以利用相同数异或抵消
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] & (1 << pos))//pos ==> 1
//		{
//			*pb ^= arr[i];
//		}
//		else					//pos ==> 0
//		{
//			*pa ^= arr[i];
//		}
//	}
//}
//
//int main()
//{
//	//注意:
//	//之前几次失败原因 ==> arr[]指定了大小,不完全初始化位置可能有奇数或者偶数对的 0,干扰异或结果
//	//或者干扰排序结果,比如前面有奇数个0
//	int arr[] = { 1,5,6,5,1,6,2,3 };////1 3 3 5 5 7 7 8	{1,3,5,5,3,7,8,7}  {1,2,3,3,2,1,7,8}
//	int i = 0;
//	int a = 0;
//	int b = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* tmp = (int*)malloc(sizeof(arr));
//	if (tmp == NULL)
//	{
//		return 1;
//	}
//
//	memcpy(tmp, arr, sizeof(arr));
//	//check_solo(tmp, sz);
//	//printf("%d %d\n", tmp[0], tmp[1]);
//
//	check_solo2(tmp, sz, &a, &b);
//	printf("%d %d\n", a, b);
//
//	free(tmp);
//	tmp = NULL;
//	return 0;
//}



////判断一个数二进制位有多少个 1
//// n = n&(n-1);
//#include <stdio.h>
//int main()
//{
//	int n = 0x00001111;
//	int count = 0;
//	while (n)
//	{
//		//例如，让7（111）&6（110）得到的是6（110），接着6（110）&5（101）得到4（100），
//		//接着4（100）&3（011）得到0（000），程序结束,得到的结果就是有3个“1”。
//		n = n & (n - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}

