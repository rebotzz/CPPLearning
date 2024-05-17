#include "UnionFindSet.h"
#include "Graph.h"
#include "BTree.h"
#include <string>
using namespace std;


void testUnionFindSet()
{
	//string s = "helodingsabc";
	//UnionFindSet<char> ufs(&s[0], s.size());
	////cout << (&s[0]) << endl;
	////printf("%p\n", &s[0]);
	////cout << (&s) << endl;
	//ufs.print();
	//cout << "---------------" << endl;

	//ufs.unionSet('h', 'e');
	//ufs.print();
	//cout << "---------------" << endl;
	//ufs.unionSet('l', 'o');
	//ufs.print();
	//cout << "---------------" << endl;
	//ufs.unionSet('b', 'c');
	//ufs.print();
	//cout << "---------------" << endl;
	//ufs.unionSet('d', 'i');
	//ufs.print();

	int arr[] = { 1,2,3,4,5,6,7 };
	UnionFindSet<int> ufs(arr, sizeof(arr) / sizeof(arr[0]));
	ufs.print();
	cout << "------1------" << endl;

	ufs.unionSet(1, 2);
	ufs.print();
	cout << "------------" << endl;

	ufs.unionSet(2, 3);
	ufs.print();
	cout << "------------" << endl;

	ufs.unionSet(3, 4);
	ufs.print();
	cout << "------------" << endl;

	ufs.unionSet(6, 6);
	ufs.print();
	cout << "------------" << endl;

	ufs.unionSet(7, 1);
	ufs.print();
	cout << "------------" << endl;

	cout << ufs.rootCount() << endl;
	ufs.unionSet(11, 1);


}

void testGraphMatrix()
{
	string arr[] = { "����", "����", "����", "��", "˹����", "��", "��ϣ", "�˲�����" };

	matrix::Graph<string, int> g(arr, sizeof(arr) / sizeof(arr[0]));

	g.print();

	g.addEdge("����", "����", 30);
	g.addEdge("����", "����", 30);
	g.addEdge("����", "��", 40);
	g.addEdge("��ϣ", "�˲�����", 40);
	g.addEdge("˹����", "��", 40);
	g.addEdge("��", "��", 40);

	//g.addEdge("����", "��ϣ", 400);

	g.print();


	//g.BroadPriTraversal("����");
	g.DeepPriTraversal("����");

}


void testGraphTable()
{
	string arr[] = { "����", "����", "����", "��", "˹����", "��", "��ϣ", "�˲�����" };

	//table::Graph<string, int> g(arr, sizeof(arr) / sizeof(arr[0]));
	table::Graph<string, int, INT_MAX, true> g(arr, sizeof(arr) / sizeof(arr[0]));

	g.print();

	g.addEdge("����", "����", 30);
	g.print();

	g.addEdge("����", "����", 30);
	g.print();

	g.addEdge("����", "��", 40);
	g.print();

	g.addEdge("��ϣ", "�˲�����", 40);
	g.addEdge("˹����", "��", 40);
	g.addEdge("��", "��", 40);

	g.print();
}

void testClass()
{
	class A
	{
	public:
		void print()
		{
			cout << "hello" << endl;
		}

		void printA()	// ����ʱ����
		{
			cout << _a << endl;
		}
		int _a;
	};

	// I think��thisָ����Ϊ�βδ��ݣ�������ѹջ���ݣ�����thisָ����ջ�ϣ�ʵ�ʴ��ݹ�������Ҫ�õ��Ĵ�����Ҳ�ڼĴ�����
	A* p = nullptr;
	p->print();
	//p->printA();
}

void testGraphMintree()
{
	const char* str = "abcdefghi";
	matrix::Graph<char, int> g(str, strlen(str));
	g.addEdge('a', 'b', 4);
	g.addEdge('a', 'h', 8);
	//g.addEdge('a', 'h', 9);
	g.addEdge('b', 'c', 8);
	g.addEdge('b', 'h', 11);

	g.addEdge('c', 'i', 2);
	g.addEdge('c', 'f', 4);
	g.addEdge('c', 'd', 7);
	g.addEdge('d', 'f', 14);
	g.addEdge('d', 'e', 9);
	g.addEdge('e', 'f', 10);
	g.addEdge('f', 'g', 2);
	g.addEdge('g', 'h', 1);
	g.addEdge('g', 'i', 6);
	g.addEdge('h', 'i', 7);

	g.print();

	//matrix::Graph<char, int> mintree(str, strlen(str));
	matrix::Graph<char, int> mintree;
	//g.bruskal(mintree);

	g.prim(mintree, 'a');
	mintree.print();

}


void testDijkstra()
{
	const char str[] = "syztx";
	matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.addEdge('s', 't', 10);
	g.addEdge('s', 'y', 5);
	g.addEdge('y', 't', 3);
	g.addEdge('y', 'x', 9);
	g.addEdge('y', 'z', 2);
	g.addEdge('z', 's', 7);
	g.addEdge('z', 'x', 6);
	g.addEdge('t', 'y', 2);
	g.addEdge('t', 'x', 1);
	g.addEdge('x', 'z', 4);

	vector<int> dist;
	vector<int> parentPath;
	//g.Dijkstra('s', dist, parentPath);
	g.Dijkstra2('s', dist, parentPath);
	g.printShortPath('s', dist, parentPath);

	cout << "------------" << endl;

	// ͼ�д��и�Ȩ·��ʱ��̰�Ĳ�����ʧЧ�ˡ�
	// ���Խ�����Կ���s->t->y֮������·��û���³���
	const char str2[] = "sytx";
	matrix::Graph<char, int, INT_MAX, true> g2(str2, strlen(str2));
	g2.addEdge('s', 't', 10);
	g2.addEdge('s', 'y', 5);
	g2.addEdge('t', 'y', -7);
	g2.addEdge('y', 'x', 3);
	vector<int> dist2;
	vector<int> parentPath2;
	g2.Dijkstra2('s', dist2, parentPath2);
	g2.printShortPath('s', dist2, parentPath2);

}

void testBellmanFord()
{
	const char str2[] = "sytx";
	matrix::Graph<char, int, INT_MAX, true> g2(str2, strlen(str2));
	g2.addEdge('s', 't', 10);
	g2.addEdge('s', 'y', 5);
	g2.addEdge('t', 'y', -7);
	g2.addEdge('y', 'x', 3);
	vector<int> dist2;
	vector<int> parentPath2;
	g2.BellmanFord('s', dist2, parentPath2);
	g2.printShortPath('s', dist2, parentPath2);
	cout << "------------" << endl;


	const char str[] = "syztx";
	matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.addEdge('s', 't', 6);
	g.addEdge('s', 'y', 7);
	g.addEdge('y', 'z', 9);
	g.addEdge('y', 'x', -3);
	g.addEdge('z', 's', 2);
	g.addEdge('z', 'x', 7);
	g.addEdge('t', 'x', 5);
	g.addEdge('t', 'y', 8);
	g.addEdge('t', 'z', -4);
	g.addEdge('x', 't', -2);
	vector<int> dist;
	vector<int> parentPath;
	if (g.BellmanFord('s', dist, parentPath))
		g.printShortPath('s', dist, parentPath);
	else
		cout << "��Ȩ��·" << endl;
	cout << "------------" << endl;


	// ΢��ͼ�ṹ�����и�Ȩ��·�Ĳ���
	const char str3[] = "syztx";
	matrix::Graph<char, int, INT_MAX, true> g3(str3, strlen(str3));
	g3.addEdge('s', 't', 6);
	g3.addEdge('s', 'y', 7);
	g3.addEdge('y', 'z', 9);
	g3.addEdge('y', 'x', -3);
	g3.addEdge('y', 's', 1); // ����
	g3.addEdge('z', 's', 2);
	g3.addEdge('z', 'x', 7);
	g3.addEdge('t', 'x', 5);
	g3.addEdge('t', 'y', -8); // ����
	g3.addEdge('t', 'z', -4);
	g3.addEdge('x', 't', -2);
	vector<int> dist3;
	vector<int> parentPath3;
	if (g3.BellmanFord('s', dist3, parentPath3))
	{
		g3.printShortPath('s', dist3, parentPath3);
	}
	else
	{
		cout << "���ڸ�Ȩ��·" << endl;
	}

}

void testFloydWarshall()
{
	//const char str[] = "syztx";
	//matrix::Graph<char, int, INT_MAX, true> g(str, strlen(str));
	//g.addEdge('s', 't', 6);
	//g.addEdge('s', 'y', 7);
	//g.addEdge('y', 'z', 9);
	//g.addEdge('y', 'x', -3);
	//g.addEdge('z', 's', 2);
	//g.addEdge('z', 'x', 7);
	//g.addEdge('t', 'x', 5);
	//g.addEdge('t', 'y', 8);
	//g.addEdge('t', 'z', -4);
	//g.addEdge('x', 't', -2);
	//vector<vector<int>> vvdist;
	//vector<vector<int>> vvparentPath;
	//g.FloydWarshall(vvdist, vvparentPath);
	//cout << "------------" << endl;


	const char str2[] = "sytx";
	matrix::Graph<char, int, INT_MAX, true> g2(str2, strlen(str2));
	g2.addEdge('s', 't', 10);
	g2.addEdge('s', 'y', 5);
	g2.addEdge('t', 'y', -7);
	g2.addEdge('y', 'x', 3);

	// ������	bug: y->t ·��û�и��³���
	g2.addEdge('t', 'x', 9);
	g2.addEdge('x', 's', 2);

	vector<vector<int>> dist2;
	vector<vector<int>> parentPath2;
	g2.FloydWarshall(dist2, parentPath2);
	// ��ӡ��������֮������·��
	for (size_t i = 0; i < strlen(str2); ++i)
	{
		cout << "Դ�㣺" << str2[i] << endl;
		g2.printShortPath(str2[i], dist2[i], parentPath2[i]);
		cout << "---------------" << endl << endl;
	}



	//const char str3[] = "12345";
	//matrix::Graph<char, int, INT_MAX, true> g3(str3, strlen(str3));
	//g3.addEdge('1', '2', 3);
	//g3.addEdge('1', '3', 8);
	//g3.addEdge('1', '5', -4);
	//g3.addEdge('2', '4', 1);
	//g3.addEdge('2', '5', 7);
	//g3.addEdge('3', '2', 4);
	//g3.addEdge('4', '1', 2);
	//g3.addEdge('4', '3', -5);
	//g3.addEdge('5', '4', 6);
	//vector<vector<int>> vvDist3;
	//vector<vector<int>> vvParentPath3;
	//g3.FloydWarshall(vvDist3, vvParentPath3);
	//// ��ӡ��������֮������·��
	//for (size_t i = 0; i < strlen(str3); ++i)
	//{
	//	cout << "Դ�㣺" << str3[i] << endl;
	//	g3.printShortPath(str3[i], vvDist3[i], vvParentPath3[i]);
	//	cout << "---------------" << endl << endl;
	//}

}


//int main()
//{
//	try
//	{
//		//testUnionFindSet();
//		//testGraphMatrix();
//		//testGraphTable();
//		//testClass();
//		//testGraphMintree();
//
//		//testDijkstra();
//		//testBellmanFord();
//		//testFloydWarshall();
//
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (const string& str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//
//	return 0;
//}



void testBTree()
{
	//BTree<int, int, 3> bt;
	//for (int i = 1; i < 10; ++i)
	//{
	//	bt.Insert(i, i);
	//}

	//bt.PrintLevel();

	int arr[] = { 53, 139,75,49,145,36,50,47,101 };
	BTree<int, int, 3> bt;
	for (auto e : arr)
	{
		bt.Insert(e, e);
	}
	bt.PrintLevel();
}

int main()
{
	testBTree();

}