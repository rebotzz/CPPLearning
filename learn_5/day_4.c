#define _CRT_SECURE_NO_WARNINGS

//指针进阶学习 1

////指针:
//char* p1;//一级指针,(存一块内存空间的首地址).访问1 byte,最低1 byte,所以强制类型转换为char* 很有用
//int* p2;//访问4 byte
//float* p3;//访问4 byte
//char** p5 = &p1;//二级指针,指向一级指针,将一级指针的地址存储到二级指针变量
//char*** p6 = &p5;//三级指针
//int(*p4)[5];//数组指针,int(*)[5]是指针类型,p4是指针变量名称,指向有5个元素的数组,数组中的每个元素是int 
//char* arr[4];//指针数组,数组4个元素,每个元素类型为char*
//char** parr = arr;//数组名,首元素地址,首元素是char*指针,指向一个指针,(存一级指针的地址)二级指针.
//char** parr = &arr[0];//[]结和性优先于&
//char* (*parr1)[4] = &arr;//&arr是取数组的地址,类型是数组指针.arr是数组首元素的地址类型是二级字符型指针.访问权限不一样,步长不同
//char** arr1[4] = { arr };
//int(*parr1[4])[6];  //去掉名字看类型,parr1[4]与[]的结合优先级更高,所以是数组.
//					  //int(*)[6];数组的每个元素类型是数组指针,指针指向有6个元素的数组,每个元素类型为int.
//void* p7;           //空指针,什么类型的指针都可以放,但是就像一个垃圾桶,
//					  //使用时必须先强制类型转换为需要的类型.以确定访问权限,加减整数步长
//int (*pf)(int, int);//函数指针,指向一个函数.函数名 == 指针.int (*)(int, int)是指针类型.
//					  //pf是指针变量名字,指向一个函数,函数参数类型是两个int,函数返回类型是int .
//int (*pfarr[2])(void*, int*);//pfarr[2]先结合,数组.
////int (*)(void*, int*),数组元素类型,函数指针,指向一个函数参数为void* ,int*;返回类型int


#include <stdio.h>

//int main()
//{
//	printf("%d \n", sizeof(long));
//	printf("%d \n", sizeof(unsigned long));
//
//	return 0;
//}


#include <stdio.h>

//int main()
//{
//	const char* ptr = "hello bit.";//常量字符串,首元素地址赋值给ptr,const修后*ptr,指向元素不能改.
//	printf("%s\n", ptr);
//
//	return 0;
//}

#include <stdio.h>
//数组名,分为三种情况.  
//1.sizeof(只有数组名arr),arr代表怎个数组
//2.&数组名arr,arr代表怎个数组,取出的是怎个数组的地址,数组指针,char(*)[]
//3.其他情况,数组名arr 代表数组首元素的地址

//C / C++会把常量字符串存储到单独的一个内存区域
//常量字符串,由于两个常量字符串的内容相同,且没有放入不同的变量(内存空间),在内存中有一块空间存放"hello bit."
//为了节省空间,两个相同的常量字符串就存一个,所以,str3,str4都是指向内存中同一个地址.常量字符串首元素'h'地址.

//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    const char* str3 = "hello bit.";
//    const char* str4 = "hello bit.";
//    if (str1 == str2)  //两个指针变量,在内存中开辟的空间不同,地址不同.                    
//        printf("str1 and str2 are same\n");
//    else                                   
//        printf("str1 and str2 are not same\n");//不同
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");//相同
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}



#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//&arr是取数组的地址,类型是数组指针.arr是数组首元素的地址类型是二级字符型指针.访问权限不一样,步长不同
//	printf("arr = %p\n", arr);//类型int*
//	printf("&arr= %p\n", &arr);//类型int (*) [10]
//	printf("arr+1 = %p\n", arr + 1);//前进一个元素,4byte
//	printf("&arr+1= %p\n", &arr + 1);//前进一个数组,40byte
//	return 0;
//}

#include <stdio.h>
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//    int(*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p
//    //但是我们一般很少这样写代码
//    return 0;
//}


#include <stdio.h>
////数组指针的使用
//void print_arr1(int arr[3][5], int row, int col)
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        int j = 0;
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//            printf("\n");
//    }
//}
//void print_arr2(int(*arr)[5], int row, int col)//arr是数组指针,所以用数组指针类型来接受int(*)[5]
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        int j = 0;
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", *(*(arr + i) + j));//arr第一行数组指针,*(arr+i)第i行数组,数组用数组名表示,即arr[i],第i行数组名.
//                            //arr类型为int(*)[5], +i前进 i个数组长度(5个int)
//                            //数组名除了两种特殊情况(sizeof(),&),其余代表首元素地址.类型为int*
//                            //*(*(arr+i)+j)  ==>*(arr[i] +j)  ==> arr[i][j]
//                            //arr[i]类型为int* , +j前进j个int长度
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    print_arr1(arr, 3, 5);
//    //数组名arr，表示首元素的地址   
//    //但是二维数组的首元素是二维数组的第一行   {1,2,3,4,5}
//    //所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
//    //可以数组指针来接收
//    print_arr2(arr, 3, 5);
//    return 0;
//}


//int arr[5];//数组
//int* parr1[10];//指针数组
//int(*parr2)[10];//数组指针
//int(*parr3[10])[5];//parr3[10]数组,数组元素为:int(*)[5]数组指针类型

//数组传参
#include <stdio.h>

//void test(int arr[])//ok,传递数组,一维数组可省略
//{}
//void test(int arr[10])//ok,传递数组
//{}
//void test(int* arr)//ok,传递指针,首元素地址
//{}
//void test2(int* arr[20])//ok,传递数组
//{}
//void test2(int** arr)//ok,传递指针,首元素地址指向一个一级指针变量,所以类型二级int指针
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}


//void test(int arr[3][5])//ok,传递数组
//{}
//void test(int arr[][])//error,二维数组列不能省略
//{}
//void test(int arr[][5])//ok,传递数组
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int* arr)//error, arr类型int(*)[5],接受类型不匹配
//{}
//void test(int* arr[5])//error,函数参数是指针数组,传递参数arr是数组指针,不匹配
//{}
//void test(int(*arr)[5])//ok,传递地址
//{}
//void test(int** arr)//error,不匹配
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//首元素是首行,arr是首行地址,数组指针,int(*)[5],{0,0,0,0,0}
//}


//一级指针传参
#include <stdio.h>

//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));//*(p + i) 等价于 p[i] 等价于 arr[i]
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	print(p, sz);
//	return 0;
//}


//二级指针传参
#include <stdio.h>

//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	**pp = 20;
//	test(&p);
//	return 0;
//}

//void test(char** p)
//{
//
//}
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	test(&pc);
//	test(ppc);
//	test(arr);//Ok,arr指向首元素地址,首元素是char*类型,所以arr类型为char**
//	return 0;
//}


//函数指针

#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);//函数名 <==> 函数指针(函数地址)
//	printf("%p\n", &test);
//	void (*pf)() = &test;
//	pf();
//	return 0;
//}
