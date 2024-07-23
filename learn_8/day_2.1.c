//#define _CRT_SECURE_NO_WARNINGS
//
////oj题目: 二叉树的前序遍历     二叉树的中序遍历     二叉树的后序遍历   二叉树的最大深度
//
//
////二叉树的前序遍历
////给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//
//  //求树的大小,便于开辟数组
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////子程序
////原程序不方便递归,参数不适合,利用子程序
//void _preorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)//很容易少写一个等号,注意
//    {
//        return;
//    }
//
//    arr[*pi] = root->val;
//    (*pi)++;
//
//    _preorderTraversal(root->left, arr, pi);
//    _preorderTraversal(root->right, arr, pi);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _preorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
//
////二叉树的中序遍历
////给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//
////求树的大小,便于开辟数组
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////子程序
//void _inorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    _inorderTraversal(root->left, arr, pi);
//    arr[(*pi)++] = root->val;
//    _inorderTraversal(root->right, arr, pi);
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);//输出型参数,返回开辟数组的大小
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _inorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
//
////
////二叉树的后序遍历
////给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//
////求树的大小,便于开辟数组
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return 1 + TreeSize(root->left) + TreeSize(root->right);
//}
//
////子程序
//void _postorderTraversal(struct TreeNode* root, int* arr, int* pi)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    _postorderTraversal(root->left, arr, pi);
//    _postorderTraversal(root->right, arr, pi);
//    arr[(*pi)++] = root->val;
//}
//
//
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);//输出型参数,返回开辟数组的大小
//    int* arr = (int*)malloc((*returnSize) * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//
//    int i = 0;
//    _postorderTraversal(root, arr, &i);
//    return arr;
//}
//
//
//
////104. 二叉树的最大深度
////给定一个二叉树，找出其最大深度。
////二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
////说明 : 叶子节点是指没有子节点的节点。
//
//int maxDepth(struct TreeNode* root) {
//    //思路: 1(根的这一层) + 左子树和右子树深度两者的最大值
//    if (NULL == root)
//    {
//        return 0;
//    }
//
//    int leftDepth = maxDepth(root->left);
//    int rightDepth = maxDepth(root->right);
//
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//
//
//
////110. 平衡二叉树
////给定一个二叉树，判断它是否是高度平衡的二叉树。
////本题中，一棵高度平衡二叉树定义为：
////一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//
////1.0   时间复杂度O(N*N)
//int TreeDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    int leftdepth = TreeDepth(root->left);
//    int rightdepth = TreeDepth(root->right);
//
//    return leftdepth > rightdepth ? 1 + leftdepth : 1 + rightdepth;
//}
//
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    int leftdepth = TreeDepth(root->left);
//    int rightdepth = TreeDepth(root->right);
//    if (leftdepth - rightdepth > 1 || leftdepth - rightdepth < -1)
//    {
//        return false;
//    }
//
//    return isBalanced(root->left) && isBalanced(root->right);
//}
//
//
////2.0   算法优化:时间复杂度优化为O(n)
//bool _isBalanced(struct TreeNode* root, int* depth)
//{
//    //后序遍历,减少重复计算
//
//    //最底层,空树
//    if (root == NULL)
//    {
//        *depth = 0;
//        return true;
//    }
//
//    //判断平衡,问题拆分==>节点平衡==>左子树平衡,右子树平衡
//    //需要两个返回值,判断是否平衡的 bool值,判断左右深度的数值
//    //只要为假,就返回,为真还需要继续判断,直到结束
//    //这里 *depth 这个值设置的很巧妙
//    //从最底层开始向上
//    int leftDepth = 0;
//    if (_isBalanced(root->left, &leftDepth) == false)
//    {
//        return false;
//    }
//
//    int rightDepth = 0;
//    if (_isBalanced(root->right, &rightDepth) == false)
//    {
//        return false;
//    }
//
//    //高度差判断,这才是最本质返回false 的条件,其他递归也是用到这个
//    int gap = abs(rightDepth - leftDepth);
//    if (gap > 1)
//    {
//        return false;
//    }
//
//    //返回高度
//    *depth = rightDepth > leftDepth ? rightDepth + 1 : leftDepth + 1;
//
//    return true;
//}
//
//bool isBalanced(struct TreeNode* root) {
//    //时间复杂度优化为O(n)
//    int i = 0;
//    return _isBalanced(root, &i);
//
//}