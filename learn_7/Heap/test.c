#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void test()
{
	Heap hp;
	//int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int a[] = { 27,15,65,49,25,37,19,18,28,34 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));

	int i = 0;
	while (i < hp._size)
	{
		printf("%d ", hp._a[i++]);
	}
	printf("\n");

	printf("%d\n", HeapTop(&hp));

	HeapPop(&hp);
	i = 0;
	while (i < hp._size)
	{
		printf("%d ", hp._a[i++]);
	}
	printf("\n");

	HeapPush(&hp, 15);
	i = 0;
	while (i < hp._size)
	{
		printf("%d ", hp._a[i++]);
	}
	printf("\n");

	//销毁
	HeapDestroy(&hp);
}

void test2()
{
	Heap hp;
	int a[] = { 27,15,65,49,25,37,19,18,28,34 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));

	for(int i = 0;i<hp._size;i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");


	HeapSort(&hp);

	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	//销毁
	HeapDestroy(&hp);
}

void test3()
{
	Heap hp;
	int a[] = { 27,15,65,49,25,37,19,18,28,34 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));

	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");


	for (int i = 0; i < 5; i++)
	{
		printf("%d ", hp._a[0]);
		HeapPop(&hp);
	}
	printf("\n");

	//销毁
	HeapDestroy(&hp);

}

void test4()
{
	Heap hp;
	int a[] = { 27,15,65,49,25,37,19,18,28,34 };
	HeapInit(&hp, a,3);//找前3个最小的,将前3个建立一个大堆,
	//堆顶的最大值就是看门狗,小于他就顶替.
	//然后进行一次向下排序,弄出新的堆顶,新的看门狗;其中,最小值一定小于等于看门狗,一定能进栈.
	for (int i = 3; i < hp._size; i++)
	{
		if (a[i] < hp._a[0])
		{
			hp._a[0] = a[i];
			AdjustDown(&hp, 3, 0);
		}
	}

	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");

	HeapSort(&hp);

	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
}

int main()
{
	//test();
	test2();//堆排序测试
	//test3();//前K个最值
	//test4();//topK问题

	return 0;
}
