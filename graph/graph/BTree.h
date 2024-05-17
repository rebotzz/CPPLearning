#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<class K, int M = 3>	// 分叉数量
struct BTreeNode
{
	using Node = BTreeNode<K, M>;

	//int _n = 0;					// 记录已有key个数,  似乎也能用_keys,但是不能初始resize()
	vector<K> _keys;
	vector<Node*> _childs;
	Node* _parent = nullptr;

	BTreeNode();
	{
		// _keys.resize(M, K());	// 记录已有key个数		// M个分叉, M - 1个key
		_childs.resize(M + 1, nullptr);	// 多留一个空间便于操作
		_size = 0;
	}
};

// V似乎没有用,通过key查找,??
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
		// 找到了
		if (kv.second != -1)
		{
			return false;
		}
		
		// 找不到,在叶子节点插入key,叶子没有孩子
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


		// 判断节点是否满了, 满了->分裂
		while (cur->_keys.size() == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// 分裂一半给兄弟
			int mid = cur->_keys.size() / 2;
			int index = 0;
			size_t i = mid + 1;
			for (; i < cur->_keys.size(); ++i)
			{
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// 兄弟必须有第一个左孩子
				if (brother->_childs[index] != nullptr)			// 孩子更改父节点指向
				{
					brother->_childs[index]->parent = brother;
				}
				index++;
			}
			brother->_childs[index] = cur->_childs[i];			// 最后一个右孩子
			if (brother->_childs[index] != nullptr)			
				brother->_childs[index]->parent = brother;

			// 提取中间节点插入父节点
			K midK = cur->_keys[mid];
			cur->_keys.resize(mid + 1);
			cur->_childs.resize(mid + 2);
			Node* parent = cur->_parent;

			// 本身就是根节点,new一个新的根节点
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
			// 父亲节点不为空,插入key,插入兄弟节点(右孩子)
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


			// 向上检查: 是否要连续分裂
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

				// 比key小,左孩子(i)
				if (key < cur->_keys[i])
				{
					parent = cur;
					cur = cur->_childs[i];
				}
				// 介于两者之间,右孩子(i+1)
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
