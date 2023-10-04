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
	//内部类与外部内几乎没有关系
	//但是内部类的作用域在外部内范围内
	//内部类定义在哪里没有关系
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
//	//A::B b1;	 //受到访问限定符的限制
//	
//
//	return 0;
//}


int main()
{
	//换行,续接 \
	注释也被接续
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