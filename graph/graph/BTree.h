#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

template<class K, int M = 3>	// �ֲ�����
struct BTreeNode
{
	using Node = BTreeNode<K, M>;

	int _size = 0;					// ��¼����key����,  �ƺ�Ҳ����_keys,���Ǻܲ�����
	Node* _parent = nullptr;
	vector<K> _keys;
	vector<Node*> _childs;

	BTreeNode()
	{
		_keys.resize(M);	 			// M���ֲ�, M - 1��key		ֱ�Ӹ���ֵҪ�õ�_size, �������Խ��
		_childs.resize(M + 1, nullptr);	// ����һ���ռ���ڲ���
	}
	~BTreeNode()
	{
		cout << "~BTreeNode(): ";
		for (int i = 0; i < _size; ++i)
			cout << _keys[i] << " ";
		cout << endl;
	}

};

// V���Դ洢���̵�ַ,��������Ϊ�˷���û��д
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
		// ����Ҫ�������,���������: �� �� ��
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
				if (cur->_childs[i])	// ���һ������
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
		// �ҵ���
		if (kv.second != -1)
		{
			return false;
		}

		// �Ҳ���,��Ҷ�ӽڵ����key,Ҷ��û�к���
		Node* cur = kv.first;
		int end = cur->_size - 1;
		while (end >= 0)
		{
			// �ҵ�С�ڵ���key��ǰһ��
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

		// �жϽڵ��Ƿ�����, ����->����
		while (cur->_size == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// ����һ����ֵ�
			int mid = cur->_size / 2;
			size_t i = mid + 1;
			int index = 0;
			for (; i < cur->_size; ++i, ++index)
			{
				brother->_size++;
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// �ֵܱ����е�һ������
				if (brother->_childs[index] != nullptr)			// ���Ӹ��ĸ��ڵ�ָ��
				{
					brother->_childs[index]->_parent = brother;
				}
			}
			//brother->_size += cur->_key.size() - mid - 1;

			brother->_childs[index] = cur->_childs[i];			// ���һ���Һ���
			if (brother->_childs[index] != nullptr)
				brother->_childs[index]->_parent = brother;

			// ��ȡ�м�ڵ���븸�ڵ�
			K midK = cur->_keys[mid];
			cur->_size -= brother->_size + 1;	// �����ֵ�,��Ҫ��ȡһ��mid			
			for (int i = cur->_size; i < cur->_keys.size(); ++i)
			{
				cur->_keys[i] = K();
				cur->_childs[i + 1] = nullptr;	// ���ӻ���,���Һ��Ӳ�����
			}
			Node* parent = cur->_parent;

			// ������Ǹ��ڵ�,newһ���µĸ��ڵ�
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
			// ���׽ڵ㲻Ϊ��,����key,�����ֵܽڵ�(�Һ���)
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

			// ���ϼ��: �Ƿ�Ҫ��������
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
				// ��keyС,����(i)
				if (key < cur->_keys[i])
				{
					parent = cur;
					cur = cur->_childs[i];
					break;
				}
				// ��������֮��,�Һ���(i+1)
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

			// ������˵��key��������Ķ���, ������
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
		// �ҵ���
		if (kv.second != -1)
		{
			return false;
		}

		// �Ҳ���,��Ҷ�ӽڵ����key,Ҷ��û�к���
		Node* cur = kv.first;
		InsertKey(cur, key, nullptr);

		// �жϽڵ��Ƿ�����, ����->����
		while (cur->_size == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// ����һ����ֵ�
			int mid = cur->_size / 2;
			size_t i = mid + 1;
			int index = 0;
			for (; i < cur->_size; ++i, ++index)
			{
				brother->_size++;
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// �ֵܱ����е�һ������
				if (brother->_childs[index] != nullptr)			// ���Ӹ��ĸ��ڵ�ָ��
				{
					brother->_childs[index]->_parent = brother;
				}
			}
			//brother->_size += cur->_key.size() - mid - 1;

			brother->_childs[index] = cur->_childs[i];			// ���һ���Һ���
			if (brother->_childs[index] != nullptr)
				brother->_childs[index]->_parent = brother;

			// ��ȡ�м�ڵ���븸�ڵ�
			K midK = cur->_keys[mid];
			Node* parent = cur->_parent;
			cur->_size -= brother->_size + 1;	// �����ֵ�,��Ҫ��ȡһ��mid			
			// ��ʼ���޳���ֵ
			for (int i = cur->_size; i < cur->_keys.size(); ++i)
			{
				cur->_keys[i] = K();
				cur->_childs[i + 1] = nullptr;	// ���ӻ���,���Һ��Ӳ�����
			}

			// ������Ǹ��ڵ�,newһ���µĸ��ڵ�
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
			// ���׽ڵ㲻Ϊ��,����key,�����ֵܽڵ�(�Һ���)
			else
			{
				InsertKey(parent, midK, brother);
			}

			// ���ϼ��: �Ƿ�Ҫ��������
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
				// ��keyС,����(i)
				if (key < cur->_keys[i])
					break;
				else if (key == cur->_keys[i])
					return make_pair(cur, i);
			}
			// i < _size: ��������; i == _size:������˵��key��������Ķ���, ������
			parent = cur;
			cur = cur->_childs[i];
		}

		return make_pair(parent, -1);
	}
private:
	Node* _root;
};


//// B+��
//template<class K, int M = 3>
//struct BpNode		
//{
//	using Node = BpNode<K, M>;
//
//	vector<K> _keys;
//	vector<Node*> _childs;
//	BpNode()
//		:_keys.resize(M),		// m��key,m���ֲ�
//		,_childs.resize(M)
//	{}
//};
//
//template<class K, int M = 3>
//class BplusTree
//{
//
//};
