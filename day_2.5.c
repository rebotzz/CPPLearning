#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

//判断一颗树是否是完全二叉树     二叉树第k层节点个数
//队列实现

typedef char TreeDataType;
typedef struct TreeNode
{
	TreeDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//判断一颗树是否是完全二叉树
bool isCompleteTree(TreeNode* root)
{
    //利用队列先进先出的特点实现
    if (NULL == root)
    {
        return;
    }

    queue q;
    QueueInit(&q);
    QueuePush(&q, root);

    while (!QueueEmpty(&q))
    {
        //出队一个数,就把它的孩子入队,由于先进先出,第K层出队,第K+1层入队
        //完全二叉树的 NULL 指针是连续的,中间没有别的指针
        TreeNode* front = QueueFront(&q);
        if (front == NULL)//遇到空指针结束循环.总的结束循环的条件,但是二叉树不一定全部入队,只适用判断完全二叉树
        {
            break;
        }
        QueuePop(&q);
        //这里子树的指针都Push进队列,没有排除 NULL
        QueuePush(&q, front->left);
        QueuePush(&q, front->right);
    }

    //判断空指针是否连续
    while (!QueueEmpty(&q))
    {
        if (QueueFront(&q) != NULL)
        {
            return false;
        }
        QueuePop(&q);
    }

    //销毁队列
    QueueDestroy(&q);
    //如果队列结束了,都没返回false,那么就是完全二叉树
    return true;
}

TreeNode* TreeNodeCreate(TreeDataType val)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

//判断一颗树是否是完全二叉树
void test()
{
    TreeNode* A = TreeNodeCreate('a');
    TreeNode* B = TreeNodeCreate('b');
    TreeNode* C = TreeNodeCreate('c');
    TreeNode* D = TreeNodeCreate('d');
    TreeNode* E = TreeNodeCreate('e');
    //TreeNode* F = TreeNodeCreate('f');


    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    //D->right = F;

    printf("%d\n", isCompleteTree(A));
}

int TreeNodeCountK(TreeNode* root,int k)
{
    //思路:问题拆分,第K层节点个数 == 左子树+右子树 (第K - 1层节点个数)
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }

    if (k > 0)
    {
        return TreeNodeCountK(root->left, k - 1) + TreeNodeCountK(root->right, k - 1);
    }
}

//二叉树第k层节点个数
void test2()
{
    TreeNode* A = TreeNodeCreate('a');
    TreeNode* B = TreeNodeCreate('b');
    TreeNode* C = TreeNodeCreate('c');
    TreeNode* D = TreeNodeCreate('d');
    TreeNode* E = TreeNodeCreate('e');
    TreeNode* F = TreeNodeCreate('f');


    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    printf("%d \n", TreeNodeCountK(A, 3));
}

int main()
{
    //test();
    test2();

    return 0;
}