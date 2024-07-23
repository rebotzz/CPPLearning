#define _CRT_SECURE_NO_WARNINGS
//数组应用,扫雷游戏

//头文件
#include "game.h"

//游戏
void game()
{
	//棋盘初始化
	InitBoard(mine, ROWS, COLS, '0');//数组名,数组首元素的地址
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置地雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//测试代码用,作弊
	//扫雷
	FindMine(mine, ROW, COL);

}

int main()
{
	//输入值
	int input = 0;
	//雷布置
	char mine[ROWS][COLS] = { 0 };
	//扫雷展示界面
	char show[ROWS][COLS] = { 0 };
	//随机种子
	srand((unsigned int) time(NULL));

	do
	{
		//菜单
		menu();
		//选择
		printf("请输入选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			//游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新输入.\n");
			break;
		}
	} while (input);



		return 0;
}