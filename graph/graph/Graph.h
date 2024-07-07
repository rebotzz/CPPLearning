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
				_vertexs.push_back(arr[i]);
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
			assert(eg._dsti >= 0 && eg._dsti < _vertexs.size());
			assert(eg._srci >= 0 && eg._srci < _vertexs.size());

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



		// 广度优先遍历 队列	BFS
		void BroadPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("没有这个顶点");

			int n = _vertexs.size();
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
			int n = _vertexs.size();

			int levelsize = 1;	// 用于区分每层元素，队列同时最多存在两层元素;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _vertexs[front] << " ";

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

		// 深度优先遍历	递归	DFS
		void DeepPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("没有这个顶点");

			int n = _vertexs.size();
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
			cout << _vertexs[begin] << " ";
			int n = _vertexs.size();
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
			size_t n = _vertexs.size();
			mintree._vertexs = _vertexs;
			mintree._indexMap = _indexMap;
			mintree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				mintree._matrix[i].resize(n, MAX_W);
			}

			UnionFindSet<V> ufs(&_vertexs[0], _vertexs.size());			// 并查集，用于判断是否成环: 多个集合 -> 森林
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
				const V& src = _vertexs[eg._srci];
				const V& dst = _vertexs[eg._dsti];
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


		// 最小生成树 局部贪心 {x}已经选过的顶点集合 -> {v}未选过的顶点集合 : 避免成环,选取{x} -> {v} 权值最小的边
		// 利用小堆优化
		W prim(Self& mintree, const V& src)
		{
			// 初始化mintree
			size_t n = _vertexs.size();
			mintree._vertexs = _vertexs;
			mintree._indexMap = _indexMap;
			mintree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				mintree._matrix[i].resize(n, MAX_W);
			}

			vector<bool> visited(n, false);
			int srci = getVertexIndex(src);
			visited[srci] = true;
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// 建立小堆，选出权值最小的边
			// 将与srci相邻的边入堆
			for (size_t i = 0; i < n; ++i)	// 建堆的时间复杂度O(N)
			{
				if (_matrix[srci][i] != MAX_W)
					minq.push(Edge(srci, i, _matrix[srci][i]));
			}

			int size = n - 1;
			W totalW = W();
			// 就像一棵从起点生长的树，最终路过所有顶点
			while (!minq.empty())
			{
				// 选取{x} -> {v} 权值最小的边
				Edge eg = minq.top();
				minq.pop();
				if (visited[eg._dsti] == false)	// 为了效率使用小堆，代价：判环
				{
					mintree.addEdge(eg);
					visited[eg._dsti] = true;
					size--;
					totalW += eg._weight;

					// 将与dsti相邻的边入堆
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[eg._dsti][i] != MAX_W && visited[i] == false)
							minq.push(Edge(eg._dsti, i, _matrix[eg._dsti][i]));
					}

					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
				else
				{
					cout << "成环：";
					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}

				if (size == 0) return totalW;
			}

			return MAX_W;
		}

		// 选取{x} -> {v} 权值最小的边	暴力版本
		W primViolence(Self& mintree, const V& src)
		{
			// 初始化mintree
			size_t n = _vertexs.size();
			mintree._vertexs = _vertexs;
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

				cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				if (size == 0) return totalW;
			}

			return MAX_W;
		}

		// 单源最短路径	无负权  类似prim算法	时间复杂度O(n^2) 空间复杂度O(n)
		// 参数 源点：source 顶点到源点最小权值和数组：distanse 最短路径父顶点数组：parentPath
		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// 初始化
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();		// srci的权值给一个最小值,自己到自己
			pPath[srci] = srci;

			vector<bool> visited(n, false);
			visited[srci] = true;
			// 可以用小堆，也可以暴力遍历找到最小边
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// 建立小堆，选出权值最小的边
			// 将与srci相邻的边入堆
			for (size_t i = 0; i < n; ++i)	// 建堆的时间复杂度O(N)
			{
				if (_matrix[srci][i] != MAX_W)
					minq.push(Edge(srci, i, _matrix[srci][i]));
			}

			while (!minq.empty())
			{
				// 选取{x} -> {v} 权值最小的边
				Edge eg = minq.top();
				minq.pop();
				// 松弛算法：更新出更短连接路径
				if (visited[eg._dsti] == false
					&& dist[eg._srci] + _matrix[eg._srci][eg._dsti] < dist[eg._dsti])	// 判环 + 更新路径
				{
					visited[eg._dsti] = true;
					dist[eg._dsti] = dist[eg._srci] + _matrix[eg._srci][eg._dsti];
					pPath[eg._dsti] = eg._srci;

					// 将与dsti相邻的边入堆
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[eg._dsti][i] != MAX_W && visited[i] == false)
							minq.push(Edge(eg._dsti, i, _matrix[eg._dsti][i]));
					}

					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
				else
				{
					cout << "成环/不是相对更短的路径：";
					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
			}
		}

		// 不用小堆，直接遍历找最小边	2.0		时间复杂度O(n^2) 空间复杂度O(n)
		void Dijkstra2(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// 初始化
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();		// srci的权值给一个最小值,便于首次遍历
			vector<bool> visited(n, false);

			// 每次访问过一个点，最多n次访问完成
			for (size_t k = 0; k < n; ++k)
			{
				// 找到没有访问过的最小权值顶点，作为这次的起点
				W minW = MAX_W;
				int cur = -1;
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i] == false && dist[i] < minW)
					{
						cur = i;
						minW = dist[i];
					}
				}
				visited[cur] = true;

				// 找到与cur相邻的，没有访问过的，所有顶点:  判断，更新路径
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i] == false && _matrix[cur][i] != MAX_W
						&& dist[cur] + _matrix[cur][i] < dist[i])
					{
						dist[i] = dist[cur] + _matrix[cur][i];	// 更新最小权值
						pPath[i] = cur;							// 更新父顶点
					}
				}
			}
		}

		// 单源最短路径	可以有负权  时间复杂度O(n^3) 空间复杂度O(n)
		// 暴力求解，不像Dijkstra访问过的就不访问，这里同样访问更新
		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// 初始化
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();
			pPath[srci] = srci;

			// 如果某一次顶点K更新路径遇到了负权值，那么途径顶点K的权值都需要改变：再来一次 -> n-1个顶点，最多n-1次
			// 如果没有遇到中间顶点更新，那么就不用再来一次了
			for (size_t k = 0; k < n - 1; ++k)
			{
				bool midExchage = false;
				// 以i为起点的所有相邻顶点都更新
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						if (_matrix[i][j] != MAX_W
							&& dist[i] + _matrix[i][j] < dist[j])
						{
							dist[j] = dist[i] + _matrix[i][j];
							pPath[j] = i;
							midExchage = true;

							cout << _vertexs[i] << " -> " << _vertexs[j] << endl;
						}
					}
				}
				if (midExchage == false)
					break;
			}

			// 判断是否有负权回路：死循环，源点到顶点的权值与绕负权回路圈数有关，可以不断减小
			//  -> 所以再来一次还能更新
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] != MAX_W
						&& dist[i] + _matrix[i][j] < dist[j])
					{
						return false;
					}
				}
			}
			return true;
		}

		//  多源最短路径 Floyd-Warshall算法	 时间复杂度O(N^3) 空间复杂度O(N^2)
		void FloydWarshall(vector<vector<W>>& vvdist, vector<vector<int>>& vvpPath)
		{
			// 每一行vvdist[i]，vvpPath[i]都是以 i 为源点的最短路径数组
			// 初始化
			size_t n = _vertexs.size();
			vvdist.resize(n);
			vvpPath.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				vvdist[i].resize(n, MAX_W);
				vvpPath[i].resize(n, -1);
			}


			// 初始化权值和路径矩阵：直接相连的边
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvdist[i][j] = _matrix[i][j];	// 距离
						vvpPath[i][j] = i;				// j的上一个顶点
					}

					if (i == j)
					{
						vvdist[i][j] = W();
					}
				}
			}
			cout << "初始化：" << endl;
			printMatrix(vvdist, vvpPath);


			for (size_t k = 0; k < n; k++)
			{
				// k是i和j的中间节点，k可能会更新(从一个点变成多点)
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						// 如果i->j 存在中间节点k，i->k->j距离更短，更新
						// debug: 判断两点间存在路径的不是_matrix[i][k]，而是vvdist[i][k]，
						// 前者只有直接路径，而后者包含了间接路径
						if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W
							&& vvdist[i][k] + vvdist[k][j] < vvdist[i][j])
						{
							vvdist[i][j] = vvdist[i][k] + vvdist[k][j];
							// j的上一个顶点
							// 如果k和j直接相连，那么就是k
							// 如果k->j更新了，变为k->...->x->j,那么就是x
							vvpPath[i][j] = vvpPath[k][j];

							cout << "新增中间节点：" << _vertexs[i] << "->[" << _vertexs[k] << "]->" << _vertexs[j] << endl;
						}
					}
				}

				cout << "k: " << k << endl;
				printMatrix(vvdist, vvpPath);
			}
		}


		void printMatrix(vector<vector<W>>& vvdist, vector<vector<int>>& vvpPath)
		{
			size_t n = vvdist.size();
			// 打印矩阵
			cout << "vvdist:" << endl;
			printf("     ");
			for (size_t i = 0; i < n; i++)
			{
				printf("%-3d ", i);
			}
			cout << endl;
			printf("     ");
			for (size_t i = 0; i < n; i++)
			{
				printf("%-3c ", _vertexs[i]);
			}
			cout << endl;

			for (size_t i = 0; i < n; i++)
			{
				printf("%-2d %c ", i, _vertexs[i]);
				for (size_t j = 0; j < n; j++)
				{
					if (vvdist[i][j] != MAX_W)
						printf("%-3d ", vvdist[i][j]);
					else
						printf("%-3c ", '*');
				}
				cout << endl;
			}
			cout << endl;

			cout << "vvpPath:" << endl;
			printf("     ");
			for (size_t i = 0; i < n; i++)
			{
				printf("%-3d ", i);
			}
			cout << endl;
			printf("     ");
			for (size_t i = 0; i < n; i++)
			{
				printf("%-3c ", _vertexs[i]);
			}
			cout << endl;
			for (size_t i = 0; i < n; i++)
			{
				printf("%-2d %c ", i, _vertexs[i]);
				for (size_t j = 0; j < n; j++)
				{
					if (vvpPath[i][j] != -1)
						printf("%-3d ", vvpPath[i][j]);
					else
						printf("%-3c ", '*');
				}
				cout << endl;
			}
			cout << "----------------------------" << endl;
		}


		void printShortPath(const V& src, const vector<W>& dist, const vector<int>& pPath)
		{
			cout << endl << "最短路径：" << endl;

			int srci = getVertexIndex(src);
			size_t n = dist.size();
			for (size_t i = 0; i < n; ++i)
			{
				vector<int> path;
				int parent = i;
				while (parent != srci)
				{
					if (parent == -1) break;
					path.push_back(parent);
					parent = pPath[parent];
				}
				path.push_back(srci);
				reverse(path.begin(), path.end());

				for (auto index : path)
				{
					cout << _vertexs[index] << " -> ";
				}
				cout << " weight: " << dist[i] << endl;
			}

		}


	private:
		vector<V> _vertexs;				// 顶点	_vertexs
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
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(arr[i]);
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
					cout << "[" << _vertexs[cur->_srci] << " - " << _vertexs[cur->_dsti] << " " << cur->_weight << " "
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
		vector<V> _vertexs;
		map<V, int> _indexMap;								// 存储数值与下标映射关系
		vector<Edge*> _table;							// 领边表(链表)：表示与这个顶点相连接的边, 权值
		//vector<pair<Edge, Edge*>> _table;				
	};
}
