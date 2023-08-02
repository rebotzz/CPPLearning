//#define _CRT_SECURE_NO_WARNINGS
//#include "Sort.h"
//#define DEBUG
////#undef DEBUG
//
////打印数组
//void arrayPrintf(int* arr, int n)
//{
//	assert(arr);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//
//
////直接插入排序
//void SortInsert(int* arr, int n)
//{
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//
//
//	//升序
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + 1] = tmp;
//	}
//
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
////插入排序	希尔排序学习1.0
//void Sort(int* arr, int n)
//{
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//
//	int gap = 3;
//
//	//预排序
//	//for (int i = 0; i < n - gap; i += gap)
//	for (int i = 0; i < n - gap; i++)
//	{
//		int end = i;
//
//		int tmp = arr[end + gap];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + gap] = arr[end];
//				end = end - gap;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + gap] = tmp;
//	}
//
//	//排序
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//#ifdef DEBUG
//				count++;
//#endif // DEBUG
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		arr[end + 1] = tmp;
//	}
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
//
//
//希尔排序
//void ShellSort(int* arr, int n)
//{
//
//#ifdef DEBUG
//	int count = 0;
//#endif // DEBUG
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;	// +1 是为了保证最后一次gap = 1,这一次就是直接插入排序排序
//
//		//预排序
//		//for (int i = 0; i < n - gap; i += gap)
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end = end - gap;
//#ifdef DEBUG
//					count++;
//#endif // DEBUG
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			arr[end + gap] = tmp;
//		}
//#ifdef DEBUG
//		arrayPrintf(arr, n);
//#endif // DEBUG
//
//	}
//
//#ifdef DEBUG
//	printf("%d\n", count);
//#endif // DEBUG
//}
//
//
//
//
//
//
//
//
////三数取中
//int GetMid(int* arr, int begin, int end)
//{
//	int left = arr[begin];
//	int right = arr[end];
//	int mid = arr[(begin + end) / 2];
//
//}
//
//
//
//
//
////快速排序 单次排序 3.0快慢指针法
//int PartSort3(int* arr, int begin, int end)
//{
//	//三数取中
//
//
//	int key = arr[end];
//	int prev = begin - 1;
//	int cur = begin;
//
//	while (cur < end)
//	{
//		//cur找比key小的,找到后就停下来;
//		if (cur < end && arr[cur] < key)
//		{
//			//cur找到后,prev++
//			prev++;
//			//交换prev与cur;
//			swap(&arr[prev], &arr[cur]);
//		}
//		cur++;
//
//
//	}
//
//	prev++;
//	swap(&arr[prev], &arr[end]);
//
//	return prev;
//}
//
//
////交换
//void swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//
////快速排序
//void QuickSort(int* arr, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int div = PartSort3(arr, begin, end);
//
//	QuickSort(arr, begin, div - 1);
//	QuickSort(arr, div + 1, end);
//}