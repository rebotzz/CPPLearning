#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	char* pa = (char*) & a;
	if (*pa == 1)
	{
		cout << "low bit" << endl;
	}

	return 0;
}