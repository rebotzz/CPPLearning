#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

// ���鼯 | ͼ

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

		// �Ż���С�ļ��Ϻϲ�����ļ���
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

		// ·���Ż�
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
	vector<int> _v;		// ���������ʾɭ�֣����Ǹ���(����ֵ�����Ա����)����Աָ���Ӧ�ĸ�
	map<T, int> _map;	// �洢��ֵT�������±��ӳ���ϵ
};





namespace matrix
{
	// G(V, E) ͼ -> ����+�� vertex, edge, weight
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

			// ��ʼ����߾���
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
				throw invalid_argument("ͼ��û�д洢�������");

			size_t srci = it1->second;
			size_t dsti = it2->second;
			_mat[srci][dsti] = weight;
			// ����ͼ
			if (DIRECTION == false)
			{
				_mat[dsti][srci] = weight;
			}
		}

		void print()
		{
			cout << "���㣺" << endl;
			for (const auto& kv : _map)
			{
				cout << kv.first << " [" << kv.second << "]" << endl;
			}
			cout << endl;

			cout << "��߾���: " << endl;
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



		// ������ȱ��� ����
		void BroadPriTraversal(const V& val)
		{
			auto it = _map.find(val);
			if (it == _map.end())
				throw invalid_argument("û���������");

			int n = _v.size();
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
			int n = _v.size();

			int levelsize = 1;	// ��������ÿ��Ԫ�أ�����ͬʱ����������Ԫ��;
			while (!q.empty())
			{
				while (levelsize--)
				{
					int front = q.front();
					q.pop();
					cout << _v[front] << " ";

					// ������߾���,�ҵ����
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

		// ������ȱ���	�ݹ�
		void DeepPriTraversal(const V& val)
		{
			auto it = _map.find(val);
			if (it == _map.end())
				throw invalid_argument("û���������");

			int n = _v.size();
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

		// ��С������
		void bruskal(Self& mintree)
		{
			UnionFindSet<V> _ufs;		// ���鼯�������ж��Ƿ�ɻ�

		}


	private:
		vector<V> _v;				// ����
		map<V, int> _map;			// �洢��ֵ���±�ӳ���ϵ
		vector<vector<W>> _mat;		// ��߾������þ����ʾ���������Ӧ�ı�, Ȩֵ
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

			// ��ʼ����߱�
			_table.resize(n, nullptr);
		}

		void addEdge(const V& src, const V& dst, const W& weight)
		{
			auto it1 = _map.find(src);
			auto it2 = _map.find(dst);
			if (it1 == _map.end() || it2 == _map.end())
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
			for (const auto& kv : _map)
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
		map<V, int> _map;								// �洢��ֵ���±�ӳ���ϵ
		vector<Edge*> _table;							// ��߱�(����)����ʾ��������������ӵı�, Ȩֵ
		//vector<pair<Edge, Edge*>> _table;				
	};
}