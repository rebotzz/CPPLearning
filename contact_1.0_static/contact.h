#pragma once

//头文件,宏定义,声明

#define MAX_PEO 1000//最大联系人数
#define MAX_LIST 20 //最大重复人名查询结果保存数量


#include <stdio.h>
#include <string.h>
#include <assert.h>


//变量声明	
//全局变量存放在数据段,不在栈上 ==> 但是不行,
//因为"contact.h"被contact.c 和 test.c 各自引用一次,所以相当于重复创建
//解决方法,在 contact.c 中创建全局变量,这里只声明
enum choice //菜单选项
{
	EXIT,//0
	ADD,//1
	DIV,
	FIND,
	CHANGE,
	DISPLAY
};
typedef struct people	//每个人信息.变量声明
{
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char addr[20];
}peo_info;
typedef struct contact		//总联系人信息.变量声明
{
	struct people* p;
	int sz;//序号,总人数
}s_con;


//菜单
void meun();
//初始化
void init();
//增加联系人
void add();
//删除联系人
void div();
//显示联系人
void display();
//查找联系人
int* find();
//修改联系人
void change();
//按照姓名排序
void sort_name();
