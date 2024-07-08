#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>	
using namespace std;

// �Թ����� -- ����·��: �������п���·��,�и���·���͸���·��
// С������һ�첻С��������һ�������Թ�, С����ϣ�����Լ���ʣ������ֵP������������Թ���
// Ϊ���������, ��������һ��n* m�ĸ����Թ�, �Թ�ÿ��λ��Ϊ0����1, 0�������λ�����ϰ���, 
// С���ܴﵽ�������λ��; 1����С���ܿ��Դﵽ��λ�á�С���ܳ�ʼ��(0, 0)λ��, 
// �����Թ��ĳ�����(0, m - 1)(��֤������λ�ö���1, ���ұ�֤һ������㵽�յ�ɴ��·��), 
// С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ, ������һ����λ������Ҫ����3����λ������ֵ, 
// �����ƶ�����������ֵ, ��С���ܵ�����ֵ����0��ʱ��û�е������, С���ܽ��޷������Թ���
// ������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0, m - 1)λ��)��
//

// ��ӡ·��
void printPath(stack<pair<int, int>> path)
{
	cout << "path:" << endl;
	stack<pair<int, int> > rpath;
	// ����ջ
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

// ��ӡ�Թ�
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

// �ж��Ƿ���·,�Ƿ�����
bool IsPath(vector<vector<int>>& maze, pair<int, int> cur)
{
	int x = cur.first;
	int y = cur.second;
	// ����Ϊ�����߽���߱���
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

// ��ȡ�Թ���·
void GetPath(vector<vector<int>>& maze, pair<int, int> cur, pair<int, int> out, stack<pair<int, int>>& path, stack<pair<int, int>>& minpath, int P)
{
	int x = cur.first;
	int y = cur.second;

	// �ҵ�����
	if (x == out.first && y == out.second)
	{
		// ��������,���ҵ����̵�·��,����·��
		if ((P >= 0) && (path.size() < minpath.size() || minpath.size() == 0))
		{
			minpath = path;
		}
		// �ָ��߹��ı�ǽڵ�,ɾ������¼�Ľڵ�
		maze[x][y] = 1;
		path.pop();
		return;
	}

	// ��һ������
	if (path.empty() && IsPath(maze, make_pair(x,y)))
	{
		maze[x][y] = 2;
		path.push(make_pair(x, y));
	}

	// �ݹ�,����·��,���ƶ���������,���غ��߹���·���Ͳ���������
	// ��
	if (IsPath(maze, make_pair(x - 1, y)))
	{
		// ����߹���·��
		maze[x - 1][y] = 2;
		path.push(make_pair(x - 1, y));
		GetPath(maze, make_pair(x - 1, y), out, path, minpath, P - 3);
		//maze[x - 1][y] = 1;	//debug: �����ָ��߹�·�������ƺ���Խ��,ԭ��δ֪
	}
	// ��
	if (IsPath(maze, make_pair(x + 1, y)))
	{
		maze[x + 1][y] = 2;
		path.push(make_pair(x + 1, y));
		GetPath(maze, make_pair(x + 1, y), out, path, minpath, P);
	}
	// ��
	if (IsPath(maze, make_pair(x, y - 1)))
	{
		maze[x][y - 1] = 2;
		path.push(make_pair(x, y - 1));
		GetPath(maze, make_pair(x, y - 1), out, path, minpath, P - 1);
	}
	// ��
	if (IsPath(maze, make_pair(x, y + 1)))
	{
		maze[x][y + 1] = 2;
		path.push(make_pair(x, y + 1));
		GetPath(maze, make_pair(x, y + 1), out, path, minpath, P - 1);
	}

	// �������Ҷ�û�г�·
	// �ָ��߹��ı�ǽڵ�,ɾ������¼�Ľڵ�
	maze[x][y] = 1;
	if (!path.empty())
		path.pop();
}

int main()
{
	//�����Թ���С N*M, ����ֵP
	int N = 0, M = 0, P = 0;
	cout << "input: N, M" << endl;
	while (cin >> N >> M >> P)
	{
		//�����Թ� ��ά����
		vector<vector<int>> maze(N, vector<int>(M, 0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> maze[i][j];
			}
		}

		// ��ӡ�Թ�
		printMaze(maze);

		//��ȡ�Թ���· ջ��¼·��
		stack<pair<int, int>> path;
		stack<pair<int, int>> minpath;
		pair<int, int> enter = make_pair(0, 0);
		pair<int, int> out = make_pair(0, M - 1);
		GetPath(maze, enter, out, path, minpath, P);

		//��ӡ·��
		if(!minpath.empty())
		{
			printPath(minpath);
		}
		else
		{
			cout << "Can not escape!" << endl;
		}

		//cout << "----����----" << endl;
	}
	return 0;
}
