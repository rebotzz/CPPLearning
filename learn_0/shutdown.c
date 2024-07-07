//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <string.h>
////
////int main()
////{
////	int i = 1;
////	while (1)
////	{
////		scanf("%d", &i);
////		if (i)
////		{
////			system("shutdown -a");
////			printf("已取消关机\n");
////		}
////		if (i == 0)
////		{
////			printf("系统将于1分钟后关机!\n");
////			system("shutdown -s -t 60");
////		}
////	}
////	return 0;
////}
//
//
//void main()
//{
//	char arr1[] = "welcome to this little game!";
//	char arr2[] = "############################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	//展示效果优化
//	printf("%s\n", arr2);
//	printf("按回车键继续:>");
//	getchar();
//	system("cls");	//清空屏幕
//
//
//	//主体
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//
//		//展示效果优化
//		Sleep(500);		//延时 单位 毫秒
//		system("cls");	//清空屏幕
//
//	}
//	printf("%s", arr1);
//
//}
