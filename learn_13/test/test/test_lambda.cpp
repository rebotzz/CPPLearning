#include <iostream>
using namespace std;


int main()
{
	int a = 10;
	cout << a << endl;
	auto foo = [&]()
		{
			a = 20;
		};

	foo();
	cout << a << endl;

	return 0;
}