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
//////138. ���ƴ����ָ�������
//////����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//////������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
//////�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
//////���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��
//////���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random-- > Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random-- > y ��
//////���ظ��������ͷ�ڵ㡣
//////��һ���� n ���ڵ���ɵ���������ʾ���� / ����е�����ÿ���ڵ���һ��[val, random_index] ��ʾ��
//////val��һ����ʾ Node.val ��������
//////random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n - 1���������ָ���κνڵ㣬��Ϊ  null ��
//////��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ���������
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
//// //�����ڵ�
////struct Node* buyNode(int x)
////{
////    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
////    newnode->val = x;
////    newnode->next = NULL;
////    newnode->random = NULL;
////    return newnode;
////}
////struct Node* copyRandomList(struct Node* head) {
////    //����val
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
////    //����һ������洢ÿ���ڵ��ַ,ָ������,������,����ָ��
////    //�����洢,��ַƫ����iȷ��randomָ��
////    //debug: malloc���ٵĿռ䲻һ������,��Ϊcalloc����,Ҳ����?
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
////    //random����
////    i = 0;
////    while (i < count)
////    {
////        if ((arr[i])->random == NULL)
////        {
////            (cp[i])->random = NULL;
////        }
////        else
////        {
////            (cp[i])->random = cp[0] + ((arr[i])->random - arr[0]);//����ָ�������ַƫ�������Ӧ;
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
////    //�ο����������˵Ĵ���
////    struct Node* n1, * n2;
////    n1 = head;
////    n2 = head->next;
////    //�м����
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
////    //����random
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
////    //���
////    old = n1 = head;      //ͷ
////    new = n2 = head->next;//ͷ
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
////147. ��������в�������
////�������������ͷ head ��ʹ�� �������� ������������򣬲����� ����������ͷ ��
////�������� �㷨�Ĳ��� :
////���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
////ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
////�ظ�ֱ�������������ݲ�����Ϊֹ��
////�����ǲ��������㷨��һ��ͼ��ʾ��������������б�(��ɫ)���ֻ�����б��еĵ�һ��Ԫ�ء�
////ÿ�ε���ʱ��������������ɾ��һ��Ԫ��(��ɫ)�����͵ز�����������б��С�
////��������в�������
//
// 
//
//////1.0
////struct ListNode* insertionSortList(struct ListNode* head) {
////    if (head == NULL)
////    {
////        return NULL;
////    }
////    //�ڱ�λ
////    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
////    //������Ԫ�� ,��ֹβ��ʱ�ı�pcurָ����һλ�ĵ�ַ
////    ListNode* cpyhead = (ListNode*)malloc(sizeof(ListNode));//�����������ôfree��?
////    cpyhead->val = head->val;
////    cpyhead->next = NULL;
////    prev->next = cpyhead;
////    int max, min;
////    max = min = head->val;
////    struct ListNode* cur = head->next, * tail = cpyhead,*pcur = head;
////    while (cur)
////    {
////        //ȡ��cur�ڵ�
////        if (pcur->next)
////        {
////            pcur->next = pcur->next->next;
////            cur->next = NULL;
////        }
////        //<min,ͷ��
////        if (cur->val < min)
////        {
////            cur->next = prev->next;
////            prev->next = cur;
////            min = cur->val;
////        }
////        //>max,β��
////        else if (cur->val >= max)
////        {
////            tail->next = cur;
////            tail = tail->next;
////            max = cur->val;
////        }
////        //�м�
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
//    //�ο����Լ�ʵ��
//    struct ListNode* n1, * n2, * n3;
//    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prehead->next = head;
//    n1 = prehead;
//    n2 = head;
//    n3 = head->next;
//    while (n3)
//    {
//        n1 = prehead;
//        //��n2֮ǰ�ʺϲ���n3��λ��
//        while (n1->next->val <= n3->val && n1 != n2)// 
//        {
//            n1 = n1->next;
//        }
//        if (n1 != n2)//��Ҫ����
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
////ɾ���������ظ��Ľ��
////����
////��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
////���磬���� 1->2->3->3->4->4->5  �����Ϊ 1->2->5
//
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
// /**
//  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//  *
//  *
//  * @param pHead ListNode��
//  * @return ListNode��
//  */
////struct ListNode* deleteDuplication(struct ListNode* pHead) {
////    if (pHead == NULL)
////    {
////        return NULL;
////    }
////    // write code here
////    //����ɾ�������ظ���Ŀ�İ汾
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
////1.0   ����δ����
//struct ListNode* deleteDuplication(struct ListNode* pHead) {
//    if (pHead == NULL)
//    {
//        return NULL;
//    }
//    // write code here
//    //����ɾ�������ظ���Ŀ�İ汾
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
////2.0 ���ܲ�����
///**
// * struct ListNode {
// *  int val;
// *  struct ListNode *next;
// * };
// */
// /**
//  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//  *
//  *
//  * @param pHead ListNode��
//  * @return ListNode��
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
//    //����ɾ�������ظ���Ŀ�İ汾
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
////3.0   �����޸İ�
///**
// * struct ListNode {
// *  int val;
// *  struct ListNode *next;
// * };
// */
// /**
//  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//  *
//  *
//  * @param pHead ListNode��
//  * @return ListNode��
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
//    //�ҵ�ͷ
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
//    //ɾ��ͷ�����
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