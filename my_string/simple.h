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

		string(const char* str = "")	//"" Ĭ�ϴ���\0 ==>�ȼ�"\0"
			:_size(strlen(str))
		{
			//_capacity = _size;
			_capacity = _size == 0 ? 3 : _size;		//��ֹ_capacity = 0  2������������
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
			assert(pos >= 0 && pos < _size);	//����ҿ�,_size��Ӧ/0
			return _str[pos];
		}

		const char& operator[](size_t pos) const	//const string
		{
			assert(pos >= 0 && pos < _size);
			return _str[pos];
		}

		//��ֵ,s1 = s2 ,�Ѵ���
		string& operator=(const string& s)
		{
			//��ֹs1 = s1,�ռ��ͷŵ������ݶ�ʧ
			//��ֹnewʧ��
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];	//newʧ��,���쳣
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

		//��Ҫconst�汾�ͷ�const�汾
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
			//if (_size + 1 > _capacity)
			//{
			//	reserve(2 * _capacity);
			//}

			//_str[_size++] = ch;
			//_str[_size] = '\0';

			insert(_size, ch);
		}

		void append(const char* str)
		{
			//size_t len = strlen(str);
			////���,����
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);	//���ﲻ��2������,_size + len���ܴ���2*_capacity
			//}

			//strcpy(_str + _size, str);
			//_size += len;

			insert(_size, str);
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


		string& insert(size_t pos, char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}

			//2.0		��pos=0ʱ
			int end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			//Ų������	2.0
			int end = _size + 1;
			while (pos < end)
			{
				_str[end - 1 + len] = _str[end - 1];	//��len=1,������һ���ַ�,_str[end]=_str[end-1];
				end--;
			}

			////����	2.0
			strncpy(_str + pos, str, len);

			_size += len;
			return *this;
		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos <= _size);

			//len = (len == npos ? _size : len);
			if (len == npos || pos + len >= _size)	//��ֹ����nposʱ���
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//2.0
				strcpy(_str + pos, _str + pos + len);

				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (int i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);

			char* p = strstr(_str + pos, str);
			if (nullptr == p)
			{
				return npos;
			}
			return p - _str;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)	//����������
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//2.0
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				while (_size < n)
				{
					_str[_size++] = ch;
				}
				_str[_size] = '\0';
			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
	public:
		const static size_t npos;
	private:
		char* _str;
		size_t _size;
		size_t _capacity;


		//��һ��д��,���Ƽ�(�﷨���)
		// ֻ֧��int
		//static const size_t n = -1;
		// ��֧�ֱ������
		//static const double dn = 1.1;
		//Ӧ��
		//static const size_t N = 10;
		//int arr[N];
	};
	const size_t string::npos = -1;

	//�����������ȡ��һ��������Ԫ����,������ýӿ�ͬ�����Լ�ӷ���˽�г�Ա
	ostream& operator<<(ostream& out, const string& s)
	{
		//out << s.c_str();		//cout<<string ����'\0'Ҳ���ӡ
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}

	//2.0	�ռ任ʱ��
	istream& operator>>(istream& in, string& s)
	{
		//���֮ǰ��
		s.clear();
		char ch = in.get();
		char buff[16];	//����ÿ��+=����
		int i = 0;

		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 15)	//0,1,2...,14,15 ==> 16
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();	//.get()���Դӻ�������ȡ' '��'\n'
		}

		//ʣ���
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

}


