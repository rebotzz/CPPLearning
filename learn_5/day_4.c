#define _CRT_SECURE_NO_WARNINGS

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
//	return 0;
//}


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
