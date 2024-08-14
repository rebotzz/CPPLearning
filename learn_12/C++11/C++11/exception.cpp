#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


void fun() //noexcept	// 有了noexcept, 内部抛异常会abort()中止程序，不会捕获异常
{
	int x;
	cin >> x;
	if (0 == x)
		throw "error, 0 == x";
	else if (-1 == x)
	{
		throw string("error, -1 == x");
	}

	else if (-2 == x)
		throw 30.0513;
		


	cout << x << endl;
}

void f() //noexcept	间接抛异常不会warning，但是抛异常会abort()中止程序
{
	fun();
}

//int main()
//{
//	printf("error 3: %s\n", strerror(3));
//
//	while (true)
//	{
//		try
//		{
//			f();
//		}
//		catch (const char* str)
//		{
//			cout << str << endl;
//		}
//		catch (const string& msg)
//		{
//			cout << msg << endl;
//		}
//		catch (...)
//		{
//			cout << "未知错误" << endl;
//		}
//
//	}
//
//	return 0;
//}