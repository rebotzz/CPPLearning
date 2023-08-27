#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//归并排序,外排序练习

//生成一个大量数据文件
void CreatFile()
{
	//打开文件
	FILE* pf = fopen("BigData", "w");

	//写入
	for (int i = 100000; i >= 0; i--)
	{
		fprintf(pf, "%d\n", i);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

//大文件排序
void OutMergeSort(FILE* pf)
{

}

int main()
{
	//生成一个大量数据文件
	CreatFile();
	//打开文件
	FILE* pf = fopen("BigData", "r");

	//拆分文件,直到内存能容纳
	//假设拆分为10份
	int arr[10000] = { 0 };
	int i = 0;
	FILE* begin = pf;

	//fseek(pf, 0, SEEK_SET);
	//printf("%d\n", ftell(pf));
	////fseek(pf, 0, SEEK_END);
	//printf("%d\n", ftell(pf));

	while (fscanf(begin,"%d\n",&arr[i]	) != EOF)
	{
		//
		printf("%d\n", ftell(pf));
		system("pause");
		//fseek(pf, -1, SEEK_CUR);
		printf("%d\n", ftell(pf));

	}




	//归并排序


	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}