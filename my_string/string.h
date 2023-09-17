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

		string(const char* str = "")	//"" Ä¬ÈÏ´øÓÐ/0
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
			assert(pos >= 0 && pos < _size);	//×ó±ÕÓÒ¿ª,_size¶ÔÓ¦/0
			return _str[pos];
		}

		//¸³Öµ,s1 = s2 ,ÒÑ´æÔÚ
		string& operator=(const string& s)
		{
			////·ÀÖ¹s1 = s1,¿Õ¼äÊÍ·Å
			//if (this != &s)
			//{
			//	delete[] _str;
			//	_size = s._size;
			//	_capacity = s._capacity;
			//	_str = new char[_capacity + 1];
			//	strcpy(_str, s._str);
			//}

			//·ÀÖ¹s1 = s1,¿Õ¼äÊÍ·Å
			//·ÀÖ¹newÊ§°Ü
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];	//newÊ§°Ü,Å×Òì³£
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


