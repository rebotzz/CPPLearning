#define _CRT_SECURE_NO_WARNINGS

//功能实现部分
#include "contact.h"

peo_info arr[1000] = { 0 };//个人信息
s_con con = { 0 };		   //通讯录信息
int list[MAX_LIST] = { 0 };	   //查询结果,保存arr[]的序号


//菜单
void meun()
{
	printf("****************************************\n");
	printf("*******        通讯录       ************\n");
	printf("*******    1.增加  2.删除   ************\n");
	printf("*******    3.查找  4.修改   ************\n");
	printf("*******    5.显示  0.退出   ************\n");
	printf("****************************************\n");
}

//初始化
void init()
{
	//创建通讯录,初始化
	con.p = arr;
	con.sz = 0;
}

//增加联系人
void add()
{
	if (con.sz < MAX_PEO)
	{
		printf("增加联系人:>\n");
		printf("请输入名字:");
		scanf("%s", ((con.p)[con.sz]).name);//字符串数组名就是首元素地址,所以可以不用取地址
		printf("请输入性别:");
		scanf("%s", (con.p)[con.sz].sex);
		printf("请输入年龄:");
		scanf("%d", &(con.p[con.sz].age));
		printf("请输入手机号:");
		scanf("%s", con.p[con.sz].tele);
		printf("请输入住址:");
		scanf("%s", con.p[con.sz].addr);
		printf("增加成功!\n");
		con.sz++;
	}
	else
	{
		printf("通讯录已满,增加失败.\n");
	}

}

//删除联系人
void div()
{
	//查找
	printf("输入要删除联系人名字:");
	int* ret = find();
	//删除
	if (ret != NULL)
	{
		printf("请输入想要删除联系人的序号:");
		int n = 0;
		scanf("%d", &n);
		//arr[list[n]]之后的数据挨个向前挪动.
		if(list[n] < con.sz)
		{ 
			//1.0循环
			int i = 0;
			for (i = list[n]; i < con.sz - 1; i++)
			{
				con.p[i] = con.p[i + 1];
			}
			con.sz--;
			printf("删除成功.\n");

			//2.0memmove或者memcpy

			//初始化list[]
			for (i = 0; i < MAX_LIST; i++)
			{
				list[i] = 0;
			}
		}
		
	}

}

//显示联系人
void display()
{
	//排序联系人
	sort_name();
	printf("%-6s\t%-5s\t%-4s\t%-12s\t%-s\n", "名字", "性别","年龄","电话","住址");
	int i = 0;
	for (i = 0; i < con.sz; i++)
	{
		printf("%-6s\t%-5s\t%-4d\t%-12s\t%-s\n", con.p[i].name, con.p[i].sex, con.p[i].age, con.p[i].tele, con.p[i].addr);
	}
}

//查找联系人
int* find()
{
	char name[20] = { 0 };
	scanf("%s", name);
	int i = 0;
	int count = 0;
	for (i = 0; i < con.sz; i++)
	{
		if (strcmp(name, con.p[i].name) == 0)
		{
			if (count == 0)
			{
				printf("已找到:\n");
				printf("%-6s%-6s\t%-5s\t%-4s\t%-12s\t%-s\n", "序号", "名字", "性别", "年龄", "电话", "住址");
			}
			printf("%-6d%-6s\t%-5s\t%-4d\t%-12s\t%-s\n", count, con.p[i].name, con.p[i].sex, con.p[i].age, con.p[i].tele, con.p[i].addr);
			list[count] = i;
			count++;
		}
	}
	if (count == 0)
	{
		printf("查无此人!\n");
		return NULL;
	}
	else
		return list;
}

//修改联系人
void change()
{
	//查找
	printf("请输入要修改联系人名字:");
	//修改
	int* ret = find();
	if (ret != NULL)
	{
		printf("请输入想要修改联系人的序号:");
		int n = 0;
		scanf("%d", &n);
		//arr[list[n]]修改
		printf("修改联系人:>\n");
		printf("请输入名字:");
		scanf("%s", ((con.p)[list[n]]).name);
		printf("请输入性别:");
		scanf("%s", (con.p)[list[n]].sex);
		printf("请输入年龄:");
		scanf("%d", &(con.p[list[n]].age));
		printf("请输入手机号:");
		scanf("%s", con.p[list[n]].tele);
		printf("请输入住址:");
		scanf("%s", con.p[list[n]].addr);
		printf("修改成功.\n");

		//初始化list[]
		int i = 0;
		for (i = 0; i < MAX_LIST; i++)
		{
			list[i] = 0;
		}
	}
}

//按照姓名排序
void sort_name()
{
	int i = 0;
	for (i = 0; i < con.sz -1; i++)
	{
		int j = 0;
		for (j = 0; j < con.sz - 1 - i; j++)
		{
			if (strcmp(con.p[j].name, con.p[j + 1].name) > 0)//升序
			{
				peo_info tmp = con.p[j];
				con.p[j] = con.p[j + 1];
				con.p[j + 1] = tmp;
			}
		}
	}
}