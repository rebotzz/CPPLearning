#define _CRT_SECURE_NO_WARNINGS

//ͨѶ¼3.0
//1.��ϵ�����������̬�޸�
//2.����:����,�޸�,ɾ��,����,��ʾ��ϵ��
//3.�����ݴ洢���ļ�,���ļ���ȡ/д����Ϣ
//4.���ҹ����Ż�,����ȫ����,�ֻ��Ų���


//���ܲ��Բ���
#include "contact.h"
extern int list[];
extern s_con con;

int main()
{
	int input = 0;
	//��ʼ��
	init();
	do
	{
		//�˵�
		meun();
		//�������
		printf("������������:>");
		scanf("%d", &input);
		//�����Ӧ����
		switch (input)
		{
		case ADD:
			add();
			break;
		case DIV:
			delete();
			break;
		case FIND:
			find();
			//��ʼ��list[]
			int i = 0;
			for (i = 0; i < MAX_LIST; i++)
			{
				list[i] = 0;
			}
			break;
		case CHANGE:
			change();
			break;
		case DISPLAY:
			display();
			break;
		case EXIT:
			exit_save();
			break;
		default:
			printf("����ָ��,����������:>\n");
			break;
		}
	} while (input);
	printf("�˳�����.\n");
	return 0;
}
