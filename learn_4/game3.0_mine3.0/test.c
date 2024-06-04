#define _CRT_SECURE_NO_WARNINGS
//数组应用,扫雷游戏2.0
//功能优化:
//			1.爆炸式边界展开
//			2.增加标记功能  (功能优化4.0)
//			3.操作步数记录  (为了更具有意义,改为时间记录)
//头文件
#include "game.h"

//游戏
void game()
{
	//存储标记坐标
	int mark[60][2] = { 0 };
	int mark_ = 0;//序号
	//棋盘初始化
	InitBoard(mine, ROWS, COLS, '0');//数组名,数组首元素的地址
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL,0,0,0);
	//布置地雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL,0,0,0);//测试代码用,作弊
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
			start = time(NULL);
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