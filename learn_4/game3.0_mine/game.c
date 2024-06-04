#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


//菜单
void menu()
{
	printf("**************************\n");
	printf("********   扫雷    *******\n");
	printf("********  1.play   *******\n");
	printf("********  0.exit   *******\n");
	printf("**************************\n");

}

//棋盘初始化
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷游戏------------\n");
	for (j = 0; j <= col; j++)
	{
		//printf("%c ", j + '0');
		printf("%d ", j);//打印的棋盘,不改变原有棋盘,所以这里可以为 整形 ,不用 字符型
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%c ", i + '0');
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏------------\n");

}

//布置地雷
//debug board[][COLS],这里不能是 COL ,否则不完整 
void SetMine(char board[ROWS][COLS], int row, int col) 
{
	//雷坐标
	int x = 0;
	int y = 0;
	//雷数量
	int count = easy_count;
	while (count)
	{
		//随机数范围, 1 ~ row
		x = rand() % row + 1;
		y = rand() % col + 1;
		//判断坐标合法性
		if (board[x][y] == '0')//随机数范围包含了 x >= 1 && x <= row && y >= 1 && y <= col && 
		{
			board[x][y] = '1';
			count--;
		}
	}

}

//扫雷
void FindMine(char board[ROWS][COLS], int row, int col)//board[ROWS][COLS] 应该相当于指针变量
{
	//非雷格子数目
	int count = ROW * COL - easy_count;
	while (count)
	{
		printf("输入扫雷坐标:>\n");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//输入坐标合法性检测
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
		{
			//有雷,被炸死,游戏结束
			if (board[x][y] == '1')
			{
				printf("很遗憾,你被炸死了,任务失败.\n");
				break;
			}
			//无雷,显示附近的雷,游戏继续
			if (board[x][y] == '0')
			{
				//显示附近的雷
				int adhere_mine = CountMine(board,x,y);//雷的数量
				show[x][y] = adhere_mine + '0';//char类型,不是 int ,按照ASCII码转换
				DisplayBoard(show, ROW, COL);//打印界面
				count--;
			}
		}
		else
		{
			printf("坐标错误,请重新输入.\n");
		}
	}
	if (count == 0)
	{
		printf("恭喜你,游戏通关.\n");
	}

}

//显示附近的雷
int CountMine(char board[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (board[x+i][y+j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}