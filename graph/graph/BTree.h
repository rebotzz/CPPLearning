#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

template<class K, int M = 3>	// 分叉数量
struct BTreeNode
{
	using Node = BTreeNode<K, M>;

	int _size = 0;					// 记录已有key个数,  似乎也能用_keys,但是很不方便
	Node* _parent = nullptr;
	vector<K> _keys;
	vector<Node*> _childs;

	BTreeNode()
	{
		_keys.resize(M);	 			// M个分叉, M - 1个key		直接赋初值要用到_size, 否则可能越界
		_childs.resize(M + 1, nullptr);	// 多留一个空间便于操作
	}
	~BTreeNode()
	{
		cout << "~BTreeNode(): ";
		for (int i = 0; i < _size; ++i)
			cout << _keys[i] << " ";
		cout << endl;
	}

};

// V可以存储磁盘地址,但是这里为了方便没有写
template<class K, int M>
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
		// 必须要后序遍历,根放在最后: 左 右 根
		Destory(_root);
	}

	void Destory(Node* pnode)
	{
		if (pnode == nullptr)
			return;

		int i = 0;
		for (; i < pnode->_size; ++i)
		{
			Destory(pnode->_childs[i]);
		}
		Destory(pnode->_childs[i]);
		if (pnode)
			delete pnode;
	}
	void _PrintInOrder(Node* pnode)
	{
		if (pnode == nullptr)
			return;

		int i = 0;
		for (; i < pnode->_size; ++i)
		{
			_PrintInOrder(pnode->_childs[i]);
			cout << pnode->_keys[i] << " ";
		}
		_PrintInOrder(pnode->_childs[i]);
	}
	void PrintInOrder()
	{
		_PrintInOrder(_root);
		cout << endl;
	}

	void PrintLevel()
	{
		int level = 0;
		queue<Node*> que;
		que.push(_root);
		while (!que.empty())
		{
			int levelsize = que.size();
			cout << "level:" << level++ << endl;
			while (levelsize--)
			{
				Node* cur = que.front();
				que.pop();
				int i = 0;
				for (; i < cur->_size; ++i)
				{
					cout << cur->_keys[i] << " ";
					if (cur->_childs[i])
						que.push(cur->_childs[i]);
				}
				if (cur->_childs[i])	// 最后一个孩子
					que.push(cur->_childs[i]);
			}
			cout << endl;
		}

	}

#if 0
	// 1.0
	bool Insert(const K& key)
	{
		pair<Node*, int> kv = find(key);
		// 找到了
		if (kv.second != -1)
		{
			return false;
		}

		// 找不到,在叶子节点插入key,叶子没有孩子
		Node* cur = kv.first;
		int end = cur->_size - 1;
		while (end >= 0)
		{
			// 找到小于等于key的前一个
			if (cur->_keys[end] > key)
			{
				cur->_keys[end + 1] = cur->_keys[end];
				end--;
			}
			else
			{
				break;
			}
		}
		cur->_keys[end + 1] = key;
		cur->_size++;

		// 判断节点是否满了, 满了->分裂
		while (cur->_size == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// 分裂一半给兄弟
			int mid = cur->_size / 2;
			size_t i = mid + 1;
			int index = 0;
			for (; i < cur->_size; ++i, ++index)
			{
				brother->_size++;
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// 兄弟必须有第一个左孩子
				if (brother->_childs[index] != nullptr)			// 孩子更改父节点指向
				{
					brother->_childs[index]->_parent = brother;
				}
			}
			//brother->_size += cur->_key.size() - mid - 1;

			brother->_childs[index] = cur->_childs[i];			// 最后一个右孩子
			if (brother->_childs[index] != nullptr)
				brother->_childs[index]->_parent = brother;

			// 提取中间节点插入父节点
			K midK = cur->_keys[mid];
			cur->_size -= brother->_size + 1;	// 除了兄弟,还要提取一个mid			
			for (int i = cur->_size; i < cur->_keys.size(); ++i)
			{
				cur->_keys[i] = K();
				cur->_childs[i + 1] = nullptr;	// 左孩子还在,是右孩子不在了
			}
			Node* parent = cur->_parent;

			// 本身就是根节点,new一个新的根节点
			if (parent == nullptr)
			{
				Node* newroot = new Node;
				newroot->_keys[0] = midK;
				newroot->_childs[0] = cur;
				newroot->_childs[1] = brother;
				newroot->_size++;
				cur->_parent = newroot;
				brother->_parent = newroot;
				_root = newroot;

				return true;
			}
			// 父亲节点不为空,插入key,插入兄弟节点(右孩子)
			else
			{
				int end = parent->_size - 1;
				while (end >= 0)
				{
					if (parent->_keys[end] > midK)
					{
						parent->_keys[end + 1] = parent->_keys[end];
						parent->_childs[end + 2] = parent->_childs[end + 1];
						end--;
					}
					else
					{
						break;
					}
				}
				parent->_keys[end + 1] = midK;
				parent->_childs[end + 2] = brother;
				parent->_size++;
				brother->_parent = parent;
			}

			// 向上检查: 是否要连续分裂
			cur = cur->_parent;
		}

		return true;
	}

	// 1.0
	pair<Node*, int> find(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur != nullptr)
		{
			size_t i = 0;
			for (; i < cur->_size; ++i)
			{
				// 比key小,左孩子(i)
				if (key < cur->_keys[i])
				{
					parent = cur;
					cur = cur->_childs[i];
					break;
				}
				// 介于两者之间,右孩子(i+1)
				else if ((i + 1 < cur->_size) && key > cur->_keys[i] && key < cur->_keys[i + 1])
				{
					parent = cur;
					cur = cur->_childs[i + 1];
					break;
				}
				else if (cur->_keys[i] == key)
				{
					return make_pair(cur, i);
				}
			}

			// 到这里说明key比数组里的都大, 往右走
			if (cur != nullptr && i == cur->_size)
			{
				parent = cur;
				cur = cur->_childs[cur->_size];
			}
		}

		return make_pair(parent, -1);
	}
#endif
	// 2.0
	bool Insert(const K& key)
	{
		pair<Node*, int> kv = find(key);
		// 找到了
		if (kv.second != -1)
		{
			return false;
		}

		// 找不到,在叶子节点插入key,叶子没有孩子
		Node* cur = kv.first;
		InsertKey(cur, key, nullptr);

		// 判断节点是否满了, 满了->分裂
		while (cur->_size == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// 分裂一半给兄弟
			int mid = cur->_size / 2;
			size_t i = mid + 1;
			int index = 0;
			for (; i < cur->_size; ++i, ++index)
			{
				brother->_size++;
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// 兄弟必须有第一个左孩子
				if (brother->_childs[index] != nullptr)			// 孩子更改父节点指向
				{
					brother->_childs[index]->_parent = brother;
				}
			}
			//brother->_size += cur->_key.size() - mid - 1;

			brother->_childs[index] = cur->_childs[i];			// 最后一个右孩子
			if (brother->_childs[index] != nullptr)
				brother->_childs[index]->_parent = brother;

			// 提取中间节点插入父节点
			K midK = cur->_keys[mid];
			Node* parent = cur->_parent;
			cur->_size -= brother->_size + 1;	// 除了兄弟,还要提取一个mid			
			// 初始化剔除的值
			for (int i = cur->_size; i < cur->_keys.size(); ++i)
			{
				cur->_keys[i] = K();
				cur->_childs[i + 1] = nullptr;	// 左孩子还在,是右孩子不在了
			}

			// 本身就是根节点,new一个新的根节点
			if (parent == nullptr)
			{
				Node* newroot = new Node;
				newroot->_keys[0] = midK;
				newroot->_childs[0] = cur;
				newroot->_childs[1] = brother;
				newroot->_size++;
				cur->_parent = newroot;
				brother->_parent = newroot;
				_root = newroot;

				return true;
			}
			// 父亲节点不为空,插入key,插入兄弟节点(右孩子)
			else
			{
				InsertKey(parent, midK, brother);
			}

			// 向上检查: 是否要连续分裂
			cur = cur->_parent;
		}

		return true;
	}

	void InsertKey(Node* parent, const K& key, Node* brother)
	{
		int end = parent->_size - 1;
		while (end >= 0)
		{
			if (parent->_keys[end] > key)
			{
				parent->_keys[end + 1] = parent->_keys[end];
				parent->_childs[end + 2] = parent->_childs[end + 1];
				end--;
			}
			else
			{
				break;
			}
		}
		parent->_keys[end + 1] = key;
		parent->_childs[end + 2] = brother;
		parent->_size++;
		if(brother)
			brother->_parent = parent;
	}

	// 2.0
	pair<Node*, int> find(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur != nullptr)
		{
			size_t i = 0;
			for (; i < cur->_size; ++i)
			{
				// 比key小,左孩子(i)
				if (key < cur->_keys[i])
					break;
				else if (key == cur->_keys[i])
					return make_pair(cur, i);
			}
			// i < _size: 正常左走; i == _size:到这里说明key比数组里的都大, 往右走
			parent = cur;
			cur = cur->_childs[i];
		}

		return make_pair(parent, -1);
	}
private:
	Node* _root;
};


//// B+树
//template<class K, int M = 3>
//struct BpNode		
//{
//	using Node = BpNode<K, M>;
//
//	vector<K> _keys;
//	vector<Node*> _childs;
//	BpNode()
//		:_keys.resize(M),		// m个key,m个分叉
//		,_childs.resize(M)
//	{}
//};
//
//template<class K, int M = 3>
//class BplusTree
//{
//
//};
