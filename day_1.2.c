#define _CRT_SECURE_NO_WARNINGS

//572. 另一棵树的子树
//给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
//如果存在，返回 true ；否则，返回 false 。
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //结构判断,不相同
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }

    //数值判断,不相同
    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
    {
        return false;
    }

    //root的子树是否与subroot相同

    bool ret = isSameTree(root, subRoot);
    if (ret)
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}