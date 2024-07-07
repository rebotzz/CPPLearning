#pragma once
#include <iostream>
#include <assert.h>
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

		// �ƶ�����
		__list_node(T&& val)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(forward<T>(val))	//����ת��
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

#ifdef TEST1
	//���������1.0		ȱ��,�ɸ����Ե�
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

		// �ƶ�����
		list(list<T>&& lt)
		{
			cout << "list(list<T>&& lt) -- �ƶ�����" << endl;
			swap(lt);
		}

		// ֧��{ }��ʼ��
		list(const initializer_list<T>& il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		// ��������
		list(list<T>& lt)
		{
			//empty_init();	//�ƺ�����,tmp������ͷ�ڵ�,��������
			cout << "list(list<T>& lt) -- ��������\n";
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		// �ƶ���ֵ
		list<T>& operator=(list<T>&& lt)
		{
			cout << "list<T>& operator=(list<T>&& lt) -- �ƶ���ֵ\n";
			clear();	// ����Լ�,�����޸�lt
			swap(lt);
			return *this;
		}

		// ��ֵ: Ϊ�˱����������,��Ϊ�Ŵ�д��
		list<T>& operator=(const list<T>& lt)
		{
			cout << "list<T>& operator=(const list<T>& lt) -- ��ֵ\n";
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
			return *this;
		}

		// ֧��{ }��ֵ
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
			insert(end(), val);	
		}

		// move�汾: ��Դת��;	��������:��ֵ/��ֵ
		void push_back(T&& val)
		{
			cout << "push_back(T && val) -- �ƶ�����" << endl;
			insert(end(), forward<T>(val));	// ����ת��,������ֵ/��ֵ����
											// ������·���ܶ�,һֱ��T���͵��ƶ�����/��ֵ
		}

		void pop_back()
		{
			//end()���ص�����ʱ����,��ʱ�������const����,
			//�������޸�,�Ǳ��������Ż�?����bug? 
			// Ӧ���ǿ�����һ��,������ֵ�������Ա�Ϊ��ֵ����. Ȼ��Կ����Ľ����޸�
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		// move�汾: ��Դת��
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

		// move�汾: ��Դת��
		void insert(iterator pos,  T&& val)
		{
			node* prev = pos._pn->_prev;
			node* cur = pos._pn;
			node* newnode = new node(forward<T>(val));	//����ת��,����node���ƶ�����

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
