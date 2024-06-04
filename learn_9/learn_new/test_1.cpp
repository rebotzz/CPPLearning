#include <iostream>

using namespace std;

class A
{
	int _a;
public:
	A()
	{
		cout << "A()" << endl;
	}
};

int main()
{
	A* pp1 = (A*)malloc(sizeof(A));		//没有初始化,这个编译器,别的编译器未知


	return 0;
}