#include <iostream>
using namespace std;

class A
{
public:
	const static int a = 10; // const static可以
	int b = 11;
	static int c;// = 12;	//static不可以，需要在类外初始化
public:
	A()
	{}
	~A()
	{}

private:

};
int A::c = 12;

enum B
{
	a = 1,
	b = 2,
	c = 3
};

union Un
{
	int i;
	char c;
};
union Un un;



int main()
{
	A a;
	cout << a.a << endl;
	cout << a.b << endl;
	cout << a.c << endl;

	//B bb = 1;	//枚举类型不能用int初始化，即使都是int，需要用其成员
	B cc = B::a;

	// 下面输出的结果是一样的吗？
	printf("%d\n", &(un.i));
	printf("%d\n", &(un.c));
	//下面输出的结果是什么？
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);

	return 0;
}