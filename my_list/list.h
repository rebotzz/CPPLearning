#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


namespace kozen
{
	//节点
	template<class T>
	struct __list_node
	{
		typedef __list_node<T> node;

		__list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(val)
		{}

		node* _next;
		node* _prev;
		T _data;
	};

	//迭代器
	//迭代器有两种
	//1.原生指针 2.对原生指针封装,然后运算符重载,模拟原生指针功能
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T,Ref,Ptr> iterator;
		node* _pn;

		__list_iterator(node* p)
			:_pn(p)
		{}

		iterator operator++()
		{
			_pn = _pn->_next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp(*this);
			_pn = _pn->_next;
			return tmp;
		}

		iterator operator--()
		{
			_pn = _pn->_prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp(*this);
			_pn = _pn->_prev;
			return tmp;
		}

		
		//Ref operator*() const	//const相当于const __list_iterator* this;
		//即const _pn => node* const _pn;但是_pn->_data可改动;感觉没啥作用;迭代器本身就可以改动,并不是const的
		//T&  const T&
		Ref operator*() 
		{
			return _pn->_data;
		}

		//迭代器模仿存储变量的指针行为,
		//当变量是对象时,使用->访问成员
		//Ptr T*  const T*
		Ptr operator->()
		{
			return &_pn->_data;
		}

		bool operator!=(iterator it) const
		{
			return _pn != it._pn;
		}

		bool operator==(iterator it) const
		{
			return _pn == it._pn;
		}

	};

	//反向迭代器1.0		缺点,可复用性低
	//template<class T, class Ref, class Ptr>
	//struct __list_reverse_iterator
	//{
	//	typedef __list_node<T> node;
	//	typedef __list_reverse_iterator<T, Ref, Ptr> reverse_iterator;
	//	node* _pn;

	//	__list_reverse_iterator(node* p)
	//		:_pn(p)
	//	{}

	//	reverse_iterator operator++()
	//	{
	//		_pn = _pn->_prev;
	//		return *this;
	//	}

	//	reverse_iterator operator++(int)
	//	{
	//		iterator tmp(*this);
	//		_pn = _pn->_prev;
	//		return tmp;
	//	}

	//	reverse_iterator operator--()
	//	{
	//		_pn = _pn->_next;
	//		return *this;
	//	}

	//	reverse_iterator operator--(int)
	//	{
	//		iterator tmp(*this);
	//		_pn = _pn->_next;
	//		return tmp;
	//	}

	//	//T&  const T&
	//	Ref operator*() const
	//	{
	//		return _pn->_data;
	//	}

	//	//Ptr T*  const T*
	//	Ptr operator->()
	//	{
	//		return &_pn->_data;
	//	}

	//	bool operator!=(reverse_iterator it) const
	//	{
	//		return _pn != it._pn;
	//	}

	//	bool operator==(reverse_iterator it) const
	//	{
	//		return _pn == it._pn;
	//	}

	//};

	//反向迭代器2.0	对正向迭代器进行分装 => 迭代器适配器
	//只要正向迭代器支持双向访问,就可以适配得出反向迭代器
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		//成员
		Iterator _cur;

		//成员函数
		Reverse_iterator(const Iterator& it)
			:_cur(it)
		{}

		Self operator++()
		{
			--_cur;
			return Reverse_iterator(_cur);	//用_cur正向迭代器构造反向迭代器的匿名对象
		}

		Self operator++(int)
		{
			Iterator tmp = _cur;
			--_cur;
			return Reverse_iterator(tmp);
		}

		Self operator--()
		{
			++_cur;
			return Reverse_iterator(_cur);
		}

		Self operator--(int)
		{
			Iterator tmp = _cur;
			++_cur;
			return Reverse_iterator(tmp);
		}

		Ref operator*() const
		{
			Iterator tmp = _cur;
			--tmp;
			return *tmp;
		}

		Ptr operator->() const 
		{
			Iterator tmp = _cur;
			--tmp;
			return &(*tmp);
		}

		bool operator!=(const Self& it) //const
		{
			return _cur != it._cur;
		}

		bool operator==(const Self& it) //const
		{
			return _cur == it._cur;
		}

	};


	//链表
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//反向迭代器1.0
		//typedef __list_reverse_iterator<T, T&, T*> reverse_iterator;
		//typedef __list_reverse_iterator<T, const T&, const T*> const_reverse_iterator;

		//反向迭代器2.0	对正向迭代器的封装
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;

		//这里为什么出错??? const_reverse_iterator
		//原因:reverse_iterator类型已经被重定义了,现在是reverse_iterator<iterator, T&, T*>,所以使用模板报错
		//修改:将reverse_iterator类名改为Reverse_iterator
		//const对象返回const_iterator,所以需要用const_iterator接受
		//总结:模板类名和tepedef后的类型名最好不同,否则分不清容易弄错
		typedef Reverse_iterator<const_iterator,const T&,const T*> const_reverse_iterator;

		//const对象在初始化的时候没有const属性,初始化之后才有
		list()
		{
			empty_init();
			//_head->_data = T();
		}

		list(size_t n, const T& val = T())
		{
			empty_init();
			while (n--)
			{
				push_back(val);
			}
		}

		list(int n, const T& val = T())
		{
			empty_init();
			while (n--)
			{
				push_back(val);
			}
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(list<T>& lt)
		{
			empty_init();	//别忘了头节点

			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//反向迭代器1.0
		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(_head->_prev);
		//}

		//reverse_iterator rend()
		//{
		//	return reverse_iterator(_head);
		//}

		//反向迭代器2.0
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		iterator begin()
		{
			//匿名对象
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		void push_back(const T& val)
		{
			//node* newnode = new node(val);
			//node* tail = _head->_prev;

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), val);
		}

		void pop_back()
		{
			//assert(!empty());
			//node* tail = _head->_prev;
			//node* prev = tail->_prev;
			//prev->_next = _head;
			//_head->_prev = prev;

			//delete tail;

			//end()返回的是临时对象,临时对象具有const属性,
			//这里能修改,是编译器的优化?还是bug?
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			node* prev = pos._pn->_prev;
			node* cur = pos._pn;
			node* newnode = new node(val);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* prev = pos._pn->_prev;
			node* next = pos._pn->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._pn;

			//return next;
			//之前这里发生隐式类型转化,利用next构造iterator
			return iterator(next);
		}

		//void clear()
		//{
		//	//assert(!empty());
		//	if (!empty())
		//	{
		//		iterator cur(_head->_next);
		//		while (cur != end())
		//		{
		//			//erase(cur++);
		//			cur = erase(cur);
		//		}
		//	}
		//}

		//2.0
		void clear()
		{
			//iterator it(_head->_next);
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		//node* creat_node(const T& val)
		//{
		//	node* newnode = new node(val);
		//	return newnode;
		//}

		T& back()
		{
			assert(!empty());
			node* back = _head->_prev;
			return back->_data;
		}

		T& front()
		{
			assert(!empty());
			node* front = _head->_next;
			return front->_data;
		}

		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		size_t size() const
		{
			node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}

		bool empty() const
		{
			return size() == 0;
		}
	private:
		node* _head;
	};


	template<class Iterator, class T>
	Iterator find(Iterator first, Iterator last, const T& val)
	{
		while (first != last)
		{
			if (*first == val)
			{
				return first;
			}
			++first;
		}
		return last;
	}

}

#define DEBUG
#ifdef DEBUG

//测试代码//////////////////////////////////////////////////////////////////////////
namespace kozen
{
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();

		//当_data是对象时才用到->
		//while (it != lt.end())
		//{
		//	//it->_data; ==> it.operator->()->_data;
		//	//it->->_data; ==> it->_data;
		//	it->_data *= 2;
		//	cout << it->_data << " ";
		//	it++;
		//}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		const list<int> lt2(2,5);

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << "lt3:" << endl;
		const list<int> lt3(lt);
		for (auto& e : lt3)
		{
			//e *= 2;
			cout << e << " ";
		}
		cout << endl;

		cout << "lt3:" << endl;
		auto cit = lt3.begin();
		//while (cit != lt3.end())
		//{
		//	//cit->_data *= 2;
		//	cout << cit->_data << " ";
		//	cit++;
		//}
		cout << endl;

		/*while (!lt.empty())
		{
			cout << lt.back() << " ";
			lt.pop_back();
		}
		cout << endl;*/
	}


	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it = lt.begin();
		it++;
		lt.insert(it, 20);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(1);
		lt.push_front(2);
		lt.push_front(3);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_front();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> ::iterator pos = find(lt.begin(), lt.end(), 3);
		lt.erase(pos);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();
		lt.push_front(1);
		lt.push_front(2);
		lt.push_front(3);
		lt.push_front(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		list<int> lt2(array, array + sizeof(array) / sizeof(array[0]));

		cout << "lt2:" << endl;
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it2 = lt2.begin();
		while (it2 != lt2.end())
		{
			it2 = lt2.erase(it2);
			//lt2.erase(it2);
			//it2++;
		}

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<string> v1 = { "hello1","hello2" ,"hello3","hello4" };
		list<string> lt3(v1.begin(), v1.end());

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	struct AA
	{
		int _a1;
		int _a2;

		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};

	void test_list4()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_a1 << " " << it->_a2 << endl;
			cout << it.operator->()->_a1 << " " << it.operator->()->_a2 << endl;
			++it;
		}
		cout << endl;
	}


	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2(lt);

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(13);

		lt2 = lt;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_list6()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//反向迭代器1.0
		//list<int>::reverse_iterator rit = lt.rbegin();
		//while (rit != lt.rend())
		//{
		//	cout << *rit << " ";
		//	++rit;
		//}
		//cout << endl;

	}
}

#endif



namespace kozen
{
	void test_list7()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		auto it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		const list<int> clt(lt);
		auto cit = clt.begin();
		while (cit != clt.end())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;


		struct AA
		{
			AA(int a = 0)
				:_a(a)
			{}
			int _a = 1;
		};

		list<AA> lt2;
		lt2.push_back(AA(1));
		lt2.push_back(AA(2));
		lt2.push_back(AA(3));
		lt2.push_back(AA(4));

		auto c_it = lt2.begin();
		while (c_it != lt2.end())
		{
			c_it->_a *= 2;
			cout << c_it->_a << " ";
			++c_it;
		}
		cout << endl;


		const list<AA> clt2(lt2);
		auto cit2 = clt2.begin();
		while (cit2 != clt2.end())
		{
			cout << cit2->_a << " ";
			++cit2;
		}
		cout << endl;
	}


	void test_list8()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> ::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

		const list<int> lt2(lt);
		list<int>::const_reverse_iterator c_rit = lt2.rbegin();
		while (c_rit != lt2.rend())
		{
			cout << *c_rit << " ";
			++c_rit;
		}
		cout << endl;

	}
}