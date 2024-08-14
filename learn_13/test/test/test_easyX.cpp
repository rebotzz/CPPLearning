#include <thread>
#include <vector>
#include <chrono>
#include <easyx.h>

using namespace std;

//int main()
//{
//	// 测试结果:easyX的绘图,一个进程只能有一个窗口,线程也不行
//	vector<thread> tv(1);
//	int length = 800;
//	bool stop = false;
//	srand(time(nullptr));
//	for (auto& t : tv) {
//		t = thread([&length, &stop] {
//			initgraph(length, length);
//			while (!stop) {
//				int tmp = length / 2;
//				int x = rand() % tmp + tmp;
//				int y = rand() % tmp + tmp;
//				circle(x, y, 100);
//				this_thread::sleep_for(chrono::seconds(1));
//			}
//			closegraph();
//			});
//	}
//
//
//	for (auto& t : tv) t.join();
//
//	return 0;
//}


//#pragma execution_character_set("utf-8")
#include <iostream>
#include <locale>

using namespace std;
//int main()
//{
//	//int length = 800;
//	//initgraph(length, length);
//
//	//int tmp = length / 2;
//	//int x = tmp;
//	//int y = tmp;
//
//	//outtextxy(x, y, L"你好");
//	wstring s(L"你哈");
//	//outtextxy(x, y, s.c_str());
//
//
//	// 设置控制台的本地化信息，这里以简体中文为例
//	std::wcout.imbue(std::locale("Chinese-simplified_China.936"));
//
//	string aa = "发送大附件";
//	cout << aa << endl;
//
//	cout << "Jj放假时间" << endl;
//	wcout << L"Jj放假时间" << endl;
//	
//	//wstring bb = aa;
//
//
//	system("pause");
//
//	return 0;
//}