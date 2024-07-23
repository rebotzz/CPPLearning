#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// ���鼯 

template<class T>
class UnionFindSet
{
public:
	UnionFindSet(const T* arr, size_t n)
	{
		_v.resize(n, -1);
		for (size_t i = 0; i < n; ++i)
		{
			_indexMap[arr[i]] = i;
		}
	}

	void unionSet(const T x, const T y)
	{
		auto it1 = _indexMap.find(x);
		auto it2 = _indexMap.find(y);
		if (it1 == _indexMap.end() || it2 == _indexMap.end())
		{
			throw string("union members not exist");
		}

		int root1 = findRoot(it1->second);
		int root2 = findRoot(it2->second);
		if (root1 == root2)
			return;

		// �Ż���С�ļ��Ϻϲ�����ļ���
		if (abs(_v[root1]) < abs(_v[root2]))
			swap(root1, root2);

		_v[root1] += _v[root2];
		_v[root2] = root1;
	}

	bool inSet(const T& x, const T& y)
	{
		auto it1 = _indexMap.find(x);
		auto it2 = _indexMap.find(y);
		if (it1 == _indexMap.end() || it2 == _indexMap.end())
			return false;

		int root1 = findRoot(it1->second);
		int root2 = findRoot(it2->second);
		return root1 == root2;
	}

	size_t findRoot(size_t index)
	{
		size_t root = index;
		while (_v[root] >= 0)
		{
			root = _v[root];
		}

		// ·���Ż�
		size_t cur = index;
		while (_v[cur] >= 0)
		{
			size_t parent = _v[cur];
			_v[cur] = root;
			cur = parent;
		}

		return root;
	}

	size_t rootCount()
	{
		size_t size = 0;
		for (auto e : _v)
		{
			if (e < 0)
				size++;
		}
		return size;
	}

	void print()
	{
		for (auto e : _indexMap)
		{
			cout << " " << e.first << " ";
		}
		cout << endl;

		for (auto e : _indexMap)
		{
			printf("%2d ", e.second);
		}
		cout << endl;

		for (auto e : _indexMap)
		{
			printf("%2d ", _v[e.second]);
		}
		cout << endl;
	}

private:
	vector<int> _v;		// ���������ʾɭ�֣����Ǹ���(����ֵ�����Ա����)����Աָ���Ӧ�ĸ�
	map<T, int> _indexMap;	// �洢��ֵT�������±��ӳ���ϵ
};




