//#define _CRT_SECURE_NO_WARNINGS
//
//
////二叉树遍历	二叉树查找
////编一个程序，读入用户输入的一串先序遍历字符串，
////根据此字符串建立一个二叉树（以指针方式存储）。 
////例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
////建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char TreeDataType;
//typedef struct TreeNode
//{
//	TreeDataType val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//}TreeNode;
//
////创建树节点
//TreeNode* creatTreeNode(TreeDataType val)
//{
//	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//	if (node == NULL)
//	{
//		perror("malloc");
//		exit(-1);
//	}
//	node->val = val;
//	node->left = node->right = NULL;
//	return node;
//}
//
////用字符串创建二叉树,先序
//TreeNode* CreatBinatyTreeByStr(char* str,int* pi)
//{
//	if (*(str + *pi) != '\0')
//	{
//		if (*(str + *pi) == '#')
//		{
//			(*pi)++;
//			return NULL;
//		}
//
//		//不是空,复制一个节点
//		TreeNode* root = creatTreeNode(*(str + (*pi)));
//		(*pi)++;//每一层递归的值都可能会变,所以用指向外界的指针确保;
//		//链接
//		root->left = CreatBinatyTreeByStr(str, pi);
//		root->right = CreatBinatyTreeByStr(str, pi);
//
//		return root;
//	}
//	return NULL;
//}
//
//void InOrder(TreeNode* root)
//{
//	if (NULL == root)
//	{
//		return;
//	}
//
//
	//InOrder(root->left);
	//printf("%c ", root->val);
	//InOrder(root->right);
//}
//
////二叉树查找
//TreeNode* BinaryFind(TreeNode* root ,TreeDataType val)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//
//	if (root->val == val)
//	{
//		printf("%c\n", root->val);
//		return root;
//	}
//
//	TreeNode* left = BinaryFind(root->left, val);
//	if (left != NULL)
//	{
//		return left;
//	}
//	TreeNode* right = BinaryFind(root->right, val);
//	if (right != NULL)
//	{
//		return right;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	char str[100] = { 0 };
//	while (scanf("%s", str) != EOF)
//	{
//		//用字符串创建二叉树,先序
//		int i = 0;
//		TreeNode* root =  CreatBinatyTreeByStr(str,&i);
//
//		//中序遍历输出
//		InOrder(root);
//		printf("\n");
//
//		//查找
//		TreeNode* p = BinaryFind(root, 'F');
//		printf("%p\n", p);
//		if (p != NULL)
//		{
//			printf("%c\n", p->val);
//		}
//
//	}
//	return 0;
//}