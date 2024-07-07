#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//extern "C"
//{
//#include"D:/develop/code/git-repository/week_7/Heap/Heap.h"
//}


//int main()
//{
//	Heap hp;
//	int a[] = { 5,6,8,13,8,48,3,1,8,13 };
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
//	HeapSort(&hp);
//	for (int i = 0; i < hp._size; i++)
//	{
//		cout << hp._a[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//
////内联函数 展开
//inline void func()
//{
//	cout << 1 << endl;
//
//}
//
////struct升级为类,默认public
//struct n1
//{
//	int add(int x = 0, int y = 1)
//	{
//		return x + y;
//	}
//
//	double add(double x, double y = 3.1)
//	{
//		return x + y;
//	}
//
//	void func1()
//	{
//		cout << "a b da db " << endl << a << " " << b << " " << da << " " << db << " " << endl;
//	}
//
//private:
//	int a = 1;
//	int b = 2;
//	double da = 2.5;
//	double db = 3.7;
//
//};
//
////类,默认private
//class n2
//{
//protected:
//	struct stack
//	{
//		int* _a;
//		int _size;
//		int _capacity;
//	};
//
//
//
//public:
//	void stackInit(stack& s)
//	{
//		s._a = nullptr;
//		s._capacity = s._size = 0;
//	}
//
//	void stackPush(stack& s, int x)
//	{
//		//...
//	}
//
//	void stackPop(stack& s)
//	{
//		//...
//	}
//
//	stack n;
//};

//int main()
//{
//	func();
//	//n1 n;
//	//auto ret = n.add(2,5);
//	//cout << ret << " " << n.add(2.1, 5.4) << " " << n.add(2.5) << endl;
//	//n.func1();
//
//	//n2 n;
//	//n.stackInit(n.n);
//
//	//cout << n.n._capacity << " " << n.n._size << endl;
//
//	return 0;
//}


//传递引用
//相当于给实参取别名 x , y ;修改x和y就相当于修改a,b
void swap(int& x, int& y)
{
	auto tmp = x;
	x = y;
	y = tmp;
}

//int main()
//{
//	int a = 9;
//	int b = 3;
//	cout << a << " " << b << " "<<endl;
//	swap(a, b);
//	cout << a << " " << b << " " << endl;
//
//	return 0;
//}

void funcA(int& x)
{
	
}

void funcB(int x)
{

}

#include <time.h>

//int main()
//{
//	int a = 0;
//
//	size_t begin1 = clock();
//	for (int i = 0; i < 1000000000; i++)
//	{
//		funcA(a);
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (int i = 0; i < 1000000000; i++)
//	{
//		funcB(a);
//	}
//	size_t end2 = clock();
//
//	cout << "funcA:传引用调用 " << end1 - begin1 << endl;
//	cout << "funcB:传值调用 " << end2 - begin2 << endl;
//
//	return 0;
//}


//1. 引用在定义时必须初始化
//2. 一个变量可以有多个引用
//3. 引用一旦引用一个实体，再不能引用其他实体

//int main()
//{
//	//引用:读写权限不能放大,可以缩小
//	int n = 0;
//	int& nn = n;
//	const int m = NULL;
//	const int& mm = m;
//
//	float f = 2.1;
//	float& ff = f;
//	const int& fff = f;//类型转化,在一个临时空间转化,这个临时空间具有const性质
//	const int& a = 0; //常数具有const性质
//
//	return 0;
//}