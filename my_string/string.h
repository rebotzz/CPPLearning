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

		string(const char* str = "")	//"" Ĭ�ϴ���/0
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_size(s._size)
			,_capacity(s._capacity)
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


		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < _size);	//����ҿ�,_size��Ӧ/0
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

			//��ֹs1 = s1,�ռ��ͷ�
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

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};



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

	}
}


