#define _CRT_SECURE_NO_WARNINGS

//��������Ϸ		�ִ���bug,���������������ַ������ƺ���ѭ��		�汾����3.0
//Ҫ��:1.����һ��1-100֮��������
//	   2.������²���˻���С��
//	   3.�и��˵�����
#include <stdio.h>			//������
#include <stdlib.h>			//rand	srand
#include <time.h>			//time
#include <string.h>			//strlen �������ÿ�
#include <windows.h>		//Sleep  system("cls") ��������

int ret = 0;			//ȫ�ֱ���
int enter = 0;
int choose2 = 0;
int m = 0;

//��̬����,����ַ��������ƶ������м��ۡ�
void cover()
{
	char arr1[] = "welcome to this little game!";
	char arr2[] = "############################";
	int left = 0;
	int right = strlen(arr1) - 1;

	//չʾЧ���Ż�
	printf("%s\n", arr2);
	printf("���س�������:>");
	getchar();
	system("cls");	//�����Ļ


	//��������
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);

		//չʾЧ���Ż�
		Sleep(300);		//��ʱ ��λ ����
		system("cls");	//�����Ļ

	}
	printf("%s", arr1);
	Sleep(1000);
	getchar();
	system("cls");
}


//�˵�1
void menu1()
{
	printf("#########������3.0#########\n");
	printf("###########################\n");
	printf("#########0.  exit##########\n");
	printf("#########1.  play##########\n");
	printf("#########2. others#########\n");
	printf("###########################\n");
}

//�˵�2
void menu2()
{
	printf("########��ѡ���Ѷ�########\n");
	printf("#########0. ��##########\n");
	printf("#########1. ����##########\n");
	printf("#########2. ����##########\n");
	printf("#########3. ����##########\n");
	printf("##########################\n");
}

//��Ϸ����
void game()
{
	printf("��Ϸ��ʼ\n");
	printf("���ܹ����Բ²� %d ��\n", m);
	printf("��������²������:\n");
	int i = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &enter);
		if (enter < ret)
		{
			printf("��С��\n");
		}
		else if (enter > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("�¶���!\n");
			Sleep(1000);
			getchar();
			system("cls");
			break;
		}

	}
	if (i == m)
	{
		printf("��Ϸʧ��\n");
		if (choose2 == 3)
		{
			printf("ѡ������Ѷ�,�������!\n");
			printf("����,��ʧ����,���ܳͷ���!\n");
			printf("��ĵ��Խ�����60���ڹػ�,�ݰ�������\(�����*\))");
			system("shutdown -s -t 60");
		}
	}

}

int main()
{
	int choose1 = 0;
	//����һ��α�����  0 - 100
	srand((unsigned int)time(NULL));			//����ʱ�� α�������ʼ��

	cover();

	do
	{
		menu1();
		scanf("%d", &choose1);
		ret = rand() % 100 + 1;					//rand() ���ɷ�Χ 0 - 32767  ---->ӳ��Ϊ 0 - 100
		switch (choose1)
		{
		case 1:
			menu2();
			scanf("%d", &choose2);
			switch (choose2)
			{
			case 0:
				m = 20;
				game();
				break;
			case 1:
				m = 10;
				game();
				break;
			case 2:
				m = 6;
				game();
				break;
			case 3:
				m = 6;
				printf("ע��:���ģʽ�гͷ�����.\n");
				game();
				break;
			default:
				printf("�������,����������!\n");
				while (1)
				{
					int abd = 0;
					if ((abd = getchar()) != '\n')
						;
					else
						break;
				}
				break;
			}
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 2:
			printf("�����������ߵ�һЩ��:\n");
			getchar();
			printf("���С��Ϸ��������һ��galgame�����,��Ů�����ĵĲ�����.\n");
			printf("������Ȥ����Ϸ,����,�ʺ�ѧϰ.\n");
			printf("���,ϣ��������������ݵ���Ϸ,лл.\n");
			getchar();
			printf("С����:�ڵ����Ѷȿ�Ҫ���ʱ,�رճ���,�Ͳ���ִ�йػ�����.����������J��");
			getchar();
			system("cls");
			break;
		default:
			printf("�������,����������!\n");
			while (1)
			{
				int abd = 0;
				if ((abd = getchar()) != '\n')
					;
				else
					break;
			}
			break;
		}

	} while (choose1);


	return 0;
}