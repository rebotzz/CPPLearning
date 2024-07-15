#include <optional>
#include <regex>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */
    vector<vector<bool>> visited;
    int m = 0, n = 0;
    bool ret = false;
    bool exist(vector<string>& board, string word) {
        if (board.size() == 0 && word.size() == 0) return true;
        else if (board.size() == 0 || word.size() == 0) return false;

        // dfs
        ret = false;
        m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        // cout<<"word size: "<<word.size()<<endl;
        if (word.size() > m * n) return false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    const int dx[4] = { 1, -1, 0, 0 };
    const int dy[4] = { 0, 0, 1, -1 };
    bool dfs(const vector<string>& board, const string& word, int x, int y, int pos) {
        if (pos < word.size() && word[pos] != board[x][y]) return false;
        if (pos == word.size()) {    // pos 从0 开始, 如果所有都访问了

            printf("成功! pos: %d, word size: %d\n", pos, word.size());
            for (auto& v : visited) {
                for (auto e : v) {
                    cout << e << " ";
                }
                cout << endl;
            }
            cout << endl;

            ret = true;
            return true;
        }

        if (pos == 0) cout << "-------------begin---------------------" << endl;
         printf("pos: %d\n", pos);
        for (auto& v : visited) {
            for (auto e : v) {
                cout << e << " ";
            }
            cout << endl;
        }
        cout << endl;

        // 当前位置符合,继续下一个
        // 上下左右判断
        for (int k = 0; k < 4; ++k) {
            int _x = x + dx[k], _y = y + dy[k];
            if (_x >= 0 && _x < m && _y >= 0 && _y < n && visited[_x][_y] == false) {
                visited[_x][_y] = true;
                if (dfs(board, word, _x, _y, pos + 1)) return true;
                visited[_x][_y] = false; // 恢复现场
            }
        }

        // 所有路径都失败
        return false;
    }
};


void test_shared_ptr()
{
    class A
    {
    public:
        shared_ptr<int> _ptr;
    };

    A tmp;
    A* pa = nullptr;
    {
        auto p1 = shared_ptr<int>(new int(45));
        A a, b;
        pa = &a;
        a._ptr = p1;
        b._ptr = p1;
        tmp._ptr = p1;
        auto p2 = a._ptr;

        cout << p1.use_count() << endl;
        cout << a._ptr.use_count() << endl;
        cout << p2.use_count() << endl;
        cout << p1.get() << endl;
        // 都指向都一个对象
    }

    cout << pa->_ptr.use_count() << endl;   // 到这里shared_ptr指向的对象释放了, 除了tmp
    cout << pa->_ptr.get() << endl;
}

void test_class()
{
    class A
    {
    public:
        int _a = -1;
        A() 
        {}
        A(int a):_a(a)
        {}
    };

    typename A a(3);
    cout << a._a << endl;
    cout << A()._a << endl;
}


//int main()
//{
//    //string str = "111111111"; //10个1  多一个
//    //vector<string> vv = { "111","111", "111" };
//
//    //if (Solution().exist(vv, str)) cout << "存在" << endl;
//    //else cout << "不存在" << endl;
//
//    //test_shared_ptr();
//    test_class();
//
//    return 0;
//}













