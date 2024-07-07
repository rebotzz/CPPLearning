//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
////Definition for singly-linked list.
//typedef struct ListNode {
//    int val;
//    struct ListNode* next;
//}ListNode;
//
//void SLprint(ListNode* phead)
//{
//    if (!phead)
//        return;
//    while (phead)
//    {
//        printf("%d->", phead->val);
//        phead = phead->next;
//    }
//    printf("->NULL\n");
//}
//
//////138. 复制带随机指针的链表
//////给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//////构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
//////新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//////复制链表中的指针都不应指向原链表中的节点 。
//////例如，如果原链表中有 X 和 Y 两个节点，其中 X.random-- > Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random-- > y 。
//////返回复制链表的头节点。
//////用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个[val, random_index] 表示：
//////val：一个表示 Node.val 的整数。
//////random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 。
//////你的代码 只 接受原链表的头节点 head 作为传入参数。
////
////
/////**
//// * Definition for a Node.
//// * struct Node {
//// *     int val;
//// *     struct Node *next;
//// *     struct Node *random;
//// * };
//// */
////
//// //创建节点
////struct Node* buyNode(int x)
////{
////    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
////    newnode->val = x;
////    newnode->next = NULL;
////    newnode->random = NULL;
////    return newnode;
////}
////struct Node* copyRandomList(struct Node* head) {
////    //拷贝val
////    struct Node* cur = head, * cphead = NULL, * tail = NULL;
////    int count = 0;
////    while (cur)
////    {
////        if (cphead == NULL)
////        {
////            cphead = tail = buyNode(cur->val);
////            count++;
////        }
////        else
////        {
////            tail->next = buyNode(cur->val);
////            tail = tail->next;
////            count++;
////        }
////        printf("0arr:val:%d,random:%p\n", cur->val, cur->random);
////        printf("0cp :val:%d,random:%p\n", tail->val, tail->random);
////        cur = cur->next;
////    }
////    //建立一个数组存储每个节点地址,指针数组,数组名,二级指针
////    //连续存储,地址偏移量i确定random指向
////    //debug: malloc开辟的空间不一定连续,改为calloc试试,也不行?
////    struct Node** arr = (struct Node**)calloc((count), sizeof(struct Node*));
////    struct Node** cp = (struct Node**)calloc((count), sizeof(struct Node*));
////    cur = head;
////    tail = cphead;
////    int i = 0;
////    while (i < count)
////    {
////        arr[i] = cur;
////        cp[i] = tail;
////        cur = cur->next;
////        tail = tail->next;
////        i++;
////    }
////    //random拷贝
////    i = 0;
////    while (i < count)
////    {
////        if ((arr[i])->random == NULL)
////        {
////            (cp[i])->random = NULL;
////        }
////        else
////        {
////            (cp[i])->random = cp[0] + ((arr[i])->random - arr[0]);//两个指针数组地址偏移量相对应;
////        }
////        if (arr[i]->val == 784)
////        {
////            printf("arr:val = %d,random = %p,r->v:%d\n", (arr[i])->val,
////                (arr[i])->random, (arr[i])->random->val);
////        }
////        printf("arr:%d  val:%d,random:%p\n", i, (arr[i])->val, (arr[i])->random);
////        printf("cp: %d  val:%d,random:%p\n", i, (cp[i])->val, (cp[i])->random);
////        i++;
////    }
////    //free
////     free(arr);
////     free(cp);
////     arr = cp = NULL;
////    return cphead;
////}
////
////
/////**
//// * Definition for a Node.
//// * struct Node {
//// *     int val;
//// *     struct Node *next;
//// *     struct Node *random;
//// * };
//// */
////struct Node* buyNode(int x)
////{
////    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
////    newnode->val = x;
////    newnode->next = NULL;
////    newnode->random = NULL;
////    return newnode;
////}
////struct Node* copyRandomList(struct Node* head) {
////    if (!head)
////    {
////        return NULL;
////    }
////    //参考评论区别人的代码
////    struct Node* n1, * n2;
////    n1 = head;
////    n2 = head->next;
////    //中间插入
////    while (n1)
////    {
////        struct Node* newnode = buyNode(n1->val);
////        n1->next = newnode;
////        newnode->next = n2;
////        n1 = n2;
////        if (n2)
////        {
////            n2 = n2->next;
////        }
////    }
////    struct Node* old, * new;
////    old = head;
////    new = head->next;
////    //拷贝random
////    while (old)
////    {
////        if (old->random != NULL)
////        {
////            new->random = old->random->next;
////        }
////        old = old->next->next;
////        if (new->next)
////        {
////            new = new->next->next;
////        }
////    }
////    //拆分
////    old = n1 = head;      //头
////    new = n2 = head->next;//头
////    while (old)
////    {
////        old->next = old->next->next;
////        old = old->next;
////        if (new->next)
////        {
////            new->next = new->next->next;
////        }
////        new = new->next;
////    }
////    return n2;
////}
//
//
//
//
//
//
//
////147. 对链表进行插入排序
////给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
////插入排序 算法的步骤 :
////插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
////每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
////重复直到所有输入数据插入完为止。
////下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。
////每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。
////对链表进行插入排序。
//
// 
//
//////1.0
////struct ListNode* insertionSortList(struct ListNode* head) {
////    if (head == NULL)
////    {
////        return NULL;
////    }
////    //哨兵位
////    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
////    //复制首元素 ,防止尾插时改变pcur指向下一位的地址
////    ListNode* cpyhead = (ListNode*)malloc(sizeof(ListNode));//但是这个该怎么free呢?
////    cpyhead->val = head->val;
////    cpyhead->next = NULL;
////    prev->next = cpyhead;
////    int max, min;
////    max = min = head->val;
////    struct ListNode* cur = head->next, * tail = cpyhead,*pcur = head;
////    while (cur)
////    {
////        //取出cur节点
////        if (pcur->next)
////        {
////            pcur->next = pcur->next->next;
////            cur->next = NULL;
////        }
////        //<min,头插
////        if (cur->val < min)
////        {
////            cur->next = prev->next;
////            prev->next = cur;
////            min = cur->val;
////        }
////        //>max,尾插
////        else if (cur->val >= max)
////        {
////            tail->next = cur;
////            tail = tail->next;
////            max = cur->val;
////        }
////        //中间
////        else
////        {
////            struct ListNode* n1 = prev->next;
////            while (1)
////            {
////                if (cur->val >= n1->val && cur->val < n1->next->val)
////                {
////                    cur->next = n1->next;
////                    n1->next = cur;
////                    break;
////                }
////                n1 = n1->next;
////            }
////        }
////        cur = pcur->next;
////    }
////    //tail->next = NULL;
////    struct ListNode* newhead = prev->next;
////    free(prev);
////    prev = NULL;
////    return newhead;
////}
//
//
////int main()
////{
////    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
////    //ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
////    n1->next = n2;
////    n2->next = n3;
////    n3->next = n4;
////    n4->next = NULL;
////    //n5->next = NULL;
////    n1->val = 4;
////    n2->val = 2;
////    n3->val = 10;
////    n4->val = 3;
////    //n5->val = 1;
////
////    SLprint(n1);
////    ListNode* ret = insertionSortList(n1);
////    SLprint(ret);
////
////
////    return 0;
////}
//
//
////2.0
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    //参考后自己实现
//    struct ListNode* n1, * n2, * n3;
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = head;
//    n1 = prehead;
//    n2 = head;
//    n3 = head->next;
//    while (n3)
//    {
//        n1 = prehead;
//        //找n2之前适合插入n3的位置
//        while (n1->next->val <= n3->val && n1 != n2)// 
//        {
//            n1 = n1->next;
//        }
//        if (n1 != n2)//需要插入
//        {
//            n2->next = n3->next;
//            n3->next = n1->next;
//            n1->next = n3;
//            n3 = n2->next;
//        }
//        else
//        {
//            n3 = n3->next;
//            n2 = n2->next;
//        }
//
//    }
//    head = prehead->next;
//    free(prehead);
//    prehead = NULL;
//    return head;
//}
//
//
//
////删除链表中重复的结点
////描述
////在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
////例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5
//
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param pHead ListNode类
//  * @return ListNode类
//  */
////struct ListNode* deleteDuplication(struct ListNode* pHead) {
////    if (pHead == NULL)
////    {
////        return NULL;
////    }
////    // write code here
////    //这是删掉多余重复项目的版本
////    struct ListNode* n1, * n2;
////    n1 = pHead;
////    n2 = pHead->next;
////    while (n2)
////    {
////        if (n1->val == n2->val)
////        {
////            n1->next = n2->next;
////            free(n2);
////            n2 = n1->next;
////        }
////        else
////        {
////            n1 = n1->next;
////            n2 = n2->next;
////        }
////    }
////    return pHead;
////}
//
//
////1.0   功能未完善
//struct ListNode* deleteDuplication(struct ListNode* pHead) {
//    if (pHead == NULL)
//    {
//        return NULL;
//    }
//    // write code here
//    //这是删掉多余重复项目的版本
//    struct ListNode* n1, * n2, * n3;
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = pHead;
//    n1 = prehead;
//    n2 = pHead;
//    n3 = pHead->next;
//    int flag = 0;
//    while (n3)
//    {
//        if (n2->val == n3->val)
//        {
//            n2->next = n3->next;
//            free(n3);
//            n3 = n2->next;
//            flag = 1;
//            if (n3 == NULL)
//            {
//                free(n2);
//            }
//        }
//        else
//        {
//            if (flag == 1)
//            {
//                n1->next = n2->next;
//                free(n2);
//                if (n1->next == NULL)
//                {
//                    break;
//                }
//                n2 = n1->next;
//                n3 = n2->next;
//
//                flag = 0;
//            }
//            else if (flag == 0)
//            {
//                n1 = n1->next;
//                n2 = n2->next;
//                n3 = n3->next;
//            }
//        }
//    }
//    pHead = prehead->next;
//    free(prehead);
//    prehead = NULL;
//    return pHead;
//}
//
//
////2.0 功能不完善
///**
// * struct ListNode {
// *  int val;
// *  struct ListNode *next;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param pHead ListNode类
//  * @return ListNode类
//  */
//struct ListNode* deleteDuplication(struct ListNode* pHead) {
//    if (pHead == NULL) {
//        return NULL;
//    }
//    if (pHead->next == NULL) {
//        return pHead;
//    }
//    if (pHead->val == pHead->next->val && pHead->next->next == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* n1, * n2, * n3;
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = pHead;
//    n1 = prehead;
//    n2 = prehead->next;
//    n3 = prehead->next->next;
//    int flag = 0;
//    while (pHead->val == pHead->next->val && pHead->next != NULL)
//    {
//        prehead->next = pHead->next;
//        free(pHead);
//        pHead = prehead->next;
//        flag = 1;
//    }
//    if (flag == 1)
//    {
//        prehead->next = pHead->next;
//        free(pHead);
//        flag = 0;
//        if (prehead->next == NULL)
//        {
//            return NULL;
//        }
//        if (prehead->next->next == NULL)
//        {
//            return prehead->next;
//        }
//    }
//    // write code here
//    //这是删掉多余重复项目的版本
//
//    while (n3) {
//        if (n2->val == n3->val) {
//            n2->next = n3->next;
//            free(n3);
//            n3 = n2->next;
//            flag = 1;
//            if (n3 == NULL)
//            {
//                 free(n2);
//                 n1->next = NULL;
//            }
//        }
//        else {
//            if (flag == 1) {
//                n1->next = n2->next;
//                free(n2);
//                if (n1->next == NULL) {
//                    break;
//                }
//                n2 = n1->next;
//                n3 = n2->next;
//
//                flag = 0;
//            }
//            else if (flag == 0) {
//                n1 = n1->next;
//                n2 = n2->next;
//                n3 = n3->next;
//            }
//        }
//    }
//    pHead = prehead->next;
//    free(prehead);
//    prehead = NULL;
//    return pHead;
//}
//
////3.0   最终修改版
///**
// * struct ListNode {
// *  int val;
// *  struct ListNode *next;
// * };
// */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  *
//  * @param pHead ListNode类
//  * @return ListNode类
//  */
//#include <stdio.h>
//
//void destory(struct ListNode* head) {
//    if (head == NULL) {
//        return;
//    }
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = head;
//    while (head) {
//        prehead->next = head->next;
//        free(head);
//        head = prehead->next;
//    }
//    free(prehead);
//}
//
//struct ListNode* deleteDuplication(struct ListNode* pHead) {
//    if (pHead == NULL) {
//        return NULL;
//    }
//    if (pHead->next == NULL) {
//        return pHead;
//    }
//    // write code here
//    // int arr[100] = {0};
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = pHead;
//    struct ListNode* n1, * n2, * prev, * n3 = NULL;
//    n1 = pHead;
//    n2 = prev = pHead->next;
//    int flag = 0;
//
//    //找到头
//    while (n1->val == n2->val && n2 != NULL) {
//        while (n1->val == n2->val && n2 != NULL) {
//            prev = n2;
//            n2 = n2->next;
//        }
//        prev->next = NULL;
//        destory(n1);
//        prehead->next = n2;
//        if (n2 == NULL) {
//            return n2;
//        }
//        n1 = n2;
//        n2 = n2->next;
//
//
//    }
//
//    //删除头后面的
//    n1 = prehead;
//    n2 = prehead->next;
//    if (prehead->next) {
//        n3 = prehead->next->next;
//    }
//
//    while (n3) {
//        if (n2->val == n3->val) {
//            n2->next = n3->next;
//            free(n3);
//            n3 = n2->next;
//            flag = 1;
//            if (n3 == NULL) {
//                free(n2);
//                n1->next = NULL;
//            }
//        }
//        else {
//            if (flag == 1) {
//                n1->next = n2->next;
//                free(n2);
//                if (n1->next == NULL) {
//                    break;
//                }
//                n2 = n1->next;
//                n3 = n2->next;
//
//                flag = 0;
//            }
//            else if (flag == 0) {
//                n1 = n1->next;
//                n2 = n2->next;
//                n3 = n3->next;
//            }
//        }
//    }
//
//
//    return prehead->next;
//
//
//}
//
//
//int main()
//{
//    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = NULL;
//    n1->val = 1;
//    n2->val = 1;
//    n3->val = 1;
//    n4->val = 1;
//    n5->val = 4;
//
//    SLprint(n1);
//    ListNode* ret = deleteDuplication(n1);
//    SLprint(ret);
//
//
//    return 0;
//}