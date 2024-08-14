#define _CRT_SECURE_NO_WARNINGS

#include "snake.h"

//全局变量
snake_info snake;//蛇的参数
food_info food;	 //食物坐标
int changeflag = 0;	//是否吃到食物标志
int liveflag = 1;	//存活标志
int key = 77;		//向右方向键对应数值77,初始默认向右
int score = 0;		//得分
int score_list[MAX_SCORE_LINE] = { 0 };	//积分排行榜,保留前MAX_SCORE_LINE位最高分		60,10,80,30,10,50


//光标移动		光标移动后的打印,效果似乎是打印覆盖
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//与windows句柄有关,暂时看不懂
}

//打印菜单
void meum()
{
	printf("********************************************\n");
	printf("*************      贪吃蛇        ***********\n");
	printf("*************  1.play   0.eixt   ***********\n");
	printf("*************  2.tips   3.others ***********\n");
	printf("********************************************\n");
}

//打印积分排行榜
void print_score()
{
	int i = 0;
	int j = 1;
	//打印排行榜界面
	gotoxy(MAPWIDTH + 4, 2);
	printf("排行榜:");
	for (i = MAX_SCORE_LINE - 1; i >= 0; i--)
	{
		gotoxy(MAPWIDTH + 4, 2+j);
		printf("%d", j);
		gotoxy(MAPWIDTH + 12, 2+j);
		printf("%d", score_list[i]);
		j++;
	}
}


//游戏初始化: 地图创建,初始蛇生成,初始食物生成
void InitGame()
{
	//清空输入缓存区
	fflush(stdin);
	//地图创建
	int i = 0;
	for (i = 0; i < MAPWIDTH; i += 2)//间隔一个打印上下边框 ==> 一个换行长度 == 两个水平空格
	{
		gotoxy(i, 0);
		printf("■");
		gotoxy(i, MAPHIGHT);
		printf("■");
	}
	for (i = 0; i <= MAPHIGHT; i++)//打印左右边框
	{
		gotoxy(0, i);
		printf("■");
		gotoxy(MAPWIDTH, i);
		printf("■");
	}

	//初始蛇生成	位置放在中间,长度为3
	snake.len = 3;//长度
	snake.speed = 200;//初始速度
	//蛇头
	snake.x[0] = MAPWIDTH / 2 +1;	//偶数
	snake.y[0] = MAPHIGHT / 2;	//奇数
	//蛇身体
	for (i = 1; i < snake.len; i++)
	{
		snake.x[i] = MAPWIDTH / 2 - i * 2;//2 * i需要吗? 需要,一个换行长度 == 两个水平空格	
		snake.y[i] = MAPHIGHT / 2;	
	}
	//打印
	for (i = 0; i < snake.len; i++)
	{
		gotoxy(snake.x[i], snake.y[i]);
		printf("■");
	}

	//初始食物生成
	CreatFood();

	//打印得分界面
	gotoxy(MAPWIDTH + 4, 0);
	printf("score:");
	gotoxy(MAPWIDTH + 12, 0);
	printf("%d", score);

	//打印积分排行榜
	print_score();


	//将光标移动到右上角隐藏
	gotoxy(MAPWIDTH - 2, 0);

	//初始状态
	changeflag = 0;//没吃到食物
	liveflag = 1;	//还活着
}

//检查键盘输入,改变前进方向
void KeyInput()
{
	int pre_key = key;//记录上一次输入方向
	//检查是否有键盘输入
	if (_kbhit())
	{
		//检查输入合法性留到后面

		key = _getch();	//方向键会返回两次数值,第一次224
		key = _getch();	//第二次方向对应数值

		//清空输入缓存区
		fflush(stdin);

		//输入坐标不能与原方向相反,相反则方向不变
		if (key == 72 && pre_key == 80)//上
			key = pre_key;
		if (key == 80 && pre_key == 72)//下
			key = pre_key;
		if (key == 75 && pre_key == 77)//左
			key = pre_key;
		if (key == 77 && pre_key == 75)//右
			key = pre_key;
	}

		//方向控制	
		//1.判读是否需要覆盖尾部坐标打印
		if (changeflag == 0)
		{
			gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
			printf(" ");//覆盖原有打印,模拟向前移动效果
		}

		//2.将身体坐标整体后移,留出新的头部坐标空间. 就算模拟出移动效果,也要记录蛇的坐标,用于死亡判断	身体坐标不需要打印
		int i = 0;
		for (i = snake.len - 1; i > 0; i--)
		{
			snake.x[i] = snake.x[i - 1];
			snake.y[i] = snake.y[i - 1];
		}

		//3.将头部坐标改为新坐标	只用打印头部和去掉尾部,中间保留,就能实现移动的视觉效果
		if (key == 72)//上
		{
			snake.y[0]--;
		}
		if (key == 80)//下
		{
			snake.y[0]++;
		}
		if (key == 75)//左
		{
			snake.x[0] -= 2;//移动两个单位
		}
		if (key == 77)//右
		{
			snake.x[0] += 2;//移动两个单位
		}
		//打印头部
		gotoxy(snake.x[0], snake.y[0]);
		printf("■");

	//状态输入
	changeflag = 0;//目前没吃到食物
	liveflag = 1;	//目前还活着

	//将光标移动到右上角隐藏
	gotoxy(MAPWIDTH - 2, 0);
}


//检查是否吃到食物,是否需要生成食物
void IsGetFood()
{
	//头部与食物坐标是否重叠
	if ((food.x == snake.x[0]) && (food.y == snake.y[0]))
	{
		//吃到食物,需要生成新的食物
		CreatFood();

		//长度+1,吃到食物标志改变,速度加快,分数增加
		snake.len++;
		changeflag = 1;
		snake.speed -= 5;
		score += 10;

		//打印刷新后得分
		gotoxy(MAPWIDTH + 12, 0);
		printf("%d", score);
	}

}

//生成食物
void CreatFood()
{
	int i = 0;
	srand((unsigned int)time(NULL));//随机种子
	while (1)
	{
		food.x = rand() % (MAPWIDTH - 4) + 2;
		food.y = rand() % (MAPHIGHT - 2) + 1;

		//因为一个换行长度 == 两个水平空格,为了长宽相等,x与食物奇偶要相同,这样才能与蛇坐标重叠,被吃到
		//判断坐标合法性
		int flag = 1;
		for (i = 0; i < snake.len; i++)//不能与蛇重叠
		{
			if ((snake.x[i] == food.x) && (snake.y[i] == food.y))
			{
				flag = 0;
			}
		}
		if ((food.x % 2 == 0) && (flag == 1))//蛇头x在偶数位,所以食物x不能在奇数位置
			break;
	}
	//打印食物
	gotoxy(food.x, food.y);
	printf("○");
}


//检查是否存活
int IsLive()
{
	//头部坐标是否与墙重叠,
	if ((snake.x[0] == 0) || (snake.x[0] == MAPWIDTH) || (snake.y[0] == 0) || (snake.y[0] == MAPHIGHT))
	{
		return DIE;
	}
	int i = 0;
	//头部坐标是否与身体重叠
	for (i = 1; i < snake.len; i++)
	{
		if ((snake.x[0] == snake.x[i]) && (snake.y[0] == snake.y[i]))
		{
			return DIE;
		}
	}
	return LIVE;
}

//qsort所用到的 int 大小比较
int cmp_int(void* e1, void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

//排序积分榜,降序
void score_sort(int* arr,int sz)
{
	//快速排序,这样时间复杂度比冒泡排序低些
	qsort(arr, sz, sizeof(int), cmp_int);

}


//打开文件,读取积分记录
void read_file()
{
	int flag = 1;
	//打开文件	R
	FILE* pf = fopen("score_list.txt","r");
	if (pf == NULL)
	{
		flag = 0;
		pf = fopen("score_list.txt", "w");
		if (pf == NULL)
		{
			perror("create and read score_list.txt failed.");
			return;
		}
	}
	//文件存在
	if (flag == 1)
	{
		int i = 0;
		for (i = 0; i < MAX_SCORE_LINE; i++)
		{
			fscanf(pf, "%d\n", &score_list[i]);
		}

	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//退出游戏,保存积分记录
void exit_save()
{
	//打开文件	W
	FILE* pf = fopen("score_list.txt", "w");
	if (pf == NULL)
	{
		perror("save score_list failed.");
		return;
	}
	//保存数据
	int i = 0;
	for (i = 0; i < MAX_SCORE_LINE; i++)
	{
		fprintf(pf, "%d\n", score_list[i]);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}


//提示
void tips()
{
	int tmp = 0;
	printf("其实这个游戏没有提示,因为上手简单.\n");
	tmp = getchar();
	tmp = getchar();
	printf("真的没有提示.\n");
	tmp = getchar();
	printf("没有,就是没有.\n");
	tmp = getchar();
	printf("你就算继续看下去也没有.\n");
	tmp = getchar();
	printf("...\n");
	tmp = getchar();
	printf("......\n");
	tmp = getchar();
	printf("我现在还没有能力做meta游戏,所以这里没有彩蛋,抱歉.\n");
	tmp = getchar();
	printf("不过,如果你想玩meta游戏的话,这里有一个推荐.\n");
	tmp = getchar();
	printf("游戏名:There is no game.\n");
	tmp = getchar();
	printf("游戏不错,不过解密可能会有些枯燥.\n");
	tmp = getchar();
	printf("通关的感觉记忆犹新.\n");
	tmp = getchar();
	printf("好了,结束了,真的没有提示.\n");
	tmp = getchar();
	printf("Tips:如果你想添加什么功能可以给我留言,但我不一定会.\n");
	tmp = getchar();
	system("cls");
}

//其他,作者的话
void others()
{
	int tmp = 0;
	printf("写这个游戏的起因:\n");
	tmp = getchar();
	tmp = getchar();
	printf("我看到别人学完C语言可以写这个游戏.\n");
	tmp = getchar();
	printf("然后,我正好学完,你懂的,我就想试一试.\n");
	tmp = getchar();
	printf("然后看来一下别人发的博客,捋了一遍逻辑.\n");
	tmp = getchar();
	printf("然后开始写bug...\n");
	tmp = getchar();
	printf("然后改bug......\n");
	tmp = getchar();
	printf("然后就写完了.\n");
	tmp = getchar();
	printf("最后,感谢你的游玩,谢谢.[]~(￣▽￣)~*\n");
	tmp = getchar();
	system("cls");

}