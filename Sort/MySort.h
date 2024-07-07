#pragma once
#include <stdio.h>
#include <assert.h>

//打印数组
void arrayPrintf(int* arr, int n);
//交换
void swap(int* p1, int* p2);

//自己写
// 
//插入排序	内排序(内存内部)
//直接插入排序
void InsertSort(int* arr, int n);
//希尔排序
void ShellSort(int* arr, int n);


//选择排序	内排序
//直接选择排序
void SelectSort(int* arr, int n);
//堆排序
void HeapSort(int* arr, int n);

//交换排序	内排序
//冒泡排序
void BubbleSort(int* arr, int n);
//快速排序
void QuickSort(int* arr, int begin, int end);
//快速排序(非递归)	
void QuickSortNonR(int* arr, int begin, int end);

//归并排序	外排序(也可以内排序),可以再外存,比如硬盘
void MergeSort(int* arr, int n);
