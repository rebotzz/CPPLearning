#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

//class MyClass;
//
//class MyClass
//{
//	friend size_t myhash(const MyClass& mc);
//public:
//	MyClass(int a, int arr[]) 
//		:_a(a), _arr(arr)
//	{}
//
//	~MyClass()
//	{}
//
//	MyClass(const MyClass& mc)
//		:_a(mc._a), _arr(mc._arr)
//	{}
//
//	MyClass(MyClass& mc)
//		:_a(mc._a), _arr(mc._arr)
//	{}
//
//	bool operator==(const MyClass& mc) const
//	{
//		cout << "operator==(const MyClass& mc)" << endl;
//		bool ret = false;
//		if (mc._arr[0] == _arr[0] && mc._arr[1] == _arr[1])
//			ret = true;
//		return _a == mc._a && ret;
//	}
//
//	void print() const
//	{
//		printf("a: %d arr: %d %d\n", _a, _arr[0], _arr[1]);
//	}
//
//private:
//	int _a;
//	int* _arr;
//};
//
//size_t myhash(const MyClass& mc)
//{
//	hash<int> hashfunc;
//	return hashfunc(mc._a) ^ hashfunc(mc._arr[0]) ^ hashfunc(mc._arr[1]);
//}
//
//
////namespace std
////{
////	template<class T>
////	size_t hash<MyClass> ()
////	{
////
////	}
////}
//
//struct Myhash
//{
//	size_t operator()(const MyClass& mc) const
//	{
//		return myhash(mc);
//	}
//};

//int main()
//{
//	decltype(myhash);
//	cout << typeid(myhash).name() << endl;
//	cout << typeid(decltype(myhash)).name() << endl;
//	cout << typeid(decltype(myhash)*).name() << endl;
//
//	//unordered_set<MyClass, decltype(myhash)*> st;
//	unordered_set<MyClass, Myhash> st;
//	int arr1[] = { 1,2 };
//	int arr2[] = { -1,7 };
//	int arr3[] = { 45,19 };
//	st.insert(MyClass(1, arr1));
//	st.insert(MyClass(1, arr1));
//	st.insert(MyClass(2, arr2));
//	st.insert(MyClass(3, arr3));
//
//	for (const auto& e : st)
//	{
//		e.print();
//	}
//
//	return 0;
//}


#include <unordered_set>

struct Mydata
{
public:
    Mydata(int a, int b, int c)
    {
        _v = { a,b,c };
    }

    Mydata(const Mydata& md)
    {
        _v = md._v;
    }

    bool operator==(const Mydata& md) const
    {
        return (_v[0] == md._v[0] && _v[1] == md._v[1] && _v[2] == md._v[2]);
    }

    vector<int> _v;
};
struct Myhash
{
public:
    size_t operator()(const Mydata& md) const
    {
        hash<int> hf;
        auto& v = md._v;
        return hf(v[0]) ^ hf(v[1]) ^ hf(v[2]);
    }
};

class Solution {
public:




    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<Mydata, Myhash> st;  // 需要自己写哈希映射
        int size = nums.size();
        for (int i = size - 1; i >= 2; --i)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];

                if (sum > 0) right--;
                else if (sum < 0) left++;
                else
                {
                    st.emplace(Mydata(nums[left++], nums[right--], nums[i]));
                }
            }

            // [0,0,0]只要一个就行，前面的都比0小，不可能了
            if (nums[i] == 0) break;
        }

        vector<vector<int>> ret;
        for (auto& v : st)
        {
            ret.push_back(v._v);
        }

        return ret;
    }

};

//int main()
//{
//    Solution s;
//    vector<int> arr = { -1,0,1,2,-1,-4 };
//    auto vv = s.threeSum(arr);
//    return 0;
//}