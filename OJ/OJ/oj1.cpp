#include <iostream>
#include <vector>
using namespace std;


// 6条边, 判断是否能够组成连个三角形
class Solution {
    vector<int> path;
    vector<bool> visited;
    bool ret = false;
    int n;
    bool dfs(vector<int>& v) {
        if (ret) return ret;
        if (path.size() == 6) {   // 判断是否能否组成三角形
            ret = isTrangile();
            return ret;
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                visited[i] = true;
                path.push_back(v[i]);
                if (dfs(v)) return ret;
                visited[i] = true;  // 恢复现场
                path.pop_back();
            }
        }

        return ret;
    }

    bool isTrangile() {
        long long a1 = path[0], b1 = path[1], c1 = path[2];
        long long a2 = path[3], b2 = path[4], c2 = path[5];
        return (a1 + b1 > c1) && (a1 + c1 > b1) && (b1 + c1 > a1)
            && (a2 + b2 > c2) && (a2 + c2 > b2) && (b2 + c2 > a2)
            && a1 > 0 && a2 > 0 && b1 > 0 && b2 > 0 && c1 > 0 && c2 > 0;
    }

public:
    bool check(vector<int>& v) {
        n = v.size();
        visited.resize(n, false);
        dfs(v);
        return ret;
    }
};

//
//int main() {
//    int t;
//    cin >> t;
//    // cout<< t<<endl;
//
//    while (t--) {
//        vector<int> v(6);
//        for (auto& x : v) cin >> x;
//
//        // for(auto& x : v) cout << x <<" "; cout<<endl;
//
//        // 判断
//        // if(Solution().check(v)) cout<<"Yes"<<endl;
//        // else cout<<"No"<<endl;
//        if (Solution().check(v)) printf("Yes\n");
//        else printf("No\n");
//    }
//
//    return 0;
//}
// 64 位输出请用 printf("%lld").


#include <iostream>
#include <vector>
using namespace std;

// 小卒走到终点的路径个数, 不能走马以及它的攻击范围
class OJ_dp1 {
public:
    int dp()
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        // 如果初始点不能走
        int i = 0, j = 0;
        if (abs(i - x) + abs(j - y) == 3 && abs(i - x) < 3 && abs(j - y) < 3
            || (i == x && j == y)) {
            cout << 0;
            return 0;
        }
        // 如果终点不能走
        i = n, j = m;
        if (abs(i - x) + abs(j - y) == 3 && abs(i - x) < 3 && abs(j - y) < 3
            || (i == x && j == y)) {
            cout << 0;
            return 0;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int up = 0, left = 0;
                if (i - 1 >= 0) left = dp[i - 1][j];
                if (j - 1 >= 0) up = dp[i][j - 1];
                if (i != 0 || j != 0) dp[i][j] = up + left;

                // 不能在马及它的攻击范围
                if (abs(i - x) + abs(j - y) == 3 && abs(i - x) < 3 && abs(j - y) < 3
                    || (i == x && j == y)) {
                    // printf("[%d, %d] no!\n", i, j);
                    dp[i][j] = 0;
                }
            }
        }

        // cout<<"   ";
        // for(int i = 0; i <= m; ++i) cout<<i<<" ";cout<<endl;
        // int i = 0;
        // for (auto& v : dp) {
        //     cout<<i++<<" ";
        //     for (auto x : v)cout << x << " ";
        //     cout << endl;
        // }
        // cout << endl;

        // cout << dp[n][m];
        printf("%lld\n", dp[n][m]);

        return 0;
    }
};


























