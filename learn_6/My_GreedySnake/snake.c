#define _CRT_SECURE_NO_WARNINGS

#include "snake.h"

//ȫ�ֱ���
snake_info snake;//�ߵĲ���
food_info food;	 //ʳ������
int changeflag = 0;	//�Ƿ�Ե�ʳ���־
int liveflag = 1;	//����־
int key = 77;		//���ҷ������Ӧ��ֵ77,��ʼĬ������
int score = 0;		//�÷�
int score_list[MAX_SCORE_LINE] = { 0 };	//�������а�,����ǰMAX_SCORE_LINEλ��߷�		60,10,80,30,10,50


//����ƶ�		����ƶ���Ĵ�ӡ,Ч���ƺ��Ǵ�ӡ����
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//��windows����й�,��ʱ������
}

//��ӡ�˵�
void meum()
{
	printf("********************************************\n");
	printf("*************      ̰����        ***********\n");
	printf("*************  1.play   0.eixt   ***********\n");
	printf("*************  2.tips   3.others ***********\n");
	printf("********************************************\n");
}

//��ӡ�������а�
void print_score()
{
	int i = 0;
	int j = 1;
	//��ӡ���а����
	gotoxy(MAPWIDTH + 4, 2);
	printf("���а�:");
	for (i = MAX_SCORE_LINE - 1; i >= 0; i--)
	{
		gotoxy(MAPWIDTH + 4, 2+j);
		printf("%d", j);
		gotoxy(MAPWIDTH + 12, 2+j);
		printf("%d", score_list[i]);
		j++;
	}
}


//��Ϸ��ʼ��: ��ͼ����,��ʼ������,��ʼʳ������
void InitGame()
{
	//������뻺����
	fflush(stdin);
	//��ͼ����
	int i = 0;
	for (i = 0; i < MAPWIDTH; i += 2)//���һ����ӡ���±߿� ==> һ�����г��� == ����ˮƽ�ո�
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, MAPHIGHT);
		printf("��");
	}
	for (i = 0; i <= MAPHIGHT; i++)//��ӡ���ұ߿�
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(MAPWIDTH, i);
		printf("��");
	}

	//��ʼ������	λ�÷����м�,����Ϊ3
	snake.len = 3;//����
	snake.speed = 200;//��ʼ�ٶ�
	//��ͷ
	snake.x[0] = MAPWIDTH / 2 +1;	//ż��
	snake.y[0] = MAPHIGHT / 2;	//����
	//������
	for (i = 1; i < snake.len; i++)
	{
		snake.x[i] = MAPWIDTH / 2 - i * 2;//2 * i��Ҫ��? ��Ҫ,һ�����г��� == ����ˮƽ�ո�	
		snake.y[i] = MAPHIGHT / 2;	
	}
	//��ӡ
	for (i = 0; i < snake.len; i++)
	{
		gotoxy(snake.x[i], snake.y[i]);
		printf("��");
	}

	//��ʼʳ������
	CreatFood();

	//��ӡ�÷ֽ���
	gotoxy(MAPWIDTH + 4, 0);
	printf("score:");
	gotoxy(MAPWIDTH + 12, 0);
	printf("%d", score);

	//��ӡ�������а�
	print_score();


	//������ƶ������Ͻ�����
	gotoxy(MAPWIDTH - 2, 0);

	//��ʼ״̬
	changeflag = 0;//û�Ե�ʳ��
	liveflag = 1;	//������
}

//����������,�ı�ǰ������
void KeyInput()
{
	int pre_key = key;//��¼��һ�����뷽��
	//����Ƿ��м�������
	if (_kbhit())
	{
		//�������Ϸ�����������

		key = _getch();	//������᷵��������ֵ,��һ��224
		key = _getch();	//�ڶ��η����Ӧ��ֵ

		//������뻺����
		fflush(stdin);

		//�������겻����ԭ�����෴,�෴���򲻱�
		if (key == 72 && pre_key == 80)//��
			key = pre_key;
		if (key == 80 && pre_key == 72)//��
			key = pre_key;
		if (key == 75 && pre_key == 77)//��
			key = pre_key;
		if (key == 77 && pre_key == 75)//��
			key = pre_key;
	}

		//�������	
		//1.�ж��Ƿ���Ҫ����β�������ӡ
		if (changeflag == 0)
		{
			gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
			printf(" ");//����ԭ�д�ӡ,ģ����ǰ�ƶ�Ч��
		}

		//2.�����������������,�����µ�ͷ������ռ�. ����ģ����ƶ�Ч��,ҲҪ��¼�ߵ�����,���������ж�	�������겻��Ҫ��ӡ
		int i = 0;
		for (i = snake.len - 1; i > 0; i--)
		{
			snake.x[i] = snake.x[i - 1];
			snake.y[i] = snake.y[i - 1];
		}

		//3.��ͷ�������Ϊ������	ֻ�ô�ӡͷ����ȥ��β��,�м䱣��,����ʵ���ƶ����Ӿ�Ч��
		if (key == 72)//��
		{
			snake.y[0]--;
		}
		if (key == 80)//��
		{
			snake.y[0]++;
		}
		if (key == 75)//��
		{
			snake.x[0] -= 2;//�ƶ�������λ
		}
		if (key == 77)//��
		{
			snake.x[0] += 2;//�ƶ�������λ
		}
		//��ӡͷ��
		gotoxy(snake.x[0], snake.y[0]);
		printf("��");

	//״̬����
	changeflag = 0;//Ŀǰû�Ե�ʳ��
	liveflag = 1;	//Ŀǰ������

	//������ƶ������Ͻ�����
	gotoxy(MAPWIDTH - 2, 0);
}


//����Ƿ�Ե�ʳ��,�Ƿ���Ҫ����ʳ��
void IsGetFood()
{
	//ͷ����ʳ�������Ƿ��ص�
	if ((food.x == snake.x[0]) && (food.y == snake.y[0]))
	{
		//�Ե�ʳ��,��Ҫ�����µ�ʳ��
		CreatFood();

		//����+1,�Ե�ʳ���־�ı�,�ٶȼӿ�,��������
		snake.len++;
		changeflag = 1;
		snake.speed -= 5;
		score += 10;

		//��ӡˢ�º�÷�
		gotoxy(MAPWIDTH + 12, 0);
		printf("%d", score);
	}

}

//����ʳ��
void CreatFood()
{
	int i = 0;
	srand((unsigned int)time(NULL));//�������
	while (1)
	{
		food.x = rand() % (MAPWIDTH - 4) + 2;
		food.y = rand() % (MAPHIGHT - 2) + 1;

		//��Ϊһ�����г��� == ����ˮƽ�ո�,Ϊ�˳������,x��ʳ����żҪ��ͬ,�����������������ص�,���Ե�
		//�ж�����Ϸ���
		int flag = 1;
		for (i = 0; i < snake.len; i++)//���������ص�
		{
			if ((snake.x[i] == food.x) && (snake.y[i] == food.y))
			{
				flag = 0;
			}
		}
		if ((food.x % 2 == 0) && (flag == 1))//��ͷx��ż��λ,����ʳ��x����������λ��
			break;
	}
	//��ӡʳ��
	gotoxy(food.x, food.y);
	printf("��");
}


//����Ƿ���
int IsLive()
{
	//ͷ�������Ƿ���ǽ�ص�,
	if ((snake.x[0] == 0) || (snake.x[0] == MAPWIDTH) || (snake.y[0] == 0) || (snake.y[0] == MAPHIGHT))
	{
		return DIE;
	}
	int i = 0;
	//ͷ�������Ƿ��������ص�
	for (i = 1; i < snake.len; i++)
	{
		if ((snake.x[0] == snake.x[i]) && (snake.y[0] == snake.y[i]))
		{
			return DIE;
		}
	}
	return LIVE;
}

//qsort���õ��� int ��С�Ƚ�
int cmp_int(void* e1, void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

//������ְ�,����
void score_sort(int* arr,int sz)
{
	//��������,����ʱ�临�Ӷȱ�ð�������Щ
	qsort(arr, sz, sizeof(int), cmp_int);

}


//���ļ�,��ȡ���ּ�¼
void read_file()
{
	int flag = 1;
	//���ļ�	R
	FILE* pf = fopen("score_list.txt","r");
	if (pf == NULL)
	{
		flag = 0;
		pf = fopen("score_list.txt", "w");
		if (pf == NULL)
		{
			perror("create and read score_list.txt failed.");
			return;
		}
	}
	//�ļ�����
	if (flag == 1)
	{
		int i = 0;
		for (i = 0; i < MAX_SCORE_LINE; i++)
		{
			fscanf(pf, "%d\n", &score_list[i]);
		}

	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//�˳���Ϸ,������ּ�¼
void exit_save()
{
	//���ļ�	W
	FILE* pf = fopen("score_list.txt", "w");
	if (pf == NULL)
	{
		perror("save score_list failed.");
		return;
	}
	//��������
	int i = 0;
	for (i = 0; i < MAX_SCORE_LINE; i++)
	{
		fprintf(pf, "%d\n", score_list[i]);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


//��ʾ
void tips()
{
	int tmp = 0;
	printf("��ʵ�����Ϸû����ʾ,��Ϊ���ּ�.\n");
	tmp = getchar();
	tmp = getchar();
	printf("���û����ʾ.\n");
	tmp = getchar();
	printf("û��,����û��.\n");
	tmp = getchar();
	printf("������������ȥҲû��.\n");
	tmp = getchar();
	printf("...\n");
	tmp = getchar();
	printf("......\n");
	tmp = getchar();
	printf("�����ڻ�û��������meta��Ϸ,��������û�вʵ�,��Ǹ.\n");
	tmp = getchar();
	printf("����,���������meta��Ϸ�Ļ�,������һ���Ƽ�.\n");
	tmp = getchar();
	printf("��Ϸ��:There is no game.\n");
	tmp = getchar();
	printf("��Ϸ����,�������ܿ��ܻ���Щ����.\n");
	tmp = getchar();
	printf("ͨ�صĸо���������.\n");
	tmp = getchar();
	printf("����,������,���û����ʾ.\n");
	tmp = getchar();
	printf("Tips:����������ʲô���ܿ��Ը�������,���Ҳ�һ����.\n");
	tmp = getchar();
	system("cls");
}

//����,���ߵĻ�
void others()
{
	int tmp = 0;
	printf("д�����Ϸ������:\n");
	tmp = getchar();
	tmp = getchar();
	printf("�ҿ�������ѧ��C���Կ���д�����Ϸ.\n");
	tmp = getchar();
	printf("Ȼ��,������ѧ��,�㶮��,�Ҿ�����һ��.\n");
	tmp = getchar();
	printf("Ȼ����һ�±��˷��Ĳ���,����һ���߼�.\n");
	tmp = getchar();
	printf("Ȼ��ʼдbug...\n");
	tmp = getchar();
	printf("Ȼ���bug......\n");
	tmp = getchar();
	printf("Ȼ���д����.\n");
	tmp = getchar();
	printf("���,��л�������,лл.[]~(������)~*\n");
	tmp = getchar();
	system("cls");

}