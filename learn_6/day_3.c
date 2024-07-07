#define _CRT_SECURE_NO_WARNINGS

//动态内存分配学习


//malloc
//calloc
//realloc
//free
//NULL
//柔性数组
// 库 #include <stdlib.h>
//1.可以解决在栈区开辟内存自动释放的问题
//2.动态开辟,内存不固定,解决数字arr[不能是变量]的问题.
//3.可存储空间大,栈区资源宝贵
//4.柔性数组:可以创建结构体,最后一个成员是不指定大小的数组,大小由malloc分配,sizeof计算结构体大小不包括柔性数组.
//5.柔性数组:数组前面至少有一个其他元素.开辟空间至少能容下其他元素

//注意事项(常见错误):
//1.内存开辟失败返回 NULL,对 NULL解引用. ==> 使用指针前先判空
//2.使用开辟内存后忘记释放,导致内存泄露. ==> free(p); p = NULL;
//3.越界访问,超出开辟大小.
//4.对非开辟空间的指针进行释放,或者对开辟空间指针多次释放.
//5.改变开辟空间指针,导致开辟空间找不到了.	==> *(p + i);别直接修改 p
//6.malloc,calloc,realloc返回指针void*,需要强制类型转换. ==>	(强制类型转换)malloc();
//7.调用函数结束,栈区开辟空间释放,所以返回指向这片空间指针没用.野指针


#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int num = 5;
//	int* pnum = &num;
//	//int arr[num] = { 0 };//error
//	int* p = (int*)malloc(num * sizeof(int));//开辟内存不初始化
//	if (p == NULL)		//判空
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < num; i++)//不能越界访问
//	{
//		*(p + i) = i + 1;
//	}
//	//打印
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//
//	//别忘了释放内存,不然会导致内存泄露
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//#include <string.h>
//#include <errno.h>
//int main()
//{
//	int num = 5;
//	//开辟内存
//	int* p = (int*)calloc(num, sizeof(int));//开辟内存初始化为 0 
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//	//扩容
//	num = 8;
//	void* tmp = realloc(p, num * sizeof(int));
//	if (tmp != NULL)
//	{
//		p = (int*)tmp;
//		tmp = NULL;
//	}
//	else
//	{
//		return 1;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//	//释放内存
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//几个经典的笔试题
//4.1 题目1：
#include <stdio.h>
#include <stdlib.h>

//void GetMemory(char* p) //p = NULL
//{
//	p = (char*)malloc(100); //p 指向开辟空间.函数调用结束,局部变量 p 在栈区释放,所存储地址丢失
//							//没有free();内存泄露
//
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str); //传递的是指针变量的值 NULL ,而不是指针变量str的地址,不会改变str
//	strcpy(str, "hello world");//str = NULL ,非法访问
//	printf(str);	// str 指向 "hello world"首元素地址. ==> printf("hello world");
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//题目 2
#include <stdio.h>
#include <stdlib.h>

//char* GetMemory(void)
//{
//	char p[] = "hello world";//p 是局部变量,在栈区开辟,当函数调用结束,p所指向空间释放.
//	return p;				 //p 返回没有意义.野指针
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);	//野指针,随机
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//题目 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void GetMemory(char** p, int num)//二级指针
//{
//	*p = (char*)malloc(num);//将开辟空间地址赋值给str
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);//传递指针变量str的地址,能改变str的值.
//	strcpy(str, "hello");
//	printf(str);
//						 //没有free(str);str = NULL; ==> 内存泄露
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//题目 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void Test(void)
//{
//	char* str = (char*)malloc(100);//没有判空处理
//	strcpy(str, "hello");
//	free(str);				//过早释放内存,且没有 str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");	//非法访问
//		printf(str);
//	}
//
//	////结合代码意图修改
//	//if (str != NULL)
//	//{
//	//	strcat(str, "world");	//非法访问
//	//	printf(str);
//	//}
//	//free(str);				//过早释放内存,且没有 str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//柔性数组
#include <stdio.h>

//typedef struct A	//结构体声明
//{
//	int a;
//	int arr[];//柔性数组空间开辟在堆上,所以整个结构在堆上开辟    !  不不不,这里理解错了,在哪里开辟由使用者决定.是否 malloc
//}a_arr;
//
//int main()
//{
//	int num = 5;
//	printf("%u\n", sizeof(a_arr));
//
//	//错误
//	//a_arr s = { 0 };//结构体变量创建  ==>  堆区  !  不不不,这里理解错了,在哪里开辟由使用者决定.是否 malloc
//	//printf("%p\n", &s);
//	////开辟空间
//	//int* parr = (int*)malloc(sizeof(a_arr) + num * sizeof(int));//使用错误,parr 与 s 无关.
//	//if (parr == NULL)
//	//{
//	//	return 1;
//	//}
//	//printf("%p\n", parr);
//	//int i = 0;
//	//for (i = 0; i < num; i++)
//	//{
//	//	s.arr[i] = i + 1;
//	//}
//
//	////修改后
//	//a_arr* parr = (a_arr*)malloc(sizeof(a_arr) + num * sizeof(int));
//	//if (parr == NULL)
//	//{
//	//	return 1;
//	//}
//	//parr->a = 2;
//	//int i = 0;
//	//for (i = 0; i < num; i++)
//	//{
//	//	parr->arr[i] = i + 1;
//	//}
//
//	//for (i = 0; i < num; i++)
//	//{
//	//	printf("%d ", parr->arr[i]);
//	//}
//
//	//修改后 2.0
//	a_arr* parr = (a_arr*)malloc(sizeof(a_arr) + num * sizeof(int));
//	if (parr == NULL)
//	{
//		return 1;
//	}
//	parr->a = num;//这里的 a 可用来记录数组大小,这样更方便
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		parr->arr[i] = i + 1;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", parr->arr[i]);
//	}
//
//
//	//释放空间
//	free(parr);
//	parr = NULL;
//
//	return 0;
//}


//上述柔性数组可以等效为:
//但是,缺点,需要多次开辟,释放内存,有先后顺序.容错低
//不利于访问速度.连续的内存有益于提高访问速度，也有益于减少内存碎片。
#include <stdio.h>
#include <stdlib.h>

//typedef struct B
//{
//	int i;
//	int* parr;
//}b_arr;
//
//int main()
//{
//	//内存开辟
//	b_arr* pb = (b_arr*)malloc(sizeof(b_arr));//开辟结构体,成员:int i ;指向数组的指针 int* parr;
//	if (pb == NULL)
//	{
//		return 1;
//	}
//	pb->i = 10;
//	pb->parr = (int*)malloc(pb->i * sizeof(int));//开辟数组,空间由结构体成员 p->parr 指向 ;大小,pb->i个int
//	int i = 0;
//	for (i = 0; i < pb->i; i++)
//	{
//		pb->parr[i] = i + 1;
//	}
//
//
//	//内存释放,两次开辟,两次释放,类似链表,注意释放先后顺序
//	free(pb->parr);//先释放结构体指向的数组
//	pb->parr = NULL;
//	free(pb);//再释放结构体所在空间
//	pb = NULL;
//
//	return 0;
//}



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
#include <limits.h>//INT_MAX INT_MIN

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

//模拟实现2.0	关键,完成代码核心后,对代码可能情况的处理,细节
//判断返回的 0 是转化的0,还是其他原因导致的 0
//enum judge
//{
//	VALID,	//0 输出结果有效
//	INVALID	//1 输出结果无效
//};
//enum judge lable = INVALID;//初始无效
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
//		ret = ret * 10 + *p - '0';//或者 ret = 10*ret flag*(*p - '0');
//		//判断是否超过最大存储范围
//		if ((ret < INT_MIN) || (ret > INT_MAX))//算数类型转换
//		{
//			return 0;
//		}
//		p++;
//	}
//	ret = flag * ret;
//	if (p > str)//进行了数字的转化
//	{
//		lable = VALID;//结果有效
//		return (int)ret;
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char str[50] = { 0 };
//	strcpy(str, "\t\f\r+-12345678AAA");
//	//int a = atoi(str);
//	int a = my_atoi(str);
//	if (lable == VALID) 
//	{
//		printf("转化结果有效.\n");
//	}
//	else
//	{
//		printf("转化结果0无效.\n");
//	}
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

