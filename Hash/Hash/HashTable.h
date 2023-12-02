#pragma once
#include <vector>
#include <assert.h>
using std::pair;
using std::make_pair;

// ���ƹ�ϣ��,Ϊ��װmap/set��׼��

// ����
template<class T>
struct HashNode;

// ������
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

	// ����������,֧����ʽ����ת��,iterator����const_iterator
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
		// �º���
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


// ��ϣ����,��ȡhashi
template<class T>
struct HashFunc
{
	T operator()(const T& key)
	{
		return key;
	}
};

// ģ���ػ�
template<>
struct HashFunc<string>
{
	int operator()(const string& str)
	{
		int hashi = 0;
		int i = 1;
		for (auto ch : str)
		{
			hashi += ch * i;
			++i;
		}

		return hashi;
	}

};

template<class T>
struct HashNode	// ������
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
		_table.resize(10, nullptr);
	}

	~HashTable()
	{
		for (auto e : _table)
		{
			Node* cur = e;
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
		}
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
		// �º���
		Hash hashf;
		GetKeyofT getK;
		// ����Ѵ���
		iterator it = Find(getK(data));
		if (it != end())
		{
			return make_pair(it, false);
		}

		// ��������,����
		if (_n / _table.size() >= 1)
		{
			int newsize = 2 * _table.size();
			vector<Node*> newTale(newsize, nullptr);

			for (auto e : _table)
			{
				Node* cur = e;
				while (cur)
				{
					// ��ϣӳ��
					Node* next = cur->_next;
					int hashi = hashf(getK(cur->_data)) % newTale.size();
					cur->_next = newTale[hashi];
					newTale[hashi] = cur;
					cur = next;
				}
			}
			_table.swap(newTale);
		}

		// ��ϣӳ��
		int hashi = hashf(getK(data)) % _table.size();
		// ͷ��
		Node* newnode = new Node(data);
		newnode->_next = _table[hashi];
		_table[hashi] = newnode;
		_n++;

		return make_pair(iterator(newnode, &_table), true);
	}

	iterator Find(const Key& key)
	{
		// �º���
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
		// �º���
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

private:
	vector<Node*> _table;
	int _n;
};