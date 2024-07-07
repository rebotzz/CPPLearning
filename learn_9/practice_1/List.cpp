#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//链表	cpp类封装,带头,双向,循环
typedef int DataType;

//节点
class ListNode
{
	friend class List;
public:
	//构造函数	初始化	
	ListNode()
		:_val(0)
		,_prev(nullptr)
		,_next(nullptr)
	{}

private:
	DataType _val;
	ListNode* _prev;
	ListNode* _next;
};

//链表
class List
{
public:
	//构造函数	初始化
	List()
		:_phead()
	{
		_phead = (ListNode*)malloc(sizeof(ListNode));
		_phead->_next = _phead;
		_phead->_prev = _phead;
	}

	//析构函数	释放资源
	~List()
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			ListNode* next = cur->_next;
			free(cur);
			cur = next;		//指向next
		}
		free(_phead);
	}

	//pos之前插入
	void PushInsert(DataType x,ListNode* pos)
	{
		assert(pos);

		ListNode* newnode = BuyNode(x);
		ListNode* prev = pos->_prev;

		prev->_next = newnode;
		newnode->_next = pos;
		pos->_prev = newnode;
		newnode->_prev = prev;
	}

	//pos之后插入
	void PushAfter(const DataType x, ListNode* pos)
	{
		//assert(pos);

		//ListNode* newnode = BuyNode(x);
		//ListNode* next = pos->_next;

		//pos->_next = newnode;
		//newnode->_next = next;
		//next->_prev = newnode;
		//newnode->_prev = pos;

		//复用
		PushInsert(x, pos->_next);
	}

	//BUG修复:逻辑修改,不是删除pos之前,是删除pos此位置
	void PopInsert(ListNode* pos)
	{
		assert(pos);
		//assert(pos->_prev != _phead);

		//ListNode* pprev = pos->_prev->_prev;
		//free(pos->_prev);
		//pprev->_next = pos;
		//pos->_prev = pprev;

		assert(pos != _phead);

		ListNode* prev = pos->_prev;
		ListNode* next = pos->_next;
		free(pos);
		prev->_next = next;
		next->_prev = prev;
	}

	void PopAfter(ListNode* pos)
	{
		//assert(pos);
		//assert(pos->_next != _phead);

		//ListNode* nnext = pos->_next->_next;
		//free(pos->_next);
		//pos->_next = nnext;
		//nnext->_prev = pos;

		//复用
		PopInsert(pos->_next);
	}

	void PushBack(const DataType x)
	{
		PushAfter(x, _phead->_prev);
	}

	void PushFront(const DataType x)
	{
		PushAfter(x, _phead);
	}

	void PopBack()
	{
		PopInsert(_phead->_prev);
	}

	void PopFront()
	{
		PopAfter(_phead);
	}

	ListNode* Find(const DataType x)
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			if (x == cur->_val)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}

	//ListNode 有访问限定,不能直接修改数据,需要接口函数
	void Change(const DataType x, ListNode* pos)
	{
		pos->_val = x;
	}

	void Print()
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			cout << cur->_val << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
protected:
	ListNode* BuyNode(DataType x)
	{
		ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
		if (nullptr == newnode)
		{
			perror("BuyNode");
			exit(-1);
		}

		newnode->_val = x;
		return newnode;
	}

private:
	ListNode* _phead;
};


//int main()
//{
//	List ls;
//	ls.PushBack(1);
//	ls.PushBack(2);
//	ls.PushBack(3);
//	ls.PushBack(4);
//
//	ls.PushFront(1);
//	ls.PushFront(2);
//	ls.PushFront(3);
//
//	ls.Print();
//
//	while (ls.Find(1) != nullptr)
//	{
//		ls.Change(5, ls.Find(1));
//	}
//
//	ls.Print();
//
//	while (ls.Find(2) != nullptr)
//	{
//		ls.PopInsert(ls.Find(2));
//	}
//
//	ls.Print();
//
//	ls.PushInsert(7, ls.Find(3));
//	ls.PushAfter(8, ls.Find(4));
//
//	ls.Print();
//
//	return 0;
//}