#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//��ϰ1��
//ʵ�ֹ��ܣ��ж�һ��������ż��
//˼·��if��䣬һ������2��������%2.

////����ֵ����
//int abs_val(int x)
//{
//	if (x >= 0)
//	{
//		return x;
//	}
//	else
//	{
//		return -x;
//	}
//}
//
//int main()
//{
//	int n = -57;
//	int a = 0;
//	int b = 0;
//	//scanf("%d",&n);
//	a = abs_val(n);
//	b = a % 2;
//	if (0 == b)
//	{
//		printf("ż��");
//	}
//	else
//	{
//		printf("����");
//
//	}
//
//	return 0;
//}


////˼·��
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d",&n);
//	a = n % 2;
//	//ifֻҪ�����Ϊ�棬����������
//	//if��else�ͽ�ԭ��Ϊ�˲���⣬�ô�����
//	//if�жϣ��Է� == ��дΪ = ������������
//	if (0 == a)
//	{
//		printf("ż��");
//	}
//	else
//	{
//		printf("����");
//	}
//	return 0;
//}


//��ϰ2��
//���1-100֮�������
//˼·����ҪӦ�õ�ѭ��������?���ã�ÿ��+1����1��ʼ��if��n%2�� ;else ���

//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100; i++)
//	{
//		//���i%2��Ϊ0��ifΪ�棬ִ��
//		if (i % 2)
//		{
//			printf("%d\n", i);
//		}
//		
//	}
//	return 0;
//}

////��whileѭ������
//int main()
//{
//	int i = 0;
//	while (i <= 100)
//	{
//		if (i % 2)
//		{
//			printf("%d\n",i);
//		}
//		i++;
//	}
//	return 0;
//}

////����3��
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100; i = i + 2)
//	{
//			printf("%d ", i);
//	}
//	return 0;
//}


////if ���֧��ϰ
//int main()
//{
//	int n = 48;
//	if (n < 0) 
//	{
//		printf("nΪ����\n");
//	}
//	else if (n >= 0 && n < 30)
//	{
//		printf("0<= n < 30\n");
//	}
//	else if (n >= 30 && n < 50)
//	{
//		printf("n��30��50֮��\n");
//	}
//	else if (n >= 50 && n < 80)
//	{
//		printf("n��50��80֮��\n");
//	}
//	else if (n >= 80 )
//	{
//		printf("n���ڵ���80\n");
//	}
//	return 0;
//}