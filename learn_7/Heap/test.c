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

	//����
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

	//����
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

	//����
	HeapDestroy(&hp);

}

void test4()
{
	Heap hp;
	int a[] = { 27,15,65,49,25,37,19,18,28,34 };
	HeapInit(&hp, a,3);//��ǰ3����С��,��ǰ3������һ�����,
	//�Ѷ������ֵ���ǿ��Ź�,С�����Ͷ���.
	//Ȼ�����һ����������,Ū���µĶѶ�,�µĿ��Ź�;����,��Сֵһ��С�ڵ��ڿ��Ź�,һ���ܽ�ջ.
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
	test2();//���������
	//test3();//ǰK����ֵ
	//test4();//topK����

	return 0;
}
