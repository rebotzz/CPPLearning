#define _CRT_SECURE_NO_WARNINGS

//̰����
//�ο�����

#include "game.h"

int main()
{
	int input = 1;
	while (input)
	{
		//�˵�
		meum();
		printf("���������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");//�����Ļ
			//���Ƶ�ͼ
			drawMap();
			while (1)
			{
				//�������
				keyDown();
				if (!snakeStatus())//�����˳�
					break;
				//����ʳ��
				createFood();
				//���Ƽ��ʱ��,�Ӷ������ߵ��ƶ��ٶ�
				Sleep(snake.speed);
			}

			//���������ӡ
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
			printf("Game Over!\n");
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 1);
			printf("������Ϸ�÷�Ϊ��%d\n", sorce);
			gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 2);
			printf("���ⰴ���������˵�.\n");
			Sleep(1000);
			_getch();
			system("cls");
			break;
		case 0:
			printf("�˳���Ϸ.\n");
			break;
		default:
			printf("�������,����������.\n");
			break;
		}
	}
	

	return 0;
}