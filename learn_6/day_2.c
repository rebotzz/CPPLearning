#define _CRT_SECURE_NO_WARNINGS

//自定义类型详解(结构体+枚举+联合)学习 2

//不完全声明,只能声明一次,在声明时创建变量,不然之后就创建不了这种结构体变量了
#include <stdio.h>

//struct
//{
//	int a;
//	char b[5];
//	float c;
//}x;
//struct
//{
//	int a;
//	char b[5];
//	float c;
//}arr[3],*p;
//
//int main()
//{
//	p = &x;//这里其实不行,因为编译器会把 x , *p 认为是不同的结构体类型.
//	printf("%p\n", p);
//	return 0;
//}


//结构体的自引用	类似链表
#include <stdio.h>
//struct n1
//{
//	int a;
//	struct n1* pn1;//相同类型结构体的指针
//};
//
//typedef struct n2
//{
//	int a;
//	str_n2* next;
//}str_n2;//类型重定义

//结构体初始化
#include <stdio.h>
//struct point
//{
//	int x;
//	int y;
//}m1 = {2,5};
//struct node
//{
//	int a;
//	struct point m2;//嵌套
//	struct node* pn;//自引用
//}node1 = {5,{4,9},NULL};
//
//struct node node2 = { 8,{4 ,6},NULL };//嵌套初始化
//
//struct tag
//{
//	int line;
//	int id[5];
//	char name[7];
//	struct point xy;
//};
//struct tag book = { 1,{1,2,3,4},"book 1",{5,4} };


//结构体的大小计算	结构体内存对齐
//visual stdio结构体默认对齐数 8 ,linux没有默认对齐数
//对齐数能提高内存访问效率,确保符合别的平台内存访问数据==>内存每次访问几个字节
//利用 #pragma pack(4) 修改默认对齐数 #pragma pack() 还原系统默认对齐数
//大小计算规则:
//1.结构体首元素放在地址0偏移位置.
//2.其余元素 ==> 放在地址偏移量是它的对齐数的整数倍的位置.
//对齐数 ==> 元素所占的字节大小与默认对齐数两者之间的较小值.
//3.结构体嵌套定义 ==> 所嵌套的结构体对齐数是其元素的最大对齐数.嵌套的结构体对齐到自己的最大对齐数的整数倍处
//4.结构体整体大小 ==> 整体所占大小是结构体元素对齐数中最大对齐数的整数倍
//计算方法  画图
//设计结构体原则:让占用空间小的成员尽量集中在一起。
#include <stdio.h>

//int main()
//{
//	//练习1
//	struct S1
//	{			//字节大小	默认对齐数	对齐数	地址偏移
//		char c1;//1			8			1		0
//		int i;  //4			8			4		4
//		char c2;//1			8			1		8
//				//总大小 9,最大对齐数 4 ,对齐后大小	12
//	};
//	printf("%d\n", sizeof(struct S1));//12
//
//
//	//练习2
//	struct S2
//	{			//字节大小	默认对齐数	对齐数	地址偏移
//		char c1;//1			8			1		0
//		char c2;//1			8			1		1
//		int i;	//4			8			4		4
//	};			//总大小 8,最大对齐数 4 ,对齐后大小	8
//	printf("%d\n", sizeof(struct S2));//8
//
//
//	//练习3
//	struct S3
//	{			 //字节大小	默认对齐数	对齐数	地址偏移
//		double d;//8			8			8		0
//		char c;	 //1			8			1		8
//		int i;	 //4			8			4		12
//	};			 //总大小 16,最大对齐数 8 ,对齐后大小	16
//	printf("%d\n", sizeof(struct S3));//16
//
//
//	//练习4-结构体嵌套问题
//	struct S4
//	{				 //字节大小	默认对齐数	对齐数	地址偏移
//		char c1;	 //1			8			1		0
//		struct S3 s3;//16(对齐数8)	*	  对齐数8		8
//		double d;	 //8			8			8		24
//	};				 //总大小 32,最大对齐数 8 ,对齐后大小	32
//	printf("%d\n", sizeof(struct S4));//32
//
//
//	//设计结构体原则:让占用空间小的成员尽量集中在一起。
//	struct S5
//	{
//		char a;
//		char b;
//		char c[2];
//		int d;
//		double e;
//	};
//	printf("%d\n", sizeof(struct S5));//16
//
//
//	//修改默认对齐数
//#pragma pack(1)
//	struct S6
//	{
//		char a;
//		int b;
//		char c;
//	};
//	printf("%d\n", sizeof(struct S6));
//#pragma pack(4)
//	struct S7
//	{
//		char a;
//		double b;
//		double c;
//	};
//	printf("%d\n", sizeof(struct S7));
//#pragma pack()
//	struct S8
//	{
//		char a;
//		double b;
//		double c;
//	};
//	printf("%d\n", sizeof(struct S8));
//
//
//	return 0;
//}



//百度笔试题：
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察： offsetof 宏的实现
//注：这里还没学习宏，可以放在宏讲解完后再实现。
#include <stdio.h>

//int offsetof(void* p1, void* p2)
//{
//	return (char*)p2 - (char*)p1;
//}
//int main()
//{
//	struct S1
//	{
//		int a;
//		char b;
//		double c;
//	}s1;
//	int ret = offsetof(&s1, &(s1.a));
//	printf("%d\n", ret);
//	ret = offsetof(&s1, &(s1.b));
//	printf("%d\n", ret);
//	ret = offsetof(&s1, &(s1.c));
//	printf("%d\n", ret);
//	return 0;
//}



//结构体传参
//函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。
//如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。
//结构体所占数据可能过大,而局部变量在栈区创建,栈空间有限
//传递数值,数据过大传得慢,且不能修改参数
//所以,优先采用传递地址
#include <stdio.h>

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //传结构体
//	print2(&s); //传地址
//	return 0;
//}


//位段概念
//位段的声明和结构是类似的，有两个不同：
//1.位段的成员必须是 int、unsigned int 或signed int 或者 char。
//2.位段的成员名后边有一个冒号和一个数字。
//位段的内存分配
//1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
//2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
//3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
//大小计算 ==> 按照类型开辟4个字节（ int ）或者1个字节（ char ）
// ":"后面的数值表示占几个bit
//在visual stdio平台,存放规则: 在一个字节(8bit)中,先放在低bit序号位置,如果后面空间足够,依次后放,不够,则...
//不同版本VS似乎规则不一样,这里的int类型,不够也接着放,剩下的放在后面

//位段的跨平台问题
//1. int 位段被当成有符号数还是无符号数是不确定的。
//2. 位段中最大位的数目不能确定。（16位机器最大16，32位机器最大32，写成27，在16位机
//器会出问题。
//3. 位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义。
//4. 当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是
//舍弃剩余的位还是利用，这是不确定的。
#include <stdio.h>

//int main()
//{
//	struct S1
//	{
//		char a : 3;//0000 0AAA
//		char b : 2;//000B BAAA
//		char c : 6;//(000B BAAA)  (00CC CCCC)   
//		int d : 4; //(000B BAAA)  (00CC CCCC) (对齐) (对齐) (0000 DDDD) (0000 0000) (0000 0000) (0000 0000)
//		int e : 10;//(000B BAAA)  (00CC CCCC) (对齐) (对齐) (EEEE DDDD) (00EE EEEE) (0000 0000) (0000 0000)
//	};
//	struct S1 s = { 0b111,0b00,0b111111,0b0000,0b1111111111 };
//
//	struct A
//	{
//		int _a : 2;
//		int _b : 5;
//		int _c : 10;
//		int _d : 30;
//	}aa = {0b11,0b00000,0b1111111111,0x010000};
//
//
//	return 0;
//}


//枚举类型
//枚举常量,默认从0开始，一次递增1，当然在定义的时候也可以赋初值。
//枚举的优点：
//1. 增加代码的可读性和可维护性
//2. 和#define定义的标识符比较枚举有类型检查，更加严谨。
//3. 防止了命名污染（封装）
//4. 便于调试
//5. 使用方便，一次可以定义多个常量
#include <stdio.h>

//enum colour	
//{
//	RED,//0		默认从0开始		//枚举常量之间用 "," 分隔
//	BLUE,//1
//	GREEN//2
//}red = RED;
//
//enum day
//{
//	MON = 1,//1		数值依次递增,可以看做int,枚举常量
//	TUES = 3,//3
//	WEN,//4
//	THUR,//5
//	FRI,//6
//	SAT = 10,//10
//	SUN//11
//};
//
//int main()
//{
//	enum colour blue = BLUE, gre = GREEN;
//	enum day d1 = MON, d2 = TUES, d3 = WEN, d4 = THUR;
//	enum day d5 = FRI;
//	enum day d6 = SAT, d7 = SUN;
//	printf("%d %d %d \n%d %d %d %d %d %d %d\n", red, blue, gre, d1, d2, d3, d4, d5, d6, d7);
//	return 0;
//}

//应用,在通讯录部分



//联合(联合体,共用体)
//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）。
//联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小
//（因为联合至少得有能力保存最大的那个成员）。
//联合大小的计算:
//联合的大小至少是最大成员的大小。
//当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。

#include <stdio.h>

////联合体声明
//union A
//{
//	char a;
//	int b;
//};
//
//union Un
//{
//	int i;
//	char c;
//};
//union Un uc;
//
//int main()
//{
//	//联合体变量创建,初始化
//	union A un = { 0 };
//	//大小计算,共用一块内存空间
//	//printf("%d\n", (int)sizeof(un));
//	//scanf("%c", &(un.a));
//	//printf("%c %d\n", un.a,un.b);
//	//scanf("%d", &(un.b));
//	//printf("%c &d\n", un.a,un.b);
//
//	// 下面输出的结果是一样的吗？
//	printf("%d\n", &(uc.i));
//	printf("%d\n", &(uc.c));
//	//下面输出的结果是什么？
//	uc.i = 0x11223344;
//	uc.c = 0x55;
//	printf("%x\n", uc.i);
//
//
//	return 0;
//}


//union Un1
//{				//大小(嵌套对齐数)												默认对齐数		对齐数	
//	char c[5];//5(数组,我认为类型结构体嵌套,可能是其内部最大对齐数作为对齐数,1) 	8	==>		1
//	int i;//4	8	==>4
//};
//union Un2
//{				//大小(嵌套对齐数)		默认对齐数		对齐数	
//	short c[7];//14							8		==>	14
//	int i;	   //4							8		==>	4
//};
//int main()
//{
//	//下面输出的结果是什么？
//	printf("%d\n", sizeof(union Un1));//8
//	printf("%d\n", sizeof(union Un2));//16
//	return 0;
//}
