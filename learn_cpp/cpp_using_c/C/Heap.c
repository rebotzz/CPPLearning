#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"


//向下调整算法
//小堆
//void AdjustDown(Heap* php, int size,HPDataType root)
//{
//	int parent = root;
//	//找到两个孩子中的较小值
//	int chird = 2 * parent + 1;
//	while (chird < size)
//	{
//		if (chird + 1 <size && php->_a[chird + 1] < php->_a[chird])
//		{
//			chird++;
//		}
//		if (php->_a[chird] < php->_a[parent])
//		{
//			//向下交换
//			swap(&php->_a[parent], &php->_a[chird]);
//			parent = chird;
//			chird = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}

//2.0	向下调整算法	小堆
//void AdjustDown(Heap* php, int n, int root)
//{
//	//左子树和右子数都满足堆顺序,根不满足时
//	//二叉树拆分,最底层数符合 AdjustDown 算法使用条件
//	int parent = root;
//	//找到两个孩子中的较小值
//	int chird = 2 * parent + 1;
//	while (chird < n)
//	{
//		if (chird + 1 < n && php->_a[chird + 1] < php->_a[chird])
//		{
//			chird++;
//		}
//		if (php->_a[chird] < php->_a[parent])
//		{
//			//向下交换
//			swap(&php->_a[parent], &php->_a[chird]);
//			parent = chird;
//			chird = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//3.0向下调整算法	大堆
void AdjustDown(Heap* php, int n, int root)
{
	//左子树和右子数都满足堆顺序,根不满足时
	//二叉树拆分,最底层数符合 AdjustDown 算法使用条件
	int parent = root;
	//找到两个孩子中的较小值
	int chird = 2 * parent + 1;
	while (chird < n)
	{
		if (chird + 1 < n && php->_a[chird + 1] > php->_a[chird])
		{
			chird++;
		}
		if (php->_a[chird] > php->_a[parent])
		{
			//向下交换
			swap(&php->_a[parent], &php->_a[chird]);
			parent = chird;
			chird = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//向上调整算法	小堆
//void AdjustUp(Heap* php, int n, int chird)
//{
//	assert(php);
//	//最后一个孩子位置不对,别的都对
//	//这个孩子向上调整
//	int parent = (chird - 1) / 2;
//	while (chird > 0)
//	{
//		if (php->_a[chird] < php->_a[parent])//小堆,更小者上浮
//		{
//			swap(&php->_a[chird], &php->_a[parent]);
//			chird = parent;
//			parent = (chird - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//向上调整算法	大堆
void AdjustUp(Heap* php, int n, int chird)
{
	assert(php);
	//最后一个孩子位置不对,别的都对
	//这个孩子向上调整
	int parent = (chird - 1) / 2;
	while (chird > 0)
	{
		if (php->_a[chird] > php->_a[parent])//大堆,更大者上浮
		{
			swap(&php->_a[chird], &php->_a[parent]);
			chird = parent;
			parent = (chird - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//交换
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//初始化
void HeapInit(Heap* php, HPDataType* a, int n)
{
	//动态数组创建
	php->_a = (HPDataType*)malloc(n * sizeof(HPDataType));
	if (php->_a == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//拷贝数据到堆
	memcpy(php->_a, a, n * sizeof(HPDataType));
	php->_capacity = php->_size = n;
	//创建堆
	//假设根的左右子树都是小堆
	//从底层开始
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		AdjustDown(php, n, root);
		root--;
	}
}
//插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//考虑是否需要增容
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,php->_capacity * sizeof(HPDataType));
		if (NULL == tmp)
		{
			perror("realloc");
			exit(-1);
		}
		php->_a = tmp;
		tmp = NULL;
	}
	//插入到堆末尾,然后进行一次向上调整算法,规范堆顺序
	//除了新插入的数值,别的元素符合堆顺序,所以只用把这个元素向上调整
	php->_a[php->_size] = x;
	php->_size++;
	AdjustUp(php, php->_size,php->_size - 1);
}
//消除
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	//memmove(php->_a, php->_a + 1, php->_size - 1);
	//php->_size--;
	//错误,不能直接移动,会改变堆的顺序,可能导致兄弟变父亲

	//方法:交换堆顶和最后一个元素,size--,
	//来一次向下调整算法,调整堆顺序
	swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php, php->_size, 0);
}
//读取
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}
//销毁
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
}


//堆排序
void HeapSort(Heap* php)
{
	assert(php);
	//排序,最小值在堆顶,将最值与末尾交换
	//忽略最后一个值,再次排序,新选出的堆顶是第二小的值,
	//重复上面操作,直到排序完成.

	for (int i = 1; i < php->_size; i++)
	{
		swap(&php->_a[0], &php->_a[php->_size - i]);
		AdjustDown(php, php->_size - i, 0);
	}
}



//测试
void print_hello()
{
	printf("hello world\n");
}


