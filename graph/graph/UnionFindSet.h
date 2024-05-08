#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

// 并查集 | 图

template<class T>
class UnionFindSet
{
public:
	UnionFindSet(const T* arr, size_t n)
	{
		_v.resize(n, -1);
		for (size_t i = 0; i < n; ++i)
		{
			_map[arr[i]] = i;
		}
	}

	void unionSet(const T x, const T y)
	{
		auto it1 = _map.find(x);
		auto it2 = _map.find(y);
		if (it1 == _map.end() || it2 == _map.end())
		{
			throw string("union members not exist");
		}

		int root1 = findRoot(it1->second);
		int root2 = findRoot(it2->second);
		if (root1 == root2)
			return;

		// 优化：小的集合合并到大的集合
		if (abs(_v[root1]) < abs(_v[root2]))
			swap(root1, root2);

		_v[root1] += _v[root2];
		_v[root2] = root1;
	}

	size_t findRoot(size_t index)
	{
		size_t root = index;
		while (_v[root] >= 0)
		{
			root = _v[root];
		}

		// 路径优化
		size_t cur = index;
		while (_v[cur] >= 0)
		{
			size_t parent = _v[cur];
			_v[cur] = root;
			cur = parent;
		}

		return root;
	}

	size_t rootCount()
	{
		size_t size = 0;
		for (auto e : _v)
		{
			if (e < 0)
				size++;
		}
		return size;
	}

	void print()
	{
		for (auto e : _map)
		{
			cout << " " << e.first << " ";
		}
		cout << endl;

		for (auto e : _map)
		{
			printf("%2d ", e.second);
		}
		cout << endl;

		for (auto e : _map)
		{
			printf("%2d ", _v[e.second]);
		}
		cout << endl;
	}

private:
	vector<int> _v;		// 利用数组表示森林，根是负数(绝对值代表成员个数)，成员指向对应的根
	map<T, int> _map;	// 存储数值T和数组下标的映射关系
};





namespace matrix
{
	// G(V, E) 图 -> 顶点+边 vertex, edge, weight
	template<class V, class W, W MAX_W = INT_MAX, bool DIRECTION = false>
	class Graph
	{
		using Self = Graph<V, W, MAX_W, DIRECTION>;
	public:
		Graph() = default;

		Graph(const V* arr, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				_v.push_back(arr[i]);
				_map[arr[i]] = i;
			}

			// 初始化领边矩阵
			_mat.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				_mat[i].resize(n, MAX_W);
			}
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _map.find(src);
			auto it2 = _map.find(dst);
			if (it1 == _map.end() || it2 == _map.end())
				throw invalid_argument("图中没有存储这个顶点");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			_mat[srci][dsti] = weight;
			// 无向图
			if (DIRECTION == false)
			{
				_mat[dsti][srci] = weight;
			}
		}

		void print()
		{
			cout << "顶点：" << endl;
			for (const auto& kv : _map)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "领边矩阵: " << endl;
			size_t n = _mat.size();

			cout << "   ";
			for (int i = 0; i < n; ++i)
				printf("%-2d ", i);
			cout << endl;

			for (size_t i = 0; i < n; ++i)
			{
				printf("%-2d ", i);
				for (size_t j = 0; j < n; ++j)
				{
					if (_mat[i][j] == MAX_W)
						printf("%-2c ", '*');
					else
						printf("%-2d ", _mat[i][j]);
				}
				cout << endl;
			}
			cout << endl;
		}



		// 广度优先遍历 队列
		void BroadPriTraversal(const V& val)
		{
			auto it = _map.find(val);
			if (it == _map.end())
				throw invalid_argument("没有这个顶点");

			int n = _v.size();
			vector<bool> visited(n, false);	// 记录访问过的顶点
			_BroadPriTraversal(it->second, visited);

			// 孤岛的情况处理: 在没有访问的数组中找到再来一次
			for (size_t i = 0; i < n; ++i)
			{
				if (visited[i] == false)
				{
					_BroadPriTraversal(i, visited);
				}
			}
		}

		void _BroadPriTraversal(int begin, vector<bool>& visited)
		{
			queue<int> q;							// 辅助遍历
			q.push(begin);
			visited[begin] = true;
			int n = _v.size();

			int levelsize = 1;	// 用于区分每层元素，队列同时最多存在两层元素;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _v[front] << " ";

					// 遍历领边矩阵,找到领边
					for (size_t i = 0; i < n; ++i)
					{
						if (_mat[front][i] != MAX_W && visited[i] == false)
						{
							q.push(i);
							visited[i] = true;
						}
					}
				}
				cout << endl;
				levelsize = q.size();
			}
		}

		// 深度优先遍历	递归
		void DeepPriTraversal(const V& val)
		{
			auto it = _map.find(val);
			if (it == _map.end())
				throw invalid_argument("没有这个顶点");

			int n = _v.size();
			vector<bool> visited(n, false);	// 记录访问过的顶点
			int begin = it->second;
			visited[begin] = true;
			_DeepPriTraversal(begin, visited);

			// 孤岛的情况处理: 在没有访问的数组中找到再来一次
			for (size_t i = 0; i < n; ++i)
			{
				if (visited[i] == false)
				{
					visited[i] = true;
					_DeepPriTraversal(i, visited);
				}
			}
		}

		void _DeepPriTraversal(int begin, vector<bool>& visited)
		{
			cout << _v[begin] << " ";
			int n = _v.size();
			for (int i = 0; i < n; ++i)
			{
				if (_mat[begin][i] != MAX_W && visited[i] == false)
				{
					visited[i] = true;
					_DeepPriTraversal(i, visited);
				}
			}
			cout << endl;
		}

		// 最小生成树
		void bruskal(Self& mintree)
		{
			UnionFindSet<V> _ufs;		// 并查集，用于判断是否成环

		}


	private:
		vector<V> _v;				// 顶点
		map<V, int> _map;			// 存储数值与下标映射关系
		vector<vector<W>> _mat;		// 领边矩阵：利用矩阵表示两个顶点对应的边, 权值
	};
}

namespace table
{
	template<class W>
	struct Edge
	{
		int _srci;
		int _dsti;
		W _weight;
		Edge<W>* _next;

		Edge(int srci, int dsti, const W weight)
			:_srci(srci)
			, _dsti(dsti)
			, _weight(weight)
			, _next(nullptr)
		{}
	};

	template<class V, class W, W MAX_W = INT_MAX, bool DIRECTION = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph() = default;

		Graph(const V* arr, size_t n)
		{
			_v.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_v.push_back(arr[i]);
				_map[arr[i]] = i;
			}

			// 初始化领边表
			_table.resize(n, nullptr);
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _map.find(src);
			auto it2 = _map.find(dst);
			if (it1 == _map.end() || it2 == _map.end())
				throw invalid_argument("图中没有存储这个顶点");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			Edge* egPtr = new Edge(srci, dsti, weight);
			if (_table[srci] != nullptr)
				egPtr->_next = _table[srci];	// debug:不是_table[srci]->_next
			_table[srci] = egPtr;

			// 无向图
			if (DIRECTION == false)
			{
				swap(srci, dsti);
				Edge* egPtr = new Edge(srci, dsti, weight);
				if (_table[srci] != nullptr)
					egPtr->_next = _table[srci];
				_table[srci] = egPtr;
			}
		}

		void print()
		{
			cout << "顶点：" << endl;
			for (const auto& kv : _map)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "领边表: " << endl;
			size_t n = _table.size();
			for (size_t i = 0; i < n; ++i)
			{
				auto cur = _table[i];
				cout << i << " : ";
				while (cur != nullptr)
				{
					cout << "[" << _v[cur->_srci] << " - " << _v[cur->_dsti] << " " << cur->_weight << " "
						/*<< "(" << cur->_srci << "->" << cur->_dsti << ")"*/ << "] -->";
					cur = cur->_next;
				}
				if (cur == nullptr)
					cout << "nullptr";
				cout << endl;
			}
			cout << endl;
		}


	private:
		vector<V> _v;
		map<V, int> _map;								// 存储数值与下标映射关系
		vector<Edge*> _table;							// 领边表(链表)：表示与这个顶点相连接的边, 权值
		//vector<pair<Edge, Edge*>> _table;				
	};
}