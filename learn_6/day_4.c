#define _CRT_SECURE_NO_WARNINGS


//�ļ�����ѧϰ 

// #include <stdio.h> ��
// fopen	���ļ�,���� FILE* ,"r" "w" "a" "rb" "wb" "ab" "w+",��ͬ��ʽ���ļ���ִ�в�����ͬ
// fclose	�ر��ļ�,��ֹ��Դ�˷�,�ɴ��ļ���Ŀ��������
// FILE*   NULL �п�
// fgetc	��ȡһ���ַ�,���� int			fgetc(pf);
// fputc	д��һ���ַ�					fputc('�ַ�',pf);
// fgets	��ȡָ�����ַ���,���� char*		fgets(char* str,��������'\0',FILE* pf);
// fputs	д���ַ���						fputs(char* str,FILE* pf);
// fscanf	��ȡ��ʽ���ı�,��scanf����,ֻ������һ��������������,�ǵ�ȡ��ַ fscanf(stdin,"",&);
// fprintf	д���ʽ���ı�,��printf����,ֻ������һ��������������	fprintf(stdout,"",);
// fread	��ȡ�������ļ�		fread(void* ptr,Ԫ�ش�С,Ԫ������,FILE* pf);
// fwrite	д��������ļ�		fwrite(void* ptr,Ԫ�ش�С,Ԫ������,FILE* pf);
// sscanf	���ַ����ж�ȡ��ʽ���ı�	sscanf(char* buff,"",&);
// sprintf	����ʽ���ı�д���ַ���		sprintf(char* buff,"",);
// fseek	�ļ���ַƫ�ƺ���			fseek(pf,ƫ����,��ʼ��)
// ftell	����Ŀǰ�ļ���ַƫ��		ftell(pf);����long int
// rewind  ==>������� f ��ͷ	��ַ��ʼ��Ϊ��ʼ��ַ	rewind(pf);
// feof		�ж��ļ���ȡ��������Ϊ��ȡ��EOF���Ǳ��ԭ�����,��������(EOF),����ture
// ferror	�ж��ļ���ȡ�Ƿ�������,��,�򷵻�ture
// fflush	ˢ���ļ�������	fflush(pf);

//��ϰ����
#include <stdio.h>

//int main()
//{
//	//�ļ���
//	//FILE* pf = fopen("test.txt", "r");//ֻ��
//	FILE* pf = fopen("test.txt", "w+");//��д
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//�ļ�ʹ��
//	char str[] = "hello world.";
//	//int i = 0;
//	//while (fputc(str[i++],pf))//fputc����ֵ:�ɹ�,����д���ַ���ASCIIֵ,ʧ��,����EOF
//	//{
//	//	;
//	//}
//	fprintf(pf,"%s", str);
//
//	printf("%ld\n", ftell(pf));//��ӡ�ļ�ָ������ʼλ�õ�ƫ����.
//	rewind(pf);//ʹ�ļ�ָ��ص���ʼλ��.
//	printf("%ld\n", ftell(pf));//��ӡ�ļ�ָ������ʼλ�õ�ƫ����.
//	int c = 0;
//	while ((c = fgetc(pf)) != EOF)//fgetc����ֵ:�ɹ�,���ض�ȡ�ַ���ASCIIֵ,ʧ��,����EOF
//	{
//		putchar(c);
//	}
//
//	//�ļ��ر�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

typedef struct A
{
	int a;
	char b[10];
	double c;
}stc_A;
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	stc_A tmp = { 0 };
//	//fwrite(&cd, sizeof(stc_A), 1, pf);
//	//fflush(pf);//ˢ���ļ�������.ˢ�º���û��,���ǹر��ļ��ٴζ�ȡ����.//�Ʋ�ԭ��:��fopen�����й� "wb+" "rb"
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	//fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//	printf("%d %s %f\n", cd.a, cd.b, cd.c);
//	printf("%d %s %f\n", tmp.a, tmp.b, tmp.c);//ʧ��ԭ���Ʋ�,�������ļ�������û��д��.
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////д��������ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////��ȡ�������ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 0 };
//	fread(&cd, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", cd.a, cd.b, cd.c);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��һ��д��,��ȡ���ɹ�
//�ܽ�:fopen�����������ļ���ʽ."wb" "rb"����һ��
// ���������һ����������,���ļ��رպ���һ�ַ�ʽ��
//


////�ۺ�
//int main()
//{
//	//���ļ�	������д��
//	FILE* pf = fopen("D:\\Desktop\\test.bin", "wb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A cd = { 10,"this is 2",2.5f };
//	fwrite(&cd, sizeof(stc_A), 1, pf);
//	//�ر��ļ�
//	fclose(pf);//�ر��ļ���,�ļ�������������д���ļ�
//	pf = NULL;
//
//	//���ļ�	�����ƶ�ȡ
//	pf = fopen("D:\\Desktop\\test.bin", "rb");//ע�� \\ ˫��б��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	stc_A tmp = { 0 };
//	fread(&tmp, sizeof(stc_A), 1, pf);
//	fprintf(stdout, "%d %s %f\n", tmp.a, tmp.b, tmp.c);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


















///* fseek example */
//#include <stdio.h>
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}


///* ftell example : getting size of a file */
//#include <stdio.h>
//int main()
//{
//    FILE* pFile;
//    long size;
//    pFile = fopen("example.txt", "rb");
//    if (pFile == NULL)
//    {
//        perror("Error opening file");
//        return 1;
//    }
//    else
//    {
//        fseek(pFile, 0, SEEK_END);   // non-portable
//        size = ftell(pFile);
//        fclose(pFile);
//        printf("Size of example.txt: %ld bytes.\n", size);
//    }
//    return 0;
//}



///* rewind example */
//#include <stdio.h>
//int main()
//{
//    int n;
//    FILE* pFile;
//    char buffer[27];
//    pFile = fopen("myfile.txt", "w+");
//    for (n = 'A'; n <= 'Z'; n++)
//        fputc(n, pFile);
//    rewind(pFile);
//    fread(buffer, 1, 26, pFile);
//    fclose(pFile);
//    buffer[26] = '\0';
//    puts(buffer);
//
//    return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "w");
//	fprintf(pf,"%d",a);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
//int main(void)
//{
//    int c; // ע�⣺int����char��Ҫ����EOF
//    FILE* fp = fopen("test.txt", "r");
//    if (!fp) {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//    {
//        putchar(c);
//    }
//    //�ж���ʲôԭ�������
//    if (ferror(fp))
//        puts("I/O error when reading");
//    else if (feof(fp))
//        puts("End of file reached successfully");
//    fclose(fp);
//}



//#include <stdio.h>
//enum { SIZE = 5 };
//int main(void)
//{
//    double a[SIZE] = { 1.,2.,3.,4.,5. };
//    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
//    fwrite(a, sizeof * a, SIZE, fp); // д double ������    //sizeof * a ==>*a�����ݵ��ڴ��С��Ҳ�������ݵĴ洢���ʹ�С
//    fclose(fp);                                             //����aԪ��������double,���Եȼ���sizeof(double)
//    double b[SIZE];
//    fp = fopen("test.bin", "rb");
//    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // �� double ������
//    if (ret_code == SIZE) {
//        puts("Array read successfully, contents: ");
//        for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
//        putchar('\n');
//    }
//    else { // error handling
//        if (feof(fp))
//            printf("Error reading test.bin: unexpected end of file\n");
//        else if (ferror(fp)) {
//            perror("Error reading test.bin");
//        }
//    }
//    fclose(fp);
//}



//�ļ�������
//#include <stdio.h>
//#include <windows.h>
////VS2013 WIN10��������
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//�Ƚ�����������������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	fclose(pf);
//	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//	pf = NULL;
//	return 0;
//}


//fgets fputs
//int main()
//{
//	//���ļ� д
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "w");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	char str[] = " hehe";
//	fputs("bit", pf);
//	int m = fputs(str, pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ� ��
//	FILE* pf = fopen("D:\\Desktop\\test.txt", "r");
//	if (!pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//ʹ���ļ�
//	char arr[30] = { 0 };
//	char* ret = fgets(arr, 9,pf);//��ȡ��С���� '\0'
//	if (ret)
//	{
//		if (feof)
//		{
//			printf("feof\n");
//		}
//		else if(ferror)
//		{
//			printf("ferror\n");
//		}
//		puts(ret);
//	}
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_SET);//�ļ�ָ���ַƫ��
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, 0, SEEK_END);
//	printf("ƫ��:%d\n", ftell(pf));
//	fseek(pf, -2, SEEK_CUR);
//	printf("ƫ��:%d\n", ftell(pf));
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////sscanf ������ȡ��ַ sprintf �Ѹ�ʽ�����ݴ����ַ���
//struct B
//{
//	int a;
//	char b[10];
//	double c;
//};
//int main()
//{
//	int buff[60] = { 0 };
//	struct B m = { 3,"asdf",5.3f };
//	sprintf(buff, "%d %s %lf", m.a, m.b, m.c);
//
//	struct B n = {0};
//	sscanf(buff, "%d %s %lf", &(n.a), n.b, &(n.c));//����scanf��,ֻ�����벻��stdin,�����ַ���.��Ҫȡ��ַ
//	printf("%d %s %lf\n", n.a, n.b, n.c);
//	printf("*************\n");
//	printf(buff);
//
//
//	return 0;
//}