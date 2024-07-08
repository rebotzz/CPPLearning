#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//#define RES
#ifdef RES
int main()
{
	printf("hello \n");

	//退出码
	for (int num = 0; num < 45; num++)
	{
		printf("%d: %s\n", num, strerror(num));
	}

	//程序奔溃后,退出码没有意义,不是按照正常执行到正确退出码位置
	//程序运行后,变成进程,由操作系统OS管理,OS杀掉进程,通过信号

	return 0;
}
#endif