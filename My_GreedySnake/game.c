#define _CRT_SECURE_NO_WARNINGS

// ̰����1.0
// 1.����ƶ�,��ӡ����,�м䲿�ֲ���,��ӡ�½�ͷ��,�Ƿ���β��,ʵ���ƶ�Ч��
// 2.�Ե�ʳ��,��������,�ٶȼӿ�,����ʱ����ʵ��
// 3.ײǽ,ײ���Լ������ж�
// 4.�÷ּ�¼
// ���а� ==>�ļ�����ʵ��
//
// ���Ż�:			  
// ���������ʵ����ʱ����  ==> ��ʱû��˼·
//

#include "snake.h"


//��ʼ��Ϸ
void game()
{
	//�����Ļ
	system("cls");
	//��Ϸ��ʼ��: ��ͼ����,��ʼ������,��ʼʳ������,�ߵĳ�ʼ״̬
	InitGame();
	while (1)
	{
		//����������,�ı�ǰ������
		KeyInput();
		//����Ƿ�Ե�ʳ��,�Ƿ���Ҫ����ʳ��
		IsGetFood();
		//����Ƿ���
		liveflag = IsLive();
		if (liveflag == 0)
		{
			break;
		}
		Sleep(snake.speed);//�ٶȿ���
	}

	//��Ϸ��������
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2);
	printf("game over!");
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2 + 1);
	printf("��ĵ÷�Ϊ: %d", score);
	gotoxy(MAPWIDTH / 2, MAPHIGHT / 2 + 2);
	printf("����������ؿ�ʼ�˵�!");
	int tmp = _getch();
	system("cls");
	//�����ִ�������
	if (score >score_list[0])
	{
		score_list[0] = score;
	}

	//������ְ�,����,������͵ķ��� times = 0
	score_sort(score_list, MAX_SCORE_LINE);
	//�÷ֳ�ʼ��
	score = 0;
}



int main()
{
	int input = 1;
	//���ļ�,��ȡ���ּ�¼
	read_file();
	do
	{
		//��ӡ�˵�
		meum();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			//��ʼ��Ϸ
			game();
			//�����������
			_getch();
			break;
		case EXIT:
			printf("�˳���Ϸ.\n");
			//�˳���Ϸ,������ּ�¼
			exit_save();
			break;
		case TIPS:
			//��ʾ
			tips();
			break;
		case OTHERS:
			//����,���ߵĻ�
			others();
			break;
		default:
			printf("�������,����������.\n");
			break;
		}
	} while (input);

	return 0;
}