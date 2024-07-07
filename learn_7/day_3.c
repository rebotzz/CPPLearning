//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct ListNode {
//    int val;
//    struct ListNode *next;
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
//
//
//
//
//
////OR36 链表的回文结构
////描述
////对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
////给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
////测试样例：
//
//
////typedef struct ListNode {
////    int val;
////    struct ListNode *next;
////}ListNode;
////
////int chkPalindrome(ListNode* A) 
////{
////   // write code here
////   //思路:将链表对半拆分为两个,对第一个翻转,进行比较
////   if (!A)
////   {
////       return 0;
////   }
////   ListNode* fast, * slow, * prev;
////   ListNode* l1, * l2;
////   prev = fast = slow = l1 = l2 = A;
////   int count = 1;
////   while (fast && fast->next)
////   {
////       prev = slow;
////       slow = slow->next;
////       fast = fast->next->next;
////       count++;
////   }
////   //奇偶数个讨论
////   if (fast == NULL)//偶
////   {
////       l2 = slow;
////   }
////   else {
////       //奇数
////       l2 = slow->next;
////   }
////   //两条链
////   l1 = A;
////   prev->next = NULL;
////
////   //逆置第一条链
////   ListNode* n1, * n2, * n3;
////   n1 = NULL;
////   n2 = l1;
////   n3 = l1->next;
////
////   while (n2)
////   {
////       n2->next = n1;
////       n1 = n2;
////       n2 = n3;
////       if (n3)
////       {
////           n3 = n3->next;
////       }
////   }
////
////   //新的起始   n1,一开始这里弄错了, n2,所以调试了很久
////   l1 = n1;
////
////   while (l1 != NULL)
////   {
////       if (l1->val != l2->val)
////       {
////           break;
////       }
////       // printf("l1 = %d,l2 = %d\n",l1->val,l2->val);
////       if (l1->val == l2->val)
////       {
////           l1 = l1->next;
////           l2 = l2->next;
////       }
////
////   }
////
////   if (l1 != NULL)
////       return 0;
////   else
////   {
////       return 1;
////   }
////
////}

////2.0	思路厘清后
////
////逆置
//#include <algorithm>
//#include <list>
//ListNode* LSreverse(ListNode* phead) {
//    if (!phead)
//        return NULL;
//    //翻转后
//    ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = phead;
//    n3 = phead->next;
//    while (n2) {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3) {
//            n3 = n3->next;
//        }
//    }
//    //新的头节点
//    return n1;
//}
//
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A) {
//        if (!A) {
//            return NULL;
//        }
//        //2.0
//        //快慢指针找中间位置
//        ListNode* fast, * slow, * mid, * prevmid;
//        fast = slow = prevmid = A;
//        while (fast && fast->next) {
//            prevmid = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        mid = slow;
//
//        //翻转后半部分
//        ListNode* l1, * l2;//前半,后半的头节点
//        l1 = A;
//        l2 = LSreverse(mid);
//
//        //判断是否是回文结构
//        ListNode* head1 = l1, * head2 = l2;
//        while (l1 != mid) {
//            if (l1->val != l2->val) {
//                return false;
//            }
//            l1 = l1->next;
//            l2 = l2->next;
//        }
//
//        //还原逆置
//        head2 = LSreverse(head2);
//
//        return true;
//    }
//};




////int main()
////{
////    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
////    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
////    n1->next = n2;
////    n2->next = n3;
////    n3->next = n4;
////    n4->next = n5;
////    n5->next = NULL;
////    n1->val = 1;
////    n2->val = 2;
////    n3->val = 3;
////    n4->val = 2;
////    n5->val = 1;
////
////    int ret = chkPalindrome(n1);
////    printf("%d\n", ret);
////
////    return 0;
////}
//
//
//
//
//////描述
//////现有一链表的头指针 ListNode* pHead，给一定值x，
//////编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//
////typedef struct ListNode {
////    int val;
////    struct ListNode *next;
////}ListNode;
//
//
//ListNode* partition(ListNode* pHead, int x) {
//    // write code here
//    if (!pHead)
//    {
//        return pHead;
//    }
//    ListNode* p = pHead;
//    ListNode* head1, * head2, * tail1, * tail2;
//    head1 = head2 = tail1 = tail2 = NULL;
//     //head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//     //head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//哨兵位的头
//     //tail2->next = NULL;
//
//    while (p)
//    {
//        if (p->val < x)
//        {
//            if (head1 == NULL)
//            {
//                head1 = tail1 = p;
//            }
//            else {
//                tail1->next = p;
//                tail1 = tail1->next;
//            }
//        }
//        else {
//            // tail2->next = p;
//            // tail2 = tail2->next; 
//            if (head2 == NULL)
//            {
//                head2 = tail2 = p;
//            }
//            else {
//                tail2->next = p;
//                tail2 = tail2->next;
//            }
//        }
//        // printf("%d,",p->val);
//        p = p->next;
//    }
//
//    if (tail2)//2结尾置空,防止陷入循环    这里出错,调试了很久
//    {
//        tail2->next = NULL;
//    }
//    //如果x大于所有值
//    if (head1 == NULL)
//    {
//        return head2;
//    }
//    //小于和大于部分续借
//    if (head2)
//    {
//        tail1->next = head2;
//    }
//
//    // ListNode* list = head1->next;
//    // free(head1);
//    // free(head2);
//    // head1 = NULL;
//
//    return head1;
//
//}
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
//    n2->val = 2;
//    n3->val = 3;
//    n4->val = 2;
//    n5->val = 1;
//
//    SLprint(n1);
//    ListNode* ret = partition(n1,2);
//    SLprint(ret);
//    //printf("%p\n", ret);
//
//    return 0;
//}
//
//
//
//
//
////160. 相交链表
////给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
////如果两个链表不存在相交节点，返回 null 。
//
//
//
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
// 
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    //方法一:A遍历改为0,B遍历改为1,从A开始找1的位置
//    //但是更改了链表,不达标
//    if (headA == NULL && headB == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* l1, * l2;
//    l1 = headA;
//    l2 = headB;
//    while (l1)
//    {
//        l1->val = 0;
//        l1 = l1->next;
//    }
//    while (l2)
//    {
//        l2->val = 1;
//        l2 = l2->next;
//    }
//
//    l1 = headA;
//    while (l1)
//    {
//        if (l1->val == 1)
//        {
//            break;
//        }
//        l1 = l1->next;
//    }
//
//    return l1;
//}
//
//
//    /**
//     * Definition for singly-linked list.
//     * struct ListNode {
//     *     int val;
//     *     struct ListNode *next;
//     * };
//     */
//     //逆置链表函数
//    struct ListNode* reverse(struct ListNode* phead)
//    {
//        if (phead == NULL)
//        {
//            return NULL;
//        }
//        struct ListNode* n1, * n2, * n3;
//        n1 = NULL;
//        n2 = phead;
//        n3 = phead->next;
//        while (n2)
//        {
//            n2->next = n1;
//            n1 = n2;
//            n2 = n3;
//            if (n3)
//            {
//                n3 = n3->next;
//            }
//        }
//        return n1;
//    }
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//        if (headA == NULL)
//        {
//            return NULL;
//        }
//        if (headB == NULL)
//        {
//            return NULL;
//        }
//        //方法二,逆置A,遍历A,B,得到公共部分个数
//        struct ListNode* l1, * l2, * Aend;
//        struct ListNode* comnode = NULL;
//        l1 = headA;
//        l2 = headB;
//        Aend = headA;
//        int a = 0;//A个数 a = a1 +m
//        int b = 0;//B个数 b = b1 +m
//        int a1_b1 = 0;//A,B单独个数之和+1, a1_b1 = a1 +b1 + 1,多了一个公共的
//        while (l1)
//        {
//            a++;
//            l1 = l1->next;
//        }
//        while (l2)
//        {
//            b++;
//            l2 = l2->next;
//        }
//        l1 = headA;
//        l2 = headB;
//        l1 = reverse(l1);//逆置A
//        while (l2->next)//得到的结果是a1_b1 - 1
//        {
//            a1_b1++;
//            l2 = l2->next;
//        }
//        if (l2 != Aend)//如果有公共节点,那么B就能去到A初始起点,此时终点
//        {
//            l1 = reverse(l1);//把A逆置回来
//            return NULL;
//        }
//        int com = (a + b - (a1_b1)) / 2;
//        printf("a= %d,b= %d,a1_b1= %d,com= %d\n", a, b, a1_b1, com);
//        comnode = l1;
//
//        while (--com)
//        {
//            comnode = comnode->next;
//        }
//        l1 = reverse(l1);//把A逆置回来
//        return comnode;
//
//    }
//
//	  //3.0	双指针,参考后自己写
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//        //双指针,参考后自己写
//        //A长度:a + m
//        //B长度:b + m
//        //走完本条链后跳到另一条,交点时,各自走到长度一样:a + b + m
//        if (headA == NULL || headB == NULL)
//        {
//            return NULL;
//        }
//        struct ListNode* a, * b;
//        a = headA;
//        b = headB;
//        int flag1 = 0, flag2 = 0;
//        while (a && b)
//        {
//            if (a == b)
//            {
//                break;
//            }
//            a = a->next;
//            b = b->next;
//
//            if (a == NULL && flag1 == 0)//走完A后,换B走
//            {
//                a = headB;
//                flag1 = 1;
//            }
//            if (b == NULL && flag2 == 0)
//            {
//                b = headA;
//                flag2 = 1;
//            }
//        }
//        return a;
//    }
//

////4.0   上课后画图再次写
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if (!headA || !headB)
//    {
//        return NULL;
//    }
//    //判断是否相交,并求两者长度
//    struct ListNode* cur1, * cur2;
//    cur1 = headA;
//    cur2 = headB;
//    int lenA = 1;
//    int lenB = 1;
//    while (cur1->next)
//    {
//        cur1 = cur1->next;
//        lenA++;
//    }
//    while (cur2->next)
//    {
//        cur2 = cur2->next;
//        lenB++;
//    }
//    if (cur1 != cur2)
//    {
//        return NULL;
//    }
//
//    //相交的后面长度一样,交点前长度可能不一样,让长的先走差值,之后同时走,交点相遇
//    //int step = lenA > lenB ?lenA - lenB: lenB - lenA;
//    int step = 0;
//    cur1 = headA;
//    cur2 = headB;
//    if (lenA > lenB)
//    {
//        step = lenA - lenB;
//        while (step--)
//        {
//            cur1 = cur1->next;
//        }
//    }
//    else
//    {
//        step = lenB - lenA;
//        while (step--)
//        {
//            cur2 = cur2->next;
//        }
//    }
//    while (cur1 != cur2)
//    {
//        cur1 = cur1->next;
//        cur2 = cur2->next;
//    }
//    return cur1;
//}


//
////环形链表 II
////给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
////如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
////评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
////如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
////不允许修改 链表。
//
////思路:
////1.确定是否是环
////2.拆开环,找公共节点
////3.恢复环
////
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//    //拆开环
//    //快慢指针
//    struct ListNode* fast = head, * slow = head, * newhead = head;
//    int flag = 0;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        if (fast == slow)
//        {
//            flag = 1;
//            break;
//        }
//        slow = slow->next;
//        if (fast == slow)
//        {
//            flag = 1;
//            break;
//        }
//    }
//    if (flag == 0)//无环
//    {
//        return NULL;
//    }
//    //拆环
//    newhead = slow->next;
//    slow->next = NULL;
//    // printf("flag = %d,newhead:%d\n",flag,newhead->val);//调试用
//    //找公共节点
//    struct ListNode* A, * B;
//    A = head;
//    B = newhead;
//    while (A != B)
//    {
//        A = (A == NULL ? newhead : A->next);
//        B = (B == NULL ? head : B->next);
//    }
//    //恢复原来的环
//    slow->next = newhead;
//    return A;
//
//}
//
//
////2.0	思路2:画图,利用数学上的关系的到一个简单等式
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//    //参考别人代码后自己实现
//    //到环距离a,环长度b+c,快慢指针相遇点b
//    //s慢指针速度1,f快指针速度2
//    //到相遇点b,s走了a+b,f走了a+n(b+c)+b,比慢指针s多走了n圈环
//    //f = 2s , s = a + b, f = a+n(b+c)+b
//    //联立方程得到:a = (n-1)(b+c) + c
//    //(n-1)(b+c)长度n-1圈环,相对位置不变
//    //结论:从相遇点b走距离c到环起始点 == 从head走距离a到起始点
//    //f的相对s的速度是1,在环中,两者距离小于等于环长,s绝对速度是1,所以当f追上s时,s走到距离小于等于环长
//    struct ListNode* fast = head, * slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            break;
//        }
//    }
//    if (fast == NULL || fast->next == NULL)
//    {
//        return NULL;
//    }
//    //结论:从相遇点b走距离c到环起始点 == 从head走距离a到起始点
//    while (head != slow)
//    {
//        head = head->next;
//        slow = slow->next;
//    }
//    return head;
//
//
//}