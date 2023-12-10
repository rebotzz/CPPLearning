#include <iostream>
using namespace std;

// �ɱ�ģ�����ѧϰ

template<class T>
void func1(T x)	// �ݹ���ֹ����
{
	cout << "void func1(T x): " << x << endl;
}

void func1()
{
	cout << "void func1()" << endl;
}

//template<class ...Args>
//void func1(Args ... args)
template<class T, class ...Args>
void func1(T x, Args ... args)
{
	cout << (sizeof...(Args) + 1) << endl;	// ��ӡ��������

	// ��������
	cout << "void func1(T x, Args ... args): " << x << endl;

	func1(args...);		// ������args...����Ϊ1ʱ,���ڵ����Լ�,�����ݹ�

}


int main()
{
	func1();
	func1(1);
	func1(1, 'c', "string size");
	func1(1, 15, "string size", "zhang");

	return 0;
}