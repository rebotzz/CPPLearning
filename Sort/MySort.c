#define _CRT_SECURE_NO_WARNINGS
#include "MySort.h"
#include "stack.h"

//直接插入排序	时间复杂度O(N^2);空间复杂度O(1)
//void InsertSort(int* arr, int n)
//{
//	assert(arr);
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		//似乎不行,虽然可以排序,但这不是插入排序了
//		while (arr[end] > arr[end + 1] && end >= 0)
//		{
//			swap(&arr[end], &arr[end + 1]);
//			end--;
//		}
//	}
//}

//2.0
//直接插入排序	时间复杂度O(N^2);空间复杂度O(1)
void InsertSort(int* arr, int n)
{
	assert(arr);//空指针断言
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int key = arr[end + 1];
		//找到比key小的位置
		while (arr[end] > key && end >= 0)
		{
			//比key大,一次后移,为插入key留出位置
			arr[end + 1] = arr[end];
			end--;
		}
		//将key插入到end下一位
		arr[end + 1] = key;
	}
}

//希尔排序	直接插入排序 + 预排序
//间距为gap的分组排序,多组并排;
//直接插入排序等价于gap = 1的希尔排序;
//1.0
//void ShellSort(int* arr, int n)
//{
//	int gap = n;
//
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;//+1为了保证最后一次gap = 1,最后一次等价于直接插入排序;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			while (arr[end] > arr[end + gap] && end >= 0)
//			{
//				swap(&arr[end], &arr[end + gap]);//这里可以优化,利用交换就像交换排序,不像插入排序
//				end -= gap;
//			}
//		}
//	}
//}

//2.0	时间复杂度O(N^1.3) ~ O(N^2);空间复杂度O(1)
void ShellSort(int* arr, int n)
{
	assert(arr);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1为了保证最后一次gap = 1,最后一次等价于直接插入排序;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int key = arr[end + gap];//保存arr[end + gap],这样arr[end + gap]就可以被覆盖,就像挖坑法
			while (end >= 0)
			{
				if (arr[end] > key)//只要比key大,就依次向后挪动
				{
					arr[end + gap] = arr[end];//向后挪动,覆盖arr[end + gap]
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//此时arr[end]小于等于key,key的值可以放在end的下一位
			arr[end + gap] = key;
		}
	}
}



//选择排序
//直接选择排序	时间复杂度O(N^2)	空间复杂度O(1)
//1.0
//void SelectSort(int* arr, int n)
//{
//	//遍历一遍数组,找到最小值,与数值前端交换
//	for (int i = 0; i < n; i++)
//	{
//		int begin = i;
//		int end = n - 1;
//		int mini = begin;//最小值的下标
//		while (begin <= end)
//		{
//			if (arr[begin] < arr[mini])
//			{
//				mini = begin;
//			}
//			begin++;
//		}
//		//交换最小值到数值前端
//		swap(&arr[i], &arr[mini]);
//	}
//}

//2.0	时间复杂度 O(N^2)	空间复杂度O(1)
void SelectSort(int* arr, int n)
{
	assert(arr);
	//遍历一遍数组,找到最小值,最大值,与数值前端,后端交换
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int left = begin, right = end;//移动left和right,不改变begin,end下标
		int mini = begin, maxi = begin;//最小值的下标,最大值的下标
		//遍历数值,找到最大值和最小值
		while (left < right)
		{
			if (arr[left] < arr[mini])
			{
				mini = left;
			}
			if (arr[left] > arr[maxi])
			{
				maxi = left;
			}
			left++;
		}   
		//交换最小值
		swap(&arr[begin], &arr[mini]);
		if (begin == maxi)//当maxi与begin重叠时,maxi位置被交换到mini位置
		{
			maxi = mini;
		}
		//交换最大值
		swap(&arr[end], &arr[maxi]);

		//两端的下标改变
		begin++;
		end--;
	}
}

//堆排序
//向下调整算法
void AdjustDown(int* arr,int root,int n)
{
	assert(arr);
	//左子树,右子树都是大堆,根节点不是的情况;
	while (root < n)
	{
		//找出左右孩子中的更大者,与根节点交换
		int chird = 2 * root + 1;
		if (chird + 1 < n && arr[chird + 1] > arr[chird])
		{
			chird++;
		}
		//更大者上浮
		if (chird < n && arr[chird] > arr[root])
		{
			swap(&arr[chird], &arr[root]);
			root = chird;
		}
		//没有比根节点更大的,根节点下沉终止
		else
		{
			break;
		}
	}
}

//堆排序	时间复杂度 O(N*logN)	空间复杂度O(1)
void HeapSort(int* arr, int n)
{
	assert(arr);
	//不重新开辟空间,直接再原数值上建堆
	
	//自下而上建堆;升序,建立大堆;
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		//向下调整算法
		AdjustDown(arr, root, n);
		root--;
	}
	//排序:将堆顶最大值与末尾交换,排除最大值所在的末尾,向下调整堆,筛选出次最大,循环
	for (int i = 0; i < n - 1; i++)
	{
		swap(&arr[0], &arr[n - 1 - i]);
		AdjustDown(arr, 0, n - 1 - i);//排除最大值所在的末尾
	}
}




//交换排序
// 
//冒泡排序
void BubbleSort(int* arr, int n)
{
	assert(arr);

	//for循环版本
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i -1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//void BubbleSort(int* arr, int n)
//{
//	//while循环版本
//	int i = 0;
//	while (i < n - 1)
//	{
//		int j = 0;
//		while (j < n - 1 - i)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//			}
//			j++;
//		}
//		i++;
//	}
//}
 


//快速排序
//三数取中
int GetMidNumber(int* arr, int begin, int end)
{
	int left = begin;
	int mid = (begin + end) / 2;
	int right = end;

	if (arr[left] > arr[mid])
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if(arr[right] > arr[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}

	else // mid => left
	{
		if (arr[right] > arr[mid])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//快速排序
//单次循环,挖坑法
int SortPart1(int* arr, int begin, int end)
{
	//三数取中,将相对中间大小的数放在最右边,让key取为基准
	int mid = GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);

	assert(arr);
	//选最右边为key
	int key = arr[end];
	int tmp = end;	//挖坑,初始坑

	while (begin < end)
	{
		//选右边为初始坑,从左边开始找
		//从左边开始,找到大于等于key的值
		while (arr[begin] <= key && begin < end)
		{
			begin++;
		}
		if (arr[begin] > key && begin < tmp)//&& begin < tmp
		{
			arr[tmp] = arr[begin];//填坑
			tmp = begin;		  //新挖的坑
			begin++;
		}

		while (arr[end] >= key && begin < end)
		{
			end--;
		}
		if (arr[end] < key && tmp < end)//&& tmp < end; 最后begin和end同时指向的数小于key,可以交换的情况
		{
			arr[tmp] = arr[end];
			tmp = end;
			end--;
		}
	}

	//key填到最后的坑
	arr[tmp] = key;
	return tmp;
}


//快速排序
//单次循环,前后指针法
int SortPart2(int* arr, int begin, int end)
{
	//三数取中,将相对中间大小的数放在最右边,让key取为基准
	int mid = GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);

	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur <= end)
	{
		//cur指针找比key小,找到比key小,prev++,把小的这个值交换到prev
		//就像两个火车头,cur是比key大的数的火车头;prev是小于等于key数字的火车头
		//这里选右边为key,所以cur和prev从左边开始
		while (arr[cur] > key && cur <= end)//想的是结束的条件,写的是继续的条件
		{
			cur++;
		}
		if (arr[cur] <= key && cur <= end)
		{
			swap(&arr[++prev], &arr[cur]);
			cur++;//交换之后cur需要++
		}
	}

	return prev;
}

//快速排序
//单次循环,左右指针法
int SortPart3(int* arr, int begin, int end)
{
	//基准定在右边
	//左指针找到比key大的时候停下,右指针找比key小的时候停下
	//然后交换左右指针指向数值
	//左指针先走,这样最后指针相遇位置的数值比key大,正好可以与key交换

	//三数取中,避免最坏情况,逆序
	int mid =  GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);
	int key = arr[end];
	int left = begin;
	int right = end - 1;
	// left ... right key

	while (left < right)//left < right;别写错,不是left < end
	{
		//左指针找大
		while (arr[left] <= key && left < right)//等于key的情况不用管,之后区间细分的时候等于的就变最大值,会升序
		{
			left++;
		}
		//右指针找小
		while (arr[right] >= key && left < right)
		{
			right--;
		}
		//交换
		if (arr[left] > key && arr[right] < key)
		{
			swap(&arr[left], &arr[right]);
			//left++;
			//right--;
		}
	}
	//交换key到左右指针相遇处
	swap(&arr[left], &arr[end]);

	return left;
}

//快速排序
//选定一个基准值key,比key小的放在左边,比key大的放在右边
//然后排序左边和右边,就像二叉树
//直到不可再分割
// 1.0	时间复杂度O(N*logN)		空间复杂度O(logN),递归的深度
void QuickSort(int* arr, int begin, int end)
{
	assert(arr);
	//递归结束条件,区间不能再分
	if (begin >= end)
	{
		return;
	}

	//小区间优化,减少递归深度
	//排序[arr + begin ,arr + end]区间的数字
	if (end - begin + 1 < 10)
	{
		//直接插入排序
		InsertSort(arr + begin, end - begin + 1);//注意:这里的排序是从arr + begin开始,不能是arr,arr一直不变
		//arrayPrintf(arr + begin, end - begin + 1);
		//printf("Insert\n");
		return;
	}

	//递归,排序;排序左半边和右半边
	int div = SortPart3(arr, begin, end);
	//arrayPrintf(arr + begin, end - begin + 1);
	//printf("%d\n", div);
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}


////2.0	快速排序,减少子函数版本
//void QuickSort(int* arr, int begin, int end)
//{
//	assert(arr);
//	//递归结束条件,区间不能再分
//	if (begin >= end)
//	{
//		return;
//	}
//
//	//递归,排序;排序左半边和右半边
//	int mid = GetMidNumber(arr, begin, end);
//	swap(&arr[mid], &arr[end]);
//	//选最右边为key
//	int key = arr[end];
//	int tmp = end;	//挖坑,初始坑
//	int left = begin, right = end;
//
//	while (left < right)
//	{
//		//选右边为初始坑,从左边开始找
//		//从左边开始,找到大于等于key的值
//		while (arr[left] <= key && left < right)
//		{
//			left++;
//		}
//		if (arr[left] > key)
//		{
//			arr[tmp] = arr[left];//填坑
//			tmp = left;		  //新挖的坑
//			left++;
//		}
//
//		while (arr[right] >= key && left < right)
//		{
//			right--;
//		}
//		if (arr[right] < key)
//		{
//			arr[tmp] = arr[right];
//			tmp = right;
//			right--;
//		}
//	}
//	arr[tmp] = key;
//
//	int div = tmp;
//	QuickSort(arr, begin, div - 1);
//	QuickSort(arr, div + 1, end);
//}



//3.0 快速排序(非递归) 1.0
//void QuickSortNonR(int* arr, int begin, int end)
//{
//	assert(arr);
//	assert(begin <= end);
//
//	stack s;
//	StackInit(&s);
//
//	//利用栈模拟递归,排序;排序左半边和右半边
//	int div = SortPart1(arr, begin, end);
//
//	//将分化的区间存入栈
//	StackPush(&s, div + 1);
//	StackPush(&s, end);
//	StackPush(&s, begin);
//	StackPush(&s, div - 1);
//	
//	while (!StackEmpty(&s))
//	{
//
//		int end1 = StackTop(&s);
//		StackPop(&s);
//		int begin1 = StackTop(&s);
//		StackPop(&s);
//
//		//如果区间还能分化,继续分化,排序,存入栈;
//		//不能就不存入栈,当栈为空,排序结束
//		if (begin1 < end1)
//		{
//			div = SortPart1(arr, begin1, end1);
//			StackPush(&s, div + 1);
//			StackPush(&s, end1);
//			StackPush(&s, begin1);
//			StackPush(&s, div - 1);
//		}
//	}
//
//	//别忘了free栈
//	StackDestroy(&s);
//}


//3.0 快速排序(非递归)	2.0
void QuickSortNonR(int* arr, int begin, int end)
{
	assert(arr);
	//assert(begin < end);

	stack s;
	StackInit(&s);
	//[begin,end]
	StackPush(&s, end);
	StackPush(&s, begin);
	
	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);

		//利用数据库栈模拟递归,排序;排序左半边和右半边
		int div = SortPart1(arr, left, right);
		//[left , div - 1] div [div + 1,right]
		if (div + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, div + 1);
		}
		if (left < div - 1)
		{
			StackPush(&s, div - 1);
			StackPush(&s, left);
		}
	}

	//别忘了free栈
	StackDestroy(&s);
}




//归并排序,子程序
void _MergeSort(int* arr, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	//区间:[begin,  mid]   [mid + 1 ,end] 
	//	   [begin1,end1]   [begin2,end2]	
	int mid = (begin + end) / 2;
	int begin1 = begin, end1 = mid;//用mid不用mid - 1,是为了避免mid - 1小于begin;
	int begin2 = mid + 1, end2 = end;//mid + 1 <= end
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	int index = begin1;
	int cpyIndex = begin1;
	//两个有序数组中选较小的依次存入tmp
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	//其中一个数组结束,但另一个数组可能还有数据
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	//将tmp中排序后的数据拷贝回原数组
	for (int i = cpyIndex; i <= end2; i++)
	{
		arr[i] = tmp[i];
	}

	//arrayPrintf(arr, 6);
}

//归并排序	外排序(也可以内排序),可以再外存,比如硬盘
void MergeSort(int* arr, int n)
{
	assert(arr);
	//开辟空间,用于临时存储归并的数据
	int* tmp = (int*)malloc(n * sizeof(int));
	//二叉树后序的思想
	_MergeSort(arr, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

















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