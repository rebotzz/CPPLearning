#define _CRT_SECURE_NO_WARNINGS
#include "string.h"

int main()
{
	try
	{
		kozen::string_test4();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}