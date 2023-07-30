#define _CRT_SECURE_NO_WARNINGS


//110. 平衡二叉树
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//1.0   时间复杂度O(N*N)
    int TreeDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftdepth = TreeDepth(root->left);
    int rightdepth = TreeDepth(root->right);

    return leftdepth > rightdepth ? 1 + leftdepth : 1 + rightdepth;
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    int leftdepth = TreeDepth(root->left);
    int rightdepth = TreeDepth(root->right);
    if (leftdepth - rightdepth > 1 || leftdepth - rightdepth < -1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}



//2.0   代码优化,时间复杂度O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //子程序
bool _isBalanced(struct TreeNode* root, int* depth)
{
    //后序遍历,减少重复计算

    //最底层,空树
    if (root == NULL)
    {
        *depth = 0;
        return true;
    }

    //判断平衡,问题拆分==>节点平衡==>左子树平衡,右子树平衡
    //需要两个返回值,判断是否平衡的 bool值,判断左右深度的数值
    //只要为假,就返回,为真还需要继续判断,直到结束
    //这里 *depth 这个值设置的很巧妙
    //从最底层开始向上
    int leftDepth = 0;
    if (_isBalanced(root->left, &leftDepth) == false)
    {
        return false;
    }

    int rightDepth = 0;
    if (_isBalanced(root->right, &rightDepth) == false)
    {
        return false;
    }

    //高度差判断,这才是最本质返回false 的条件,其他递归也是用到这个
    int gap = abs(rightDepth - leftDepth);
    if (gap > 1)
    {
        return false;
    }

    //返回高度
    *depth = rightDepth > leftDepth ? rightDepth + 1 : leftDepth + 1;

    return true;
}

bool isBalanced(struct TreeNode* root) {
    //时间复杂度优化为O(n)
    int i = 0;
    return _isBalanced(root, &i);

}