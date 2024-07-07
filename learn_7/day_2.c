//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
////给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
//
// //Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };
// 
//
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    //1. 
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    //2.first
//    struct ListNode* prev = head;
//    while (head->val == val)
//    {
//        head = prev->next;
//        free(prev);
//        prev = head;
//        if (head == NULL)
//        {
//            return NULL;
//        }
//    }
//    //2.5
//    if (head->next == NULL)
//    {
//        return head;
//    }
//
//    //3.other
//    struct ListNode* cur = head->next;
//    while (cur->next)
//    {
//        if (cur->val == val)
//        {
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//        }
//        else
//        {
//            cur = cur->next;
//            prev = prev->next;
//        }
//    }
//    //最后一个值
//    if (cur->val == val)
//    {
//        prev->next = cur->next;
//        free(cur);
//        cur = prev->next;
//    }
//    return head;
//}
//
//
////参考代码
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
//    dummyHead->next = head;
//    struct ListNode* temp = dummyHead;
//    while (temp->next != NULL) {
//        if (temp->next->val == val) {
//            temp->next = temp->next->next;
//        }
//        else {
//            temp = temp->next;
//        }
//    }
//    return dummyHead->next;
//}
//
//
//
//
////给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//struct ListNode* BuyNode(int x)
//{
//    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node->val = x;
//    node->next = NULL;
//    return node;
//}
//
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* cur = head;
//    struct ListNode* new = NULL;
//    struct ListNode* next = NULL;
//
//    while (cur->next != NULL)
//    {
//        //新建节点
//        if (next == NULL)
//        {
//            next = BuyNode(cur->val);
//            cur = cur->next;
//        }
//        else
//        {
//            new = BuyNode(cur->val);
//            new->next = next;
//            next = new;
//            cur = cur->next;
//        }
//    }
//    //最后一个
//    new = BuyNode(cur->val);
//    new->next = next;
//    return new;
//
//
//}
//
//
////参考代码
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* prev = NULL;
//    struct ListNode* curr = head;
//    while (curr) {
//        struct ListNode* next = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = next;
//    }
//    return prev;
//}
//
////参考代码  2.0
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* newHead = reverseList(head->next);
//    head->next->next = head;
//    head->next = NULL;
//    return newHead;
//}
//
////参考后自己写
//struct ListNode* reverseList(struct ListNode* head) {
//    //画图后再次解题
//    struct ListNode* n1, * n2, * n3;
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//
//    while (n2 != NULL)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//    }
//    return n1;
//}
//
//
////描述
////输入一个链表，输出该链表中倒数第k个结点。
//
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
//
// /**
//  *
//  * @param pListHead ListNode类
//  * @param k int整型
//  * @return ListNode类
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    int n = 0;
//    //第一次得到元素个数
//    if (pListHead == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* cur = pListHead;
//    while (cur->next)
//    {
//        n++;
//        cur = cur->next;
//    }
//    n++;
//    //k范围判断
//    if (k > n)
//    {
//        return NULL;//其实我觉得应该返回全部
//    }
//    if (k == 0)
//    {
//        return NULL;
//    }
//    //第二次找到n - k个
//    int i = n - k;
//
//    cur = pListHead;
//    while (i--)
//    {
//        cur = cur->next;
//    }
//    return cur;
//}
//
//
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
//
// /**
//  *
//  * @param pListHead ListNode类
//  * @param k int整型
//  * @return ListNode类
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    //快慢指针,间隔K,快的到终点,慢的位置正好
//    if (pListHead == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* front = pListHead;
//    struct ListNode* back = pListHead;
//    while (k--)
//    {
//        back = back->next;
//        if (back == NULL && k != 0)//越界
//        {
//            return NULL;
//        }
//    }
//    if (front == back)//0个元素
//    {
//        return NULL;
//    }
//    if (back == NULL)//全部
//    {
//        return pListHead;
//    }
//    while (back->next)
//    {
//        front = front->next;
//        back = back->next;
//    }
//    front = front->next;
//    return front;
//}
//
//
////2.0   画图分析很重要
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    //快慢指针
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    //if (pListHead == NULL)
//    //    return NULL;
//    while (k--)
//    {
//        if (fast == NULL)
//            return NULL;
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
//
//
////876. 链表的中间结点
////给你单链表的头结点 head ，请你找出并返回链表的中间结点。
////
////如果有两个中间结点，则返回第二个中间结点。
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* middleNode(struct ListNode* head) {
//    int count, middle;
//    count = 0;
//    middle = 0;
//    if (head == NULL)
//        return NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        cur = cur->next;
//        count++;
//    }
//    cur = head;
//    while (cur)
//    {
//        if (middle == count / 2)
//        {
//            break;
//        }
//        cur = cur->next;
//        middle++;
//    }
//    return cur;
//}
//
//struct ListNode* middleNode(struct ListNode* head) {
//    //快慢指针
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast != NULL && fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//
//
//
//
//
//
////将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
////失败
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//
//    struct ListNode* c1, * c2, * n1, * n2, * head, * p1, * p2;
//    c1 = list1;
//    c2 = list2;
//    n1 = list1->next;
//    n2 = list2->next;
//    p1 = NULL;
//    p2 = NULL;
//    head = ((c1->val) >= (c2->val)) ? c2 : c1;
//    while ((c1 != NULL) && (c2 != NULL))
//    {
//
//        //比较
//        if (c1->val >= c2->val)
//        {
//            printf("head = %d,%p\n", head->val, head);
//            printf("c1 = %d ,c2 = %d\n", c1->val, c2->val);
//            c2->next = c1;
//            if (p1 == NULL)
//                p1 = c2;
//            else
//                p1->next = c2;
//            c2 = n2;
//            if (n2)
//                n2 = n2->next;
//        }
//        else if (c1->val < c2->val)
//        {
//            printf("head = %d,%p\n", head->val, head);
//            printf("c1 = %d ,c2 = %d\n", c1->val, c2->val);
//            c1->next = c2;
//            if (p2 == NULL)
//                p2 = c1;
//            else
//                p2->next = c1;
//            c1 = n1;
//            if (n1)
//                n1 = n1->next;
//        }
//
//        // if(cur1->val <= cur2->val)
//        // {
//
//        //     cur1->next = cur2;
//        //     cur1 = next1;
//        //     if(next1)
//        //         next1 = next1->next;
//        // }
//        // else
//        // {
//        //     cur2->next = cur1;
//        //     cur2 = next2;
//        //     if(next2)
//        //         next2 = next2->next;
//        // }    
//
//    }
//    return head;
//}
//
//
////成功
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//struct ListNode* buynode(int x)
//{
//    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node->next = NULL;
//    node->val = x;
//    return node;
//}
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//    struct ListNode* c1, * c2, * phead, * c3;
//    c1 = list1;
//    c2 = list2;
//    c3 = NULL;
//    // int min = (c1->val)>=(c2->val)?c2->val:c1->val;
//    // phead = buynode(min);
//    phead = NULL;
//    while (c1 && c2)
//    {
//        if (c1->val >= c2->val)
//        {
//            if (phead == NULL)
//            {
//                c3 = buynode(c2->val);
//                phead = c3;
//            }
//            if (c3)
//            {
//                c3->next = buynode(c2->val);
//            }
//            c2 = c2->next;
//        }
//        else
//        {
//            if (phead == NULL)
//            {
//                c3 = buynode(c1->val);
//                phead = c3;
//            }
//            if (c3)
//            {
//                c3->next = buynode(c1->val);
//            }
//            c1 = c1->next;
//        }
//        c3 = c3->next;
//    }
//    if (c1)
//        c3->next = c1;
//    if (c2)
//        c3->next = c2;
//
//    return phead->next;
//}
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
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* l1 = list1, * l2 = list2;
//    struct ListNode* head, * tail;
//    //其中一个为空
//    if (l1 == NULL)
//        return l2;
//    if (l2 == NULL)
//        return l1;
//    //两个不为空
//    if (l1->val < l2->val)
//    {
//        head = l1;
//        l1 = l1->next;
//    }
//    else
//    {
//        head = l2;
//        l2 = l2->next;
//    }
//    tail = head;
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            tail->next = l1;
//            l1 = l1->next;
//        }
//        else
//        {
//            tail->next = l2;
//            l2 = l2->next;
//        }
//        tail = tail->next;
//    }
//    //其中一个结束,另一条链还有
//    if (l1)
//    {
//        tail->next = l1;
//    }
//
//    if (l2)
//    {
//        tail->next = l2;
//    }
//
//    return head;
//
//}
//
//
//
////描述
////现有一链表的头指针 ListNode* pHead，给一定值x，
////编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//#include <cstddef>
//#include <list>
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//        if (!pHead)
//        {
//            return pHead;
//        }
//        ListNode* p = pHead;
//        ListNode* head1, * head2, * tail1, * tail2;
//        head1 = head2 = tail1 = tail2 = nullptr;
//        head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//        // head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//        // tail2->next = nullptr;
//
//        while (p)
//        {
//            if (p->val < x)
//            {
//                tail1->next = p;
//                tail1 = tail1->next;
//            }
//            else {
//                // tail2->next = p;
//                // tail2 = tail2->next; 
//                if (head2 == nullptr)
//                {
//                    head2 = tail2 = p;
//                }
//                else {
//                    tail2->next = p;
//                    tail2 = tail2->next;
//                }
//            }
//            p = p->next;
//        }
//
//        //小于和大于部分续借
//        if (head2)
//        {
//            tail1->next = head2;
//        }
//        ListNode* list = head1->next;
//        free(head1);
//        // free(head2);
//        head1 = nullptr;
//
//        return list;
//
//    }
//};
//
//
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//#include <cstddef>
//#include <list>
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//        if (!pHead)
//        {
//            return pHead;
//        }
//        ListNode* p = pHead;
//        ListNode* head1, * head2, * tail1, * tail2;
//        head1 = head2 = tail1 = tail2 = nullptr;
//        // head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//        // head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//        // tail2->next = nullptr;
//
//        while (p)
//        {
//            if (p->val < x)
//            {
//                if (head1 == nullptr)
//                {
//                    head1 = tail1 = p;
//                }
//                else {
//                    tail1->next = p;
//                    tail1 = tail1->next;
//                }
//            }
//            else {
//                // tail2->next = p;
//                // tail2 = tail2->next; 
//                if (head2 == nullptr)
//                {
//                    head2 = tail2 = p;
//                }
//                else {
//                    tail2->next = p;
//                    tail2 = tail2->next;
//                }
//            }
//            // printf("%d,",p->val);
//            p = p->next;
//        }
//
//        //如果x大于所有值
//        if (head1 == nullptr)
//        {
//            return head2;
//        }
//        //小于和大于部分续借
//        if (head2)
//        {
//            tail1->next = head2;
//        }
//
//        // ListNode* list = head1->next;
//        // free(head1);
//        // free(head2);
//        // head1 = nullptr;
//
//        return head1;
//
//    }
//};
//
