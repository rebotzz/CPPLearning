#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Test
{
public:
	Test()
		:_a(1)
	{}
	Test(const Test& t)
		:_a(2)
	{}
private:
	int _a;
};

int main()
{
	Test a;
	Test b = a;
	return 0;
}