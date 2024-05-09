#pragma once
#include <queue>
#include <functional>
#include <unordered_set>
#include "UnionFindSet.h"

// 图

namespace matrix
{
	template<class W>
	struct Edge
	{
		int _srci;
		int _dsti;
		W _weight;

		Edge() = default;
		Edge(int srci, int dsti, const W& weight)
			:_srci(srci)
			, _dsti(dsti)
			, _weight(weight)
		{}

		bool operator>(const Edge& eg) const
		{
			return _weight > eg._weight;
		}
	};

	// G(V, E) 图 -> 顶点+边 vertex, edge, weight
	template<class V, class W, W MAX_W = INT_MAX, bool DIRECTION = false>
	class Graph
	{
		using Self = Graph<V, W, MAX_W, DIRECTION>;
		using Edge = Edge<W>;
	public:
		Graph() = default;

		Graph(const V* arr, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				_vertex.push_back(arr[i]);
				_indexMap[arr[i]] = i;
			}

			// 初始化领边矩阵
			_matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				_matrix[i].resize(n, MAX_W);
			}
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _indexMap.find(src);
			auto it2 = _indexMap.find(dst);
			if (it1 == _indexMap.end() || it2 == _indexMap.end())
				throw invalid_argument("图中没有存储这个顶点");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			_matrix[srci][dsti] = weight;
			// 无向图
			if (DIRECTION == false)
			{
				_matrix[dsti][srci] = weight;
			}
		}

		void addEdge(const Edge& eg)
		{
			assert(eg._dsti >= 0 && eg._dsti < _vertex.size());
			assert(eg._srci >= 0 && eg._srci < _vertex.size());

			_matrix[eg._srci][eg._dsti] = eg._weight;
			// 无向图
			if (DIRECTION == false)
			{
				_matrix[eg._dsti][eg._srci] = eg._weight;
			}
		}

		int getVertexIndex(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				return -1;
			return it->second;
		}

		void print()
		{
			cout << "顶点：" << endl;
			for (const auto& kv : _indexMap)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "领边矩阵: " << endl;
			size_t n = _matrix.size();

			cout << "   ";
			for (int i = 0; i < n; ++i)
				printf("%-2d ", i);
			cout << endl;

			for (size_t i = 0; i < n; ++i)
			{
				printf("%-2d ", i);
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] == MAX_W)
						printf("%-2c ", '*');
					else
						printf("%-2d ", _matrix[i][j]);
				}
				cout << endl;
			}
			cout << endl;
		}



		// 广度优先遍历 队列
		void BroadPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("没有这个顶点");

			int n = _vertex.size();
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
			int n = _vertex.size();

			int levelsize = 1;	// 用于区分每层元素，队列同时最多存在两层元素;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _vertex[front] << " ";

					// 遍历领边矩阵,找到领边
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[front][i] != MAX_W && visited[i] == false)
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
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("没有这个顶点");

			int n = _vertex.size();
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
			cout << _vertex[begin] << " ";
			int n = _vertex.size();
			for (int i = 0; i < n; ++i)
			{
				if (_matrix[begin][i] != MAX_W && visited[i] == false)
				{
					visited[i] = true;
					_DeepPriTraversal(i, visited);
				}
			}
			cout << endl;
		}

		// 最小生成树	全局贪心
		W bruskal(Self& mintree)
		{
			size_t n = _vertex.size();
			mintree._vertex = _vertex;
			mintree._indexMap = _indexMap;
			mintree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				mintree._matrix[i].resize(n, MAX_W);
			}

			UnionFindSet<V> ufs(&_vertex[0], _vertex.size());			// 并查集，用于判断是否成环: 多个集合 -> 森林
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// 贪心：找到局部最优解，权值最小的边

			// 建立小堆，选出权值最小的边
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					// 无向图，只用存储一半矩阵就行
					if (i < j && _matrix[i][j] != MAX_W)
						minq.push(Edge(i, j, _matrix[i][j]));
					// 有向图，存储另一半
					if (DIRECTION == true && i > j && _matrix[i][j] != MAX_W)
						minq.push(Edge(i, j, _matrix[i][j]));
				}
			}

			W totalW = W();
			int size = n - 1;	// n个顶点，最少需要n - 1 条边相连接
			while (!minq.empty())
			{
				Edge eg = minq.top();					// 取权值最小的边
				minq.pop();
				const V& src = _vertex[eg._srci];
				const V& dst = _vertex[eg._dsti];
				if (ufs.inSet(src, dst) == false)	// 不成环
				{
					ufs.unionSet(src, dst);
					mintree.addEdge(eg);
					totalW += eg._weight;
					size--;

					cout << src << "->" << dst << " : " << eg._weight << endl;
				}
				else
				{
					cout << "成环：";
					cout << src << "->" << dst << " : " << eg._weight << endl;
				}

				if (size == 0) return totalW;
			}
			return MAX_W;
		}


		// 最小生成树	局部贪心	{x}已经选过的顶点集合 -> {v}未选过的顶点集合 : 避免成环
		//// 选取{x} -> {v} 权值最小的边
		//W prim(Self& mintree, const V& src)
		//{
		//	// 初始化mintree
		//	size_t n = _vertex.size();
		//	mintree._vertex = _vertex;
		//	mintree._indexMap = _indexMap;
		//	mintree._matrix.resize(n);
		//	for (size_t i = 0; i < n; ++i)
		//	{
		//		mintree._matrix[i].resize(n, MAX_W);
		//	}

		//	vector<bool> visited(n, false);
		//	int srci = getVertexIndex(src);
		//	queue<int> qe;
		//	qe.push(srci);

		//	// 建立小堆，选出权值最小的边
		//	priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// 贪心：找到局部最优解，权值最小的边


		//	int size = n - 1;
		//	W totalW = W();
		//	while (!qe.empty())
		//	{
		//		int front = qe.front();
		//		visited[front] = true;
		//		qe.pop();
		//		// 把与这个节点相关的边入小堆
		//		for (size_t i = 0; i < n; ++i)
		//		{
		//			if (_matrix[front][i] != MAX_W)
		//			{
		//				minq.push(Edge(front, i, _matrix[front][i]));
		//				if(visited[i] == false) 
		//					qe.push(i);
		//			}
		//		}

		//		Edge eg = minq.top();
		//		minq.pop();
		//		// 就像一棵从起点生长的树，最终路过所有顶点
		//		if (visited[eg._srci] == true && visited[eg._dsti] == false)	// 为了效率使用小堆，代价：判环
		//		{
		//			mintree.addEdge(eg);
		//			visited[eg._dsti] = true;
		//			size--;
		//			totalW += eg._weight;

		//			cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
		//		}
		//		//else
		//		//{
		//		//	cout << "成环：";
		//		//	cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
		//		//}

		//		if (size == 0) return totalW;
		//	}

		//	return MAX_W;
		//}

		// 选取{x} -> {v} 权值最小的边	暴力版本
		W prim(Self& mintree, const V& src)
		{
			// 初始化mintree
			size_t n = _vertex.size();
			mintree._vertex = _vertex;
			mintree._indexMap = _indexMap;
			mintree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				mintree._matrix[i].resize(n, MAX_W);
			}

			vector<bool> visited(n, false);
			int srci = getVertexIndex(src);
			visited[srci] = true;

			int size = n - 1;
			W totalW = W();
			// 就像一棵从起点生长的树，最终路过所有顶点
			for (size_t k = 0; k < n; ++k)
			{
				Edge eg;
				eg._weight = MAX_W;
				//选取{ x } -> {v} 权值最小的边
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i] == true)				// {x}已经选过的顶点集合
					{
						for (size_t j = 0; j < n; ++j)
						{
							if (visited[j] == false)	// {v}未选过的顶点集合
							{
								if (_matrix[i][j] < eg._weight)
									eg = Edge(i, j, _matrix[i][j]);
							}
						}
					}
				}

				mintree.addEdge(eg);
				visited[eg._dsti] = true;
				size--;
				totalW += eg._weight;

				cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
				if (size == 0) return totalW;
			}

			return MAX_W;
		}


	private:
		vector<V> _vertex;				// 顶点	_vertex
		map<V, int> _indexMap;			// 存储数值与下标映射关系	_indexmap
		vector<vector<W>> _matrix;		// 领边矩阵：利用矩阵表示两个顶点对应的边, 权值	_matrix
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
			_vertex.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertex.push_back(arr[i]);
				_indexMap[arr[i]] = i;
			}

			// 初始化领边表
			_table.resize(n, nullptr);
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _indexMap.find(src);
			auto it2 = _indexMap.find(dst);
			if (it1 == _indexMap.end() || it2 == _indexMap.end())
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
			for (const auto& kv : _indexMap)
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
					cout << "[" << _vertex[cur->_srci] << " - " << _vertex[cur->_dsti] << " " << cur->_weight << " "
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
		vector<V> _vertex;
		map<V, int> _indexMap;								// 存储数值与下标映射关系
		vector<Edge*> _table;							// 领边表(链表)：表示与这个顶点相连接的边, 权值
		//vector<pair<Edge, Edge*>> _table;				
	};
}
