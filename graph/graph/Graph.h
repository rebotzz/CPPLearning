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
				_vertex.push_back(arr[i]);
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
			assert(eg._dsti >= 0 && eg._dsti < _vertex.size());
			assert(eg._srci >= 0 && eg._srci < _vertex.size());

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



		// ������ȱ��� ����
		void BroadPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("û���������");

			int n = _vertex.size();
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
			int n = _vertex.size();

			int levelsize = 1;	// ��������ÿ��Ԫ�أ�����ͬʱ����������Ԫ��;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _vertex[front] << " ";

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

		// ������ȱ���	�ݹ�
		void DeepPriTraversal(const V& val)
		{
			auto it = _indexMap.find(val);
			if (it == _indexMap.end())
				throw invalid_argument("û���������");

			int n = _vertex.size();
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

		// ��С������	ȫ��̰��
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

			UnionFindSet<V> ufs(&_vertex[0], _vertex.size());			// ���鼯�������ж��Ƿ�ɻ�: ������� -> ɭ��
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
				const V& src = _vertex[eg._srci];
				const V& dst = _vertex[eg._dsti];
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


		// ��С������	�ֲ�̰��	{x}�Ѿ�ѡ���Ķ��㼯�� -> {v}δѡ���Ķ��㼯�� : ����ɻ�
		//// ѡȡ{x} -> {v} Ȩֵ��С�ı�
		//W prim(Self& mintree, const V& src)
		//{
		//	// ��ʼ��mintree
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

		//	// ����С�ѣ�ѡ��Ȩֵ��С�ı�
		//	priority_queue<Edge, vector<Edge>, greater<Edge>> minq;		// ̰�ģ��ҵ��ֲ����Ž⣬Ȩֵ��С�ı�


		//	int size = n - 1;
		//	W totalW = W();
		//	while (!qe.empty())
		//	{
		//		int front = qe.front();
		//		visited[front] = true;
		//		qe.pop();
		//		// ��������ڵ���صı���С��
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
		//		// ����һ�ô������������������·�����ж���
		//		if (visited[eg._srci] == true && visited[eg._dsti] == false)	// Ϊ��Ч��ʹ��С�ѣ����ۣ��л�
		//		{
		//			mintree.addEdge(eg);
		//			visited[eg._dsti] = true;
		//			size--;
		//			totalW += eg._weight;

		//			cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
		//		}
		//		//else
		//		//{
		//		//	cout << "�ɻ���";
		//		//	cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
		//		//}

		//		if (size == 0) return totalW;
		//	}

		//	return MAX_W;
		//}

		// ѡȡ{x} -> {v} Ȩֵ��С�ı�	�����汾
		W prim(Self& mintree, const V& src)
		{
			// ��ʼ��mintree
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

				cout << _vertex[eg._srci] << "->" << _vertex[eg._dsti] << " : " << eg._weight << endl;
				if (size == 0) return totalW;
			}

			return MAX_W;
		}


	private:
		vector<V> _vertex;				// ����	_vertex
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
			_vertex.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertex.push_back(arr[i]);
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
		map<V, int> _indexMap;								// �洢��ֵ���±�ӳ���ϵ
		vector<Edge*> _table;							// ��߱�(����)����ʾ��������������ӵı�, Ȩֵ
		//vector<pair<Edge, Edge*>> _table;				
	};
}
