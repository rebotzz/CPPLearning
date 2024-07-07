#pragma once
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// 这里为了简化,就没有V, 可以KV
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
				cout << " ↓";
			}
			cout << endl;
			cur = cur->_nexts[0];
		}
	}

	bool Insert(const K& key)
	{
		vector<Node*> path(_head->_level, nullptr);
		Find(key, path);
		// 无论找到/没有找到,都要插入,允许重复
		size_t level = RandomLevel();
		Node* newnode = new Node(key, level);
		if (level > _head->_level)
		{
			_head->_level = level;
			_head->_nexts.resize(level, nullptr);		
			path.resize(level, _head);			// 高出的部分对应的是头节点
		}

		// 建立链接			
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
		// 找到了,开始删除
		if (ret == true)
		{
			Node* del = path[0]->_nexts[0];
			// 修改指针指向
			for (int i = 0; i < del->_level; ++i)	// 0层:删除目标的前一个节点
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
			// 比后一个大,且最后一个不为nullptr	向后跳
			if (next != nullptr && key > next->_key)
			{
				cur = next;
			}
			// debug: 为了插入/删除,需要每一层的指针, 找到也继续向下,直到0层
			else if (next != nullptr && key == next->_key)	
			{
				path[level] = cur;
				--level;
				ret = true;
			}
			// 小于/末尾nullptr 向下跳
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
	double _p = 0.5;	// 有下层的概率
};
