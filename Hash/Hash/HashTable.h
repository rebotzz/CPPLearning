#pragma once
#include <vector>
#include <assert.h>
using std::pair;
using std::make_pair;

// 完善哈希表,为封装map/set做准备

// 声明
template<class T>
struct HashNode;

// 迭代器
template<class T, class Ref, class Ptr, class Hash, class GetKeyofT>
class __hashTable_iterator
{
public:
	typedef __hashTable_iterator<T, T&, T*, Hash, GetKeyofT> iterator;
	typedef __hashTable_iterator<T, Ref, Ptr, Hash, GetKeyofT> self;
	typedef HashNode<T> Node;

	Node* _node;
	vector<Node*>* _table;

	__hashTable_iterator(Node* node, vector<Node*>* table)
		:_node(node)
		,_table(table)
	{}

	// 单参数构造,支持隐式类型转换,iterator构造const_iterator
	__hashTable_iterator(const iterator& it)
		:_node(it._node)
		,_table(it._table)
	{}

	Ref operator*()
	{
		assert(_node != nullptr);

		return _node->_data;
	}

	Ptr operator->()
	{
		return &operator*();
	}

	self operator++()
	{
		assert(_node != nullptr || _table != nullptr);
		// 仿函数
		Hash hashf;
		GetKeyofT getK;
		Node* cur = _node->_next;
		size_t size = _table->size();
		size_t hashi = hashf(getK(_node->_data)) % size;
		while (cur == nullptr)
		{
			if (++hashi < size)
			{
				cur = (*_table)[hashi];
			}
			else
			{
				break;
			}
		}

		_node = cur;
		return *this;
	}

	self operator++(int)
	{
		self tmp = *this;
		operator++();
		return tmp;
	}

	bool operator==(const self& it)
	{
		return _node == it._node && _table == it._table;
	}

	bool operator!=(const self& it)
	{
		return _node != it._node;
	}

};


// 哈希函数,获取hashi
template<class T>
struct HashFunc
{
	T operator()(const T& key)
	{
		return key;
	}
};

// 模板特化
template<>
struct HashFunc<string>
{
	int operator()(const string& str)
	{
		int hashi = 0;

		//int i = 1;
		//for (auto ch : str)
		//{
		//	hashi += ch * i;
		//	++i;
		//}

		// BKDRHash
		for (auto ch : str)
		{
			hashi += ch * 31; // 也可以乘以31、131、1313、13131、131313..  
		}

		return hashi;
	}

};

template<class T>
struct HashNode	// 单链表
{
	HashNode<T>* _next;
	T _data;

	HashNode(const T& data = T())
		:_next(nullptr)
		, _data(data)
	{}
};

template<class Key, class T, class GetKeyofT, class Hash = HashFunc<T>>
class HashTable
{
	typedef HashNode<T> Node;
public:
	typedef __hashTable_iterator<T, T&, T*, Hash, GetKeyofT> iterator;
	typedef __hashTable_iterator<T, const T&, const T*, Hash, GetKeyofT> const_iterator;

	HashTable()
		:_n(0)
	{
		_table.resize(7, nullptr);	//  除留余数法，最好模一个素数
	}

	~HashTable()
	{
		Clear();
		//std::cout << "~HashTable()" << "\n";
	}

	iterator begin()
	{
		Node* cur = nullptr;
		for (auto e : _table)
		{
			if (e != nullptr)
			{
				cur = e;
				break;
			}
		}

		return iterator(cur, &_table);
	}

	iterator end()
	{
		return iterator(nullptr, &_table);
	}

	const_iterator begin() const
	{
		Node* cur = nullptr;
		for (auto e : _table)
		{
			if (e != nullptr)
			{
				cur = e;
				break;
			}
		}

		return const_iterator(cur, &_table);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr, &_table);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		// 仿函数
		Hash hashf;
		GetKeyofT getK;
		// 如果已存在
		iterator it = Find(getK(data));
		if (it != end())
		{
			return make_pair(it, false);
		}

		// 负载因子,扩容
		if (_n / _table.size() >= 1)
		{
			//size_t newsize = 2 * _table.size();
			size_t newsize = GetNextPrime(_table.size()); // 除留余数法，最好模一个素数
			vector<Node*> newTale(newsize, nullptr);

			for (auto e : _table)
			{
				Node* cur = e;
				while (cur)
				{
					// 哈希映射
					Node* next = cur->_next;
					int hashi = hashf(getK(cur->_data)) % newTale.size();
					cur->_next = newTale[hashi];
					newTale[hashi] = cur;
					cur = next;
				}
			}
			_table.swap(newTale);
		}

		// 哈希映射
		int hashi = hashf(getK(data)) % _table.size();
		// 头插
		Node* newnode = new Node(data);
		newnode->_next = _table[hashi];
		_table[hashi] = newnode;
		_n++;

		return make_pair(iterator(newnode, &_table), true);
	}

	iterator Find(const Key& key)
	{
		// 仿函数
		Hash hashf;
		GetKeyofT getK;
		int hashi = hashf(key) % _table.size();
		Node* cur = _table[hashi];
		while (cur)
		{
			if (getK(cur->_data) == key)
			{
				return iterator(cur, &_table);
			}
			cur = cur->_next;
		}

		return iterator(nullptr, &_table);
	}

	bool Erase(const Key& key)
	{
		// 仿函数
		Hash hashf;
		GetKeyofT getK;
		int hashi = hashf(key) % _table.size();
		Node* cur = _table[hashi];
		Node* prev = cur;
		while (cur)
		{
			if (getK(cur->_data) == key)
			{
				if (prev == cur)
				{
					_table[hashi] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				_n--;
				delete cur;
				return true;
			}

			prev = cur;
			cur = cur->_next;
		}
		return false;
	}

	int size()
	{
		return _n;
	}

	void Clear()
	{
		for (auto& e : _table)
		{
			Node* cur = e;
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			e = nullptr;	// _table[] 每个元素置空,防止重复delete
		}
		_n = 0;
	}

	void Swap(HashTable< Key, T, GetKeyofT, Hash>& hs)
	{
		_table.swap(hs._table);
		std::swap(_n, hs._n);
	}

	// 返回为关键值为key的元素个数
	size_t Count(const Key& key)
	{
		size_t count = 0;
		// 仿函数
		Hash hashf;
		GetKeyofT getK;
		int hashi = hashf(key) % _table.size();
		Node* cur = _table[hashi];
		while (cur)
		{
			if (getK(cur->_data) == key)
			{
				++count;
			}
			cur = cur->_next;
		}
		return count;
	}

private:
	size_t GetNextPrime(size_t val)
	{
		// 素数表
		static const size_t primeList[] =
		{
		17ul, 53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul,25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul,805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
		};

		for (auto num : primeList)
		{
			if (num > val)
				return num;
		}
		size_t sz = sizeof(primeList) / sizeof(primeList[0]);
		return primeList[sz - 1];
	}
	 
private:
	vector<Node*> _table;
	int _n;
};