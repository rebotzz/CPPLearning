#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "move_cursor.hpp"

using namespace std;


enum PatternDirection
{
	// windows键盘方向键输入对应数字
	DIR_UP = 72,
	DIR_DOWN = 80,
	DIR_LEFT = 75,
	DIR_RIGHT = 77
};

// 图案砖块
class Pattern	// : public PatternBase
{
	using func_t = function<void(Pattern*)>;
public:
	Pattern(string name = "T")
		:_name(name)
	{
		make(_name);
	}
	~Pattern()
	{}

	// 获取图案
	vector<vector<int>> get()
	{
		return _pattern;
	}

	void printPattern()
	{
		for (auto x : _pattern)
		{
			for (auto y : x)
			{
				cout << y;
			}
			cout << endl;
		}
		cout << endl;
	}

	// 光标移动覆盖print
	void printPt(int x, int y)
	{
		int high_x = _pattern.size();		//2
		int width_y = _pattern[0].size();	//3
		clearOldLine(x, y);
		for (int i = x; i < x + high_x; ++i)
		{
			for (int j = y; j < y + width_y; ++j)
			{
				gotoxy(i, j);
				cout << _pattern[i - x][j - y];
			}
		}
		fflush(stdout);
	}

	void clearOldLine(int x, int y)
	{
		int width_y = _pattern[0].size();	//3
		for (int i = y; i < y + width_y; ++i)
		{
			gotoxy(x, i);
			cout << 0;
		}
	}

	void changeDir(PatternDirection dir)
	{
		switch (dir)
		{
		case DIR_UP:

			break;
		case DIR_DOWN:

			break;		
		case DIR_LEFT:

			break;
		case DIR_RIGHT:

			break;
		default:
			cerr << "changeDir error, no direction" << endl;
			break;
		}
	}

	int getx()
	{
		return _pattern.size();
	}

	int gety()
	{
		return _pattern[0].size();
	}

protected:
	void make(string patternName)
	{
		static unordered_map<string, func_t> mkmap = { 
			{"T",[](Pattern* ptr) {
				ptr->resize(2,3);
				ptr->build("T");
			}}
			,{"田",[](Pattern* ptr) {
				ptr->resize(2,2);
				ptr->build("田");
				}}
			,{"一",[](Pattern* ptr) {
				ptr->resize(1,4);
				ptr->build("一");
				}}
			,{"L",[](Pattern* ptr) {
				ptr->resize(2,3);
				ptr->build("L");
				}}
		};
		
		if (mkmap.find(patternName) != mkmap.end())
		{
			mkmap[patternName](this);
		}
		else
		{
			cout << "make not find" << endl;
		}
	}

	void resize(int x, int y)
	{
		_pattern.resize(x);
		for (auto& vv : _pattern)
		{
			vv.resize(y, 0);	//初始化0
		}
	}

	void build(string str)
	{
		if (str == "T")
		{
			//2*3
			_pattern[0][0] = 0;
			_pattern[0][1] = 1;
			_pattern[0][2] = 0;
			_pattern[1][0] = 1;
			_pattern[1][1] = 1;
			_pattern[1][2] = 1;
		}
		else if (str == "田")
		{
			//2*2
			_pattern[0][0] = 1;
			_pattern[0][1] = 1;
			_pattern[1][0] = 1;
			_pattern[1][1] = 1;
		}
		else if (str == "一")
		{
			//1*4
			_pattern[0][0] = 1;
			_pattern[0][1] = 1;
			_pattern[0][2] = 1;
			_pattern[0][3] = 1;
		}
		else if (str == "L")
		{
			//2*3
			_pattern[0][0] = 1;
			_pattern[0][1] = 0;
			_pattern[0][2] = 0;
			_pattern[1][0] = 1;
			_pattern[1][1] = 1;
			_pattern[1][2] = 1;
		}
	}

protected:
	vector<vector<int>> _pattern;	//_pattern[x][y];
	string _name;
};

// 整个表格
class Table
{
public:
	Table(int x = 10, int y = 10)
		:_x(x)
		, _y(y)
		, _table(_x)
	{
		for (auto& v : _table)
		{
			v.resize(_y);
		}

		//init
		for (auto& vx : _table)
		{
			for (auto& vy : vx)
			{
				vy = 0;
			}
		}

		//cout << "init table" << endl;
	}
	~Table()
	{}

	//notice: 2*横 == 换行
	void Print()
	{
		for (int i = 0; i <= _x; ++i)
		{
			cout << "|";
			for (int j = 0; j < _y; ++j)
			{
				//underlayer
				if (i == _x)
				{
					cout << "--";
				}
				else
				{
					if (_table[i][j] == 1)
					{
						cout << "■ ";
					}
					else
					{
						cout << "  ";
					}
				}

			}
			cout << "|" << endl;
		}
	}

	void printBinary()
	{
		for (int i = 0; i <= _x + 1; ++i)
		{
			//if (-1 != i && _x + 1 != i) printf("%2d", i);
			//else printf("  ");
			//cout << "| ";
			for (int j = 0; j < _y; ++j)
			{
				//up
				if (i == -1)
				{
					//cout << "-";
					continue;
				}
				//underlayer
				if (i == _x)
				{
					//cout << "-";
					continue;
				}
				if (i == _x + 1)
				{
					printf("%d", j);
					continue;
				}
				cout << _table[i][j];
			}
			cout << endl;
			//cout << " |" << endl;
		}
	}

	// 坐标; 图案
	// 注意 y <= _y - width_y
	void checkStatus(int x, int y, vector<vector<int>> pattern)
	{
		int high_x = pattern.size();
		int width_y = pattern[0].size();

		cout << "high_x: " << high_x << endl;
		cout << "width_y: " << width_y << endl;

		int px = 0;	//pattern内部相对坐标
		int py = 0;
	}


public:
	int _x;
	int _y;
	vector<vector<int>> _table;	//_table[x][y];
};


class Game
{
public:
	// windows默认: 横x, 竖y  -- 与数组不同: 横y, 竖x
	// 为了方便处理,统一使用数组表示
	Game(int x = 10, int y = 10)
		:_tb(x, y),_dir(DIR_UP)
	{
		
	}
	~Game(){}

	void start()
	{
		int x = rand() % (_tb._x - _pt.getx());
		int y = rand() % (_tb._y - _pt.gety());
		_pt = Pattern("L");
		_pt.printPattern();
		system("pause");
		system("cls");
		while (true)
		{
			// 1.print table
			_tb.printBinary();

			// 2.print pattern
			_pt.printPt(x++,y);
			fflush(stdout);
			//// 3.change direction
			//changeDirection();

			//// 4.check fail	 -- fail: false;	 go on: true
			//bool go = checkStatus();
			//if (!go)
			//{
			//	// 5.1 fail
			//	break;
			//}

			//// 5.drop
			//drop();


			//// 5.2 check bottom
			//int line = checkBottom();

			//// 5.2.1 delete bottom
			//deleteBottom(line);

			// 6.sleep
			this_thread::sleep_for(chrono::milliseconds(700));

			//system("pause");
			system("cls");

		}

		endGame();

	}

	void endGame()
	{
		system("cls");
		cout << "game over" << endl;
	}

	void changeDirection()
	{
		PatternDirection dir = KeyInput();
		_pt.changeDir(dir);
	}

	bool checkStatus()
	{
		return true;
	}

	void deleteBottom(int line)
	{

	}


	
	void drop()
	{

	}

	int checkBottom()
	{

		return 0;
	}

	//检查键盘输入,改变前进方向
	PatternDirection KeyInput()
	{
		int key;
		PatternDirection pre_key = _dir;//记录上一次输入方向
		//检查是否有键盘输入
		if (_kbhit())
		{
			//检查输入合法性留到后面
			key = _getch();	//方向键会返回两次数值,第一次224
			key = _getch();	//第二次方向对应数值

			//清空输入缓存区
			fflush(stdin);

			//输入坐标不能与原方向相反,相反则方向不变
			if (key == 72 && pre_key == 80)//上
				key = pre_key;
			if (key == 80 && pre_key == 72)//下
				key = pre_key;
			if (key == 75 && pre_key == 77)//左
				key = pre_key;
			if (key == 77 && pre_key == 75)//右
				key = pre_key;
		}

		return (PatternDirection)key;
	}


private:
	Table _tb;
	Pattern _pt;			
	PatternDirection _dir;	//pattern方向
};