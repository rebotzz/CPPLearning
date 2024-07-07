#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

//27. �Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 1��
//���룺nums = [3, 2, 2, 3], val = 3
//�����2, nums = [2, 2]
//���ͣ�����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء����磬�������ص��³���Ϊ 2 ���� nums = [2, 2, 3, 3] �� nums = [2, 2, 0, 0]��Ҳ�ᱻ������ȷ�𰸡�
//ʾ�� 2��
//���룺nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//�����5, nums = [0, 1, 4, 0, 3]
//���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

//1.0   ʱ�临�Ӷ�O(N*N)     �ռ临�Ӷ�O(1)
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    //˳�����,�ҵ���memmove����,Ȼ��numsSize--,i--
    for (i = 0; i < numsSize; i++)
    {
        if (val == nums[i])
        {
            memmove(nums + i, nums + i + 1, (numsSize - i - 1) * sizeof(int));
            numsSize--;
            i--;
        }
    }
    return numsSize;

}


//2.0   ʱ�临�Ӷȿ�����O(N*log(2)N + ...)      �ռ临�Ӷ�O(1)
int cmp_int(void* e1, void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
int removeElement(int* nums, int numsSize, int val) {
    //2.0
    //����,Ȼ�����val����,λ��,MEMMOVE
    qsort(nums, numsSize, sizeof(int), cmp_int);
    int i = 0;
    int count = 0;
    int pos = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (val == nums[i])
        {
            if (count == 0)
            {
                pos = i;
            }
            count++;
        }
    }
    memmove(nums + pos, nums + pos + count, (numsSize - pos - count) * sizeof(int));
    return numsSize - count;
}



//3.0����val,�򽫽������һ��������  ʱ�临�Ӷ�O(N)   �ռ临�Ӷ�O(N)
int removeElement(int* nums, int numsSize, int val) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    int i = 0;
    int count = 0;
    //����val,�򽫽������һ��������
    for (i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            arr[count] = nums[i];
            count++;
        }
    }
    memmove(nums, arr, count * sizeof(int));
    free(arr);
    arr = NULL;

    return count;

}


//4.0   ����val,����nums[count],count++     ʱ�临�Ӷ�O(N)   �ռ临�Ӷ�O(1)
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (val != nums[i])
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}