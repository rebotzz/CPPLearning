#define _CRT_SECURE_NO_WARNINGS








//26. ɾ�����������е��ظ���
//����һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����
//���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����
//�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
//���� k ��
//ʾ�� 2��
//���룺nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//�����5, nums = [0, 1, 2, 3, 4]
//���ͣ�����Ӧ�÷����µĳ��� 5 �� ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4 ������Ҫ���������г����³��Ⱥ����Ԫ�ء�
#include <stdio.h>

//int removeDuplicates(int* nums, int numsSize) {
//    //����ͬ��Ԫ�ش���nums[dst],dst++
//    int src = 1, dst = 0;
//    //nums[0]��ʼλ�ò��ô��,Ĭ�ϳ�ʼ����
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
//    //��dst+1��Ԫ��,��Ϊ0û�м���
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

////3.0	��ָ��
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

////3.5	˫ָ��
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


//88. �ϲ�������������
//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�
//Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
//ʾ�� 1��
//���룺nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//�����[1, 2, 2, 3, 5, 6]
//���ͣ���Ҫ�ϲ�[1, 2, 3] ��[2, 5, 6] ��
//�ϲ������[1, 2, 2, 3, 5, 6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�

//int cmp_int(void* a, void* b)
//{
//    return *((int*)a) - *((int*)b);
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    // //���ٿռ�
//    // int* tmp = (int*)malloc((m+nums2Size)*sizeof(int));
//    // if(tmp == NULL)
//    // {
//    //     perror("realloc");
//    //     exit(-1);
//    // }
//    // //����
//    // memcpy(tmp,nums1,m*sizeof(int));
//    memcpy(nums1 + m, nums2, nums2Size * sizeof(int));
//    //����
//    n = nums2Size;
//    qsort(nums1, m + n, sizeof(int), cmp_int);
//    return m + n;
//
//    // //�ͷſռ�
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

////1.0   û�н���������ʱ�������������
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    //nums����ת��Ϊ����
//    int i = 0;
//    long long sum = 0;
//    while (i < numSize)
//    {
//        sum = sum * 10 + num[i];
//        i++;
//    }
//    //�Ӻ�
//    sum += k;
//    //���ת��Ϊ����
//    long long tmp = sum;
//    int count = 1;
//    while (tmp = tmp / 10)
//    {
//        count++;
//    }
//    //���ٿռ�
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
//    //��������
//    *returnSize = count;
//    return arr;
//
//}


////2.0     ��λ���,����9��1
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    //˼·:ÿһλ��Ӧ���,�������
//    //ͳ��kλ��
//    int count_k = 1;
//    int tmp = k;
//    int count_n = numSize;
//    while (tmp /= 10)
//    {
//        count_k++;
//    }
//    //�Ƚ�λ����ϵ
//    if (numSize >= count_k)
//    {
//        numSize = numSize + 1;//��һλ,�����λ
//    }
//    else if (numSize < count_k)
//    {
//        numSize = k + 1;
//    }
//    //���ٿռ�
//    int* arr = (int*)calloc(numSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //��Ӧλ���
//    int i = 0;
//    int up = 0;//��λ
//    int num_i = 0;//ԭ�����Ӧλ
//    for (i = 0; i < numSize; i++)
//    {
//        //ԭ�����λ���ܿ�ȱ
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
//        //�ж��Ƿ�Ҫ��λ
//        if (arr[numSize - i - 1] > 9)
//        {
//            arr[numSize - i - 1] %= 10;
//            up = 1;
//        }
//        else {
//            up = 0;
//        }
//        //���λ�Ƿ���Ҫ��λ�ж�
//        if (i == numSize - 2 && up == 0)
//        {
//            break;
//        }
//
//    }
//    //�ж�Ԥ����λ�Ƿ���Ԫ��
//    if (arr[0] != 0)
//    {
//        //�������,��С����
//    }
//    else {
//        //��Ϊ����ԭ����numSize���ܱ�ʵ��ֵ��
//        //�ҵ���λ��Ϊ0λ��
//        int pos = 0;
//        while (arr[pos] == 0)
//        {
//            pos++;
//        }
//        //������Ҫ����ǰ��(numSize - pos)λ
//        memmove(arr, arr + pos, (numSize - pos) * sizeof(int));
//        numSize = numSize - pos;
//    }
//    //��������
//    *returnSize = numSize;
//    return arr;
//
//}


//�ο�����  1.0
//����һ����λ���
//˼·
//
//��������λ�����ּ���һ���������
//123
//+
//912
//123 + 912�����Ǵӵ�λ����λ���μ���

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
////�ο�����  2.0
////��һ��˼·�ǽ���������
////k ���������ʾ���������λ��

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



//�ο����Լ�д
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) 
//{
//    int pre_sz = numSize -1;
//    //��λ���,��λ,�������λ�� = max(10,numsize) ,int��10λ��
//    numSize = numSize > 10 ? numSize + 1 : 11;
//    //���ٿռ�
//    int* arr = (int*)calloc(numSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //���
//    int i = numSize -1;
//    while (i >= 0)
//    {
//        //k�Ƚ���,��num�Ƚ���
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
//    //��λ�ж�
//    i = 0;
//    while (arr[i] == 0)
//    {
//        i++;
//    }
//    memmove(arr, arr + i, (numSize - i) * sizeof(int));
//    numSize = numSize - i;
//
//    //�����׵�ַ
//    *returnSize = numSize;
//    return arr;
//
//}

////2.0
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    //��λ���,��λ,�������λ�� = max(10,numsize) ,int��10λ��
//    int newSize = numSize > 10 ? numSize + 1 : 11;
//    //���ٿռ�
//    int* arr = (int*)calloc(newSize, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc");
//        exit(-1);
//    }
//    //���
//    *returnSize = 0;
//    for (int i = numSize - 1; i >= 0 || k > 0; i--, k /= 10)
//    {
//        if (i >= 0)
//        {
//            k += num[i];
//        }
//        arr[(*returnSize)++] = k % 10;//ע�����ȼ�(*returnSize)
//    }
//    //����
//    for (int i = 0; i < (*returnSize) / 2; i++)
//    {
//        int tmp = arr[i];
//        arr[i] = arr[*returnSize -1 - i];
//        arr[*returnSize -  1 - i] = tmp;
//    }
//    //�����׵�ַ
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
//    //��ӡ
//    int i = 0;
//    for (i = 0; i < newsz; i++)
//    {
//        printf("%d ", newarr[i]);
//    }
//    printf("\n");
//    //�ͷſռ�
//    free(newarr);
//    newarr = NULL;
//
//    return 0;
//}