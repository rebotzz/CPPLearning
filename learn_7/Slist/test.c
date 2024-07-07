#define _CRT_SECURE_NO_WARNINGS

#include "Slist.h"



void test1()
{
	SListNode* plist = NULL;

	SListPrint(plist);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);


}

void test2()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 3);
	int i = 1;
	while (pos != NULL)
	{
		printf("找到了%d个%d,指针:%p\n", i++, pos->data, pos);
		pos->data = 10;
		pos = SListFind(pos->next, 3);
	}

	SListPrint(plist);

}


void test3()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListDestory(&plist);
	SListPrint(plist);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 3);
	SListInsertAfter(pos, 10);
	SListPrint(plist);
	SListEraseAfter(pos);
	SListPrint(plist);

	SListEraseFront(&plist,pos);
	SListPrint(plist);


}

void test4()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 5);
	printf("找到了%d个%d,指针:%p\n", 1, pos->data, pos);
	SListEraseFront(&plist, pos);
	SListPrint(plist);

	pos = SListFind(plist, 1);
	SListInsertFront(&plist, pos, 10);
	SListPrint(plist);

}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();


	return 0;
}