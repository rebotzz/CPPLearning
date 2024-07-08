#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// AVL��ѧϰ: �߶�ƽ������������
// 
// ���������߶Ȳ����1

// �ڵ�
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;		// blance factor ƽ������:�������߶� - �������߶�
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V> kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}

	AVLTreeNode(const AVLTreeNode<K, V>& node)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(node._bf)
		, _kv(node._kv)
	{}

};

// AVL��
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree() = default;

	AVLTree(const AVLTree<K, V>& tree)
	{
		_root = copyTree(tree._root, nullptr);
	}

	~AVLTree()
	{
		cout << "~AVLTree(): " << _root << endl;
		destory(_root);
		cout << endl;
	}

	bool Insert(const pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
		}
		else
		{
			// ����_root->parent = nullptr,��Ķ��и��ڵ�
			Node* parent = nullptr;
			Node* cur = _root;
			// �ҵ�����λ��
			while (cur)
			{
				if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv);
			if (parent->_kv.first > kv.first)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			cur->_parent = parent;

			// ����ƽ������
			while (parent)
			{
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				// ���ڵ�߶Ȳ���,���ø���
				if (parent->_bf == 0)
				{
					break;
				}
				// �߶ȱ�Ϊ1 �� -1,���ϸ���
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}
				// �߶�Ϊ2 �� -2,�������ṹ,ʹ��ƽ��
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					// �������ṹ
					// 1.ʹ��������ƽ��. 2.�������ĸ߶�
					//cout << "�������ṹ" << endl;
					if (parent->_bf == 2 && cur->_bf == 1)	// ����
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1) // �ҵ���
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1) // RL˫��
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1) // LR˫��
					{
						RotateLR(parent);
					}

					break;
				}
				else
				{
					// ���ṹ����
					assert(false);
				}
			}
		}
		return true;
	}

	bool Find(const K key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K key)
	{
		//����...
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	// ����Ƿ�ƽ��
	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int deepL = TreeDeep(root->_left);
		int deepR = TreeDeep(root->_right);
		if (root->_bf >= 2)
		{
			cout << root->_kv.first << "ƽ�����ӳ���:" << root->_bf << endl;
			return false;
		}

		// 1.0
		//if (abs(deepL - deepR) >= 2)
		//	return false;
		//_IsBalance(root->_left);
		//_IsBalance(root->_right);
		//return true;

		// 2.0
		// ���������߶Ȳ�ܳ���2
		return (abs(deepL - deepR) < 2) && _IsBalance(root->_left) && _IsBalance(root->_right);
	}

	// ���ĸ߶�
	int TreeDeep(Node* root)
	{
		if (root == nullptr)
			return 0;

		int deepL = TreeDeep(root->_left);
		int deepR = TreeDeep(root->_right);

		return deepL > deepR ? deepL + 1 : deepR + 1;  // int deep = 1 + max(deepL, deepR);
	}

private:
	// ����
	void RotateL(Node* parent)
	{
		//cout << "����: " << parent->_kv.first << endl;
		Node* ppnode = parent->_parent;
		Node* childR = parent->_right;
		Node* childRL = childR->_left;
		// 3��ָ��:ppnode--parent--childR--childRL
		parent->_right = childRL;
		if(childRL)
			childRL->_parent = parent;

		childR->_left = parent;
		parent->_parent = childR;

		// parent��root
		if (ppnode == nullptr) // ����if(parent == _root)
		{
			_root = childR;
			_root->_parent = nullptr;
		}
		else  
		{
			childR->_parent = ppnode;

			if (ppnode->_left == parent)
			{
				ppnode->_left = childR;
			}
			else
			{
				ppnode->_right = childR;
			}
		}
		// ��ƽ������
		parent->_bf = childR->_bf = 0;
	}
	// �ҵ���
	void RotateR(Node* parent)
	{
		//cout << "�ҵ���: " << parent->_kv.first << endl;
		Node* ppnode = parent->_parent;
		Node* childL = parent->_left;
		Node* childLR = childL->_right;
		// 3��ָ��:ppnode--parent--childL--childLR

		parent->_left = childLR;
		if (childLR)
			childLR->_parent = parent;

		childL->_right = parent;
		parent->_parent = childL;

		// parent��root
		if (ppnode == nullptr)
		{
			_root = childL;
			_root->_parent = nullptr;
		}
		else
		{
			childL->_parent = ppnode;

			if (ppnode->_left == parent)
			{
				ppnode->_left = childL;
			}
			else
			{
				ppnode->_right = childL;
			}
		}
		// ��ƽ������
		parent->_bf = childL->_bf = 0;
	}

	// RL˫��
	void RotateRL(Node* parent)
	{
		//cout << "RL˫��: " << parent->_kv.first << endl;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;	
		int bf = subRL->_bf;
		// subR����,parent����
		RotateR(subR);
		RotateL(parent);
		// �޸�ƽ������
		if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	// LR˫��
	void RotateLR(Node* parent)
	{
		//cout << "LR˫��: " << parent->_kv.first << endl;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		// subL����,parent�ҵ���
		RotateL(subL);
		RotateR(parent);
		//�޸�ƽ������
		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void destory(Node* root)
	{
		if (nullptr == root)
			return;

		destory(root->_left);
		destory(root->_right);
		//cout << root->_parent << " " << root->_kv.first << endl;
		delete root;
	}

	Node* copyTree(Node* root, Node* parent)
	{
		if (nullptr == root)
			return nullptr;

		Node* cur = new Node(*root);
		cur->_left = copyTree(root->_left, cur);
		cur->_right = copyTree(root->_right, cur);
		cur->_parent = parent;
		return cur;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;

		_InOrder(cur->_left);
		cout << cur->_kv.first << " ";
		_InOrder(cur->_right);
	}

private:
	Node* _root = nullptr;
};