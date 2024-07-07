#define _CRT_SECURE_NO_WARNINGS
#include "List.h"



void test1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

}

void test2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListNode* pos = ListFind(plist,4);
	ListInsert(plist, pos, 10);
	ListPrint(plist);
	pos = ListFind(plist, 1);
	ListInsert(plist, pos, 20);
	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);

}

void test3()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 4);
	ListErase(pos);
	ListPrint(plist);
	pos = ListFind(plist, 5);
	ListErase(pos);
	ListPrint(plist);
	pos = ListFind(plist, 1);
	ListErase(pos);
	ListPrint(plist);

	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);

	ListDestroy(plist);
	plist = NULL;


}

int main()
{
	//test1();
	//test2();
	test3();


	return 0;
}