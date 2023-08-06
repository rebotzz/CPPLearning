#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void SelectSort(int* arr, int n)
{
	assert(arr);
	int end = n - 1;
	while (end > 0)
	{
		int maxIndex = 0;//设初始最大原下标位0,即第一个元素
		//遍历数组,找出最大元素的下标
		for (int i = 0; i <= end; i++)
		{
			if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
		}
		swap(&arr[maxIndex], &arr[end--]);
	}
}

void adjustdown(int* arr, int root, int n)
{
	int parents = root;//父节点
	int chird = 2 * parents + 1;//左孩子
	while (parents < n)
	{
		//找左右孩子中最大者
		if (chird + 1 < n && arr[chird + 1] > arr[chird])
		{
			chird++;
		}
		//大的上浮,小的下沉
		if (chird < n && arr[chird] > arr[parents])//注意条件:chird < n
		{
			swap(&arr[chird], &arr[parents]);
			parents = chird;
			chird = 2 * parents + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int n)
{
	assert(arr);
	//建立堆,向下调整算法
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		adjustdown(arr, root--, n);
	}
	//堆顶与末尾交换调整
	int size = n - 1;
	while (size > 0)
	{
		swap(&arr[0], &arr[size]);
		adjustdown(arr, 0, size);
		size--;
	}
}

//冒泡排序
void BubbleSort(int* arr, int n)
{
	assert(arr);
	int i = 0;
	int j = 0;
	//外层,遍历次数,只用遍历n - 1次,当n - 1个数排序完成,最后一个数字也就排序完成 
	for (i = 0; i < n - 1; i++)
	{
		//内层,将相对大的数字向后交换.已经排序好的位置不用比较,小心数组越界
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}








void test()
{
	//int arr[] = { 1,9,8,3,4,6,7,2,0 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 1,2,3,4,5,6,7 };

	int n = sizeof(arr) / sizeof(arr[0]);
	arrayPrintf(arr, n);
	QuickSort(arr, 0, n - 1);
	arrayPrintf(arr, n);

}







int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestQuickSortNonR();
	//TestMergeSort();
	test();


	return 0;
}