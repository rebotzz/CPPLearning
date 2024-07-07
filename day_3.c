#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
//【题目名称】
//杨辉三角
//【题目内容】
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
#include <stdio.h>

////1.0
//void init(int arr[],int tmp[], int line)
//{
//	arr[0] = 1;
//	arr[line - 1] = 1;
//	int i = 0;
//	for (i = 1; i < line - 1; i++)
//	{
//		arr[i] = tmp[i - 1] + tmp[i];
//	}
//
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[100] = { 0 };
//	int tmp[100] = { 0 };
//	int* parr = arr;
//	int* ptmp = tmp;
//	int line = 0;
//	scanf("%d", &line);//打印多少行
//	for (i = 0; i <= line; i++)
//	{
//		//存储上一次的值
//		for (int n = 0; n < line; n++)
//		{
//			tmp[n] = arr[n];
//		}
//		for (int j = 0; j < i; j++)
//		{
//
//			init(arr, tmp, line);//初始化arr
//			//打印前置空格
//
//			//打印杨辉三角数字
//			printf("%2d ", arr[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


////2.0	代码优化
//void init(int arr[], int line)
//{
//	arr[0] = 1;
//	arr[line - 1] = 1;
//	int i = 0;
//	for (i = line - 2; i > 0; i--)//反着来,不用创建临时数组
//	{
//		arr[i] = arr[i] + arr[i - 1];
//	}
//}
//int main()
//{
//	int arr[100] = { 0 };//只存储最新一行
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 1; i <= line; i++)
//	{
//		init(arr, i);//初始化
//		int j = 0;
//		for (j = 0; j < i; j++)
//		{
//			printf("%2d ", arr[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////3.0	代码拓展

//int main()
//{
//	int arr[50][50] = {0};//创建一个二位数组存储每行每列
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;//行
//	int j = 0;//列
//	for (i = 1; i <= line; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i - 1] = 1;
//		int n = 0;
//		for (n = i - 2; n > 0; n--)
//		{
//			arr[i][n] = arr[i-1][n] + arr[i-1][n - 1];
//		}
//
//		for (j = 0; j < i; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//【题目名称】
//猜凶手
//【题目内容】
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include <stdio.h>

//1.0
////四个人
//int a = 0;
//int b = 1;
//int c = 2;
//int d = 3;
//
////结果真假数量
//int anwser(int arr[])
//{
//	int yes = 0;
//	if (arr[a] == 0)//A真
//		yes++;
//	if (arr[c] == 1)//B真
//		yes++;
//	if (arr[d] == 1)//C真
//		yes++;
//	if (arr[d] != 1)//D真
//		yes++;
//	return yes;
//}
//int main()
//{
//
//	int arr[4] = { 0 };
//	int truth = 0;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		arr[i] = 1;
//		
//		//结果真假数量
//		truth = anwser(arr);
//		if (truth == 3)//总数为4,有三个真,必有一个假.
//		{
//			switch (i)
//			{
//			case 0:
//				printf("A是凶手.\n");
//				break;
//			case 1:
//				printf("B是凶手.\n");
//				break;
//			case 2:
//				printf("C是凶手.\n");
//				break;
//			case 3:
//				printf("D是凶手.\n");
//				break;
//			}
//
//		}
//		//置为0
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			arr[j] = 0;
//		}
//	}
//	return 0;
//}

//2.0	代码优化
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)//结果为真,返回1,为假返回0
//			printf("%c 是凶手\n", killer);
//	}
//}


//请简述大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序。（10分）
//答:计算机存储的数据类型有超过1个类型,比如short,int 分别对应2,4字节.不同编译器有差异.
//超过一个字节的内容需要拆开存入到每个字节中,就涉及到拆开顺序.
//大端字节序,高字节序的内容存储到低地址位,低字节序内容存储到高地址位.
//小端字节序,低字节序的内容存储到低地址位,高字节序内容存储到高地址位.
#include <stdio.h>

//int main()
//{
//	//int a = 0x00000001;
//	int a = 1;
//	char* p = &a;
//	if (*p == 1)
//		printf("小端字节序.\n");
//	else
//		printf("大端字节序.\n");
//
//	return 0;
//}


//数据存储练习

//1.
//输出什么？
#include <stdio.h>
//int main()
//{
//    char a = -1;//char 此编译器默认是 signed char
//    //10000000000000000000000000000001原码    
//    //11111111111111111111111111111110反码
//    //11111111111111111111111111111111补码
//    //11111111截断后面 8bit
//
//    signed char b = -1;
//    //10000000000000000000000000000001原码    
//    //11111111111111111111111111111110反码
//    //11111111111111111111111111111111补码
//    //11111111截断后面 8bit
//
//    unsigned char c = -1;
//    //10000000000000000000000000000001原码    
//    //11111111111111111111111111111110反码
//    //11111111111111111111111111111111补码
//    //11111111截断后面 8bit     这里unsigned ,所以首位1不是符号位
//
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    //%d 按照10进制打印,4个字节
//    //整形提升,按照符号位补位,无符号位补 0 
//    //a
//    //11111111补码
//    //11111111111111111111111111111111补位后补码
//    //11111111111111111111111111111110反码
//    //10000000000000000000000000000001原码    -1
//    
//    //b
//    //11111111补码
//    //11111111111111111111111111111111补位后补码
//    //11111111111111111111111111111110反码
//    //10000000000000000000000000000001原码    -1
//
//    //c
//    //11111111补码  unsigned char  无符号位补 0 
//    //00000000000000000000000011111111补位后补码
//    //00000000000000000000000011111111  %d看待内存的视角,int ,正数,原反补相同 2^8-1 = 255
//
//    return 0;
//}
//总结:看待内存的视角


//2.
#include <stdio.h>
//int main()
//{
//    char a = -128;
//    //10000000000000000000000010000000
//    //11111111111111111111111101111111
//    //11111111111111111111111110000000
//    //10000000  按照char 8bit截断后
//
//    printf("%u\n", a);
//    //a
//    //10000000补码    signed 补1   整形提升
//    //11111111111111111111111110000000补码
//    //%u 看待内存视角, unsigned,没有符号位,原反补相同   对应10进制 4,294,967,168
//
//    return 0;
//}


//3.
#include <stdio.h>
//int main()
//{
//    char a = 128;
//    //00000000000000000000000010000000  原,反,补码相同
//    //10000000  按照char 8bit截断后
//
//    printf("%u\n", a);
//    //a
//    //10000000补码    signed 补1   整形提升
//    //11111111111111111111111110000000补码
//    //%u 看待内存视角, unsigned,没有符号位,原反补相同   对应10进制 4,294,967,168
//
//    return 0;
//}


////4.
//int main() 
//{
//	int i = -20;
//	//10000000000000000000000000010100
//	//11111111111111111111111111101011
//	//11111111111111111111111111101100
//
//	unsigned  int  j = 10;
//	//00000000000000000000000000001010	原,反,补码相同
//	
//	printf("%d\n", i + j);
//	//按照补码的形式进行运算，最后格式化成为有符号整数
//	//不同类型数据计算,需要类型转换
//	//为寻常算术转换	由低到高
//	//long double
//	//double
//	//float
//	//unsigned long int
//	//long int
//	//unsigned int
//	//int
//	//其中 i转化位unsigned int 
//	//11111111111111111111111111101100	i	int  ->  unsigned int
//	//00000000000000000000000000001010	j	unsigned int
//	//11111111111111111111111111110110	i+j	unsigned int	对应10进制	4,294,967,286
//	//但是
//	//关键不是数据是什么类型,而是	看待内存的视角
//	//%d	看待内存的视角为 int ,signed
//	//11111111111111111111111111110110	补码	i+j
//	//11111111111111111111111111110101	反码
//	//10000000000000000000000000001010	原码	对应10进制 -10
//
//	return 0;
//}
////总结: 关键不是数据是什么类型,而是	看待内存的视角


////5.
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)//无限循环
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}


////6.
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    //char 范围 -128~127
//    //-1 -2 ...-128 127 126 ... 2 1 0
//    //0 ASCII '\0'
//    //255
//    return 0;
//}


////7.
//#include <stdio.h>
//unsigned char i = 0;    // 0~255
////int m;//全局变量未初始化,默认为 0
//int main()
//{
//    //printf("%d\n", m);//0
//
//    for (i = 0; i <= 255; i++)//死循环
//    {
//        printf("hello world\n");
//    }
//    return 0;
//}


////浮点数
#include <stdio.h>
//int main()
//{
//	//IEEE（电气和电子工程协会） 754 规定任意一个二进制浮点数V可以表示成下面的形式
//	//浮点数可以表示为
//	//(-1) ^ S* M * 2 ^ E
//	//(-1) ^ s表示符号位，当s = 0，V为正数；当s = 1，V为负数。
//	//M表示有效数字，大于等于1，小于2。
//	//2 ^ E表示指数位。
//	//对于32位的浮点数，最高的1位是符号位s，接着的8位是指数E，剩下的23位为有效数字M。
//	//对于64位的浮点数，最高的1位是符号位S，接着的11位是指数E，剩下的52位为有效数字M。
//	//存入内存时E的真实值必须再加上一个中间数，对于8位的E，
//	//这个中间数是127；对于11位的E，这个中间数是1023
//	//E全为0	这时，浮点数的指数E等于1 - 127（或者1 - 1023）即为真实值，
//  //E全为1	这时，如果有效数字M全为0，表示±无穷大（正负取决于符号位s）；
//
//	int n = 9;
//	//00000000000000000000000000001001
//
//	float* pFloat = (float*)&n;//64位,64bit
//	printf("n的值为：%d\n", n);
//	//00000000000000000000000000001001	%d	9
//	printf("*pFloat的值为：%f\n", *pFloat);
//	//0 00000000 00000000000000000001001	%f
//	//s E		 m		E全0,e = 0-127,m = 0.xxxxx
//	//(-1)^0*2^(-127)*(0.00000000000000000001001这里是二进制表示)	约等于0
//
//	*pFloat = 9.0;
//	//1001.0 = 1.001*2^3	m = 1.001	e = 3 + 127 = 130
//	//s		e		m(1.省略,只留下小数点后面)
//	//0	10000010	00100000000000000000000
//
//	printf("num的值为：%d\n", n);
//	//n	看待内存视角 %d	int
//	//0 10000010 00100000000000000000000	原反补相同	对应10进制	1,091,567,616
//
//	printf("*pFloat的值为：%f\n", *pFloat);
//	//n
//	//0	10000010	00100000000000000000000
//	//s	e			m		e = e -127 = 130 -127 = 3
//	// n = (-1)^s*m*2^e		9.0
//	return 0;
//}


//【题目名称】
//猜名次
//【题目内容】
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include <stdio.h>
#include <time.h>

////有问题,不对
//int main()
//{
//	int a = 0, b = 1, c = 2, d = 3, e = 4;
//	char ranking[5] = { 0 };
//	
//	while (1)
//	{
//		while (1)//随机次序
//		{
//			ranking[a] = rand() % 5 + 1;//1~5
//			if ((ranking[b] = (rand() % 5 + 1)) != ranking[a])
//				if ((ranking[c] = (rand() % 5 + 1)) != ranking[a] && (ranking[c] = (rand() % 5 + 1)) != ranking[b])
//					if ((ranking[d] = (rand() % 5 + 1)) != ranking[a] && (ranking[d] = (rand() % 5 + 1)) != ranking[b] && (ranking[d] = (rand() % 5 + 1)) != ranking[c])
//						if ((ranking[e] = (rand() % 5 + 1)) != ranking[a] && (ranking[e] = (rand() % 5 + 1)) != ranking[b] && (ranking[e] = (rand() % 5 + 1)) != ranking[c] && (ranking[e] = (rand() % 5 + 1)) != ranking[d])
//							break;
//		}
//		//检验真伪
//		if ((ranking[b] == 2) + (ranking[a] == 3) == 1	 //A
//			&& (ranking[b] == 2) + (ranking[e] == 4) == 1//B
//			&& (ranking[c] == 1) + (ranking[d] == 2) == 1//C
//			&& (ranking[c] == 5) + (ranking[d] == 3) == 1//D
//			&& (ranking[e] == 4) + (ranking[a] == 1) == 1)//E
//			break;
//	}
//
//	//打印
//	printf("a  b  c  d  e  \n");
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ranking[i]);
//	}
//	printf("\n");
//	return 0;
//}

//有问题,不对
//int main()
//{
//	int a = 0, b = 1, c = 2, d = 3, e = 4;
//	char ranking[5] = { 0 };
//
//	while (1)
//	{
//		//随机	二选一
//		if (rand() % 2 == 1)//a
//			ranking[b] = 2;
//		else
//			ranking[a] = 3;
//		if (rand() % 2 == 1)//b
//			ranking[b] = 2;
//		else
//			ranking[e] = 4;
//		if (rand() % 2 == 1)//c
//			ranking[c] = 1;
//		else
//			ranking[d] = 2;
//		if (rand() % 2 == 1)//d
//			ranking[c] = 5;
//		else
//			ranking[d] = 3;
//		if (rand() % 2 == 1)//e
//			ranking[e] = 4;
//		else
//			ranking[a] = 1;
//		//判断	名次不重复
//		int i = 0;
//		int count = 0;
//		for (i = 0; i < 5; i++)
//		{
//			int j = 0;
//			for (j = 0;( j < 5 && j != i); j++)
//			{
//				if (ranking[i] == ranking[j] || ranking[i] == 0)
//					count++;
//			}
//		}
//		if (count == 0)
//			break;
//		count = 0;
//	}
//
//	//打印
//	printf("a  b  c  d  e  \n");
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ranking[i]);
//	}
//	printf("\n");
=======
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
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
////参考代码
//#include <stdio.h>
//
//int checkData(int* p)
//{
//	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。
//
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
//		{
//			return 0;
//		}
//		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
//	}
//	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
=======

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
>>>>>>> w6/main
//}
//
//int main()
//{
<<<<<<< HEAD
//	int p[5]; //0 1 2 3 4分别代表a b c d e
//
//	for (p[0] = 1; p[0] <= 5; p[0]++)
//	{
//		for (p[1] = 1; p[1] <= 5; p[1]++)
//		{
//			for (p[2] = 1; p[2] <= 5; p[2]++)
//			{
//				for (p[3] = 1; p[3] <= 5; p[3]++)
//				{
//					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
//					{
//						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
//						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
//							checkData(p) //不能并列
//							)
//						{
//							for (int i = 0; i < 5; i++)
//							{
//								printf("%d ", p[i]);
//							}
//							putchar('\n');
//						}
//					}
//				}
//			}
//		}
//	}
=======
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
>>>>>>> w6/main
//
//	return 0;
//}

<<<<<<< HEAD
//参考后写的代码	
//数组存储 0 1 2 3 4 分别放 a b c d e 的排名
//p[0]从 1...5依次变换,接着是p[1],p[2]...p[4]	5层循环
//检查名次是否重叠
//检测是否符合判断,各对一半
#include <stdio.h>

////1.0
//int CheakRepeat(int p[])
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if (i != j)
//			{
//				if (p[i] == p[j])
//					count++;
//			}
//		}
//	}
//	if (count == 0)
//		return 1;
//	else
//		return 0;
//}

////2.0
//int CheakRepeat(int p[])
//{
//	int n = 0;
//	int i = 0;
//	for (i = 0; i < 5; i++)	//是 0 ~ 4 ,不是1 ~ 5,数组下标
//	{
//		n = n | (1 << p[i]);
//	}
//	//0011 1110
//	if (n == 0x0000003e)
//		return 1;
//	else
//		return 0;
//}

////3.0
//int CheakRepeat(int* p)
//{
//	int tmp[7] = { 0 };	//标记表,p[i] ,i: 0 ...4  p[i]:1 ... 5  
//	int i = 0;
//	for (i = 0; i < 5; i++)	
//	{
//		if (tmp[p[i]])//没改变前为 0,如果p[i]没有重复的值,则每次都是新的tmp[p[i]],都为 0
//			return 0;
//		tmp[p[i]] = 1;//改变后为 1
//	}
//	return 1;
//}
//int main()
//{
//	int p[5] = { 0 }; //存储 0 1 2 3 4 分别放 a b c d e 的排名
//	//构建不会重复的排序
//	for (p[0] = 1; p[0] <= 5; p[0]++)//a
//	{
//		for (p[1] = 1; p[1] <= 5; p[1]++)//b
//		{
//			for (p[2] = 1; p[2] <= 5; p[2]++)//c
//			{
//				for (p[3] = 1; p[3] <= 5; p[3]++)//d
//				{
//					for (p[4] = 1; p[4] <= 5; p[4]++)//e
//					{
//						//检测是否符合要求
//						if ((p[1] == 2) + (p[0] == 3) &&
//							(p[1] == 2) + (p[4] == 4) &&
//							(p[2] == 1) + (p[3] == 2) &&
//							(p[2] == 5) + (p[3] == 3) &&
//							(p[4] == 4) + (p[0] == 1) &&
//							CheakRepeat(p))
//						{
//							int i = 0;//打印
//							for (i = 0; i < 5; i++)
//							{
//								printf("%d ", p[i]);
//							}
//							printf("\n");
//							return 0;//结束,这样就不用跳出5层循环
//						}
//							
//					}
//				}
//			}
//		}
//	}
//	printf("?\n");
//	return 0;
//}


//参考代码2.0
#include <stdio.h>
//int checkData(int* p)
//{
//	int tmp[7] = { 0 };	//标记表,p[i] ,i: 0 ...4  p[i]:1 ... 5  
//	int i = 0;
//	for (i = 0; i < 5; i++)	
//	{
//		if (tmp[p[i]])//没改变前为 0,如果p[i]没有重复的值,则每次都是新的tmp[p[i]],都为 0
//			return 0;
//		tmp[p[i]] = 1;//改变后为 1
//	}
//	return 1;
//}
//void diveRank(int* p, int n)
//{
//	if (n >= 5) //此时的n是用来控制循环层数的。
//	{
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//			(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
//			checkData(p)) //查重
//		{
//			for (int i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			putchar('\n');
//		}
//		return;
//	}
//
//	for (p[n] = 1; p[n] <= 5; p[n]++)
//	{
//		diveRank(p, n + 1); //通过递归模拟多层循环，每进一次递归相当于进了一层新的循环。
//	}
//}
//
//int main()
//{
//	int p[5];
//
//	diveRank(p, 0);
//
//	return 0;
//}


//参考后自己写
//递归实现5层for循环
//每层递归分别改变 p[0] p[1] ... p[4]
//用p[n]表示每层中的p[0] p[1] ... p[4]
//改变n,n是判断递归结束标志
#include <stdio.h>

int checkData(int* p)//检查重复
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < 5; i++)
	{
		tmp = tmp | (1 << p[i]);
	}
	//0011 1110
	if (tmp == 0x0000003e)
		return 1;
	else
		return 0;
}
////1.0	执行5^5次,有重复
//void diveRank(int* p, int n)//递归实现5层for循环,并检验
//{
//	if (n >= 5)//结束第5层递归
//	{	//检验
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//			(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
//			checkData(p)) //查重
//		{
//			int i = 0;//打印结果
//			for (i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			puts("\n");
//			//就算打印后程序依旧会执行,直到递归结束,递归回到第一层的return,彻底结束函数
//		}
//		return;//结束本层递归
//	}
//	//递归部分
//	for (p[n] = 1; p[n] <= 5; p[n]++)//用p[n]表示每层中分别表示p[0] p[1] ... p[4],每次依次从1到5,共执行5^5 = 3125次
//	{
//		diveRank(p, n + 1);//进入下一次递归
//	}
//}

////2.0	优化,执行5!次,没有重复,不用checkData(p)	未完成
//void diveRank(int* p,int* arr, int n)//递归实现5层for循环,并检验
//{
//	if (n >= 5)//结束第5层递归
//	{
//		p = p - n;//第五层递归中p地址迁移了5单位,还原,访问素组
//		//检验
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
//		{
//			int i = 0;//打印结果
//			for (i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			puts("\n");
//			//就算打印后程序依旧会执行,直到递归结束,递归回到第一层的return,彻底结束函数
//		}
//		p = p + n;//回到p在第五层递归中原有地址
//		return;//结束本层递归
//	}
//	//递归部分
//	int i = 0;
//	for (i = 0; i < 5 - n; i++)
//	{
//		//for (int a = 1; a < 5 - n; a++)//此处未完成
//		//{
//		//	arr[a] = p[a];
//		//}
//		//p首位交换
//		int tmp = p[0];
//		p[0] = p[i];
//		p[i] = tmp;
//
//		//p首位前移
//		diveRank(p+1,arr+1, n + 1);
//		//每层递归结束,该层p还原,不然打乱的顺序会漏掉某些值	此处未完成.下一层会干扰上一次顺序.
//		//for (int a = 1; a < 5 - n; a++)
//		//{
//		//	p[a] = arr[a];
//		//}
//	}
//
//}
//int main()
//{
//	int arr[5] = { 0 };
//	int p[5] = { 1,2,3,4,5 };
//	diveRank(p,arr,0);
//	return 0;
//}


//参考代码
#include <stdio.h>

//void swapArgs(int* a, int* b) //交换函数
//{
//	int tmp;
//
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void diveRank(int* p, int n)
//{
//	if (n >= 5) //此时的n也是用来控制循环层数的。
//	{
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
//			//由于此时是执行的全排列，所以查重也省了。
//		{
//			for (int i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			putchar('\n');
//		}
//		return;
//	}
//
//	int i;
//	for (i = n; i < 5; i++) //这个递归方式就完成了对1~5的全排列，方法是从后向前不停的执行交换。可以参考改进二和原代码，将这个递归程序写回成循环后，可以更好的理解。
//	{
//		swapArgs(p + i, p + n);
//		diveRank(p, n + 1);
//		swapArgs(p + i, p + n);//还原
//	}
//}
//
//int main()
//{
//	int p[5] = { 1, 2, 3, 4, 5 }; //当然由于是全排列，所以初值必须给好。
//
//	diveRank(p, 0);
//
//	return 0;
//}


//参考后,自己写
//之前失败的原因:
//1.递归没有处理好,递归的核心思想:大事化小,拆分问题,逐渐接近,结束递归
//2.还原每层的序列时,问题没有拆分,导致不知道怎么还原,所以失败
//还原序列这个复杂操作也需要拆分问简单操作,从还原一组序列 简化为 还原交换的两个值
#include <stdio.h>

////交换
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void diveRank(int* p,int n)//递归实现5层for循环,并检验
//{
//	if (n >= 5)//结束第5层递归
//	{
//		//检验
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
//			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
//			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
//			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
//			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
//		{
//			int i = 0;//打印结果
//			for (i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			puts("\n");
//			//就算打印后程序依旧会执行,直到递归结束,递归回到第一层的return,彻底结束函数
//		}
//		return;//结束本层递归
//	}
//	//递归部分
//	int i = 0;
//	for (i = n; i < 5; i++)
//	{
//		swap(p + i, p + n);//p + n首位,p + i首位及之后
//		diveRank(p, n + 1);
//		swap(p + i, p + n);//还原交换,以防某位漏掉应有值
//	}
//}
//int main()
//{
//	int p[5] = { 1,2,3,4,5 };
//	diveRank(p,0);
//	return 0;
//}
=======


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

>>>>>>> w6/main
