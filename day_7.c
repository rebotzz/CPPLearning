#define _CRT_SECURE_NO_WARNINGS

<<<<<<< HEAD
//字符串函数,内存函数进阶学习 1


//strlen 模拟实现.
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

//注意:strlen 返回类型是size_t,在运算中可能会导致 算数类型转换
#include <stdio.h>
//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "bbb";
//	//if (strlen(str2) - strlen(str1) > 0)//strlen(str2) - strlen(str1)都是无符号整形,计算结果也是无符号整形.
//	//if (strlen(str2) > strlen(str1))//更改1.0
//	int n = strlen(str2) - strlen(str1);//更改2.0
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


//strcpy 模拟实现
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
//	//char arr2[] = { 'a','b','c' };//source必须包含 '\0'
//	//strcpy(arr, "this is a code.");
//	my_strcpy(arr, "this is a code.");
//	//my_strcpy(arr, arr2);
//	printf("%s\n", arr);
//	return 0;
//}


//strcat 模拟实现
//char * strcat ( char * destination, const char * source );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* cp = dest;
//	//找到dest指向的 '\0'
//	while (*dest++)
//	{
//		;
//	}
//	dest = dest - 1;
//	//复制
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



//strcmp 模拟实现
//int strcmp ( const char * str1, const char * str2 );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	//ASCII相同,下一位,直到不同或者 '\0'
//	while ((*s1 == *s2) && (*s1 != '\0'))//记得解引用
//	{
//		s1++;
//		s2++;
//	}
//	//返回比较结果 >0  =0  <0
//	//return *s1 - *s2;
//	//或者
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



//strstr 模拟实现
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
//	//判断dest是否结束
//	while (*dest != '\0')
//	{
//		//找到dest 中起始相同的  注意 '\0'
//		while ((*dest - *src) && (*dest))
//		{
//			dest++;
//		}
//		if (*dest == '\0')
//			return NULL;
//		cp = dest;//记录起始位置
//		//依次进行比较,不同,则返回比较初始后一位
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
//		dest++;//返回比较初始后一位
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
//		//找到首字母相同位置
//		while ((*dest != *src) && (*dest != '\0'))
//		{
//			dest++;
//
//		}
//		cpd = dest;//起始位置
//		src = cps;//初始化
//		while ((*dest == *src) && (*src != '\0'))//不用同时 (*dest != '\0') && (*src != '\0'),只要其中一个为 0,
//		{										 //如果相等,退出循环,如果不相等,也退出循环
//			dest++;
//			src++;
//		}
//		if (*src == '\0')
//			return cpd;
//		if (*dest == '\0')
//			return NULL;
//		dest = cpd + 1;//回到起始位置下一位
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
//	if (ret)//不是NULL
//		printf("%s found.\n",ret);
//	else
//		printf("not found\n");
//	return 0;
//}
//
////参考代码
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1, * s2;
//
//	if (!*str2)//str2找完了,*str2 == '\0'
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
//		if (!*s2)//str2找完了,*str2 == '\0'
//			return(cp);
//
//		cp++;
//	}
//
//	return(NULL);
//}



//strncpy  模拟实现
//char* strncpy(char* dest, const char* src,size_t num);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* cp = dest;
//	while ((num--) && (*src))//拷贝num个完成,或者src指向 '\0'
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



//strncat 模拟实现
//char * strncat ( char * destination, const char * source, size_t num );
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* cp = dest;
//	//找到dest指向'\0'的位置
//	while (*dest++)
//	{
//		;
//	}
//	dest--;
//	//复制	n个字节,末尾补 '\0'
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





//strncmp 模拟实现
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
//		else if (*s1 > *s2)//只要其中一方为 '\0',对应的就是 0 ,ASCII值较小
//		{
//			return 1;
//		}
//		else if (*s1 < *s2)
//			return -1;
//		if ((*s1 ==0) && (*s2 == 0))//防止"aabbc\0d" "aabbc\0z"这种情况.
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
//        if (strncmp(str[n], "R2xx", 2) == 0)//不错的应用方式
//        {
//            printf("found %s\n", str[n]);
//        }
//    return 0;
//}





//strtok 模拟实现
//char* strtok(char* str, const char* delimiters);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* cmp_first(char* arr[],int num)
//{
//	//两两比较,可以用起泡排序思想
//	//将最小一个至于末尾
//	int i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		//从后往前
//		if (arr[i] < arr[i + 1])
//		{
//			//交换
//			char* tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//	if (num == 0)//避免越界访问
//	{
//		return NULL;
//	}
//	return arr[num - 1];
//}
//
//char* my_strtok(char* str,const char* delim)
//{
//
//	assert(delim);//str可以为NULL
//	static char* start = NULL;//下一次查找的起始位置 && 结束返回NULL的判断标志
//	char* cp = str;
//	char* de = delim;
//	char* cmp[20] = { 0 };//存储起始指针
//	int i = 0;
//
//
//	//继续上一次调用保存的位置开始执行
//	if (str == NULL)
//	{
//		str = start;
//		cp = str;
//		
//		if (start == NULL)//找完了的结束标志
//		{
//			return NULL;
//		}
//	}
//
//	//如果没有分割符
//	if (*delim == '\0')
//	{
//		start = NULL;
//		return str;
//	}
//
//	while (*delim)//不是依次,而是几个分割符号并行查找谁优先用谁
//	{
//		str = cp;//str 初始化位置
//		//找到分割符号位置
//		while (*str)
//		{
//			if (*str != *delim)
//				str++;
//			else
//			{
//				cmp[i++] = str;//存储每个分割符对应起始位置
//				break;
//			}
//		}
//		delim++;
//	}
//
//	if (i != 0)
//	{
//		//选出最靠前的起始位置
//		str = cmp_first(cmp, i);
//		//最后一次cmp[]中没有存入指针,只有初始化空指针 .cmp[0-1]访问错误,所以避免
//	}
//
//	if (!(*str))//*str 为 \0,找完了,但是还得返回这一次的起始位置.
//	{
//		start = NULL;
//		return cp;
//	}
//
//	//替换分割符号为 \0 
//	*str = '\0';
//	//记录分割符号的下一位作为下次调用时的起始位置
//	start = str + 1;
//	//返回起始位置
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
//	printf("以特定符号\"%s\"分割字符串\"%s\"\n", deli, tmp);
//
//	//char* ptok = strtok(tmp, deli);//也可以直接",;.:"
//	//while (ptok)//不为NULL
//	//{
//	//	printf("%s\n", ptok);
//	//	ptok = strtok(NULL, deli);
//	//}
//
//	char* ptok = my_strtok(tmp, deli);
//	while (ptok)//不为NULL
//	{
//		printf("%s\n", ptok);
//		ptok = my_strtok(NULL, deli);
//	}
//
//	return 0;
//}



//strerror	和  perror  使用
//char * strerror ( int errnum );
//void perror(const char* str);
#include <stdio.h>
#include <string.h>
#include <errno.h>

//int main()
//{
//	//printf("%s\n", strerror(0));//不同的错误代码
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
//		perror("The following error occurred");//The following error occurred: No such file or directory 后面会有错误信息
//	else
//		fclose(pFile);
//	return 0;
//
//}




//memcpy	模拟实现
// 目标和源参数指向的数组大小应至少为字节数，并且不应重叠
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
//		*((char*)dest) = *((char*)src);//注意:类型转换只是一种临时的状态,用完就没了
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
//	my_memcpy(arr1 +2, arr1, 20);//有重叠部分,拷贝方向与重叠方向对应,拷贝会重复
//	//打印
//	int i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	return 0;
//}




////memmove	模拟实现
// void * memmove ( void * destination, const void * source, size_t num );
//将字节数的值从源指向的位置复制到目标指向的内存块。复制就像使用了中间缓冲区一样，允许目标和源重叠。
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* cp = dest;
//
//	//注意:这里是地址的关系比较,是谁在前面的关系
//	//当 dest < src ,不管有没有重叠,都可以从左向右复制(从前向末尾复制)
//	if (dest < src)
//	{
//		while (num--)//从前向末尾复制
//		{
//			*((char*)dest) = *((char*)src);//注意:类型转换只是一种临时的状态,用完就没了
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//
//	}
//
//	//当 dest > src ,不管有没有重叠,都可以从右向左复制(从末尾向前复制)
//	if (dest > src)
//	{
//		while (num--)//从末尾向前复制
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
//	//打印
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
//	//打印
//	i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	return 0;
//}



//memcmp   使用,模拟实现
//int memcmp(const void* ptr1, const void* ptr2, size_t num);
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_memcmp(const void* s1, const void* s2,size_t num)
//{
//	assert(s1 && s2);
//	//ASCII相同,下一位,直到不同或者 num结束
//	while (*((char*)s1) == *((char*)s2) && num--)
//	{
//		s1 = (char*)s1 + 1;
//		s2 = (char*)s2 + 1;
//	}
//	//返回比较结果 >0  =0  <0
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




//是,返回 非0 ;不是,返回 0
//iscntrl 任何控制字符
//isspace 空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车‘\r’，制表符'\t'或者垂直制表符'\v'
//isdigit 十进制数字 0~9
//isxdigit 十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
//islower 小写字母a~z
//isupper 大写字母A~Z
//isalpha 字母a~z或A~Z
//isalnum 字母或者数字，a~z, A~Z, 0~9
//ispunct 标点符号，任何不属于数字或者字母的图形字符（可打印）
//isgraph 任何图形字符
//isprint 任何可打印字符，包括图形字符和空白字符

//字符转换函数    参考代码
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

//27. 移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//示例 1：
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2, nums = [2, 2]
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2, 2, 3, 3] 或 nums = [2, 2, 0, 0]，也会被视作正确答案。
//示例 2：
//输入：nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//输出：5, nums = [0, 1, 4, 0, 3]
//解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

//1.0   时间复杂度O(N*N)     空间复杂度O(1)
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    //顺序查找,找到后memmove覆盖,然后numsSize--,i--
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


//2.0   时间复杂度可能是O(N*log(2)N + ...)      空间复杂度O(1)
int cmp_int(void* e1, void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
int removeElement(int* nums, int numsSize, int val) {
    //2.0
    //排序,然后计算val个数,位置,MEMMOVE
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



//3.0不是val,则将结果存入一个新数组  时间复杂度O(N)   空间复杂度O(N)
int removeElement(int* nums, int numsSize, int val) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    int i = 0;
    int count = 0;
    //不是val,则将结果存入一个新数组
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


//4.0   不是val,存入nums[count],count++     时间复杂度O(N)   空间复杂度O(1)
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
