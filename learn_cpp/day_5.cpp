//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "head.h"
//using namespace std;
//
//
//
////类大的小计算
////类似结构体大小,有对齐规则
////类成员函数不计入大小计算,存放在公共代码段
////空类的大小为1字节,目的:保留地址
//// 
////类比:函数开辟栈帧也要计算大小.函数所占空间大小
////这可能就是arr[]在开辟的函数内能用sizeof计算大小(int(*p)[count]数组指针),
////但是传递给别的函数却只是int*指针,计算不了大小,一个解释
////当然也可能有数组指针变成int*的原因
//
//class S1
//{
//public:
//	void print(const char* str = "hello world.")
//	{
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//
//	}
//
//private:
//	int b;
//	char a;
//	char c;
//
//};
//
//class S2
//{
//public:
//	void func()
//	{
//		cout << "S2:func" << endl;
//	}
//};
//
//class S3
//{
//
//};
//
////类的大小计算
//void Test1()
//{
//	cout << sizeof(S1) << endl;
//	cout << sizeof(S2) << endl;
//	cout << sizeof(S3) << endl;
//}
//
////类实例化对象
//void Test2()
//{
//	S1 a;
//	S1 b;
//	//a.print("1231");
//	//b.print();
//
//	S1* ps;
//	ps = nullptr;
//	ps->print();
//
//	//大小端测试
//	//大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
//	//小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位, ，保存在内存的高地址中。
//	int n = 1;
//	char* pn = (char*)&n;
//	printf("%d\n", *pn);
//	if (*pn == 1)
//	{
//		cout << "小端" << endl;
//	}
//
//}
//
//
////类的作用域,声明和定义分离
//void Test3()
//{
//	PART p;
//	p.print();
//}
//
//
//
////类的 this指针
////用于区分不同类实例化对象
//void Test4()
//{
//	class S
//	{
//	public:
//		//构造函数,初始化
//		S(int a = 0, int b = 0, int c = 0)
//		{
//			_a = a;
//			_b = b;
//			this->_c = c;
//		}
//
//		//析构函数,对象销毁时释放资源
//		~S()
//		{
//			//目前:无malloc,fopen,不用
//			cout << this<<"->"<<"~S" << endl;
//		}
//
//		//拷贝构造函数
//		S(const S& src)
//		{
//			this->_a = src._a;
//			this->_b = src._b;
//			//this指针可以省略不写,毕竟在this指向的类中
//			_c = src._c;
//		}
//
//		//this
//		void printThis()
//		{
//			//this = nullptr; //this指针具有const属性,不能更改
//			cout << this << endl;
//			cout << this->_a << endl;
//			cout << (*this)._b << endl;
//			cout << _c << endl << endl;
//		}
//
//
//	private:
//		int _a;
//		int _b;
//		int _c;
//	};
//
//
//	S n1(1,2,3);
//	S n2;
//	S n3(1, 2);
//	S n4(n1);
//
//	n1.printThis();
//	n2.printThis();
//	n3.printThis();
//	n4.printThis();
//}
//
//void get(Date d)
//{
//	d.print();
//}
//
//void Test5()
//{
//	Date d1;
//	Date d2(2023, 8, 26);
//	Date d3 = d2;
//	d1.print();
//	d1.Init(2000, 2, 5);
//	cout << endl;
//	d1.print();
//	d2.print();
//	d3.print();
//
//	Date d(d1);
//	cout << "d:";
//	d.print();
//	get(d);
//
//}
//
//
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	while (!s.IsEmpty())
//	{
//		cout << s.Top() << " ";
//		s.Pop();
//		//cout << s.Size() << endl;
//	}
//}
//
//
//void TestMyqueue()
//{
//	MyQueue q;
//	q.print();
//}
//
////int main()
////{
////	//Test1();
////	//Test2();
////	//Test3();
////	//Test4();
////	Test5();
////	//TestStack();
////	//TestMyqueue();
////
////	return 0;
////}