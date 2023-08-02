#define _CRT_SECURE_NO_WARNINGS
#include "MySort.h"

void TestInsertSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	InsertSort(arr, n);
	arrayPrintf(arr, n);

}

void TestShellSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	ShellSort(arr, n);
	arrayPrintf(arr, n);
}

void TestSelectSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	SelectSort(arr, n);
	arrayPrintf(arr, n);
}

void TestHeapSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	HeapSort(arr, n);
	arrayPrintf(arr, n);
}

void TestBubbleSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	BubbleSort(arr, n);
	arrayPrintf(arr, n);
}

void TestQuickSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 0,5,4,1,2,3 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	QuickSort(arr, 0, n - 1);
	arrayPrintf(arr, n);
}

void TestQuickSortNonR()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 0,5,4,1,2,3 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	QuickSortNonR(arr, 0, n - 1);
	arrayPrintf(arr, n);
}

void TestMergeSort()
{
	//int arr[] = { 9,5,4,8,7,3,4,6,4,2,1,5 };
	//int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	int arr[] = {5,4,3,2,1,0 };// 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,
	//int arr[] = { 0,5,4,1,2,3 };
	//int arr[] = { 2,1 };
	int n = sizeof(arr) / sizeof(int);
	arrayPrintf(arr, n);
	MergeSort(arr, n);
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
	TestMergeSort();



	return 0;
}