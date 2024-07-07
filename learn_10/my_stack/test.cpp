#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include "Queue.h"

int main()
{
	try
	{
		kozen::test_stack2();
		kozen::test_queue3();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}




	return 0;
}