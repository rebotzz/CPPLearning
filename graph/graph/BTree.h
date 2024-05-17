#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class K, int M = 3>	// �ֲ�����
struct BTreeNode
{
	using Node = BTreeNode<K, M>;

	int _n = 0;					// ��¼����key����,  �ƺ�Ҳ����_keys,���Ǻܲ�����
	vector<K> _keys;
	vector<Node*> _childs;
	Node* _parent = nullptr;

	BTreeNode()
	{
		// ����ֱ�Ӹ���ֵ�����µ�����,�Ƚϵ�ʱ����Ҫ�õ�_n, �������Խ��
		 _keys.resize(M);	 			// M���ֲ�, M - 1��key
		_childs.resize(M + 1, nullptr);	// ����һ���ռ���ڲ���
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
				for (; i < cur->_n; ++i)
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
		int end = cur->_n - 1;
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
		cur->_n++;

		// �жϽڵ��Ƿ�����, ����->����
		while (cur->_n == M)
		{
			Node* brother = new Node;
			brother->_parent = cur->_parent;
			// ����һ����ֵ�
			int mid = cur->_n / 2;
			size_t i = mid + 1;
			int index = 0;
			for (; i < cur->_n; ++i, ++index)
			{
				brother->_n++;
				brother->_keys[index] = cur->_keys[i];
				brother->_childs[index] = cur->_childs[i];		// �ֵܱ����е�һ������
				if (brother->_childs[index] != nullptr)			// ���Ӹ��ĸ��ڵ�ָ��
				{
					brother->_childs[index]->_parent = brother;
				}
			}
			//brother->_n += cur->_key.size() - mid - 1;

			brother->_childs[index] = cur->_childs[i];			// ���һ���Һ���
			if (brother->_childs[index] != nullptr)
				brother->_childs[index]->_parent = brother;

			// ��ȡ�м�ڵ���븸�ڵ�
			K midK = cur->_keys[mid];
			cur->_n -= brother->_n + 1;	// �����ֵ�,��Ҫ��ȡһ��mid			
			for (int i = cur->_n; i < cur->_keys.size(); ++i)
			{
				cur->_keys[i] = K();
				cur->_childs[i + 1] = nullptr;	// ���ӻ���,���Һ��Ӳ�����
			}
			//cur->_keys.resize(mid);
			//cur->_childs.resize(mid + 2);
			Node* parent = cur->_parent;

			// ������Ǹ��ڵ�,newһ���µĸ��ڵ�
			if (parent == nullptr)
			{
				Node* newroot = new Node;
				newroot->_keys[0] = midK;
				newroot->_childs[0] = cur;
				newroot->_childs[1] = brother;
				newroot->_n++;
				cur->_parent = newroot;
				brother->_parent = newroot;
				_root = newroot;

				return true;
			}
			// ���׽ڵ㲻Ϊ��,����key,�����ֵܽڵ�(�Һ���)
			else
			{
				int end = parent->_n - 1;
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
				parent->_n++;
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
			size_t i = 0;
			for (; i < cur->_n; ++i)
			{
				// ��keyС,����(i)
				if (key < cur->_keys[i])
				{
					parent = cur;
					cur = cur->_childs[i];
					break;
				}
				// ��������֮��,�Һ���(i+1)
				else if ((i + 1 < cur->_n) && key > cur->_keys[i] && key < cur->_keys[i + 1])
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
			if (cur != nullptr && i == cur->_n)
			{
				parent = cur;
				cur = cur->_childs[cur->_n];
			}
		}

		return make_pair(parent, -1);
	}
private:
	Node* _root;
};
