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
////OR36 ����Ļ��Ľṹ
////����
////����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
////����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
////����������
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
////   //˼·:������԰���Ϊ����,�Ե�һ����ת,���бȽ�
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
////   //��ż��������
////   if (fast == NULL)//ż
////   {
////       l2 = slow;
////   }
////   else {
////       //����
////       l2 = slow->next;
////   }
////   //������
////   l1 = A;
////   prev->next = NULL;
////
////   //���õ�һ����
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
////   //�µ���ʼ   n1,һ��ʼ����Ū����, n2,���Ե����˺ܾ�
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

////2.0	˼·�����
////
////����
//#include <algorithm>
//#include <list>
//ListNode* LSreverse(ListNode* phead) {
//    if (!phead)
//        return NULL;
//    //��ת��
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
//    //�µ�ͷ�ڵ�
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
//        //����ָ�����м�λ��
//        ListNode* fast, * slow, * mid, * prevmid;
//        fast = slow = prevmid = A;
//        while (fast && fast->next) {
//            prevmid = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        mid = slow;
//
//        //��ת��벿��
//        ListNode* l1, * l2;//ǰ��,����ͷ�ڵ�
//        l1 = A;
//        l2 = LSreverse(mid);
//
//        //�ж��Ƿ��ǻ��Ľṹ
//        ListNode* head1 = l1, * head2 = l2;
//        while (l1 != mid) {
//            if (l1->val != l2->val) {
//                return false;
//            }
//            l1 = l1->next;
//            l2 = l2->next;
//        }
//
//        //��ԭ����
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
//////����
//////����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//////��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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
//     //head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
//     //head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
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
//    if (tail2)//2��β�ÿ�,��ֹ����ѭ��    �������,�����˺ܾ�
//    {
//        tail2->next = NULL;
//    }
//    //���x��������ֵ
//    if (head1 == NULL)
//    {
//        return head2;
//    }
//    //С�ںʹ��ڲ�������
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
////160. �ཻ����
////���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
////����������������ཻ�ڵ㣬���� null ��
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
//    //����һ:A������Ϊ0,B������Ϊ1,��A��ʼ��1��λ��
//    //���Ǹ���������,�����
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
//     //����������
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
//        //������,����A,����A,B,�õ��������ָ���
//        struct ListNode* l1, * l2, * Aend;
//        struct ListNode* comnode = NULL;
//        l1 = headA;
//        l2 = headB;
//        Aend = headA;
//        int a = 0;//A���� a = a1 +m
//        int b = 0;//B���� b = b1 +m
//        int a1_b1 = 0;//A,B��������֮��+1, a1_b1 = a1 +b1 + 1,����һ��������
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
//        l1 = reverse(l1);//����A
//        while (l2->next)//�õ��Ľ����a1_b1 - 1
//        {
//            a1_b1++;
//            l2 = l2->next;
//        }
//        if (l2 != Aend)//����й����ڵ�,��ôB����ȥ��A��ʼ���,��ʱ�յ�
//        {
//            l1 = reverse(l1);//��A���û���
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
//        l1 = reverse(l1);//��A���û���
//        return comnode;
//
//    }
//
//	  //3.0	˫ָ��,�ο����Լ�д
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//        //˫ָ��,�ο����Լ�д
//        //A����:a + m
//        //B����:b + m
//        //���걾������������һ��,����ʱ,�����ߵ�����һ��:a + b + m
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
//            if (a == NULL && flag1 == 0)//����A��,��B��
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

////4.0   �Ͽκ�ͼ�ٴ�д
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if (!headA || !headB)
//    {
//        return NULL;
//    }
//    //�ж��Ƿ��ཻ,�������߳���
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
//    //�ཻ�ĺ��泤��һ��,����ǰ���ȿ��ܲ�һ��,�ó������߲�ֵ,֮��ͬʱ��,��������
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
////�������� II
////����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
////�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ���
////����ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
////��� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
////�������޸� ����
//
////˼·:
////1.ȷ���Ƿ��ǻ�
////2.�𿪻�,�ҹ����ڵ�
////3.�ָ���
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
//    //�𿪻�
//    //����ָ��
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
//    if (flag == 0)//�޻�
//    {
//        return NULL;
//    }
//    //��
//    newhead = slow->next;
//    slow->next = NULL;
//    // printf("flag = %d,newhead:%d\n",flag,newhead->val);//������
//    //�ҹ����ڵ�
//    struct ListNode* A, * B;
//    A = head;
//    B = newhead;
//    while (A != B)
//    {
//        A = (A == NULL ? newhead : A->next);
//        B = (B == NULL ? head : B->next);
//    }
//    //�ָ�ԭ���Ļ�
//    slow->next = newhead;
//    return A;
//
//}
//
//
////2.0	˼·2:��ͼ,������ѧ�ϵĹ�ϵ�ĵ�һ���򵥵�ʽ
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//    //�ο����˴�����Լ�ʵ��
//    //��������a,������b+c,����ָ��������b
//    //s��ָ���ٶ�1,f��ָ���ٶ�2
//    //��������b,s����a+b,f����a+n(b+c)+b,����ָ��s������nȦ��
//    //f = 2s , s = a + b, f = a+n(b+c)+b
//    //�������̵õ�:a = (n-1)(b+c) + c
//    //(n-1)(b+c)����n-1Ȧ��,���λ�ò���
//    //����:��������b�߾���c������ʼ�� == ��head�߾���a����ʼ��
//    //f�����s���ٶ���1,�ڻ���,���߾���С�ڵ��ڻ���,s�����ٶ���1,���Ե�f׷��sʱ,s�ߵ�����С�ڵ��ڻ���
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
//    //����:��������b�߾���c������ʼ�� == ��head�߾���a����ʼ��
//    while (head != slow)
//    {
//        head = head->next;
//        slow = slow->next;
//    }
//    return head;
//
//
//}