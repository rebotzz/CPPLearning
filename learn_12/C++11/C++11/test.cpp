#include <iostream>

using namespace std;

class A
{
public:
	void f()
	{
		cout << "A" << endl;
	}

	A(int a = 10):_a(a)
	{}

	int _a;
};

//ʹ�ùؼ���classʱĬ�ϵļ̳з�ʽ��private��ʹ��structʱĬ�ϵļ̳з�ʽ��public
class B : A	// ����Ĭ��private�̳�
//class B : public A	
{
public:
	void f(int)	// ��������ͬ���̳У�-- ����
	{
		cout << "B" << endl;
	}

	void test()
	{
		cout << _a << " " << _b << endl;
	}

	// �ȵ���A����
	B(int b = 11, int a = 102) :_b(b)//,A(a)	
	{}

	int _b;
};

class C
{

};

class D : public C
{

};


//int main()
//{
//	B b;
//	b.test();
//	//b.f();
//	//b.f(1);
//	//b.A::f();	// ��������
//	return 0;
//}