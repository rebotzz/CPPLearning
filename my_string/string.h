#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

namespace kozen
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		string(const char* str = "")	//"" 默认带有\0 ==>等价"\0"
			:_size(strlen(str))
		{
			//_capacity = _size;
			_capacity = _size == 0 ? 3 : _size;		//防止_capacity = 0  2倍数扩容问题
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			//assert(_str != nullptr);
			delete[] _str;
			_size = _capacity = 0;
		}


		const char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < _size);	//左闭右开,_size对应/0
			return _str[pos];
		}

		const char& operator[](size_t pos) const	//const string
		{
			assert(pos >= 0 && pos < _size);	
			return _str[pos];
		}

		//赋值,s1 = s2 ,已存在
		string& operator=(const string& s)
		{
			////防止s1 = s1,空间释放
			//if (this != &s)
			//{
			//	delete[] _str;
			//	_size = s._size;
			//	_capacity = s._capacity;
			//	_str = new char[_capacity + 1];
			//	strcpy(_str, s._str);
			//}

			//防止s1 = s1,空间释放导致数据丢失
			//防止new失败
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];	//new失败,抛异常
				strcpy(tmp, s._str);

				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		iterator begin()
		{
			//cout << "iterator begin()" << endl;
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//需要const版本和非const版本
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			//检查,扩容
			if (_size + len > _capacity)
			{
				reserve(_size + len);	//这里不能2倍扩容,_size + len可能大于2*_capacity
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s) const
		{
			return (*this == s) || (*this > s);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator!=(const string& s) const
		{
			return !(s == *this);
		}

		int compare(const string& s) const
		{
			return strcmp(_str, s._str);
		}


		void insert(size_t pos, char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}

			int end = _size;	//end不能是size_t,不然end--为-1的时候变为2^32-1;死循环
			while ((int)pos <= end)	//隐式类型转化 size_t 和 int 比较,默认转化为size_t
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			//挪动数据
			int end = _size;
			//while (pos <= end && end != -1)//防止end变为-1,即2^32-1
			while ((int)pos <= end)	
			{
				_str[end + len] = _str[end];
				end--;
			}

			//拷贝
			int i = 0;
			while (str[i] != '\0')
			{
				_str[pos + i] = str[i];
				i++;
			}
			_size += len;
		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			//len = (len == npos ? _size : len);
			if (pos + len >= _size)
			{
				_str[pos] = '\0';
			}
			else
			{
				size_t begin = pos;
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[begin] = _str[end];
					begin++;
					end++;
				}
			}

			_size = pos;
		}

		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n >= _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				while (_size < n)
				{
					_str[_size++] = ch;
				}
				//_str[_size] = '\0';
			}
			//else
			//{
			//	_size = n;
			//	_str[_size] = '\0';
			//}

			_size = n;
			_str[_size] = '\0';
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;

		//另一种写法,不推荐(语法奇怪)
		// 只支持int
		//static const size_t n = -1;
		// 不支持别的类型
		//static const double dn = 1.1;
		//应用
		//static const size_t N = 10;
		//int arr[N];
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, string& s)
	{
		out << s.c_str();
		return out;
	}

	void string_test1()
	{
		string s1;
		string s2("hello kozen");
		string s3(s2);

		cout << &s1 << "  " << s1.c_str() << endl;
		cout << &s2 << "  " << s2.c_str() << endl;
		cout << &s3 << "  " << s3.c_str() << endl;

		s2[0]++;

		cout << &s2 << "  " << s2.c_str() << endl;
		cout << &s3 << "  " << s3.c_str() << endl;
		cout << endl;

		s1 = s2;
		cout << &s1 << "  " << s1.c_str() << endl;


	}
	void string_test2()
	{
		string s1;
		string s2("hello world");

		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto e : s2)	//本质是替换为迭代器 s2.begin(); s2.end();
		{
			cout << e << " ";
		}
		cout << endl;

		const string s3 = "shfoe";
		string::const_iterator cit = s3.begin();
		while (cit != s3.end())
		{
			//(*cit)++;
			cout << *cit << " ";
			cit++;
		}
		cout << endl;

		s2.push_back('x');
		cout << s2.c_str() << endl;
		s2.append("hahah");
		cout << s2.c_str() << endl;

		s2 += '?';
		cout << s2.c_str() << endl;

		s2 += "dddddd";
		cout << s2.c_str() << endl;
	}

	void string_test3()
	{
		const string s1 = "const string";
		string s2 = "const string";
		string s3 = "hello world";

		cout << (s1 > s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s3 <= s2) << endl;
		cout << s2.compare(s3) << endl;

		s2.insert(4, 'x');
		cout << s2 << endl;
		s2.insert(0, 'x');
		cout << s2 << endl;
		s2.insert(s2.size(), "ddddda");
		cout << s2 << endl;
		s2.insert(0, "ddddda");
		cout << s2 << endl;
		s2.insert(4, "mico");
		cout << s2 << endl;

		s2.erase(4, 4);
		cout << s2 << endl;

		s2.erase(15, 20);
		cout << s2 << endl;

		s2.erase();
		cout << s2 << endl;

		cout << "end" << endl;
	}

	void string_test4()
	{
		string s1 = "hello world";

		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		s1.resize(16,'z');
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		s1.resize(20);
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		s1.resize(8);
		cout << s1 << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		const string s2 = "const hello";
		cout << s2[3] << endl;

	}
}


