#pragma once
#include "RBTree.h"

namespace kozen
{
	template<class K>
	class set
	{
		// 仿函数
		struct GetKofV
		{	
			const K& operator()(const K& data) const
			{	// set中,data就是key
				return data;
			}
		};
	public:
		// 迭代器
		// 封装红黑树的迭代器
		// typename用于区分类型和变量
		typedef typename RBTree<K, K, GetKofV>::const_iterator iterator;	//封装const迭代器,防止修改Key
		typedef typename RBTree<K, K, GetKofV>::const_reverse_iterator reverse_iterator;

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

		// 插入
		pair<iterator, bool> Insert(const K& key)
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
			//....
		}

	private:
		RBTree<K, K, GetKofV> _tree;
	};
}