#define _CRT_SECURE_NO_WARNINGS

//const ����ָ��
//#include <stdio.h>
//#include <assert.h>
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	//const int* pa = &a;	//const�� * ��� �� �ұ� �ֱ����� *p �� p
//	//int const* pb = &b;	//ָ������ �� ָ������洢ֵ
//	//*pa = 1;
//	//*pb = 2;
//	//pa = &b;
//
//	//int* const pa = &a;
//	//int* const pb = &b;
//	//*pa = 3;
//	//pa = &b;
//
//	//const int a = 0;	//const ���κ� ������
//	//int const b = 1;
//	const int* const pa = &a;
//	int const* const pb = &b;
//	//pa = &b;
//	//*pa = b;
//	a = 10;
//	b = 20;
//
//	//assert(a != 10);//����	ֵΪ�� ����assert
//	int** ppa = &pa;//����ָ��
//	const int* const* const ppb = &pb;
//
//	return 0;
//}


//ģ�� strlen
#include <stdio.h>
#include <assert.h>

//1.0
//size_t my_strlen(const char* str)//�Ż�,���Ȳ�Ϊ����	size_t  ->  unsigned int
//{
//	assert(str != NULL);//����
//	//assert(str); //��ָ�� ֵΪ0 ��
//	size_t count = 0;
//	//while (*str++ != '\0')//while(*str++)
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}

////2.0
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);//����
//	char* start = str;
//	while (*str++)
//	{
//	}
//	return str - start - 1;//ָ�����,����Ԫ�ظ���
//}
//int main()
//{
//	char arr[] = "12345678";
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}


//ģ�� strcpy
#include <stdio.h>
#include <assert.h>

//1.0
//void my_strcpy(char* dest, char* src)
//{
//	assert(src != NULL);//����
//	assert(dest != NULL);
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}

////2.0
//char* my_strcpy(char* dest,const char* src)//consr �޶� *src���ܸ�
//{
//	assert(src != NULL);//����
//	assert(dest != NULL);
//	char* start = dest;
//	while (*dest++ = *src++)//'\0' ASCCI��ֵ Ϊ0
//	{
//		;
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[30] = "xxxxxxxxxxxxxxxxxxxxxxxx";
//	char arr2[] = "12345678hello";
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

//����Ŀ���ơ�
//ͳ�ƶ�������1�ĸ���
//����Ŀ���ݡ�
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1
#include <stdio.h>

//1.0
//int NumberOf1(int n)
//{
//    // write code here
//    int i = 0;
//    int count = 0;
//    for (i = 31; i >= 0; i--)
//    {
//        if (((n >> i) & 1))
//        {
//            count++;
//        }
//    }
//    return count;
//}

//2.0
//int NumberOf1(unsigned int n)
//{
//    // write code here
//    int i = 0;
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n /= 2; //��2 �ȼ��� ����������һλ
//    }
//    return count;
//}

//3.0
//int NumberOf1(int n)//�������� 1 �ĸ���
//{
//    // write code here
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n = n & (n - 1);//ÿ����һ�� 1
//    }
//    return count;
//}
//
//int main()
//{
//    int a = 0;
//    scanf("%d", &a);
//    int ret = NumberOf1(a);
//    printf("%d\n", ret);
//    return 0;
//}


//����Ŀ���ơ�
//���������������в�ͬλ�ĸ���
//����Ŀ���ݡ�
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
#include <stdio.h>

//1.0
//size_t diff(int x, int y)//�����Ʋ�ͬλ�ĸ���
//{
//	int i = 0;
//	size_t count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((x >> i) & 1) != (((y >> i) & 1)))
//			count++;
//	}
//	return count;
//}

//2.0
//int NumberOf1(int n)
//{
//     write code here
//    int count = 0;
//    while (n)
//    {
//        count++;
//        n = n & (n - 1);//ÿ����һ�� 1
//    }
//    return count;
//}
//size_t diff(int x, int y)
//{
//	size_t count = 0;
//	int n = x ^ y;
//	count = (unsigned int)NumberOf1(n);
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	size_t ret = diff(a, b);
//	printf("%d\n", ret);
//	return 0;
//}


////����Ŀ���ơ�
////��ӡ���������Ƶ�����λ��ż��λ
////����Ŀ���ݡ�
////��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 31; i >= 1; i -=2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//	return 0;
//}


////�ж�һ�����Ƿ�Ϊ 2 �ļ��η�
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//��������ֻ��һ��1;������� 1 ���Է���ĩβ ,2^0 =1;����ȫ��0
//	int n = a;
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	if (count == 1)
//		printf("%d ��2���������η�\n",a);
//	return 0;
//}

////���� ջ ��ɵ���ѭ��
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//�������ڴ���,�ȴ���arr[],�����±�����,��ַ�е͵���
//    int i = 0;                           //��vs2022�汾,�ڴ����5��int*ָ��ռ�,Ȼ�󴴽��� i
//    for (i = 0; i <= 15; i++)            //������Խ�����,���˵�6��Խ����ʵĵ�ַ,������i �ĵ�ַ
//    {
//        arr[i] = 0;                      //i��ֵ��15���޸�Ϊ0;������ѭ��;ϵͳ�޷�����
//        printf("hello bit\n");
//    }
//    return 0;
//}

//
////����Ŀ���ơ�
////��������ż��˳��
////����Ŀ���ݡ�
////��������ʹ����ȫ����λ��ż��ǰ�档
////��Ŀ��
////����һ���������飬ʵ��һ��������
////�����������������ֵ�˳��ʹ�����������е����� λ�������ǰ�벿�֣�
////����ż�� λ������ĺ�벿�֡�
#include <stdio.h>

//����ż���� �ֱ� ���մ�С����
void sort_part(int* arr, int left, int right)
{
	int i = 0;
	int tmp = 0;
	for (i = left - 1; i > 0; i--)//������������
	{
		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])//��������
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = right - 1; i > left; i--)//ż����������
	{
		int j = left;
		for (j = left; j < i; j++)
		{
			if (arr[j] > arr[j + 1])//��������
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
////��ż������ 1.0
//int sort_parity(int arr[], int sz)
//{
//	int i = 0;
//	int left = 0;//�˵�
//	int tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] % 2)//����
//		{
//			//������λ��ǰ����,������λ����ǰ��,��ô����ֻ��ż��λ��
//			tmp = arr[left];
//			arr[left] = arr[i];
//			arr[i] = tmp;
//			left++;
//		}
//	}
//	return left;//�������һ��������ŵ���һλ,����һ��ż�����
//}

////��ż������	2.0
//int sort_parity(int arr[], int sz)
//{
//	int left = 0;//�˵�
//	int right = sz - 1;
//	int tmp = 0;
//	//left ��Ӧ�����ż�� �� right �����Ӧ����������
//	while (left < right)
//	{
//		while (((arr[left] % 2) == 1) && (left < right))//����ż��ֹͣ
//		{
//			left++;
//		}
//		while (((arr[right] % 2) == 0) && (left < right))//��������ֹͣ
//		{
//			right--;
//		}
//		if (left < right)//����
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//	return left+1;//�������һ��������ŵ���һλ,����һ��ż�����
//}
//
//int main()
//{
//	int arr[41] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//��ʼ��
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//	//arr[2] = 91;//��֤��������
//	//��ӡ
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//������ż˳��
//	int start_2 = sort_parity(arr,sz);//ż��λ��ʼλ��
//	//����ż���� �ֱ� ���մ�С����
//	sort_part(arr, start_2, sz);
//	//��ӡ
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}