#define _CRT_SECURE_NO_WARNINGS
//����Ӧ��,ɨ����Ϸ

//ͷ�ļ�
#include "game.h"

//��Ϸ
void game()
{
	//���̳�ʼ��
	InitBoard(mine, ROWS, COLS, '0');//������,������Ԫ�صĵ�ַ
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//���õ���
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//���Դ�����,����
	//ɨ��
	FindMine(mine, ROW, COL);

}

int main()
{
	//����ֵ
	int input = 0;
	//�ײ���
	char mine[ROWS][COLS] = { 0 };
	//ɨ��չʾ����
	char show[ROWS][COLS] = { 0 };
	//�������
	srand((unsigned int) time(NULL));

	do
	{
		//�˵�
		menu();
		//ѡ��
		printf("������ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			//��Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,����������.\n");
			break;
		}
	} while (input);



		return 0;
}