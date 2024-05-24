#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int main()
//{
//	//int arr[] = { 1,1,1,2,2,2,5,6,7,4 };
//	//for (auto e : arr)
//	//	cout << e << " ";
//	//cout << endl;
//	//auto iter = unique(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	//for (auto it = arr; it != iter; ++it)
//	//	cout << (*it) << " ";
//	//cout << endl;
//	//return 0;
//
//	//vector<int> nums = { 1,1,1,2,2,2,5,6,7,4 };
//	//auto end = unique(nums.begin(), nums.end());
//	//for (auto it = nums.begin(); it != end; ++it)
//	//{
//	//	cout << (*it) << " ";
//	//}
//	//cout << endl;
//
//	string s = "abc";
//	cout << s.size() << endl;
//
//
//	return 0;
//
//}


//int main()
//{
//    class Solution {
//    public:
//        vector<int> inventoryManagement(vector<int>& stock, int cnt) {
//            // topK
//            int n = stock.size();
//            for (int i = n - 1; i >= 0; --i)
//                adjustDown(stock, i, n);
//
//            vector<int> ret(cnt);
//            for (int i = 0; i < cnt; ++i)
//            {
//                for (int j = 0; j < n - i; ++j)
//                    cout << stock[j] << " ";
//                cout << endl;
//                cout << "swap: " << stock[0] << "  " << stock[n - 1 - i] << endl;
//
//                ret[i] = stock[0];
//                int end = n - 1 - i;
//                swap(stock[0], stock[end]);
//                adjustDown(stock, 0, end);
//            }
//            return ret;
//        }
//
//        // 向下调整
//        void adjustDown(vector<int>& arr, int root, int end)
//        {
//            int n = end, parent = root, child = 2 * root + 1;
//            while (child < n)
//            {
//                if (child + 1 < n && arr[child + 1] < arr[child]) child++;
//                if (child < n && arr[child] < arr[parent]) swap(arr[child], arr[parent]);
//                else break;
//                parent = child;
//                child = 2 * parent + 1;
//            }
//        }
//    };
//
//    vector<int> arr = { 0,0,1,2,4,2,2,3,1,4 };
//    auto v = Solution().inventoryManagement(arr, 8);
//    cout << "outcome: " << endl;
//    for (auto e : v)
//        cout << e << " ";
//    cout << endl;
//
//	return 0;
//}

int main()
{
	//const char *pchar = "123456aavb";
	//char str[] = "123456aavb";
	//cout << sizeof(pchar) << endl;	// 指针大小
	//cout << sizeof(str) << endl;	// 数组大小

	vector<int> arr = { 1,2,3,4,5 };
	//reverse(arr.begin(), arr.begin() + 3);
	reverse(arr.begin(), arr.begin() + 2);
	for (auto e : arr) cout << e << " ";
	cout << endl;

	return 0;
}