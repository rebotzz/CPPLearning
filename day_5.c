#define _CRT_SECURE_NO_WARNINGS

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
//
//	return 0;
//}


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
//	return 0;
//}


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
//	return 0;
//}


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

//ģ��ʵ�� qsort()����.
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
//	return 0;
//}


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
