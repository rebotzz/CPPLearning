#define _CRT_SECURE_NO_WARNINGS

//����Ŀ���ơ�
//��ӡһ������ÿһλ
//����Ŀ���ݡ�
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ

//����:1234    �������
//1234  > 1  234   >1  2  34  >   1  2  3  4

//#include<stdio.h>
//
////��ӡ����
//void print(int x)
//{
//	if (x / 10 != 0)
//	{
//		print(x / 10);
//	}
//	printf("%d  ", x % 10);
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//��ӡ����
//	print(a);
//	return 0;
//}


//����Ŀ���ơ�
//��׳�
//����Ŀ���ݡ�
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩

////1.0�ǵݹ�
//#include<stdio.h>
//
////�׳˺���
//int res(int x)
//{
//	int i = 1;
//	int n = 1;
//	for (i = 1; i <= x; i++)
//	{
//		n = n * i;
//	}
//	return n;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//�׳˺���
//	printf("%d\n",res(a));
//	return 0;
//}


////2.0�ݹ�
//// n! = n*(n-1)!
//#include<stdio.h>
//
////�׳˺���
//int res(int x)
//{
//	if (x > 1)
//	{
//		return x * res(x - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//�׳˺���
//	printf("%d\n", res(a));
//	return 0;
//}


//����Ŀ���ơ�
//strlen��ģ�⣨�ݹ�ʵ�֣�
//����Ŀ���ݡ�
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen   >   ���ַ�������

////1.0 strlen ʹ��
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	char arr2[20] = { 0 };
//	printf("%s\n", arr2);
//	printf("%u\n", strlen(arr2));
//
//	strcpy(arr2, arr1);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	printf("%u\n", strlen(arr1));
//	return 0;
//}


//
////2.0   strlen ģ��  �ǵݹ�
//#include<stdio.h>
//#include<string.h>
//
////���ַ�������
//int strlen1(char* arr)
//{
//	int i = 0;
//	while (1)
//	{
//		if (*arr != '\0')
//		{
//			i++;
//			arr++;
//		}
//		else
//			break;
//	}
//	return i;
//
//}
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	//���ַ�������
//	printf("%d", strlen1(&arr1));
//	return 0;
//}



////3.0   strlen ģ��  �ݹ�
//#include<stdio.h>
//
////���ַ�������
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//
//}
//
//int main()
//{
//	char arr1[] = "this is a code.";
//	//���ַ�������
//	printf("%d", strlen1(&arr1));
//	return 0;
//}


//����Ŀ���ơ�
//�ַ������򣨵ݹ�ʵ�֣�
//����Ŀ���ݡ�
//��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������У����������ӡ��
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//���� :
//char arr[] = "abcdef";
//����֮����������ݱ�ɣ�fedcba

////1.0   �ǵݹ�
//#include<stdio.h>
//
////abcdef  >   fedcba
//// t = arr[i]; arr[i] = arr[n-i]  ; arr[n-i] = t;
////   0 1 2 3 .... n 
////������
//void reverse_string(char* string)
//{
//	int i = 0;
//	int t = 1;
//	int n = strlen1(string);
//	for (i = 0; i < n - i; i++)
//	{
//		t = *(string + i);
//		*(string + i) = *(string + n - 1 - i);
//		*(string + n - 1 - i) = t;
//	}
//}
//
////���ַ�������
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdefghijklmnopqrstuvwxyz";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//������
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}

////1.1   �ǵݹ�  �����Ż�
//#include<stdio.h>
//
////������
//void reverse_string(char* string)
//{
//	int left = 0;
//	int right = strlen1(string)-1;
//	int tmp = 1;
//	while (left < right)
//	{
//		tmp = string[left];
//		string[left] = string[right];
//		string[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
////���ַ�������
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdefghijklmnopqrstuvwxyz";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//������
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////2.0  �ݹ�ʵ��
//#include<stdio.h>
//
////������
//void reverse_string(char* string)
//{
//	//�������
//	int static i = 0;
//	int n = strlen1(string);
//	int t = 1;
//	//����
//	t = *(string);
//	*(string) = *(string + n - 1 - i);
//	*(string + n - 1 - i) = t;
//	
//	//�ݹ�,��������
//	//ע��,�ַ������ȷ�Ϊ: ��ż. n - 1 - i�仯���ɲ�ͬ. ����ʱ:2 -> 0;  ż��ʱ:3 -> 1
//	if (n - 1 - i > 1)
//	{
//		i++;
//		reverse_string(string + 1);
//	}
//
//}
//
////���ַ�������
//int strlen1(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + strlen1(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdef123456789";
//	printf("%s\n", arr);
//	printf("%d\n", strlen1(arr));
//	//������
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////3.0  �ݹ�ʵ��  �����Ż�
//#include<stdio.h>
//
////������
//void reverse_string(char* string)
//{
//	//�������
//	int n = my_strlen(string);
//	int t = 1;
//	//����
//	t = *string;//����дΪstring[0]
//	*(string) = *(string + n - 1);//����дΪstring[n-1]
//	*(string + n - 1) = '\0';//�ı�ĩβ,���̶���
//
//	//�ݹ�,��������
//	if (string +1 < string +n -1)//�ȼ���: if(my_strlen(string+1) >= 2)
//	{
//		reverse_string(string + 1);
//	}
//	*(string + n - 1) = t;
//}
//
////���ַ�������
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + my_strlen(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdef1";
//	printf("%s\n", arr);
//	printf("%d\n", my_strlen(arr));
//	//������
//	reverse_string(&arr);
//	printf("%s\n", arr);
//	return 0;
//}


////����Ŀ���ơ�
////����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
////����Ŀ���ݡ�
////дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
////���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
////���룺1729�������19
//
////1729  >  1 729  >  1 7 29
//
//#include<stdio.h>
//
////λ�Ӻͺ���
//int DigitSum(int x)
//{
//	if (x / 10 != 0)
//	{
//		return x % 10 + DigitSum(x / 10);
//	}
//	else
//		return x % 10;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//λ�Ӻͺ���
//	printf("%d", DigitSum(a));
//	return 0;
//}



////����Ŀ���ơ�
////�ݹ�ʵ��n��k�η�
////����Ŀ���ݡ�
////��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
//
////1.0  ˼·:  n^k = n*n^(k-1) = n*n*n....*n	���� n �� k ����������
//
//#include<stdio.h>
//
////n��k�η�����
//int resnk(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * resnk(n, k - 1);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	int k = 1;
//	scanf("%d%d", &n, &k);
//	//n��k�η�����
//	printf("%d", resnk(n, k));
//	return 0;
//}

////2.0  ʵ�ָ�������
//#include<stdio.h>
//
////n��k�η�����
//float resnk(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * resnk(n, k - 1);
//	}
//	else if (0 == k)
//	{
//		return 1;
//	}
//	if(k < 0)
//	{
//		return 1/resnk(n, -k);
//	}
//}
//
//int main()
//{
//	int n = 1;
//	int k = 1;
//	scanf("%d%d", &n, &k);
//	//n��k�η�����
//	printf("%f", resnk(n, k));
//	return 0;
//}


//����Ŀ���ơ�
//����쳲�������
//����Ŀ���ݡ�
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//���磺
//���룺5  �����5
//���룺10�� �����55
//���룺2�� �����1

//˼·: 1 1 2 3 5 8 13 21 34 55 89
//		f(n) = f(n-1) + f(n-2)

////1.0 �ǵݹ�
//#include<stdio.h>
//
////쳲���������
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int i = 1;
//	if (n >= 3)
//	{
//		for (i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	scanf("%d", &n);
//	//쳲���������
//	printf("%d", fib(n));
//	return 0;
//}

////2.0 �ݹ�
//#include<stdio.h>
//
////쳲���������
//int fib(int n)
//{
//	if (n >= 3)
//	{
//		return fib(n-1)+fib(n-2);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 1;
//	scanf("%d", &n);
//	//쳲���������
//	printf("%d", fib(n));
//	return 0;
//}

