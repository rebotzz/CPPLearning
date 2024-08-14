#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


//�˵�
void menu()
{
	printf("**************************\n");
	printf("********   ɨ��    *******\n");
	printf("********  1.play   *******\n");
	printf("********  0.exit   *******\n");
	printf("**************************\n");

}

//���̳�ʼ��
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

//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ------------\n");
	for (j = 0; j <= col; j++)
	{
		//printf("%c ", j + '0');
		printf("%d ", j);//��ӡ������,���ı�ԭ������,�����������Ϊ ���� ,���� �ַ���
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
	printf("----------ɨ����Ϸ------------\n");

}

//���õ���
//debug board[][COLS],���ﲻ���� COL ,�������� 
void SetMine(char board[ROWS][COLS], int row, int col) 
{
	//������
	int x = 0;
	int y = 0;
	//������
	int count = easy_count;
	while (count)
	{
		//�������Χ, 1 ~ row
		x = rand() % row + 1;
		y = rand() % col + 1;
		//�ж�����Ϸ���
		if (board[x][y] == '0')//�������Χ������ x >= 1 && x <= row && y >= 1 && y <= col && 
		{
			board[x][y] = '1';
			count--;
		}
	}

}

//ɨ��
void FindMine(char board[ROWS][COLS], int row, int col)//board[ROWS][COLS] Ӧ���൱��ָ�����
{
	//���׸�����Ŀ
	int count = ROW * COL - easy_count;
	while (count)
	{
		printf("����ɨ������:>\n");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//��������Ϸ��Լ��
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
		{
			//����,��ը��,��Ϸ����
			if (board[x][y] == '1')
			{
				printf("���ź�,�㱻ը����,����ʧ��.\n");
				break;
			}
			//����,��ʾ��������,��Ϸ����
			if (board[x][y] == '0')
			{
				//��ʾ��������
				int adhere_mine = CountMine(board,x,y);//�׵�����
				show[x][y] = adhere_mine + '0';//char����,���� int ,����ASCII��ת��
				DisplayBoard(show, ROW, COL);//��ӡ����
				count--;
			}
		}
		else
		{
			printf("�������,����������.\n");
		}
	}
	if (count == 0)
	{
		printf("��ϲ��,��Ϸͨ��.\n");
	}

}

//��ʾ��������
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