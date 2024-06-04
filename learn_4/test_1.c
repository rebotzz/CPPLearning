#define _CRT_SECURE_NO_WARNINGS

//头文件
#include "game.h"

//三子棋

void meum()
{
	printf("*******************************\n");
	printf("**********   三子棋   *********\n");
	printf("**********   1.play   *********\n");
	printf("**********   0.exit   *********\n");
	printf("*******************************\n");

}

int main()
{

	int input = 0;
	do {
		//菜单
		meum();
		//选择
		printf("新的游戏,请输入选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			//游戏
			printf("游戏开始.\n");
			//动态封面
			cover();
			game();
			break;
		}
		case 0:
		{
			//退出游戏
			break;
		}
		default:
			printf("输入错误,请重新输入:>");
		}
	} while (input);

	printf("游戏结束,关闭窗口.\n");
	//关闭窗口
	//exit();




	return 0;
}