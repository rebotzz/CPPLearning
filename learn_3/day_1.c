#define _CRT_SECURE_NO_WARNINGS

////������ϰ
////����������
//
//#include<stdio.h>
//
//void swap(int* pa, int* pb)			//������ʽ���������ñ��ʽ, ��ֵ���� = 
//{
//	int z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	printf(" ����ǰ: a = %d; b = %d\n", a, b);
//	//��������
//	swap(&a, &b);
//	//������
//	printf("������: a = %d; b = %d\n",a, b);
//
//	return 0;
//}


////max ����
//#include<stdio.h>
//
//int max(int x, int y)
//{
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//	return z;
//}
//
//int main()
//{
//	int a = 150;
//	int b = 20;
//	//��max
//	int c = max(a, b);
//	printf("%d", c);
//	return 0;
//}