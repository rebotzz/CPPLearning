#include <iostream>
using namespace std;


// 水果: 苹果n / 桃子m, 2苹果+1桃子价格a, 1苹果+2桃子价格b; 求最大卖出收益
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ret = 0, ret1 = 0, ret2 = 0;
    // 全是a
    int apple = n / 2;
    int peach = m;
    if (apple > peach) {
        ret1 = peach * a;
    }
    else {
        ret1 = apple * a;
        // // 考虑剩余可以组成另一组
        if (n % 2 == 1) {
            int leftpeach = peach - apple;
            ret1 += leftpeach / 2 * b;
        }
    }


    // 全是b
    apple = n;
    peach = m / 2;
    if (apple > peach) {
        ret2 = peach * b;
        if (m % 2 == 1) {
            int leftapple = apple - peach;
            ret2 += leftapple / 2 * b;
        }
    }
    else ret2 = apple * b;

    ret = max(ret1, ret2);
    cout << ret;

    return 0;
}
// 64 位输出请用 printf("%lld")












