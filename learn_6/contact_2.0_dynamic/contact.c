#define _CRT_SECURE_NO_WARNINGS

//功能实现部分
#include "contact.h"

s_con con = { 0 };			   //通讯录信息,static修饰,放在数据段,不会自动销毁
int list[MAX_LIST] = { 0 };	   //查询结果,保存arr[]的序号
int max_sz = 0;


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
	peo_info* arr = (peo_info*)malloc(MAX_PEO*sizeof(peo_info));//个人信息,在堆区上开辟,不会自动销毁,arr在栈上,自动销毁
	if (arr == NULL)
	{
		perror("init");
		return;
	}

	max_sz = MAX_PEO;					   //当前最大容量
	con.p = arr;
	con.sz = 0;
}

//增加联系人
void add()
{
	if (con.sz < max_sz)
	{
		if (con.sz == max_sz - 1)
		{
			//增加开辟内存
			void* tmp = realloc(con.p, (max_sz + INC_SZ) * sizeof(peo_info));
			if (tmp != NULL)
			{
				con.p = (peo_info*)tmp;
				max_sz += INC_SZ;
				printf("扩容成功.\n");
			}
		}
		printf("增加联系人:\n");
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
		printf("增加失败.\n");
	}

}

//删除联系人
void delete()
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
		if (list[n] < con.sz)
		{
			//2.0memmove或者memcpy
			memmove(con.p + list[n], con.p + list[n] + 1, (con.sz - list[n] - 1) * sizeof(peo_info));
			con.sz--;
			printf("删除成功.\n");

			//减小开辟空间
			if (con.sz < max_sz - 2)
			{
				void* tmp = realloc(con.p, (max_sz - 2) * sizeof(peo_info));
				if (tmp != NULL)
				{
					con.p = (peo_info*)tmp;
					max_sz = max_sz - 2;
					printf("减小空间成功.\n");
				}
			}


			//初始化list[]
			int i = 0;
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
	printf("%-6s%-6s\t%-5s\t%-4s\t%-12s\t%-s\n", "序号", "名字", "性别", "年龄", "电话", "住址");
	int i = 0;
	for (i = 0; i < con.sz; i++)
	{
		printf("%-6d%-6s\t%-5s\t%-4d\t%-12s\t%-s\n", i, con.p[i].name, con.p[i].sex, con.p[i].age, con.p[i].tele, con.p[i].addr);
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
	for (i = 0; i < con.sz - 1; i++)
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