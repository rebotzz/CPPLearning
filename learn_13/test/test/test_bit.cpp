#include <iostream>
using namespace std;
#define BIT_NUM 31


void printBit(int x) {
	for (int i = BIT_NUM; i >= 0; --i)
	{
		if (x & (1 << i)) printf("1");
		else printf("0");
	}

	printf("\n");
}

//int main()
//{
//	int i = -1;
//	cout << (i >> 1) << endl;
//	cout << ((size_t)i >> 1) << endl;
//	cout << (int((size_t)i >> 1)) << endl;
//	cout << "-------------" << endl;
//	size_t u = -1;
//	cout << u << endl;
//	cout << (u >> 1) << endl;
//	cout << int(u >> 1) << endl;
//	// ���ۣ�>> �������ƣ�����λ���; �������ͣ�ֻ��01����
//
//	cout << "-------------" << endl;
//	int a = 1;
//	printBit(a);
//	printBit(a << 1);
//	printBit(a << 31);
//	printBit(a << 32);	// ���������������
//	cout << a << endl;	// << >> ���ı�ԭ����ֵ
//	
//	return 0;
//}


//int main()
//{
//	printf("test: %d", string("aaa") > string("a"));
//
//	return 0;
//}