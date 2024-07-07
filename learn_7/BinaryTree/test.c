#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"


void test()
{
	BTnode* A = BTNodeCreate('A');
	BTnode* B = BTNodeCreate('B');
	BTnode* C = BTNodeCreate('C');
	BTnode* D = BTNodeCreate('D');
	BTnode* E = BTNodeCreate('E');
	BTnode* F = BTNodeCreate('F');


	A->_leftChird = B;
	A->_rightChird = C;
	B->_leftChird = D;
	B->_rightChird = E;
	E->_rightChird = F;

	//±éÀú¶þ²æÊ÷
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	//printf("%d\n", BTNodeCount(A));
	//printf("%d\n", BTNodeCount(A));

	//int n = 0;
	//BTNodeCount(A, &n);
	//printf("%d\n", n);
	//n = 0;
	//BTNodeCount(A, &n);
	//printf("%d\n", n);

	printf("%d\n", BTNodeCount(A));
	printf("%d\n", BTNodeCount(A));

	printf("%d\n", BTNodeLeafCount(A));

	printf("%d\n", BinTreeDepth(A));

}

int main()
{
	test();
	return 0;
}