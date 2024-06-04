#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//头文件在展开的地方编译,在.h不编译;
//eg:"vector.h",所以在自定义头文件展开前,需要using namespace std(如果使用了std);包含别的头文件
//

namespace kozen
{
	////反向迭代器	对正向迭代器进行分装 => 迭代器适配器: vector和list用同一个就行
	//template<class Iterator, class Ref, class Ptr>
	//struct Reverse_iterator		


	template<class T>
	class vector
	{
	public:
		//这里的迭代器是原生指针,不用重载++,--,*; 原生指针 ==> 天然迭代器
		typedef T* iterator;
		typedef const T* const_iterator;
		//typedef const iterator const_iterator;	不能这样
		//const iterator ==> iterator不能修改,即T* const

		//反向迭代器
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;


		//构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		//用T的默认构造的匿名对象初始化val,即初始化每一个成员
		//const T&引用之后,匿名对象的生命周期延长至const引用作用域结束
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

		//避免定位到vector(InputIterator first, InputIterator last)构造
		vector(int n, const T& val = T())
		{
			reserve(n);
			_finish += n;
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
		}

		// 迭代器区间构造
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

		// 支持{ }初始化
		vector(const initializer_list<T>& il)
		{
			reserve(il.size());	// 开辟空间
			_finish = _start;
			for (auto& e : il)
			{
				//push_back(e);	//1.0
				*_finish++ = e;	//2.0
			}
		}

		// 移动构造
		vector(vector<T>&& v) 
		{
			cout << "vector(vector<T>&& v) -- 移动构造" << endl;
			swap(v);
		}
			
		// 移动赋值
		vector<T>& operator=(vector<T>&& v)
		{
			cout << "vector<T>& operator=(vector<T>&& v) -- 移动赋值" << endl;
			swap(v);
			return *this;
		}

		//拷贝构造 2.0
		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());

			swap(tmp);
		}

		//赋值重载 1.0 为了避免调用歧义,换为古代写法
		vector<T>& operator=(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
			return *this;
		}

		////赋值重载 2.0 与移动赋值有调用歧义
		//vector<T>& operator=(const vector<T> v)
		//{
		//	swap(v);
		//	return *this;
		//}

		// 支持{ }赋值
		vector<T>& operator=(const initializer_list<T>& il)
		{
			vector<T> tmp(il);
			swap(tmp);
			return *this;
		}

		//析构
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
				//开辟新空间
				T* tmp = new T[n];
				//拷贝
				for (size_t i = 0; i < size(); ++i)
				{
					tmp[i] = _start[i];
				}
				//释放旧空间,nullptr无影响 
				size_t sz = size();
				delete[] _start;
				_start = tmp;
				//注意:size() = _finish - _start;	inline
				//_start + size() = _start + _finish - _start = _finish;
				//注意求sz先后顺序
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
			//扩容
			if (size() + 1 > capacity())
			{
				//迭代器失效问题
				size_t sz = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + sz;
			}
			iterator end = _finish;
			//挪动数据
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
			//挪动数据
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
			// 伪删除,可以覆盖,这调用析构彻底吗? 应该彻底的,delete[] _start;
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