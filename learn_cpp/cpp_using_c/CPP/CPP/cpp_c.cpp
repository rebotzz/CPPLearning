#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//由于函数命名规则不同,所以cpp调用c需要extern "C"
extern "C"
{
#include"../../Heap.h"
}

int main()
{
	print_hello();

	int a[] = { 5,8,6,1,5,31,8,43,1,8,43,1,4,51 };
	int size = 0;
	for (auto e : a)
	{
		cout << e << " ";
		size++;
	}
	cout << endl;

	//堆排序
	Heap hp;
	HeapInit(&hp, a, size);
	HeapSort(&hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
	HeapDestroy(&hp);


	return 0;
}