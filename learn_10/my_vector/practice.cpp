//
////letcodeϰ����ϰ
//
////ֻ����һ�ε�����
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int ret = 0;
//        for (auto e : nums)
//        {
//            ret ^= e;
//        }
//        return ret;
//    }
//};
//
////�������
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv(numRows);
//        //��ʼ��
//        for (int i = 0; i < numRows; ++i)
//        {
//            vv[i].resize(i + 1, 0);
//            vv[i][0] = 1;
//            vv[i][i] = 1;
//        }
//
//        for (int i = 0; i < numRows; ++i)
//        {
//            for (int j = 0; j <= i; ++j)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//                }
//            }
//        }
//
//        return vv;
//    }
//};
//
////������� C�汾
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
//    //returnSize�����С
//    //returnColumnSizes��ά���������
//    //���ٶ�ά����
//    int** ppa = (int**)malloc(sizeof(int**) * numRows);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows); //�������Ͳ�����Ҫ�Լ�����
//    //��ʼ��
//    for (int i = 0; i < numRows; ++i)
//    {
//        ppa[i] = (int*)calloc(i + 1, sizeof(int));
//        ppa[i][0] = 1;
//        ppa[i][i] = 1;
//        (*returnColumnSizes)[i] = i + 1;
//    }
//    printf("-----\n");
//    for (int i = 0; i < numRows; ++i)
//    {
//        printf("-----\n");
//
//        for (int j = 0; j <= i; ++j)
//        {
//            if (ppa[i][j] == 0)
//            {
//                ppa[i][j] = ppa[i - 1][j - 1] + ppa[i - 1][j];
//                printf("ppa[i][j]:%d\n", ppa[i][j]);
//
//            }
//        }
//    }
//    *returnSize = numRows;
//    return ppa;
//}
//
//
////�绰�������ĸ���
//vector<string> numLetter = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//
//class Solution {
//public:
//    void _letterCombinations(string& digits, int pi, string tmp, vector<string>& astr)
//    {
//        //�ݹ��������,��ײ�
//        if (pi == digits.size())
//        {
//            astr.push_back(tmp);
//            return;
//        }
//
//        int num = digits[pi] - '0';
//        string letter = numLetter[num];     //���ּ���Ӧ��ĸ��
//        int end = letter.size();
//        //�������,���ƶ����
//        for (int i = 0; i < end; ++i)
//        {
//            char ch = letter[i];
//            tmp += ch;
//
//            _letterCombinations(digits, pi + 1, tmp, astr);
//            tmp.pop_back();
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> astr;
//        if (0 == digits.size())
//        {
//            return astr;
//        }
//        int maxdepth = digits.size();
//        int pi = 0;
//        string tmp;
//        _letterCombinations(digits, pi, tmp, astr);
//
//        return astr;
//    }
//};