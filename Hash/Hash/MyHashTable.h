#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// 哈希表学习

// 开放地址法
namespace OpenAdress
{
	// 状态
	enum State
	{
		ABSENT,	// 无
		EXIST,  // 有
		DELETE,	// 删除
	};

	// 节点:数据+状态
	template<class T>
	struct HashNode
	{
		T _data;
		State _state;

		HashNode(const T& data = T())	// 默认构造
			:_data(data)
			, _state(ABSENT)
		{}
	};

	template <class T>
	class HashTable
	{
	public:
		HashTable()
			:_n(0)
		{
			// 初值,不能reserve,没有初始化,且越界不能访问
			_table.resize(10);
		}

		bool Insert(const T& key)
		{
			// 如果已经存在
			if (Find(key) >= 0)
			{
				return false;
			}

			// 负载因子
			if (_n * 10 / _table.size() >= 7)	// 整形,不能浮点运算
			{
				// 扩容
				size_t newsize = 2 * _table.size();
				HashTable<T> newTable;
				newTable._table.resize(newsize);

				// 插入已有节点,需要更新hashi
				for (int i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXIST)
					{
						newTable.Insert(_table[i]._data);
					}
				}

				_table.swap(newTable._table);	// 交换
			}

			// hashi映射关系
			int hashi = key % _table.size();
			int i = 0;
			int index = hashi;
			// 哈希冲突时
			while (_table[index]._state == EXIST)
			{
				i++;
				index = hashi + i;		// 线性探测
				//index = hashi + i*i;	// 二次探测
				index %= _table.size();	// 防止越界
			}

			_table[index]._data = key;
			_table[index]._state = EXIST;
			++_n;

			return true;
		}

		int Find(const T& key)
		{
			// hashi映射关系
			int hashi = key % _table.size();
			int i = 0;
			int index = hashi;

			while (_table[index]._state != ABSENT)
			{
				if (_table[index]._data == key)
				{
					return index;
				}

				i++;
				index = hashi + i;
				index %= _table.size();	// 防止越界

				if (index == hashi)	// 找了一圈,什么情景? 哈希表中只有:存在和删除,没有空
				{
					return -1;		// 没找到
				}
			}

			return -1;
		}

		bool Erase(const T& key)
		{
			int index = Find(key);
			if (index == -1)
			{
				return false;
			}
			else
			{
				_table[index]._state = DELETE;	// 伪删除
				--_n;
				return true;
			}
		}

		void Print()
		{
			for (auto v : _table)
			{
				if (v._state == EXIST)
				{
					cout << v._data << " ";
				}
			}
			cout << endl;
		}

	private:
		vector<HashNode<T>> _table;
		int _n;
	};


	void test_hashtable1()
	{
		HashTable<int> ht;
		srand((unsigned)time(NULL));
		int N = 15;
		for (int i = 0; i < N; ++i)
		{
			int num = rand();
			ht.Insert(num);
		}


		//ht.Insert(2);
		//ht.Insert(4);
		//ht.Insert(5);
		//ht.Insert(15);
		//ht.Insert(21);
		//ht.Insert(32);
		//ht.Insert(9);
		//ht.Insert(19);
	}

	void test_hashtable2()
	{
		int arr[] = { 2, 12, 4, 13, 33,102, 8,15, 25 };
		HashTable<int> ht;

		for (auto e : arr)
		{
			ht.Insert(e);
		}
		ht.Print();

		ht.Erase(12);
		ht.Erase(33);
		ht.Erase(4);
		ht.Print();

	}

}

// 拉链法/哈希桶
namespace HashBuket
{
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
	struct HashNode	// 单链表
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data = T())
			:_next(nullptr)
			,_data(data)
		{}
	};

	template<class T, class Hash = HashFunc<T>>
	class HashTable
	{
		typedef HashNode<T> Node;
	public:
		HashTable()
			:_n(0)
		{
			_table.resize(10,nullptr);
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
		}

		bool Insert(const T& key)
		{
			// 如果已存在
			if (Find(key) == true)
			{
				return false;
			}

			Hash hashf;
			// 负载因子,扩容
			if (_n / _table.size() >= 1)
			{
				size_t newsize = 2 * _table.size();
				vector<Node*> newTale(newsize, nullptr);

				for (auto e : _table)
				{
					Node* cur = e;
					while (cur)
					{
						// 哈希映射
						Node* next = cur->_next;
						//int hashi = cur->_data % newTale.size();
						int hashi = hashf(cur->_data) % newTale.size();
						cur->_next = newTale[hashi];
						newTale[hashi] = cur;
						cur = next;
					}
				}
				_table.swap(newTale);
			}

			// 哈希映射
			//int hashi = key % _table.size();
			int hashi = hashf(key) % _table.size();

			// 头插
			Node* newnode = new Node(key);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			_n++;

			return true;
		}

		bool Find(const T& key)
		{
			Hash hashf;
			int hashi = hashf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_data == key)
				{
					return true;
				}
				cur = cur->_next;
			}

			return false;
		}

		bool Erase(const T& key)
		{
			//int hashi = key % _table.size();
			Hash hashf;
			int hashi = hashf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = cur;
			while (cur)
			{
				if (cur->_data == key)
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

	private:
		vector<Node*> _table;
		int _n;
	};



	void test_hashB1()
	{
		HashTable<int> ht;
		int arr[] = { 2, 12, 4, 13, 33,102, 8,15, 25 };
		for (auto e : arr)
		{
			ht.Insert(e);
		}
		ht.Insert(12);

		cout << ht.Find(19) << endl;
		cout << ht.Find(8) << endl;
		cout << ht.Erase(4) << endl;
		//cout << ht.Erase(102) << endl;
		cout << ht.Erase(12) << endl;
		//cout << ht.Erase(2) << endl;

		cout << " " << endl;
	}
}
