#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
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


=======

//文件操作学习 

// #include <stdio.h> 库
// fopen	打开文件,返回 FILE* ,"r" "w" "a" "rb" "wb" "ab" "w+",不同方式打开文件可执行操作不同
// fclose	关闭文件,防止资源浪费,可打开文件数目存在限制
// FILE*   NULL 判空
// fgetc	读取一个字符,返回 int			fgetc(pf);
// fputc	写入一个字符					fputc('字符',pf);
// fgets	读取指定个字符串,返回 char*		fgets(char* str,个数包含'\0',FILE* pf);
// fputs	写入字符串						fputs(char* str,FILE* pf);
// fscanf	读取格式化文本,与scanf类似,只不过第一个参数是所有流,记得取地址 fscanf(stdin,"",&);
// fprintf	写入格式化文本,与printf类似,只不过第一个参数是所有流	fprintf(stdout,"",);
// fread	读取二进制文件		fread(void* ptr,元素大小,元素数量,FILE* pf);
// fwrite	写入二进制文件		fwrite(void* ptr,元素大小,元素数量,FILE* pf);
// sscanf	从字符串中读取格式化文本	sscanf(char* buff,"",&);
// sprintf	将格式化文本写入字符串		sprintf(char* buff,"",);
// fseek	文件地址偏移函数			fseek(pf,偏移量,起始点)
// ftell	返回目前文件地址偏移		ftell(pf);返回long int
// rewind  ==>这个不是 f 开头	地址初始化为起始地址	rewind(pf);
// feof		判断文件读取结束是因为读取到EOF还是别的原因结束,正常结束(EOF),返回ture
// ferror	判断文件读取是否发生错误,有,则返回ture
// fflush	刷新文件缓存区	fflush(pf);

//练习熟练
>>>>>>> w6/main
#include <stdio.h>

//int main()
//{
<<<<<<< HEAD
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
=======
//	//文件打开
//	//FILE* pf = fopen("test.txt", "r");//只读
//	FILE* pf = fopen("test.txt", "w+");//读写
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//文件使用
//	char str[] = "hello world.";
//	//int i = 0;
//	//while (fputc(str[i++],pf))//fputc返回值:成功,返回写入字符的ASCII值,失败,返回EOF
//	//{
//	//	;
//	//}
//	fprintf(pf,"%s", str);
//
//	printf("%ld\n", ftell(pf));//打印文件指针与起始位置的偏移量.
//	rewind(pf);//使文件指针回到初始位置.
//	printf("%ld\n", ftell(pf));//打印文件指针与起始位置的偏移量.
//	int c = 0;
//	while ((c = fgetc(pf)) != EOF)//fgetc返回值:成功,返回读取字符的ASCII值,失败,返回EOF
//	{
//		putchar(c);
//	}
//
//	//文件关闭
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

typedef struct A
{
	int a;
	char b[10];
	double c;
}stc_A;
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//注意 \\ 双反斜杠
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	stc_A cd = { 10,"this is 2",2.5f };
//	stc_A tmp = { 0 };
//	//fwrite(&cd, sizeof(stc_A), 1, pf);
//	//fflush(pf);//刷新文件缓存区.刷新后还是没有,但是关闭文件再次读取有了.//推测原因:与fopen参数有关 "wb+" "rb"
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	//fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//	printf("%d %s %f\n", cd.a, cd.b, cd.c);
//	printf("%d %s %f\n", tmp.a, tmp.b, tmp.c);//失败原因推测,数据在文件缓存区没有写入.
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////写入二进制文件
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//注意 \\ 双反斜杠
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////读取二进制文件
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//注意 \\ 双反斜杠
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	stc_A cd = { 0 };
//	fread(&cd, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", cd.a, cd.b, cd.c);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//这一次写入,读取都成功
//总结:fopen参数决定打开文件形式."wb" "rb"各自一次
// 或与可以在一个函数中用,打开文件关闭后换另一种方式打开
//


////综合
//int main()
//{
//	//打开文件	二进制写入
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//注意 \\ 双反斜杠
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//关闭文件
//	fclose(pf);//关闭文件后,文件缓存区的数据写入文件
//	pf = NULL;
//
//	//打开文件	二进制读取
//	pf = fopen("D:\\Desktop\\test.bin", "rb");//注意 \\ 双反斜杠
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	stc_A tmp = { 0 };
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
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
=======
















///* fseek example */
//#include <stdio.h>
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}


///* ftell example : getting size of a file */
//#include <stdio.h>
//int main()
//{
//    FILE* pFile;
//    long size;
//    pFile = fopen("example.txt", "rb");
//    if (pFile == NULL)
//    {
//        perror("Error opening file");
//        return 1;
//    }
//    else
//    {
//        fseek(pFile, 0, SEEK_END);   // non-portable
//        size = ftell(pFile);
//        fclose(pFile);
//        printf("Size of example.txt: %ld bytes.\n", size);
//    }
//    return 0;
//}



///* rewind example */
//#include <stdio.h>
//int main()
//{
//    int n;
//    FILE* pFile;
//    char buffer[27];
//    pFile = fopen("myfile.txt", "w+");
//    for (n = 'A'; n <= 'Z'; n++)
//        fputc(n, pFile);
//    rewind(pFile);
//    fread(buffer, 1, 26, pFile);
//    fclose(pFile);
//    buffer[26] = '\0';
//    puts(buffer);
//
//    return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "w");
//	fprintf(pf,"%d",a);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
//int main(void)
//{
//    int c; // 注意：int，非char，要求处理EOF
//    FILE* fp = fopen("test.txt", "r");
//    if (!fp) {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//    {
//        putchar(c);
//    }
//    //判断是什么原因结束的
//    if (ferror(fp))
//        puts("I/O error when reading");
//    else if (feof(fp))
//        puts("End of file reached successfully");
//    fclose(fp);
//}



//#include <stdio.h>
//enum { SIZE = 5 };
//int main(void)
//{
//    double a[SIZE] = { 1.,2.,3.,4.,5. };
//    FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式
//    fwrite(a, sizeof * a, SIZE, fp); // 写 double 的数组    //sizeof * a ==>*a是数据的内存大小，也就是数据的存储类型大小
//    fclose(fp);                                             //这里a元素类型是double,所以等价于sizeof(double)
//    double b[SIZE];
//    fp = fopen("test.bin", "rb");
//    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // 读 double 的数组
//    if (ret_code == SIZE) {
//        puts("Array read successfully, contents: ");
//        for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
//        putchar('\n');
//    }
//    else { // error handling
//        if (feof(fp))
//            printf("Error reading test.bin: unexpected end of file\n");
//        else if (ferror(fp)) {
//            perror("Error reading test.bin");
//        }
//    }
//    fclose(fp);
//}



//文件缓冲区
//#include <stdio.h>
//#include <windows.h>
////VS2013 WIN10环境测试
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//先将代码放在输出缓冲区
//	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//	//注：fflush 在高版本的VS上不能使用了
//	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	fclose(pf);
//	//注：fclose在关闭文件的时候，也会刷新缓冲区
//	pf = NULL;
//	return 0;
//}


//fgets fputs
//int main()
//{
//	//打开文件 写
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "w");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	char str[] = " hehe";
//	fputs("bit", pf);
//	int m = fputs(str, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件 读
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "r");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用文件
//	char arr[30] = { 0 };
//	char* ret = fgets(arr, 9,pf);//读取大小包括 '\0'
//	if (ret)
//	{
//		if (feof)
//		{
//			printf("feof\n");
//		}
//		else if(ferror)
//		{
//			printf("ferror\n");
//		}
//		puts(ret);
//	}
//	printf("偏移:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_SET);//文件指针地址偏移
//	printf("偏移:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_END);
//	printf("偏移:%d\n", ftell(pf));
//	fseek(pf, -2, SEEK_CUR);
//	printf("偏移:%d\n", ftell(pf));
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////sscanf 别忘了取地址 sprintf 把格式化数据存入字符串
//struct B
//{
//	int a;
//	char b[10];
//	double c;
//};
//int main()
//{
//	int buff[60] = { 0 };
//	struct B m = { 3,"asdf",5.3f };
//	sprintf(buff, "%d %s %lf", m.a, m.b, m.c);
//
//	struct B n = {0};
//	sscanf(buff, "%d %s %lf", &(n.a), n.b, &(n.c));//当作scanf用,只不输入不是stdin,而是字符串.需要取地址
//	printf("%d %s %lf\n", n.a, n.b, n.c);
//	printf("*************\n");
//	printf(buff);
//
//
//	return 0;
//}
>>>>>>> w6/main
