//#define _CRT_SECURE_NO_WARNINGS
//
////100. 相同的树
////给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
////如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//
//    //结构判断,不相同
//    if (p == NULL && q != NULL)
//    {
//        return false;
//    }
//    if (p != NULL && q == NULL)
//    {
//        return false;
//    }
//
//    //数值判断,不相同
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//注意p,q别写错
//}