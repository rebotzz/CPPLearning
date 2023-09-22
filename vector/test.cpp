#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	char a[] = "abcd";
	printf("%d\n", "abcd");	//所以这里传递的常量字符串的指针
	int i =(int) "abcd";
	int b = (int)a;
	cout << i << endl;
	cout << b << endl;

	return 0;
}