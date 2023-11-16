#define _CRT_SECURE_NO_WARNINGS
#include "AVLtree.h"

void testAVL1()
{
	AVLTree<int> t1;
	t1.Insert(8);
	t1.Insert(3);
	t1.Insert(10);
	t1.Insert(14);
	t1.Insert(9);

	t1.InOrder();
}

int main()
{
	testAVL1();

	return 0;
}