#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"




//节点创建(临时)
BTnode* BTNodeCreate(BTDataType x)
{
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	if (NULL == newnode)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_leftChird = NULL;
	newnode->_rightChird = NULL;
	return newnode;
}

//二叉树遍历
//前序遍历
void PrevOrder(BTnode* root)
{
	//结束条件:问题不能在拆解,不能再分解子树了
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//根	左子树	右子树
	printf("%c ", root->_data);
	PrevOrder(root->_leftChird);
	PrevOrder(root->_rightChird);
}
//中序遍历
void InOrder(BTnode* root)
{
	//结束条件:问题不能在拆解,不能再分解子树了
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//左子树	根	右子树
	InOrder(root->_leftChird);	//记得是调用自己InOrder,别搞错弄出前序调用
	printf("%c ", root->_data);
	InOrder(root->_rightChird);
}
//后序遍历
void PostOrder(BTnode* root)
{
	//结束条件:问题不能在拆解,不能再分解子树了
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//左子树	右子树	根	
	PostOrder(root->_leftChird);
	PostOrder(root->_rightChird);
	printf("%c ", root->_data);
}

//二叉树总节点统计
//
//1.0	静态变量或者全局变量实现.但是第二次使用如果count不初始化,结果叠加
//int glo_count;// = 0;//全局不初始化默认为0
//int BTNodeCount(BTnode* root)
//{
//	static int count = 0;
//	if (NULL == root)
//	{
//		return 0;
//	}
//	//利用遍历,递归,调用自己
//	count++;
//	BTNodeCount(root->_leftChird);
//	BTNodeCount(root->_rightChird);
//	return count;
//}
//
//2.0	利用传出参数
//void BTNodeCount(BTnode* root,int* pcount)
//{
//	if (NULL == root)
//	{
//		return;
//	}
//	//利用遍历,递归,调用自己
//	(*pcount)++;
//	BTNodeCount(root->_leftChird, pcount);
//	BTNodeCount(root->_rightChird, pcount);
//}
//
//3.0	递归实现(推荐使用):根的1个节点 + 左子树节点数 + 右子树节点数
int BTNodeCount(BTnode* root)
{
	if (NULL == root)
	{
		return 0;
	}
	return 1 + BTNodeCount(root->_leftChird) + BTNodeCount(root->_rightChird);
}

//叶节点数统计
int BTNodeLeafCount(BTnode* root)
{
	//思路:叶节点数 = 左子树叶 + 右子树叶
	if (root == NULL)
	{
		return 0;
	}
	if (root->_leftChird == NULL && root->_rightChird == NULL)//是叶子
	{
		return 1;
	}
	return BTNodeLeafCount(root->_leftChird) + BTNodeLeafCount(root->_rightChird);
}
//求二叉树深度
int BinTreeDepth(BTnode* root)
{
	//思路:深度 = 1(根这一层) + 子树中最深的一个的深度
	if (NULL == root)
	{
		return 0;
	}

	int Ldeep = BinTreeDepth(root->_leftChird);
	int Rdeep = BinTreeDepth(root->_rightChird);
	int deeper = Ldeep > Rdeep ? Ldeep : Rdeep;
	return 1 + deeper;
}