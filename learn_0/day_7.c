#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////getchar()Ӧ��
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)     //һ���ַ�һ���ַ���ȡ�������ASSCII��洢������������ֹ��
//	{									//getchar()   ������    ����
//		putchar(ch);
//	}
//
//	return 0;
//}

////getchar()Ӧ��2
//int main() 
//{
//	char password[20] = { 0 };
//	printf("����������>:");
//	scanf("%s",password);	//�ַ��������ﲻ�� & ����
//	printf("��ȷ�����룺Y/N\n");
//	int ch = 0;
//	int a = 0;				//������������ַ���û��ȡһ�Σ�����һ��, ֱ�� '\n'  �س�
//	while ((a = getchar()) != '\n')
//	{
//		;					//�����
//	}
//	if ((ch = getchar()) == 'Y')
//	{
//		printf("ȷ�ϳɹ�");
//	}
//	else
//	{
//		printf("ȷ��ʧ��");
//	}
//	return 0;
//}


//while ;for ;do while ѭ������ϰ

//int main()
//{
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	printf("%d ",i);
//	//}
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


////��ȡ����
//int main()
//{
//	int ch = 0;
//	while ((ch =getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}


////���� n �Ľ׳�
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	long long int n_i = n;      //���⣨ע�⣩���洢����д�С���ƣ�������  ���
//	while (n != 1 && n>=1 )
//	{
//		n_i = n_i*(n - 1);
//		n--;
//	}
//	if (n_i >= 0)
//		printf("�׳�Ϊ��%lld\n", n_i);	//��������洢��Сƥ��
//	else
//		//��仰��һ��׼ȷ������Ŀǰ��ѧ
//		printf("����ֵΪ������û�н׳� or �����洢��С��������\n");	
//	return 0;
//}


////���� n �Ľ׳�   ˼·�Ż�
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	long long int n_i = 1;      //���⣨ע�⣩���洢����д�С���ƣ�������  ���
//								//�� n-1 ��� ��Ϊ n+1��ˣ��������ж� n-1 Ϊ 0 �����
//								//���ǲ��ܱ��� n_i ��ʼ��������
//	for(int i=1;i <= n; i++)
//	{
//		n_i = n_i*i;
//	}
//	if (n_i >= 0)
//		printf("�׳�Ϊ��%lld\n", n_i);	//��������洢��Сƥ��
//	else
//		//��仰��һ��׼ȷ������Ŀǰ��ѧ������ ������ ����Ϊ����
//		printf("����ֵΪ������û�н׳� or ���ܳ����洢��С��������\n");	
//	return 0;
//}


////���� 1��+2��+3������+10��
////˼·�� ѭ��Ƕ�ף����ı�n ; �ڲ���� n!
//int main()
//{
//									//��һ��������֤ long long int �ܴ洢 15!
//									//�����������洢�� long long int �ǿɿ���
//	int n = 10;						//ע�⣺�洢��С���ƣ������Ӱ��
//	long long int n_i = n;			 
//	long long int sum_n_i = 0;		
//	
//	for (n = 10;n >= 1;n--)         //for ��ͬ���Ľ׳�
//	{
//		int i = n;
//		n_i = n;					//��������仰��n_i �ĳ�ʼ��   
//		while (i != 0 && i >= 0)	//while �����һ���� i �Ľ׳�
//		{
//			if ((i - 1) == 0)
//				break;
//			n_i = n_i * (i - 1);	//ÿ�� n_i �ĳ�ʼ����ֵ��ͬ
//			i--;
//			if (i == 1)
//				sum_n_i = sum_n_i + n_i;	//�׳����
//		}
//	}
//	printf("1��+2��+3������+10��= %lld\n",sum_n_i);	//������1��+2��+3������+10��= 4037912
//	return 0;
//}


////���� 1��+2��+3������+10��    ˼·�Ż�
////˼·�� ѭ��Ƕ�ף����ı�n ; �ڲ���� n!
//int main()
//{
//									//��һ��������֤ long long int �ܴ洢 15!
//									//�����������洢�� long long int �ǿɿ���
//	int n = 10;						//ע�⣺�洢��С���ƣ������Ӱ��
//	long long int n_i = 1;			
//	long long int sum_n_i = 0;		
//	
//	for (n = 10;n >= 1;n--)         //for ��ͬ���Ľ׳�
//	{
//		int a = n;					//��ʼ��������Ҫ�����䶼������
//		n_i = 1;					//������ˣ����Ϊ 1��+2��+3������+10��= 3220178247989976832
//		for(int i = 1;i <= a; i++)
//		{
//			n_i = n_i*i;
//			//if (i == a)
//			//	sum_n_i = sum_n_i + n_i;	//�ȼ�
//		}
//		sum_n_i += n_i;						//�ȼ�
//	}
//	printf("1��+2��+3������+10��= %lld\n",sum_n_i);	//������1��+2��+3������+10��= 4037913
//	return 0;
//}


////���� 1��+2��+3������+10��    ˼·�Ż�2.0
////˼·�� ѭ��Ƕ�ף����ı�n ; �ڲ���� n!     (n+1)! = n!*(n+1),������һ�ν������ѭ������
//int main()
//{
//	int n = 10;						//ע�⣺�洢��С���ƣ������Ӱ��
//	long long int n_i = 1;
//	long long int sum_n_i = 0;
//
//	for (n = 1; n <= 10; n++)         //for ��ͬ���Ľ׳�
//	{				
//									  //�Ż���ѭ����������������� sum_n_i �ĳ�ʼ��
//		//3! = 3*2*1 = 3*2!
//		//2! = 2*1
//		n_i = n_i * n;
//		sum_n_i += n_i;						
//	}
//	printf("1��+2��+3������+10��= %lld\n", sum_n_i);	//������1��+2��+3������+10��= 4037913
//	return 0;
//}


//// do while ��׳�
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int i = 1;
//	long int ret = 1;
//	do
//	{
//		ret *= i;
//		i++;
//	} while (i <= n);
//	printf("�׳�Ϊ��%ld\n",ret);
//	return 0;
//}



//// ���ַ� ��������������ĳ��Ԫ�ص��±�
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10,14,16,18,20};
//	int k = 16;									//Ŀ��Ԫ��
//	int lenth = sizeof(arr) / sizeof(arr[0]);	//����Ԫ�ظ���
//	int left = 0;
//	int right = lenth - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ�Ŀ��Ԫ���±�Ϊ��%d\n", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("û���ҵ�������Ŀ��Ԫ�ز��ڲ������鷶Χ\n");
//	}
//
//
//	return 0;
//}


//��д���룬��ʾ����ַ��������ƶ������м��ۡ�
int main()
{
	char arr1[] = "welcome to night city";
	char arr2[] = "#####################";
	int lenth = sizeof(arr1) / sizeof(arr1[0]);
	float mid = (lenth - 1) / 2.0;
	int left = 0;
	int right = lenth - 2;
	printf("%s\n",arr2);
	printf("���»س��鿴��������:>");
	getchar();						//���س���ż���

	for (int i = left; i < mid; i =i+1 )
	{
									//��ӡ���
		int a = 0;
		while (a <= i)
		{
			printf("%c", arr1[a]);
			a++;
		}
									//��ӡ�м�
		for (int j = i + 1; j < right - i; j++)
		{
			printf("%c", arr2[j]);
		}
									//��ӡ�Ҷ�
		a = i;						//��ʼ�������治ͬ��ȷ����ӡ��ĸ˳��
		while (a >= 0)
		{
			printf("%c", arr1[right - a]);
			if (i == right - a)		//������һ���м��ַ��ظ���ӡ
				printf("\b");
			a--;
		}
		//printf("\n");
		getchar();					//���س���ż���
		
	}
	return 0;
}


////////��д���룬��ʾ����ַ��������ƶ������м��ۡ� ��Ϊ�����ֶ�����  �������1.0   û��ʵ�֣������
//////int main()
//////{
//////	char arr1[22] = { 0 };
//////
//////	int ch1 = 0;
//////	int ch2 = 0;
//////
//////	printf("������һ���ַ�:>");
//////	for (int n1 = 0; (ch1 = getchar()) != '\n'; n1++)
//////	{
//////		arr1[n1] = getchar();
//////	}
//////	int lenth = sizeof(arr1) / sizeof(arr1[0]);
//////	float mid = (lenth - 1) / 2.0;
//////	int left = 0;
//////	int right = lenth - 2;
//////
//////	printf("���»س�ִ��:>");
//////	getchar();						//���س���ż���
//////
//////	for (int i = left; i < mid; i = i + 1)
//////	{
//////		//��ӡ���
//////		int a = 0;
//////		while (a <= i)
//////		{
//////			printf("%c", arr1[a]);
//////			a++;
//////		}
//////		//��ӡ�м�
//////		for (int j = i + 1; j < right - i; j++)
//////		{
//////			printf("#");
//////		}
//////		//��ӡ�Ҷ�
//////		a = i;						//��ʼ�������治ͬ��ȷ����ӡ��ĸ˳��
//////		while (a >= 0)
//////		{
//////			printf("%c", arr1[right - a]);
//////			if (i == right - a)		//������һ���м��ַ��ظ���ӡ
//////				printf("\b");
//////			a--;
//////		}
//////		//printf("\n");
//////		getchar();					//���س���ż���
//////
//////	}
//////	return 0;
//////}