#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class A
{
public:
	class C
	{
	public:
		int _c = 15;
	};

	void test()
	{
		class B bb;
		bb._b = 1;
		cout << bb._b << endl;
	}
private:
	int _a;

	//I think:
	//�ڲ������ⲿ�ڼ���û�й�ϵ
	//�����ڲ�������������ⲿ�ڷ�Χ��
	//�ڲ��ඨ��������û�й�ϵ
	class B
	{
	public:
		int _b = 12;
	};
};

//int main()
//{
//	A().test();
//	class A a1;
//	//class B b1;
//	//class C c1;
//	A a2;
//	A::C c1;
//	//A::B b1;	 //�ܵ������޶���������
//	
//
//	return 0;
//}


int main()
{
	//����,���� \
	ע��Ҳ������
	int a = 3 + \
		5;		
	cout << a << endl;

	int b = 3 +
		2;
	cout << b << endl;
	cout << "a:"
		<< a <<
		endl;
#define AA (3 + \
				7)
	cout << AA << endl;

	return 0;
}