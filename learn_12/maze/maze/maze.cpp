//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stack>
//#include <vector>	
//using namespace std;
//
//// �Թ�����
//// ���������������ֱ��ʾ��ά�������������������������Ӧ�����飬���е�1��ʾǽ�ڣ�0��ʾ������
//// ��·�����ݱ�֤��Ψһ��, �������ж�����������Թ�ֻ��һ��ͨ����
//// �Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ������
//// �ҳ������Ͻǵ����½ǵ�·�ߡ���ڵ�Ϊ[0, 0], �ȵ�һ���ǿ����ߵ�·. ���ڵ�[N-1, M-1]
//
//// �ж��Ƿ���·
//bool IsPath(vector<vector<int>>& maze, pair<int, int> cur)
//{
//	int x = cur.first;
//	int y = cur.second;
//	// ����Ϊ�����߽���߱���
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
//// ��ȡ�Թ���·
//bool GetPath(vector<vector<int>>& maze, pair<int, int> cur, pair<int, int> out, stack<pair<int, int>>& path)
//{
//	int x = cur.first;
//	int y = cur.second;
//	// �ҵ�����
//	if (x == out.first && y == out.second)
//	{
//		cout << "find out:" << x << ":" << y << endl;
//		return true;
//	}
//	// ��һ������
//	if (path.empty())
//	{
//		maze[x][y] = 2;
//		path.push(make_pair(x, y));
//	}
//
//	//printf("(%d,%d)\n", x, y);
//	
//	// ��
//	if (IsPath(maze, make_pair(x -1, y)))
//	{
//		maze[x-1][y] = 2;
//		path.push(make_pair(x - 1, y));
//		if (GetPath(maze, make_pair(x - 1, y), out, path))
//			return true;
//	}
//	// ��
//	if (IsPath(maze, make_pair(x + 1, y)))
//	{
//		maze[x+1][y] = 2;
//		path.push(make_pair(x + 1, y));
//		if (GetPath(maze, make_pair(x + 1, y), out, path))
//			return true;
//	}
//	// ��
//	if (IsPath(maze, make_pair(x, y - 1)))
//	{
//		maze[x][y-1] = 2;
//		path.push(make_pair(x, y - 1));
//		if (GetPath(maze, make_pair(x, y - 1), out, path))
//			return true;
//	}
//	// ��
//	if (IsPath(maze, make_pair(x, y + 1)))
//	{
//		maze[x][y+1] = 2;
//		path.push(make_pair(x, y + 1));
//		if (GetPath(maze, make_pair(x, y + 1), out, path))
//			return true;
//	}
//
//	// �������Ҷ�û�г�·
//	if(!path.empty())
//		path.pop();
//	return false;
//}
//
//int main()
//{
//	//�����Թ���С N*M
//	int N = 0, M = 0;
//	cout << "input: N, M" << endl;
//	while (cin >> N >> M)
//	{
//		//�����Թ� ��ά����
//		vector<vector<int>> maze(N,vector<int>(M,0));
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < M; ++j)
//			{
//				cin >> maze[i][j];
//			}
//		}
//
//		// ��ӡ�Թ�
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
//		//��ȡ�Թ���· ջ��¼·��
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
