<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS

//Ö¸Õë½ø½×Ñ§Ï° 3


//¡¾ÌâÄ¿Ãû³Æ¡¿
//×Ö·û´®Ğı×ª½á¹û
//¡¾ÌâÄ¿ÄÚÈİ¡¿
//Ğ´Ò»¸öº¯Êı£¬ÅĞ¶ÏÒ»¸ö×Ö·û´®ÊÇ·ñÎªÁíÍâÒ»¸ö×Ö·û´®Ğı×ªÖ®ºóµÄ×Ö·û´®¡£
//ÀıÈç£º¸ø¶¨s1 = AABCDºÍs2 = BCDAA£¬·µ»Ø1
//¸ø¶¨s1 = abcdºÍs2 = ACBD£¬·µ»Ø0.
//AABCD×óĞıÒ»¸ö×Ö·ûµÃµ½ABCDA
//AABCD×óĞıÁ½¸ö×Ö·ûµÃµ½BCDAA
//AABCDÓÒĞıÒ»¸ö×Ö·ûµÃµ½DAABC

//·ÖÎö:·Ö×óĞıÓÒĞı,Ñ­»·,½»»»Ë³Ğò,ÒÀ´ÎµÃµ½Ğı×ªºóµÃ½á¹û,½øĞĞ±È½Ï
//×óĞı »òÕß ÓÒĞı ÈÎÒ»Ò»ÖÖÖ»ÒªÑ¡ÔñÁËËùÓĞ¿ÉÄÜĞÔ,¾Í°üº¬ÁíÒ»ÖÖÑ¡ÔñµÄ¿ÉÄÜĞÔ
#include <stdio.h>
#include <string.h>

////1.0
//void rotate(char* s1)
//{
//	//¿ÉÒÔÀûÓÃÆğÅİ·¨µÄ½»»»·½·¨
//	int sz = strlen(s1);
//	//²»ÓÃÍâ²ãÑ­»·,Ò»´ÎÖ»Ğı×ª1¸öÔªËØ
//	int j = 0;
//	for (j = 0; j < sz - 1 ; j++)
//	{
//		char tmp = s1[j];
//		s1[j] = s1[j+1];
//		s1[j+1] = tmp;
//	}
//}
//
//int judge_rotate(const char* s1,const char* s2)
//{
//	int sz1 = strlen(s1);
//	int sz2 = strlen(s2);
//	char tmp[50];
//	strcpy(tmp, s1);
//	if (sz1 == sz2)
//	{
//		int i = 0;
//		for (i = 0; i < sz1 - 1; i++)
//		{
//			//×óĞı,Õâ²»ÊÇµ¥´¿µÄ½»»»,ÊÇÕûÌåµÄÒÆ¶¯
//			//rotate(s1);//²»×ãÖ®´¦,¸Ä±äÁËs1Ô­ÓĞµÄÖµ
//			rotate(tmp);//²»¸Ä±äs1Ô­ÓĞµÄÖµ
//
//			//ÅĞ¶Ï
//			if (strcmp(tmp, s2) == 0)
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char s1[20] = "hello world.";
//	char s2[20] = "hello siri.";
//	gets(s1);//gets()²ÎÊıÊÇchar*
//	//getchar();
//	gets(s2);
//	//ÅĞ¶ÏÊÇ·ñĞı×ª
//	int ret = judge_rotate(s1, s2);
//	printf("%d\n", ret);
//
//	return 0;
//}

////1.5
//int judge_rotate(const char* s1, const char* s2)
//{
//	int sz1 = strlen(s1);
//	int sz2 = strlen(s2);
//	char tmp[50];
//	strcpy(tmp, s1);
//	if (sz1 == sz2)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < sz1; i++)
//		{
//			for (j = 0; j < sz1 - 1; j++)
//			{
//				char t = tmp[j];
//				tmp[j] = tmp[j + 1];
//				tmp[j + 1] = t;
//			}
//			//ÅĞ¶Ï
//			if (strcmp(tmp, s2) == 0)
//				return 1;
//		}
//	}
//	return 0;
//}

////2.0		È«ÓÃ¿âº¯ÊıÊµÏÖ,¼ò½à,Ê¡Ê±¼ä
//#include <assert.h>
//int judge_rotate(char* s1,char* s2)
//{
//	assert(s1);
//	assert(s2);
//	//ÅĞ¶Ïs1 s2³¤¶ÈÊÇ·ñÒ»Ñù
//	if (strlen(s1) != strlen(s2))
//	{
//		return 0;
//	}
//	//1. s1:  AABCD ¼Ó³¤Îª AABCDAABCD
//	strncat(s1, s1, strlen(s1));//ºó¶Ë¼ÓÉÏ strlen(s1) ¸ö×Ö·û´®
//	//2. ÅĞ¶Ïs2ÊÇ·ñÊÇs1µÄ×Ó´®
//	char* ret = strstr(s1, s2);//²»ÊÇ×Ó´®,·µ»ØNULL,ÊÇ×Ó´®·µ»Ø¶ÔÓ¦µØÖ·
//	return ret != NULL;
//}
//
//int main()
//{
//	char s1[20] = "hello world.";
//	char s2[20] = "hello siri.";
//	gets(s1);//gets()²ÎÊıÊÇchar*
//	//getchar();
//	gets(s2);
//	//ÅĞ¶ÏÊÇ·ñĞı×ª
//	int ret = judge_rotate(s1, s2);
//	printf("%d\n", ret);
//
//	return 0;
//}


//²Î¿¼´úÂë
#include<stdio.h>
#include<string.h>

//int judge(const char* str1, const char* str2)
//{
//	char str3[200] = { 0 };
//	strcpy(str3, str1);//¿½±´str1×Ö·û´®µ½str3ÀïÃæ	//AABCD
//	strcat(str3, str1);//°Ñstr1µÄ×Ö·û´®Á¬½Óµ½str3ÀïÃæ	//AABCDAABCD
//	return strstr(str3, str2) != NULL;//ËÑË÷str3ÀïÃæÊÇ·ñÓĞstr2×Ö·û´®µÄ³öÏÖ,ÓĞ¾Í·µ»Ø1	//AABCDAABCD ´ÓÖĞÕÒÊÇ·ñÓĞ BCDAA,ÓĞ¾Í·µ»ØÆğÊ¼µØÖ·
//}
//
//int main()
//{
//	char s1[200] = { 0 };//AABCD
//	char s2[200] = { 0 };//BCDAA
//	scanf("%s %s", s1, s2);
//	if (judge(s1, s2) && (strlen(s1) == strlen(s2)))
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//
//	return 0;
=======
ï»¿#define _CRT_SECURE_NO_WARNINGS

//æ•°æ®ç»“æ„å­¦ä¹ 
//æ—¶é—´å¤æ‚åº¦&ç©ºé—´å¤æ‚åº¦







//// è®¡ç®—BinarySearchçš„æ—¶é—´å¤æ‚åº¦ï¼Ÿ
////äºŒåˆ†æŸ¥æ‰¾
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);//äºŒè¿›åˆ¶å³ç§»ä¸€ä½ ==> é™¤ä»¥2
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
>>>>>>> w6/main
//}



<<<<<<< HEAD
//¡¾ÌâÄ¿Ãû³Æ¡¿
//×Ö·û´®×óĞı
//¡¾ÌâÄ¿ÄÚÈİ¡¿
//ÊµÏÖÒ»¸öº¯Êı£¬¿ÉÒÔ×óĞı×Ö·û´®ÖĞµÄk¸ö×Ö·û¡£
//ÀıÈç£º
//ABCD×óĞıÒ»¸ö×Ö·ûµÃµ½BCDA
//ABCD×óĞıÁ½¸ö×Ö·ûµÃµ½CDAB
#include <stdio.h>

////1.0
////×óĞınumÎ»
//void rotate_num_L(char* s1,int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//´úÂëÓÅ»¯
//	for (j = 0; j < num; j++)
//	{
//		for (i = 0; i < sz - 1; i++)//Á½Á½½»»»,ÒÀ´ÎÒÆ¶¯µ½Ä©¶Ë
//		{
//			char tmp = s1[i];
//			s1[i] = s1[i + 1];
//			s1[i + 1] = tmp;
//		}
//	}
//}

////2.0	´úÂëÓÅ»¯
////void rotate_num_L(char* s1,int num)
////{
////	int i = 0;
////	int sz = strlen(s1);
////	int j = 0;
////	num = num % sz;//´úÂëÓÅ»¯
////	for (j = 0; j < num; j++)
////	{
////		char tmp = s1[0];
////		for (i = 0; i < sz - 1; i++)//Á½Á½½»»»,ÒÀ´ÎÒÆ¶¯µ½Ä©¶Ë
////		{
////			s1[i] = s1[i + 1];
////		}
////		s1[sz -1] = tmp;
////	}
////}

////3.0	´úÂëÓÅ»¯
//void rotate_num_L(char* s1, int num)
//{
//	int i = 0;
//	int sz = strlen(s1);
//	int j = 0;
//	num = num % sz;//´úÂëÓÅ»¯
//	for (j = 0; j < num; j++)
//	{
//		char tmp = s1[0];
//		for (i = 0; i < sz - 1; i++)//Á½Á½½»»»,ÒÀ´ÎÒÆ¶¯µ½Ä©¶Ë
//		{
//			s1[i] = s1[i + 1];
//		}
//		s1[sz - 1] = tmp;//Ö»ÓÃ½»»»µ½Ä©¶Ë¾ÍĞĞ
//	}
//}

////4.0	´úÂëÓÅ»¯	strcat ÔÚ¸´ÖÆÒ»·İ·ÅÔÚºóÃæ
//void rotate_num_L(char* s1, int num)
//{
//	int sz = strlen(s1);
//	num = num % sz;
//	char tmp[100];
//	strcpy(tmp, s1 + num);//½«Ğı×ªºóÃæµÄ¸´ÖÆµ½tmp,
//	strcat(tmp, s1);//½«Ğı×ªÇ°ÃæµÄ²¿·ÖÁ¬½Óµ½tmp,
//	tmp[sz] = '\0';
//	strcpy(s1,tmp);
//}

////5.0	´úÂëÓÅ»¯	Èı´Î·­×ª·¨
//#include <assert.h>
//
//void reverse(char* start, char* end)
//{
//	assert(start);
//	assert(end);
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void rotate_num_L(char* s1, int num)
//{
//	assert(s1);
//	int sz = strlen(s1);
//	num = num % sz;
//	//Èı´Î·­×ª·¨		abcde
//	//1´Î·­×ª
//	reverse(s1, s1 + num -1);//cba de	num = 3, s1 +2 ==> 'c'
//	//2´Î·­×ª
//	reverse(s1 + num, s1 + sz - 1);//cba ed
//	//3´Î·­×ª
//	reverse(s1, s1 + sz - 1);//de abc
//}
//
//int main()
//{
//	char s1[50] = "hello";
//	gets(s1);
//	int num = 0;
//	scanf("%d", &num);
//	//×óĞınumÎ»
//	rotate_num_L(s1,num);
//	//´òÓ¡
//	printf("%s\n", s1);
//	return 0;
=======















//æ•°ç»„numsåŒ…å«ä»0åˆ°nçš„æ‰€æœ‰æ•´æ•°ï¼Œä½†å…¶ä¸­ç¼ºäº†ä¸€ä¸ªã€‚è¯·ç¼–å†™ä»£ç æ‰¾å‡ºé‚£ä¸ªç¼ºå¤±çš„æ•´æ•°ã€‚ä½ æœ‰åŠæ³•åœ¨O(n)æ—¶é—´å†…å®Œæˆå—ï¼Ÿ
//æ³¨æ„ï¼šæœ¬é¢˜ç›¸å¯¹ä¹¦ä¸ŠåŸé¢˜ç¨ä½œæ”¹åŠ¨
//ç¤ºä¾‹ 1ï¼š
//è¾“å…¥ï¼š[3, 0, 1]
//è¾“å‡ºï¼š2
//ç¤ºä¾‹ 2ï¼š
//è¾“å…¥ï¼š[9, 6, 4, 2, 3, 5, 7, 0, 1]
//è¾“å‡ºï¼š8
//æ¥æºï¼šåŠ›æ‰£ï¼ˆLeetCodeï¼‰
//é“¾æ¥ï¼šhttps ://leetcode.cn/problems/missing-number-lcci
//è‘—ä½œæƒå½’é¢†æ‰£ç½‘ç»œæ‰€æœ‰ã€‚å•†ä¸šè½¬è½½è¯·è”ç³»å®˜æ–¹æˆæƒï¼Œéå•†ä¸šè½¬è½½è¯·æ³¨æ˜å‡ºå¤„ã€‚
#include <stdio.h>

////1.0
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int sum = 0;
//    //ä¸¤ä¸¤å¼‚æˆ–
//    for (i = 0; i <= numsSize; i++)
//    {
//        sum ^= i;
//    }
//    for (i = 0; i < numsSize; ++i)
//    {
//        sum ^= nums[i];
//
//    }
//    return sum;
//}


////2.0
//int missingNumber(int* nums, int numsSize) {
//    // å­˜æ”¾åˆ°æ•°ç»„
//    int i = 0;
//    //å¼€è¾Ÿç©ºé—´,æ•°ç»„
//    int* tmp = (int*)calloc(numsSize + 1, sizeof(int));
//    if (tmp == NULL)
//    {
//        return 1;
//    }
//    //åˆå§‹åŒ–ä¸º-1
//    for (i = 0; i <= numsSize; i++)
//    {
//        tmp[i] = -1;
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//
//        tmp[nums[i]] = nums[i];
//
//
//    }
//    //å…¶ä¸­ä¸€ä¸ªå…ƒç´ æ²¡æœ‰å­˜å…¥
//    for (i = 0; i <= numsSize; i++)
//    {
//        //åˆå§‹åŒ– 0,æ’é™¤ i = 0
//        //è§£å†³æ–¹æ³•,æ”¹å˜åˆå§‹åŒ–å€¼ -1
//        if (tmp[i] != i)
//        {
//            break;
//        }
//    }
//
//    //é‡Šæ”¾ç©ºé—´
//    free(tmp);
//    tmp = NULL;
//    return i;
//}
//
//
////3.0
//int missingNumber(int* nums, int numsSize) {
//    //åŠ å’Œ0~ n,åœ¨å‡å»æ•°ç»„
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i <= numsSize; i++)
//    {
//        if (i < numsSize)
//        {
//            sum = sum + i - nums[i];
//        }
//        else
//        {
//            sum += i;
//        }
//
//    }
//    return sum;
>>>>>>> w6/main
//}



<<<<<<< HEAD
//ÑîÊÏ¾ØÕó
//ÌâÄ¿ÄÚÈİ:
//ÓĞÒ»¸öÊı×Ö¾ØÕó£¬¾ØÕóµÄÃ¿ĞĞ´Ó×óµ½ÓÒÊÇµİÔöµÄ£¬¾ØÕó´ÓÉÏµ½ÏÂÊÇµİÔöµÄ
//Çë±àĞ´³ÌĞòÔÚÕâÑùµÄ¾ØÕóÖĞ²éÕÒÄ³¸öÊı×ÖÊÇ·ñ´æÔÚ.
//ÒªÇó:Ê±¼ä¸´ÔÓ¶ÈĞ¡ÓÚo(N)£»


//1 2 3 4 
//2 3 4 5
//3 4 5 6
#include <stdio.h>
#define ROW 5
#define COL 5

//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int a = 1;
//	//³õÊ¼»¯
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			//arr[i][j] = i+j +1;
//			arr[i][j] =a++;
//		}
//	}
//	//´òÓ¡
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()º¯Êı¸ñÊ½ÒªÒ»ÖÂ
//
//	////²éÕÒn		1.0
//	//for (i = 0; i < ROW; i++)
//	//{
//	//	for (j = 0; j < COL; j++)
//	//	{
//	//		if (arr[ROW - 1][j] < n)//ÕâÒ»ÁĞÖĞÃ»ÓĞ
//	//		{
//	//			continue;
//	//		}
//	//		if (arr[i][COL - 1] >= n)//ÕâÒ»ĞĞÖĞ¿ÉÄÜ´æÔÚ
//	//		{
//	//			if (n == arr[i][j])
//	//			{
//	//				printf("´æÔÚ,arr[%d][%d] = %d\n", i, j, n);
//	//				return 0;
//	//			}
//	//		}
//	//		else
//	//			break;
//	//	}
//	//}
//
//	//²éÕÒn		2.0
//	int count = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = COL -1; j >=0; j--)
//		{
//			count++;
//			if (arr[i][COL - 1] >= n)//ÕâÒ»ĞĞÖĞ¿ÉÄÜ´æÔÚ
//			{
//				if (n == arr[i][j])
//				{
//					printf("´æÔÚ,arr[%d][%d] = %d\n", i, j, n);
//					printf("²éÕÒ´ÎÊıcount = %d\n", count);
//					return 0;
//				}
//			}
//			else
//				break;
//		}
//	}
//	printf("²»´æÔÚ.\n");
//	return 0;
//}


////2.0	²Î¿¼ºó×Ô¼ºĞ´

//int find_n(int arr[ROW][COL], int* px, int* py, int n)
//{
//	int x = 0;
//	int y = *py - 1;//Ä©Î²ÁĞ
//	while (x < *px && y >= 0)//&& ÓÅÏÈ¼¶µÍÓÚ < >=
//	{
//		if (arr[x][y] < n)//xĞĞ×î´óÖµĞ¡ÓÚ n
//		{
//			x++;
//		}
//		else if (arr[x][y] > n)//ÔÚxĞĞ¼°ÒÔºóĞĞ,µÚyÁĞ,arr[x][y]ÊÇÕâÒ»ÁĞÖĞ×îĞ¡µÄÖµ.arr[x][y]Ò²ÊÇ arr[x+i][y+i]Ö®ºóµÄ×îĞ¡Öµ
//		{
//			y--;
//		}
//		else	//²»ĞèÒªÅĞ¶ÏÊÇ·ñÏàµÈ.==> ÉÏÃæµÄarr[x][y] < n ºÍ arr[x][y] > n ÅÅ³ıÁËÆäËûÇé¿ö,Ö»Ê£ÏÂarr[x][y] == n
//		{
//			*px = x;
//			*py = y;
//			return 1;//ÕÒµ½ return 1
//		}
//	}
//	
//	return 0;//ÕÒ²»µ½ return 0
//}
//int main()
//{
//	int arr[ROW][COL] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int a = 1;
//	//³õÊ¼»¯
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (i == ROW - 1 && j == 0)
//			{
//				a = a + COL;
//			}
//			arr[i][j] =a++;
//		}
//	}
//	//´òÓ¡
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	scanf("%d", &n);//scanf()º¯Êı¸ñÊ½ÒªÒ»ÖÂ
//	//²éÕÒ
//	int x = ROW;
//	int y = COL;
//	int ret = find_n(arr, &x, &y, n);
//	if (ret == 1)
//	{
//		printf("ÕÒµ½ÁË,×ø±êx = %d,y = %d\n", x, y);
//	}
//	else
//		printf("ÕÒ²»µ½.\n");
//	return 0;
=======

//ç»™å®šä¸€ä¸ªæ•´æ•°æ•°ç»„ numsï¼Œå°†æ•°ç»„ä¸­çš„å…ƒç´ å‘å³è½®è½¬ kÂ ä¸ªä½ç½®ï¼Œå…¶ä¸­Â kÂ æ˜¯éè´Ÿæ•°ã€‚
//ç¤ºä¾‹ 1:
//è¾“å…¥: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//è¾“å‡º : [5, 6, 7, 1, 2, 3, 4]
//è§£é‡Š :
//    å‘å³è½®è½¬ 1 æ­¥ : [7, 1, 2, 3, 4, 5, 6]
//    å‘å³è½®è½¬ 2 æ­¥ : [6, 7, 1, 2, 3, 4, 5]
//    å‘å³è½®è½¬ 3 æ­¥ : [5, 6, 7, 1, 2, 3, 4]
//    ç¤ºä¾‹Â 2 :
//    è¾“å…¥ï¼šnums = [-1, -100, 3, 99], k = 2
//    è¾“å‡ºï¼š[3, 99, -1, -100]
//    è§£é‡Š :
//    å‘å³è½®è½¬ 1 æ­¥ : [99, -1, -100, 3]
//    å‘å³è½®è½¬ 2 æ­¥ : [3, 99, -1, -100]
//    æç¤ºï¼š
//    1 <= nums.length <= 105
//    - 231 <= nums[i] <= 231 - 1
//    0 <= k <= 105
//    è¿›é˜¶ï¼š
//    å°½å¯èƒ½æƒ³å‡ºæ›´å¤šçš„è§£å†³æ–¹æ¡ˆï¼Œè‡³å°‘æœ‰ ä¸‰ç§ ä¸åŒçš„æ–¹æ³•å¯ä»¥è§£å†³è¿™ä¸ªé—®é¢˜ã€‚
//    ä½ å¯ä»¥ä½¿ç”¨ç©ºé—´å¤æ‚åº¦ä¸ºÂ O(1) çš„Â åŸåœ°Â ç®—æ³•è§£å†³è¿™ä¸ªé—®é¢˜å—ï¼Ÿ
//    æ¥æºï¼šåŠ›æ‰£ï¼ˆLeetCodeï¼‰
//    é“¾æ¥ï¼šhttps ://leetcode.cn/problems/rotate-array
//è‘—ä½œæƒå½’é¢†æ‰£ç½‘ç»œæ‰€æœ‰ã€‚å•†ä¸šè½¬è½½è¯·è”ç³»å®˜æ–¹æˆæƒï¼Œéå•†ä¸šè½¬è½½è¯·æ³¨æ˜å‡ºå¤„ã€‚
#include <stdio.h>

//1.0
//void rotate(int* nums, int numsSize, int k) {
//    //memmove
//    int n = numsSize;
//    int* arr = (int*)malloc(numsSize * sizeof(int));
//    //æ‹·è´nums åˆ° arr
//    memcpy(arr, nums, n * sizeof(int));
//    k %= numsSize;
//    //n - k ä½ç½®å¼€å§‹çš„kä¸ªå…ƒç´ ç§»åŠ¨åˆ°é¦–ä½
//    memmove(nums, nums + n - k, k * sizeof(int));
//    //n - k -1 ~ n -1çš„ n - kä¸ªå…ƒç´ ç§»åŠ¨åˆ° n + kä½ç½®
//    memmove(nums + k, arr, (n - k) * sizeof(int));
//
//    free(arr);
//    arr = NULL;
//
//}

////2.0
//void rotate(int* nums, int numsSize, int k) {
//    //æ¥é•¿æ•°ç»„,æˆªå–
//    int n = numsSize;
//    k %= n;
//    int* tmp = (int*)malloc(2 * n * sizeof(int));
//    memcpy(tmp, nums, n * sizeof(int));
//    memcpy(tmp + n, nums, n * sizeof(int));
//    //æˆªå–,tmp + n - k ä½ç½®å¼€å§‹,nä¸ªå…ƒç´ 
//    memcpy(nums, tmp + n - k, n * sizeof(int));
//
//
//    free(tmp);
//    tmp = NULL;
//}

//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
////3.0
//void rotate(int* nums, int numsSize, int k) {
//    //ä¸‰æ¬¡ç¿»è½¬æ³•
//    //å‰éƒ¨åˆ†ç¿»è½¬,0 ~ n - k -1
//    int n = numsSize;
//    k %= n;
//    reverse(nums, 0, n - k - 1);
//    //åéƒ¨åˆ†ç¿»è½¬,n - k ~ n - 1
//    reverse(nums, n - k, n - 1);
//    //æ•´ä½“ç¿»è½¬,0 ~ n - 1
//    reverse(nums, 0, n - 1);
//
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    rotate(arr, sz, 14);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    return 0;
>>>>>>> w6/main
//}