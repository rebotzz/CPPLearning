#define _CRT_SECURE_NO_WARNINGS

//ͨѶ¼1.0
//1.��ϵ����������ǹ̶����ɸĵ�
//2.����:����,�޸�,ɾ��,����,��ʾ��ϵ��


//���ܲ��Բ���
#include "contact.h"
extern int list[];


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
		scanf("%d", &input);
		//�����Ӧ����
		switch (input)
		{
		case ADD:
			add();
			break;
		case DIV:
			div();
			break;
		case FIND:
			printf("��������Ҫ�����˵�����:");
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
			break;
		default:
			printf("����ָ��,����������;>\n");
			break;
		}
	} while (input);
	printf("�˳�����.\n");
	return 0;
}
