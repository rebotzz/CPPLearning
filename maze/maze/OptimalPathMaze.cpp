#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>	
using namespace std;

// 迷宫问题 -- 最优路径: 遍历所有可能路径,有更短路径就更新路径
// 小青蛙有一天不小心落入了一个地下迷宫, 小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
// 为了让问题简单, 假设这是一个n* m的格子迷宫, 迷宫每个位置为0或者1, 0代表这个位置有障碍物, 
// 小青蛙达到不了这个位置; 1代表小青蛙可以达到的位置。小青蛙初始在(0, 0)位置, 
// 地下迷宫的出口在(0, m - 1)(保证这两个位置都是1, 并且保证一定有起点到终点可达的路径), 
// 小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值, 向上爬一个单位距离需要消耗3个单位的体力值, 
// 向下移动不消耗体力值, 当小青蛙的体力值等于0的时候还没有到达出口, 小青蛙将无法逃离迷宫。
// 现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0, m - 1)位置)。
//

// 打印路径
void printPath(stack<pair<int, int>> path)
{
	cout << "path:" << endl;
	stack<pair<int, int> > rpath;
	// 逆置栈
	while (!path.empty())
	{
		rpath.push(path.top());
		path.pop();
	}
	while (!rpath.empty())
	{
		if(rpath.size() > 1)
		{
			printf("[%d,%d],", rpath.top().first, rpath.top().second);
			rpath.pop();
		}
		else if(rpath.size() == 1)
		{
			printf("[%d,%d]", rpath.top().first, rpath.top().second);
			rpath.pop();
		}
	}
	cout << endl;
}

// 打印迷宫
void printMaze(vector<vector<int>>& maze)
{
	cout << "print maze:" << endl;
	for (auto row : maze)
	{
		for (auto col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
}

// 判断是否有路,是否能走
bool IsPath(vector<vector<int>>& maze, pair<int, int> cur)
{
	int x = cur.first;
	int y = cur.second;
	// 不能为遇到边界或者壁面
	if ((x >= 0 && y >= 0)
		&& (x < maze.size() && y < maze[0].size())
		&& maze[x][y] == 1
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 获取迷宫出路
void GetPath(vector<vector<int>>& maze, pair<int, int> cur, pair<int, int> out, stack<pair<int, int>>& path, stack<pair<int, int>>& minpath, int P)
{
	int x = cur.first;
	int y = cur.second;

	// 找到出口
	if (x == out.first && y == out.second)
	{
		// 还有体力,且找到更短的路径,更新路径
		if ((P >= 0) && (path.size() < minpath.size() || minpath.size() == 0))
		{
			minpath = path;
		}
		// 恢复走过的标记节点,删除最后记录的节点
		maze[x][y] = 1;
		path.pop();
		return;
	}

	// 第一次运行
	if (path.empty() && IsPath(maze, make_pair(x,y)))
	{
		maze[x][y] = 2;
		path.push(make_pair(x, y));
	}

	// 递归,遍历路径,类似二叉树遍历,返回后走过的路径就不会再走了
	// 上
	if (IsPath(maze, make_pair(x - 1, y)))
	{
		// 标记走过的路径
		maze[x - 1][y] = 2;
		path.push(make_pair(x - 1, y));
		GetPath(maze, make_pair(x - 1, y), out, path, minpath, P - 3);
		//maze[x - 1][y] = 1;	//debug: 这样恢复走过路径数组似乎会越界,原因未知
	}
	// 下
	if (IsPath(maze, make_pair(x + 1, y)))
	{
		maze[x + 1][y] = 2;
		path.push(make_pair(x + 1, y));
		GetPath(maze, make_pair(x + 1, y), out, path, minpath, P);
	}
	// 左
	if (IsPath(maze, make_pair(x, y - 1)))
	{
		maze[x][y - 1] = 2;
		path.push(make_pair(x, y - 1));
		GetPath(maze, make_pair(x, y - 1), out, path, minpath, P - 1);
	}
	// 右
	if (IsPath(maze, make_pair(x, y + 1)))
	{
		maze[x][y + 1] = 2;
		path.push(make_pair(x, y + 1));
		GetPath(maze, make_pair(x, y + 1), out, path, minpath, P - 1);
	}

	// 上下左右都没有出路
	// 恢复走过的标记节点,删除最后记录的节点
	maze[x][y] = 1;
	if (!path.empty())
		path.pop();
}

int main()
{
	//输入迷宫大小 N*M, 体力值P
	int N = 0, M = 0, P = 0;
	cout << "input: N, M" << endl;
	while (cin >> N >> M >> P)
	{
		//输入迷宫 二维数组
		vector<vector<int>> maze(N, vector<int>(M, 0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> maze[i][j];
			}
		}

		// 打印迷宫
		printMaze(maze);

		//获取迷宫出路 栈记录路径
		stack<pair<int, int>> path;
		stack<pair<int, int>> minpath;
		pair<int, int> enter = make_pair(0, 0);
		pair<int, int> out = make_pair(0, M - 1);
		GetPath(maze, enter, out, path, minpath, P);

		//打印路径
		if(!minpath.empty())
		{
			printPath(minpath);
		}
		else
		{
			cout << "Can not escape!" << endl;
		}

		//cout << "----结束----" << endl;
	}
	return 0;
}
