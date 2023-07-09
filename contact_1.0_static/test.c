#define _CRT_SECURE_NO_WARNINGS

//通讯录1.0
//1.联系人最大数量是固定不可改的
//2.功能:增加,修改,删除,查找,显示联系人


//功能测试部分
#include "contact.h"
extern int list[];


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
		scanf("%d", &input);
		//进入对应功能
		switch (input)
		{
		case ADD:
			add();
			break;
		case DIV:
			div();
			break;
		case FIND:
			printf("请输入想要查找人的名字:");
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
			break;
		default:
			printf("错误指令,请重新输入;>\n");
			break;
		}
	} while (input);
	printf("退出程序.\n");
	return 0;
}
