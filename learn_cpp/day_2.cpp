#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//inline 内联函数替代宏函数
//auto 自动识别类型,范围for
//struct class public private protected 类/封装 成员函数,成员变量

#define ADD(x,y) ((x)+(y))


inline int add(int x, int y)
{
	return x + y;
}



//int main()
//{
//	int arr[100];
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		arr[i] = i;
//	}
//	
//	for (auto& e : arr)
//	{
//		e++;
//	}
//
//	//范围for
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//typedef char* pstring;
//int main()
//{
//	const pstring p1 ;    // 编译成功还是失败？
//	const pstring* p2;   // 编译成功还是失败？
//	return 0;
//}


//int main()
//{
//	cout << NULL << endl;
//	printf("%p\n", nullptr);
//	int a = 0;
//	cout << &a << endl;
//	return 0;
//}