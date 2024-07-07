//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
////����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
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
//    //���һ��ֵ
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
////�ο�����
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
////���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
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
//        //�½��ڵ�
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
//    //���һ��
//    new = BuyNode(cur->val);
//    new->next = next;
//    return new;
//
//
//}
//
//
////�ο�����
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
////�ο�����  2.0
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
////�ο����Լ�д
//struct ListNode* reverseList(struct ListNode* head) {
//    //��ͼ���ٴν���
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
////����
////����һ����������������е�����k����㡣
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
//  * @param pListHead ListNode��
//  * @param k int����
//  * @return ListNode��
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    int n = 0;
//    //��һ�εõ�Ԫ�ظ���
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
//    //k��Χ�ж�
//    if (k > n)
//    {
//        return NULL;//��ʵ�Ҿ���Ӧ�÷���ȫ��
//    }
//    if (k == 0)
//    {
//        return NULL;
//    }
//    //�ڶ����ҵ�n - k��
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
//  * @param pListHead ListNode��
//  * @param k int����
//  * @return ListNode��
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    //����ָ��,���K,��ĵ��յ�,����λ������
//    if (pListHead == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* front = pListHead;
//    struct ListNode* back = pListHead;
//    while (k--)
//    {
//        back = back->next;
//        if (back == NULL && k != 0)//Խ��
//        {
//            return NULL;
//        }
//    }
//    if (front == back)//0��Ԫ��
//    {
//        return NULL;
//    }
//    if (back == NULL)//ȫ��
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
////2.0   ��ͼ��������Ҫ
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    //����ָ��
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
////876. ������м���
////���㵥�����ͷ��� head �������ҳ�������������м��㡣
////
////����������м��㣬�򷵻صڶ����м��㡣
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
//    //����ָ��
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
////��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
////ʧ��
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
//        //�Ƚ�
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
////�ɹ�
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
//    //����һ��Ϊ��
//    if (l1 == NULL)
//        return l2;
//    if (l2 == NULL)
//        return l1;
//    //������Ϊ��
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
//    //����һ������,��һ��������
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
////����
////����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
////��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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
//        head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
//        // head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
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
//        //С�ںʹ��ڲ�������
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
//        // head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
//        // head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ��ͷ
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
//        //���x��������ֵ
//        if (head1 == nullptr)
//        {
//            return head2;
//        }
//        //С�ںʹ��ڲ�������
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
