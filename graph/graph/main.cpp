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
	string arr[] = { "张三", "李四", "王五", "九", "斯科拉", "神", "哈希", "邓布利多"};

	matrix::Graph<string, int> g(arr, sizeof(arr) / sizeof(arr[0]));
	
	g.print();

	g.addEdge("张三", "李四", 30);
	g.addEdge("张三", "王五", 30);
	g.addEdge("张三", "九", 40);
	g.addEdge("哈希", "邓布利多", 40);
	g.addEdge("斯科拉", "九", 40);
	g.addEdge("神", "九", 40);

	//g.addEdge("李四", "哈希", 400);

	g.print();


	//g.BroadPriTraversal("张三");
	g.DeepPriTraversal("张三");

}


void testGraphTable()
{
	string arr[] = { "张三", "李四", "王五", "九", "斯科拉", "神", "哈希", "邓布利多" };

	//table::Graph<string, int> g(arr, sizeof(arr) / sizeof(arr[0]));
	table::Graph<string, int, INT_MAX, true> g(arr, sizeof(arr) / sizeof(arr[0]));

	g.print();

	g.addEdge("张三", "李四", 30);
	g.print();

	g.addEdge("张三", "王五", 30);
	g.print();

	g.addEdge("张三", "九", 40);
	g.print();

	g.addEdge("哈希", "邓布利多", 40);
	g.addEdge("斯科拉", "九", 40);
	g.addEdge("神", "九", 40);

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
		cout << "未知异常" << endl;
	}

	return 0;
}