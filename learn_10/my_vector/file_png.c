//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	FILE* pf = fopen("2022.png", "r");
//	FILE* fin = fopen("in.png", "w");
//	char ch;
//	//不行,图片编码方式可能不同
//	while (ch = fgetc(pf) != EOF)
//	{
//		fputc(ch, fin);
//	}
//	fclose(pf);
//	fclose(fin);
//	pf = fin = NULL;
//
//	return 0;
//}