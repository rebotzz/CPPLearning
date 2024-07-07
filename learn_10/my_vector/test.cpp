#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//using namespace std;

#include "vector.h"
#include <string.h>

//int main()
//{
//	//vector<int> v1(5);
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
// //可以这样初始化
//	vector<string> numLetter = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//	for (auto e : numLetter)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}


#define TEST
int main()
{
#ifdef TEST
	try
	{
		kozen::test_vector7();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
#endif

	//nullptr不处理
	int* p = nullptr;
	delete p;

	//第一次先判断,再执行
	//for (int i = 0; i < 0; ++i)
	//{
	//	cout << "hello" << endl;
	//}



	return 0;
}