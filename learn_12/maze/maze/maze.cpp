//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stack>
//#include <vector>	
//using namespace std;
//
//// 迷宫问题
//// 输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走
//// 的路。数据保证有唯一解, 不考虑有多解的情况，即迷宫只有一条通道。
//// 迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序
//// 找出从左上角到右下角的路线。入口点为[0, 0], 既第一格是可以走的路. 出口点[N-1, M-1]
//
//// 判断是否有路
//bool IsPath(vector<vector<int>>& maze, pair<int, int> cur)
//{
//	int x = cur.first;
//	int y = cur.second;
//	// 不能为遇到边界或者壁面
//	if ((x >= 0 && y >= 0)
//		&& (x < maze.size() && y < maze[0].size())
//		&& maze[x][y] == 0
//		)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//// 获取迷宫出路
//bool GetPath(vector<vector<int>>& maze, pair<int, int> cur, pair<int, int> out, stack<pair<int, int>>& path)
//{
//	int x = cur.first;
//	int y = cur.second;
//	// 找到出口
//	if (x == out.first && y == out.second)
//	{
//		cout << "find out:" << x << ":" << y << endl;
//		return true;
//	}
//	// 第一次运行
//	if (path.empty())
//	{
//		maze[x][y] = 2;
//		path.push(make_pair(x, y));
//	}
//
//	//printf("(%d,%d)\n", x, y);
//	
//	// 上
//	if (IsPath(maze, make_pair(x -1, y)))
//	{
//		maze[x-1][y] = 2;
//		path.push(make_pair(x - 1, y));
//		if (GetPath(maze, make_pair(x - 1, y), out, path))
//			return true;
//	}
//	// 下
//	if (IsPath(maze, make_pair(x + 1, y)))
//	{
//		maze[x+1][y] = 2;
//		path.push(make_pair(x + 1, y));
//		if (GetPath(maze, make_pair(x + 1, y), out, path))
//			return true;
//	}
//	// 左
//	if (IsPath(maze, make_pair(x, y - 1)))
//	{
//		maze[x][y-1] = 2;
//		path.push(make_pair(x, y - 1));
//		if (GetPath(maze, make_pair(x, y - 1), out, path))
//			return true;
//	}
//	// 右
//	if (IsPath(maze, make_pair(x, y + 1)))
//	{
//		maze[x][y+1] = 2;
//		path.push(make_pair(x, y + 1));
//		if (GetPath(maze, make_pair(x, y + 1), out, path))
//			return true;
//	}
//
//	// 上下左右都没有出路
//	if(!path.empty())
//		path.pop();
//	return false;
//}
//
//int main()
//{
//	//输入迷宫大小 N*M
//	int N = 0, M = 0;
//	cout << "input: N, M" << endl;
//	while (cin >> N >> M)
//	{
//		//输入迷宫 二维数组
//		vector<vector<int>> maze(N,vector<int>(M,0));
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				cin >> maze[i][j];
//			}
//		}
//
//		// 打印迷宫
//		cout << "print maze:" << endl;
//		for (auto row : maze)
//		{
//			for (auto col : row)
//			{
//				cout << col << " ";
//			}
//			cout << endl;
//		}
//		
//		//获取迷宫出路 栈记录路径
//		stack<pair<int, int>> path;
//		pair<int, int> enter = make_pair(0, 0);
//		pair<int, int> out = make_pair(N - 1, M - 1);
//		GetPath(maze, enter, out, path);
//
//		cout << "path:" << endl;
//		stack<pair<int, int> > rpath;
//		while (!path.empty())
//		{
//			rpath.push(path.top());
//			path.pop();
//		}
//		while (!rpath.empty())
//		{
//			printf("(%d,%d)", rpath.top().first, rpath.top().second);
//			rpath.pop();
//		}
//
//	}
//	return 0;
//}
