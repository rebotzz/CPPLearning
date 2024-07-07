#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

namespace kozen
{
	//FIFO∂”¡–, first in first out, »›∆˜  ≈‰∆˜
	//Œ≤≤ÂÕ∑…æ
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_qu.push_back(val);
			_size++;
		}

		void pop()
		{
			_qu.pop_front();
			_size--;
		}

		const T& front()
		{
			return _qu.front();
		}

		const T& back()
		{
			return _qu.back();
		}

		size_t size() const 
		{
			return _size;
		}

		bool empty() const 
		{
			return _size == 0;
		}

		void swap(queue<T, Container>& q)
		{
			_qu.swap(q._qu);
			std::swap(_size, q._size);
		}

	private:
		Container _qu;
		size_t _size = 0;
	};
}


namespace kozen
{
	void test_queue1()
	{
		//queue<int, list<int>> qu;
		queue<int> qu;


		qu.push(1);
		qu.push(2);
		qu.push(3);
		qu.push(4);
		qu.push(5);

		while (!qu.empty())
		{
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;

		qu.push(3);
		qu.push(4);
		cout << qu.front() << " " << qu.back() << endl;
		qu.pop();
		qu.push(5);

		while (!qu.empty())
		{
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;
	}

	void test_queue2()
	{
		//queue<int, list<int>> qu;
		queue<int> qu;

		qu.push(1);
		qu.push(2);
		qu.push(3);
		qu.push(4);
		qu.push(5);

		queue<int> qu2;

		qu2.push(7);
		qu2.push(8);
		qu2.push(9);

		qu.swap(qu2);

		cout << "qu:" << endl;
		while (!qu.empty())
		{
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;

		cout << "qu2:" << endl;
		while (!qu2.empty())
		{
			cout << qu2.front() << " ";
			qu2.pop();
		}
		cout << endl;

	}


	void test_queue3()
	{
		//queue<int, list<int>> qu;
		queue<int,deque<int>> qu;

		qu.push(1);
		qu.push(2);
		qu.push(3);
		qu.push(4);
		qu.push(5);
		cout << "queue:" << endl;
		while (!qu.empty())
		{
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;
	}
}