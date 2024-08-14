#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include "coderain.hpp"
using namespace std;
// 数字雨



int main()
{
#ifdef DIF
	srand((unsigned int)time(nullptr));
	// todo: 获取窗口大小，动态调整尺寸
	vector<int> table;		//15滴雨
	set<int> st;			// 利用set去重

	begin:
	st.clear();
	while (st.size() < 20)
	{
		int tmp = (rand() % 59) * 2;
		st.insert(tmp);
		//cout << tmp << " ";
	}

	for (auto s : st)
	{
		table.push_back(s);
	}

	//for (int i = 1; i <= 25; i++)
	//{
	//	int tmp = 4 * i - 1;
	//	table.push_back(tmp);
	//	gotoxy(tmp, 0);
	//	//cout << i << " ";
	//	//printf("%2d ", tmp);
	//}
	//cout << "-----------------------" << endl;

	vector<Rain> rains;
	for (auto x : table)
	{
		rains.push_back(Rain(x));
	}
	int sz = rains.size();

	while (true)
	{
		for (auto& r : rains)
		{
			r.drop();
			//Sleep(1);
			//this_thread::sleep_for(chrono::milliseconds(2));
			this_thread::sleep_for(chrono::milliseconds(1));
			if (r.death()) sz--;
		}
		if (sz <= 0)
		{
			break;
		}
	}

	system("cls");
	goto begin;

#else
	// 简易代码雨
	simple_rain();


#endif





	return 0;
}

