#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>
#include "logMessage.hpp"
using namespace std;


void func(int a, ...)
{
	int* ptr = &a;
	for (int i = 0; i < a; ++i)
		printf("%d ", *(ptr + i));
	cout << endl;
}

void test1()
{
	//vector<double> tmp(5);
	//for (auto e : tmp) cout << e << " ";
	//cout << endl;

	//time_t now = time(nullptr);
	//tm tim;
	//localtime_s(&tim, &now);
	//tm* local_time = &tim;
	//printf("[%d-%d-%d %02d:%02d:%02d]",
	//	local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
	//	local_time->tm_hour, local_time->tm_min, local_time->tm_sec);


	logMessage(NOTICE, "%d \n", 3);
	logMessage(NOTICE, "测试日志功能\n");
	logMessage(ERROR, "code_file: %s, line: %d\n", __FILEW__, __LINE__);
}

int main()
{
	test1();

	func(4, 1, 2, 3, 4);

	return 0;
}