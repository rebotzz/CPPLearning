#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
//ָ�����ѧϰ 2


#include <stdio.h>

//int main()
//{
//	//����1
//	(*(void (*)())0)();//(void (*)())����ָ������,����void,����ֵvoid.���������,�ж�Ϊ( )ǿ������ת��.
//					   //�� 0 (NULL��ָ��)ǿ������ת��Ϊ void (*)()����ָ������.����0��ַָ��һ������.
//					   //(*(void (*)())0)������0��ַָ��ĺ�����(��ַ).������();���øú���.
//					   //(*(void (*)())0)();����0��ַָ��ĺ���.
//	//����2
//	void (*signal(int, void(*)(int)))(int);//void (*)(int)ȥ������,���µ�������.����ָ������,��������int,����ֵvoid.
//										   //signal(int, void(*)(int)),����������,����,���ʾһ����Ϊsignal�ĺ���.
//										   //signal�����Ĳ���������int ,void(*)(int)����ָ������.
//										   //�����ķ���ֵ���ʹ����濴,��void (*)(int)����.��������void (*)(int)����ָ������.
//	//�����Ż�
//	typedef void(*pf_void_int)(int);//�����ض���,�� void (*)(int) ������ pf_void_int ��ʾ.
//	pf_void_int signal(int, pf_void_int);
//	return 0;
//}


//����ָ������
//����ָ���������;��ת�Ʊ�
#include <stdio.h>

//int main()
//{
//	int(*pfarr[5])();//����ָ������,pfarr[5],int(*)()Ԫ������
//
//	return 0;
//}


//������

//�˵�
void meun()
{
	printf("*************  ������  ******************\n");
	printf("************* 1.��  2.�� ****************\n");
	printf("************* 3.��  4.�� ****************\n");
	printf("*************    0.exit     *************\n");
	printf("*****************************************\n");
}

//�ӷ�
int add(int x, int y)
{
	return x + y;
}
//����
int sub(int x, int y)
{
	return x - y;
}
//�˷�
int mul(int x, int y)
{
	return x * y;
}
//����
int div(int x,int y)
{
	return x / y;
}
////����2.0
//float div(float x,float y)
//{
//	return x / y;
//}

//1.0	��������,�ظ�������
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		//�˵�
//		meun();
//		printf("���������.\n");
//		scanf("%d" ,&input);
//
//		int x = 0, y = 0;
//		int ret = 0;
//
//		switch(input)
//		{
//		case 1:
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			printf("%d \n", ret);
//			break;
//		case 2:
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			printf("%d \n", ret);
//			break;
//		case 3:
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			printf("%d \n", ret);
//			break;
//		case 4:
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			//ret = div(x, y);
//			//printf("%d \n", ret);
//			printf("%f \n", div((float)x, (float)y));
//			break;
//		case 0:
//			printf("�˳�����.\n");
//			break;
//		default:
//			printf("�������,����������.\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

////2.0	�����Ż�,���ú���ָ��,�ص�����Ӧ��
//int main()
//{
//	int input = 1;
//	int x = 0, y = 0;
//	int ret = 0;
//	//����һ������ָ������,�洢��ͬ���ú���		==> ת�Ʊ�
//	int(*pfun[5])(int, int) = { NULL,add,sub,mul,div };//���������1��ʼ,�����±�� 0, &add �� add �ȼ�.NULL �� 0 �ȼ�.
//	while (input)
//	{
//		//�˵�
//		meun();
//		printf("���������.\n");
//		scanf("%d", &input);
//		if ((input >= 1) && (input <= 4))//��ֹ�������Խ��,����Ұָ��
//		{
//			printf("������������\n");
//			scanf("%d %d", &x, &y);
//			//���ú���
//			ret = pfun[input](x, y);
//			printf("%d \n", ret);
//		}
//		else if(input != 0)
//			printf("ѡ�����,����������.\n");
//	}
//
//	printf("�˳�����.\n");
=======
//���򻷾���Ԥ���� ѧϰ

// Դ�ļ�test.c  ==>  Ŀ���ļ�test.obj   ==>  ��ִ���ļ�test.exe	==>	ִ�н��
//						���ɿ�������				ִ�л���
//			������					������
//	Ԥ����  ����	���			 ����					
// Ԥ����:1.#includeͷ�ļ��İ���	2.#define����ȫ�滻		3.ע�͵�ɾ��		gcc -test.c -E > test.i
// ����:������ת��Ϊ������.	1.�﷨���� 2.�ʷ����� 3.������� 4.���Ż���		gcc -test.c -S > test.s
// ���:��������ת��Ϊ�����ƵĻ���ָ��.	���ɷ��ű�							gcc -test.c -c > test.o
// ��������Դ�ļ�test.c ==> Ŀ���ļ�test.obj 
// 
// ����:�Ѷ��Ŀ���ļ���������. 1.�α�ĺϲ� 2.���Ż��ܺ��ض�λ(���纯��������,����,������ָ������ַ,�Ƿ���)
// �������Ѷ��Ŀ���ļ�test.obj�����ӿ�����  ==>  ��ִ���ļ�test.exe
//
// ע��:ͷ�ļ���������
// �������:1.#pragma once	
//			2.#ifndef	#define		#endif
// 
// #define ����ȫ�滻	�滻���Ż��߶����		\ ���з���
// ��ȱ��:
// 1.�滻������ʱִ��Ч�ʸ�
// 2.����ʹ�� # ## ,#��������ת��Ϊ�ַ���			##���ӱ�����.���԰�λ�������ߵķ��źϳ�һ�����š�
//					#��һ���������ɶ�Ӧ���ַ���	##������궨��ӷ�����ı�Ƭ�δ�����ʶ����
//													##���������ӱ������һ���Ϸ��ı�ʶ����������������δ����ġ�
// 3.����ָ����������
// 4.���滻,���ǵ���,�����Ӵ��볤��
// ע��:
// 1.��Ҫ������������,����Ժ����ȼ�����,�Ͼ���ȫ�滻,��ֹ����
// 2.��++,--ʱ���׸ı�ԭ����ֵ,���и�����,�׳���
// 3.�뺯����ͬ,�ڲ����ʽ������,ֱ���滻
// 4.���ܵ���,���ܵݹ�
// 5.����ĩβ��� ; ��ȻҲ���滻
// 6.��ϰ��:�Ѻ���ȫ����д,��������Ҫȫ����д
// 
// #include <>ֱ�Ӵӱ�׼��λ����Ѱ��	""�ӵ�ǰ�ļ�Ѱ��,���û��,��ȥ��׼��λ��Ѱ��
// 
// ��������		����Ƕ��
// �����ԵĴ��룬ɾ����ϧ�������ְ��£��������ǿ���ѡ���Եı��롣
// #if	�������ʽ	true�����,ֱ��#endif
// #elif		�൱��else if
// #else		�൱��else
// #endif	��������ĩβ
// #ifndef	#if !defined(������)	���û�ж���,�����
// #ifdef	#if defined(������)		���������,�����
// #undef	ȡ���궨��
// 
// �����ж���
// ���C �ı������ṩ��һ���������������������ж�����š���������������̡�
// ���磺�����Ǹ���ͬһ��Դ�ļ�Ҫ�������ͬ��һ������Ĳ�ͬ�汾��ʱ����������е��ô���
// 
// 
//  Ԥ�������
//  __FILE__      //���б����Դ�ļ�
//	__LINE__     //�ļ���ǰ���к�
//	__DATE__    //�ļ������������
//	__TIME__    //�ļ��������ʱ��
//	__STDC__    //�����������ѭANSI C����ֵΪ1������δ����
// 
//


//��ϰ����
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
//	//���ٿռ�
//	//int* p = (int*)malloc(sizeof(int));
//	int* p = MALLOC(1, int);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	//ʹ�ÿռ�
//	*p = ret + 1;
//	printf("%d\n", *p);
//	//�رտռ�
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
//	//���Դ���
//	printf("test code.\n");
//#endif
//
//#ifndef FIRST__
//#define FIRST__
//	#ifdef TAG
//	#undef TAG
//	printf("Ƕ��,��������\n");
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
>>>>>>> w6/main
//
//	return 0;
//}


<<<<<<< HEAD
//ָ����ָ�������ָ��
#include <stdio.h>

//int main()
//{
//	int (*pf)(int);//����ָ��
//	int (*pfarr[5])(int);//����ָ������
//	int(**ppf)(int) = pfarr;//pfarr������,��Ԫ��(����ָ��)�ĵ�ַ,ָ��ĵ�ַ,����ָ��.int(*(*ppf))(int)
//							//ָ��*ppf,ָ����ppf,ָ���Ԫ������int(*)(int)
//							//�ۺ�:int(*(*ppf))(int)	ָ����ָ��������Ԫ�ص�ָ��
//	int(*(*ppfarr)[5])(int) = &pfarr;//&pfarr����ĵ�ַ,������ָ��洢
//									 //Ԫ������		(* ָ����)		[Ԫ�ظ���]
//									 //int(*)(int)   (*ppfarr)		[5]
//									 //�ۺ�: int(*(*ppfarr)[5])(int)	ָ����ָ�������ָ��
=======
////# ##ʹ��
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









//����Ŀ���ơ�
//������żλ
//����Ŀ���ݡ�
//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
//����������32λ �ó�����λ,ż��λ,����λ����һλ,ż��λ����һλ,��λ��
#include <stdio.h>

////1.0	����
////����
//void swap_bin(int* const a)
//{
//	int i = 0x55555555;//0b01010101010101010101010101010101  ==>  0x55555555
//	int s = (*a) & i;//����λ
//	i = i << 1;		//0b10101010101010101010101010101010
//	int d = (*a) & i;//ż��λ
//	*a = (s << 1) | (d >> 1);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%p\n", a);
//	swap_bin(&a);
//	printf("%p\n", a);
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//����ָ��pfun
//	void (*pfun)(const char*) = test;
//	//����ָ�������pfunArr
//	void (*pfunArr[5])(const char* );
//	pfunArr[0] = test;
//	//ָ����ָ������pfunArr��ָ��ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
=======
////2.0	��
//#define SWAP_BIN(x) ((((x)&0x55555555)<<1) |(((x)&0xaaaaaaaa)>>1))
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%p\n", a);
//	a = SWAP_BIN(a);
//	printf("%p\n", a);
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
//�ص�����

//qsort����	
//����,����������������
//void qsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
//void* �޾�������ָ��,���Դ洢�κ�����ָ��,����ʹ��ʱ��Ҫǿ������ת��.
//void* base������׵�ַ, size_t num����Ԫ�ظ���, size_t sizeÿ��Ԫ�ش�С(byte),
//int (*compar)(const void*, const void*)����ָ��,ָ��Ƚ�������ַָ�����ݴ�С�Ƚϵĺ���
#include <stdio.h>

////qosrt������ʹ�õ�ʵ��һ���ȽϺ���
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//ǰ�ߴ��ں��߷��� >0 ,���ڷ��� 0,С�ڷ��� <0
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

////ģ��ʵ�� qsort()����.
////����Ԫ��
//#include <stdio.h>
//#include <string.h>
//
//void swap(void* e1,void* e2,size_t width)//��֪����������,���ԾͰ���С��λbyte���ν�����Ԫ��ĩβ�ֽ�
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *((char*)e1 + i);//* ���ȼ����� (ǿ������ת��), (ǿ������ת��) ���ȼ����� ������� +
//		*((char*)e1 +i) = *((char*)e2 +i);//+i ������һ���ֽ�
//		*((char*)e2 +i) = tmp;
//	}
//}
//
//void my_qsort(void* arr,unsigned int sz,size_t width,int (*cmp)(void* ,void*))
//{
//	//����ĺ���˼�뻹�����ݷ����� bubble_sort
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//ǰ����������,���һ��Ԫ�ؾͲ�������,λ�ù�λ
//	{
//		int j = 0;
//		for (j = 0; j <sz -i -1; j++)//��һ���ϴ��߷���ĩ��
//		{
//			if (cmp((char*)arr + j*width,(char*)arr + (j+1)*width)>0)//widthԪ�ش�С,��λ�ֽ�
//			{
//				//����,��ͬ���ͽ�����ʽ��һ��,���Դ���ַ,��void* ����,��Ҫÿ��Ԫ���ֽڴ�С
//				swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
//			}
//		}
//	}
//
//}
//
////�Ƚ�����Ԫ�� int
//int cmp_int(void* e1, void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//
////�Ƚ�����Ԫ�� char
//int cmp_char(void* e1, void* e2)
//{
//	//strcmp���αȽ������ַ�����Ӧ�ַ���ASCII��ֵ,���� ���� >0,С�� ���� <0 ,���� ���� 0 (��ͬ������һλ,ֱ����ͬ���߽���)
//	return strcmp((char*) e1,(char*) e2);
//}
//
////����
////�ṹ������
//struct stu
//{
//	int age;
//	char name[15];
//};
////�Ƚ�����Ԫ�� �ṹ�� age
//int cmp_struct_stu_age(void* e1, void* e2)
//{
//	//e1 , e2 �ṹ������Ԫ�ص��׵�ַ
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;//���ʽṹָ���Ա -> ���ȼ����� (ǿ������ת��).����Ϸ���ͬ
//}
//
////�Ƚ�����Ԫ�� �ṹ�� name
//int cmp_struct_stu_name(void* e1, void* e2)
//{
//	//e1 , e2 �ṹ������Ԫ�ص��׵�ַ
//	return strcmp(&(((struct stu*)e1)->name) ,&(((struct stu*)e2)->name));//strcmp���ݲ�����char*��ַ
//}
//
//
////��ӡ
////void print(void* arr, size_t sz,size_t width)//��֪����ӡԪ������,����С��λbyte���δ�ӡ
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		printf("");//���ﲻ��,printf()�����ڴ���ӽǲ�ͬ,��ӡ�Ľ���Ͳ�ͬ,��֪������,��֪����ô��ӡ
////				   //���� �� Ū����ͨ�õ�.
//// 	}
////}
//void print(void* arr, size_t sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡint
//		//printf("%d ", *(((int*)arr) + i));
//		//��ӡchar
//		printf("%c", *((char*)arr + i));
//		////��ӡfloat
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
//	struct stu arr[3] = { {15,"wangping"},{21,"heweidao"},{19,"zhangwudi"}};//�ṹ������
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	//print(arr, sz);
//
//	//����
//	//my_qsort(arr, sz, width, cmp_int);
//	//my_qsort(arr, sz, width, cmp_char);
//	//my_qsort(arr, sz, width, cmp_struct_stu_age);
//	my_qsort(arr, sz, width, cmp_struct_stu_name);
//
//
//	//��ӡ
//	//print(arr, sz);
//	return 0;
//}
//
////�ο�����
//void myqsort(void* base, size_t nitems, size_t size, int(*compar)(const void*, const void*))
//{
//	int i, j;
//	char* st = (char*)base; //void *������Ӽ�����char *�Ӽ��������ֽ���תΪ1��������ơ�
//	char tmp[16]; //���ǵ�long double���ͣ���ʱ�ռ�����16�ֽڱȽϱ���
//
//	for (i = 0; i < nitems - 1; i++)
//	{
//		for (j = 0; j < nitems - 1 - i; j++) //ð�ݳ���ѭ��ͷ
//		{
//			if (compar(st + j * size, st + (j + 1) * size)) //�Ƚϵ�ʱ����תע���size
//			{
//				memcpy(tmp, st + j * size, size); //����������memcpy��ɾͲ�������⡣
//				memcpy(st + j * size, st + (j + 1) * size, size);
//				memcpy(st + (j + 1) * size, tmp, size);
//			}
//		}
//	}
//}

//ģ��ʵ�� qsort()����.		����
//����Ԫ��
#include <stdio.h>
#include <string.h>

//void swap(void* e1,void* e2,size_t width)//��֪����������,���ԾͰ���С��λbyte���ν�����Ԫ��ĩβ�ֽ�
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *((char*)e1 + i);//* ���ȼ����� (ǿ������ת��), (ǿ������ת��) ���ȼ����� ������� +
//		*((char*)e1 +i) = *((char*)e2 +i);//+i ������һ���ֽ�
//		*((char*)e2 +i) = tmp;
//	}
//}
//
//void my_qsort(void* arr,unsigned int sz,size_t width,int (*cmp)(void* ,void*))
//{
//	//����ĺ���˼�뻹�����ݷ����� bubble_sort
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//ǰ����������,���һ��Ԫ�ؾͲ�������,λ�ù�λ
//	{
//		int j = 0;
//		for (j = 0; j <sz -i -1; j++)//��һ���ϴ��߷���ĩ��
//		{
//			if (cmp((char*)arr + j*width,(char*)arr + (j+1)*width)>0)//widthԪ�ش�С,��λ�ֽ�
//			{
//				//����,��ͬ���ͽ�����ʽ��һ��,���Դ���ַ,��void* ����,��Ҫÿ��Ԫ���ֽڴ�С
//				swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
//			}
//		}
//	}
//
//}
//
////�Ƚ�����Ԫ�� int
//int cmp_int(void* e1, void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//
////�Ƚ�����Ԫ�� char
//int cmp_char(void* e1, void* e2)
//{
//	//strcmp���αȽ������ַ�����Ӧ�ַ���ASCII��ֵ,���� ���� >0,С�� ���� <0 ,���� ���� 0 (��ͬ������һλ,ֱ����ͬ���߽���)
//	return strcmp((char*) e1,(char*) e2);
//}
//
////�Ƚ�����Ԫ�� float
//int cmp_float(void* e1, void* e2)
//{
//	//����ֱ�ӷ���*((float*)e1) - *((float*)e2),���ڴ��д洢��ʽ�� float,������������ int
//	if (*((float*)e1) > *((float*)e2))
//		return 1;
//	else if (*((float*)e1) == *((float*)e2))
//		return 0;
//	else
//		return -1;
//}
//
////�Ƚ�����Ԫ�� double
//int cmp_double(void* e1, void* e2)
//{
//	//�ؼ� ���������� int ,���� double
//	if (*((double*)e1) > *((double*)e2))
//		return 1;
//	else if (*((double*)e1) == *((double*)e2))
//		return 0;
//	else
//		return -1;
//}
//
////����
////�ṹ������
//struct stu
//{
//	int age;
//	char name[15];
//};
////�Ƚ�����Ԫ�� �ṹ�� age
//int cmp_struct_stu_age(void* e1, void* e2)
//{
//	//e1 , e2 �ṹ������Ԫ�ص��׵�ַ
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;//���ʽṹָ���Ա -> ���ȼ����� (ǿ������ת��).����Ϸ���ͬ
//}
//
////�Ƚ�����Ԫ�� �ṹ�� name
//int cmp_struct_stu_name(void* e1, void* e2)
//{
//	//e1 , e2 �ṹ������Ԫ�ص��׵�ַ
//	return strcmp(&(((struct stu*)e1)->name) ,&(((struct stu*)e2)->name));//strcmp���ݲ�����char*��ַ
//}
//
//
//void test_int()
//{
//	int arr[10] = { 2,8,4,6,7,1,3,5,9,0 };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡint
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void test_char()
//{
//	char arr[20] = "hello bit.1234dcba";
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_char);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡchar
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//}
//
//void test_float()
//{
//	float arr[20] = {1.0,1.5,23.1,2.5,108,6.9,5.6,4.1,3.2,8.9,10};
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡfloat
//		printf("%f ", arr[i]);
//	}
//	printf("\n");
//}
//
//void test_double()
//{
//	double arr[20] = { 1.0,1.5,23.1,2.5,108,6.9,5.6,4.1,3.2,8.9,10 };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_double);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡdouble
//		printf("%lf ", arr[i]);
//	}
//	printf("\n");
//}
//
//void test_struct_age()
//{
//	struct stu arr[3] = { {15,"wangping"},{21,"heweidao"},{19,"zhangwudi"} };//�ṹ������
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_struct_stu_age);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡ arr.age
//		printf("%d ", (arr+i)->age);
//	}
//	printf("\n");
//}
//
//void test_struct_name()
//{
//	struct stu arr[3] = { {15,"wangping"},{21,"heweidao"},{19,"zhangwudi"} };//�ṹ������
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	size_t width = sizeof(arr[0]);
//	my_qsort(arr, sz, width, cmp_struct_stu_name);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		////��ӡ arr.name
//		printf("%s ", (arr+i)->name);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	test_int();
//	test_char();
//	test_float();
//	test_double();
//	test_struct_age();
//	test_struct_name();
//	return 0;
//}

//ָ���������������
//�����������壺
//1. sizeof(������)���������������ʾ�������飬���������������Ĵ�С��
//2. & ���������������������ʾ�������飬ȡ��������������ĵ�ַ��
//3. ����֮�����е�����������ʾ��Ԫ�صĵ�ַ��
#include <stdio.h>
#include <string.h>

//int main()
//{
//	////һά����
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));//a��ʾ��������,��sizeof(),�ҵ���	4*4 = 16
//	//printf("%d\n", sizeof(a + 0));//a+0ָ��,��Ԫ�ص�ַ,x64ƽ̨,ָ��64bit, 8�ֽ�
//	//printf("%d\n", sizeof(*a));//Ԫ��1,int 4
//	//printf("%d\n", sizeof(a + 1));//��ַ, 8
//	//printf("%d\n", sizeof(a[1]));//Ԫ��2,int 4
//	//printf("%d\n", sizeof(&a));//a��ʾ��������,&.	����ָ��,��ַ,	8
//	//printf("%d\n", sizeof(*&a));//����������ָ��,�õ�����	16
//	//printf("%d\n", sizeof(&a + 1));//��ַ,�ƶ�һ�����鳤��,	8
//	//printf("%d\n", sizeof(&a[0]));//��ַ,	8
//	//printf("%d\n", sizeof(&a[0] + 1));//��ַ	8
//	
//	////�ַ�����
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//arr��������, 6*1 = 6
//	//printf("%d\n", sizeof(arr + 0));//��ַ,	8
//	//printf("%d\n", sizeof(*arr));//arr������Ԫ�ص�ַ,	1
//	//printf("%d\n", sizeof(arr[1]));//Ԫ��'b',	1
//	//printf("%d\n", sizeof(&arr));//����ָ��,	8
//	//printf("%d\n", sizeof(&arr + 1));//����ָ��,�ƶ�һ������,	8
//	//printf("%d\n", sizeof(&arr[0] + 1));//�ַ�ָ��,�ƶ�һ��char����,	8
//	//printf("%d\n", strlen(arr));//	û��'\0'����,���ֵ
//	//printf("%d\n", strlen(arr + 0));//	û��'\0'����,���ֵ
//	////printf("%d\n", strlen(*arr));//strlen()������char* ,*arr��Ԫ�� 'a',���Ͳ�ƥ��,error
//	////printf("%d\n", strlen(arr[1]));//Ԫ��'b',���Ͳ�ƥ��,error
//	//printf("%d\n", strlen(&arr));//����ָ��,char(*)[6],	ָ��Ļ�����Ԫ�ص�ַ,���Ƿ���Ȩ�޺Ͳ�����һ��,	û��'\0'����,���ֵ
//	////��ô,��������,����Ϊ�����ֵ
//	////����,ÿ�δ�ӡ����� 42	,but why?
//	////����ƽ̨x64,ÿ�ν������42,����ĵ�ַ�ƺ�������,ԭ��δ֪
//	////����ƽ̨��Ϊx86,���Ϊ���ֵ
//	//printf("%d\n", strlen(&arr + 1));//��ַ,�ƶ���һ������,���ֵ
//	//printf("%d\n", strlen(&arr[0] + 1));//��ַ,�ƶ���һ��Ԫ��,û��'\0'����,���ֵ	
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//	7*1 = 7
//	//printf("%d\n", sizeof(arr + 0));//��ַ	8/4
//	//printf("%d\n", sizeof(*arr));//��Ԫ�ص�ַ,������,'a'	1
//	//printf("%d\n", sizeof(arr[1]));//'b' 1
//	//printf("%d\n", sizeof(&arr));//��ַ,	4/8
//	//printf("%d\n", sizeof(&arr + 1));//��ַ,	4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//��ַ,	4/8
//	//printf("%d\n", strlen(arr));//	��'\0'����,	6
//	//printf("%d\n", strlen(arr + 0));//6
//	////printf("%d\n", strlen(*arr));//'a'���ǵ�ַ,error
//	////printf("%d\n", strlen(arr[1]));//'b'���ǵ�ַ,error
//	//printf("%d\n", strlen(&arr));//����ָ������,����ֵ������Ԫ�ص�ַ,	6
//	//printf("%d\n", strlen(&arr + 1));//���ֵ
//	//printf("%d\n", strlen(&arr[0] + 1));//5
//
//	//char* p = "abcdef";//ָ�����ַ�����ָ��
//	//printf("%d\n", sizeof(p));//��ַ,ָ��,	4/8
//	//printf("%d\n", sizeof(p + 1));//��ַ,	4/8
//	//printf("%d\n", sizeof(*p));//������,'a',char	1
//	//printf("%d\n", sizeof(p[0]));//p[0] �ȼ��� *(p+0) ,'a',	1
//	//printf("%d\n", sizeof(&p));//��ַ,����ָ��,	4/8
//	//printf("%d\n", sizeof(&p + 1));//��ַ,����ָ��,�ƶ�һ����ַ��С		4/8
//	//printf("%d\n", sizeof(&p[0] + 1));//[] ��������� &,��ַ,ָ��'b',	4/8
//	//printf("%d\n", strlen(p));//'\0',	6
//	//printf("%d\n", strlen(p + 1));//�ƶ�һ��char,	5
//	////printf("%d\n", strlen(*p));//'a',	error
//	////printf("%d\n", strlen(p[0]));//'a',	error
//	//printf("%d\n", strlen(&p));//����ָ��,	���ֵ
//	//printf("%d\n", strlen(&p + 1));//����ָ��,�ƶ�һ��ָ���С,(4/8)	���ֵ
//	//printf("%d\n", strlen(&p[0] + 1));//&(p[0]) => &('a') => &(*(p+0)) => p, p+1,	5
//	////ʵ�������,����x86,x64,���ֵ�������
//	////����Ӧ�ø�Ϊδֵ֪
//	////��η��ʵĶ���ָ��,�������ڴ��д��ָ��Ŀռ�����δ֪���Ĺ���
//
//	////��ά����
//	//int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a));//a��������,	12*4 = 48
//	//printf("%d\n", sizeof(a[0][0]));//Ԫ��,int	4
//	//printf("%d\n", sizeof(a[0]));//a[0]��ʾ�� 0 �е�һά����,�ǵ�0�е�������,
//	//							 //������������sizeof()��,��ʾ������0������,{0,0,0,0},	4*4 = 16
//	//printf("%d\n", sizeof(a[0] + 1));//��0�е������� + 1,�������������,��ʾ0��{0,0,0,0}��Ԫ�ص�ַ,�ƶ�һ��int,	4/8
//	//printf("%d\n", sizeof(*(a[0] + 1)));//Ԫ��,int 4
//	//printf("%d\n", sizeof(a + 1));//a��ʾ��Ԫ�ص�ַ,��Ԫ����һά����,�����ַ,����������ָ������,int(*)[4],
//	//							  //��ַ,�ƶ�һ�д�С	4/8
//	//printf("%d\n", sizeof(*(a + 1)));//����ָ��,�ƶ�һ�д�С,ָ��ڶ���,*(a + 1) <==> a[1],�ڶ���һά������,
//	//								 //��������������sizeof()��,��ʾ��������,	4*4 = 16 byte
//	//printf("%d\n", sizeof(&a[0] + 1));//a[0]��0��������,&a[0],��0�е�ַ,����ָ��,�ƶ�һ��,	4/8
//	//printf("%d\n", sizeof(*(&a[0] + 1)));//ָ���1��һά�����ָ��,�� &a[1],������,a[1],��1��������
//	//									 //��������������sizeof(),��ʾ������1��һά����,	4*4 = 16
//	//printf("%d\n", sizeof(*a));//a��0������ָ��,�����õõ���0������,	4*4 =16
//	//printf("%d\n", sizeof(a[3]));//a��3��������,��������������sizeof(),��ʾ������3��һά����,
//	//							 //����ʵ����û�е�3��,sizeof()�ڲ����ʽ����������,���� "ֵ����",ֻ�õ� "��������"
//	//							 //���������Ʋ���		4*4 = 16
//
//}



//ָ�������
#include <stdio.h>

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
////����Ľ����ʲô��
////2,5


////�ṹ��Ĵ�С��20���ֽ�, int + char* + short + char[2] + short[4]
////						   4  +  4/8  +   2   +    2    +     8     = 20 byte
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;//struct Test *p,�ṹ������ָ��
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
////��֪���ṹ��Test���͵ı�����С��20���ֽ�
//int main()
//{
//	printf("%p\n", p + 0x1);//0x100014,ָ���1,�ƶ�1��ָ�����ʹ�С�ĳ���,20byte
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001,��ǿ������ת��Ϊ�޷���long����,��ʵ��������޷���int,���ּ�1,��������
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004,ָ���1,�ƶ�1��ָ�����ʹ�С�ĳ���,4byte
=======
//����Ŀ���ơ�
//offsetof��
//����Ŀ���ݡ�
//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
//���죺offsetof���ʵ��
#include <stdio.h>

//struct A
//{
//	char a;
//	int b;
//	double c;
//};
//
//////1.0	����
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
////2.0	��
////#define OFFSETOF(x,y) (size_t)((char*)(&y) - (char*)(&x))
////x�ṹ�������,y�ṹ���Ա��(��Ҫ��).ȡ��ַ,�����ַ��ǿ��ת��λchar*,��ַ����õ�ƫ���ֽڸ���.����ǿ��ת��Ϊsize_t
//
////�ο���
////#define offsetof(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName)
////StructType�ǽṹ����������MemberName�ǳ�Ա����������������ǣ�
////1���Ƚ�0ת��Ϊһ���ṹ�����͵�ָ�룬�൱��ĳ���ṹ����׵�ַ��0����ʱ��ÿһ����Ա��ƫ�����ͳ������0��ƫ�����������Ͳ���Ҫ��ȥ�׵�ַ�ˡ�
////2���Ը�ָ����->�������Ա����ȡ����ַ�����ڽṹ����ʼ��ַΪ0����ʱ��Աƫ����ֱ���൱�ڶ�0��ƫ���������Եõ���ֱֵ�Ӿ��Ƕ��׵�ַ��ƫ������
////3��ȡ���ó�Ա�ĵ�ַ��ǿת��size_t����ӡ������������ƫ������
//
////3.0	��
////#define OFFSETOF(StructName, MenberName) (size_t)((char*)(&(StructName.MenberName)) - (char*)(&StructName))
////#define OFFSETOF(x,y) (size_t)((char*)(&x.y) - (char*)(&x))
//
////4.0	��
//#define offsetof(StructType,MenberName) (size_t)&(((StructType*) 0)->MenberName)
////#define offsetof(StructType,MenberName) (size_t)&(((StructType*) 0x500)->MenberName) - 0x500
// //����һ����Թ�ϵ
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
>>>>>>> w6/main
//	return 0;
//}


<<<<<<< HEAD
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1] �ȼ��� *(ptr1 - 1)	4
//									 //С�˴洢,01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//									 //���� 00 00 00 02	С�˴洢��ԭ 0x02000000		
//	return 0;
//}


#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };// () ���� {} ,����ʵ�ʴ洢{1,3,5}
//	int* p;
//	p = a[0];//a[0]���е�ַ,����ָ��,��ֵΪ������Ԫ�ص�ַ,��ֵ�� int* ����ָ��,��Ҫǿ������ת��
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
//	//p����ָ��,int(*)[4]�ƶ���λ����4��int   ==>  +  4*4 byte
//	//*(p + 4)����ָ������õ�������,һά������,��Ԫ�ص�ַ,int*
//	//*(p + 4) +2		==>  + 2  byte
//	//p�ƶ�18byte
//	
//	//&a[4][2] ==> &(*(*(a + 4) +2))
//	//a����ָ��,int(*)[5],�ƶ���λ����5��int   ==>  +  4*5 byte
//	//*(a + 4)����ָ������õ�������,һά������,��Ԫ�ص�ַ,int*
//	//*(a + 4) +2		==>  + 2  byte
//	//p�ƶ�22byte
//
//	//-4
//	// 10000000000000000000000000000100ԭ��
//	// 11111111111111111111111111111011����
//	// 11111111111111111111111111111100����
//	
//	//����:FFFF FFFC,-4
//	return 0;
//}


//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa,aa��ʾ��������,��ά����ָ��,�ƶ�10 int����
//	int* ptr2 = (int*)(*(aa + 1));//aa��ʾ��������ָ��,һά����ָ��,�ƶ�5 int����
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5
//	return 0;
//}


#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;//pa = pa +1,�ƶ�char**����, 4byte.
//	printf("%s\n", *pa);//"at"		��ӡat
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
////�ܽ�:ָ����Ŀ��ͼ���,�𼶽���
=======
>>>>>>> w6/main
