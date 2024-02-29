#include <iostream>
#include <functional>
using namespace std;

class Func
{
public:
	static void p1()
	{
		cout << "static void p1()" << endl;
	}

	void p2()
	{
		cout << "void p2() -- " << _v << endl;
	}

	void p3(int val)
	{
		cout << "void p3(int val)  -- " << val << endl;
	}
private:
	int _v = 1;
};

int main()
{
	function<void(void)> f1 = []() {cout << "[](){cout}" << endl; };
	//function<void(void)> f2 = &Func::p1;
	function<void(void)> f2 = Func::p1;
	function<void(Func)> f3 = &Func::p2;
	function<void(Func, int)> f4(&Func::p3);
	function<void(Func*)> f5 = &Func::p2;	// 指针不如直接对象好，因为：匿名对象，右值不能取地址

	f1();
	f2();
	f3(Func());
	Func tmp;
	f4(tmp, 3);
	cout << "---------" << endl;
	//f5(&Func());	// 右值不能取地址
	f5(&tmp);


		return 0;
}