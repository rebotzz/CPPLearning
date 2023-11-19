#include <iostream>
using namespace std;

class A
{
public:
	int a;
	static int b;
};
int A:: b = 1;


int main()
{
	A aa1;
	cout << aa1.b++ << endl;
	A aa2;
	cout << aa2.b++ << endl;
	cout << A::b++ << endl;
	cout << A::b << endl;
	return 0;
}