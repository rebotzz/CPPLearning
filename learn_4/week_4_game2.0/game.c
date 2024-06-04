#define _CRT_SECURE_NO_WARNINGS


//头文件
#include "game.h"


//棋盘 -初始化
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//棋盘数组初始化
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

//打印棋盘
void Display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < COL; j++)
		{
			if (i < ROW - 1)
			{
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
		}
		printf("\n");

	}

}


//玩家走
void player_do(char board[][COL], int row, int col)
{
	printf("玩家走'*':>");
	int x = 0, y = 0;
	//判断输入是否合法
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("非法输入,请重新输入:>");
	}

}

//电脑走
void computer_do(char board[][COL], int row, int col)
{
	printf("电脑走'#':>");
	int x = 0, y = 0;
	//利用时间,生成随机数. srand放在循环外面,  时间间隔 逐渐增大 ,循环里面时间间隔改变小
	srand((unsigned)time(NULL));
	//判断输入是否合法
	while (1)
	{
		//x = rand() % row;		//局限,不会生成 0
		//y = rand() % col;
		//代码优化
		x = rand() % (row + 1);	//范围: 1 ~ row
		y = rand() % (col + 1);
		if (x >= 1 && x <= row && y >= 1 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			printf("\n");
			break;
		}
	}
}

//判断输赢 - 只判断赢
char Is_Win(char board[ROW][COL], int row, int col, char who)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	//行符合要求
	for (i = 0; i < row; i++)
	{
		tmp = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == who)
				tmp++;
		}
		if (tmp == col)
			return who;
	}

	//列符合要求
	for (j = 0; j < col; j++)
	{
		tmp = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == who)
				tmp++;
		}
		if (tmp == row)
			return who;
	}

	//对角线符合要求
	{
		//主对角线
		for (i = 0, tmp = 0; i < col; i++)	//tmp 初始化 0
		{
			if (board[i][i] == who)
				tmp++;
			if (tmp == col)
				return who;
		}
		//副对角线
		for (j = 0, tmp = 0; j < col; j++)
		{
			if (board[j][col - 1 - j] == who)
				tmp++;
			if (tmp == col)
				return who;

		}

	}
}


//判断输赢 - 分析情况
char IsWin_Fail(char board[ROW][COL], int row, int col)
{

	//玩家赢了 '*'
	if (Is_Win(board, ROW, COL, '*') == '*')
	{
		printf("玩家赢了!\n");
		return '*';
	}

	//电脑赢了 '#'
	if (Is_Win(board, ROW, COL, '#') == '#')
	{
		printf("电脑赢了!\n");
		return '#';
	}

	//平局    'q'
	int i = 0;
	int j = 0;
	int tmp = 1;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				tmp = 0;
		}
	}//填满了,且没有赢家
	if (tmp == 1 && i == row - 1 && j == col - 1)
		return 'q';

	//进行中  'c'
	else
		return 'c';

}


//动态封面
void cover()
{
	int time = 400;
	printf("Are ");
	Sleep(time);
	printf("you ");
	Sleep(time);
	printf("ready?\n");
	Sleep(time);
	printf("GO!\n");
	printf("输入两个数字作为落子坐标,中间用空格隔开.	回车继续.\n");
	getchar();
	getchar();
	system("cls");
}


void game()
{
	printf("%d 子棋\n", COL);

	//游戏
	printf("游戏开始.\n");
	//动态封面
	cover();

	//数组
	char board[ROW][COL];

	//棋盘  -初始化
	init_board(board, ROW, COL);
	//打印棋盘
	Display_board(board, ROW, COL);

	char res = 'c';//判断输赢依据

	while (1)
	{

		//玩家走
		player_do(board, ROW, COL);
		Display_board(board, ROW, COL);
		//判断输赢
		res = IsWin_Fail(board, ROW, COL);
		if (res != 'c')
			break;
		//清空屏幕
		system("cls");
		//电脑走
		computer_do(board, ROW, COL);
		Display_board(board, ROW, COL);
		//判断输赢
		res = IsWin_Fail(board, ROW, COL);
		if (res != 'c')
			break;

	}
	printf("游戏结束.\n");


}