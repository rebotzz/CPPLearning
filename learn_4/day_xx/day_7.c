#define _CRT_SECURE_NO_WARNINGS



//����Ŀ���ơ�
//���������������в�ͬλ�ĸ���
//����Ŀ���ݡ�
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7

//#include <stdio.h>
//
////�ж�c�Ķ��������м��� 1
//int count(int x)
//{
//	int num = 0;
//	//�����10������λ��
//	while (x > 0)
//	{
//		if (x % 2 == 1)
//			num++;
//		x = x >> 1;
//		//�ȼ���  (�����10����)
//		//x = x / 2;
//	}
//	return num;
//}
//
// //������
////int calc_diff_bit(int m, int n)
////{
////	int tmp = m ^ n;
////	int count = 0;
////	while (tmp)
////	{
////		tmp = tmp & (tmp - 1);
////		count++;
////	}
////	return count;
////}
// 
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;//��λ���
//	//�ж�c�Ķ��������м��� 1
//	printf("%d\n", count(c));
//	//int m = -1;
//	//printf("%d", m >> 1);//ִ����������,��λ������λ 1
//	return 0;
//}


//����Ŀ���ơ�
//��ӡ���������Ƶ�����λ��ż��λ
//����Ŀ���ݡ�
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

//1.0 ����һ
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	
//	if (set == 0)//ż��
//	{
//		static int times = sizeof(int) * 8;//static ����,�������ڸı�,�����򲻱�
//		if (times == sizeof(int) * 8)
//		{
//			x = x >> 1;
//			times--;
//			printf("\nż��λ:");
//		}	
//		while (times > 0)
//		{
//			my_print(x >> 2, (times -= 2,0));
//			printf("%d ", x % 2);
//		}
//	}
//
//	if (set == 1)//����
//	{
//		static int times = sizeof(int) * 8;//static ����,�������ڸı�,�����򲻱�
//		if (times == sizeof(int) * 8)
//		{
//			printf("\n����λ:");
//		}
//		while (times > 0)
//		{
//			my_print(x >> 2, (times -= 2,1));
//			printf("%d ", x % 2);
//		}
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//�ֱ��ӡ  ż��λ������λ
//	my_print(a, 0);//ż��λ
//	my_print(a, 1);//����λ
//	return 0;
//}

//2.0 �����Ż�
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	int i = 32;
//	if (set == 0)//ż��
//	{
//		x >>= 1;
//		for (i = 31; i > 0; i = i - 2)
//		{
//			printf("%d ", x & 1);
//			x = x >> 2;
//		}
//	}
//
//	if (set == 1)//����
//	{
//		for (i = 32; i > 0; i -= 2)
//		{
//			printf("%d ", x & 1);
//			x = x >> 2;
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//�ֱ��ӡ  ż��λ������λ
//	my_print(a, 0);//ż��λ
//	my_print(a, 1);//����λ
//	return 0;
//}

//3.0 �����Ż�
//#include <stdio.h>
//
//void my_print(int x, int set)
//{
//	int i = 32;
//	if (set == 0)//ż��
//	{
//		for (i = 31; i > 0; i = i - 2)
//		{
//			printf("%d ",(x>>i) & 1);
//		}
//	}
//
//	if (set == 1)//����
//	{
//		for (i = 30; i >= 0; i -= 2)
//		{
//			printf("%d ",( x>>i ) & 1);
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//�ֱ��ӡ  ż��λ������λ
//	my_print(a, 0);//ż��λ
//	my_print(a, 1);//����λ
//	return 0;
//}


//����Ŀ���ơ�
//ͳ�ƶ�������1�ĸ���
//����Ŀ���ݡ�
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1

//#include <stdio.h>
//
////��������1��������
//int count(int x)
//{
//	int i = 31;
//	int sum = 0;
//	for (i = 31; i >= 0; i--)
//	{
//		if ((x >> i) & 1)
//		{
//			sum++;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//��������1��������
//	printf("%d \n",count(a));
//	return 0;
//}


//����Ŀ���ơ�
//����������������������ʱ������
//����Ŀ���ݡ�
//����������ʱ������������������������

//#include <stdio.h>
//
//int main()
//{
//	int a = 4;
//	int b = 5;
//	printf("%d %d \n", a, b);
//	a = a ^ b;
//	b = a ^ b;  // <==>  (a^b)^b <==>  a^(b^b)  <==>  a ^ 0  -> a
//	a = a ^ b;  // <==>  (a^b)^a <==> a^a^b  <==>  b
//	printf("%d %d \n", a, b);
//	return 0;
//}

//�����е�  ->  �������� �� ����ת��
//#include <stdio.h>
//int i;//ȫ�ֱ�������ֵ,Ĭ��Ϊ 0
//int main()
//{
//    i--;
//    //unsigned int b = i;   �ȼ��� if(b > sizeof(i))
//    if (i > sizeof(i))//sizeof(i) ����ֵΪ unsigned int ,��ϵ���ʽҪ����,�͵ð���� i ����ǿ��ת�� -> unsigned int 
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}


//����Ŀ���ơ�
//�������
//����Ŀ���ݡ�
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

//1.0
//#include <stdio.h>
//#include <math.h>
//
//int Sn(int x,int n)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		for (int j = i; j >= 0; j--)
//		{
//			//tmp = tmp + x * (10 ^ j);//error: �ⲻ��MATLAB, ^ �������ݺ���,���� ��λ���
//			tmp = tmp + x * pow(10, j);//�� math.h ���е��ݺ����� 10^j 
//
//		}
//		sum = sum + tmp;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a,&n);
//	//��ͺ���
//	printf("%d\n",Sn(a,n));
//	return 0;
//}

////2.0   �����Ż�
//#include <stdio.h>
//
//int Sn(int x, int n)
//{
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//	for (i = 0; i < n; i++)
//	{
//		tmp = x + tmp*10;
//		sum = sum + tmp;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//��ͺ���
//	printf("%d\n", Sn(a, n));
//	return 0;
//}

////3.0	�����Ż�
//#include <stdio.h>
//
//int Sn(int x, int n)
//{
//	int sum = 0;
//	int tmp = 0;
//	while(n--)
//	{
//		tmp = x + tmp * 10;
//		sum = sum + tmp;
//	}
//	return sum ;
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//��ͺ���
//	printf("%d\n", Sn(a, n));
//	return 0;
//	return 0;
//}

////3.0	�ݹ�ʵ��
//#include <stdio.h>
//#include <math.h>
//
//int Sn(int x, int n)
//{
//	int tmp = 0;
//	int i = n;
//	if (n == 1)
//		return x;
//	while (i--)
//	{
//		tmp += x * pow(10, i);
//	}
//	return tmp + Sn(x, n - 1);
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	//��ͺ���
//	printf("%d\n", Sn(a, n));
//	return 0;
//	return 0;
//}


//����Ŀ���ơ�
//��ӡˮ�ɻ���
//����Ŀ���ݡ�
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

//1.0
//#include <stdio.h>
//#include <math.h>
//
////i �Ĵη���
//int sum_pow(int x,int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	int n = 1;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//��λ�� n
//		for (int j = 0; j <= 5; j++)
//		{
//			if ((i >= pow(10, j)) && (i < pow(10,j+1)))//0^0 = 1 10^0 = 1
//			{
//				n = j + 1;
//				break;
//			}
//			if (i == 0)
//				break;
//		}
//
//		//i �Ĵη���
//		if (sum_pow(i, n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}

////2.0  �����Ż�
//#include <stdio.h>
//#include <math.h>
//
////i �Ĵη���
//int sum_pow(int x,int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
////��λ�� n
//int nit(int x)
//{
//	if (x < 10)
//	{
//		return 1;
//	}
//	return 1 + nit(x / 10);
//}
//
//int main()
//{
//	int i = 0;
//	int n = 1;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//��λ�� n
//		n = nit(i);
//
//		//i �Ĵη���
//		if (sum_pow(i,n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}


//3.0  �����Ż�
//#include <stdio.h>
//#include <math.h>
//
////i �Ĵη���
//int sum_pow(int x, int n)
//{
//	int sum = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + pow((x % 10), n);
//		x = x / 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//��λ�� n
//		int n = 1;
//		tmp = i;
//		while (tmp / 10)	//һ�ֲ������λ���ķ���
//		{
//			n++;
//			tmp /= 10;
//		}
//
//		//i �Ĵη���
//		if (sum_pow(i, n) == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//	return 0;
//}


//����Ŀ���ơ�
//ʹ��ָ���ӡ��������
//����Ŀ���ݡ�
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣

//#include <stdio.h>
////��ӡ����
//void print(int * p,int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,100,7,8,9,10 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);//int * ptr = arr ; *ptr
//	int sz = sizeof(arr) / sizeof(*arr);
//	//��ӡ����
//	print(&arr[0],sz);
//	return 0;
//}