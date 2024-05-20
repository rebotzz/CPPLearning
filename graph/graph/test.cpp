#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//int arr[] = { 1,1,1,2,2,2,5,6,7,4 };
	//for (auto e : arr)
	//	cout << e << " ";
	//cout << endl;
	//auto iter = unique(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//for (auto it = arr; it != iter; ++it)
	//	cout << (*it) << " ";
	//cout << endl;
	//return 0;

	vector<int> nums = { 1,1,1,2,2,2,5,6,7,4 };
	auto end = unique(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != end; ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	return 0;

}