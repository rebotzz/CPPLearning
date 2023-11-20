#include <iostream>
#include <string>
#include "mySet.h"
#include "myMap.h"
using namespace std;

class A
{
public:
	int a;
	static int b;
};
int A:: b = 1;

void test1()
{
	A aa1;
	cout << aa1.b++ << endl;
	A aa2;
	cout << aa2.b++ << endl;
	cout << A::b++ << endl;
	cout << A::b << endl;
}

void test2()
{
	pair<string, int> kv1("sjflsj",12);
	kv1.first = "skjf";
	kv1.second = 23;
	//cout << kv1 << endl;
}

void test_set()
{
	kozen::set<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);

	cout << s.Find(3) << endl;
	cout << s.Find(5) << endl;

	kozen::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		//*it = 2;
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	kozen::set<int> s2;
	for (auto e : arr)
	{
		s2.Insert(e);
	}

	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	kozen::set<int>::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	cout << s2.Find(11) << endl;
	cout << s2.Find(27) << endl;

}

void test_map()
{
	kozen::map<int, int> m1;
	m1.Insert(make_pair(1, 1));
	m1.Insert(make_pair(2, 1));
	m1.Insert(make_pair(3, 1));
	m1.Insert(make_pair(4, 1));

	kozen::map<int, int>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << (*it).first << ":" << it->second << " ";
		++it;
	}
	cout << endl;

	for (auto e : m1)
	{
		cout << e.first << ":" << e.second << " ";
	}
	cout << endl;

	kozen::map<string, int> m2;
	string str[] = { "English", "Math", "Physic", "Tensor","English" };
	for (auto e : str)
	{
		cout << e << endl;
		cout << (m2[e]++) << endl;;
	}

	for (auto e : m2)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	cout << m2.Find("English") << endl;
	cout << m2.Find("why") << endl;

	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	kozen::map<int, int> m3;
	for (auto num : arr)
	{
		m3.Insert(make_pair(num, num));
	}
	cout << endl;

	for (auto e : m3)
	{
		cout << e.first << ":" << e.second << " ";
	}
	cout << endl;

	kozen::map<int, int>::reverse_iterator rit = m3.rbegin();
	while (rit != m3.rend())
	{
		cout << rit->first << ":" << rit->second << " ";
		rit++;
	}
	cout << endl;

}


int main()
{
	//test_set();
	test_map();

	return 0;
}