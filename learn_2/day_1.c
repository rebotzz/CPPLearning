#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////����д�Ĵ��룬�����Ż�
////��д���룬��ʾ����ַ��������ƶ������м��ۡ�
//int main()
//{
//	char arr1[] = "welcome to night city";
//	char arr2[] = "#####################";
//	int lenth = sizeof(arr1) / sizeof(arr1[0]);
//	float mid = (lenth - 1) / 2.0;
//	int left = 0;
//	int right = lenth - 2;
//	printf("%s\n", arr2);
//	printf("���»س��鿴��������:>");
//	getchar();						//���س���ż���
//
//	for (int i = left; i < mid; i = i + 1)
//	{
//		//��ӡ���
//		int a = 0;
//		while (a <= i)
//		{
//			printf("%c", arr1[a]);
//			a++;
//		}
//		//��ӡ�м�
//		for (int j = i + 1; j < right - i; j++)
//		{
//			printf("%c", arr2[j]);
//		}
//		//��ӡ�Ҷ�
//		a = i;						//��ʼ�������治ͬ��ȷ����ӡ��ĸ˳��
//		while (a >= 0)
//		{
//			printf("%c", arr1[right - a]);
//			if (i == right - a)		//������һ���м��ַ��ظ���ӡ
//				printf("\b");
//			a--;
//		}
//		//printf("\n");
//		getchar();					//���س���ż���
//
//	}
//	return 0;


	
////��д���룬��ʾ����ַ��������ƶ������м��ۡ�	�����Ż�1.0		��̬���룡������Ү
//#include <string.h>			//strlen �������ÿ�
//#include <windows.h>		//Sleep  system("cls") ��������
//int main()
//{
//	char arr1[] = "welcome to night city.";
//	char arr2[] = "######################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	//չʾЧ���Ż�
//	printf("%s", arr2);
//	getchar();
//	system("cls");	//�����Ļ
//
//
//	//����
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//
//		//չʾЧ���Ż�
//		Sleep(500);		//��ʱ ��λ ����
//		system("cls");	//�����Ļ
//
//
//	}
//	return 0;
//}



////��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�
////ֻ���������������룬���������ȷ����ʾ��¼�ɣ�������ξ�����������˳�����
//int main()
//{
//	char password1[20] = { 0 };		//��������
//
//	//char password2[] = { '1','2','3','4','5','6' };
//	//int right = sizeof(password2)/sizeof(password2[0]) - 1;		
//	////�����ܽ�
//	////�����󳤶Ȳ����� strlen ,��Ϊ���ﲻ���� " " д���ַ����������� {'',''} д��
//
//	//����
//	char password2[] = "123456";	//��ʵ����
//	int right = strlen(password2) - 1;
//
//	//���ۣ� strlen �� "" �ַ����ȣ� sizeof(����)/sizeof(Ԫ��) ��  {''} ���鳤�ȣ�
//	//��������� ��������\0�� �йأ�""��ĩβĬ����ӡ�\0��;
//
//	int times = 3;
//
//
//	printf("����������:>");
//	scanf("%s", password1);			//�������������ǵ�ַ������ &
//	
//
//	int i = 0;
//	while (i <= right )
//	{
//		if (password1[i] == password2[i])
//		{
//			i++;
//			if (i > right)
//			{
//				printf("��������ɹ���\n");
//				break;
//			}
//		}
//		else
//		{
//			times--;
//			printf("�����������ʣ�������%d\n",times );
//			if (times == 0)
//			{
//				printf("���Ѿ����3�Σ������˳���");
//				break;
//			}
//			scanf("%s", password1);
//			
//		}
//		
//	}
//
//
//
//	return 0;
//}


////��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�
////ֻ���������������룬���������ȷ����ʾ��¼�ɣ�������ξ�����������˳�����
////�����Ż�1.0			   strcmp(  ,  ) �ַ����ȽϺ���,����ֵΪ int
//#include <string.h>		//strcmp �⺯��
//
//int main()
//{
//	int password[20] = { 0 };
//	printf("����������:>");
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		//������ȷ����Ϊ123456
//		if (strcmp(password, "123456") == 0)	//����ͬ,����ֵΪ 0
//		{
//			printf("����������ȷ,��¼�ɹ�!\n");
//			break;
//		}
//		else
//		{
//			printf("�����������,����������:\n");
//		}
//	}
//	if (3 == i)
//	{
//		printf("�������3��,�����˳�!");
//	}
//	return 0;
//}


////��������Ϸ
////Ҫ��:1.����һ��1-100֮��������
////	   2.������²���˻���С��
////	   3.�и��˵�����
//#include <stdlib.h>		//rand	srand
//#include <time.h>		//time
//
//int ret = 0;			//ȫ�ֱ���
//int enter = 0;
//
//
//void menu()
//{
//	printf("######### ������ #########\n");
//	printf("##########################\n");
//	printf("#########1. play##########\n");
//	printf("#########0. exit##########\n");
//	printf("##########################\n");
//}
//
//
//void game()
//{
//	printf("��Ϸ��ʼ\n");
//	printf("��������²������:");
//
//	while (1)
//	{
//		scanf("%d", &enter);
//		if (enter < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (enter > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���!\n");
//			break;
//		}
//
//	}
//
//}
//
//int main()
//{
//	int choose = 0;
//	//����һ��α�����  0 - 100
//	srand((unsigned int)time(NULL));			//����ʱ�� α�������ʼ��
//	
//	do
//	{
//		menu();
//		scanf("%d", &choose);
//		ret = rand() % 100 + 1;					//rand() ���ɷ�Χ 0 - 32767  ---->ӳ��Ϊ 0 - 100
//		switch (choose)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�������,����������!\n");
//			break;
//		}
//
//	} while (choose);
//	
//
//	return 0;
//}


////��������Ϸ							�汾����2.0
////Ҫ��:1.����һ��1-100֮��������
////	   2.������²���˻���С��
////	   3.�и��˵�����
//#include <stdlib.h>		//rand	srand
//#include <time.h>		//time
//
//int ret = 0;			//ȫ�ֱ���
//int enter = 0;
//int choose2 = 0;
//int m = 0;
//
//void menu1()
//{
//	printf("#########������2.0#########\n");
//	printf("###########################\n");
//	printf("#########1.  play##########\n");
//	printf("#########0.  exit##########\n");
//	printf("###########################\n");
//}
//
//void menu2()
//{
//	printf("########��ѡ���Ѷ�########\n");
//	printf("#########0. ��##########\n");
//	printf("#########1. ����##########\n");
//	printf("#########2. ����##########\n");
//	printf("##########################\n");
//}
//
//
//void game()
//{
//	printf("��Ϸ��ʼ\n");
//	printf("���ܹ����Բ²� %d ��\n",m);
//	printf("��������²������:");
//	int i = 0;
//	for(i = 0; i <m; i++)
//	{
//		scanf("%d", &enter);
//		if (enter < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (enter > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���!\n");
//			break;
//		}
//
//	}
//	if(i == m)
//		printf("��Ϸʧ��\n");
//
//}
//
//int main()
//{
//	int choose1 = 0;
//
//	//����һ��α�����  0 - 100
//	srand((unsigned int)time(NULL));			//����ʱ�� α�������ʼ��
//
//	do
//	{
//		menu1();
//		scanf("%d", &choose1);
//		ret = rand() % 100 + 1;					//rand() ���ɷ�Χ 0 - 32767  ---->ӳ��Ϊ 0 - 100
//		switch (choose1)
//		{
//		case 1:
//			menu2();
//			scanf("%d", &choose2);
//			switch (choose2)
//			{
//			case 0:
//				m = 20;
//				game();
//				break;
//			case 1:
//				m = 10;
//				game();
//				break;
//			case 2:
//				m = 6;
//				game();
//				break;
//			default:
//				printf("�������,����������!\n");
//				break;
//			}
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�������,����������!\n");
//			break;
//		}
//
//	} while (choose1);
//
//
//	return 0;
//}

//���

//git �ϴ���������ʱ�е�����?	ʧ��,����?