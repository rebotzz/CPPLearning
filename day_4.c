#define _CRT_SECURE_NO_WARNINGS


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
#include <stdio.h>

//int main()
//{
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
//	return 0;
//}


















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