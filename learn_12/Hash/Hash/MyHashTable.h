#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// ��ϣ��ѧϰ

// ���ŵ�ַ��
namespace OpenAdress
{
	// ״̬
	enum State
	{
		ABSENT,	// ��
		EXIST,  // ��
		DELETE,	// ɾ��
	};

	// �ڵ�:����+״̬
	template<class T>
	struct HashNode
	{
		T _data;
		State _state;

		HashNode(const T& data = T())	// Ĭ�Ϲ���
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
			// ��ֵ,����reserve,û�г�ʼ��,��Խ�粻�ܷ���
			_table.resize(10);
		}

		bool Insert(const T& key)
		{
			// ����Ѿ�����
			if (Find(key) >= 0)
			{
				return false;
			}

			// ��������
			if (_n * 10 / _table.size() >= 7)	// ����,���ܸ�������
			{
				// ����
				size_t newsize = 2 * _table.size();
				HashTable<T> newTable;
				newTable._table.resize(newsize);

				// �������нڵ�,��Ҫ����hashi
				for (int i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXIST)
					{
						newTable.Insert(_table[i]._data);
					}
				}

				_table.swap(newTable._table);	// ����
			}

			// hashiӳ���ϵ
			int hashi = key % _table.size();
			int i = 0;
			int index = hashi;
			// ��ϣ��ͻʱ
			while (_table[index]._state == EXIST)
			{
				i++;
				index = hashi + i;		// ����̽��
				//index = hashi + i*i;	// ����̽��
				index %= _table.size();	// ��ֹԽ��
			}

			_table[index]._data = key;
			_table[index]._state = EXIST;
			++_n;

			return true;
		}

		int Find(const T& key)
		{
			// hashiӳ���ϵ
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
				index %= _table.size();	// ��ֹԽ��

				if (index == hashi)	// ����һȦ,ʲô�龰? ��ϣ����ֻ��:���ں�ɾ��,û�п�
				{
					return -1;		// û�ҵ�
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
				_table[index]._state = DELETE;	// αɾ��
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

// ������/��ϣͰ
namespace HashBuket
{
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
			// ����Ѵ���
			if (Find(key) == true)
			{
				return false;
			}

			Hash hashf;
			// ��������,����
			if (_n / _table.size() >= 1)
			{
				size_t newsize = 2 * _table.size();
				vector<Node*> newTale(newsize, nullptr);

				for (auto e : _table)
				{
					Node* cur = e;
					while (cur)
					{
						// ��ϣӳ��
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

			// ��ϣӳ��
			//int hashi = key % _table.size();
			int hashi = hashf(key) % _table.size();

			// ͷ��
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
