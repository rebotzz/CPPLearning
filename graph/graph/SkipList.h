#pragma once
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// ����Ϊ�˼�,��û��V, ����KV
template<class K>
struct SkiplistNode
{
	using Node = SkiplistNode<K>;

	K _key;
	size_t _level;
	vector<Node*> _nexts;

	SkiplistNode(const K& key = K(), size_t level = 1)
		:_key(key)
		, _level(level)
	{
		_nexts.resize(level, nullptr);
	}
};

template<class K, size_t MAXLEVEL = 32>
class Skiplist
{
	using Node = SkiplistNode<K>;
public:
	Skiplist()
		:_head(new Node)
	{
		srand((unsigned int)time(nullptr));
	}
	~Skiplist()
	{
		Node* cur = _head;
		Node* next = cur->_nexts[0];
		while (cur)
		{
			delete cur;
			cur = next;
			if(next)
				next = next->_nexts[0];
		}
	}

	void Print()
	{
		Node* cur = _head;
		while (cur)
		{
			cout << cur->_key << endl;
			for (int i = 0; i < cur->_level; ++i)
			{
				cout << " ��";
			}
			cout << endl;
			cur = cur->_nexts[0];
		}
	}

	bool Insert(const K& key)
	{
		vector<Node*> path(_head->_level, nullptr);
		Find(key, path);
		// �����ҵ�/û���ҵ�,��Ҫ����,�����ظ�
		size_t level = RandomLevel();
		Node* newnode = new Node(key, level);
		if (level > _head->_level)
		{
			_head->_level = level;
			_head->_nexts.resize(level, nullptr);		
			path.resize(level, _head);			// �߳��Ĳ��ֶ�Ӧ����ͷ�ڵ�
		}

		// ��������			
		for (size_t i = 0; i < newnode->_level; ++i)
		{
			newnode->_nexts[i] = path[i]->_nexts[i];
			path[i]->_nexts[i] = newnode;
		}

		return true;
	}

	size_t RandomLevel()
	{
		size_t level = 1;
		while (rand() < _p * RAND_MAX && level <= MAXLEVEL)
		{
			level++;
		}
		return level;
	}

	bool Erase(const K& key)
	{
		vector<Node*> path(_head->_level, nullptr);
		bool ret = Find(key, path);
		// �ҵ���,��ʼɾ��
		if (ret == true)
		{
			Node* del = path[0]->_nexts[0];
			// �޸�ָ��ָ��
			for (int i = 0; i < del->_level; ++i)	// 0��:ɾ��Ŀ���ǰһ���ڵ�
			{
				path[i]->_nexts[i] = del->_nexts[i];
			}

			delete del;
			return true;
		}
		
		return false;
	}

	bool Find(const K& key, vector<Node*>& path)
	{
		path.resize(_head->_level, nullptr);
		int level = _head->_level - 1;
		Node* cur = _head;
		bool ret = false;
		while (cur != nullptr && level >= 0)	
		{
			Node* next = cur->_nexts[level];
			// �Ⱥ�һ����,�����һ����Ϊnullptr	�����
			if (next != nullptr && key > next->_key)
			{
				cur = next;
			}
			// debug: Ϊ�˲���/ɾ��,��Ҫÿһ���ָ��, �ҵ�Ҳ��������,ֱ��0��
			else if (next != nullptr && key == next->_key)	
			{
				path[level] = cur;
				--level;
				ret = true;
			}
			// С��/ĩβnullptr ������
			else if (next == nullptr || key < next->_key)
			{
				path[level] = cur;
				--level;
			}
		}

		return ret;
	}


private:
	Node* _head;
	double _p = 0.5;	// ���²�ĸ���
};
