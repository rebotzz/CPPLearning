#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void func()
{
	cout << "void func() -- thread id: " << this_thread::get_id() << endl;
}

class Print
{
public:
	static void p(int x)
	{
		cout << "static void p(int x) -- thread id: " << this_thread::get_id() << endl;
		cout << "x: " << x << endl;
	}
};

//int main()
//{
//	thread t1([](int x, int y)->int {
//		cout << "[](int x, int y)->int {} -- thread id: " << this_thread::get_id() << endl;
//		cout << x << "+" << y << "=" << x + y << endl;
//		return x + y;
//		}, 1, 2);
//
//	thread t2{func};
//	thread t3(Print::p, 1);
//
//
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}


#include <windows.h>	//Sleep
//int main()
//{
//	//int tNum = 3;
//	//vector<thread> vt(tNum);
//	//for (int i = 0; i < tNum; ++i)
//	//{
//	//	//vt.push_back(thread(func));
//	//	vt[i] = thread(func);
//	//}
//
//	//for (auto& e : vt)
//	//{
//	//	e.join();
//	//}
//
//	string _1 = "thread _1: ";
//	string _2 = "thread _2: ";
//	thread t1([&_1]() {
//		while (true)
//		{
//			cout << _1;
//			cout << this_thread::get_id() << endl;
//			Sleep(2000);	//ºÁÃë
//		}
//		});
//
//	thread t2([](string str) {
//		while (true)
//		{
//			cout << str;
//			cout << this_thread::get_id() << endl;
//			Sleep(2000);
//		}
//		}, _2);
//
//
//	t1.join();
//	t2.join();
//	return 0;
//}