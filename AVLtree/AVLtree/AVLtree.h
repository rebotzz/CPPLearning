#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// AVL树学习: 高度平衡搜索二叉树
// 左右子树高度差不超过1

// 节点
template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	int _bf;		// blance factor 平衡因子:右子树高度 - 左子树高度
	T _key;

	AVLTreeNode(const T key)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _key(key)
	{}

};

// AVL树
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
			// 除了_root->parent = nullptr,别的都有父节点
			Node* parent = nullptr;
			Node* cur = _root;
			// 找到插入位置
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

			// 更新平衡因子
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

				// 父节点高度不变,不用更新
				if (parent->_bf == 0)
				{
					break;
				}
				// 高度变为1 或 -1,向上更新
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}
				// 高度为2 或 -2,调整树结构,使其平衡
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					cout << "调整树结构" << endl;

					break;
				}
				else
				{
					// 树结构出错
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
	// 左单旋
	void RotateL(Node* parent)
	{
		Node* ppnode = parent->_parent;
		Node* childR = parent->_right;
		Node* childRL = childR->_left;
		// 3对指针:ppnode--parent--childR--childRL
		parent->_right = childRL;
		if(childRL)
			childRL->_parent = parent;

		childR->_left = parent;
		parent->_parent = childR;

		// parent是root
		if (ppnode == nullptr) // 或者if(parent == _root)
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
		// 改平衡因子
		parent->_bf = childR->_bf = 0;
	}
	// 右单旋
	void RotateR(Node* parent)
	{
		Node* ppnode = parent->_parent;
		Node* childL = parent->_left;
		Node* childLR = childL->_right;
		// 3对指针:ppnode--parent--childL--childLR

		parent->_left = childLR;
		if (childLR)
			childLR->_parent = parent;

		childL->_right = parent;
		parent->_parent = childL;

		// parent是root
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
		// 改平衡因子
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