#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include "list.h"

using namespace std;

//#define TEST1
#ifdef TEST1
class A
{
public:
	class C
	{
	public:
		int _c = 15;
	};

	void test() const
	{
		class B bb;
		bb._b = 1;
		cout << bb._b << endl;
	}
private:
	int _a = 3;

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

int main()
{
	//const����
	//Ȩ�޿�����С,���ܷŴ�;
	//��const���Ե���const����,constֻ�ܵ���const����
	A aa;
	aa.test();
	const A aa2;
	aa2.test();
	return 0;
}

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


//int main()
//{
//	//����,���� \
//	ע��Ҳ������
//	int a = 3 + \
//		5;		
//	cout << a << endl;
//
//	int b = 3 +
//		2;
//	cout << b << endl;
//	cout << "a:"
//		<< a <<
//		endl;
//#define AA (3 + \
//				7)
//	cout << AA << endl;
//
//	return 0;
//}

#endif


void test1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);

	list<int>::iterator it = lt1.begin();
	while (it != lt1.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	lt1.push_front(10);
	it = lt1.begin();
	++it;
	++it;
	lt1.insert(it, 30);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.pop_back();
	lt1.pop_front();
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	it = find(lt1.begin(), lt1.end(), 3);
	*it = 24;
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.erase(it);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.clear();
	lt1.push_front(1);
	lt1.push_front(2);
	lt1.push_front(3);
	lt1.push_front(4);

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	it = lt1.begin();
	while (it != lt1.end())
	{
		it = lt1.erase(it);
		//it++;
	}



}




int main()
{
	//test1();

	kozen::test_list8();

	return 0;
}