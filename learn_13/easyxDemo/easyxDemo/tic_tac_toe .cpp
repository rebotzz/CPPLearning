#include <string>
#include <ctime>
#include "easyx.h"
using std::string;
// ������С��Ϸ

#define BOARD_SIZE 3
#define WINDOW_HIGH 600
#define WINDOW_WIDTH 600

char board[BOARD_SIZE][BOARD_SIZE];
int gapx = WINDOW_WIDTH / BOARD_SIZE, gapy = WINDOW_HIGH / BOARD_SIZE;

void initBoard()
{
	// ��ʼ����������
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			board[i][j] = '-';
		}
	}
}

// ��������
void drawBoard(char user)
{
	// ��������
	for (int i = 1; i < BOARD_SIZE; ++i)
		line(0, i * gapy, WINDOW_WIDTH, i * gapy);
	for (int i = 1; i < BOARD_SIZE; ++i)
		line(i * gapx, 0, i * gapy, WINDOW_HIGH);

	// ��������
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (board[i][j] == 'o')
			{
				int x = i * gapx + gapx / 2;
				int y = j * gapy + gapy / 2;
				circle(x, y, (gapx + gapy) / 4);
			}
			else if (board[i][j] == 'x')
			{
				int x1 = i * gapx, y1 = j * gapy;
				line(x1, y1, x1 + gapx, y1 + gapy);
				line(x1, y1 + gapy, x1 + gapx, y1);
			}
		}
	}

	int x = 0, y = 0;
	TCHAR buff[10];
	_stprintf_s(buff, L"��ǰ�ֵ�: %c", user);
	outtextxy(x, y, buff);

	FlushBatchDraw();
}


// ����:�޸���������
bool putChess(int x, int y, char user)
{
	if (board[x][y] != '-') return false;

	board[x][y] = user;
	return true;
}


// �ж���Ϸʤ��
bool checkGameContinue()
{
	// 'o'ʤ��
	char user1 = 'o', user2 = 'x', user = '-';
	char winner = '-';
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[0][i] == user1 && board[1][i] == user1 && board[2][i] == user1)
		{
			winner = user1;
			break;
		}
		if (board[i][0] == user1 && board[i][1] == user1 && board[i][2] == user1)
		{
			winner = user1;
			break;
		}

		if (board[0][i] == user2 && board[1][i] == user2 && board[2][i] == user2)
		{
			winner = user2;
			break;
		}
		if (board[i][0] == user2 && board[i][1] == user2 && board[i][2] == user2)
		{
			winner = user2;
			break;
		}
	}

	user = user1;
	if (board[0][0] == user && board[1][1] == user && board[2][2] == user)
		winner = user;
	if (board[0][2] == user && board[1][1] == user && board[2][0] == user)
		winner = user;

	user = user2;
	if (board[0][0] == user && board[1][1] == user && board[2][2] == user)
		winner = user;
	if (board[0][2] == user && board[1][1] == user && board[2][0] == user)
		winner = user;

	int x = gapx, y = gapy;
	TCHAR buff[20];
	if (winner != '-')
	{
		_stprintf_s(buff, L"��ʤ����: %c!", winner);
		outtextxy(x, y, buff);
		return false;
	}

	// ����δ��
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
			if (board[i][j] == '-') return true;
	}

	// ����ȫ��:ƽ��
	_stprintf_s(buff, L"ƽ��!");
	outtextxy(x, y, buff);
	return false;
}

int main()
{
	// ��ʼ��
	initgraph(WINDOW_WIDTH, WINDOW_HIGH);
	initBoard();
	int x = 300, y = 300;
	char user = 'o';	// �û��л�״̬
	ExMessage msg;
	bool running = true;
	BeginBatchDraw();	// ��Ⱦ������
	while (running)
	{
		bool click = false;
		int begin = clock();
		// 1.��ȡ����
		while (peekmessage(&msg))
		{
			// ���������
			if (msg.message == WM_LBUTTONDOWN)
			{
				x = msg.x;
				y = msg.y;
				click = true;
			}
			else if (msg.message == WM_KEYDOWN)
			{
				if (msg.vkcode == VK_ESCAPE)	// �����˳�����
					running = false;
			}
		}

		// 2.��������
		if (click)
		{
			if (putChess(x / gapx, y / gapy, user))// ͳһʹ��easyX����
			{
				// ���ӳɹ�,�л��û�
				if (user == 'o') user = 'x';
				else user = 'o';
			}
			running = checkGameContinue();
		}

		// 3.���ƻ���
		drawBoard(user);

		// ͨ�����Ƽ��ʱ��:����֡�� 60/s
		int end = clock();		
		int duration = (begin - end) / CLOCKS_PER_SEC * 1000;
		if (duration < 1000 / 60)
		{
			Sleep(1000 / 60 - duration);
		}
	}
	Sleep(2000);

	// ������Դ
	EndBatchDraw();
	closegraph();

	return 0;
}