#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<class K, int M = 3>	// �ֲ�����
struct BTreeNode
{
	using Node = BTreeNode<K, M>;

	//int _n = 0;					// ��¼����key����,  �ƺ�Ҳ����_keys,���ǲ��ܳ�ʼresize()
	vector<K> _keys;
	vector<Node*> _childs;
	Node* _parent = nullptr;

	BTreeNode();
	{
		// _keys.resize(M, K());	// ��¼����key����		// M���ֲ�, M - 1��key
		_childs.resize(M + 1, nullptr);	// ����һ���ռ���ڲ���
		_size = 0;
	}
};

// V�ƺ�û����,ͨ��key����,??
template<class K, class V, int M>
class BTree
{
	using Node = BTreeNode<K, M>;
public:
	BTree()
	{
		_root = new Node;
	}
	~BTree()
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			// todo...
		}
	}

	bool Insert(const K& key, const V& value)
	{
		pair<Node*, int> kv = find(key);
		// �ҵ���
		if (kv.second != -1)
		{
			return false;
		}
		
		// �Ҳ���,��Ҷ�ӽڵ����key,Ҷ��û�к���
		Node* cur = kv.first;
		int end = cur->_keys.size() - 1;
		while (end >= 0)
		{
			if (cur->_keys[end] > key)
			{
				cur->_keys[end + 1] = cur->_keys[end];
				end--;
			}
			else
			{
				cur->_keys[end + 1] = key;
				break;
			}
		}


		// �жϽڵ��Ƿ�����, ����->����
		while (cur->_keys.size() == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// ����һ����ֵ�
			int mid = cur->_keys.size() / 2;
			int index = 0;
			size_t i = mid + 1;
			for (; i < cur->_keys.size(); ++i)
			{
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// �ֵܱ����е�һ������
				if (brother->_childs[index] != nullptr)			// ���Ӹ��ĸ��ڵ�ָ��
				{
					brother->_childs[index]->parent = brother;
				}
				index++;
			}
			brother->_childs[index] = cur->_childs[i];			// ���һ���Һ���
			if (brother->_childs[index] != nullptr)			
				brother->_childs[index]->parent = brother;

			// ��ȡ�м�ڵ���븸�ڵ�
			K midK = cur->_keys[mid];
			cur->_keys.resize(mid + 1);
			cur->_childs.resize(mid + 2);
			Node* parent = cur->_parent;

			// ������Ǹ��ڵ�,newһ���µĸ��ڵ�
			if (parent == nullptr)
			{
				Node* newroot = new Node;
				newroot->_keys[0] = midK;
				newroot->_childs[0] = cur;
				newroot->_childs[1] = brother;
				cur->_parent = newroot;
				brother->_parent = newroot;
				_root = newroot;
			}
			// ���׽ڵ㲻Ϊ��,����key,�����ֵܽڵ�(�Һ���)
			else
			{
				int end = parent->_keys.size() - 1;
				while (end >= 0)
				{
					if (parent->_keys[end] > midK)
					{
						parent->_keys[end + 1] = parent->_keys[end];
						parent->_childs[end + 2] = parent->_childs[end + 1];

					}
					else
					{
						parent->_keys[end + 1] = midK;
						parent->_childs[end + 2] = brother;
					}
				}
				brother->_parent = parent;
			}


			// ���ϼ��: �Ƿ�Ҫ��������
			cur = cur->_parent;
		}

		return true;
	}

	pair<Node*, int> find(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur != nullptr)
		{
			for (size_t i = 0; i < cur->_keys.size(); ++i)
			{

				// ��keyС,����(i)
				if (key < cur->_keys[i])
				{
					parent = cur;
					cur = cur->_childs[i];
				}
				// ��������֮��,�Һ���(i+1)
				else if (key > cur->_keys[i] && key < cur->_keys[i + 1])
				{
					parent = cur;
					cur = cur->_childs[i + 1];
				}
				else
				{
					return make_pair(cur, i);
				}
			}
		}

		return (parent, -1);
	}
private:
	Node* _root;
};
