#pragma once
#include <assert.h>
using std::pair;
using std::make_pair;
// 红黑树封装map/set
// 
// 为了能同时适配map和set,需要更改模板参数

// 枚举类型变量只能赋值其中的值
enum Colour
{
	RED,
	BLACK
};

// 节点
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

// 迭代器: 双向
template<class T, class Ref, class Ptr>
struct __iterator_rbTree
{
	typedef RBTreeNode<T> Node;
	typedef __iterator_rbTree<T, T&, T*> Iterator;	// 普通迭代器
	typedef __iterator_rbTree<T, Ref, Ptr> Self;	// 普通/const迭代器
	// 成员变量
	Node* _pnode;

	__iterator_rbTree(Node* pnode)	// debug:不是const Node*,权限不能放大
		:_pnode(pnode)
	{}

	// 支持普通迭代器构造const迭代器,可以隐式类型转换
	__iterator_rbTree(const Iterator& it)
		:_pnode(it._pnode)
	{}

	Ref operator*()		// 返回引用
	{
		return _pnode->_data;
	}

	Ptr operator->()	// 当存储的是结构体时,返回结构体指针
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

	//前置++
	Self& operator++()
	{
		// 当_pnode为空,由于_root->parent == nullptr; 待解决
		assert(_pnode != nullptr);

		// 按照中序找下一个
		Node* cur = _pnode;
		if (cur->_right)
		{
		// 1.右子树不为空,下一个是右子树的最左节点
			Node* subR = cur->_right;
			while (subR->_left)
			{
				subR = subR->_left;
			}
			_pnode = subR;
		}
		else
		{
		// 2.右子树为空:
		// cur是parent的左节点,parent就是下一个
		// cur是parent的右节点,向上寻找,直到cur是parent的左节点
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_pnode = parent;	// 最后一个的下一个为nullptr
		}
		return *this;
	}

	//后置++
	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}

	//前置--
	Self& operator--()
	{	
		// 当_pnode为空,即--end();由于_root->parent == nullptr; 待解决
		assert(_pnode != nullptr);

		// 按中序找上一个
		Node* cur = _pnode;
		if (cur->_left)
		{
		// 1.左子树不为空,上一个就是左子树的最右节点
			Node* subL = cur->_left;
			while (subL->_right)
			{
				subL = subL->_right;
			}
			_pnode = subL;
		}
		else
		{
		// 2.左子树为空:
		// cur为parent右节点,上一个是parent
		// cur为parent左节点,继续向上找,直到cur是parent右节点
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_pnode = parent;	// 第一个的上一个为nullptr
		}
		return *this;
	}

	//后置--
	Self operator--(int)
	{
		Self tmp(*this);
		--(*this);
		return tmp;
	}

};

// 反向迭代器: 封装正向迭代器
template<class forward_iterator, class T, class Ref, class Ptr>
struct __reverse_iterator_rbTree
{
	typedef __reverse_iterator_rbTree<forward_iterator, T, T&, T*> reverse_iterator;
	typedef __reverse_iterator_rbTree<forward_iterator, T, Ref, Ptr> Self;
	forward_iterator _it;

	__reverse_iterator_rbTree(const forward_iterator& it)
		:_it(it)
	{}

	// 支持<iterator, T, T&, T*>构造<iterator, T, const T&, const T*>,隐式类型转换
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

// key, value:key(set) | key/value(map)  仿函数: get key of value
template<class Key, class Value, class GetKofV>
class RBTree
{
	// 使用Value构造节点
	typedef RBTreeNode<Value> Node;
public:
	// 迭代器
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
		// 指向最后一个的下一个,即nullptr
		return iterator(nullptr);
	}

	const_iterator end() const 
	{
		return const_iterator(nullptr);
	}

	reverse_iterator rbegin()
	{
		// 应为end()为nullptr,所以不能直接用end()构造
		Node* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return reverse_iterator(iterator(cur));
	}

	reverse_iterator rend()
	{
		// rend()为第一个的上一个,为nullptr
		return reverse_iterator(iterator(nullptr));
	}

	const_reverse_iterator rbegin() const
	{
		// 应为end()为nullptr,所以不能直接用end()构造
		Node* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return const_reverse_iterator(iterator(cur));
	}

	const_reverse_iterator rend() const
	{
		// rend()为第一个的上一个,为nullptr
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
			// 除了_root->parent = nullptr,别的都有父节点
			Node* parent = nullptr;
			Node* cur = _root;
			// 找到插入位置
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
			// 插入节点
			cur = new Node(data);
			Node* newnode = cur;	// 提前保存,防止旋转向上调整丢失
			if (getKey(parent->_data) > getKey(data))
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
					else
					{
						if (parent->_left == cur)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
								_root = parent;
						}
						else
						{
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
								_root = cur;
						}
						// 子树根节点为黑,不用继续向上调整
						break;
					}
				}
				// p在g右边
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
					else
					{
						if (parent->_right == cur)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
								_root = parent;
						}
						else
						{
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;

							// 修改根节点
							if (_root == grandfather)
								_root = cur;
						}
						break;
					}
				}
			}
			_root->_col = BLACK;	//根节点为黑
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

	// 左单旋
	void RotateL(Node* parent)
	{
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
	GetKofV getKey;			// 仿函数
};