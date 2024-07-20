#include <iostream>
#include <vector>
using namespace std;


void plan1() {
    int n, price;
    cin >> n;
    vector<int> arr(n);
    for (auto& e : arr) cin >> e;
    int ret = 0;
    int left = 0, right = 1;
    while (right < n) {
        if (arr[right] >
            arr[left]) {   // 只考虑了后一天的情况,间隔多天的情况没考虑
            ret += arr[right] - arr[left];
            right++;
            left = right;
        }
        else {
            right++;
        }
    }

    cout << ret;
}

void plan2() {
    int n, price;
    cin >> n;
    vector<int> arr(n), dp(n);
    for (auto& e : arr) cin >> e;
    int ret = 0;
    for (int i = 1; i < n; ++i) {
        // 第i天最大收获 = 第i-1天最大 + 当天收获
        dp[i] = dp[i - 1] + max(0, arr[i] - arr[i - 1]);
    }

    ret = dp[n - 1];
    cout << ret;
}

//int main() {
//    plan2();
//
//    return 0;
//}
// 64 位输出请用 printf("%lld")
















