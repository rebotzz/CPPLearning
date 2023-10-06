#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

//头文件在展开的地方编译,在.h不编译;
//eg:"vector.h",所以在自定义头文件展开前,需要using namespace std(如果使用了std);包含别的头文件
//

namespace kozen
{
	template<class T>
	class vector
	{
	public:
		//这里的迭代器是原生指针,不用重载++,--,*; 原生指针 ==> 天然迭代器
		typedef T* iterator;
		typedef const T* const_iterator;
		//typedef const iterator const_iterator;	不能这样
		//const iterator ==> iterator不能修改,即T* const


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
			for (size_t i = 0; i < n; ++i)
			{
				_start[i] = val;
			}
		}

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

		//拷贝构造
		//vector(const vector<T>& v)
		//{
		//	//reserve(v.capacity());
		//	_start = new T[v.capacity()];
		//	for (size_t i = 0; i < v.size(); ++i)
		//	{
		//		_start[i] = v._start[i];
		//	}
		//	_finish = _start + v.size();
		//	_end_of_storage = _start + v.capacity();
		//	cout << "vector(const vector<T>& v)" << endl;
		//}

		//拷贝构造 2.0
		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());

			swap(tmp);
		}

		////赋值重载
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		delete[] _start;
		//		reserve(v.capacity());
		//		for (size_t i = 0; i < v.size(); ++i)
		//		{
		//			_start[i] = v[i];
		//		}
		//		_finish = _start + v.size();
		//	}
		//}

		//赋值重载 2.0
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		//析构
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
			cout << "~vector()" << endl;
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

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
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

		void clear()
		{
			_finish = _start;
			//方法2
			//vector<T>().swap(*this);
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


	//template<class T, class Iterator>
	//Iterator find( Iterator first,  Iterator last, const T& val)	//[first,last)
	//{
	//	while (first != last && *first != val)
	//	{
	//		//if (*first == val)
	//		//{
	//		//	return first;
	//		//}
	//		first++;
	//	}
	//	return first;
	//}

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (int i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
			cout << v1[i] << " ";
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(v1);
		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(3);
		v3 = v2;

		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << "v3: " << endl;
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_vector2()
	{
		vector<string> v1;
		v1.push_back("hello1");
		v1.push_back("hello2");
		v1.push_back("hello3");
		v1.push_back("hello4");
		v1.push_back("hello5");

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<string> v2(v1.begin() + 1, v1.end() - 1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		int a[] = { 5,7,6,4 };
		vector<int> v3(a, a + sizeof(a) / sizeof(a[0]));
		vector<int>::iterator it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		v1.insert(v1.begin(), 10);
		v1.insert(v1.end(), 20);
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		v1.insert(pos, 30);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		pos = find(v1.begin(), v1.end(), 3);
		v1.erase(pos);
		v1.erase(v1.begin());
		v1.erase(v1.end() - 1);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		v1.insert(v1.begin(), 30);
		v1.push_back(30);
		v1.push_back(30);
		v1.push_back(30);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		pos = find(v1.begin(), v1.end(), 30);
		while (pos != v1.end())
		{
			pos = v1.erase(pos);
			pos = find(pos, v1.end(), 30);
		}

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		//这里迭代器是原生指针,没有检查机制
		//不对,这是我自己实现的迭代器,不是vs库里的,所以不同
		it = v1.end();
		cout << typeid(it).name() << ": " << it << endl;
		cout << v1.end() << endl;

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void test_vector4()
	{
		//库里的
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		v1.insert(v1.begin(), 10);
		v1.insert(v1.end(), 20);
		std::vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		v1.insert(pos, 30);

		std::vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;


		pos = find(v1.begin(), v1.end(), 3);
		v1.erase(pos);
		v1.erase(v1.begin());
		v1.erase(v1.end() - 1);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		v1.insert(v1.begin(), 30);
		v1.push_back(30);
		v1.push_back(30);
		v1.push_back(30);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		pos = find(v1.begin(), v1.end(), 30);
		while (pos != v1.end())
		{
			pos = v1.erase(pos);
			pos = find(pos, v1.end(), 30);
		}

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		//vs2013,2019这里的迭代器是对原生指针的封装,有迭代器失效检查
		//it = v1.begin();
		//v1.insert(it, 0);
		//(*it)++;
		//it = v1.end() - 1;
		//v1.erase(it);
		//(*it) = 21;

		it = v1.end();
		cout << typeid(it).name()<< endl;


		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		v1.pop_back();
		v1.pop_back();
		cout << "v1: " << endl;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		string s1("hello");
		vector<int> v2(s1.begin(),s1.end());
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		//排序
		sort(v2.begin(), v2.end());
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;
		
		//仿函数
		//greater<int> g;
		//sort(v2.begin(), v2.end(), g);
		sort(v2.begin(), v2.end(),greater<int>());
		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		v1.swap(v2);
		cout << "v1: " << endl;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		v2.clear();
		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		vector<int>().swap(v2);
		v2.push_back(20);

		cout << "v2: " << endl;
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(20);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(50);


		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				it = v1.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

	}





}