#include <iostream>
using namespace std;

//int main()
//{
//	char s1[] = "const str";
//	const char* s2 = "const str";
//	cout << "s1:" << (void*)s1 << endl;
//	cout << "s2:" << (void*)s2 << endl;
//	cout << "const:" << (void*)"const str" << endl;
//	cout << "ps1:" << &s1 << endl;
//	cout << "ps2:" << &s2 << endl;
//	return 0;
//}


int main()
{
	class A
	{
	public:
		A(int a = 1, int b = 1)
			:_a(a)
			,_b(b)
		{
			cout << "A(int a = 1, int b = 1):" << this << endl;
		}

		~A()
		{
			cout << "~A():" << this << endl;
		}
	private:
		int _a;
		int _b;
	};

	A* pa = new A(1, 2);
	delete pa;

	//A* p2 = new A[3]{ (1,2),(2,3),(4,3) };	//不行,不能用(,),逗号表达式取最后一个的值
	A* p2 = new A[3]{ 1,2,3,};		//失败,看来自定义类型数组初始化只能初始化第一个元素

	delete[] p2;

	return 0;
}