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
// ������



int main()
{
#ifdef DIF
	srand((unsigned int)time(nullptr));
	// todo: ��ȡ���ڴ�С����̬�����ߴ�
	vector<int> table;		//15����
	set<int> st;			// ����setȥ��

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
	// ���״�����
	simple_rain();


#endif





	return 0;
}

