#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//#define RES
#ifdef RES
int main()
{
	printf("hello \n");

	//�˳���
	for (int num = 0; num < 45; num++)
	{
		printf("%d: %s\n", num, strerror(num));
	}

	//��������,�˳���û������,���ǰ�������ִ�е���ȷ�˳���λ��
	//�������к�,��ɽ���,�ɲ���ϵͳOS����,OSɱ������,ͨ���ź�

	return 0;
}
#endif