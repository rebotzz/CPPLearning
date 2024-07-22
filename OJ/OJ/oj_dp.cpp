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



// 找字符串的字串 "shy" 个数 dfs超时
#include <iostream>
#include "string"
using namespace std;

class Solution {
public:
    string path;
    int deep = 0, n = 0;
    int ret = 0;
    string target;
    int dfs(string& str) {
        target = "shy";
        n = target.size();
        _dfs(str, 0);
        return ret;
    }

    void _dfs(string& str, int pos) {
        if (deep >= n) {
            ret++;
            return;
        }

        for (int i = pos; i < str.size(); ++i) {
            if (str[i] == target[deep]) {
                deep++;
                _dfs(str, i + 1);
                deep--;
            }
        }
    }
};

#include <array>
#include <unordered_map>
int main() {
    int n;
    string str;
    cin >> n;
    str.resize(n);
    cin >> str;

    // 先缩减不要的
    string tmp;
    for (auto ch : str) {
        if (ch == 's' || ch == 'h' || ch == 'y') tmp.push_back(ch);
    }

    int ret = 0;
    ret = Solution().dfs(tmp);
    cout << ret;


    // // 模拟
    // int hash[3] = {0};
    // unordered_map<char, int> index; // 前一个字符的下标
    // // int index[128] = {-1};
    // index['s'] = 0;
    // index['h'] = 0;
    // index['y'] = 1;
    // unordered_map<char, int> indexcur; // 前一个字符的下标
    // indexcur['h'] = 1;
    // indexcur['y'] = 2;
    // for (char ch : str) {
    //     // 判断前一个字符是否出现
    //     if(index.count(ch)){
    //     // if (index[ch] != -1) {  // 是需要的字符
    //         // 首字符特殊处理
    //         if (ch == 's') {
    //             hash[0]++;
    //         } else {
    //             // 先看前一个有没有
    //             int pre = index[ch];
    //             if (hash[pre] > 0) {
    //                 hash[pre]--;
    //                 hash[indexcur[ch]]++;
    //             }
    //         }
    //     }
    // }

    // // 有序的组合   漏了:零散的字
    // int m = hash[2];
    // ret = m * m * m;
    // cout << ret;

    return 0;
}
// 64 位输出请用 printf("%lld")


























