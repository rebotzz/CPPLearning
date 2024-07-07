#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <bitset>
#include "mybitset.h"
using namespace std;

void test_bitset1()
{
	int a[] = { 1,2,3,4,1,3,2,4,0,7 };
	bitset<sizeof(a) / sizeof(a[0])> bs;
	cout << bs.size() << endl;
	for (auto e : a)
	{
		//cout << e << endl;
		bs.set(e % bs.size());
	}
	cout << bs << endl;
}

void test_bitset2()
{
	//int a[] = { 1,2,3,4,1,3,2,4,0,7 };
	//kozen::bitset<sizeof(a) / sizeof(a[0])> bs;
	//cout << bs.size() << endl;
	//for (auto e : a)
	//{
	//	//cout << e << endl;
	//	bs.set(e % bs.size());
	//}

	//cout << bs << endl;

	kozen::bitset<16> bs2;
	bs2.set(1);
	bs2.set(4);
	bs2.set(8);
	bs2.set(15);

}

void test_bitset3()
{
	vector<string> v = { "maxwell", "newton","laplace","lambda","linux" };
	const static size_t n = v.size();
	kozen::bitset<7> bs1;

	// lambda,自己确定hash映射
	auto hash = [](const string& s)->int {
		int i = 0;
		for (char ch : s)
		{
			i += ch * 31;
		}
		return i;
		};

	for (auto e : v)
	{
		cout << hash(e) << endl;
		cout << hash(e) % bs1.size() << endl;
		bs1.set(hash(e) % bs1.size());

	}

	cout << bs1 << endl;

}

void test_bloomFilter1()
{
	kozen::BloomFilter<4> bf;

	vector<string> v = { "tecent", "baidu", "ali","mihoyo" };
	for (auto& e : v)
	{
		bf.insert(e);
		//cout << bf._bs << endl;
	}

	v.push_back("opencv");

	for (auto& e : v)
	{
		cout << bf.test(e) << " ";
	}
	cout << endl;

	cout << endl;
}

//void test_CountBloomFilter1()
//{
//	kozen::CountBloomFilter<3> cbf;
//	vector<string> v = { "tecent", "baidu", "ali","mihoyo" };
//
//	for (auto e : v)
//	{
//		cbf.insert(e);
//		cout << cbf._bs1;
//		cout << cbf._bs2;
//		cout << cbf._bs3 << endl;
//	}
//
//	v.push_back("opencv");
//
//	for (auto& e : v)
//	{
//		cout << cbf.test(e) << " ";
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cbf.erase(e);
//		cout << cbf._bs1;
//		cout << cbf._bs2;
//		cout << cbf._bs3 << endl;
//	}
//
//}
//
//void test_CountBloomFilter2()
//{
//	kozen::CountBloomFilter<2> bf;
//	int N = 7;
//	for (int i = 0; i < N; ++i)
//	{
//		bf.insert("a");
//		cout << bf._bs1;
//		cout << bf._bs2;
//		cout << bf._bs3 << endl;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		bf.erase("a");
//		cout << bf._bs1;
//		cout << bf._bs2;
//		cout << bf._bs3 << endl;
//	}
//
//	cout << "---------------" << endl << endl;
//
//	kozen::CountBloomFilter<1> bf2;
//	for (int i = 0; i < N; ++i)
//	{
//		bf2.addone(3);
//		cout << bf2.count(3) << endl;
//		cout << bf2._bs1;
//		cout << bf2._bs2;
//		cout << bf2._bs3 << endl;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		bf2.subone(3);
//		cout << bf2.count(3) << endl;
//		cout << bf2._bs1;
//		cout << bf2._bs2;
//		cout << bf2._bs3 << endl;
//	}
//
//}

//int main()
//{
//	//test_bitset3();
//	//test_bloomFilter1();
//	//test_CountBloomFilter2();
//
//	return 0;
//}
