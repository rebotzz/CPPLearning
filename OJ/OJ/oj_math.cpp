#include <iostream>
using namespace std;

// 最大公约数
int maxCommonNum(int x, int y)
{
	int a = max(x, y), b = min(x, y);
	// 辗转相除法
	// 大 / 小 = 商 ...... 余数
	// 大(前一个小) / 小(前一个余数) = 商 ...... 余数
	// ...
	// 大 / 小 = 商  -> 余数为0,最大公约数: 小
	int mod = a % b;
	while (mod)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

// 最小公倍数
int minCommonNum(int x, int y)
{
	// 最小公倍数 = x * y / 最大公约数
	return x * y / maxCommonNum(x, y);
}

int main()
{
	cout << maxCommonNum(30, 18) << endl;
	cout << maxCommonNum(81, 97) << endl;
	cout << maxCommonNum(102, 69) << endl;

	cout << minCommonNum(15, 5) << endl;
	cout << minCommonNum(30, 18) << endl;

	return 0;
}