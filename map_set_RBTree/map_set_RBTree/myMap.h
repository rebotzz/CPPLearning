#pragma once
#include "RBTree.h"

namespace kozen
{
	template<class K, class V>
	class map
	{
		// �º���
		struct GetKofV
		{
			const K& operator()(const pair<K, V>& data) const
			{	
				return data.first;
			}
		};
	public:
		// ������
		// ��װ������ĵ�����
		typedef typename RBTree<K, pair<K, V>, GetKofV>::iterator iterator;
		typedef typename RBTree<K, pair<K, V>, GetKofV>::reverse_iterator reverse_iterator;

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
			// ����key
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}

		// ����
		pair<iterator, bool> Insert(const pair<K, V>& key)
		{
			return _tree.Insert(key);
		}

		// ����
		bool Find(const K& key) const
		{
			return _tree.Find(key) != nullptr;
		}

		// ɾ��
		bool Erase(const K& key)
		{
			//...
		}

	private:
		RBTree<K, pair<K, V>, GetKofV> _tree;
	};
}