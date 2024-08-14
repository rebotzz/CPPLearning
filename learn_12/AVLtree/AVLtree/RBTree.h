#pragma once
#include <iostream>
#include <queue>
using namespace std;

// �����ѧϰ
// 
// 1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ 
// 2. ���ڵ��Ǻ�ɫ��
// 3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
// 4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ��� ������ͬ��Ŀ�ĺ�ɫ���
// 5. ÿ��Ҷ�ӽ�㶼�Ǻ�ɫ��(�˴���Ҷ�ӽ��ָ���ǿս��)

enum Colour
{
	RED,
	BLACK
};

// �ڵ�
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

	//BSTree(const RBTree<K, V>& tree)   // bug:?? ��������Ϊʲô����ʧ��
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
			// ����ڵ�
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

			// �޸Ľڵ���ɫ,��תʹ��ƽ��: ��cur��parent���Ǻ�ɫ,һ�����游,��Ϊ���ڵ�һ���Ǻ�
			while (cur->_col == RED && parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;

				// p��g���
				//        g
				//    p       u
				//  c | c
				if (grandfather->_left == parent)
				{

					Node* uncle = grandfather->_right;

					// ���1.���������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// �������ϵ���
						cur = grandfather;
						parent = cur->_parent;
					}

					// ���2/3.���岻����/������Ϊ��: �����1���ϵ������
					// ����ת,������Ҫ�������ڵ�
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

							// �޸ĸ��ڵ�
							if (_root == grandfather)
							{
								_root = parent;
							}
						}
						else
						{
							// pΪg����
							//      g                       c
							//   p      u      ==>      p        g
							//     c                                u      
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// �޸ĸ��ڵ�
							if (_root == grandfather)
							{
								_root = cur;
							}
						}
						// �������ڵ�Ϊ��,���ü������ϵ���
						break;
					}
				}
				// p��g�ұ�
				//       g
				//   u       p
				//         c | c
				else
				{
					Node* uncle = grandfather->_left;

					// ���1.���������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// �������ϵ���
						cur = grandfather;
						parent = cur->_parent;
					}

					// ���2/3:���岻����/������Ϊ��: �����1���ϵ������
					// ����ת,������Ҫ�������ڵ�
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

							// �޸ĸ��ڵ�
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

							// �޸ĸ��ڵ�
							if (_root == grandfather)
							{
								_root = cur;
							}
						}
						break;
					}
				}
			}
			_root->_col = BLACK;	//���ڵ�Ϊ��
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

	// debug��
	bool Isbalance()
	{
		int base = -1;

		return Check(_root, 0, base);
	}

	// debug��
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

	// ���ڽڵ�߶� && ���������ڵ�
	bool Check(Node* root, int deep, int& base)
	{
		if (root == nullptr)
		{
			if (base == -1)
				base = deep;

			if (deep != base)
			{
				cout << "�ڽڵ�߶Ȳ�ƽ��" << endl;
				return false;
			}
			else
				return true;
		}

		// root && parent ����Ϊ��
		Node* parent = root->_parent;
		if (root->_col == RED && parent && parent->_col == RED)
		{
			cout << "������ڵ�:" << endl;
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

	// ����
	void RotateL(Node* parent)
	{
		//cout << "����: " << parent->_kv.first << endl;
		Node* ppnode = parent->_parent;
		Node* childR = parent->_right;
		Node* childRL = childR->_left;
		// 3��ָ��:ppnode--parent--childR--childRL
		parent->_right = childRL;
		if (childRL)
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
	}

private:
	Node* _root = nullptr;	// debug:�����˳�ʼ��
};