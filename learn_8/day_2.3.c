//#define _CRT_SECURE_NO_WARNINGS
//
//
////OJ题目: 单值二叉树   二叉树的深度  翻转二叉树   相同的树    另一棵树的子树 对称二叉树   二叉树的镜像  判断对称二叉树
////  复制二叉树   销毁复制的树(销毁二叉树)
//
//
////965. 单值二叉树
////如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
////只有给定的树是单值二叉树时，才返回 true；否则返回 false。
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
// //子程序
//bool _isUnivalTree(struct TreeNode* root, int val)
//{
//    //遍历,左子树是,右子树是.
//    //返回真继续,直到结束;返回假结束;
//    if (NULL == root)
//    {
//        return true;
//    }
//
//    if (_isUnivalTree(root->left, val) == false)
//    {
//        return false;
//    }
//    if (_isUnivalTree(root->right, val) == false)
//    {
//        return false;
//    }
//
//    if (root->val != val)
//    {
//        return false;
//    }
//
//    return true;
//}
//
//bool isUnivalTree(struct TreeNode* root)
//{
//    //原函数的root->val不适合递归,所以用子函数;
//    int val = root->val;
//    return _isUnivalTree(root, val);
//}
//
//
//
////二叉树的深度
////输入一棵二叉树的根节点，求该树的深度。
////从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
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
//
//
//int maxDepth(struct TreeNode* root) {
//    //1 + max(左子树深度,右子树深度)
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
//
////226. 翻转二叉树
////给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//
////1.0   方法一:前序
//struct TreeNode* invertTree(struct TreeNode* root) {
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
//
////2.0   方法二:中序和后序结合
//struct TreeNode* invertTree(struct TreeNode* root) {
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
//
//
//
////100. 相同的树
////给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
////如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//
//
//
////572. 另一棵树的子树
////给你两棵二叉树 root 和 subRoot 。
////检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
////二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    //root的子树是否与subroot相同
//    if (isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
//
//
////剑指 Offer 27. 二叉树的镜像
////请完成一个函数，输入一个二叉树，该函数输出它的镜像。
//struct TreeNode* mirrorTree(struct TreeNode* root) {
//    //左子树 , 右子树分别翻转
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    struct TreeNode* preleft = root->left;
//    root->left = mirrorTree(root->right);
//    root->right = mirrorTree(preleft);
//
//    return root;
//}
//
//
////101. 对称二叉树
////给你一个二叉树的根节点 root ， 检查它是否轴对称。
//
//
// //创建树节点
//struct TreeNode* creatTreeNode(int val)
//{
//    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node->val = val;
//    node->left = node->right = NULL;
//    return node;
//}
//
//
////复制二叉树
//struct TreeNode* copyTree(struct TreeNode* root)
//{
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    //复制树 ==>制造根节点 + 复制左子树 + 复制右子树 ,然后链接根
//    struct TreeNode* cpyroot = creatTreeNode(root->val);
//    cpyroot->left = copyTree(root->left);
//    cpyroot->right = copyTree(root->right);
//
//    return cpyroot;
//}
//
//// 翻转二叉树
//struct TreeNode* mirrorTree(struct TreeNode* root) {
//    //左子树 , 右子树分别翻转
//    if (NULL == root)
//    {
//        return NULL;
//    }
//
//    struct TreeNode* preleft = root->left;
//    root->left = mirrorTree(root->right);
//    root->right = mirrorTree(preleft);
//
//    return root;
//}
//
////判断是否是相同的树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//
////销毁复制的树
// //销毁二叉树  1.0 根节点销毁了,但没有置空,需要外界置空.优点:保证了接口参数的一致性
//void DestroyTree(struct TreeNode* root)
//{
//    if (NULL == root)
//    {
//        return;
//    }
//
//    DestroyTree(root->left);
//    DestroyTree(root->right);
//    free(root);
//}
//  //2.0   传递二级指针,置空根节点
////void DestroyTree(struct TreeNode** root)
////{
////    if (NULL == *root)
////    {
////        return;
////    }
////
////    DestroyTree((*root)->left);
////    DestroyTree((*root)->right);
////    free(*root);
////}
//
//bool isSymmetric(struct TreeNode* root) {
//    //思路:复制该二叉树,翻转复制后的树,比较翻转后与原来的树是否相同,销毁复制的树
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    //复制树
//    struct TreeNode* cpy = copyTree(root);
//
//    //翻转树
//    cpy = mirrorTree(cpy);
//
//    //比较树
//    bool ret = isSameTree(root, cpy);
//
//    //销毁复制的树
//    DestroyTree(cpy);
//	  cpy = NULL;
//    return ret;
//}
//
//
////2.0   算法优化: 空间复杂度是 O(n)，空间复杂度是递归的深度，也就是跟树高度有关
//// 
////子程序
//bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
//{
//    //左子树的左 == 右子树的右
//    //左子树的右 == 右子树的左
//    if (left == NULL && right == NULL)
//    {
//        return true;
//    }
//
//    //结构对称判断
//    if (left == NULL && right != NULL)
//    {
//        return false;
//    }
//    if (left != NULL && right == NULL)
//    {
//        return false;
//    }
//
//    //数值对称判断
//    if (left->val != right->val)
//    {
//        return false;
//    }
//
//    //注意左右颠倒;判断两个数是否相同的应用
//    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    //左子树的左 == 右子树的右
//    //左子树的右 == 右子树的左
//    if (NULL == root)
//    {
//        return true;
//    }
//
//    struct TreeNode* leftTree = root->left;
//    struct TreeNode* rightTree = root->right;
//
//    return _isSymmetric(leftTree, rightTree);
//}