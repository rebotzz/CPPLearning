#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


////��9�ĸ���
////��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9

//int main()
//{
//	int num = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9)
//			num++;
//		if (i % 10 == 9)
//			num++;
//	}
//	printf("%d", num);
//	return 0;
//}


////����Ŀ���ơ�
////�������
////����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ����ӡ�����
//
//int main()
//{
//	float sum = 0;
//	int a = 1;
//	int i = 1;
//	for (i = 1; i <= 100000; i++)
//	{
//		if (i % 2 == 0)
//			a = -1;
//		else
//			a = 1;
//		sum = sum + a * (1.0 / i);
//	}
//	printf("sum = %f", sum);	//�������ѧû�����Ļ�,�����, i->����ʱ, sum = ln2;Լ����0.69314718
//
//	return 0;
//}


////����Ŀ���ơ�
////�����ֵ
////����Ŀ���ݡ�
////��10 �����������ֵ
//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("����10������\n");
//	int i = 0;
//	for (int j = 0; j < 10; j++)
//	{
//		scanf("%d", &arr[j]);
//	}
//	//scanf("%d %d %d %d %d %d%d%d%d%d",&arr);		����д������?	���ַ������鲻һ��?
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] >= arr[i + 1])
//		{
//			if( max <= arr[i] )
//			max = arr[i];
//		}
//		else
//		{
//			if ( max <= arr[i + 1] )
//				max = arr[i + 1];
//		}
//
//	}
//	printf("max = %d", max);
//	
//	return 0;
//}


//����Ŀ���ơ�
//�˷��ھ���
//����Ŀ���ݡ�
//����Ļ�����9 * 9�˷��ھ���

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		for (j = 0; j <= 9; j++)
//		{
//			printf("%d * %d = %d   ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////�˷��ھ���
////����Ļ�����9 * 9�˷��ھ���			�����Ż�1.0
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}