#define _CRT_SECURE_NO_WARNINGS

//数据结构学习
//时间复杂度&空间复杂度







//// 计算BinarySearch的时间复杂度？
////二分查找
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);//二进制右移一位 ==> 除以2
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}


















//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//注意：本题相对书上原题稍作改动
//示例 1：
//输入：[3, 0, 1]
//输出：2
//示例 2：
//输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
//输出：8
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/missing-number-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <stdio.h>

////1.0
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int sum = 0;
//    //两两异或
//    for (i = 0; i <= numsSize; i++)
//    {
//        sum ^= i;
//    }
//    for (i = 0; i < numsSize; ++i)
//    {
//        sum ^= nums[i];
//
//    }
//    return sum;
//}


////2.0
//int missingNumber(int* nums, int numsSize) {
//    // 存放到数组
//    int i = 0;
//    //开辟空间,数组
//    int* tmp = (int*)calloc(numsSize + 1, sizeof(int));
//    if (tmp == NULL)
//    {
//        return 1;
//    }
//    //初始化为-1
//    for (i = 0; i <= numsSize; i++)
//    {
//        tmp[i] = -1;
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//
//        tmp[nums[i]] = nums[i];
//
//
//    }
//    //其中一个元素没有存入
//    for (i = 0; i <= numsSize; i++)
//    {
//        //初始化 0,排除 i = 0
//        //解决方法,改变初始化值 -1
//        if (tmp[i] != i)
//        {
//            break;
//        }
//    }
//
//    //释放空间
//    free(tmp);
//    tmp = NULL;
//    return i;
//}
//
//
////3.0
//int missingNumber(int* nums, int numsSize) {
//    //加和0~ n,在减去数组
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i <= numsSize; i++)
//    {
//        if (i < numsSize)
//        {
//            sum = sum + i - nums[i];
//        }
//        else
//        {
//            sum += i;
//        }
//
//    }
//    return sum;
//}




//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//示例 1:
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//    向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//    向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//    向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//    示例 2 :
//    输入：nums = [-1, -100, 3, 99], k = 2
//    输出：[3, 99, -1, -100]
//    解释 :
//    向右轮转 1 步 : [99, -1, -100, 3]
//    向右轮转 2 步 : [3, 99, -1, -100]
//    提示：
//    1 <= nums.length <= 105
//    - 231 <= nums[i] <= 231 - 1
//    0 <= k <= 105
//    进阶：
//    尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
//    你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//    来源：力扣（LeetCode）
//    链接：https ://leetcode.cn/problems/rotate-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <stdio.h>

//1.0
//void rotate(int* nums, int numsSize, int k) {
//    //memmove
//    int n = numsSize;
//    int* arr = (int*)malloc(numsSize * sizeof(int));
//    //拷贝nums 到 arr
//    memcpy(arr, nums, n * sizeof(int));
//    k %= numsSize;
//    //n - k 位置开始的k个元素移动到首位
//    memmove(nums, nums + n - k, k * sizeof(int));
//    //n - k -1 ~ n -1的 n - k个元素移动到 n + k位置
//    memmove(nums + k, arr, (n - k) * sizeof(int));
//
//    free(arr);
//    arr = NULL;
//
//}

////2.0
//void rotate(int* nums, int numsSize, int k) {
//    //接长数组,截取
//    int n = numsSize;
//    k %= n;
//    int* tmp = (int*)malloc(2 * n * sizeof(int));
//    memcpy(tmp, nums, n * sizeof(int));
//    memcpy(tmp + n, nums, n * sizeof(int));
//    //截取,tmp + n - k 位置开始,n个元素
//    memcpy(nums, tmp + n - k, n * sizeof(int));
//
//
//    free(tmp);
//    tmp = NULL;
//}

//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
////3.0
//void rotate(int* nums, int numsSize, int k) {
//    //三次翻转法
//    //前部分翻转,0 ~ n - k -1
//    int n = numsSize;
//    k %= n;
//    reverse(nums, 0, n - k - 1);
//    //后部分翻转,n - k ~ n - 1
//    reverse(nums, n - k, n - 1);
//    //整体翻转,0 ~ n - 1
//    reverse(nums, 0, n - 1);
//
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    rotate(arr, sz, 14);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    return 0;
//}