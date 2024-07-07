#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

void test1()
{
	stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);

	//printf("%d \n", StackTop(&s));
	//StackPop(&s);

	StackPush(&s, 3);
	StackPush(&s, 4);

	printf("%d\n", StackSize(&s));

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");

	printf("%d\n", StackSize(&s));
	//StackPop(&s);
	//StackTop(&s);
	StackPush(&s, 10);
	StackPush(&s, 20);
	printf("%d ", StackTop(&s));
	StackPop(&s);
	StackDestroy(&s);
}

int main()
{
	test1();

	return 0;
}