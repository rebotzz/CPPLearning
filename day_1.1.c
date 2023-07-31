//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//
////226. 翻转二叉树
////给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//
///**
// * Definition for a binary tree node.
//
//
// */
//struct TreeNode {
//   int val;
//   struct TreeNode* left;
//   struct TreeNode* right;
//    
//};
//
////方法一:前序
//struct TreeNode* invertTree(struct TreeNode* root) 
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//    
//    //不,不是交换数组,而是改变左右指向的指针
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//    
//    invertTree(root->left);
//    invertTree(root->right);
//    return root;
//}
//
//
////方法二:中序和后序结合
//struct TreeNode* invertTree(struct TreeNode* root) 
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    //不,不是交换数组,而是改变左右指向的指针
//    struct TreeNode* right = root->right;
//    root->right = invertTree(root->left);
//    root->left = invertTree(right);
//
//    return root;
//}