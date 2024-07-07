#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//交换
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//打印数组
void arrayPrintf(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//快速排序 单次排序
//前后指针法
int SortPart1(int* arr, int begin, int end)
{
	//选择基准key,以end为基准
	int key = arr[end];
	int prev = begin - 1;
	int cur = begin;
	//目的:比key大的放左边,比key小的放左边
	// [小于key区间]  key  [大于key区间]
	while (cur <= end)
	{
		//cur遇到比key小的值就停下,prev++,然后交换cur与prev指向的数字
		//cur后面连续跟着大于key的数字,prev后面跟着小于等于key的数字
		//最后一次交换keyIndex指向的key,所以遍历完成后prev指向数字是key
		//就像两个火车头:    小于等于key...(key)prev  大于key...cur 
		while (arr[cur] > key && cur <= end)
		{
			cur++;
		}
		if (arr[cur] <= key && cur <= end)
		{
			swap(&arr[++prev], &arr[cur]);
			cur++;
		}
	}
	return prev;
}

//快速排序
void QuickSort(int* arr, int begin ,int end)
{
	assert(arr);
	if (begin >= end)//结束递归条件
	{
		return;
	}

	int div = SortPart1(arr, begin ,end);
	//[0, div -1] div [div + 1,end]
	//递归,继续分割排序左右区间,结构类似二叉树,前序
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}