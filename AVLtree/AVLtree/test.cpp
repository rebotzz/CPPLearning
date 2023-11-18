#define _CRT_SECURE_NO_WARNINGS
#include "AVLTree.h"
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
		cout << "����: " << e << " �Ƿ�ƽ��: " << t1.IsBalance() << " / " << endl;
		t1.InOrder();
	}

	t1.InOrder();
}

void testAVL2()
{
	srand((unsigned)time(NULL));
	AVLTree<int, int> t;
	int N = 1000000;
	for (int i = 0; i < N; ++i)
	{
		//cout << i << endl;
		int num = rand();		//��������������ķ����ܵ�ʱ������,��ȱ��
		t.Insert(make_pair(num, num));

		//if (!t.IsBalance())
		//{
		//	cout << "i = " << i << "��ƽ��: " << num << endl;
		//	t.InOrder();
		//	break;
		//}
	}
	//t.InOrder();
	if (t.IsBalance())
	{
		cout << "ƽ��" << endl;
	}

}

int main()
{
	testAVL2();

	return 0;
}