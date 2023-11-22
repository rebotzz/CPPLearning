#include <iostream>
#include <vector>	
using namespace std;

int main()
{
	//int a[] = { 1,2,3,4,5 };
	vector<int> a = { 1,2,3,4,5 };
	for (auto num : a)			// ��Χfor��*it����ʱ����
	{
		num = 2;
		//cout << num << " ";
		cout << &num << " ";
	}
	cout << endl;

	for (auto it = a.begin(); it != a.end(); ++it)	// ֱ��*it��ԭ����
	{
		cout << &(*it) << " ";
	}
	cout << endl;

	for (int i = 0; i < a.size(); ++i)
	{
		cout << &a[i] << " ";
	}
	cout << endl;

	for (auto& e : a)			// ��Χfor������ԭ����
	{
		cout << &e << " ";
	}
	cout << endl;

	vector<int> a2(4);	// ����4��int()
	for (auto e : a2)
	{
		cout << e << " ";
	}
	cout << endl;

	for (int e : a2)	// auto���Ի�Ϊ��������		
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}