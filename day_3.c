#define _CRT_SECURE_NO_WARNINGS

//��̬�ڴ����ѧϰ













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

////ģ��ʵ��2.0
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
//		ret = ret * 10 + *p - '0';
//		//�ж��Ƿ񳬹����洢��Χ
//		if ((ret < INT_MIN) || (ret > INT_MAX))//��������ת��
//		{
//			return 0;
//		}
//		p++;
//	}
//	ret = flag * ret;
//	if (p > str)
//		return (int)ret;
//	else
//		return 0;
//}
//
//int main()
//{
//	char str[50] = { 0 };
//	strcpy(str, "\t\f\v\r+-12345678AAA");
//	//int a = atoi(str);
//	int a = my_atoi(str);
//
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

