#define _CRT_SECURE_NO_WARNINGS

//贪吃蛇
//参考代码

#include "game.h"

int main()
{
	int input = 1;
	while (input)
	{
		//菜单
		meum();
		printf("请输入操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");//清空屏幕
			//绘制地图
			drawMap();
			while (1)
			{
				//方向控制
				keyDown();
				if (!snakeStatus())//死亡退出
					break;
				//生成食物
				createFood();
				//控制间隔时间,从而控制蛇的移动速度
				Sleep(snake.speed);
			}

			//结束界面打印
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
			printf("Game Over!\n");
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 1);
			printf("本次游戏得分为：%d\n", sorce);
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 2);
			printf("任意按键返回主菜单.\n");
			Sleep(1000);
			_getch();
			system("cls");
			break;
		case 0:
			printf("退出游戏.\n");
			break;
		default:
			printf("输入错误,请重新输入.\n");
			break;
		}
	}
	

	return 0;
}