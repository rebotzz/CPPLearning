#define _CRT_SECURE_NO_WARNINGS

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//三子棋

void meum_1()
{
	printf("***************************************\n");
	printf("************   三子棋   ***************\n");
	printf("************   1.play   ***************\n");
	printf("************   0.exit   ***************\n");
	printf("************   2.other  ***************\n");
	printf("***************************************\n");

}

void meum_2()
{
	printf("***************************************\n");
	printf("************   1.三子棋  **************\n");
	printf("************   2.五子棋  **************\n");
	printf("************   3.未完成  **************\n");
	printf("***************************************\n");

}




int main()
{

	int input = 0;
	do {
		//菜单1
		meum_1();
		//选择
		printf("新的游戏,请输入选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			//菜单2
			meum_2();
			//难度选择
			printf("不同难度,请输入选择:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:		//三子棋
				game();
				break;
			case 2:		//五子棋
				game_2();
				break;
			case 3:		//n子棋
				printf("未完成.....\n");
				printf("前面的区域以后再来探索吧.\n");
				break;
			default:
				printf("输入错误,请重新输入:>\n");
			}

			break;
		}
		case 0:
		{
			//退出游戏
			break;
		}
		case 2:
			printf("Tips:\n这个游戏没有tips.\n");
			getchar();
			getchar();
			printf("电脑的算法只是随机数生成,没有智能.\n");
			getchar();
			printf("这个算是我写的第二个C语言小游戏了,\n300行左右代码(￣▽￣)\n");
			getchar();
			printf("呼~,从中午写到晚上,嗯,是一个学习的过程.\n");
			getchar();
			printf("很高兴你能玩这个不算有趣游戏,撒花~\n");
			getchar();
			printf("我说完了,拜~\n再玩一把 or 退出游戏随你高兴 <(￣︶￣)↗[GO!]\n");
			getchar();

		default:
			printf("输入错误,请重新输入:>\n");
		}
	} while (input);

	printf("游戏结束,关闭窗口.\n");
	//关闭窗口
	//exit();




	return 0;
}