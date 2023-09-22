#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//vector<int> v1(5);
	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	vector<string> numLetter = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	for (auto e : numLetter)
	{
		cout << e << endl;
	}

	return 0;
}