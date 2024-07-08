#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace kozen
{
	//LIFOÕ», last in first out, ÈÝÆ÷ÊÊÅäÆ÷
	//Î²²åÎ²É¾
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_st.push_back(val);
			_size++;
		}

		void pop()
		{
			_st.pop_back();
			_size--;
		}

		const T& top()
		{
			return _st.back();
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return size() == 0;
		}

		void swap(stack<T, Container>& st)
		{
			_st.swap(st._st);
			std::swap(_size, st._size);
		}

	private:
		Container _st;
		size_t _size = 0;
	};

}



namespace kozen
{
	void test_stack1()
	{
		//stack<int, list<int>> st;
		//stack<int,vector<int>> st;
		stack<int> st;


		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		//while (!st.empty())
		//{
		//	cout << st.top() << " ";
		//	st.pop();
		//}
		//cout << endl;

		//stack<int, vector<int>> st2;
		stack<int> st2;
		st2.push(4);
		st2.push(5);
		st2.push(6);

		st2.swap(st);

		cout << "st:" << endl;
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

		cout << "st2:" << endl;
		while (!st2.empty())
		{
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;

	}
}