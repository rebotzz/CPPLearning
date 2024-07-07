#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//打印数组
void arrayPrintf(int* arr, int n);
//交换
void swap(int* p1, int* p2);

//希尔排序
void SelectSort(int* arr, int n);

//堆排序
void HeapSort(int* arr, int n);

//快速排序
void QuickSort(int* arr, int begin, int end);

//归并排序
void MergeSort(int* arr, int begin, int end);