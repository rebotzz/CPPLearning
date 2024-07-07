#define _CRT_SECURE_NO_WARNINGS








//26. 删除有序数组中的重复项
//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
//考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
//更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
//返回 k 。
//示例 2：
//输入：nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出：5, nums = [0, 1, 2, 3, 4]
//解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
#include <stdio.h>

//int removeDuplicates(int* nums, int numsSize) {
//    //将不同的元素存入nums[dst],dst++
//    int src = 1, dst = 0;
//    //nums[0]起始位置不用存放,默认初始就行
//    while (src < numsSize)
//    {
//        if (nums[dst] != nums[src])
//        {
//            dst++;
//            nums[dst] = nums[src];
//            src++;
//        }
//        else
//        {
//            src++;
//        }
//    }
//    //有dst+1个元素,因为0没有计数
//    return dst + 1;
//
//}
//
//
////2.0
//int removeDuplicates(int* nums, int numsSize) {
//    int* arr = (int*)malloc(numsSize * sizeof(int));
//    if (arr == NULL)
//    {
//        exit(-1);
//    }
//    int count = 0;
//    arr[count++] = nums[0];
//    int i = 1;
//    while (i < numsSize)
//    {
//        if (arr[count - 1] != nums[i])
//        {
//            arr[count] = nums[i];
//            i++;
//            count++;
//        }
//        else
//            i++;
//
//    }
//    memcpy(nums, arr, count * sizeof(int));
//    free(arr);
//    arr = NULL;
//    return count;
//}

////3.0	三指针
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 1)
//	{
//		return 1;
//	}
//	int prev = 0;
//	int next = 1;
//	int count = 0;
//	while (next < numsSize)
//	{
//		if (nums[prev] != nums[next])
//		{
//			nums[count] = nums[prev];
//			prev = next;
//			next++;
//			count++;
//		}
//		else
//		{
//			next++;
//		}
//	}
//	nums[count] = nums[numsSize - 1];
//	count++;
//	return count;
//}

////3.5	双指针
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 1)
//	{
//		return 1;
//	}
//	int prev = 0;
//	int next = 1;
//	while (next < numsSize)
//	{
//		if (nums[prev] != nums[next])
//		{
//			prev++;
//			nums[prev] = nums[next];
//			next++;
//		}
//		else
//		{
//			next++;
//		}
//	}
//	prev++;
//	return prev;
//}
//
//
//int main()
//{
//	int arr[7] = { 1,1,1,2,2,3,4 };
//	int n = removeDuplicates(arr, 7);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//88. 合并两个有序数组
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
//示例 1：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。

//int cmp_int(void* a, void* b)
//{
//    return *((int*)a) - *((int*)b);
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    // //开辟空间
//    // int* tmp = (int*)malloc((m+nums2Size)*sizeof(int));
//    // if(tmp == NULL)
//    // {
//    //     perror("realloc");
//    //     exit(-1);
//    // }
//    // //拷贝
//    // memcpy(tmp,nums1,m*sizeof(int));
//    memcpy(nums1 + m, nums2, nums2Size * sizeof(int));
//    //排序
//    n = nums2Size;
//    qsort(nums1, m + n, sizeof(int), cmp_int);
//    return m + n;
//
//    // //释放空间
//    // free(tmp);
//
//
//}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

////1.0   没有解决素组过大时整形溢出的问题
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    //nums数组转换为数字
//    int i = 0;
//    long long sum = 0;
//    while (i < numSize)
//    {
//        sum = sum * 10 + num[i];
//        i++;
//    }
//    //加和
//    sum += k;
//    //结果转化为数组
//    long long tmp = sum;
//    int count = 1;
//    while (tmp = tmp / 10)
//    {
//        count++;
//    }
//    //开辟空间
//    int* arr = (int*)calloc(count, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    for (i = 0; i < count; i++)
//    {
//        arr[count - i - 1] = sum % 10;
//        sum /= 10;
//    }
//    //传出参数
//    *returnSize = count;
//    return arr;
//
//}


////2.0     按位相加,大于9进1
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    //思路:每一位对应相加,避免溢出
//    //统计k位数
//    int count_k = 1;
//    int tmp = k;
//    int count_n = numSize;
//    while (tmp /= 10)
//    {
//        count_k++;
//    }
//    //比较位数关系
//    if (numSize >= count_k)
//    {
//        numSize = numSize + 1;//多一位,方便进位
//    }
//    else if (numSize < count_k)
//    {
//        numSize = k + 1;
//    }
//    //开辟空间
//    int* arr = (int*)calloc(numSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //对应位相加
//    int i = 0;
//    int up = 0;//进位
//    int num_i = 0;//原数组对应位
//    for (i = 0; i < numSize; i++)
//    {
//        //原数组高位可能空缺
//        if (count_n - i - 1 < 0)
//        {
//            num_i = 0;
//        }
//        else
//        {
//            num_i = num[count_n - i - 1];
//        }
//        arr[numSize - i - 1] = num_i + k % 10 + up;
//        k /= 10;
//        //判断是否要进位
//        if (arr[numSize - i - 1] > 9)
//        {
//            arr[numSize - i - 1] %= 10;
//            up = 1;
//        }
//        else {
//            up = 0;
//        }
//        //最高位是否需要进位判定
//        if (i == numSize - 2 && up == 0)
//        {
//            break;
//        }
//
//    }
//    //判断预留首位是否有元素
//    if (arr[0] != 0)
//    {
//        //无需操作,大小合适
//    }
//    else {
//        //因为输入原数组numSize可能比实际值大
//        //找到首位不为0位置
//        int pos = 0;
//        while (arr[pos] == 0)
//        {
//            pos++;
//        }
//        //数组需要整体前移(numSize - pos)位
//        memmove(arr, arr + pos, (numSize - pos) * sizeof(int));
//        numSize = numSize - pos;
//    }
//    //传出参数
//    *returnSize = numSize;
//    return arr;
//
//}


//参考代码  1.0
//方法一：逐位相加
//思路
//
//让我们逐位将数字加在一起。例如计算
//123
//+
//912
//123 + 912，我们从低位到高位依次计算

//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
//    *returnSize = 0;
//    for (int i = numSize - 1; i >= 0; --i) {
//        int sum = num[i] + k % 10;
//        k /= 10;
//        if (sum >= 10) {
//            k++;
//            sum -= 10;
//        }
//        res[(*returnSize)++] = sum;
//    }
//    for (; k > 0; k /= 10) {
//        res[(*returnSize)++] = k % 10;
//    }
//    for (int i = 0; i < (*returnSize) / 2; i++) {
//        int tmp = res[i];
//        res[i] = res[(*returnSize) - 1 - i];
//        res[(*returnSize) - 1 - i] = tmp;
//    }
//    return res;
//}
//
////参考代码  2.0
////另一个思路是将整个加数
////k 加入数组表示的数的最低位。

//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
//    *returnSize = 0;
//    for (int i = numSize - 1; i >= 0 || k > 0; --i, k /= 10) {
//        if (i >= 0) {
//            k += num[i];
//        }
//        res[(*returnSize)++] = k % 10;
//    }
//
//    for (int i = 0; i < (*returnSize) / 2; i++) {
//        int tmp = res[i];
//        res[i] = res[(*returnSize) - 1 - i];
//        res[(*returnSize) - 1 - i] = tmp;
//    }
//    return res;
//}



//参考后自己写
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) 
//{
//    int pre_sz = numSize -1;
//    //低位相加,进位,可能最大位数 = max(10,numsize) ,int有10位数
//    numSize = numSize > 10 ? numSize + 1 : 11;
//    //开辟空间
//    int* arr = (int*)calloc(numSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //相加
//    int i = numSize -1;
//    while (i >= 0)
//    {
//        //k先结束,或num先结束
//        if (pre_sz >= 0)
//        {
//            arr[i] = (k + num[pre_sz]) % 10;
//            k = (k + num[pre_sz]) / 10;
//            i--;
//            pre_sz--;
//        }
//        else
//        {
//            arr[i] = k % 10;
//            k /= 10;
//            i--;
//        }
//    }
//
//    //首位判断
//    i = 0;
//    while (arr[i] == 0)
//    {
//        i++;
//    }
//    memmove(arr, arr + i, (numSize - i) * sizeof(int));
//    numSize = numSize - i;
//
//    //返回首地址
//    *returnSize = numSize;
//    return arr;
//
//}

////2.0
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    //低位相加,进位,可能最大位数 = max(10,numsize) ,int有10位数
//    int newSize = numSize > 10 ? numSize + 1 : 11;
//    //开辟空间
//    int* arr = (int*)calloc(newSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //相加
//    *returnSize = 0;
//    for (int i = numSize - 1; i >= 0 || k > 0; i--, k /= 10)
//    {
//        if (i >= 0)
//        {
//            k += num[i];
//        }
//        arr[(*returnSize)++] = k % 10;//注意优先级(*returnSize)
//    }
//    //逆序
//    for (int i = 0; i < (*returnSize) / 2; i++)
//    {
//        int tmp = arr[i];
//        arr[i] = arr[*returnSize -1 - i];
//        arr[*returnSize -  1 - i] = tmp;
//    }
//    //返回首地址
//    return arr;
//
//}
//
//int main()
//{
//    int arr[4] = {1,2,0, 0};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int newsz = 0;
//    int k = 9834;
//    int* newarr = addToArrayForm(arr, sz, k, &newsz);
//    //打印
//    int i = 0;
//    for (i = 0; i < newsz; i++)
//    {
//        printf("%d ", newarr[i]);
//    }
//    printf("\n");
//    //释放空间
//    free(newarr);
//    newarr = NULL;
//
//    return 0;
//}