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
// //����������ʼ��
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

	//nullptr������
	int* p = nullptr;
	delete p;

	//��һ�����ж�,��ִ��
	//for (int i = 0; i < 0; ++i)
	//{
	//	cout << "hello" << endl;
	//}



	return 0;
}