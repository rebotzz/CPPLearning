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

////归并排序子程序
//void _MergeSort(int* arr,int* tmp, int begin, int end)
//{
//	assert(arr);
//	if (begin >= end)
//	{
//		return;
//	}
//	//begin mid mid+1 end
//	// begin end1 begin1 end
//	//二叉树的前序遍历 ==> 拆分
//	int mid = (begin + end) / 2;
//	int end1 = mid;
//	int begin1 = mid + 1;
//	_MergeSort(arr,tmp, begin, end1);
//	_MergeSort(arr,tmp, begin1, end);
//
//	//arrayPrintf(arr + begin, end - begin + 1);
//
//	// begin end1 begin1 end
//	//归并,排序
//	int tbegin = begin;
//	int first = begin;
//	//两个有序数组中选出较小值归并到tmp数组
//	while (begin <= end1 && begin1 <= end)
//	{
//		if (arr[begin] < arr[begin1])
//		{
//			tmp[tbegin++] = arr[begin++];
//		}
//		else
//		{
//			tmp[tbegin++] = arr[begin1];
//			begin1++;
//		}
//		//printf("%d->", tmp[tbegin -1]);
//	}
//
//	//当其中一组结束,另一组处理
//	while (begin <= end1)
//	{
//		tmp[tbegin++] = arr[begin++];
//	}
//	while (begin1 <= end)
//	{
//		tmp[tbegin++] = arr[begin1];
//		begin1++;
//	}
//
//	//把每次归并后的数据放回原数组
//	int i = first;
//	for (i = first; i <= end; i++)
//	{
//		arr[i] = tmp[i];
//	}
//
//}
//
////归并排序
//void MergeSort(int* arr,int n)
//{
//	//额外空间存储归并后数据
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (NULL == tmp)
//	{
//		perror("malloc error");
//		exit(-1);
//	}
//	//1.拆分 2.归并
//	_MergeSort(arr, tmp, 0, n - 1);
//
//	//将排序好的tmp数组拷贝覆盖arr
//	//memmove(arr, tmp, sizeof(int) * n);
//	//释放tmp
//	free(tmp);
//	tmp = NULL;
//}


//代码优化 1.0
//归并排序子程序
void _MergeSort(int* arr, int* tmp, int begin, int end)
{
	assert(arr);
	if (begin >= end)  //结束递归条件
	{
		return;
	}

	//二叉树的前序遍历 ==> 拆分
	//[begin end] ==>  [begin1 end1] [begin2 end2]
	int begin1 = begin;
	int end1 = (begin + end) / 2;
	int begin2 = end1 + 1;       //小细节:与if (begin >= end)相对应
	int end2 = end;
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	//[begin1 end1] [begin2 end2]
	//归并+排序
	int tmpbegin = begin;
	//两个有序数组中选出较小值归并到tmp数组
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[tmpbegin++] = arr[begin1++];
		}
		else
		{
			tmp[tmpbegin++] = arr[begin2++];
		}
	}

	//当其中一组结束,另一组处理
	while (begin1 <= end1)
	{
		tmp[tmpbegin++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[tmpbegin++] = arr[begin2++];
	}

	//将排序好的tmp数组拷贝覆盖arr
	// 因为递归拆分后的逻辑单元是 ==> 从arr中两个有序的数组中抽取两个数字依次放入tmp排序
	// 排序好有序的数组是arr接下来继续归并到tmp的基础
	//把每次归并后的数据放回原数组 ==> 关键:别忘了!
	int i = begin;
	for (i = begin; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}

//归并排序
void MergeSort(int* arr, int begin, int end)
{
	//临时空间存储归并后数据
	int* tmp = (int*)malloc(sizeof(int) * (end - begin + 1));
	if (NULL == tmp)
	{
		perror("malloc error");
		exit(-1);
	}

	//1.拆分 2.归并
	//begin end
	_MergeSort(arr, tmp, begin, end);

	//释放tmp
	free(tmp);
	tmp = NULL;
}



void test()
{
	//int arr[] = { 1,9,8,3,4,6,7,2,0 };
	int arr[] = { 20,19,18,17,9,8,7,6,5,4,3,2,1,0,16,15,14,13,12,11,10 };
	//int arr[] = { 1,2,3,4,5,6,7 };
	//int arr[] = { 4,3,2,1 };

	int n = sizeof(arr) / sizeof(arr[0]);
	arrayPrintf(arr, n);
	MergeSort(arr, 0, n - 1);
	arrayPrintf(arr, n);

}







//int main()
//{
//	//TestInsertSort();
//	//TestShellSort();
//	//TestSelectSort();
//	//TestHeapSort();
//	//TestBubbleSort();
//	//TestQuickSort();
//	//TestQuickSortNonR();
//	//TestMergeSort();
//	//test();
//
//
//	return 0;
//}