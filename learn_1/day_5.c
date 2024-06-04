#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//switch语句练习
int main()
{
	int n = 0;
	scanf("%d",&n);
	switch (n)
	{
	case 1:
		printf("上班");
		break;
	case 2:
		printf("加班");
		break;
	case 3:
		printf("换休假");
		break;
	case 4:
	case 5:
		printf("随机");
		break;
	case 6:
	case 7:
		printf("周末休息");
		break;
	default:
		printf("error,please enter 1~7.\n");
		//break;			//加上是个好习惯
	}
	//switch语句可以走出来，没有break;
	printf("out");
	return 0;
}


