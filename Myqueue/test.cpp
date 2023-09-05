#define _CRT_SECURE_NO_WARNINGS
#include "myqueue.h"

void test()
{
	MyQueue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	while (!q.IsEmpty())
	{
		cout << q.Front() << " ";
		q.Pop();

	}

	q.Push(6);
	q.Push(7);
	q.Push(8);

	//cout << q.Tail() << endl;
	//cout << q.Front() << " ";
	//q.Pop();
	//cout << q.Front() << " ";
	//q.Pop();

	//q.Push(9);
	//cout << endl << endl;
	//while (!q.IsEmpty())
	//{
	//	cout << q.Front() << " ";
	//	q.Pop();

	//}

	MyQueue q2(q);
	MyQueue q3;
	q3 = q2;


	
}

int main()
{
	test();

	return 0;
}