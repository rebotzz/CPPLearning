#define _CRT_SECURE_NO_WARNINGS

//指针进阶学习 2


#include <stdio.h>

//int main()
//{
//	//代码1
//	(*(void (*)())0)();//(void (*)())函数指针类型,参数void,返回值void.外层有括号,判断为( )强制类型转换.
//					   //将 0 (NULL空指针)强制类型转换为 void (*)()函数指针类型.所以0地址指向一个函数.
//					   //(*(void (*)())0)代表着0地址指向的函数名(地址).函数名();调用该函数.
//					   //(*(void (*)())0)();调用0地址指向的函数.
//	//代码2
//	void (*signal(int, void(*)(int)))(int);//void (*)(int)去掉名字,留下的是类型.函数指针类型,函数参数int,返回值void.
//										   //signal(int, void(*)(int)),后面有括号,函数,这表示一个名为signal的函数.
//										   //signal函数的参数类型有int ,void(*)(int)函数指针类型.
//										   //函数的返回值类型从外面看,由void (*)(int)决定.返回类型void (*)(int)函数指针类型.
//	//代码优化
//	typedef void(*pf_void_int)(int);//类型重定义,将 void (*)(int) 类型用 pf_void_int 表示.
//	pf_void_int signal(int, pf_void_int);
//	return 0;
//}


//函数指针数组
//函数指针数组的用途：转移表
#include <stdio.h>

//int main()
//{
//	int(*pfarr[5])();//函数指针数组,pfarr[5],int(*)()元素类型
//
//	return 0;
//}


//计算器

//菜单
void meun()
{
	printf("*************  计算器  ******************\n");
	printf("************* 1.加  2.减 ****************\n");
	printf("************* 3.乘  4.除 ****************\n");
	printf("*************    0.exit     *************\n");
	printf("*****************************************\n");
}

//加法
int add(int x, int y)
{
	return x + y;
}
//减法
int sub(int x, int y)
{
	return x - y;
}
//乘法
int mul(int x, int y)
{
	return x * y;
}
//除法
int div(int x,int y)
{
	return x / y;
}
////除法2.0
//float div(float x,float y)
//{
//	return x / y;
//}

//1.0	代码冗余,重复操作多
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		//菜单
//		meun();
//		printf("请输入操作.\n");
//		scanf("%d" ,&input);
//
//		int x = 0, y = 0;
//		int ret = 0;
//
//		switch(input)
//		{
//		case 1:
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("%d \n", ret);
//			break;
//		case 2:
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("%d \n", ret);
//			break;
//		case 3:
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("%d \n", ret);
//			break;
//		case 4:
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			//ret = div(x, y);
//			//printf("%d \n", ret);
//			printf("%f \n", div((float)x, (float)y));
//			break;
//		case 0:
//			printf("退出程序.\n");
//			break;
//		default:
//			printf("输入错误,请重新输入.\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

////2.0	代码优化,利用函数指针,回调函数应用
//int main()
//{
//	int input = 1;
//	int x = 0, y = 0;
//	int ret = 0;
//	//建立一个函数指针数组,存储不同调用函数		==> 转移表
//	int(*pfun[5])(int, int) = { NULL,add,sub,mul,div };//输入数组从1开始,所以下标空 0, &add 与 add 等价.NULL 和 0 等价.
//	while (input)
//	{
//		//菜单
//		meun();
//		printf("请输入操作.\n");
//		scanf("%d", &input);
//		if ((input >= 1) && (input <= 4))//防止数组访问越界,访问野指针
//		{
//			printf("请输入两个数\n");
//			scanf("%d %d", &x, &y);
//			//调用函数
//			ret = pfun[input](x, y);
//			printf("%d \n", ret);
//		}
//		else if(input != 0)
//			printf("选择错误,请重新输入.\n");
//	}
//
//	printf("退出程序.\n");
//
//	return 0;
//}


//指向函数指针数组的指针
#include <stdio.h>

//int main()
//{
//	int (*pf)(int);//函数指针
//	int (*pfarr[5])(int);//函数指针数组
//	int(**ppf)(int) = pfarr;//pfarr函数名,首元素(函数指针)的地址,指针的地址,二级指针.int(*(*ppf))(int)
//							//指针*ppf,指针名ppf,指向的元素类型int(*)(int)
//							//综合:int(*(*ppf))(int)	指向函数指针数组首元素的指针
//	int(*(*ppfarr)[5])(int) = &pfarr;//&pfarr数组的地址,用数组指针存储
//									 //元素类型		(* 指针名)		[元素个数]
//									 //int(*)(int)   (*ppfarr)		[5]
//									 //综合: int(*(*ppfarr)[5])(int)	指向函数指针数组的指针
//	return 0;
//}


//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针pfun
//	void (*pfun)(const char*) = test;
//	//函数指针的数组pfunArr
//	void (*pfunArr[5])(const char* );
//	pfunArr[0] = test;
//	//指向函数指针数组pfunArr的指针ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
//	return 0;
//}


//回调函数

//qsort函数	
//排序,可以任意类型排序
//void qsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
//void* 无具体类型指针,可以存储任何类型指针,但是使用时需要强制类型转换.
//void* base数组的首地址, size_t num数组元素个数, size_t size每个元素大小(byte),
//int (*compar)(const void*, const void*)函数指针,指向比较两个地址指向内容大小比较的函数
#include <stdio.h>

////qosrt函数的使用得实现一个比较函数
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//前者大于后者返回 >0 ,等于返回 0,小于返回 <0
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//模拟实现 qsort()函数.
//交换元素
#include <stdio.h>
#include <string.h>

//void swap(void* e1,void* e2,size_t width)//不知道交换类型,所以就按最小单位byte依次交换到元素末尾字节
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *((char*)e1 + i);//* 优先级高于 (强制类型转换), (强制类型转换) 优先级高于 算数相加 +
//		*((char*)e1 +i) = *((char*)e2 +i);//+i 访问下一个字节
//		*((char*)e2 +i) = tmp;
//	}
//}
//
//void my_qsort(void* arr,unsigned int sz,size_t width,int (*cmp)(void* ,void*))
//{
//	//排序的核心思想还是起泡法排序 bubble_sort
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//前面的排序好了,最后一个元素就不用排序,位置归位
//	{
//		int j = 0;
//		for (j = 0; j <sz -i -1; j++)//把一个较大者放在末端
//		{
//			if (cmp((char*)arr + j*width,(char*)arr + (j+1)*width)>0)//width元素大小,单位字节
//			{
//				//交换,不同类型交换方式不一样,所以传地址,用void* 接收,需要每个元素字节大小
//				swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
//			}
//		}
//	}
//
//}
//
////比较两个元素 int
//int cmp_int(void* e1, void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//
////比较两个元素 char
//int cmp_char(void* e1, void* e2)
//{
//	//strcmp依次比较两个字符串对应字符的ASCII码值,大于 返回 >0,小于 返回 <0 ,等于 返回 0 (相同继续下一位,直到不同或者结束)
//	return strcmp((char*) e1,(char*) e2);
//}
//
////声明
////结构体类型
//struct stu
//{
//	int age;
//	char name[15];
//};
////比较两个元素 结构体 age
//int cmp_struct_stu_age(void* e1, void* e2)
//{
//	//e1 , e2 结构体数组元素的首地址
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;//访问结构指针成员 -> 优先级高于 (强制类型转换).但结合方向不同
//}
//
////比较两个元素 结构体 name
//int cmp_struct_stu_name(void* e1, void* e2)
//{
//	//e1 , e2 结构体数组元素的首地址
//	return strcmp(&(((struct stu*)e1)->name) ,&(((struct stu*)e2)->name));//strcmp传递参数是char*地址
//}
//
//
////打印
////void print(void* arr, size_t sz,size_t width)//不知道打印元素类型,按最小单位byte依次打印
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		printf("");//这里不行,printf()看待内存的视角不同,打印的结果就不同,不知道类型,不知道怎么打印
////				   //这里 我 弄不了通用的.
//// 	}
////}
//void print(void* arr, size_t sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////打印int
//		//printf("%d ", *(((int*)arr) + i));
//		//打印char
//		printf("%c", *((char*)arr + i));
//		////打印float
//		//printf("%f ", *((float*)arr + i));
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	//int arr[10] = { 2,8,4,6,7,1,3,5,9,0 };
//	//char arr[20] = "hello bit.1234dcba";
//	struct stu arr[3] = { {15,"wangping"},{21,"heweidao"},{19,"zhangwudi"}};//结构体数组
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	//print(arr, sz);
//
//	//排序
//	//my_qsort(arr, sz, width, cmp_int);
//	//my_qsort(arr, sz, width, cmp_char);
//	//my_qsort(arr, sz, width, cmp_struct_stu_age);
//	my_qsort(arr, sz, width, cmp_struct_stu_name);
//
//
//	//打印
//	//print(arr, sz);
//	return 0;
//}


//指针和数组笔试题解析
//数组名的意义：
//1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
//2. & 数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
//3. 除此之外所有的数组名都表示首元素的地址。
#include <stdio.h>
#include <string.h>

//int main()
//{
//	////一维数组
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));//a表示整个数组,有sizeof(),且单独	4*4 = 16
//	//printf("%d\n", sizeof(a + 0));//a+0指针,首元素地址,x64平台,指针64bit, 8字节
//	//printf("%d\n", sizeof(*a));//元素1,int 4
//	//printf("%d\n", sizeof(a + 1));//地址, 8
//	//printf("%d\n", sizeof(a[1]));//元素2,int 4
//	//printf("%d\n", sizeof(&a));//a表示整个数组,&.	数组指针,地址,	8
//	//printf("%d\n", sizeof(*&a));//解引用数组指针,得到数组	16
//	//printf("%d\n", sizeof(&a + 1));//地址,移动一个数组长度,	8
//	//printf("%d\n", sizeof(&a[0]));//地址,	8
//	//printf("%d\n", sizeof(&a[0] + 1));//地址	8
//	
//	////字符数组
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//arr整个数组, 6*1 = 6
//	//printf("%d\n", sizeof(arr + 0));//地址,	8
//	//printf("%d\n", sizeof(*arr));//arr数组首元素地址,	1
//	//printf("%d\n", sizeof(arr[1]));//元素'b',	1
//	//printf("%d\n", sizeof(&arr));//数组指针,	8
//	//printf("%d\n", sizeof(&arr + 1));//数组指针,移动一个数组,	8
//	//printf("%d\n", sizeof(&arr[0] + 1));//字符指针,移动一个char长度,	8
//	//printf("%d\n", strlen(arr));//	没有'\0'结束,随机值
//	//printf("%d\n", strlen(arr + 0));//	没有'\0'结束,随机值
//	////printf("%d\n", strlen(*arr));//strlen()参数是char* ,*arr是元素 'a',类型不匹配,error
//	////printf("%d\n", strlen(arr[1]));//元素'b',类型不匹配,error
//	//printf("%d\n", strlen(&arr));//数组指针,char(*)[6],	指向的还是首元素地址,但是访问权限和步长不一样,	没有'\0'结束,随机值
//	////那么,问题来了,我认为是随机值
//	////但是,每次打印结果是 42	,but why?
//	////测试平台x64,每次结果都是42,后面的地址似乎被用了,原理未知
//	////测试平台改为x86,结果为随机值
//	//printf("%d\n", strlen(&arr + 1));//地址,移动了一个数组,随机值
//	//printf("%d\n", strlen(&arr[0] + 1));//地址,移动了一个元素,没有'\0'结束,随机值	
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//	7*1 = 7
//	//printf("%d\n", sizeof(arr + 0));//地址	8/4
//	//printf("%d\n", sizeof(*arr));//首元素地址,解引用,'a'	1
//	//printf("%d\n", sizeof(arr[1]));//'b' 1
//	//printf("%d\n", sizeof(&arr));//地址,	4/8
//	//printf("%d\n", sizeof(&arr + 1));//地址,	4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//地址,	4/8
//	//printf("%d\n", strlen(arr));//	有'\0'结束,	6
//	//printf("%d\n", strlen(arr + 0));//6
//	////printf("%d\n", strlen(*arr));//'a'不是地址,error
//	////printf("%d\n", strlen(arr[1]));//'b'不是地址,error
//	//printf("%d\n", strlen(&arr));//数组指针类型,但是值还是首元素地址,	6
//	//printf("%d\n", strlen(&arr + 1));//随机值
//	//printf("%d\n", strlen(&arr[0] + 1));//5
//
//	//char* p = "abcdef";//指向常量字符串的指针
//	//printf("%d\n", sizeof(p));//地址,指针,	4/8
//	//printf("%d\n", sizeof(p + 1));//地址,	4/8
//	//printf("%d\n", sizeof(*p));//解引用,'a',char	1
//	//printf("%d\n", sizeof(p[0]));//p[0] 等价于 *(p+0) ,'a',	1
//	//printf("%d\n", sizeof(&p));//地址,二级指针,	4/8
//	//printf("%d\n", sizeof(&p + 1));//地址,二级指针,移动一个地址大小		4/8
//	//printf("%d\n", sizeof(&p[0] + 1));//[] 结和性优于 &,地址,指向'b',	4/8
//	//printf("%d\n", strlen(p));//'\0',	6
//	//printf("%d\n", strlen(p + 1));//移动一个char,	5
//	////printf("%d\n", strlen(*p));//'a',	error
//	////printf("%d\n", strlen(p[0]));//'a',	error
//	//printf("%d\n", strlen(&p));//二级指针,	随机值
//	//printf("%d\n", strlen(&p + 1));//二级指针,移动一个指针大小,(4/8)	随机值
//	//printf("%d\n", strlen(&p[0] + 1));//&(p[0]) => &('a') => &(*(p+0)) => p, p+1,	5
//	////实际情况是,无论x86,x64,随机值都不随机
//	////或许应该改为未知值
//	////这次访问的二级指针,或许在内存中存放指针的空间有尚未知晓的规律
//
//	////二维数组
//	//int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a));//a整个数组,	12*4 = 48
//	//printf("%d\n", sizeof(a[0][0]));//元素,int	4
//	//printf("%d\n", sizeof(a[0]));//a[0]表示第 0 行的一维数组,是第0行的数组名,
//	//							 //数组名单独在sizeof()内,表示整个第0行数组,{0,0,0,0},	4*4 = 16
//	//printf("%d\n", sizeof(a[0] + 1));//第0行的数组名 + 1,非两种特殊情况,表示0行{0,0,0,0}首元素地址,移动一个int,	4/8
//	//printf("%d\n", sizeof(*(a[0] + 1)));//元素,int 4
//	//printf("%d\n", sizeof(a + 1));//a表示首元素地址,首元素是一维数组,数组地址,所以是数组指针类型,int(*)[4],
//	//							  //地址,移动一行大小	4/8
//	//printf("%d\n", sizeof(*(a + 1)));//数组指针,移动一行大小,指向第二行,*(a + 1) <==> a[1],第二行一维数组名,
//	//								 //数组名单独放在sizeof()里,表示整个数组,	4*4 = 16 byte
//	//printf("%d\n", sizeof(&a[0] + 1));//a[0]第0行数组名,&a[0],第0行地址,数组指针,移动一行,	4/8
//	//printf("%d\n", sizeof(*(&a[0] + 1)));//指向第1行一维数组的指针,即 &a[1],解引用,a[1],第1行数组名
//	//									 //数组名单独放在sizeof(),表示整个第1行一维数组,	4*4 = 16
//	//printf("%d\n", sizeof(*a));//a第0行数组指针,解引用得到第0行数组,	4*4 =16
//	//printf("%d\n", sizeof(a[3]));//a第3行数组名,数组名单独放在sizeof(),表示整个第3行一维数组,
//	//							 //但是实际上没有第3行,sizeof()内部表达式不参与运算,不用 "值属性",只用到 "类型属性"
//	//							 //利用类型推测结果		4*4 = 16
//
//}



//指针笔试题
#include <stdio.h>

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
////程序的结果是什么？
////2,5


////结构体的大小是20个字节, int + char* + short + char[2] + short[4]
////						   4  +  4/8  +   2   +    2    +     8     = 20 byte
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;//struct Test *p,结构体类型指针
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	printf("%p\n", p + 0x1);//0x100014,指针加1,移动1个指向类型大小的长度,20byte
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001,被强制类型转换为无符号long类型,其实这里就是无符号int,数字加1,正常计算
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004,指针加1,移动1个指向类型大小的长度,4byte
//	return 0;
//}


//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1] 等价于 *(ptr1 - 1)	4
//									 //小端存储,01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//									 //访问 00 00 00 02	小端存储还原 0x02000000		
//	return 0;
//}


#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };// () 不是 {} ,所以实际存储{1,3,5}
//	int* p;
//	p = a[0];//a[0]首行地址,数组指针,数值为首行首元素地址,赋值给 int* 类型指针,需要强制类型转换
//	printf("%d", p[0]);//p[0] <==> *(p +0),	1
//	return 0;
//}


//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//&p[4][2] ==> &(*(*(p + 4) +2)), 
//	//p数组指针,int(*)[4]移动单位长度4个int   ==>  +  4*4 byte
//	//*(p + 4)数组指针解引用得数组名,一维数组名,首元素地址,int*
//	//*(p + 4) +2		==>  + 2  byte
//	//p移动18byte
//	
//	//&a[4][2] ==> &(*(*(a + 4) +2))
//	//a数组指针,int(*)[5],移动单位长度5个int   ==>  +  4*5 byte
//	//*(a + 4)数组指针解引用得数组名,一维数组名,首元素地址,int*
//	//*(a + 4) +2		==>  + 2  byte
//	//p移动22byte
//
//	//-4
//	// 10000000000000000000000000000100原码
//	// 11111111111111111111111111111011反码
//	// 11111111111111111111111111111100补码
//	
//	//结论:FFFF FFFC,-4
//	return 0;
//}


//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa,aa表示整个数组,二维数组指针,移动10 int长度
//	int* ptr2 = (int*)(*(aa + 1));//aa表示首行数组指针,一维数组指针,移动5 int长度
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}


#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;//pa = pa +1,移动char**长度, 4byte.
//	printf("%s\n", *pa);//"at"		打印at
//	return 0;
//}


//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT		cpp = &cp[1]
//	printf("%s\n", *-- * ++cpp + 3);//ER	cpp = &cp[2]	cp[2] = c
//	printf("%s\n", *cpp[-2] + 3);//ST		cpp = &cp[2]	*cpp[-2] ==> *(*(cpp - 2))
//	printf("%s\n", cpp[-1][-1] + 1);//EW	cpp[-1][-1] ==> *(*(cpp -1) -1) ; *(cpp -1) => *cp[1] => c + 2
//	return 0;
//}
////总结:指针题目画图求解,逐级揭破
