#pragma once

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//宏
#define SLDataType int	//所存入数据的类型,便于后期修改
#define PRINTTYPE "%d " //打印类型,便于后期修改
#define SCANFTYPE "%d"  //输入类型

#if 0
#define SLCapacity 1000
#endif
////静态顺序表
//// 最大容量不可修改,不方便
//// 数据类型定义
//typedef struct SeqList
//{
//	int size;
//	SLDataType arr[SLCapacity];
//}SeqListInfo;

//类型定义
//动态顺序表	依据需要开辟空间
typedef struct SeqList
{
	int size;	//当前存储数据个数
	int SLCapacity;	//容量
	SLDataType* arr;	//指向所存储类型数据的指针
}SeqListInfo;
//菜单选项符号
enum meun_choice				//1.前插     2.前删    
{								//3.后插     4.后删    
	EXIT_SAVE,					//5.中间插   6.中间删  
	PUSHFRONT,					//7.中间改   0.保存退出
	POPFRONT,					//8.打印	 9.读取
	PUSHBACK,					//10.查找
	POPBACK,
	PUSHMIDDLE,
	POPMIDDLE,
	REVISEMIDDLE,
	PRINT,
	GETDATA,
	FIND
};

//变量声明
SeqListInfo SLData;

//函数声明 接口函数
// 初始化
void SeqListInit(SeqListInfo* ps);
//后插
void SeqListPushBack(SeqListInfo* ps, SLDataType x);
//后删
void SeqListPopBack(SeqListInfo* ps);
//前插入
void SeqListPushFront(SeqListInfo* ps, SLDataType x);
//前删
void SeqlistPopFront(SeqListInfo* ps);
//中间插入
void SeqListInsert(SeqListInfo* ps,int pos, SLDataType x);
//中间修改	查找,删除,修改配合使用
void SeqListReviseMiddle(SeqListInfo* ps, int pos, SLDataType x);
//中间删除
void SeqListErase(SeqListInfo* ps,int pos);
// 顺序表查找
int SeqListFind(SeqListInfo* ps, SLDataType x);
//菜单
void menu();
//打印数据
void SeqListPrint(SeqListInfo* ps);
//读取文件
void GetData(SeqListInfo* ps);
//退出保存文件
void ExitSave(SeqListInfo* ps);
//销毁空间
void SeqListDestory(SeqListInfo* ps);