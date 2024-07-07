#define _CRT_SECURE_NO_WARNINGS

//顺序表学习
//顺序排放,相邻

//目的,实现数据管理

#include "SeqList.h"

void test1()
{
	//初始化
	SeqListInit(&SLData);
	//后插数据
	SeqListPushBack(&SLData, 1);
	SeqListPushBack(&SLData, 2);
	SeqListPushBack(&SLData, 3);
	SeqListPushBack(&SLData, 4);
	SeqListPushBack(&SLData, 5);
	SeqListPushBack(&SLData, 6);
	SeqListPushBack(&SLData, 7);
	SeqListPushBack(&SLData, 8);
	//打印数据
	SeqListPrint(&SLData);
	//后删
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	//打印数据
	SeqListPrint(&SLData);
	//后删
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	//后插数据
	SeqListPushBack(&SLData, 1);
	SeqListPushBack(&SLData, 2);
	SeqListPushBack(&SLData, 3);
	//打印数据
	SeqListPrint(&SLData);

}

//前插,前删测试
void test2()
{
	//初始化
	SeqListInit(&SLData);
	//前插
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	SeqListPrint(&SLData);
	//前删
	for (i = 0; i < 10; i++)
	{
		SeqlistPopFront(&SLData);
	}
	SeqListPrint(&SLData);
	//前插
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i + 3);
	}
	SeqListPrint(&SLData);
}


//中间插入数据,中间删除测试
void test3()
{
	//初始化
	SeqListInit(&SLData);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		SeqListPushBack(&SLData, i + 1);
	}
	SeqListPrint(&SLData);
	//中间插入
	SeqListInsert(&SLData, 5, 10);
	SeqListInsert(&SLData, -1, 11);
	SeqListInsert(&SLData, 19, 12);
	SeqListPrint(&SLData);

	//中间修改
	SeqListReviseMiddle(&SLData,3,0);
	SeqListPrint(&SLData);

	//中间删除
	SeqListErase(&SLData,3);
	SeqListErase(&SLData, 3);
	SeqListPrint(&SLData);


}

void test_menu()
{

	int input = 1;
	SLDataType x = { 0 };
	int pos = 0;
	do
	{
		//菜单
		menu();
		printf("输入操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT_SAVE:
			ExitSave(&SLData);
			break;
		case PUSHFRONT:
			printf("输入插入数据:");
			scanf(SCANFTYPE, &x);
			SeqListPushFront(&SLData, x);
			break;
		case POPFRONT:
			SeqlistPopFront(&SLData);
			break;
		case PUSHBACK:
			printf("输入插入数据:");
			scanf(SCANFTYPE, &x);
			SeqListPushBack(&SLData, x);
			break;
		case POPBACK:
			SeqListPopBack(&SLData);
			break;
		case PUSHMIDDLE:
			printf("输入插入数据和插入位置:");
			scanf(SCANFTYPE, &x);
			scanf("%d", &pos);
			SeqListInsert(&SLData, pos - 1, x);
			break;
		case POPMIDDLE:
			printf("输入删除位置:");
			scanf("%d", &pos);
			SeqListErase(&SLData, pos - 1);
			break;
		case REVISEMIDDLE:
			printf("输入修改后数据和修改位置:");
			scanf(SCANFTYPE, &x);
			scanf("%d", &pos);
			SeqListReviseMiddle(&SLData, pos - 1, x);
			break;
		case PRINT:
			SeqListPrint(&SLData);
			break;
		case GETDATA:
			GetData(&SLData);
			break;
		case FIND:
			printf("输入查找数据:");
			scanf(SCANFTYPE, &x);
			int ret = SeqListFind(&SLData, x);
			if (ret != -1)
			{
				printf("找到了:"PRINTTYPE"\t数组下标为:%d\n", x, ret);
			}
			else
			{
				printf("查询无果.\n");
			}
			break;
		default:
			printf("输入错误,重新输入.\n");
		}
	} while (input);

}

void test4()
{
	//初始化
	SeqListInit(&SLData);
	//前插
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	i = 9;
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	SeqListPrint(&SLData);

	int pos = SeqListFind(&SLData, 9);
	while (pos != -1)
	{
		SeqListErase(&SLData, pos);
		pos = SeqListFind(&SLData, 9);
	}
	SeqListPrint(&SLData);
	pos = SeqListFind(&SLData, 0);
	while (pos != -1)
	{
		SeqListReviseMiddle(&SLData, pos, 10);
		pos = SeqListFind(&SLData, 0);
	}
	SeqListPrint(&SLData);

}

int main()
{
	//后插,后删测试
	//test1();

	//前插,前删测试
	//test2();

	//中间插入数据,中间删除测试
	//test3();

	//test_menu();

	//查找组合功能测试
	test4();

	return 0;
}