#pragma once
#include <queue>
#include <functional>
#include <unordered_set>
#include "UnionFindSet.h"

// ͼ

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

	// G(V, E) ͼ -> ����+�� vertex, edge, weight
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

			// ��ʼ����߾���
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
				throw invalid_argument("ͼ��û�д洢�������");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			_matrix[srci][dsti] = weight;
			// ����ͼ
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
			// ����ͼ
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
			cout << "���㣺" << endl;
			for (const auto& kv : _indexMap)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "��߾���: " << endl;
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



		// ������ȱ��� ����	BFS
		void BroadPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("û���������");

			int n = _vertexs.size();
			vector<bool> visited(n, false);	// ��¼���ʹ��Ķ���
			_BroadPriTraversal(it->second, visited);

			// �µ����������: ��û�з��ʵ��������ҵ�����һ��
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
			queue<int> q;							// ��������
			q.push(begin);
			visited[begin] = true;
			int n = _vertexs.size();

			int levelsize = 1;	// ��������ÿ��Ԫ�أ�����ͬʱ����������Ԫ��;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _vertexs[front] << " ";

					// ������߾���,�ҵ����
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

		// ������ȱ���	�ݹ�	DFS
		void DeepPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("û���������");

			int n = _vertexs.size();
			vector<bool> visited(n, false);	// ��¼���ʹ��Ķ���
			int begin = it->second;
			visited[begin] = true;
			_DeepPriTraversal(begin, visited);

			// �µ����������: ��û�з��ʵ��������ҵ�����һ��
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

		// ��С������	ȫ��̰��
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

			UnionFindSet<V> ufs(&_vertexs[0], _vertexs.size());			// ���鼯�������ж��Ƿ�ɻ�: ������� -> ɭ��
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// ̰�ģ��ҵ��ֲ����Ž⣬Ȩֵ��С�ı�

			// ����С�ѣ�ѡ��Ȩֵ��С�ı�
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					// ����ͼ��ֻ�ô洢һ��������
					if (i < j && _matrix[i][j] != MAX_W)
						minq.push(Edge(i, j, _matrix[i][j]));
					// ����ͼ���洢��һ��
					if (DIRECTION == true && i > j && _matrix[i][j] != MAX_W)
						minq.push(Edge(i, j, _matrix[i][j]));
				}
			}

			W totalW = W();
			int size = n - 1;	// n�����㣬������Ҫn - 1 ����������
			while (!minq.empty())
			{
				Edge eg = minq.top();					// ȡȨֵ��С�ı�
				minq.pop();
				const V& src = _vertexs[eg._srci];
				const V& dst = _vertexs[eg._dsti];
				if (ufs.inSet(src, dst) == false)	// ���ɻ�
				{
					ufs.unionSet(src, dst);
					mintree.addEdge(eg);
					totalW += eg._weight;
					size--;

					cout << src << "->" << dst << " : " << eg._weight << endl;
				}
				else
				{
					cout << "�ɻ���";
					cout << src << "->" << dst << " : " << eg._weight << endl;
				}

				if (size == 0) return totalW;
			}
			return MAX_W;
		}


		// ��С������ �ֲ�̰�� {x}�Ѿ�ѡ���Ķ��㼯�� -> {v}δѡ���Ķ��㼯�� : ����ɻ�,ѡȡ{x} -> {v} Ȩֵ��С�ı�
		// ����С���Ż�
		W prim(Self& mintree, const V& src)
		{
			// ��ʼ��mintree
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
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// ����С�ѣ�ѡ��Ȩֵ��С�ı�
			// ����srci���ڵı����
			for (size_t i = 0; i < n; ++i)	// ���ѵ�ʱ�临�Ӷ�O(N)
			{
				if (_matrix[srci][i] != MAX_W)
					minq.push(Edge(srci, i, _matrix[srci][i]));
			}

			int size = n - 1;
			W totalW = W();
			// ����һ�ô������������������·�����ж���
			while (!minq.empty())
			{
				// ѡȡ{x} -> {v} Ȩֵ��С�ı�
				Edge eg = minq.top();
				minq.pop();
				if (visited[eg._dsti] == false)	// Ϊ��Ч��ʹ��С�ѣ����ۣ��л�
				{
					mintree.addEdge(eg);
					visited[eg._dsti] = true;
					size--;
					totalW += eg._weight;

					// ����dsti���ڵı����
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[eg._dsti][i] != MAX_W && visited[i] == false)
							minq.push(Edge(eg._dsti, i, _matrix[eg._dsti][i]));
					}

					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
				else
				{
					cout << "�ɻ���";
					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}

				if (size == 0) return totalW;
			}

			return MAX_W;
		}

		// ѡȡ{x} -> {v} Ȩֵ��С�ı�	�����汾
		W primViolence(Self& mintree, const V& src)
		{
			// ��ʼ��mintree
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
			// ����һ�ô������������������·�����ж���
			for (size_t k = 0; k < n; ++k)
			{
				Edge eg;
				eg._weight = MAX_W;
				//ѡȡ{ x } -> {v} Ȩֵ��С�ı�
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i] == true)				// {x}�Ѿ�ѡ���Ķ��㼯��
					{
						for (size_t j = 0; j < n; ++j)
						{
							if (visited[j] == false)	// {v}δѡ���Ķ��㼯��
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

		// ��Դ���·��	�޸�Ȩ  ����prim�㷨	ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(n)
		// ���� Դ�㣺source ���㵽Դ����СȨֵ�����飺distanse ���·�����������飺parentPath
		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// ��ʼ��
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();		// srci��Ȩֵ��һ����Сֵ,�Լ����Լ�
			pPath[srci] = srci;

			vector<bool> visited(n, false);
			visited[srci] = true;
			// ������С�ѣ�Ҳ���Ա��������ҵ���С��
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// ����С�ѣ�ѡ��Ȩֵ��С�ı�
			// ����srci���ڵı����
			for (size_t i = 0; i < n; ++i)	// ���ѵ�ʱ�临�Ӷ�O(N)
			{
				if (_matrix[srci][i] != MAX_W)
					minq.push(Edge(srci, i, _matrix[srci][i]));
			}

			while (!minq.empty())
			{
				// ѡȡ{x} -> {v} Ȩֵ��С�ı�
				Edge eg = minq.top();
				minq.pop();
				// �ɳ��㷨�����³���������·��
				if (visited[eg._dsti] == false
					&& dist[eg._srci] + _matrix[eg._srci][eg._dsti] < dist[eg._dsti])	// �л� + ����·��
				{
					visited[eg._dsti] = true;
					dist[eg._dsti] = dist[eg._srci] + _matrix[eg._srci][eg._dsti];
					pPath[eg._dsti] = eg._srci;

					// ����dsti���ڵı����
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[eg._dsti][i] != MAX_W && visited[i] == false)
							minq.push(Edge(eg._dsti, i, _matrix[eg._dsti][i]));
					}

					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
				else
				{
					cout << "�ɻ�/������Ը��̵�·����";
					cout << _vertexs[eg._srci] << "->" << _vertexs[eg._dsti] << " : " << eg._weight << endl;
				}
			}
		}

		// ����С�ѣ�ֱ�ӱ�������С��	2.0		ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(n)
		void Dijkstra2(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// ��ʼ��
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();		// srci��Ȩֵ��һ����Сֵ,�����״α���
			vector<bool> visited(n, false);

			// ÿ�η��ʹ�һ���㣬���n�η������
			for (size_t k = 0; k < n; ++k)
			{
				// �ҵ�û�з��ʹ�����СȨֵ���㣬��Ϊ��ε����
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

				// �ҵ���cur���ڵģ�û�з��ʹ��ģ����ж���:  �жϣ�����·��
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i] == false && _matrix[cur][i] != MAX_W
						&& dist[cur] + _matrix[cur][i] < dist[i])
					{
						dist[i] = dist[cur] + _matrix[cur][i];	// ������СȨֵ
						pPath[i] = cur;							// ���¸�����
					}
				}
			}
		}

		// ��Դ���·��	�����и�Ȩ  ʱ�临�Ӷ�O(n^3) �ռ临�Ӷ�O(n)
		// ������⣬����Dijkstra���ʹ��ľͲ����ʣ�����ͬ�����ʸ���
		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// ��ʼ��
			size_t n = _vertexs.size();
			size_t srci = getVertexIndex(src);
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);
			dist[srci] = W();
			pPath[srci] = srci;

			// ���ĳһ�ζ���K����·�������˸�Ȩֵ����ô;������K��Ȩֵ����Ҫ�ı䣺����һ�� -> n-1�����㣬���n-1��
			// ���û�������м䶥����£���ô�Ͳ�������һ����
			for (size_t k = 0; k < n - 1; ++k)
			{
				bool midExchage = false;
				// ��iΪ�����������ڶ��㶼����
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

			// �ж��Ƿ��и�Ȩ��·����ѭ����Դ�㵽�����Ȩֵ���Ƹ�Ȩ��·Ȧ���йأ����Բ��ϼ�С
			//  -> ��������һ�λ��ܸ���
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

		//  ��Դ���·�� Floyd-Warshall�㷨	 ʱ�临�Ӷ�O(N^3) �ռ临�Ӷ�O(N^2)
		void FloydWarshall(vector<vector<W>>& vvdist, vector<vector<int>>& vvpPath)
		{
			// ÿһ��vvdist[i]��vvpPath[i]������ i ΪԴ������·������
			// ��ʼ��
			size_t n = _vertexs.size();
			vvdist.resize(n);
			vvpPath.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				vvdist[i].resize(n, MAX_W);
				vvpPath[i].resize(n, -1);
			}


			// ��ʼ��Ȩֵ��·������ֱ�������ı�
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvdist[i][j] = _matrix[i][j];	// ����
						vvpPath[i][j] = i;				// j����һ������
					}

					if (i == j)
					{
						vvdist[i][j] = W();
					}
				}
			}
			cout << "��ʼ����" << endl;
			printMatrix(vvdist, vvpPath);


			for (size_t k = 0; k < n; k++)
			{
				// k��i��j���м�ڵ㣬k���ܻ����(��һ�����ɶ��)
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						// ���i->j �����м�ڵ�k��i->k->j������̣�����
						// debug: �ж���������·���Ĳ���_matrix[i][k]������vvdist[i][k]��
						// ǰ��ֻ��ֱ��·���������߰����˼��·��
						if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W
							&& vvdist[i][k] + vvdist[k][j] < vvdist[i][j])
						{
							vvdist[i][j] = vvdist[i][k] + vvdist[k][j];
							// j����һ������
							// ���k��jֱ����������ô����k
							// ���k->j�����ˣ���Ϊk->...->x->j,��ô����x
							vvpPath[i][j] = vvpPath[k][j];

							cout << "�����м�ڵ㣺" << _vertexs[i] << "->[" << _vertexs[k] << "]->" << _vertexs[j] << endl;
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
			// ��ӡ����
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
			cout << endl << "���·����" << endl;

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
		vector<V> _vertexs;				// ����	_vertexs
		map<V, int> _indexMap;			// �洢��ֵ���±�ӳ���ϵ	_indexmap
		vector<vector<W>> _matrix;		// ��߾������þ����ʾ���������Ӧ�ı�, Ȩֵ	_matrix
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

			// ��ʼ����߱�
			_table.resize(n, nullptr);
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _indexMap.find(src);
			auto it2 = _indexMap.find(dst);
			if (it1 == _indexMap.end() || it2 == _indexMap.end())
				throw invalid_argument("ͼ��û�д洢�������");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			Edge* egPtr = new Edge(srci, dsti, weight);
			if (_table[srci] != nullptr)
				egPtr->_next = _table[srci];	// debug:����_table[srci]->_next
			_table[srci] = egPtr;

			// ����ͼ
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
			cout << "���㣺" << endl;
			for (const auto& kv : _indexMap)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "��߱�: " << endl;
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
		map<V, int> _indexMap;								// �洢��ֵ���±�ӳ���ϵ
		vector<Edge*> _table;							// ��߱�(����)����ʾ��������������ӵı�, Ȩֵ
		//vector<pair<Edge, Edge*>> _table;				
	};
}
