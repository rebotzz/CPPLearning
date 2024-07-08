#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


namespace kozen
{
	//�ڵ�
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

	//������
	//������������
	//1.ԭ��ָ�� 2.��ԭ��ָ���װ,Ȼ�����������,ģ��ԭ��ָ�빦��
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

		
		//Ref operator*() const	//const�൱��const __list_iterator* this;
		//��const _pn => node* const _pn;����_pn->_data�ɸĶ�;�о�ûɶ����;����������Ϳ��ԸĶ�,������const��
		//T&  const T&
		Ref operator*() 
		{
			return _pn->_data;
		}

		//������ģ�´洢������ָ����Ϊ,
		//�������Ƕ���ʱ,ʹ��->���ʳ�Ա
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

	//���������1.0		ȱ��,�ɸ����Ե�
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

	//���������2.0	��������������з�װ => ������������
	//ֻҪ���������֧��˫�����,�Ϳ�������ó����������
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		//��Ա
		Iterator _cur;

		//��Ա����
		Reverse_iterator(const Iterator& it)
			:_cur(it)
		{}

		Self operator++()
		{
			--_cur;
			return Reverse_iterator(_cur);	//��_cur������������췴�����������������
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


	//����
	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//���������1.0
		//typedef __list_reverse_iterator<T, T&, T*> reverse_iterator;
		//typedef __list_reverse_iterator<T, const T&, const T*> const_reverse_iterator;

		//���������2.0	������������ķ�װ
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;

		//����Ϊʲô����??? const_reverse_iterator
		//ԭ��:reverse_iterator�����Ѿ����ض�����,������reverse_iterator<iterator, T&, T*>,����ʹ��ģ�屨��
		//�޸�:��reverse_iterator������ΪReverse_iterator
		//const���󷵻�const_iterator,������Ҫ��const_iterator����
		//�ܽ�:ģ��������tepedef�����������ò�ͬ,����ֲ�������Ū��
		typedef Reverse_iterator<const_iterator,const T&,const T*> const_reverse_iterator;

		//const�����ڳ�ʼ����ʱ��û��const����,��ʼ��֮�����
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
			empty_init();	//������ͷ�ڵ�

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

		//���������1.0
		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(_head->_prev);
		//}

		//reverse_iterator rend()
		//{
		//	return reverse_iterator(_head);
		//}

		//���������2.0
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
			//��������
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

			//end()���ص�����ʱ����,��ʱ�������const����,
			//�������޸�,�Ǳ��������Ż�?����bug?
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
			//֮ǰ���﷢����ʽ����ת��,����next����iterator
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

//���Դ���//////////////////////////////////////////////////////////////////////////
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

		//��_data�Ƕ���ʱ���õ�->
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

		//���������1.0
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