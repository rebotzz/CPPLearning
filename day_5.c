#define _CRT_SECURE_NO_WARNINGS

//程序环境和预处理 学习

// 源文件test.c  ==>  目标文件test.obj   ==>  可执行文件test.exe	==>	执行结果
//						集成开发环境				执行环境
//			编译器					链接器
//	预编译  编译	汇编			 链接					
// 预编译:1.#include头文件的包含	2.#define的完全替换		3.注释的删除		gcc -test.c -E > test.i
// 编译:将代码转化为汇编代码.	1.语法分析 2.词法分析 3.语义分析 4.符号汇总		gcc -test.c -S > test.s
// 汇编:将汇编代码转化为二进制的机器指令.	生成符号表							gcc -test.c -c > test.o
// 编译器把源文件test.c ==> 目标文件test.obj 
// 
// 链接:把多个目标文件进行链接. 1.段表的合并 2.符号汇总和重定位(比如函数的声明,定义,函数名指向函数地址,是符号)
// 链接器把多个目标文件test.obj与链接库链接  ==>  可执行文件test.exe
//
// 注意:头文件反复包含
// 解决方法:1.#pragma once	
//			2.#ifndef	#define		#endif
// 
// #define 是完全替换	替换符号或者定义宏		\ 续行符号
// 优缺点:
// 1.替换内容少时执行效率高
// 2.可以使用 # ## ,#将变量名转化为字符串			##链接变量名.可以把位于它两边的符号合成一个符号。
//					#把一个宏参数变成对应的字符串	##它允许宏定义从分离的文本片段创建标识符。
//													##这样的连接必须产生一个合法的标识符。否则其结果就是未定义的。
// 3.不用指定具体类型
// 4.是替换,不是调用,会增加代码长度
// 注意:
// 1.需要用括号括起来,结和性和优先级问题,毕竟完全替换,防止出错
// 2.有++,--时容易改变原来数值,带有副作用,易出错
// 3.与函数不同,内部表达式不计算,直接替换
// 4.不能调试,不能递归
// 5.建议末尾别加 ; 不然也会替换
// 6.好习惯:把宏名全部大写,函数名不要全部大写
// 
// #include <>直接从标准库位置中寻找	""从当前文件寻找,如果没有,再去标准库位置寻找
// 
// 条件编译		可以嵌套
// 调试性的代码，删除可惜，保留又碍事，所以我们可以选择性的编译。
// #if	常量表达式	true则编译,直到#endif
// #elif		相当于else if
// #else		相当于else
// #endif	条件编译末尾
// #ifndef	#if !defined(宏名字)	如果没有定义,则编译
// #ifdef	#if defined(宏名字)		如果定义了,则编译
// #undef	取消宏定义
// 
// 命令行定义
// 许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。
// 例如：当我们根据同一个源文件要编译出不同的一个程序的不同版本的时候，这个特性有点用处。
// 
// 
//  预定义符号
//  __FILE__      //进行编译的源文件
//	__LINE__     //文件当前的行号
//	__DATE__    //文件被编译的日期
//	__TIME__    //文件被编译的时间
//	__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义
// 
//


//练习熟练
#include "stdio.h"
#include <stdlib.h>
#define M 100
#define ADD(x,y) ((x)+(y))
#define MUL(x,y) ((x)*(y))
#define MALLOC(x,y) (y*)malloc(x*sizeof(y))

//int main()
//{
//	int ret = ADD(M, 5 * 2);
//	printf("%d\n", ret);
//	ret = MUL(5 + 1, 3 + 2);
//	printf("%d\n", ret);
//
//	//开辟空间
//	//int* p = (int*)malloc(sizeof(int));
//	int* p = MALLOC(1, int);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	//使用空间
//	*p = ret + 1;
//	printf("%d\n", *p);
//	//关闭空间
//	free(p);
//	p = NULL;
//
//	printf("hehe\n");
//	return 0;
//}

//#define __FLAG_CODE_ 1
//#define TAG 3
//int main()
//{
//#if __FLAG_CODE_
//	printf("hehe %d\n",TAG);
//#endif
//
//#if 0
//	//测试代码
//	printf("test code.\n");
//#endif
//
//#ifndef FIRST__
//#define FIRST__
//	#ifdef TAG
//	#undef TAG
//	printf("嵌套,条件编译\n");
//	#endif
//#endif
//
//	printf("end.\n");
//	return 0;
//}



//int main()
//{
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//
//	return 0;
//}


////# ##使用
//#define PRINT(name,format) printf("the value of "#name" is "format"\n",name)
//#define LINKNAME(left,right) left##right
//
//int main()
//{
//	int a = 4;
//	char b = 'c';
//	float c = 5.2f;
//	int ab = a + b;
//
//	//printf("the value of a is %d\n", a);
//	//printf("the value of b is %c\n", b);
//	//printf("the value of c is %f\n", c);
//
//	PRINT(a, "%d");
//	PRINT(b, "c");
//	PRINT(c, "%f");
//
//	PRINT(LINKNAME(a, b), "%d");
//
//	printf("%d\n", LINKNAME(a, b));
//	printf("%d\n", 'c');
//
//	return 0;
//}









//【题目名称】
//交换奇偶位
//【题目内容】
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//整数二进制32位 拿出奇数位,偶数位,奇数位左移一位,偶数位右移一位,按位或
#include <stdio.h>

////1.0	程序
////交换
//void swap_bin(int* const a)
//{
//	int i = 0x55555555;//0b01010101010101010101010101010101  ==>  0x55555555
//	int s = (*a) & i;//奇数位
//	i = i << 1;		//0b10101010101010101010101010101010
//	int d = (*a) & i;//偶数位
//	*a = (s << 1) | (d >> 1);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%p\n", a);
//	swap_bin(&a);
//	printf("%p\n", a);
//	return 0;
//}


////2.0	宏
//#define SWAP_BIN(x) ((((x)&0x55555555)<<1) |(((x)&0xaaaaaaaa)>>1))
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%p\n", a);
//	a = SWAP_BIN(a);
//	printf("%p\n", a);
//	return 0;
//}


//【题目名称】
//offsetof宏
//【题目内容】
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察：offsetof宏的实现
#include <stdio.h>

//struct A
//{
//	char a;
//	int b;
//	double c;
//};
//
//////1.0	函数
////int offsetof(void* set,void* end)
////{
////	return (char*)end - (char*)set;
////}
////
////int main()
////{
////	struct A m = { 0 };
////	printf("%d\n", offsetof(&m,&m.a));
////	printf("%d\n", offsetof(&m, &m.b));
////	printf("%d\n", offsetof(&m, &m.c));
////
////	return 0;
////}
//
////2.0	宏
////#define OFFSETOF(x,y) (size_t)((char*)(&y) - (char*)(&x))
////x结构体变量名,y结构体成员名(需要点).取地址,将类地址型强制转换位char*,地址相减得到偏移字节个数.类型强制转换为size_t
//
////参考宏
////#define offsetof(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName)
////StructType是结构体类型名，MemberName是成员名。具体操作方法是：
////1、先将0转换为一个结构体类型的指针，相当于某个结构体的首地址是0。此时，每一个成员的偏移量就成了相对0的偏移量，这样就不需要减去首地址了。
////2、对该指针用->访问其成员，并取出地址，由于结构体起始地址为0，此时成员偏移量直接相当于对0的偏移量，所以得到的值直接就是对首地址的偏移量。
////3、取出该成员的地址，强转成size_t并打印，就求出了这个偏移量。
//
////3.0	宏
////#define OFFSETOF(StructName, MenberName) (size_t)((char*)(&(StructName.MenberName)) - (char*)(&StructName))
////#define OFFSETOF(x,y) (size_t)((char*)(&x.y) - (char*)(&x))
//
////4.0	宏
//#define offsetof(StructType,MenberName) (size_t)&(((StructType*) 0)->MenberName)
////#define offsetof(StructType,MenberName) (size_t)&(((StructType*) 0x500)->MenberName) - 0x500
// //就是一个相对关系
//
//int main()
//{
//	struct A m = { 0 };
//	//printf("%d\n", OFFSETOF(m,m.a));
//	//printf("%d\n", OFFSETOF(m,m.b));
//	//printf("%d\n", OFFSETOF(m,m.c));
//
//	//printf("%d\n", offsetof(struct A,a));
//	//printf("%d\n", offsetof(struct A,b));
//	//printf("%d\n", offsetof(struct A,c));
//
//	//printf("%d\n", OFFSETOF(m, a));
//	//printf("%d\n", OFFSETOF(m, b));
//	//printf("%d\n", OFFSETOF(m, c));
//
//	printf("%d\n", offsetof(struct A,a));
//	printf("%d\n", offsetof(struct A,b));
//	printf("%d\n", offsetof(struct A,c));
//
//	return 0;
//}


