#include <iostream>
#include <vector>	
using namespace std;

int main()
{
	//int a[] = { 1,2,3,4,5 };
	vector<int> a = { 1,2,3,4,5 };
	for (auto num : a)			// 范围for是*it的临时拷贝
	{
		num = 2;
		//cout << num << " ";
		cout << &num << " ";
	}
	cout << endl;

	for (auto it = a.begin(); it != a.end(); ++it)	// 直接*it是原数据
	{
		cout << &(*it) << " ";
	}
	cout << endl;

	for (int i = 0; i < a.size(); ++i)
	{
		cout << &a[i] << " ";
	}
	cout << endl;

	for (auto& e : a)			// 范围for引用是原数据
	{
		cout << &e << " ";
	}
	cout << endl;

	vector<int> a2(4);	// 构造4个int()
	for (auto e : a2)
	{
		cout << e << " ";
	}
	cout << endl;

	for (int e : a2)	// auto可以换为具体类型		
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}