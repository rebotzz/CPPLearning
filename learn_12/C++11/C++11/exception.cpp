#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


void fun() //noexcept	// ����noexcept, �ڲ����쳣��abort()��ֹ���򣬲��Ჶ���쳣
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

void f() //noexcept	������쳣����warning���������쳣��abort()��ֹ����
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
//			cout << "δ֪����" << endl;
//		}
//
//	}
//
//	return 0;
//}