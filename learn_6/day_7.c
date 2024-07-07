#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

//27. 移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//示例 1：
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2, nums = [2, 2]
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2, 2, 3, 3] 或 nums = [2, 2, 0, 0]，也会被视作正确答案。
//示例 2：
//输入：nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//输出：5, nums = [0, 1, 4, 0, 3]
//解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

//1.0   时间复杂度O(N*N)     空间复杂度O(1)
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    //顺序查找,找到后memmove覆盖,然后numsSize--,i--
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


//2.0   时间复杂度可能是O(N*log(2)N + ...)      空间复杂度O(1)
int cmp_int(void* e1, void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
int removeElement(int* nums, int numsSize, int val) {
    //2.0
    //排序,然后计算val个数,位置,MEMMOVE
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



//3.0不是val,则将结果存入一个新数组  时间复杂度O(N)   空间复杂度O(N)
int removeElement(int* nums, int numsSize, int val) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    int i = 0;
    int count = 0;
    //不是val,则将结果存入一个新数组
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


//4.0   不是val,存入nums[count],count++     时间复杂度O(N)   空间复杂度O(1)
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