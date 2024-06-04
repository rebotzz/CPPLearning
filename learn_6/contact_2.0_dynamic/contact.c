#define _CRT_SECURE_NO_WARNINGS

//����ʵ�ֲ���
#include "contact.h"

s_con con = { 0 };			   //ͨѶ¼��Ϣ,static����,�������ݶ�,�����Զ�����
int list[MAX_LIST] = { 0 };	   //��ѯ���,����arr[]�����
int max_sz = 0;


//�˵�
void meun()
{
	printf("****************************************\n");
	printf("*******        ͨѶ¼       ************\n");
	printf("*******    1.����  2.ɾ��   ************\n");
	printf("*******    3.����  4.�޸�   ************\n");
	printf("*******    5.��ʾ  0.�˳�   ************\n");
	printf("****************************************\n");
}

//��ʼ��
void init()
{
	//����ͨѶ¼,��ʼ��
	peo_info* arr = (peo_info*)malloc(MAX_PEO*sizeof(peo_info));//������Ϣ,�ڶ����Ͽ���,�����Զ�����,arr��ջ��,�Զ�����
	if (arr == NULL)
	{
		perror("init");
		return;
	}

	max_sz = MAX_PEO;					   //��ǰ�������
	con.p = arr;
	con.sz = 0;
}

//������ϵ��
void add()
{
	if (con.sz < max_sz)
	{
		if (con.sz == max_sz - 1)
		{
			//���ӿ����ڴ�
			void* tmp = realloc(con.p, (max_sz + INC_SZ) * sizeof(peo_info));
			if (tmp != NULL)
			{
				con.p = (peo_info*)tmp;
				max_sz += INC_SZ;
				printf("���ݳɹ�.\n");
			}
		}
		printf("������ϵ��:\n");
		printf("����������:");
		scanf("%s", ((con.p)[con.sz]).name);//�ַ���������������Ԫ�ص�ַ,���Կ��Բ���ȡ��ַ
		printf("�������Ա�:");
		scanf("%s", (con.p)[con.sz].sex);
		printf("����������:");
		scanf("%d", &(con.p[con.sz].age));
		printf("�������ֻ���:");
		scanf("%s", con.p[con.sz].tele);
		printf("������סַ:");
		scanf("%s", con.p[con.sz].addr);
		printf("���ӳɹ�!\n");
		con.sz++;
	}
	else
	{
		printf("����ʧ��.\n");
	}

}

//ɾ����ϵ��
void delete()
{
	//����
	printf("����Ҫɾ����ϵ������:");
	int* ret = find();
	//ɾ��
	if (ret != NULL)
	{
		printf("��������Ҫɾ����ϵ�˵����:");
		int n = 0;
		scanf("%d", &n);
		//arr[list[n]]֮������ݰ�����ǰŲ��.
		if (list[n] < con.sz)
		{
			//2.0memmove����memcpy
			memmove(con.p + list[n], con.p + list[n] + 1, (con.sz - list[n] - 1) * sizeof(peo_info));
			con.sz--;
			printf("ɾ���ɹ�.\n");

			//��С���ٿռ�
			if (con.sz < max_sz - 2)
			{
				void* tmp = realloc(con.p, (max_sz - 2) * sizeof(peo_info));
				if (tmp != NULL)
				{
					con.p = (peo_info*)tmp;
					max_sz = max_sz - 2;
					printf("��С�ռ�ɹ�.\n");
				}
			}


			//��ʼ��list[]
			int i = 0;
			for (i = 0; i < MAX_LIST; i++)
			{
				list[i] = 0;
			}
		}

	}

}

//��ʾ��ϵ��
void display()
{
	//������ϵ��
	sort_name();
	printf("%-6s%-6s\t%-5s\t%-4s\t%-12s\t%-s\n", "���", "����", "�Ա�", "����", "�绰", "סַ");
	int i = 0;
	for (i = 0; i < con.sz; i++)
	{
		printf("%-6d%-6s\t%-5s\t%-4d\t%-12s\t%-s\n", i, con.p[i].name, con.p[i].sex, con.p[i].age, con.p[i].tele, con.p[i].addr);
	}
}

//������ϵ��
int* find()
{
	char name[20] = { 0 };
	scanf("%s", name);
	int i = 0;
	int count = 0;
	for (i = 0; i < con.sz; i++)
	{
		if (strcmp(name, con.p[i].name) == 0)
		{
			if (count == 0)
			{
				printf("���ҵ�:\n");
				printf("%-6s%-6s\t%-5s\t%-4s\t%-12s\t%-s\n", "���", "����", "�Ա�", "����", "�绰", "סַ");
			}
			printf("%-6d%-6s\t%-5s\t%-4d\t%-12s\t%-s\n", count, con.p[i].name, con.p[i].sex, con.p[i].age, con.p[i].tele, con.p[i].addr);
			list[count] = i;
			count++;
		}
	}
	if (count == 0)
	{
		printf("���޴���!\n");
		return NULL;
	}
	else
		return list;
}

//�޸���ϵ��
void change()
{
	//����
	printf("������Ҫ�޸���ϵ������:");
	//�޸�
	int* ret = find();
	if (ret != NULL)
	{
		printf("��������Ҫ�޸���ϵ�˵����:");
		int n = 0;
		scanf("%d", &n);
		//arr[list[n]]�޸�
		printf("�޸���ϵ��:>\n");
		printf("����������:");
		scanf("%s", ((con.p)[list[n]]).name);
		printf("�������Ա�:");
		scanf("%s", (con.p)[list[n]].sex);
		printf("����������:");
		scanf("%d", &(con.p[list[n]].age));
		printf("�������ֻ���:");
		scanf("%s", con.p[list[n]].tele);
		printf("������סַ:");
		scanf("%s", con.p[list[n]].addr);
		printf("�޸ĳɹ�.\n");

		//��ʼ��list[]
		int i = 0;
		for (i = 0; i < MAX_LIST; i++)
		{
			list[i] = 0;
		}
	}
}

//������������
void sort_name()
{
	int i = 0;
	for (i = 0; i < con.sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < con.sz - 1 - i; j++)
		{
			if (strcmp(con.p[j].name, con.p[j + 1].name) > 0)//����
			{
				peo_info tmp = con.p[j];
				con.p[j] = con.p[j + 1];
				con.p[j + 1] = tmp;
			}
		}
	}
}