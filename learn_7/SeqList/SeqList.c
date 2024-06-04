#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//变量创建
SeqListInfo SLData = { 0 };

//检查空间容量,判断是否开辟空间或者空间不足,开辟空间
void CheckCapacity(SeqListInfo* ps)
{
	while (ps->SLCapacity <= ps->size)
	{
		//判断是否开辟初始空间,或者扩容空间
		int newcapacity = ps->SLCapacity == 0 ? 4 : 2 * ps->SLCapacity;
		//开辟空间
		SLDataType* tmp = (SLDataType*)realloc(ps->arr,newcapacity * sizeof(SeqListInfo));//当地址为NULL,作用同malloc
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);	//退出整个程序
		}
		//开辟成功
		ps->arr = tmp;
		ps->SLCapacity = newcapacity;
		tmp = NULL;
	}
}

//销毁空间
void SeqListDestory(SeqListInfo* ps)
{
	free(ps->arr);
	ps->arr = NULL;
}

// 初始化
void SeqListInit(SeqListInfo* ps)
{
	//初始容量为空
	ps->SLCapacity = ps->size = 0;
	ps->arr = NULL;
}
//后插
void SeqListPushBack(SeqListInfo* ps, SLDataType x)
{
	////检查空间容量,判断是否开辟空间或者空间不足,开辟空间
	//CheckCapacity(ps);

	////若空间足够,正常插入数据
	//ps->arr[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}
//后删
void SeqListPopBack(SeqListInfo* ps)
{
	//避免越界访问
	//1.0
	if (ps->size > 0)
	{
		ps->size--;
	}
	//2.0
	//assert(ps->size >= 0);
}
//前插入
void SeqListPushFront(SeqListInfo* ps, SLDataType x)
{
	//检查空间容量,判断是否开辟空间或者空间不足,开辟空间
	//CheckCapacity(ps);

	//空间足够,正常插入
	//将数据顺序后移,插入到ps->arr[0]
	//int i = 0;
	//for (i = ps->size; i > 0 ; i--)	//注意挪动方向,避免覆盖,从后开始挪动
	//{
	//	ps->arr[i] = ps->arr[i - 1];
	//}
	//ps->arr[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);

}
//前删
void SeqlistPopFront(SeqListInfo* ps)
{
	if (ps->size > 0)	//避免越界
	{
		//将数据顺序向前挪动	从前开始挪动
		int i = 1;
		while (i < ps->size)
		{
			ps->arr[i - 1] = ps->arr[i];
			i++;
		}
		ps->size--;
	}

}
//中间插入
//pos代表下标位置,从 0 开始
void SeqListInsert(SeqListInfo* ps, int pos, SLDataType x)
{
	//检查空间容量,判断是否开辟空间或者空间不足,开辟空间
	CheckCapacity(ps);

	//pos自己和之后的数据后移	从后面开始移动
	// 
	//判断pos合法性
	////1.0
	//if (pos < 0 || pos >ps->size)
	//{
	//	return;
	//}
	//2.0
	assert(pos >= 0 && pos <= ps->size);

	if (pos == ps->size)//后插
	{
		ps->arr[ps->size] = x;
		ps->size++;
	}
	else	//中间插入
	{
		int i = 0;
		for (i = ps->size; i > pos; i--)
		{
			ps->arr[i] = ps->arr[i - 1];
		}
		ps->arr[pos] = x;
		ps->size++;
	}

}
//中间修改
void SeqListReviseMiddle(SeqListInfo* ps, int pos, SLDataType x)
{
	//判断pos合法性
	if (pos < 0)
	{
		pos = 0;
	}
	else if (pos > ps->size)
	{
		pos = ps->size;
	}
	ps->arr[pos] = x;

}
//中间删除
void SeqListErase(SeqListInfo* ps, int pos)
{
	//判断pos合法性
	if (pos <= 0)//前删
	{
		SeqlistPopFront(ps);
	}
	else if (pos >= ps->size)//后删
	{
		SeqListPopBack(ps);
	}
	else
	{
		int i = pos;	//从前开始挪动
		while (i < ps->size - 1)
		{
			ps->arr[i] = ps->arr[i + 1];
			i++;
		}
		ps->size--;
	}

}

// 顺序表查找
int SeqListFind(SeqListInfo* ps, SLDataType x)
{
	int i = 0;
	while (i < ps->size)
	{
		if (x == ps->arr[i])
		{
			return i;	//返回下标位置
		}
		i++;
	}
	
	return -1;
}

//菜单
void menu()
{
	printf("************************************************************\n");
	printf("******************     顺序表             ******************\n");
	printf("******************  1.前插     2.前删     ******************\n");
	printf("******************  3.后插     4.后删     ******************\n");
	printf("******************  5.中间插   6.中间删   ******************\n");
	printf("******************  7.中间改   8.打印     ******************\n");
	printf("******************  9.读取文件 10.查找    ******************\n");
	printf("******************  0.保存退出            ******************\n");
	printf("************************************************************\n");

}

//打印数据
void SeqListPrint(SeqListInfo* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf(PRINTTYPE, ps->arr[i]);
	}
	printf("\n");
}


//读取文件
void GetData(SeqListInfo* ps)
{
	//打开文件	r
	FILE* pf = fopen("SeqListData.bin", "rb");
	if (pf == NULL)
	{
		//创建文件
		pf = fopen("SeqListData.bin", "wb");
		if (pf == NULL)
		{
			perror("fopen SeqListData.bin error");
			exit(-1);
		}
	}
	//判断文件字节大小
	fseek(pf, 0, SEEK_END);
	long Isize = ftell(pf);//所占字节大小
	rewind(pf);

	ps->size = Isize / sizeof(SLDataType);
	CheckCapacity(ps);//扩容

	fread(ps->arr, Isize, 1, pf);

	
	//关闭文件
	fclose(pf);
	pf = NULL;
}
//退出保存文件
void ExitSave(SeqListInfo* ps)
{
	//打开文件 WB
	FILE* pf = fopen("SeqListData.bin", "wb");
	if (pf == NULL)
	{
		perror("fopen save error");
		exit(-1);
	}
	int i = 0;
	while (i < ps->size)
	{
		fwrite(&(ps->arr[i]), sizeof(SLDataType), 1, pf);
		i++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
	//销毁空间
	SeqListDestory(ps);
}