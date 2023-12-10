#include <iostream>
using namespace std;

// 可变模板参数学习

template<class T>
void func1(T x)	// 递归终止函数
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
	cout << (sizeof...(Args) + 1) << endl;	// 打印参数个数

	// 解析参数
	cout << "void func1(T x, Args ... args): " << x << endl;

	func1(args...);		// 当参数args...个数为1时,不在调用自己,结束递归

}


int main()
{
	func1();
	func1(1);
	func1(1, 'c', "string size");
	func1(1, 15, "string size", "zhang");

	return 0;
}