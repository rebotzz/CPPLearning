#define _CRT_SECURE_NO_WARNINGS

//��̬�ڴ����ѧϰ


//malloc
//calloc
//realloc
//free
//NULL
//��������
// �� #include <stdlib.h>
//1.���Խ����ջ�������ڴ��Զ��ͷŵ�����
//2.��̬����,�ڴ治�̶�,�������arr[�����Ǳ���]������.
//3.�ɴ洢�ռ��,ջ����Դ����
//4.��������:���Դ����ṹ��,���һ����Ա�ǲ�ָ����С������,��С��malloc����,sizeof����ṹ���С��������������.
//5.��������:����ǰ��������һ������Ԫ��.���ٿռ���������������Ԫ��

//ע������(��������):
//1.�ڴ濪��ʧ�ܷ��� NULL,�� NULL������. ==> ʹ��ָ��ǰ���п�
//2.ʹ�ÿ����ڴ�������ͷ�,�����ڴ�й¶. ==> free(p); p = NULL;
//3.Խ�����,�������ٴ�С.
//4.�Էǿ��ٿռ��ָ������ͷ�,���߶Կ��ٿռ�ָ�����ͷ�.
//5.�ı俪�ٿռ�ָ��,���¿��ٿռ��Ҳ�����.	==> *(p + i);��ֱ���޸� p
//6.malloc,calloc,realloc����ָ��void*,��Ҫǿ������ת��. ==>	(ǿ������ת��)malloc();
//7.���ú�������,ջ�����ٿռ��ͷ�,���Է���ָ����Ƭ�ռ�ָ��û��.Ұָ��


#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int num = 5;
//	int* pnum = &num;
//	//int arr[num] = { 0 };//error
//	int* p = (int*)malloc(num * sizeof(int));//�����ڴ治��ʼ��
//	if (p == NULL)		//�п�
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < num; i++)//����Խ�����
//	{
//		*(p + i) = i + 1;
//	}
//	//��ӡ
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//
//	//�������ͷ��ڴ�,��Ȼ�ᵼ���ڴ�й¶
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//#include <string.h>
//#include <errno.h>
//int main()
//{
//	int num = 5;
//	//�����ڴ�
//	int* p = (int*)calloc(num, sizeof(int));//�����ڴ��ʼ��Ϊ 0 
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//	//����
//	num = 8;
//	void* tmp = realloc(p, num * sizeof(int));
//	if (tmp != NULL)
//	{
//		p = (int*)tmp;
//		tmp = NULL;
//	}
//	else
//	{
//		return 1;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//
//	//�ͷ��ڴ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//��������ı�����
//4.1 ��Ŀ1��
#include <stdio.h>
#include <stdlib.h>

//void GetMemory(char* p) //p = NULL
//{
//	p = (char*)malloc(100); //p ָ�򿪱ٿռ�.�������ý���,�ֲ����� p ��ջ���ͷ�,���洢��ַ��ʧ
//							//û��free();�ڴ�й¶
//
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str); //���ݵ���ָ�������ֵ NULL ,������ָ�����str�ĵ�ַ,����ı�str
//	strcpy(str, "hello world");//str = NULL ,�Ƿ�����
//	printf(str);	// str ָ�� "hello world"��Ԫ�ص�ַ. ==> printf("hello world");
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//��Ŀ 2
#include <stdio.h>
#include <stdlib.h>

//char* GetMemory(void)
//{
//	char p[] = "hello world";//p �Ǿֲ�����,��ջ������,���������ý���,p��ָ��ռ��ͷ�.
//	return p;				 //p ����û������.Ұָ��
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);	//Ұָ��,���
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//��Ŀ 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void GetMemory(char** p, int num)//����ָ��
//{
//	*p = (char*)malloc(num);//�����ٿռ��ַ��ֵ��str
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);//����ָ�����str�ĵ�ַ,�ܸı�str��ֵ.
//	strcpy(str, "hello");
//	printf(str);
//						 //û��free(str);str = NULL; ==> �ڴ�й¶
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//��Ŀ 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void Test(void)
//{
//	char* str = (char*)malloc(100);//û���пմ���
//	strcpy(str, "hello");
//	free(str);				//�����ͷ��ڴ�,��û�� str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");	//�Ƿ�����
//		printf(str);
//	}
//
//	////��ϴ�����ͼ�޸�
//	//if (str != NULL)
//	//{
//	//	strcat(str, "world");	//�Ƿ�����
//	//	printf(str);
//	//}
//	//free(str);				//�����ͷ��ڴ�,��û�� str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//��������
#include <stdio.h>

//typedef struct A	//�ṹ������
//{
//	int a;
//	int arr[];//��������ռ俪���ڶ���,���������ṹ�ڶ��Ͽ���    !  ������,����������,�����￪����ʹ���߾���.�Ƿ� malloc
//}a_arr;
//
//int main()
//{
//	int num = 5;
//	printf("%u\n", sizeof(a_arr));
//
//	//����
//	//a_arr s = { 0 };//�ṹ���������  ==>  ����  !  ������,����������,�����￪����ʹ���߾���.�Ƿ� malloc
//	//printf("%p\n", &s);
//	////���ٿռ�
//	//int* parr = (int*)malloc(sizeof(a_arr) + num * sizeof(int));//ʹ�ô���,parr �� s �޹�.
//	//if (parr == NULL)
//	//{
//	//	return 1;
//	//}
//	//printf("%p\n", parr);
//	//int i = 0;
//	//for (i = 0; i < num; i++)
//	//{
//	//	s.arr[i] = i + 1;
//	//}
//
//	////�޸ĺ�
//	//a_arr* parr = (a_arr*)malloc(sizeof(a_arr) + num * sizeof(int));
//	//if (parr == NULL)
//	//{
//	//	return 1;
//	//}
//	//parr->a = 2;
//	//int i = 0;
//	//for (i = 0; i < num; i++)
//	//{
//	//	parr->arr[i] = i + 1;
//	//}
//
//	//for (i = 0; i < num; i++)
//	//{
//	//	printf("%d ", parr->arr[i]);
//	//}
//
//	//�޸ĺ� 2.0
//	a_arr* parr = (a_arr*)malloc(sizeof(a_arr) + num * sizeof(int));
//	if (parr == NULL)
//	{
//		return 1;
//	}
//	parr->a = num;//����� a ��������¼�����С,����������
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		parr->arr[i] = i + 1;
//	}
//
//	for (i = 0; i < num; i++)
//	{
//		printf("%d ", parr->arr[i]);
//	}
//
//
//	//�ͷſռ�
//	free(parr);
//	parr = NULL;
//
//	return 0;
//}


//��������������Ե�ЧΪ:
//����,ȱ��,��Ҫ��ο���,�ͷ��ڴ�,���Ⱥ�˳��.�ݴ��
//�����ڷ����ٶ�.�������ڴ���������߷����ٶȣ�Ҳ�����ڼ����ڴ���Ƭ��
#include <stdio.h>
#include <stdlib.h>

//typedef struct B
//{
//	int i;
//	int* parr;
//}b_arr;
//
//int main()
//{
//	//�ڴ濪��
//	b_arr* pb = (b_arr*)malloc(sizeof(b_arr));//���ٽṹ��,��Ա:int i ;ָ�������ָ�� int* parr;
//	if (pb == NULL)
//	{
//		return 1;
//	}
//	pb->i = 10;
//	pb->parr = (int*)malloc(pb->i * sizeof(int));//��������,�ռ��ɽṹ���Ա p->parr ָ�� ;��С,pb->i��int
//	int i = 0;
//	for (i = 0; i < pb->i; i++)
//	{
//		pb->parr[i] = i + 1;
//	}
//
//
//	//�ڴ��ͷ�,���ο���,�����ͷ�,��������,ע���ͷ��Ⱥ�˳��
//	free(pb->parr);//���ͷŽṹ��ָ�������
//	pb->parr = NULL;
//	free(pb);//���ͷŽṹ�����ڿռ�
//	pb = NULL;
//
//	return 0;
//}



//��ҵ

//ģ��ʵ�� atoi()
//int atoi(const char *str)
//C ��׼�� - <stdlib.h>
//C �⺯�� int atoi(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ�
//atoi�Ĺ����ǣ��������ɼ��ַ����������Ż������ֿ�ʼת����ת�����������ַ�Ϊֹ��

//ʹ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>//INT_MAX INT_MIN

//int main()
//{
//	int val;
//	char str[20];
//
//	strcpy(str, "98993489");
//	val = atoi(str);
//	printf("�ַ���ֵ = %s, ����ֵ = %d\n", str, val);
//
//	strcpy(str, "a48runoob.com");
//	val = atoi(str);
//	printf("�ַ���ֵ = %s, ����ֵ = %d\n", str, val);
//
//	return(0);
//}

////ģ��ʵ��1.0	���ܲ�����
//int my_atoi(const char* str)
//{
//	assert(str != NULL);
//	int ret = 0;
//	char* p = str;
//	while ((*p >= '0') && (*p <= '9'))
//	{
//		ret = ret * 10 + *p - '0';
//		p++;
//	}
//	if (p > str)
//		return ret;
//	else
//		return 0;
//}

//ģ��ʵ��2.0	�ؼ�,��ɴ�����ĺ�,�Դ����������Ĵ���,ϸ��
//�жϷ��ص� 0 ��ת����0,��������ԭ���µ� 0
//enum judge
//{
//	VALID,	//0 ��������Ч
//	INVALID	//1 ��������Ч
//};
//enum judge lable = INVALID;//��ʼ��Ч
//int my_atoi(const char* str)
//{
//	assert(str != NULL);
//	long long int ret = 0;
//	int flag = 1;
//	char* p = (char*)str;
//	//�������ɼ��ַ� ' ' '\t' '\n' '\v'  '\f'  '\r''
//	while (isspace(*p))
//	{
//		p++;
//	}
//	//����������
//	while (*p == '+' || *p == '-')
//	{
//		if (*p == '+')
//			flag = 1;
//		else
//			flag = -1;
//		p++;
//	}
//	str = p;//��¼���ֿ��ܵ���ʼλ��
//	while (isdigit(*p))//���������
//	{
//		ret = ret * 10 + *p - '0';//���� ret = 10*ret flag*(*p - '0');
//		//�ж��Ƿ񳬹����洢��Χ
//		if ((ret < INT_MIN) || (ret > INT_MAX))//��������ת��
//		{
//			return 0;
//		}
//		p++;
//	}
//	ret = flag * ret;
//	if (p > str)//���������ֵ�ת��
//	{
//		lable = VALID;//�����Ч
//		return (int)ret;
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char str[50] = { 0 };
//	strcpy(str, "\t\f\r+-12345678AAA");
//	//int a = atoi(str);
//	int a = my_atoi(str);
//	if (lable == VALID) 
//	{
//		printf("ת�������Ч.\n");
//	}
//	else
//	{
//		printf("ת�����0��Ч.\n");
//	}
//	printf("ԭ�ַ���:%s\t��Ӧ����ֵ:%d\n", str, a);
//
//	return 0;
//}



//����Ŀ���ơ�
//�ҵ���
//����Ŀ���ݡ�
//һ��������ֻ�� �������� �ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
#include <stdio.h>
#include <string.h>

//void check_solo(int arr[],int sz)
//{
//	//����
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	//���������ڵ����Ƚ�
//	int n = 0;//������,ֻ����������
//	for (i = 0; i < sz - 1; )
//	{
//
//		if (arr[i] != arr[i + 1])
//		{
//
//			arr[n] = arr[i];
//			n++;
//			if (n == 2)
//			{
//				break;
//			}
//			if (i == sz - 2 && n == 1)//��ֹԽ��,�������������λ���, AABBCCDDEF
//			{
//				arr[n] = arr[i + 1];
//				return;
//			}
//			//��Ӧ���ֲ�ͬ���
//			if (arr[i + 1] != arr[i + 2])//ABCCEE ==> BCCEE
//			{
//				i++;
//			}
//			else						 //ABBCCEDD ==> CCEDD
//			{
//				i += 3;
//			}
//		}
//		else				//����ǰ����ͬ����,��AABBCCDEE ==> DEE
//			i += 2;
//
//	}
//
//}
//
////�ο�����˼·:
////�ҳ�һ��ֻ���ֹ�һ�ε����ֵ����⴦����������һ�����ְ��������е����ֶ����һ�飬
////����������ε���û�����ص���������ô������������ֶ�ֻ������һ�Σ�
////��ô��˵õ���Ӧ�������������Ľ���������������϶�����0��Ҫ��Ȼ��ȫ������ˣ���
////��������һ������һλ��һ���ҳ�ֵΪ1��һλ������һλ��ֵ�������Ϊ���顣����1 2 3 4 1 2��
////�����Ľ��Ӧ����3 ^ 4�õ���111����ô�����һλ�����ˡ����������λ����ô��һλ��1����1 3 1����0����2 4 2��
////���������������Ϊ1��ĳһλ�ֵ��飬������������ѯ����һ���ֱ��������С�
////�������������������ֱ�����������������ҵ�����������
//
////2.0	�ο����Լ�д
//void check_solo2(int arr[], int sz, int* pa, int* pb)
//{
//	//��������������Ϊ a b
//	//�����������	==> ��ͬ��������,�õ���������������� sum = a^b
//	int sum = arr[0];
//	int i = 0;
//	for (i = 1; i < sz; i++)
//	{
//		sum ^= arr[i];
//	}
//		//�ҵ�a��b�����Ʋ�ͬλ��,int ==> 32 bit
//		int pos = 0;
//		for (i = 0; i < 32; i++)
//		{
//			if (sum & (1 << i))
//			{
//				pos = i;
//				break;
//			}
//		}
//	//�����ڶ�����posλ����,a��0,b��1;��ô,�����λ���Ϸֱ�Ϊ0 , 1����Ҳ������һ��,ͬ������������ͬ��������
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] & (1 << pos))//pos ==> 1
//		{
//			*pb ^= arr[i];
//		}
//		else					//pos ==> 0
//		{
//			*pa ^= arr[i];
//		}
//	}
//}
//
//int main()
//{
//	//ע��:
//	//֮ǰ����ʧ��ԭ�� ==> arr[]ָ���˴�С,����ȫ��ʼ��λ�ÿ�������������ż���Ե� 0,���������
//	//���߸���������,����ǰ����������0
//	int arr[] = { 1,5,6,5,1,6,2,3 };////1 3 3 5 5 7 7 8	{1,3,5,5,3,7,8,7}  {1,2,3,3,2,1,7,8}
//	int i = 0;
//	int a = 0;
//	int b = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* tmp = (int*)malloc(sizeof(arr));
//	if (tmp == NULL)
//	{
//		return 1;
//	}
//
//	memcpy(tmp, arr, sizeof(arr));
//	//check_solo(tmp, sz);
//	//printf("%d %d\n", tmp[0], tmp[1]);
//
//	check_solo2(tmp, sz, &a, &b);
//	printf("%d %d\n", a, b);
//
//	free(tmp);
//	tmp = NULL;
//	return 0;
//}



////�ж�һ����������λ�ж��ٸ� 1
//// n = n&(n-1);
//#include <stdio.h>
//int main()
//{
//	int n = 0x00001111;
//	int count = 0;
//	while (n)
//	{
//		//���磬��7��111��&6��110���õ�����6��110��������6��110��&5��101���õ�4��100����
//		//����4��100��&3��011���õ�0��000�����������,�õ��Ľ��������3����1����
//		n = n & (n - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}

