#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	//ָ�� ���� ��ַ
//	int a = 15;
//	printf("%p\n", &a);   //%p��ӡ��ַ
//	int* pa = &a;         //*��ָ���ַ���������Ϊint      pa�洢�˱���a�ĵ�ַ��pa��ָ�����
//	printf("%p\n",pa);
//	*pa = 16;              //�����ò�������ͨ����ַ�ı��ڵ�ַ�д洢����ֵ
//	printf("%d\n",a);
//	printf("%d\n",sizeof(int*));
//
//	return 0;
//}

//
//int main()
//{
//	int arry[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int i =0;i<10;i++)
//	{
//		printf("%d",arry[i]);
//	}
//
//	return 0;
//}

//typedef unsigned long long un_l_l;            //�����ض���
//int main()
//{
//	unsigned long long a = 10;
//	un_l_l b = 7;
//	printf("%d\n",sizeof(a));
//	printf("%d\n", sizeof(b));
//
//	return 0;
//}

//int main()
//{
//	extern num1;
//	int b = num1;
//	printf("%d",b);
//	return 0;
//}

//void qte()
//{
//	static int a = 1;         //static �ı��˱������������ڣ����洢������λ�øı���
//	int b = 1;
//	printf("%d",a);
//	a++;
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		qte();
//		i++;
//	}
//	return 0;
//}

//extern max();
//int main()
//{
//	int num3 = max(8,10);
//	printf("%d",num3);
//	return 0;
//}
//

//#define phi 3.14
////#include <stdio.h>
//
//int main()
//{
//	printf("%0.3f",phi);
//	return 0;
//}
//
//#define dev(x,y) ((x)-(y))       //��
//
//int main()
//{
//	int a = 10;
//	int b = 2;
//	int num2 = dev(a + 1, b * 2);
//	printf("%d",num2);
//	return 0;
//}
