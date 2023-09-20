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
			////��ֹs1 = s1,�ռ��ͷ�
			//if (this != &s)
			//{
			//	delete[] _str;
			//	_size = s._size;
			//	_capacity = s._capacity;
			//	_str = new char[_capacity + 1];
			//	strcpy(_str, s._str);
			//}

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

			////1.0		��pos=0ʱ
			//int end = _size;	//end������size_t,��Ȼend--Ϊ-1��ʱ���Ϊ2^32-1;����Խ��
			//while ((int)pos <= end)	//��ʽ����ת�� size_t �� int �Ƚ�,Ĭ��ת��Ϊsize_t
			//{
			//	_str[end + 1] = _str[end];
			//	end--;
			//}

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

			////Ų������	1.0
			//int end = _size;
			////while (pos <= end && end != -1)//��ֹend��Ϊ-1,��2^32-1	��������д������,���������
			//while ((int)pos <= end)	
			//{
			//	_str[end + len] = _str[end];
			//	end--;
			//}

			//Ų������	2.0
			int end = _size + 1;
			while (pos < end)
			{
				_str[end - 1 + len] = _str[end - 1];	//��len=1,������һ���ַ�,_str[end]=_str[end-1];
				end--;
			}

			////����	1.0
			//int i = 0;
			//while (str[i] != '\0')
			//{
			//	_str[pos + i] = str[i];
			//	i++;
			//}

			////����	2.0
			strncpy(_str + pos, str, len);

			_size += len;
			return *this;
		}

		////�ο�����
		//string& insert(size_t pos, const char* str)
		//{
		//	assert(pos <= _size);

		//	size_t len = strlen(str);

		//	if (_size + len > _capacity)
		//	{
		//		reserve(_size + len);
		//	}

		//	// Ų������
		//	size_t end = _size + len;
		//	while (end > pos + len - 1)		//�������-1,����ת��,size_t
		//	{
		//		_str[end] = _str[end - len];
		//		--end;
		//	}

		//	/*size_t end = _size;
		//	for (size_t i = 0; i < _size + 1; ++i)
		//	{
		//		_str[end + len] = _str[end];
		//		--end;
		//	}*/

		//	// ��������
		//	strncpy(_str + pos, str, len);
		//	_size += len;

		//	return *this;

		//}


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
				////1.0
				//size_t begin = pos;
				//size_t end = pos + len;
				//while (end <= _size)
				//{
				//	_str[begin] = _str[end];
				//	begin++;
				//	end++;
				//}

				////2.0
				strcpy(_str + pos, _str + pos + len);

				_size -= len;
			}
		}

		size_t find(char ch,size_t pos = 0) const
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

		//1.0
		//void resize(size_t n, char ch = '\0')
		//{
		//	if (n >= _size)
		//	{
		//		if (n > _capacity)
		//		{
		//			reserve(n);
		//		}

		//		while (_size < n)
		//		{
		//			_str[_size++] = ch;
		//		}
		//		//_str[_size] = '\0';
		//	}
		//	//else
		//	//{
		//	//	_size = n;
		//	//	_str[_size] = '\0';
		//	//}

		//	_size = n;
		//	_str[_size] = '\0';
		//}

		//2.0
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else if(n > _size)
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
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;

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
	ostream& operator<<(ostream& out,const string& s)
	{
		//out << s.c_str();		//cout<<string ����'\0'Ҳ���ӡ
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}

	////1.0
	//istream& operator>>(istream& in, string& s)
	//{
	//	//���֮ǰ��
	//	s.clear();
	//	char ch = in.get();
	//	//in >> ch;
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		//in >> ch;		//' '��'\n'����뻺����,��������Ϊ>>����ȡ�ķָ��,���ܱ�����ȡ
	//		ch = in.get();	//.get()���Դӻ�������ȡ' '��'\n'

	//	}
	//	return in;
	//}

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

	void getline(istream& in, string& s)
	{
		//���֮ǰ��
		s.clear();
		char ch = in.get();
		//in >> ch;
		while (ch != '\n')
		{
			s += ch;
			//in >> ch;		//' '��'\n'����뻺����,��������Ϊ>>����ȡ�ķָ��,���ܱ�����ȡ
			ch = in.get();	//.get()���Դӻ�������ȡ' '��'\n'
		}
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

		for (auto e : s2)	//�������滻Ϊ������ s2.begin(); s2.end();
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


	void string_test5()
	{
		string s1 = "1234678";

		s1.insert(0,"ddd");
		cout << s1 << endl;
		s1.insert(9, "kkk");
		cout << s1 << endl;

		s1.insert(0, "");
		cout << s1 << endl;

		cout << s1 << endl;
		cin >> s1;
		cout << s1 << endl;

		getline(cin, s1);
		cout << s1 << endl;
	}

	void string_test6()
	{
		string s1 = "13246578946";
		cout << s1 << endl;	
		s1.push_back('x');
		cout << s1 << endl;
		s1.append("jjj");
		cout << s1 << endl;
		s1.insert(0, "asfjlaj");
		cout << s1 << endl;
		s1.insert(s1.size(), "???");
		cout << s1 << endl;
		s1.erase(10, 3);
		cout << s1 << endl;
		s1.erase(0, 3);
		cout << s1 << endl;
		s1.erase(6);
		cout << s1 << endl;

	}

	void string_test7()
	{
		string s1("hello world,welcome to here.");
		cout << s1 << endl;
		cout << s1.find('c') << endl;
		cout << s1.find('o') << endl;

		cout << s1.find('o',10) << endl;
		cout << s1.find("to") << endl;
		cout << s1.find("el") << endl;
		cout << s1.find("el",5) << endl;
		cout << s1.find("el",14) << endl;

	}
}


