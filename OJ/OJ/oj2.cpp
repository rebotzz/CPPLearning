#include <iostream>
using namespace std;


// ˮ��: ƻ��n / ����m, 2ƻ��+1���Ӽ۸�a, 1ƻ��+2���Ӽ۸�b; �������������
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ret = 0, ret1 = 0, ret2 = 0;
    // ȫ��a
    int apple = n / 2;
    int peach = m;
    if (apple > peach) {
        ret1 = peach * a;
    }
    else {
        ret1 = apple * a;
        // // ����ʣ����������һ��
        if (n % 2 == 1) {
            int leftpeach = peach - apple;
            ret1 += leftpeach / 2 * b;
        }
    }


    // ȫ��b
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
// 64 λ������� printf("%lld")












