#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// AVL��ѧϰ: �߶�ƽ������������
// ���������߶Ȳ����1

// �ڵ�
template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	int _bf;		// blance factor ƽ������:�������߶� - �������߶�
	T _key;

	AVLTreeNode(const T key)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _key(key)
	{}

};

// AVL��
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree() = default;

	bool Insert(const T key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
		}
		else
		{
			// ����_root->parent = nullptr,��Ķ��и��ڵ�
			Node* parent = nullptr;
			Node* cur = _root;
			// �ҵ�����λ��
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key > key)
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
					cout << "�������ṹ" << endl;

					break;
				}
				else
				{
					// ���ṹ����
					assert(false);
				}
			}
			return true;
		}
	}

	bool Find(const T key)
	{

	}

	bool Erase(const T key)
	{

	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:
	// ����
	void RotateL(Node* parent)
	{
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



	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;

		_InOrder(cur->_left);
		cout << cur->_key << "-" << cur->_bf << " ";
		_InOrder(cur->_right);
	}

private:
	Node* _root = nullptr;
};