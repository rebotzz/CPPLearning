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
//			Sleep(2000);	//毫秒
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

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <chrono>

//int main()
//{
//	//function<void(int x, int y)> f([](int x, int y) {cout << x << " " << y << endl; });
//
//	//auto f1 = [](int x, int y) {cout << x << " " << y << endl; };
//	//thread t1(f1, 2, 4);    // 线程构造函数，可变参数
//
//	//// 锁不能拷贝，需要引用，ref()
//	//mutex mtx;
//	//thread t2([](mutex& m) {
//	//    lock_guard<mutex> lock(m);
//	//    }, ref(mtx));
//
//
//	thread tid[3];
//	// 临界资源
//	int n = 0;
//	mutex mtx;
//	condition_variable cv;
//	bool start = false;
//	int count = 3;
//	int i = 1;
//	// 3线程消费
//	for (auto& t : tid)
//	{
//		string tmp = "thread ";
//		tmp += to_string(i++);
//		t = thread([&n, &mtx, &cv, &start](int cnt, string str) {
//
//			unique_lock<mutex> lock(mtx);
//			//lock_guard<mutex> lock(mtx);
//			while (!start)   // 条件
//			{
//				cv.wait(lock);
//			}
//			cout << str << endl;
//
//			for (size_t i = 0; i < cnt; i++)
//			{
//				cout << (++n) << endl;
//			}
//			this_thread::sleep_for(chrono::seconds(1));
//
//			}, count, tmp);
//	}
//
//	// main线程生产
//	cout << "start" << endl;
//	start = true;
//	//for (int i = 0; i < count*3; ++i)
//	{
//		cv.notify_all();	// 唤醒所有线程
//		this_thread::sleep_for(chrono::seconds(1));
//	}
//
//
//	// 回收资源
//	for (auto& t : tid)
//	{
//		t.join();
//	}
//
//	return 0;
//}


int main()
{
	thread t;
	t = thread([]() {cout << "test\n" << endl; });

	class A
	{
	public:
		static void af_static()
		{
			cout << "void af_static()" << endl;
		}

		void af()
		{
			cout << "void af()" << endl;
		}
	};

	thread t2(A::af_static);
	//function<void(void)> f1(A::af_static);
	function<void()> f1 = A::af_static;
	function<void(A)> f2 = &A::af;
	thread t3(f1);
	A aa;
	thread t4(f2, aa);


	t.join();
	t2.join();
	t3.join();
	t4.join();


	return 0;
}