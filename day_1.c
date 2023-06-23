#define _CRT_SECURE_NO_WARNINGS

//const 修饰指针
//#include <stdio.h>
//#include <assert.h>
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	//const int* pa = &a;	//const在 * 左边 和 右边 分别修饰 *p 和 p
//	//int const* pb = &b;	//指向内容 和 指针变量存储值
//	//*pa = 1;
//	//*pb = 2;
//	//pa = &b;
//
//	//int* const pa = &a;
//	//int* const pb = &b;
//	//*pa = 3;
//	//pa = &b;
//
//	//const int a = 0;	//const 修饰后 常变量
//	//int const b = 1;
//	const int* const pa = &a;
//	int const* const pb = &b;
//	//pa = &b;
//	//*pa = b;
//	a = 10;
//	b = 20;
//
//	//assert(a != 10);//断言	值为假 触发assert
//	int** ppa = &pa;//二级指针
//	const int* const* const ppb = &pb;
//
//	return 0;
//}


////模拟 strlen
//#include <stdio.h>
//#include <assert.h>
//
//// size_t unsigned int
//size_t my_strlen(const char* str)//优化,长度不为负数
//{
//	assert(str != NULL);//断言
//	//assert(str); //空指针 值为0 假
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


//模拟 strcpy