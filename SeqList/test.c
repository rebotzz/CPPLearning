#define _CRT_SECURE_NO_WARNINGS

//˳���ѧϰ
//˳���ŷ�,����

//Ŀ��,ʵ�����ݹ���

#include "SeqList.h"

void test1()
{
	//��ʼ��
	SeqListInit(&SLData);
	//�������
	SeqListPushBack(&SLData, 1);
	SeqListPushBack(&SLData, 2);
	SeqListPushBack(&SLData, 3);
	SeqListPushBack(&SLData, 4);
	SeqListPushBack(&SLData, 5);
	SeqListPushBack(&SLData, 6);
	SeqListPushBack(&SLData, 7);
	SeqListPushBack(&SLData, 8);
	//��ӡ����
	SeqListPrint(&SLData);
	//��ɾ
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	//��ӡ����
	SeqListPrint(&SLData);
	//��ɾ
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	SeqListPopBack(&SLData);
	//�������
	SeqListPushBack(&SLData, 1);
	SeqListPushBack(&SLData, 2);
	SeqListPushBack(&SLData, 3);
	//��ӡ����
	SeqListPrint(&SLData);

}

//ǰ��,ǰɾ����
void test2()
{
	//��ʼ��
	SeqListInit(&SLData);
	//ǰ��
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	SeqListPrint(&SLData);
	//ǰɾ
	for (i = 0; i < 10; i++)
	{
		SeqlistPopFront(&SLData);
	}
	SeqListPrint(&SLData);
	//ǰ��
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i + 3);
	}
	SeqListPrint(&SLData);
}


//�м��������,�м�ɾ������
void test3()
{
	//��ʼ��
	SeqListInit(&SLData);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		SeqListPushBack(&SLData, i + 1);
	}
	SeqListPrint(&SLData);
	//�м����
	SeqListInsert(&SLData, 5, 10);
	SeqListInsert(&SLData, -1, 11);
	SeqListInsert(&SLData, 19, 12);
	SeqListPrint(&SLData);

	//�м��޸�
	SeqListReviseMiddle(&SLData,3,0);
	SeqListPrint(&SLData);

	//�м�ɾ��
	SeqListErase(&SLData,3);
	SeqListErase(&SLData, 3);
	SeqListPrint(&SLData);


}

void test_menu()
{

	int input = 1;
	SLDataType x = { 0 };
	int pos = 0;
	do
	{
		//�˵�
		menu();
		printf("�������:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT_SAVE:
			ExitSave(&SLData);
			break;
		case PUSHFRONT:
			printf("�����������:");
			scanf(SCANFTYPE, &x);
			SeqListPushFront(&SLData, x);
			break;
		case POPFRONT:
			SeqlistPopFront(&SLData);
			break;
		case PUSHBACK:
			printf("�����������:");
			scanf(SCANFTYPE, &x);
			SeqListPushBack(&SLData, x);
			break;
		case POPBACK:
			SeqListPopBack(&SLData);
			break;
		case PUSHMIDDLE:
			printf("����������ݺͲ���λ��:");
			scanf(SCANFTYPE, &x);
			scanf("%d", &pos);
			SeqListInsert(&SLData, pos - 1, x);
			break;
		case POPMIDDLE:
			printf("����ɾ��λ��:");
			scanf("%d", &pos);
			SeqListErase(&SLData, pos - 1);
			break;
		case REVISEMIDDLE:
			printf("�����޸ĺ����ݺ��޸�λ��:");
			scanf(SCANFTYPE, &x);
			scanf("%d", &pos);
			SeqListReviseMiddle(&SLData, pos - 1, x);
			break;
		case PRINT:
			SeqListPrint(&SLData);
			break;
		case GETDATA:
			GetData(&SLData);
			break;
		case FIND:
			printf("�����������:");
			scanf(SCANFTYPE, &x);
			int ret = SeqListFind(&SLData, x);
			if (ret != -1)
			{
				printf("�ҵ���:"PRINTTYPE"\t�����±�Ϊ:%d\n", x, ret);
			}
			else
			{
				printf("��ѯ�޹�.\n");
			}
			break;
		default:
			printf("�������,��������.\n");
		}
	} while (input);

}

void test4()
{
	//��ʼ��
	SeqListInit(&SLData);
	//ǰ��
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	i = 9;
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	SeqListPushFront(&SLData, i);
	for (i = 0; i < 4; i++)
	{
		SeqListPushFront(&SLData, i);
	}
	SeqListPrint(&SLData);

	int pos = SeqListFind(&SLData, 9);
	while (pos != -1)
	{
		SeqListErase(&SLData, pos);
		pos = SeqListFind(&SLData, 9);
	}
	SeqListPrint(&SLData);
	pos = SeqListFind(&SLData, 0);
	while (pos != -1)
	{
		SeqListReviseMiddle(&SLData, pos, 10);
		pos = SeqListFind(&SLData, 0);
	}
	SeqListPrint(&SLData);

}

int main()
{
	//���,��ɾ����
	//test1();

	//ǰ��,ǰɾ����
	//test2();

	//�м��������,�м�ɾ������
	//test3();

	//test_menu();

	//������Ϲ��ܲ���
	test4();

	return 0;
}