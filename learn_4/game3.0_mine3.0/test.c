#define _CRT_SECURE_NO_WARNINGS
//����Ӧ��,ɨ����Ϸ2.0
//�����Ż�:
//			1.��ըʽ�߽�չ��
//			2.���ӱ�ǹ���  (�����Ż�4.0)
//			3.����������¼  (Ϊ�˸���������,��Ϊʱ���¼)
//ͷ�ļ�
#include "game.h"

//��Ϸ
void game()
{
	//�洢�������
	int mark[60][2] = { 0 };
	int mark_ = 0;//���
	//���̳�ʼ��
	InitBoard(mine, ROWS, COLS, '0');//������,������Ԫ�صĵ�ַ
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL,0,0,0);
	//���õ���
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL,0,0,0);//���Դ�����,����
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
			start = time(NULL);
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