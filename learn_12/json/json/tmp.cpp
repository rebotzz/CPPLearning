#include <iostream>
using namespace std;

class A
{
public:
	const static int a = 10; // const static����
	int b = 11;
	static int c;// = 12;	//static�����ԣ���Ҫ�������ʼ��
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

	//B bb = 1;	//ö�����Ͳ�����int��ʼ������ʹ����int����Ҫ�����Ա
	B cc = B::a;

	// ��������Ľ����һ������
	printf("%d\n", &(un.i));
	printf("%d\n", &(un.c));
	//��������Ľ����ʲô��
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);

	return 0;
}