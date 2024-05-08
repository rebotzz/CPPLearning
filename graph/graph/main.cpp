#include "UnionFindSet.h"

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
	string arr[] = { "����", "����", "����", "��", "˹����", "��", "��ϣ", "�˲�����"};

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


int main()
{
	try
	{
		//testUnionFindSet();
		testGraphMatrix();
		//testGraphTable();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (const string& str)
	{
		cout << str << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	return 0;
}