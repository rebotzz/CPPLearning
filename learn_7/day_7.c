#define _CRT_SECURE_NO_WARNINGS

//622. ���ѭ������
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ��
//��������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ����������,
//���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//���ʵ��Ӧ��֧�����²�����
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�������

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//�����Ǿ�̬�Ķ���,������ʵ��
//�������±�Խ��ʱ,ȡģ�ص���ʼ�±�,ʵ��ѭ��Ч��

typedef struct {
    int* _data;
    int _front;//��ͷ
    int _rear;//��β����һ��
    int _capacity;//����

    // int _size;
    // int _capacity;//�ƺ�û�����ݵı�Ҫ
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //����һ��K+1��С������,��һ�������ж϶����Ƿ�����
    //�ӿں���,����Ϊ�˱���ֲ���������,ʹ��static ���� malloc
    //�ṹ��
    MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (NULL == pq)
    {
        printf("malloc");
        exit(-1);
    }
    //����k+1��С
    pq->_data = (int*)malloc((k + 1) * sizeof(int));
    if (NULL == pq->_data)//ע������==,����=
    {
        printf("malloc");
        exit(-1);
    }
    pq->_front = pq->_rear = 0;
    pq->_capacity = k + 1;
    return pq;
}

//���,β��
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //���в���,�����
    if (!myCircularQueueIsFull(obj))
    {
        obj->_data[obj->_rear] = value;//->���ȼ�����
        // printf("%d ", obj->_data[obj->_rear]);
        (obj->_rear)++;
        obj->_rear %= obj->_capacity;
        return true;
    }
    //����,����ʧ��,���ؼ�
    else
    {
        return false;
    }
}

//����,ͷɾ,�ȼ���ͷָ����ǰ�ƶ�
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    //���в�Ϊ��,����,������
    if (!myCircularQueueIsEmpty(obj))
    {
        obj->_front = (obj->_front + 1) % obj->_capacity;
        return true;
    }
    //����Ϊ��,���ؼ�
    else
    {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    //��ȡ��ͷԪ��
    assert(obj);
    if (obj->_front == obj->_rear)//���û��ֵ,��ͷ��β��ͬ
    {
        return -1;
    }
    return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    //��ȡ��β����
    assert(obj);
    // assert(obj->_front != obj->_rear);
    if (obj->_front == obj->_rear)//���û��ֵ,��ͷ��β��ͬ
    {
        return -1;
    }
    if (0 == obj->_rear)//С����ǰԽ��
    {
        return obj->_data[obj->_capacity - 1];
    }
    else
    {
        return obj->_data[obj->_rear - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->_rear + 1) % obj->_capacity == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    //ע���Ⱥ�,������malloc
    assert(obj);
    free(obj->_data);
    free(obj);
    obj = NULL;
}

void test()
{
    MyCircularQueue* obj = myCircularQueueCreate(3);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 4);


    myCircularQueueFront(obj);
    myCircularQueueRear(obj);
    myCircularQueueIsEmpty(obj);
    myCircularQueueIsFull(obj);
    myCircularQueueDeQueue(obj);
    myCircularQueueFree(obj);
}

int main()
{
    test();
    return 0;
}