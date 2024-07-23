#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//归并排序,外排序练习

//生成一个大量数据文件
void CreatFile()
{
	//打开文件
	FILE* pf = fopen("BigData", "w");

	//写入
	for (int i = 1005; i >= 0; i--)
	{
		fprintf(pf, "%d\n", i);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

//文件归并排序子程序:从fout1,fout2文件读取数据,一边读取一边顺序写入tmp文件
void _OutMergeSort(char* fout1, char* fout2, char* tmp)
{
	FILE* f1 = fopen(fout1, "r");
	FILE* f2 = fopen(fout2, "r");
	FILE* f3 = fopen(tmp, "w");

	//因为文件指针自动向前,不能直接用fscanf()的返回值判断文件是否结束
	// (直接用可能导致文件指针前移,但上次读取数据还未使用就被覆盖)
	//将fscanf()的返回值存入ret,利用ret判断,能有效控制文件指针移动
	//解决一个文件中数据都比另一个文件小,文件指针不好控制问题
	int num1, num2;
	int ret1 = fscanf(f1, "%d\n", &num1);
	int ret2 = fscanf(f2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(f3, "%d\n", num1);
			ret1 = fscanf(f1, "%d\n", &num1);
		}
		else
		{
			fprintf(f3, "%d\n", num2);
			ret2 = fscanf(f2, "%d\n", &num2);
		}
	}

	//另一个文件剩下的数据
	while (ret1 != EOF)
	{
		fprintf(f3, "%d\n", num1);
		ret1 = fscanf(f1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(f3, "%d\n", num2);
		ret2 = fscanf(f2, "%d\n", &num2);
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
}


//(大)文件排序
void OutMergeSort(FILE* pf)
{
	//拆分文件,直到内存能容纳
	//假设拆分为10份
	int arr[100] = { 0 };//拆分后存入内存
	int i = 0;
	int n = 100; //分割后的每个文件存储n=100个数据
	char* fname[20];//分割后文件名
	int fileid = 1;	//分割后文件id序号

	while (fscanf(pf, "%d\n", &arr[i]) != EOF)
	{
		if (i < n - 1)//[0 ~ n-2] 共n-1个数字;解决最后一个数据的存储问题
		{					//(最后一次判断fscanf()!= EOF又存入了一个数)		
			i++;
		}
		else
		{
			i++;  //i == n
			//将分割后的文件排序:快速排序
			QuickSort(arr, 0, n - 1);
			//创建文件存储分割后的数据
			sprintf(fname, "%d", fileid++);
			//创建文件:打开,写入,关闭
			FILE* fin = fopen(fname, "w");
			for (int j = 0; j < i; j++)
			{
				fprintf(fin, "%d\n", arr[j]);
			}
			fclose(fin);

			//初始化i
			i = 0;
		}
	}

	//当最后数据不足n个时:
	//这里不用i++;最后一次读取似乎无意义,==EOF是情况,越界
	sprintf(fname, "%d", fileid++);
	QuickSort(arr, 0, i - 1);
	FILE* fin = fopen(fname, "w");
	for (int j = 0; j < i; j++)
	{
		fprintf(fin, "%d\n", arr[j]);
	}
	fclose(fin);

	//归并排序
	//将1,2文件归并为tmp
	//直到归并到最后一个文件
	char* fout1[20];	//文件名
	char* fout2[20];
	char* tmp[20];
	sprintf(fout1, "%d", 1);
	sprintf(fout2, "%d", 2);
	sprintf(tmp, "1_%d.tmp", 2);

	FILE* f1 = fopen(fout1, "r");	//文件指针名字
	FILE* f2 = fopen(fout2, "r");
	FILE* f3 = fopen(tmp, "w");		//写
	_OutMergeSort(fout1, fout2, tmp);//归并排序
	fclose(f1);
	fclose(f2);
	fclose(f3);
	f1 = f2 = f3 = NULL;

	//依次归并,直到分割的最后一个文件
	for (int i = 3; i < fileid; i++)
	{
		sprintf(fout1, tmp);	//将上一次归并后的文件作为这一次归并的两个文件之一
		sprintf(fout2, "%d", i);
		sprintf(tmp, "1_%d.tmp", i);//新创建一个文件,用于存放归并后的数据
		_OutMergeSort(fout1, fout2, tmp);//归并排序
	}
}

int main()
{
	//生成一个大量数据文件
	CreatFile();

	//打开文件
	FILE* pf = fopen("BigData", "r");

	//排序文件
	OutMergeSort(pf);

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}