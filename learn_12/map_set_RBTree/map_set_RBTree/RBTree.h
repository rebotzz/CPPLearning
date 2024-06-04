#pragma once
#include <assert.h>
using std::pair;
using std::make_pair;
// �������װmap/set
// 
// Ϊ����ͬʱ����map��set,��Ҫ����ģ�����

// ö�����ͱ���ֻ�ܸ�ֵ���е�ֵ
enum Colour
{
	RED,
	BLACK
};

// �ڵ�
template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left = nullptr;
	RBTreeNode<T>* _right = nullptr;
	RBTreeNode<T>* _parent = nullptr;
	Colour _col = RED;
	T _data;

	RBTreeNode(const T& data)
		:_data(data)
	{}

};

// ������: ˫��
template<class T, class Ref, class Ptr>
struct __iterator_rbTree
{
	typedef RBTreeNode<T> Node;
	typedef __iterator_rbTree<T, T&, T*> Iterator;	// ��ͨ������
	typedef __iterator_rbTree<T, Ref, Ptr> Self;	// ��ͨ/const������
	// ��Ա����
	Node* _pnode;

	__iterator_rbTree(Node* pnode)	// debug:����const Node*,Ȩ�޲��ܷŴ�
		:_pnode(pnode)
	{}

	// ֧����ͨ����������const������,������ʽ����ת��
	__iterator_rbTree(const Iterator& it)
		:_pnode(it._pnode)
	{}

	Ref operator*()		// ��������
	{
		return _pnode->_data;
	}

	Ptr operator->()	// ���洢���ǽṹ��ʱ,���ؽṹ��ָ��
	{
		return &_pnode->_data;
	}

	bool operator!=(const Self& it)
	{
		return _pnode != it._pnode;
	}

	bool operator==(const Self& it)
	{
		return _pnode == it._pnode;
	}

	//ǰ��++
	Self& operator++()
	{
		// ��_pnodeΪ��,����_root->parent == nullptr; �����
		assert(_pnode != nullptr);

		// ������������һ��
		Node* cur = _pnode;
		if (cur->_right)
		{
		// 1.��������Ϊ��,��һ����������������ڵ�
			Node* subR = cur->_right;
			while (subR->_left)
			{
				subR = subR->_left;
			}
			_pnode = subR;
		}
		else
		{
		// 2.������Ϊ��:
		// cur��parent����ڵ�,parent������һ��
		// cur��parent���ҽڵ�,����Ѱ��,ֱ��cur��parent����ڵ�
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_pnode = parent;	// ���һ������һ��Ϊnullptr
		}
		return *this;
	}

	//����++
	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}

	//ǰ��--
	Self& operator--()
	{	
		// ��_pnodeΪ��,��--end();����_root->parent == nullptr; �����
		assert(_pnode != nullptr);

		// ����������һ��
		Node* cur = _pnode;
		if (cur->_left)
		{
		// 1.��������Ϊ��,��һ�����������������ҽڵ�
			Node* subL = cur->_left;
			while (subL->_right)
			{
				subL = subL->_right;
			}
			_pnode = subL;
		}
		else
		{
		// 2.������Ϊ��:
		// curΪparent�ҽڵ�,��һ����parent
		// curΪparent��ڵ�,����������,ֱ��cur��parent�ҽڵ�
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_pnode = parent;	// ��һ������һ��Ϊnullptr
		}
		return *this;
	}

	//����--
	Self operator--(int)
	{
		Self tmp(*this);
		--(*this);
		return tmp;
	}

};

// ���������: ��װ���������
template<class forward_iterator, class T, class Ref, class Ptr>
struct __reverse_iterator_rbTree
{
	typedef __reverse_iterator_rbTree<forward_iterator, T, T&, T*> reverse_iterator;
	typedef __reverse_iterator_rbTree<forward_iterator, T, Ref, Ptr> Self;
	forward_iterator _it;

	__reverse_iterator_rbTree(const forward_iterator& it)
		:_it(it)
	{}

	// ֧��<iterator, T, T&, T*>����<iterator, T, const T&, const T*>,��ʽ����ת��
	__reverse_iterator_rbTree(const reverse_iterator& rit)
		:_it(rit._it)
	{}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return &(*_it);
	}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(_it);
		--_it;
		return tmp;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(_it);
		++_it;
		return tmp;
	}

	bool operator!=(const Self& rit)
	{
		return _it != rit._it;
	}

	bool operator==(const Self& rit)
	{
		return _it == rit._it;
	}

};

// key, value:key(set) | key/value(map)  �º���: get key of value
template<class Key, class Value, class GetKofV>
class RBTree
{
	// ʹ��Value����ڵ�
	typedef RBTreeNode<Value> Node;
public:
	// ������
	typedef __iterator_rbTree<Value, Value&, Value*> iterator;
	typedef __iterator_rbTree<Value, const Value&, const Value*> const_iterator;
	typedef __reverse_iterator_rbTree<iterator, Value, Value&, Value*> reverse_iterator;
	typedef __reverse_iterator_rbTree<iterator, Value, const Value&, const Value*> const_reverse_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	iterator end()
	{
		// ָ�����һ������һ��,��nullptr
		return iterator(nullptr);
	}

	const_iterator end() const 
	{
		return const_iterator(nullptr);
	}

	reverse_iterator rbegin()
	{
		// ӦΪend()Ϊnullptr,���Բ���ֱ����end()����
		Node* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return reverse_iterator(iterator(cur));
	}

	reverse_iterator rend()
	{
		// rend()Ϊ��һ������һ��,Ϊnullptr
		return reverse_iterator(iterator(nullptr));
	}

	const_reverse_iterator rbegin() const
	{
		// ӦΪend()Ϊnullptr,���Բ���ֱ����end()����
		Node* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return const_reverse_iterator(iterator(cur));
	}

	const_reverse_iterator rend() const
	{
		// rend()Ϊ��һ������һ��,Ϊnullptr
		return const_reverse_iterator(iterator(nullptr));
	}


	RBTree() = default;

	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	pair<iterator, bool> Insert(const Value& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			//return pair<iterator, bool>(_root, true);
			return make_pair(iterator(_root), true);
		}
		else
		{
			// ����_root->parent = nullptr,��Ķ��и��ڵ�
			Node* parent = nullptr;
			Node* cur = _root;
			// �ҵ�����λ��
			while (cur)
			{
				if (getKey(cur->_data) > getKey(data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (getKey(cur->_data) < getKey(data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					//return pair<iterator, bool>(cur, false);
					return make_pair(iterator(cur), false);
				}
			}
			// ����ڵ�
			cur = new Node(data);
			Node* newnode = cur;	// ��ǰ����,��ֹ��ת���ϵ�����ʧ
			if (getKey(parent->_data) > getKey(data))
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
					else
					{
						if (parent->_left == cur)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// �޸ĸ��ڵ�
							if (_root == grandfather)
								_root = parent;
						}
						else
						{
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// �޸ĸ��ڵ�
							if (_root == grandfather)
								_root = cur;
						}
						// �������ڵ�Ϊ��,���ü������ϵ���
						break;
					}
				}
				// p��g�ұ�
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
					else
					{
						if (parent->_right == cur)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// �޸ĸ��ڵ�
							if (_root == grandfather)
								_root = parent;
						}
						else
						{
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// �޸ĸ��ڵ�
							if (_root == grandfather)
								_root = cur;
						}
						break;
					}
				}
			}
			_root->_col = BLACK;	//���ڵ�Ϊ��
			return make_pair(iterator(newnode), true);
		}
	}

	Node* Find(const Key& key) const
	{
		Node* cur = _root;
		while (cur)
		{
			if (getKey(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (getKey(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const Key& key)
	{
		//...
	}



private:
	void Destory(Node* root)
	{
		if (nullptr == root)
			return;

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	// ����
	void RotateL(Node* parent)
	{
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
	GetKofV getKey;			// �º���
};