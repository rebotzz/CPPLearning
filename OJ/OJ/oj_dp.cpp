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
            arr[left]) {   // ֻ�����˺�һ������,�����������û����
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
        // ��i������ջ� = ��i-1����� + �����ջ�
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
// 64 λ������� printf("%lld")
















