#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//堆
//小堆,大堆
// 向下调整算法,向上调整算法,递归
// 完全二叉树,这里用数组,利用数值可以支持随机访问的特点
// 堆排序,最值移动到最后,忽略他,继续建堆,选出新的最值,重复;
// TopK问题,建立一个K个数的堆.求最小值就建立大堆;求最大值就建立小堆;
// 堆顶是看门狗,比他还大/小就替换他,进堆;
//

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;


//接口函数
//初始化,拷贝数据到堆,递归向下调整建立大堆/小堆
void HeapInit(Heap* php, HPDataType* a, int n);
//插入,插入到末尾,与堆顶交换,向下调整
void HeapPush(Heap* php, HPDataType x);
//消除堆顶元素
void HeapPop(Heap* php);
//读取堆顶元素
HPDataType HeapTop(Heap* php);
//销毁
void HeapDestroy(Heap* php);

//向下调整算法
void AdjustDown(Heap* php, int n, int root);
//向上调整算法
void AdjustUp(Heap* php, int n, int chird);
//交换
void swap(HPDataType* a, HPDataType* b);
//堆排序
void HeapSort(Heap* php);


//测试
void print_hello();