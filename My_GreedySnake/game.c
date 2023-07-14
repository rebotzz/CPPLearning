#define _CRT_SECURE_NO_WARNINGS

// 贪吃蛇1.0
// 1.光标移动,打印覆盖,中间部分不变,打印新建头部,是否保留尾部,实现移动效果
// 2.吃到食物,长度增加,速度加快,用延时函数实现
// 3.撞墙,撞到自己身体判定
// 4.得分记录
// 排行榜 ==>文件管理实现
//
// 待优化:			  
// 长按方向键实现临时加速  ==> 暂时没有思路
//

#include "snake.h"


//开始游戏
void game()
{
	//清空屏幕
	system("cls");
	//游戏初始化: 地图创建,初始蛇生成,初始食物生成,蛇的初始状态
	InitGame();
	while (1)
	{
		//检查键盘输入,改变前进方向
		KeyInput();
		//检查是否吃到食物,是否需要生成食物
		IsGetFood();
		//检查是否存活
		liveflag = IsLive();
		if (liveflag == 0)
		{
			break;
		}
		Sleep(snake.speed);//速度控制
	}

	//游戏结束界面
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2);
	printf("game over!");
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2 + 1);
	printf("你的得分为: %d", score);
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2 + 2);
	printf("按任意键返回开始菜单!");
	int tmp = _getch();
	system("cls");
	//将积分存入数组
	if (score >score_list[0])
	{
		score_list[0] = score;
	}

	//排序积分榜,升序,分数最低的放在 times = 0
	score_sort(score_list, MAX_SCORE_LINE);
	//得分初始化
	score = 0;
}



int main()
{
	int input = 1;
	//打开文件,读取积分记录
	read_file();
	do
	{
		//打印菜单
		meum();
		printf("请输入选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			//开始游戏
			game();
			//按任意键继续
			_getch();
			break;
		case EXIT:
			printf("退出游戏.\n");
			//退出游戏,保存积分记录
			exit_save();
			break;
		case TIPS:
			//提示
			tips();
			break;
		case OTHERS:
			//其他,作者的话
			others();
			break;
		default:
			printf("输入错误,请重新输入.\n");
			break;
		}
	} while (input);

	return 0;
}