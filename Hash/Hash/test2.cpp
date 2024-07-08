//#include <iostream>
//using namespace std;
//
//void test2_1()
//{
//	int a = 1;
//	char* pa = (char*)&a;
//	if (*pa == 1)
//	{
//		cout << "low bit" << endl;
//	}
//}
//
//class TEST2
//{
//public:
//	TEST2()
//		:arr(nullptr)
//	{
//		arr = new int[10];
//	}
//
//	~TEST2()
//	{
//		cout << "~TEST2()" << endl;
//		delete[] arr;
//	}
//
//private:
//	int* arr;
//};
//
//class Derive2
//{
//public:
//	Derive2()
//		:a2(0)
//	{
//
//	}
//
//	~Derive2()
//	{
//		cout << "~Derive2()" << endl;
//	}
//
//private:
//	int a2;
//	TEST2 t2;	// 自定义类型会自定调用构造和析构,哪怕显示写的没有
//};
//
//void test2_2()
//{
//	Derive2 d2;
//}
//
//int main()
//{
//	test2_2();
//
//	return 0;
//}