#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////�ۿ۷Ѽ���
//int main()
//{
//	float zhekf = 0;
//	float value = 0;
//	float feip = 0;
//	float year = 0;
//	printf("���������룺����۸� ��Ʒ�۸� ʹ������\n");
//	scanf("%f %f %f",&value,&feip,&year);
//	zhekf = (value - feip) / year;
//	printf("�ۿ۷�:%0.2f",zhekf);
//	return 0;
//}


//���㻹����
//int main()
//{
//	float daikun_v = 20000.00;        //������
//	float intreset_year = 0.06;			//������
//	float month_huanqian = 386.66;		//ÿ���»�����
//	float shengyu_v[12] = { 0 };		//��i+1����ʣ����軹���
//	float in_month = intreset_year / 12;//������
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (i == 0)
//		{
//			shengyu_v[i] = daikun_v * (1 + in_month) - month_huanqian;
//			printf("��%d����ʣ����軹��%0.2f\n",(i + 1),shengyu_v[i]);
//		}
//		else
//		{
//			shengyu_v[i] = shengyu_v[(i - 1)] * (1 + in_month) - month_huanqian;
//			printf("��%d����ʣ����軹��%0.2f\n", (i + 1), shengyu_v[i]);
//
//		}
//	}
//	return 0;
//}