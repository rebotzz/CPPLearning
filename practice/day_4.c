#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
//ָ�����ѧϰ 1

////ָ��:
//char* p1;//һ��ָ��,(��һ���ڴ�ռ���׵�ַ).����1 byte,���1 byte,����ǿ������ת��Ϊchar* ������
//int* p2;//����4 byte
//float* p3;//����4 byte
//char** p5 = &p1;//����ָ��,ָ��һ��ָ��,��һ��ָ��ĵ�ַ�洢������ָ�����
//char*** p6 = &p5;//����ָ��
//int(*p4)[5];//����ָ��,int(*)[5]��ָ������,p4��ָ���������,ָ����5��Ԫ�ص�����,�����е�ÿ��Ԫ����int 
//char* arr[4];//ָ������,����4��Ԫ��,ÿ��Ԫ������Ϊchar*
//char** parr = arr;//������,��Ԫ�ص�ַ,��Ԫ����char*ָ��,ָ��һ��ָ��,(��һ��ָ��ĵ�ַ)����ָ��.
//char** parr = &arr[0];//[]�����������&
//char* (*parr1)[4] = &arr;//&arr��ȡ����ĵ�ַ,����������ָ��.arr��������Ԫ�صĵ�ַ�����Ƕ����ַ���ָ��.����Ȩ�޲�һ��,������ͬ
//char** arr1[4] = { arr };
//int(*parr1[4])[6];  //ȥ�����ֿ�����,parr1[4]��[]�Ľ�����ȼ�����,����������.
//					  //int(*)[6];�����ÿ��Ԫ������������ָ��,ָ��ָ����6��Ԫ�ص�����,ÿ��Ԫ������Ϊint.
//void* p7;           //��ָ��,ʲô���͵�ָ�붼���Է�,���Ǿ���һ������Ͱ,
//					  //ʹ��ʱ������ǿ������ת��Ϊ��Ҫ������.��ȷ������Ȩ��,�Ӽ���������
//int (*pf)(int, int);//����ָ��,ָ��һ������.������ == ָ��.int (*)(int, int)��ָ������.
//					  //pf��ָ���������,ָ��һ������,������������������int,��������������int .
//int (*pfarr[2])(void*, int*);//pfarr[2]�Ƚ��,����.
////int (*)(void*, int*),����Ԫ������,����ָ��,ָ��һ����������Ϊvoid* ,int*;��������int


=======

//�ļ�����ѧϰ 

// #include <stdio.h> ��
// fopen	���ļ�,���� FILE* ,"r" "w" "a" "rb" "wb" "ab" "w+",��ͬ��ʽ���ļ���ִ�в�����ͬ
// fclose	�ر��ļ�,��ֹ��Դ�˷�,�ɴ��ļ���Ŀ��������
// FILE*   NULL �п�
// fgetc	��ȡһ���ַ�,���� int			fgetc(pf);
// fputc	д��һ���ַ�					fputc('�ַ�',pf);
// fgets	��ȡָ�����ַ���,���� char*		fgets(char* str,��������'\0',FILE* pf);
// fputs	д���ַ���						fputs(char* str,FILE* pf);
// fscanf	��ȡ��ʽ���ı�,��scanf����,ֻ������һ��������������,�ǵ�ȡ��ַ fscanf(stdin,"",&);
// fprintf	д���ʽ���ı�,��printf����,ֻ������һ��������������	fprintf(stdout,"",);
// fread	��ȡ�������ļ�		fread(void* ptr,Ԫ�ش�С,Ԫ������,FILE* pf);
// fwrite	д��������ļ�		fwrite(void* ptr,Ԫ�ش�С,Ԫ������,FILE* pf);
// sscanf	���ַ����ж�ȡ��ʽ���ı�	sscanf(char* buff,"",&);
// sprintf	����ʽ���ı�д���ַ���		sprintf(char* buff,"",);
// fseek	�ļ���ַƫ�ƺ���			fseek(pf,ƫ����,��ʼ��)
// ftell	����Ŀǰ�ļ���ַƫ��		ftell(pf);����long int
// rewind  ==>������� f ��ͷ	��ַ��ʼ��Ϊ��ʼ��ַ	rewind(pf);
// feof		�ж��ļ���ȡ��������Ϊ��ȡ��EOF���Ǳ��ԭ�����,��������(EOF),����ture
// ferror	�ж��ļ���ȡ�Ƿ�������,��,�򷵻�ture
// fflush	ˢ���ļ�������	fflush(pf);

//��ϰ����
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
//	const char* ptr = "hello bit.";//�����ַ���,��Ԫ�ص�ַ��ֵ��ptr,const�޺�*ptr,ָ��Ԫ�ز��ܸ�.
//	printf("%s\n", ptr);
//
//	return 0;
//}

#include <stdio.h>
//������,��Ϊ�������.  
//1.sizeof(ֻ��������arr),arr������������
//2.&������arr,arr������������,ȡ��������������ĵ�ַ,����ָ��,char(*)[]
//3.�������,������arr ����������Ԫ�صĵ�ַ

//C / C++��ѳ����ַ����洢��������һ���ڴ�����
//�����ַ���,�������������ַ�����������ͬ,��û�з��벻ͬ�ı���(�ڴ�ռ�),���ڴ�����һ��ռ���"hello bit."
//Ϊ�˽�ʡ�ռ�,������ͬ�ĳ����ַ����ʹ�һ��,����,str3,str4����ָ���ڴ���ͬһ����ַ.�����ַ�����Ԫ��'h'��ַ.

//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    const char* str3 = "hello bit.";
//    const char* str4 = "hello bit.";
//    if (str1 == str2)  //����ָ�����,���ڴ��п��ٵĿռ䲻ͬ,��ַ��ͬ.                    
//        printf("str1 and str2 are same\n");
//    else                                   
//        printf("str1 and str2 are not same\n");//��ͬ
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");//��ͬ
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}



#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//&arr��ȡ����ĵ�ַ,����������ָ��.arr��������Ԫ�صĵ�ַ�����Ƕ����ַ���ָ��.����Ȩ�޲�һ��,������ͬ
//	printf("arr = %p\n", arr);//����int*
//	printf("&arr= %p\n", &arr);//����int (*) [10]
//	printf("arr+1 = %p\n", arr + 1);//ǰ��һ��Ԫ��,4byte
//	printf("&arr+1= %p\n", &arr + 1);//ǰ��һ������,40byte
//	return 0;
//}

#include <stdio.h>
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//    int(*p)[10] = &arr;//������arr�ĵ�ַ��ֵ������ָ�����p
//    //��������һ���������д����
//    return 0;
//}


#include <stdio.h>
////����ָ���ʹ��
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
//void print_arr2(int(*arr)[5], int row, int col)//arr������ָ��,����������ָ������������int(*)[5]
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        int j = 0;
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", *(*(arr + i) + j));//arr��һ������ָ��,*(arr+i)��i������,��������������ʾ,��arr[i],��i��������.
//                            //arr����Ϊint(*)[5], +iǰ�� i�����鳤��(5��int)
//                            //���������������������(sizeof(),&),���������Ԫ�ص�ַ.����Ϊint*
//                            //*(*(arr+i)+j)  ==>*(arr[i] +j)  ==> arr[i][j]
//                            //arr[i]����Ϊint* , +jǰ��j��int����
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    print_arr1(arr, 3, 5);
//    //������arr����ʾ��Ԫ�صĵ�ַ   
//    //���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��   {1,2,3,4,5}
//    //�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
//    //��������ָ��������
//    print_arr2(arr, 3, 5);
//    return 0;
//}


//int arr[5];//����
//int* parr1[10];//ָ������
//int(*parr2)[10];//����ָ��
//int(*parr3[10])[5];//parr3[10]����,����Ԫ��Ϊ:int(*)[5]����ָ������

//���鴫��
#include <stdio.h>

//void test(int arr[])//ok,��������,һά�����ʡ��
//{}
//void test(int arr[10])//ok,��������
//{}
//void test(int* arr)//ok,����ָ��,��Ԫ�ص�ַ
//{}
//void test2(int* arr[20])//ok,��������
//{}
//void test2(int** arr)//ok,����ָ��,��Ԫ�ص�ַָ��һ��һ��ָ�����,�������Ͷ���intָ��
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}


//void test(int arr[3][5])//ok,��������
//{}
//void test(int arr[][])//error,��ά�����в���ʡ��
//{}
//void test(int arr[][5])//ok,��������
//{}
////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
////��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
////�����ŷ������㡣
//void test(int* arr)//error, arr����int(*)[5],�������Ͳ�ƥ��
//{}
//void test(int* arr[5])//error,����������ָ������,���ݲ���arr������ָ��,��ƥ��
//{}
//void test(int(*arr)[5])//ok,���ݵ�ַ
//{}
//void test(int** arr)//error,��ƥ��
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//��Ԫ��������,arr�����е�ַ,����ָ��,int(*)[5],{0,0,0,0,0}
//}


//һ��ָ�봫��
#include <stdio.h>

//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));//*(p + i) �ȼ��� p[i] �ȼ��� arr[i]
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//һ��ָ��p����������
//	print(p, sz);
//	return 0;
//}


//����ָ�봫��
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
//	test(arr);//Ok,arrָ����Ԫ�ص�ַ,��Ԫ����char*����,����arr����Ϊchar**
=======
//	//�ļ���
//	//FILE* pf = fopen("test.txt", "r");//ֻ��
//	FILE* pf = fopen("test.txt", "w+");//��д
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//�ļ�ʹ��
//	char str[] = "hello world.";
//	//int i = 0;
//	//while (fputc(str[i++],pf))//fputc����ֵ:�ɹ�,����д���ַ���ASCIIֵ,ʧ��,����EOF
//	//{
//	//	;
//	//}
//	fprintf(pf,"%s", str);
//
//	printf("%ld\n", ftell(pf));//��ӡ�ļ�ָ������ʼλ�õ�ƫ����.
//	rewind(pf);//ʹ�ļ�ָ��ص���ʼλ��.
//	printf("%ld\n", ftell(pf));//��ӡ�ļ�ָ������ʼλ�õ�ƫ����.
//	int c = 0;
//	while ((c = fgetc(pf)) != EOF)//fgetc����ֵ:�ɹ�,���ض�ȡ�ַ���ASCIIֵ,ʧ��,����EOF
//	{
//		putchar(c);
//	}
//
//	//�ļ��ر�
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
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	stc_A tmp = { 0 };
//	//fwrite(&cd, sizeof(stc_A), 1, pf);
//	//fflush(pf);//ˢ���ļ�������.ˢ�º���û��,���ǹر��ļ��ٴζ�ȡ����.//�Ʋ�ԭ��:��fopen�����й� "wb+" "rb"
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	//fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//	printf("%d %s %f\n", cd.a, cd.b, cd.c);
//	printf("%d %s %f\n", tmp.a, tmp.b, tmp.c);//ʧ��ԭ���Ʋ�,�������ļ�������û��д��.
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////д��������ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////��ȡ�������ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 0 };
//	fread(&cd, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", cd.a, cd.b, cd.c);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��һ��д��,��ȡ���ɹ�
//�ܽ�:fopen�����������ļ���ʽ."wb" "rb"����һ��
// ���������һ����������,���ļ��رպ���һ�ַ�ʽ��
//


////�ۺ�
//int main()
//{
//	//���ļ�	������д��
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//�ر��ļ�
//	fclose(pf);//�ر��ļ���,�ļ�������������д���ļ�
//	pf = NULL;
//
//	//���ļ�	�����ƶ�ȡ
//	pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A tmp = { 0 };
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
//����ָ��

#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);//������ <==> ����ָ��(������ַ)
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
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "w");
//	fprintf(pf,"%d",a);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
//int main(void)
//{
//    int c; // ע�⣺int����char��Ҫ����EOF
//    FILE* fp = fopen("test.txt", "r");
//    if (!fp) {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//    {
//        putchar(c);
//    }
//    //�ж���ʲôԭ�������
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
//    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
//    fwrite(a, sizeof * a, SIZE, fp); // д double ������    //sizeof * a ==>*a�����ݵ��ڴ��С��Ҳ�������ݵĴ洢���ʹ�С
//    fclose(fp);                                             //����aԪ��������double,���Եȼ���sizeof(double)
//    double b[SIZE];
//    fp = fopen("test.bin", "rb");
//    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // �� double ������
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



//�ļ�������
//#include <stdio.h>
//#include <windows.h>
////VS2013 WIN10��������
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//�Ƚ�����������������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	fclose(pf);
//	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//	pf = NULL;
//	return 0;
//}


//fgets fputs
//int main()
//{
//	//���ļ� д
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "w");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	char str[] = " hehe";
//	fputs("bit", pf);
//	int m = fputs(str, pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ� ��
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "r");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	char arr[30] = { 0 };
//	char* ret = fgets(arr, 9,pf);//��ȡ��С���� '\0'
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
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_SET);//�ļ�ָ���ַƫ��
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_END);
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, -2, SEEK_CUR);
//	printf("ƫ��:%d\n", ftell(pf));
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////sscanf ������ȡ��ַ sprintf �Ѹ�ʽ�����ݴ����ַ���
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
//	sscanf(buff, "%d %s %lf", &(n.a), n.b, &(n.c));//����scanf��,ֻ�����벻��stdin,�����ַ���.��Ҫȡ��ַ
//	printf("%d %s %lf\n", n.a, n.b, n.c);
//	printf("*************\n");
//	printf(buff);
//
//
//	return 0;
//}
>>>>>>> w6/main
