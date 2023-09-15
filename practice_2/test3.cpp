//#include <iostream>
//using namespace std;
//
////int main()
////{
////	char s1[] = "const str";
////	const char* s2 = "const str";
////	cout << "s1:" << (void*)s1 << endl;
////	cout << "s2:" << (void*)s2 << endl;
////	cout << "const:" << (void*)"const str" << endl;
////	cout << "ps1:" << &s1 << endl;
////	cout << "ps2:" << &s2 << endl;
////	return 0;
////}
//
//
//int main()
//{
//	class A
//	{
//	public:
//		A(int a = 1, int b = 1)
//			:_a(a)
//			,_b(b)
//		{
//			cout << "A(int a = 1, int b = 1):" << this << endl;
//		}
//
//		~A()		//析构函数可以显示调用
//		{
//			cout << "~A():" << this << endl;
//		}
//	private:
//		int _a;
//		int _b;
//	};
//
//	A* pa = new A(1, 2);
//	delete pa;
//
//	//A* p2 = new A[3]{ (1,2),(2,3),(4,3) };	//不行,不能用(,),逗号表达式取最后一个的值
//	A* p2 = new A[3]{ 1,2,3,};		//失败,看来自定义类型数组初始化只能初始化第一个元素
//
//	delete[] p2;
//	
//	//定位new
//	A* p3 = (A*)malloc(sizeof(A));
//	new(p3)A(10);
//	p3->~A();			//手动调用析构
//	free(p3);
//	//delete(p3);		//这里更应该用free,毕竟空间是malloc的;但是没有调用析构
//
//	A* p4 = (A*)malloc(sizeof(A) * 4);
//	const int num = 3;
//	new(p4)A[num]{ 4,5,6 };			//这里可以用变量,毕竟malloc可以用变量开辟空间,不是直接的数组定义
//	for (int i = 0; i < num; i++)
//	{
//		(p4 + i)->~A();
//	}
//	//delete[] p4;			//不能用delete[] 这里死循环了,或许定位new没有记录需要调用多少次析构
//	//delete p4;			//用delete,然后delete调用free,free函数记录了开辟多大空间,所以释放对应大小;
//	free(p4);				//这里delete只调用了一次析构.	==>总结:这里更应该用free,毕竟空间是malloc的
//
//
//	//operator new(); operator delete();是函数,与malloc类似,不初始化,不调用析构
//	A* p5 = (A*)operator new(sizeof(A));	
//	//new(p5)A;
//	//p5->~A();
//	operator delete(p5);
//
//
//	return 0;
//}