#include <thread>
#include <vector>
#include <chrono>
#include <easyx.h>

using namespace std;

//int main()
//{
//	// ���Խ��:easyX�Ļ�ͼ,һ������ֻ����һ������,�߳�Ҳ����
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
//	//outtextxy(x, y, L"���");
//	wstring s(L"���");
//	//outtextxy(x, y, s.c_str());
//
//
//	// ���ÿ���̨�ı��ػ���Ϣ�������Լ�������Ϊ��
//	std::wcout.imbue(std::locale("Chinese-simplified_China.936"));
//
//	string aa = "���ʹ󸽼�";
//	cout << aa << endl;
//
//	cout << "Jj�ż�ʱ��" << endl;
//	wcout << L"Jj�ż�ʱ��" << endl;
//	
//	//wstring bb = aa;
//
//
//	system("pause");
//
//	return 0;
//}