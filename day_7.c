#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
//�ַ�������,�ڴ溯������ѧϰ 1


//strlen ģ��ʵ��.
//size_t strlen(const char* str);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//1.0
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	const char* cp = str;
//	while (*cp++ !='\0')
//	{
//		;
//	}
//	return cp - str - 1;
//}

//2.0
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}

////3.0
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}

//int main()
//{
//	char arr[] = "asfsfsf";
//	//int len = strlen(arr);
//	int len = my_strlen(arr);
//
//	printf("%d\n", len);
//	return 0;
//}

//ע��:strlen ����������size_t,�������п��ܻᵼ�� ��������ת��
#include <stdio.h>
//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "bbb";
//	//if (strlen(str2) - strlen(str1) > 0)//strlen(str2) - strlen(str1)�����޷�������,������Ҳ���޷�������.
//	//if (strlen(str2) > strlen(str1))//����1.0
//	int n = strlen(str2) - strlen(str1);//����2.0
//	if (n > 0)
//	{
//		printf("str2>str1\n");
//	}
//	else
//	{
//		printf("srt1>str2\n");
//	}
//	return 0;
//}


//strcpy ģ��ʵ��
//char * strcpy ( char * destination, const char * source );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* cp = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return cp;
//}
//
//int main()
//{
//	char arr[20] = "123456\0**********";
//	//char arr2[] = { 'a','b','c' };//source������� '\0'
//	//strcpy(arr, "this is a code.");
//	my_strcpy(arr, "this is a code.");
//	//my_strcpy(arr, arr2);
//	printf("%s\n", arr);
//	return 0;
//}


//strcat ģ��ʵ��
//char * strcat ( char * destination, const char * source );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* cp = dest;
//	//�ҵ�destָ��� '\0'
//	while (*dest++)
//	{
//		;
//	}
//	dest = dest - 1;
//	//����
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return cp;
//}
//
//int main()
//{
//	char arr1[30] = "hhhhhhh \0zzzzzzzz";
//	char arr2[] = "this is a function.";
//	//strcat(arr1, arr2);
//	my_strcat(arr1, arr2);
//
//	printf("%s\n", arr1);
//	return 0;
//}



//strcmp ģ��ʵ��
//int strcmp ( const char * str1, const char * str2 );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	//ASCII��ͬ,��һλ,ֱ����ͬ���� '\0'
//	while ((*s1 == *s2) && (*s1 != '\0'))//�ǵý�����
//	{
//		s1++;
//		s2++;
//	}
//	//���رȽϽ�� >0  =0  <0
//	//return *s1 - *s2;
//	//����
//	if (*s1 > *s2)
//	{
//		return 1;
//	}
//	else if (*s1 < *s2)
//	{
//		return -1;
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr1[] = "aaag";
//	char arr2[] = "ad";
//	//int ret = strcmp(arr1, arr2);
//	int ret = my_strcmp(arr1, arr2);
//
//	printf("%d\n", ret);
//	return 0;
//}



//strstr ģ��ʵ��
//const char * strstr ( const char * str1, const char * str2 ); 
#include <stdio.h>
#include <string.h>
#include <assert.h>

//1.0
//char* my_strstr(const char* dest, const char* src)
//{
//	assert(dest && src);
//	int sz = strlen(src);
//	char* cp = dest;
//	//�ж�dest�Ƿ����
//	while (*dest != '\0')
//	{
//		//�ҵ�dest ����ʼ��ͬ��  ע�� '\0'
//		while ((*dest - *src) && (*dest))
//		{
//			dest++;
//		}
//		if (*dest == '\0')
//			return NULL;
//		cp = dest;//��¼��ʼλ��
//		//���ν��бȽ�,��ͬ,�򷵻رȽϳ�ʼ��һλ
//		int i = 0;
//		for (i = 0; i < sz; i++)
//		{
//			if ((*(dest+i) == *(src+i)) )
//			{
//				if ((i == sz - 1) && (*(dest + i) != '\0'))
//					return cp;
//			}
//			else
//				break;
//		}
//		dest++;//���رȽϳ�ʼ��һλ
//	}
//}

////2.0
//char* my_strstr(const char* dest, const char* src)
//{
//	assert(dest && src);
//	char* cpd = dest;
//	char* cps = src;
//	while (1)
//	{
//		//�ҵ�����ĸ��ͬλ��
//		while ((*dest != *src) && (*dest != '\0'))
//		{
//			dest++;
//
//		}
//		cpd = dest;//��ʼλ��
//		src = cps;//��ʼ��
//		while ((*dest == *src) && (*src != '\0'))//����ͬʱ (*dest != '\0') && (*src != '\0'),ֻҪ����һ��Ϊ 0,
//		{										 //������,�˳�ѭ��,��������,Ҳ�˳�ѭ��
//			dest++;
//			src++;
//		}
//		if (*src == '\0')
//			return cpd;
//		if (*dest == '\0')
//			return NULL;
//		dest = cpd + 1;//�ص���ʼλ����һλ
//	}
//	
//}
//
//int main()
//{
//	char arr1[] = "abcddedef";
//	char arr2[] = "def";
//	//char* ret = strstr(arr1, arr2);
//	char* ret = my_strstr(arr1, arr2);
//
//	if (ret)//����NULL
//		printf("%s found.\n",ret);
//	else
//		printf("not found\n");
//	return 0;
//}
//
////�ο�����
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1, * s2;
//
//	if (!*str2)//str2������,*str2 == '\0'
//		return((char*)str1);
//
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//
//		while (*s1 && *s2 && !(*s1 - *s2))//!(*s1 - *s2)  ==> (*s1 == *s2) ;*s1 && *s2  ==>  *s1 != 0 && *s2 != 0
//			s1++, s2++;
//
//		if (!*s2)//str2������,*str2 == '\0'
//			return(cp);
//
//		cp++;
//	}
//
//	return(NULL);
//}



//strncpy  ģ��ʵ��
//char* strncpy(char* dest, const char* src,size_t num);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* cp = dest;
//	while ((num--) && (*src))//����num�����,����srcָ�� '\0'
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return cp;
//}
//
//int main()
//{
//	char arr1[20] = "";
//	char arr2[] = "hello.";
//	//char* ret = strncpy(arr1, arr2,8);
//	char* ret = my_strncpy(arr1, arr2, 2);
//
//	printf("%s\n", ret);
//	return 0;
//}



//strncat ģ��ʵ��
//char * strncat ( char * destination, const char * source, size_t num );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* cp = dest;
//	//�ҵ�destָ��'\0'��λ��
//	while (*dest++)
//	{
//		;
//	}
//	dest--;
//	//����	n���ֽ�,ĩβ�� '\0'
//	while ((num--) && (*src))
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return cp;
//}
//
//
//int main()
//{
//	char arr1[20] = "hello \0########";
//	//char* ret = strncat(arr1, "world.", 10);
//	char* ret = my_strncat(arr1, "world.", 3);
//
//	printf("%s\n", ret);
//	return 0;
//}

/* strncat example */
#include <stdio.h>
#include <string.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	strncat(str1, str2, 6);
//	puts(str1);
//	return 0;
//}





//strncmp ģ��ʵ��
//char * strncmp ( char * destination, const char * source, size_t num );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_strncmp(const char* s1, const char* s2, size_t num)
//{
//	assert(s1 && s2);
//	while (num--)
//	{
//		if (*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		else if (*s1 > *s2)//ֻҪ����һ��Ϊ '\0',��Ӧ�ľ��� 0 ,ASCIIֵ��С
//		{
//			return 1;
//		}
//		else if (*s1 < *s2)
//			return -1;
//		if ((*s1 ==0) && (*s2 == 0))//��ֹ"aabbc\0d" "aabbc\0z"�������.
//			return 0;
//	}
//	return 0;
//}
//
//
//int main()
//{
//	char arr1[] = "aabbc\0d";
//	char arr2[] = "aaabbc\0z";
//	//int ret = strncmp(arr1, arr2, 3);
//	int ret = my_strncmp(arr1, arr2, 2);
//
//	printf("%d\n", ret);
//	return 0;
//}

/* strncmp example */
#include <stdio.h>
#include <string.h>

//int main()
//{
//    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//    int n;
//    puts("Looking for R2 astromech droids...");
//    for (n = 0; n < 3; n++)
//        if (strncmp(str[n], "R2xx", 2) == 0)//�����Ӧ�÷�ʽ
//        {
//            printf("found %s\n", str[n]);
//        }
//    return 0;
//}





//strtok ģ��ʵ��
//char* strtok(char* str, const char* delimiters);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* cmp_first(char* arr[],int num)
//{
//	//�����Ƚ�,��������������˼��
//	//����Сһ������ĩβ
//	int i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		//�Ӻ���ǰ
//		if (arr[i] < arr[i + 1])
//		{
//			//����
//			char* tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//	if (num == 0)//����Խ�����
//	{
//		return NULL;
//	}
//	return arr[num - 1];
//}
//
//char* my_strtok(char* str,const char* delim)
//{
//
//	assert(delim);//str����ΪNULL
//	static char* start = NULL;//��һ�β��ҵ���ʼλ�� && ��������NULL���жϱ�־
//	char* cp = str;
//	char* de = delim;
//	char* cmp[20] = { 0 };//�洢��ʼָ��
//	int i = 0;
//
//
//	//������һ�ε��ñ����λ�ÿ�ʼִ��
//	if (str == NULL)
//	{
//		str = start;
//		cp = str;
//		
//		if (start == NULL)//�����˵Ľ�����־
//		{
//			return NULL;
//		}
//	}
//
//	//���û�зָ��
//	if (*delim == '\0')
//	{
//		start = NULL;
//		return str;
//	}
//
//	while (*delim)//��������,���Ǽ����ָ���Ų��в���˭������˭
//	{
//		str = cp;//str ��ʼ��λ��
//		//�ҵ��ָ����λ��
//		while (*str)
//		{
//			if (*str != *delim)
//				str++;
//			else
//			{
//				cmp[i++] = str;//�洢ÿ���ָ����Ӧ��ʼλ��
//				break;
//			}
//		}
//		delim++;
//	}
//
//	if (i != 0)
//	{
//		//ѡ���ǰ����ʼλ��
//		str = cmp_first(cmp, i);
//		//���һ��cmp[]��û�д���ָ��,ֻ�г�ʼ����ָ�� .cmp[0-1]���ʴ���,���Ա���
//	}
//
//	if (!(*str))//*str Ϊ \0,������,���ǻ��÷�����һ�ε���ʼλ��.
//	{
//		start = NULL;
//		return cp;
//	}
//
//	//�滻�ָ����Ϊ \0 
//	*str = '\0';
//	//��¼�ָ���ŵ���һλ��Ϊ�´ε���ʱ����ʼλ��
//	start = str + 1;
//	//������ʼλ��
//	return cp;
//
//}
//
//
//int main()
//{
//	char str[] = "first,forget sadness;second,try to be better.last:emmm";
//	char tmp[80];
//	strcpy(tmp, str);
//	char deli[] = ",;.:";
//	printf("���ض�����\"%s\"�ָ��ַ���\"%s\"\n", deli, tmp);
//
//	//char* ptok = strtok(tmp, deli);//Ҳ����ֱ��",;.:"
//	//while (ptok)//��ΪNULL
//	//{
//	//	printf("%s\n", ptok);
//	//	ptok = strtok(NULL, deli);
//	//}
//
//	char* ptok = my_strtok(tmp, deli);
//	while (ptok)//��ΪNULL
//	{
//		printf("%s\n", ptok);
//		ptok = my_strtok(NULL, deli);
//	}
//
//	return 0;
//}



//strerror	��  perror  ʹ��
//char * strerror ( int errnum );
//void perror(const char* str);
#include <stdio.h>
#include <string.h>
#include <errno.h>

//int main()
//{
//	//printf("%s\n", strerror(0));//��ͬ�Ĵ������
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(3));
//	//printf("%s\n", strerror(4));
//	//printf("****************************\n");
//
//	////strerror
//	//FILE* pFile;
//	//pFile = fopen("unexist.ent", "r");
//	//if (pFile == NULL)
//	//	printf("Error opening file unexist.ent: %s\n", strerror(errno));
//	//return 0;
//
//	//perror
//	FILE* pFile;
//	pFile = fopen("unexist.ent", "rb");
//	if (pFile == NULL)
//		perror("The following error occurred");//The following error occurred: No such file or directory ������д�����Ϣ
//	else
//		fclose(pFile);
//	return 0;
//
//}




//memcpy	ģ��ʵ��
// Ŀ���Դ����ָ��������СӦ����Ϊ�ֽ��������Ҳ�Ӧ�ص�
//void * memcpy ( void * destination, const void * source, size_t num );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	assert(dest && src);
//	void* cp = dest;
//	while (num--)
//	{
//		*((char*)dest) = *((char*)src);//ע��:����ת��ֻ��һ����ʱ��״̬,�����û��
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return cp;
//}
//
//int main()
//{
//	int arr1[20] = { 1,2,3,4,6,7,8,9,10,11,12,13,14,15,16,17,18 };
//	int arr2[10] = { 0,0,0,0 };
//	//memcpy(arr1+2, arr1,16);
//	//int* ret = (int*)my_memcpy(arr1 + 2, arr2, 20);
//	my_memcpy(arr1 +2, arr1, 20);//���ص�����,�����������ص������Ӧ,�������ظ�
//	//��ӡ
//	int i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	return 0;
//}




////memmove	ģ��ʵ��
// void * memmove ( void * destination, const void * source, size_t num );
//���ֽ�����ֵ��Դָ���λ�ø��Ƶ�Ŀ��ָ����ڴ�顣���ƾ���ʹ�����м仺����һ��������Ŀ���Դ�ص���
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* cp = dest;
//
//	//ע��:�����ǵ�ַ�Ĺ�ϵ�Ƚ�,��˭��ǰ��Ĺ�ϵ
//	//�� dest < src ,������û���ص�,�����Դ������Ҹ���(��ǰ��ĩβ����)
//	if (dest < src)
//	{
//		while (num--)//��ǰ��ĩβ����
//		{
//			*((char*)dest) = *((char*)src);//ע��:����ת��ֻ��һ����ʱ��״̬,�����û��
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//
//	}
//
//	//�� dest > src ,������û���ص�,�����Դ���������(��ĩβ��ǰ����)
//	if (dest > src)
//	{
//		while (num--)//��ĩβ��ǰ����
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//
//
//	return cp;
//}
//
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
//	int arr2[10] = { 0,0,0,0 };
//	//��ӡ
//	int i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	//my_memmove(arr1, arr2, 20);
//	//memmove(arr1+2, arr1,20);
//	my_memmove(arr1 + 2, arr1,20);
//	//my_memmove(arr1, arr1 + 2, 20);
//
//	//��ӡ
//	i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	return 0;
//}



//memcmp   ʹ��,ģ��ʵ��
//int memcmp(const void* ptr1, const void* ptr2, size_t num);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_memcmp(const void* s1, const void* s2,size_t num)
//{
//	assert(s1 && s2);
//	//ASCII��ͬ,��һλ,ֱ����ͬ���� num����
//	while (*((char*)s1) == *((char*)s2) && num--)
//	{
//		s1 = (char*)s1 + 1;
//		s2 = (char*)s2 + 1;
//	}
//	//���رȽϽ�� >0  =0  <0
//	return *((unsigned char*)s1) - *((unsigned char*)s2);
//}
//
//
//int main()
//{
//	char arr1[10] = "ABCD";
//	char arr2[10] = "ABCD";
//	//int ret = memcmp(arr1, arr2,4);
//	int ret = my_memcmp(arr1, arr2, 4);
//
//	if (ret > 0)
//		printf("arr1 > arr2\n");
//	else if (ret < 0)
//		printf("arr1 < arr2\n");
//	else
//		printf("arr1 == arr2\n");
//	return 0;
//}




//��,���� ��0 ;����,���� 0
//iscntrl �κο����ַ�
//isspace �հ��ַ����ո� ������ҳ��\f��������'\n'���س���\r�����Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
//isdigit ʮ�������� 0~9
//isxdigit ʮ���������֣���������ʮ�������֣�Сд��ĸa~f����д��ĸA~F
//islower Сд��ĸa~z
//isupper ��д��ĸA~Z
//isalpha ��ĸa~z��A~Z
//isalnum ��ĸ�������֣�a~z, A~Z, 0~9
//ispunct �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
//isgraph �κ�ͼ���ַ�
//isprint �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�

//�ַ�ת������    �ο�����
//isupper example 
#include <stdio.h>
#include <ctype.h>

//int main()
//{
//    int i = 0;
//    char str[] = "Test String.\n";
//    char c;
//    while (str[i])
//    {
//        c = str[i];
//        if (isupper(c))
//            c = tolower(c);
//        putchar(c);
//        i++;
//    }
//    return 0;
//}
=======

#include <stdio.h>

//27. �Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 1��
//���룺nums = [3, 2, 2, 3], val = 3
//�����2, nums = [2, 2]
//���ͣ�����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء����磬�������ص��³���Ϊ 2 ���� nums = [2, 2, 3, 3] �� nums = [2, 2, 0, 0]��Ҳ�ᱻ������ȷ�𰸡�
//ʾ�� 2��
//���룺nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//�����5, nums = [0, 1, 4, 0, 3]
//���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

//1.0   ʱ�临�Ӷ�O(N*N)     �ռ临�Ӷ�O(1)
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    //˳�����,�ҵ���memmove����,Ȼ��numsSize--,i--
    for (i = 0; i < numsSize; i++)
    {
        if (val == nums[i])
        {
            memmove(nums + i, nums + i + 1, (numsSize - i - 1) * sizeof(int));
            numsSize--;
            i--;
        }
    }
    return numsSize;

}


//2.0   ʱ�临�Ӷȿ�����O(N*log(2)N + ...)      �ռ临�Ӷ�O(1)
int cmp_int(void* e1, void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
int removeElement(int* nums, int numsSize, int val) {
    //2.0
    //����,Ȼ�����val����,λ��,MEMMOVE
    qsort(nums, numsSize, sizeof(int), cmp_int);
    int i = 0;
    int count = 0;
    int pos = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (val == nums[i])
        {
            if (count == 0)
            {
                pos = i;
            }
            count++;
        }
    }
    memmove(nums + pos, nums + pos + count, (numsSize - pos - count) * sizeof(int));
    return numsSize - count;
}



//3.0����val,�򽫽������һ��������  ʱ�临�Ӷ�O(N)   �ռ临�Ӷ�O(N)
int removeElement(int* nums, int numsSize, int val) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    int i = 0;
    int count = 0;
    //����val,�򽫽������һ��������
    for (i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            arr[count] = nums[i];
            count++;
        }
    }
    memmove(nums, arr, count * sizeof(int));
    free(arr);
    arr = NULL;

    return count;

}


//4.0   ����val,����nums[count],count++     ʱ�临�Ӷ�O(N)   �ռ临�Ӷ�O(1)
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}
>>>>>>> w6/main
