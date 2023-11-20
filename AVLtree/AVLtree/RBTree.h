#pragma once
#include <iostream>
#include <queue>
using namespace std;

// 红黑树学习
// 
// 1. 每个结点不是红色就是黑色 
// 2. 根节点是黑色的
// 3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
// 4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均 包含相同数目的黑色结点
// 5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点)

enum Colour
{
	RED,
	BLACK
};

// 节点
template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left = nullptr;
	RBTreeNode<K, V>* _right = nullptr;
	RBTreeNode<K, V>* _parent = nullptr;
	Colour _col = RED;
	pair<K, V> _kv;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
	{}

	RBTreeNode(const RBTreeNode<K, V>& node)
		:_col(node._col)
		, _kv(node._kv)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	//BSTree(const RBTree<K, V>& tree)   // bug:?? 拷贝构造为什么编译失败
	//{
	//	cout << "BSTree(const RBTree<K, V>& t)" << endl;
	//	_root = CopyTree(tree._root, nullptr);
	//}

	~RBTree()
	{
		cout << "~RBTree()" << endl;
		Destory(_root);
	}

	//Node* CopyTree(Node* root, Node* parent)
	//{
	//	if (root == nullptr)
	//		return nullptr;

	//	Node* cur = new Node(*root);
	//	cur->_left = CopyTree(root->_left, cur);
	//	cur->_right = CopyTree(root->_right, cur);
	//	cur->_parent = parent;
	//	return cur;
	//}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
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
			// 插入节点
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

			// 修改节点颜色,旋转使其平衡: 当cur和parent都是红色,一定有祖父,因为根节点一定是黑
			while (cur->_col == RED && parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;

				// p在g左边
				//        g
				//    p       u
				//  c | c
				if (grandfather->_left == parent)
				{

					Node* uncle = grandfather->_right;

					// 情况1.叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续向上调整
						cur = grandfather;
						parent = cur->_parent;
					}

					// 情况2/3.叔叔不存在/存在且为黑: 由情况1向上调整造成
					// 有旋转,可能需要调整根节点
					else
					{
						if (parent->_left == cur)
						{
							//       g                    p 
							//   p        u      ==>   c      g
							// c                                u
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
							{
								_root = parent;
							}
						}
						else
						{
							// p为g的左
							//      g                       c
							//   p      u      ==>      p        g
							//     c                                u      
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
							{
								_root = cur;
							}
						}
						// 子树根节点为黑,不用继续向上调整
						break;
					}
				}
				// p在g右边
				//       g
				//   u       p
				//         c | c
				else
				{
					Node* uncle = grandfather->_left;

					// 情况1.叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续向上调整
						cur = grandfather;
						parent = cur->_parent;
					}

					// 情况2/3:叔叔不存在/存在且为黑: 由情况1向上调整造成
					// 有旋转,可能需要调整根节点
					else
					{
						if (parent->_right == cur)
						{
							//      g					      p 
							//  u        p      ==>		   g      c
							//              c			 u    
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
							{
								_root = parent;
							}
						}
						else
						{
							//      g                       c
							//   u      p      ==>      g        p
							//        c               u      
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
							{
								_root = cur;
							}
						}
						break;
					}
				}
			}
			_root->_col = BLACK;	//根节点为黑
			return true;
		}
	}

	bool Find(const K& key) const
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

	bool Erase(const K& key)
	{
		//...
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	// debug用
	bool Isbalance()
	{
		int base = -1;

		return Check(_root, 0, base);
	}

	// debug用
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << "-------------------------" << endl;
	}

private:
	void _LevelOrder(Node* root)
	{
		if (root == nullptr)
			return;

		queue<Node*> st;
		Node* cur = root;
		st.push(cur);
		int levelSize = 1;
		while (!st.empty())
		{

			while (levelSize--)
			{
				Node* top = st.front();
				st.pop();
				if (top)
				{
					cout << "kv: " << top->_kv.first << " col:" << top->_col << " -> ";
					//if (top->_left)
					st.push(top->_left);
					//if (top->_right)
					st.push(top->_right);
				}
				else
					cout << "NULL" << " -> ";


			}
			cout << endl;
			levelSize = st.size();
		}
	}

	// 检查黑节点高度 && 检查连续红节点
	bool Check(Node* root, int deep, int& base)
	{
		if (root == nullptr)
		{
			if (base == -1)
				base = deep;

			if (deep != base)
			{
				cout << "黑节点高度不平衡" << endl;
				return false;
			}
			else
				return true;
		}

		// root && parent 连续为红
		Node* parent = root->_parent;
		if (root->_col == RED && parent && parent->_col == RED)
		{
			cout << "连续红节点:" << endl;
			cout << root->_kv.first << " : " << parent->_kv.first << endl;
			return false;
		}

		if (root->_col == BLACK)
			deep++;

		return Check(root->_left, deep, base) && Check(root->_right, deep, base);
	}

	void Destory(Node* root)
	{
		if (nullptr == root)
			return;

		Destory(root->_left);
		Destory(root->_right);
		//cout << root << " " << root->_kv.first << endl;
		delete root;
	}

	void _InOrder(Node* root)
	{
		if (nullptr == root)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	// 左单旋
	void RotateL(Node* parent)
	{
		//cout << "左单旋: " << parent->_kv.first << endl;
		Node* ppnode = parent->_parent;
		Node* childR = parent->_right;
		Node* childRL = childR->_left;
		// 3对指针:ppnode--parent--childR--childRL
		parent->_right = childRL;
		if (childRL)
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
	}

private:
	Node* _root = nullptr;	// debug:别忘了初始化
};