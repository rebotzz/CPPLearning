#define _CRT_SECURE_NO_WARNINGS

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
//
//	return 0;
//}


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
//	return 0;
//}


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
//	return 0;
//}


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
//	return 0;
//}


