#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//ͷ�ļ���չ���ĵط�����,��.h������;
//eg:"vector.h",�������Զ���ͷ�ļ�չ��ǰ,��Ҫusing namespace std(���ʹ����std);�������ͷ�ļ�
//

namespace kozen
{
	////���������	��������������з�װ => ������������: vector��list��ͬһ������
	//template<class Iterator, class Ref, class Ptr>
	//struct Reverse_iterator		


	template<class T>
	class vector
	{
	public:
		//����ĵ�������ԭ��ָ��,��������++,--,*; ԭ��ָ�� ==> ��Ȼ������
		typedef T* iterator;
		typedef const T* const_iterator;
		//typedef const iterator const_iterator;	��������
		//const iterator ==> iterator�����޸�,��T* const

		//���������
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;


		//����
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		//��T��Ĭ�Ϲ�������������ʼ��val,����ʼ��ÿһ����Ա
		//const T&����֮��,������������������ӳ���const�������������
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
		}

		//���ⶨλ��vector(InputIterator first, InputIterator last)����
		vector(int n, const T& val = T())
		{
			reserve(n);
			_finish += n;
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
		}

		// ���������乹��
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)		//[first,last)
		{
			reserve(last - first);
			_finish = _start;
			InputIterator it = first;
			while (it != last)
			{
				*_finish++ = *it++;
				//++_finish;
				//++it;
			}
		}

		// ֧��{ }��ʼ��
		vector(const initializer_list<T>& il)
		{
			reserve(il.size());	// ���ٿռ�
			_finish = _start;
			for (auto& e : il)
			{
				//push_back(e);	//1.0
				*_finish++ = e;	//2.0
			}
		}

		// �ƶ�����
		vector(vector<T>&& v) 
		{
			cout << "vector(vector<T>&& v) -- �ƶ�����" << endl;
			swap(v);
		}
			
		// �ƶ���ֵ
		vector<T>& operator=(vector<T>&& v)
		{
			cout << "vector<T>& operator=(vector<T>&& v) -- �ƶ���ֵ" << endl;
			swap(v);
			return *this;
		}

		//�������� 2.0
		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());

			swap(tmp);
		}

		//��ֵ���� 1.0 Ϊ�˱����������,��Ϊ�Ŵ�д��
		vector<T>& operator=(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
			return *this;
		}

		////��ֵ���� 2.0 ���ƶ���ֵ�е�������
		//vector<T>& operator=(const vector<T> v)
		//{
		//	swap(v);
		//	return *this;
		//}

		// ֧��{ }��ֵ
		vector<T>& operator=(const initializer_list<T>& il)
		{
			vector<T> tmp(il);
			swap(tmp);
			return *this;
		}

		//����
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
			cout << "~vector()" << endl;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

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

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		//change capacity
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//�����¿ռ�
				T* tmp = new T[n];
				//����
				for (size_t i = 0; i < size(); ++i)
				{
					tmp[i] = _start[i];
				}
				//�ͷžɿռ�,nullptr��Ӱ�� 
				size_t sz = size();
				delete[] _start;
				_start = tmp;
				//ע��:size() = _finish - _start;	inline
				//_start + size() = _start + _finish - _start = _finish;
				//ע����sz�Ⱥ�˳��
				_finish = tmp + sz;
				_end_of_storage = tmp + n;

				cout << "void reserve(size_t n)" << endl;
			}
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			//_finish != _end_of_storage
			*_finish = val;
			_finish++;
		}

		void pop_back()
		{
			assert(!empty());
			_finish--;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//����
			if (size() + 1 > capacity())
			{
				//������ʧЧ����
				size_t sz = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + sz;
			}
			iterator end = _finish;
			//Ų������
			while (end != pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = val;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator end = pos;
			//Ų������
			while (end != _finish)
			{
				*end = *(end + 1);
				end++;
			}
			_finish--;
			return pos;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		void clear()
		{
			// αɾ��,���Ը���,���������������? Ӧ�ó��׵�,delete[] _start;
			//_finish = _start;	

			vector<T>().swap(*this);
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty() const
		{
			return size() == 0;
		}

	private:
		T* _start = nullptr;
		T* _finish = nullptr;
		T* _end_of_storage = nullptr;
	};
}