#define _CRT_SECURE_NO_WARNINGS


//ͷ�ļ�
#include "game.h"


//���� -��ʼ��
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//���������ʼ��
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

//��ӡ����
void Display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ
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


//�����
void player_do(char board[][COL], int row, int col)
{
	printf("�����'*':>");
	int x = 0, y = 0;
	//�ж������Ƿ�Ϸ�
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("�Ƿ�����,����������:>");
	}

}

//������
void computer_do(char board[][COL], int row, int col)
{
	printf("������'#':>");
	int x = 0, y = 0;
	//����ʱ��,���������. srand����ѭ������,  ʱ���� ������ ,ѭ������ʱ�����ı�С
	srand((unsigned)time(NULL));
	//�ж������Ƿ�Ϸ�
	while (1)
	{
		//x = rand() % row;		//����,�������� 0
		//y = rand() % col;
		//�����Ż�
		x = rand() % (row + 1);	//��Χ: 1 ~ row
		y = rand() % (col + 1);
		if (x >= 1 && x <= row && y >= 1 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			printf("\n");
			break;
		}
	}
}

//�ж���Ӯ - ֻ�ж�Ӯ
char Is_Win(char board[ROW][COL], int row, int col, char who)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	//�з���Ҫ��
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

	//�з���Ҫ��
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

	//�Խ��߷���Ҫ��
	{
		//���Խ���
		for (i = 0, tmp = 0; i < col; i++)	//tmp ��ʼ�� 0
		{
			if (board[i][i] == who)
				tmp++;
			if (tmp == col)
				return who;
		}
		//���Խ���
		for (j = 0, tmp = 0; j < col; j++)
		{
			if (board[j][col - 1 - j] == who)
				tmp++;
			if (tmp == col)
				return who;

		}

	}
}


//�ж���Ӯ - �������
char IsWin_Fail(char board[ROW][COL], int row, int col)
{

	//���Ӯ�� '*'
	if (Is_Win(board, ROW, COL, '*') == '*')
	{
		printf("���Ӯ��!\n");
		return '*';
	}

	//����Ӯ�� '#'
	if (Is_Win(board, ROW, COL, '#') == '#')
	{
		printf("����Ӯ��!\n");
		return '#';
	}

	//ƽ��    'q'
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
	}//������,��û��Ӯ��
	if (tmp == 1 && i == row - 1 && j == col - 1)
		return 'q';

	//������  'c'
	else
		return 'c';

}


//��̬����
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
	printf("��������������Ϊ��������,�м��ÿո����.	�س�����.\n");
	getchar();
	getchar();
	system("cls");
}


void game()
{
	printf("%d ����\n", COL);

	//��Ϸ
	printf("��Ϸ��ʼ.\n");
	//��̬����
	cover();

	//����
	char board[ROW][COL];

	//����  -��ʼ��
	init_board(board, ROW, COL);
	//��ӡ����
	Display_board(board, ROW, COL);

	char res = 'c';//�ж���Ӯ����

	while (1)
	{

		//�����
		player_do(board, ROW, COL);
		Display_board(board, ROW, COL);
		//�ж���Ӯ
		res = IsWin_Fail(board, ROW, COL);
		if (res != 'c')
			break;
		//�����Ļ
		system("cls");
		//������
		computer_do(board, ROW, COL);
		Display_board(board, ROW, COL);
		//�ж���Ӯ
		res = IsWin_Fail(board, ROW, COL);
		if (res != 'c')
			break;

	}
	printf("��Ϸ����.\n");


}