#pragma once
#include "RBTree.h"

namespace kozen
{
	template<class K, class V>
	class map
	{
		// 仿函数
		struct GetKofV
		{
			const K& operator()(const pair<const K, V>& data) const
			{	
				return data.first;
			}
		};
	public:
		// 迭代器
		// 封装红黑树的迭代器
		// const K不能修改,但是普通迭代器V可以修改
		typedef typename RBTree<K, pair<const K, V>, GetKofV>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, GetKofV>::reverse_iterator reverse_iterator;

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		reverse_iterator rbegin()
		{
			return _tree.rbegin();
		}

		reverse_iterator rend()
		{
			return _tree.rend();
		}

		V& operator[](const K& key)
		{
			// 插入key
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}

		// 插入
		pair<iterator, bool> Insert(const pair<K, V>& key)
		{
			return _tree.Insert(key);
		}

		// 查找
		bool Find(const K& key) const
		{
			return _tree.Find(key) != nullptr;
		}

		// 删除
		bool Erase(const K& key)
		{
			//...
		}

	private:
		RBTree<K, pair<const K, V>, GetKofV> _tree;
	};
}