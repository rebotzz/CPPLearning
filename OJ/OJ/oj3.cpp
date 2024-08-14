#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "unordered_map"
using namespace std;


#if 0

string ret;
vector<bool> visited;
bool dfs(string& s) {
    if (ret.size() == s.size()) return true;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        bool pre = false;
        if (ret.size() > 0 && ret.back() == s[i]) pre = true;
        if (visited[i] == false && pre == false) {
            visited[i] = true;
            ret.push_back(s[i]);
            if (dfs(s)) return true;
            ret.pop_back();
            visited[i] = false;
        }
    }

    return false;
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.resize(n);
    unordered_map<char, int> hash1;
    int hash[128] = { 0 };

    for (auto ch : s) {
        if (++hash[ch] > (n + 1) / 2) {
            cout << "no";
            return 0;
        }
        hash1[ch]++;
    }

    // 到这里,一定可以
    string ret1;
    while (ret1.size() < n) {
        if (ret1.empty()) {
            auto it = hash1.begin();
            ret1.push_back(it->first);
            if (--it->second == 0) {
                hash1.erase(it);
            }
            continue;
        }

        // 找一个与之前不同的
        auto it = hash1.begin();
        char pre = ret.back();
        while (it != hash1.end()) {
            if (it->first != pre) {
                ret.push_back(it->first);
                if (--it->second == 0) {
                    hash1.erase(it);
                }
                break;
            }
            else ++it;
        }

        if (it == hash1.end()) {
            cout << "no";
            return 0;
        }
    }


    // visited.resize(n, false);
    // if (dfs(s)) {
    //     cout << "yes" << endl;
    //     cout << ret;
    // } else cout << "no";

    return 0;
}
// 64 位输出请用 printf("%lld")














// 最长连续字串长度     -> 部分案例没通过
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        int ret = 0;
        unordered_set<size_t> hash;
        hash.clear();
        int left = 0, right = 0, n = arr.size();

        // 前提,连续
        while (right < n) {
            if (!hash.count(arr[right])) hash.insert(arr[right]);
            else { hash.clear(); hash.insert(arr[right]); }
            ret = max(ret, (int)hash.size());
            right++;
        }

        return ret;
    }



};



#include <iostream>
#include "vector"
#include "unordered_map"
#include "queue"
using namespace std;

int main() {
    int n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    unordered_map<int, int> hash;
    for (auto e : v) hash[e]++;
    int ret = 0;

    // while(hash.size() > 1){
    //     for(auto [k, v] :hash){
    //         int mid = k * v;
    //         int left = 0, right = 0;
    //         if(hash.count(k - 1)) left = hash[k - 1] * (k - 1);
    //         if(hash.count(k + 1)) right = hash[k + 1] * (k + 1);
    //         if(left + right < mid){
    //             ret += k;
    //             if(hash.count(k - 1)) hash.erase(k - 1);
    //             if(hash.count(k + 1)) hash.erase(k + 1);
    //         }
    //         else{

    //         }
    //     }
    // }

    // auto kv = *hash.begin();
    // ret += kv.first * kv.second;

    // priority_queue<pair<int,int>> pq()
    unordered_map<int, int> hash2;
    priority_queue<int> pq;
    for (auto [k, v] : hash) {
        hash2[k * v] = k;
        pq.push(k * v);
    }
    while (pq.size() > 1) {
        int tmp = pq.top();
        int k = hash2[tmp];
        ret += k;
        if (hash.count(k - 1)) {
            hash2.erase(hash[k - 1] * (k - 1));
            hash.erase(k - 1);
        }
        if (hash.count(k + 1)) {
            hash2.erase(hash[k + 1] * (k + 1));
            hash.erase(k + 1);
        }
        if (--hash[k] <= 0) {
            hash.erase(k);
            hash2.erase(tmp);
        }
        else {
            hash[k]--;
            hash2[tmp] -= k;
        }
    }


    cout << ret;
    return 0;
}
// 64 位输出请用 printf("%lld")



bool isPrime(int number)
{
    // ignore negative sign
    number = abs(number);

    // 0 and 1 are no prime numbers
    if (number == 0 || number == 1) {
        return false;
    }

    // find divisor that divides without a remainder
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;
    }

    // if no divisor greater than 1 is found, it is a prime number
    return divisor == 1;
}
















#endif
















