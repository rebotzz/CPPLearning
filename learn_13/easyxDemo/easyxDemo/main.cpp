#include <iostream>
#include "easyx.h"
//#include "graphics.h"

using namespace std;
int main()
{
	//printf("ver: %s\n", GetEasyXVer());
	//auto* s = GetEasyXVer();
	//printf("EasyX ��ǰ�汾��%s\n", s);
	//cout << (char*)(GetEasyXVer()) << endl;

	initgraph(1200, 800);
	int x = 300, y = 300;
	ExMessage msg;
	BeginBatchDraw();
	while (true)
	{
		// ��Ϣ����
		while (peekmessage(&msg))
		{
			if (msg.message == WM_MOUSEMOVE)
			{
				x = msg.x;
				y = msg.y;
			}
		}

		// ���ݴ���

		// ͼ����
		solidcircle(x, y, 20);
		FlushBatchDraw();


		//Sleep(10);
		cleardevice();
	}
	EndBatchDraw();
	closegraph();

	return 0;
}