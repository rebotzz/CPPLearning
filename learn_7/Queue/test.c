#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"


void test()
{
	queue q;
	//´´½¨
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d\n", QueueSize(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("%d\n", QueueSize(&q));
	//printf("%d \n", QueueFront(&q));

	//QueuePop(&q);
	QueuePush(&q, 10);
	QueuePush(&q, 20);
	printf("%d \n", QueueBack(&q));

	//while (!QueueEmpty(&q))
	//{
	//	printf("%d ", QueueFront(&q));
	//	QueuePop(&q);
	//}
	//printf("\n");

	printf("%d\n", QueueSize(&q));



	//Ïú»Ù
	QueueDestroy(&q);

}

int main()
{
	test();
	return 0;
}