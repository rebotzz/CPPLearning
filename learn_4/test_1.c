#define _CRT_SECURE_NO_WARNINGS

//ͷ�ļ�
#include "game.h"

//������

void meum()
{
	printf("*******************************\n");
	printf("**********   ������   *********\n");
	printf("**********   1.play   *********\n");
	printf("**********   0.exit   *********\n");
	printf("*******************************\n");

}

int main()
{

	int input = 0;
	do {
		//�˵�
		meum();
		//ѡ��
		printf("�µ���Ϸ,������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			//��Ϸ
			printf("��Ϸ��ʼ.\n");
			//��̬����
			cover();
			game();
			break;
		}
		case 0:
		{
			//�˳���Ϸ
			break;
		}
		default:
			printf("�������,����������:>");
		}
	} while (input);

	printf("��Ϸ����,�رմ���.\n");
	//�رմ���
	//exit();




	return 0;
}