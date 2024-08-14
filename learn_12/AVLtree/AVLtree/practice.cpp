
// OJ练习

#ifdef PRACTICE

// 前K个高频单词
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 1.0
        map<string, int> cntMap;
        // 统计次数
        for (auto e : words)
        {
            cntMap[e]++;
        }

        // 排序
        vector<pair<string, int>> v(cntMap.begin(), cntMap.end());
        stable_sort(v.begin(), v.end(), comp());

        // 前k个
        vector<string> ret;
        for (int i = 0; i < k; ++i)
        {
            ret.push_back(v[i].first);
        }

        return ret;
    }

    struct comp
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y)
        {
            return x.second > y.second;
        }
    };
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 1.5
        map<string, int> cntMap;
        // 统计次数
        for (auto e : words)
        {
            cntMap[e]++;
        }

        // 排序
        vector<pair<string, int>> v(cntMap.begin(), cntMap.end());
        sort(v.begin(), v.end(), comp());

        // 前k个
        vector<string> ret;
        for (int i = 0; i < k; ++i)
        {
            ret.push_back(v[i].first);
        }

        return ret;
    }

    struct comp
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y)
        {
            // 控制次数和单词顺序
            return x.second > y.second
                || (x.second == y.second && x.first < y.first);
        }
    };
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 2.0
        map<string, int> cntMap;
        // 统计次数
        for (auto e : words)
        {
            cntMap[e]++;
        }

        // 排序
        multiset<pair<string, int>, comp> sortSet(cntMap.begin(), cntMap.end());

        // 前k个
        vector<string> ret;
        multiset<pair<string, int>, comp>::iterator it = sortSet.begin();
        while (k--)
        {
            ret.push_back(it->first);
            ++it;
        }

        return ret;
    }

    struct comp
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y) const //debug: 加上const
        {
            return x.second > y.second;
        }
    };
};







#endif