#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include "Queue.h"

int main()
{
	try
	{
		//kozen::test_stack1();
		kozen::test_queue2();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}




	return 0;
}