#include <iostream>
#include <vector>	
#include <string>
#include "MyHashTable.h"
#include <unordered_map>
#include <unordered_set>
#include <time.h>
using namespace std;

void test1()
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

}

void test_unmap()
{
	unordered_map<string, int> m1;
	string str[] = { "123", "hase", "dash", "table", "123","as","as","as" };
	for (const string& s : str)
	{
		m1[s]++;
	}

	unordered_map<string, int>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << "\n";
		++it;
	}
	cout << endl;
}

void test_unset()
{
	unordered_set<int> s1;
	int a[] = { 1,1,1,2,4,5,67,3,1,5,3,4,6 };
	for (auto e : a)
	{
		s1.insert(e);
	}
	
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include "MyUnordered_set.h"

void test_unset1()
{
	kozen::unordered_set<int> s1;
	int a[] = { 1,1,1,2,4,5,67,3,1,5,3,4,6 };
	for (auto e : a)
	{
		s1.insert(e);
	}

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	s1.erase(1);
	s1.erase(3);
	s1.erase(67);

	for (auto it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_unset2()
{
	kozen::unordered_set<string> s1;
	string str[] = { "123", "hase", "dash", "table", "123","as","as","as","你好"};
	for (string& e : str)
	{
		s1.insert(e);
	}

	kozen::unordered_set<string>::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	auto pos = s1.find("as");
	if (pos != s1.end())
		cout << *pos << endl;
	else
		cout << "absent" << endl;
	pos = s1.find("hello");
	if (pos != s1.end())
		cout << *pos << endl;
	else
		cout << "absent" << endl;

	s1.erase("123");
	s1.erase("as");
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;


	s1.erase("table");
	for (auto e2 : s1)
	{
		cout << e2 << " ";
	}
	cout << endl;	
	s1.erase("dash");
	for (auto e2 : s1)
	{
		cout << e2 << " ";
	}
	cout << endl;
	s1.erase("hase");
	for (auto e2 : s1)
	{
		cout << e2 << " ";
	}
	cout << endl;
	s1.erase("nier");
	for (auto e2 : s1)
	{
		cout << e2 << " ";
	}
	cout << endl;
	s1.erase("你好");
	for (auto e2 : s1)
	{
		cout << e2 << " ";
	}
	cout << endl;
}

#include "MyUnordered_map.h"

void test_map1()
{
	kozen::unordered_map<int, int> m1;
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,5 };
	for (auto e : a)
	{
		m1.insert(make_pair(e, e));
	}

	for (auto e : m1)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	string str[] = { "123", "hase", "dash", "table", "123","as","as","as","你好","西瓜","西瓜" ,"西瓜" ,"西瓜" };
	kozen::unordered_map<string, int> m2;
	for (const string& e : str)
	{
		m2[e]++;
	}

	for (const auto& e : m2)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

void test_map_set1()
{
	srand((unsigned)time(nullptr));
	int N = 1000000;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		v[i] = rand() + i;
	}

	kozen::unordered_set<int> s1;
	kozen::unordered_map<int, int> m1;
	for (auto e : v)
	{
		s1.insert(e);
		m1.insert(make_pair(e, e));
	}

	cout << s1.size() << endl;
	cout << m1.size() << endl;

	for (int i = 0; i < 30; ++i)
	{
		int num = rand() + i;
		auto pos1 = s1.find(num);
		auto pos2 = m1.find(num);
		cout << pos1._node << ":" << pos2._node << endl;
	}

}

void test_map_set2()
{
	kozen::unordered_map<int, int> m1;
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,5 };
	for (auto e : a)
	{
		m1.insert(make_pair(e, e));
	}

	for (auto e : m1)
	{
		cout << e.first << " ";
	}
	cout << endl;

	kozen::unordered_map<int, int> m2;
	m2.insert(make_pair(1, 1));
	m2.insert(make_pair(2, 2));
	m2.insert(make_pair(3, 3));

	for (auto e : m2)
	{
		cout << e.first << " ";
	}
	cout << endl;

	cout << m1.count(1)<< endl;
	cout << m1.count(11)<< endl;
	cout << m1.count(32)<< endl;

	m2.swap(m1);

	for (auto e : m1)
	{
		cout << e.first << " ";
	}
	cout << endl;	
	for (auto e : m2)
	{
		cout << e.first << " ";
	}
	cout << endl;
	m1.clear();

	kozen::unordered_set<int> s1;
	for (auto e : a)
	{
		s1.insert(e);
	}
	cout << s1.count(1)<< endl;
	cout << s1.count(11)<< endl;
	cout << s1.count(32)<< endl;
}

int main()
{
	//OpenAdress::test_hashtable2();
	//HashBuket::test_hashB1();
	//test_unmap();
	//test_unset();

	//test_unset1();
	//test_unset2();

	//test_map1();
	test_map_set2();

	return 0;
}