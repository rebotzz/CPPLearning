#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//利用链表实现二叉树
// 数组在完全二叉数构建上有优势,
// 但是非完全二叉树存在空间浪费的问题;
// 所以这里用链表构建;
//

typedef char BTDataType;
//树节点
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _leftChird;
	struct BinaryTreeNode* _rightChird;
}BTnode;

//单纯二叉树的增删查改用处不大,留在之后平衡二叉搜索树学习
////初始化
//void BinTreeInit();
////插入
//void BinTreePush();
////消除
////销毁

//节点创建(临时)
BTnode* BTNodeCreate(BTDataType x);
//二叉树遍历
//前序遍历
void PrevOrder(BTnode* root);
//中序遍历
void InOrder(BTnode* root);
//后序遍历
void PostOrder(BTnode* root);
//二叉树总节点统计
//void BTNodeCount(BTnode* root,int* pcount);//2.0
int BTNodeCount(BTnode* root);//1.0	3.0
//叶节点数统计
int BTNodeLeafCount(BTnode* root);
//求二叉树深度
int BinTreeDepth(BTnode* root);
