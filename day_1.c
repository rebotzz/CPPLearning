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


////ģ�� strlen
//#include <stdio.h>
//#include <assert.h>
//
//// size_t unsigned int
//size_t my_strlen(const char* str)//�Ż�,���Ȳ�Ϊ����
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
//int main()
//{
//	char arr[] = "12345678";
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}


//ģ�� strcpy