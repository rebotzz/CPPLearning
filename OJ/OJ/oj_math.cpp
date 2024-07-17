#include <iostream>
using namespace std;

// ���Լ��
int maxCommonNum(int x, int y)
{
	int a = max(x, y), b = min(x, y);
	// շת�����
	// �� / С = �� ...... ����
	// ��(ǰһ��С) / С(ǰһ������) = �� ...... ����
	// ...
	// �� / С = ��  -> ����Ϊ0,���Լ��: С
	int mod = a % b;
	while (mod)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

// ��С������
int minCommonNum(int x, int y)
{
	// ��С������ = x * y / ���Լ��
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