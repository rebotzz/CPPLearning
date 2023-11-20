#pragma once
#include "RBTree.h"

namespace kozen
{
	template<class K>
	class set
	{
		// �º���
		struct GetKofV
		{	
			const K& operator()(const K& data) const
			{	// set��,data����key
				return data;
			}
		};
	public:
		// ������
		// ��װ������ĵ�����
		// typename�����������ͺͱ���
		typedef typename RBTree<K, K, GetKofV>::const_iterator iterator;	//��װconst������,��ֹ�޸�Key
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

		// ����
		pair<iterator, bool> Insert(const K& key)
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
			//....
		}

	private:
		RBTree<K, K, GetKofV> _tree;
	};
}