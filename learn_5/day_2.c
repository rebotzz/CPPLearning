#define _CRT_SECURE_NO_WARNINGS

//�ֲ�������ȫ�ֱ�����ͻʱ,�ֲ���������.	���������� int a = 1;һ��ȫ��,һ���ֲ�

//int main()//λ�ÿ�������
//{
//	printf("s\n");
//	return 0;
//}
//#include <stdio.h>


//����С������
#include <stdio.h>

//1.0
//int min_muitiple(int x, int y)//����С������
//{
//	int i = x * y;
//	int min = 0;
//	//����Ϊ�Ż�
//	int min_unit = x > y ? y : x;
//	for (i = x * y; (i >= x) && (i >= y);i = i - min_unit)
//	{
//		if ((i % x == 0) && (i % y == 0))
//		{
//			min = i;
//		}
//	}
//	return min;
//}

//2.0
//int min_muitiple(int x, int y)//����С������
//{
//	int i = 1;
//	for (i = 1; ; i++)
//	{
//		if (x*i%y == 0)
//		{
//			break;
//		}
//	}
//	return x*i;
//}

////3.0
//int min_muitiple(int x, int y)//շת��������Լ��, ��С������ = x*y / ���Լ��
//{
//	int m = x * y;
//	int max = x > y ? x : y;
//	int n = x % y;//����
//	while (n)
//	{
//		x = y;
//		y = n;
//		n = x % y;//շת���
//	}
//	//���Լ�� y
//	m = m / y;//���Լ��
//	return m;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = min_muitiple(a, b);//����С������
//	printf("%d\n", ret);
//	return 0;
//}


//��Ŀ����
//��һ�仰�ĵ��ʽ��е��ã���㲻���á�����l like beijing.�����������Ϊ: beijing.like l
//�������� :
//ÿ�������������1����������: �� like beijing�������������Ȳ�����100
//������� :
//�����������֮����ַ������Կո�ָ�
#include <stdio.h>
#include <string.h>

//δʵ��
//void reverse(char* str)
//{
//
//}

////1.0  ���˺þ�,һֱ����,��ǿ�ﵽ
//void reverse(char* str)
//{
//	char tmp[110] = " ";
//	strcpy((tmp+1), str);//ǰ������һ�� �ո�
//	int sz = strlen(tmp);
//	char* p = tmp + sz;
//	char* p1 = tmp + sz;
//	char* p2 = tmp + sz;
//	char arr[110] = " ";
//	char* pa1 = arr;
//	char* pa2 = arr;
//	while (p >= p1 - sz)
//	{
//		if (*(p - 1) == ' ')
//		{
//			strcpy(pa1, p);
//			pa1 = pa1 + (p2 - p);
//			*pa1 = ' ';//���һ�ζ���һ�� �ո�	Ӱ���ƺ�����
//			pa1++;
//			p2 = p-1;
//			*(p-1) = '\0';
//		}
//		p--;
//	}
//	strcpy(str, pa2);
//}
//int main()
//{
//	char arr1[110] = "I like beijing.";
//	//scanf("%s", arr1);//scanf()���� �ո� ��ֹͣ��ȡ,����
//	gets(arr1);
//	//����
//	reverse(arr1);
//	printf("%s\n", arr1);
//	return 0;
//}

////2.0	�����Ż�
//void reverse(char* start,char* end)//���� start �� end֮�����ĸ
//{
//	int left = 0;
//	int right = end - start;
//	char tmp = '0';
//	while (left < right)
//	{
//		tmp = start[left];
//		start[left] = start[right];
//		start[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr1[110] = "I like beijing.";
//	//scanf("%s", arr1);//scanf()���� �ո� ��ֹͣ��ȡ,����
//	gets(arr1);//��ȡһ��,�����ַ���
//	char* start = arr1;
//	char* end = arr1 + strlen(arr1) - 1;
//	//���η�ת��
//	reverse(start,end);//���嵹��
//	//�ֲ�����,����ÿ������
//	end = start;
//	while (*end != '\0')
//	{
//		if (*(end+1) == ' ' || *(end + 1 ) == '\0') //ÿ�����ʼ��Կո����
//		{
//			reverse(start, end);//���õ���
//			start = end + 2;//�ո����һλ,�����ʵ�����ĸλ
//		}
//		end++;
//	}
//
//	printf("%s\n", arr1);
//	return 0;
//}
//�ܽ�:
//д����˼·��д����Ҫ,˼·������,д���Ĵ�����Ҫ�����ĵ�������˼·.
//д֮ǰ�ȷ���һ������,ָ��������,д��������ƿ��.

