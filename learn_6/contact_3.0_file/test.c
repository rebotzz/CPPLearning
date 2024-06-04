#define _CRT_SECURE_NO_WARNINGS

//通讯录3.0
//1.联系人最大数量动态修改
//2.功能:增加,修改,删除,查找,显示联系人
//3.将数据存储到文件,从文件读取/写入信息
//4.查找功能优化,不完全查找,手机号查找


//功能测试部分
#include "contact.h"
extern int list[];
extern s_con con;

int main()
{
	int input = 0;
	//初始化
	init();
	do
	{
		//菜单
		meun();
		//输入操作
		printf("请输入操作序号:>");
		scanf("%d", &input);
		//进入对应功能
		switch (input)
		{
		case ADD:
			add();
			break;
		case DIV:
			delete();
			break;
		case FIND:
			find();
			//初始化list[]
			int i = 0;
			for (i = 0; i < MAX_LIST; i++)
			{
				list[i] = 0;
			}
			break;
		case CHANGE:
			change();
			break;
		case DISPLAY:
			display();
			break;
		case EXIT:
			exit_save();
			break;
		default:
			printf("错误指令,请重新输入:>\n");
			break;
		}
	} while (input);
	printf("退出程序.\n");
	return 0;
}
