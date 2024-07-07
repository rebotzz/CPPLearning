#pragma once
#include <iostream>
#include <assert.h>
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

		// 移动构造
		__list_node(T&& val)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(forward<T>(val))	//完美转发
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

#ifdef TEST1
	//反向迭代器1.0		缺点,可复用性低
	template<class T, class Ref, class Ptr>
	struct __list_reverse_iterator
	{
		typedef __list_node<T> node;
		typedef __list_reverse_iterator<T, Ref, Ptr> reverse_iterator;
		node* _pn;

		__list_reverse_iterator(node* p)
			:_pn(p)
		{}

		reverse_iterator operator++()
		{
			_pn = _pn->_prev;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			iterator tmp(*this);
			_pn = _pn->_prev;
			return tmp;
		}

		reverse_iterator operator--()
		{
			_pn = _pn->_next;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			iterator tmp(*this);
			_pn = _pn->_next;
			return tmp;
		}

		//T&  const T&
		Ref operator*() const
		{
			return _pn->_data;
		}

		//Ptr T*  const T*
		Ptr operator->()
		{
			return &_pn->_data;
		}

		bool operator!=(reverse_iterator it) const
		{
			return _pn != it._pn;
		}

		bool operator==(reverse_iterator it) const
		{
			return _pn == it._pn;
		}

	};
#endif

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

		// 移动构造
		list(list<T>&& lt)
		{
			cout << "list(list<T>&& lt) -- 移动构造" << endl;
			swap(lt);
		}

		// 支持{ }初始化
		list(const initializer_list<T>& il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		// 拷贝构造
		list(list<T>& lt)
		{
			//empty_init();	//似乎不用,tmp就有了头节点,交换就行
			cout << "list(list<T>& lt) -- 拷贝构造\n";
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		// 移动赋值
		list<T>& operator=(list<T>&& lt)
		{
			cout << "list<T>& operator=(list<T>&& lt) -- 移动赋值\n";
			clear();	// 清空自己,避免修改lt
			swap(lt);
			return *this;
		}

		// 赋值: 为了避免调用歧义,换为古代写法
		list<T>& operator=(const list<T>& lt)
		{
			cout << "list<T>& operator=(const list<T>& lt) -- 赋值\n";
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
			return *this;
		}

		// 支持{ }赋值
		list<T>& operator=(const initializer_list<T>& il)
		{
			list<T> tmp(il);
			swap(tmp);
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
			insert(end(), val);	
		}

		// move版本: 资源转移;	万能引用:右值/左值
		void push_back(T&& val)
		{
			cout << "push_back(T && val) -- 移动语义" << endl;
			insert(end(), forward<T>(val));	// 完美转发,保留右值/左值属性
											// 这条链路不能断,一直到T类型的移动构造/赋值
		}

		void pop_back()
		{
			//end()返回的是临时对象,临时对象具有const属性,
			//这里能修改,是编译器的优化?还是bug? 
			// 应该是拷贝了一份,就像右值引用属性变为左值引用. 然后对拷贝的进行修改
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		// move版本: 资源转移
		void push_front(T&& val)
		{
			insert(begin(), forward<T>(val));
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

		// move版本: 资源转移
		void insert(iterator pos,  T&& val)
		{
			node* prev = pos._pn->_prev;
			node* cur = pos._pn;
			node* newnode = new node(forward<T>(val));	//完美转发,调用node的移动构造

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
