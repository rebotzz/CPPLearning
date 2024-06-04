#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


//�˵�
void menu()
{
	printf("**************************\n");
	printf("********   ɨ��    *******\n");
	printf("********  1.play   *******\n");
	printf("********  0.exit   *******\n");
	printf("**************************\n");

}

//���̳�ʼ��
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ------------\n");
	for (j = 0; j <= col; j++)//��ӡ�к�
	{
		//printf("%c ", j + '0');
		printf("%-2d ", j);//��ӡ������,���ı�ԭ������,�����������Ϊ ���� ,���� �ַ���
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%-2d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			int jump = 0;//������������ forѭ�� 
			//�������
			for (int k = 0; k < mark_; k++)
			{
				if ((i == mark[k][0]) && (j == mark[k][1]) && (arr[i][j] == '*'))
				{
					printf_red("*  ");
					jump = 1;
					continue;
				}
			}

			if (jump == 1)
			{
				jump = 0;//��ԭ
				continue;
			}
			//��ͬ������Ŀ�ĸ����ò�ͬ��ɫ��ӡ
			if (arr[i][j] == '1')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };//������printf_green����һ��.32Ϊ�ո��ASCII��ֵ,��ʵҲ������' ',�������û���
				printf_green(tmp);
				continue;
			}
			if (arr[i][j] == '2')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_blue(tmp);
				continue;
			}
			if (arr[i][j] == '3')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_yellow(tmp);
				continue;
			}
			if (arr[i][j] > '3')
			{
				char tmp[4] = { arr[i][j],32,32,'\0' };
				printf_red(tmp);
				continue;
			}
			printf("%c  ", arr[i][j]);
		}
		//�������������ӡ,ʣ�µ�������ӡ
		printf("\n");
	}
	printf("----------ɨ����Ϸ------------\n");

}

//���õ���
//debug: board[][COLS],���ﲻ���� COL ,�������� 
void SetMine(char board[ROWS][COLS], int row, int col) 
{
	//������
	int x = 0;
	int y = 0;
	//������
	int count = easy_count;
	while (count)
	{
		//�������Χ, 1 ~ row
		x = rand() % row + 1;
		y = rand() % col + 1;
		//�ж�����Ϸ���
		if (board[x][y] == '0')//�������Χ������ x >= 1 && x <= row && y >= 1 && y <= col && 
		{
			board[x][y] = '1';
			count--;
		}
	}

}

//ɨ��
void FindMine(char board[ROWS][COLS], int row, int col)//board[ROWS][COLS] Ӧ���൱��ָ�����
{
	//���׸�����Ŀ
	int all_count = ROW * COL - easy_count;
	int count = 1;
	while (count < all_count)	//�����ʼֻ�� 1 �����׸���,����©��,ͨ��
	{
		int x = 0;
		int y = 0;
		int z = 0;
		//��ջ�������������
		clear();
		printf("��ѡ������:> 1.ɨ������  2.�������  3.ȡ���ϴα��  4.ȡ��ĳ����\n");
		scanf("%d", &z);
		switch(z)
		{
		case 1:
			//��ջ�������������
			clear();
			printf("����ɨ������:>\n");
			scanf("%d %d", &x, &y);
			//��������Ϸ��Լ��
			if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
			{
				//����,��ը��,��Ϸ����
				if (board[x][y] == '1')
				{
					printf_red("���ź�,�㱻ը����,����ʧ��.\n");
					goto lable;
					break;
				}
				//����,��ʾ��������,��Ϸ����
				if (board[x][y] == '0')
				{
					//��ʾ��������
					CountMine(board, x, y, ROW, COL);//�׵�����

					DisplayBoard(show, ROW, COL);//��ӡ����
					//�����׸�����Ŀ
					count = CheckMine(show, ROW, COL);
				}
			}
			else
			{
				printf("�������,����������.\n");
			}
			break;
		
		case 2:
			printf("����������:>\n");
			scanf("%d %d", &x, &y);
			//��������Ϸ��Լ��
			if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
			{
				//����������
				mark[mark_][0] = x;
				mark[mark_][1] = y;
				mark_++;
				DisplayBoard(show, ROW, COL);//��ӡ����
			}
			else
			{
				printf("�������,����������.\n");
			}
			break;

		case 3:
			if (mark_ <= 0)
			{
				printf("�Ѿ�û�б��\n");
				break;
			}
			printf("ȡ����һ�α��:>\n");
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
			DisplayBoard(show, ROW, COL);//��ӡ����
			break;

		case 4:
			//����������
			printf("����������ı������:>\n");
			int x0 = 0;
			int y0 = 0;
			scanf("%d %d", &x0, &y0);
			//��������Ϸ��Լ��
			if (x0 >= 1 && x0 <= row && y0 >= 1 && y0 <= col && show[x0][y0] == '*')
			{
				int i = 0;
				for (i = 0; i < mark_; i++)
				{
					if ((mark[i][0] == x0) && (mark[i][1] == y0))//���������������ǰŲ��,���Ǵ�����
					{
						memmove(&(mark[i][0]), &(mark[i + 1][0]), (mark_ - 1 - i) * sizeof(mark[0]));//mark[0]�൱������Ԫ����,sizeof(mark[0])���д�С
						mark_--;
						break;
					}
				}
					DisplayBoard(show, ROW, COL);//��ӡ����
			}
			else
			{
				printf("�������,����������.\n");
			}
			break;

		default:
			printf("�������,����������.\n");
		}
	
	}
	if (count == all_count)
	{

		end = time(NULL);//����ʱ��
		unsigned int time = (unsigned int)difftime(end,start);//�����ʱ /��
		printf_green("��ϲ��,��Ϸͨ��!(��������)��\n");
		printf("\033[0m\033[1;32m���ܹ���ʱ: %d ��\033[0m\n",time);
		//����洢�ı������
		while (mark_)
		{
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
		}

	}
lable:
	if (count < all_count)
	{
		end = time(NULL);//����ʱ��
		unsigned int time = (unsigned int)difftime(end, start);//�����ʱ /��
		printf("\033[0m\033[1;31m��ķ���: %d ��\033[0m\n", time);
		//����洢�ı������
		while (mark_)
		{
			mark[mark_][0] = 0;
			mark[mark_][1] = 0;
			mark_--;
		}
	}

}

//��ʾ��������
void CountMine(char board[ROWS][COLS], int x, int y,int row,int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{	//&& (i !=0 || j !=0)��ʡ��,��Ϊ�����������ײ��ܽ�����һ��
			if (board[x+i][y+j] == '1' && (i !=0 || j !=0) )//&& (i !=0 || j !=0)����:i,j��ͬʱΪ 0
			{
				count++;
			}
		}
	}
	//����(x,y)������Χ������
	//show[x][y] = 1+ count + '0';//char����,���� int ,����ASCII��ת��	+1֤�����������
	show[x][y] = count + '0';	//���� +1 ֤��,��Ϊԭ��ֵ '*' ,���� '0'
	//һ����Ҳû��,��ըʽչ��
	if (count == 0)
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{	
				//ע��:������·��ըչ��,��ֹջ���  && show[x + i][y + j] == '*'  ,������ '*' ,����չ�����ĵط�
				//��ըչ���߽�	&& x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col
				if (x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col && show[x + i][y + j] == '*')
					CountMine(board, x + i, y + j, row, col);
			}
		}
	}

	//show[x][y] =count + '0' -1;	// -1��ԭ����

}


//�����׸�����Ŀ
int CheckMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] != '*')
				count++;
		}

	}
	return count;
}


//��ɫ��ӡ����
//��ʽ \033[��������m    ��������;ǰ��ɫ;��ɫ
// 0 ���� 1 ����
//ǰ��ɫ 31 �� 32 �� 33 �� 34 ��
//��ɫ 40 �� 41 ��
void printf_red(char* s)
{
	printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(char* s)
{
	printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(char* s)
{
	printf("\033[0m\033[1;33m%s\033[0m", s);
}

void printf_blue(char* s)
{
	printf("\033[0m\033[1;34m%s\033[0m", s);
}


//��ջ�������������
void clear()
{
	//��̰���ߴ�����ѧ����˼·
	//�����ƺ��𲻵�Ԥ��Ч��
	fflush(stdin);
	//gets();//�Ƕ�ȡһ��,�������ַ���ָ��,Ҳ�ﲻ��Ԥ��Ч��;ͬ��,getchar(),_getch()Ҳ�ﲻ��Ԥ��Ч��.
	
}