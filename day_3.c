#define _CRT_SECURE_NO_WARNINGS

//����Ŀ���ơ�
//�������
//����Ŀ���ݡ�
//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//����
#include <stdio.h>

////1.0
//void init(int arr[],int tmp[], int line)
//{
//	arr[0] = 1;
//	arr[line - 1] = 1;
//	int i = 0;
//	for (i = 1; i < line - 1; i++)
//	{
//		arr[i] = tmp[i - 1] + tmp[i];
//	}
//
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[100] = { 0 };
//	int tmp[100] = { 0 };
//	int* parr = arr;
//	int* ptmp = tmp;
//	int line = 0;
//	scanf("%d", &line);//��ӡ������
//	for (i = 0; i <= line; i++)
//	{
//		//�洢��һ�ε�ֵ
//		for (int n = 0; n < line; n++)
//		{
//			tmp[n] = arr[n];
//		}
//		for (int j = 0; j < i; j++)
//		{
//
//			init(arr, tmp, line);//��ʼ��arr
//			//��ӡǰ�ÿո�
//
//			//��ӡ�����������
//			printf("%2d ", arr[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//2.0	�����Ż�
void init(int arr[], int line)
{

}




//����Ŀ���ơ�
//������
//����Ŀ���ݡ�
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
#include <stdio.h>

//1.0
////�ĸ���
//int a = 0;
//int b = 1;
//int c = 2;
//int d = 3;
//
////����������
//int anwser(int arr[])
//{
//	int yes = 0;
//	if (arr[a] == 0)//A��
//		yes++;
//	if (arr[c] == 1)//B��
//		yes++;
//	if (arr[d] == 1)//C��
//		yes++;
//	if (arr[d] != 1)//D��
//		yes++;
//	return yes;
//}
//int main()
//{
//
//	int arr[4] = { 0 };
//	int truth = 0;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		arr[i] = 1;
//		
//		//����������
//		truth = anwser(arr);
//		if (truth == 3)//����Ϊ4,��������,����һ����.
//		{
//			switch (i)
//			{
//			case 0:
//				printf("A������.\n");
//				break;
//			case 1:
//				printf("B������.\n");
//				break;
//			case 2:
//				printf("C������.\n");
//				break;
//			case 3:
//				printf("D������.\n");
//				break;
//			}
//
//		}
//		//��Ϊ0
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			arr[j] = 0;
//		}
//	}
//	return 0;
//}

//2.0	�����Ż�
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)//���Ϊ��,����1,Ϊ�ٷ���0
//			printf("%c ������\n", killer);
//	}
//}