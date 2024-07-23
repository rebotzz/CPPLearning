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

    // ������,һ������
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

        // ��һ����֮ǰ��ͬ��
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
// 64 λ������� printf("%lld")














// ������ִ�����     -> ���ְ���ûͨ��
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param arr int����vector the array
     * @return int����
     */
    int maxLength(vector<int>& arr) {
        int ret = 0;
        unordered_set<size_t> hash;
        hash.clear();
        int left = 0, right = 0, n = arr.size();

        // ǰ��,����
        while (right < n) {
            if (!hash.count(arr[right])) hash.insert(arr[right]);
            else { hash.clear(); hash.insert(arr[right]); }
            ret = max(ret, (int)hash.size());
            right++;
        }

        return ret;
    }



};


#endif
















