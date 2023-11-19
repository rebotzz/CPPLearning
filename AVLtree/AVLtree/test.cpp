#define _CRT_SECURE_NO_WARNINGS
#include "AVLTree.h"
#include "RBTree.h"
#include <time.h>
void testAVL1()
{
	//int arr[] = { 8,3,10,14,9 };
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : arr)
	{
		t1.Insert(make_pair(e, e));
		//cout << "插入: " << e << " 是否平衡: " << t1.IsBalance() << " / " << endl;
		//t1.InOrder();
	}

	t1.InOrder();
	cout << t1.Find(6) << endl;
	cout << t1.Find(20) << endl;
}

void testAVL2()
{
	srand((unsigned)time(NULL));
	AVLTree<int, int> t;
	int N = 1000000;
	for (int i = 0; i < N; ++i)
	{
		//cout << i << endl;
		int num = rand();		//这种生成随机数的方法受到时间限制,有缺陷
		t.Insert(make_pair(num, num));

		//if (!t.IsBalance())
		//{
		//	cout << "i = " << i << "不平衡: " << num << endl;
		//	t.InOrder();
		//	break;
		//}
	}
	//t.InOrder();
	if (t.IsBalance())
	{
		cout << "平衡" << endl;
	}

}

void testAVL3()
{

	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : arr)
	{
		t1.Insert(make_pair(e, e));
	}

	AVLTree<int, int> t2(t1);
	cout << "t1: " << endl;
	t1.InOrder();
	cout << "t2: " << endl;
	t2.InOrder();

}

void test_RBTree1()
{
	//int arr[] = { 1,2,3,4,5 };
	//int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, int> t;
	for (auto e : arr)
	{
		if (e == 14)
		{
			cout << " ";
		}

		t.Insert(make_pair(e, e));
		t.InOrder();
		t.LevelOrder();
		if (!t.Isbalance())
		{
			cout << "不平衡: " << e << endl;
		}
	}
	cout << t.Isbalance() << endl;
}

void test_RBTree2()
{
	srand((unsigned)time(NULL));
	RBTree<int, int> t;
	int N = 100000;
	for (int i = 0; i < N; ++i)
	{
		//cout << i << endl;
		int num = rand() + i;		
		t.Insert(make_pair(num, num));

		//if (!t.Isbalance())
		//{
		//	cout << "不平衡: " << num << endl;
		//}
	}
	cout << t.Isbalance() << endl;

}

void test_RBTree3()
{

	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, int> t;
	for (auto e : arr)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();

	//RBTree<int, int> t2(t);
	//t2.InOrder();
}

int main()
{
	//testAVL2();
	test_RBTree3();

	return 0;
}