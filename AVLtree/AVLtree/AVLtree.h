#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// AVL树学习: 高度平衡搜索二叉树
// 
// 左右子树高度差不超过1

// 节点
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;		// blance factor 平衡因子:右子树高度 - 左子树高度
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

// AVL树
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
			// 除了_root->parent = nullptr,别的都有父节点
			Node* parent = nullptr;
			Node* cur = _root;
			// 找到插入位置
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
					// 调整树结构
					// 1.使左右子树平衡. 2.降低树的高度
					//cout << "调整树结构" << endl;
					if (parent->_bf == 2 && cur->_bf == 1)	// 左单旋
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1) // 右单旋
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1) // RL双旋
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1) // LR双旋
					{
						RotateLR(parent);
					}

					break;
				}
				else
				{
					// 树结构出错
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
		//待续...
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	// 检查是否平衡
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
			cout << root->_kv.first << "平衡因子出错:" << root->_bf << endl;
			return false;
		}

		// 1.0
		//if (abs(deepL - deepR) >= 2)
		//	return false;
		//_IsBalance(root->_left);
		//_IsBalance(root->_right);
		//return true;

		// 2.0
		// 所有子树高度差不能超过2
		return (abs(deepL - deepR) < 2) && _IsBalance(root->_left) && _IsBalance(root->_right);
	}

	// 树的高度
	int TreeDeep(Node* root)
	{
		if (root == nullptr)
			return 0;

		int deepL = TreeDeep(root->_left);
		int deepR = TreeDeep(root->_right);

		return deepL > deepR ? deepL + 1 : deepR + 1;  // int deep = 1 + max(deepL, deepR);
	}

private:
	// 左单旋
	void RotateL(Node* parent)
	{
		//cout << "左单旋: " << parent->_kv.first << endl;
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
		//cout << "右单旋: " << parent->_kv.first << endl;
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

	// RL双旋
	void RotateRL(Node* parent)
	{
		//cout << "RL双旋: " << parent->_kv.first << endl;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;	
		int bf = subRL->_bf;
		// subR右旋,parent左旋
		RotateR(subR);
		RotateL(parent);
		// 修改平衡因子
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
	// LR双旋
	void RotateLR(Node* parent)
	{
		//cout << "LR双旋: " << parent->_kv.first << endl;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		// subL左单旋,parent右单旋
		RotateL(subL);
		RotateR(parent);
		//修改平衡因子
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