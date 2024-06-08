#include <iostream>
#include "easyx.h"
//#include "graphics.h"

using namespace std;
int main()
{
	//printf("ver: %s\n", GetEasyXVer());
	//auto* s = GetEasyXVer();
	//printf("EasyX 当前版本：%s\n", s);
	//cout << (char*)(GetEasyXVer()) << endl;

	initgraph(1200, 800);
	int x = 300, y = 300;
	ExMessage msg;
	BeginBatchDraw();
	while (true)
	{
		// 消息处理
		while (peekmessage(&msg))
		{
			if (msg.message == WM_MOUSEMOVE)
			{
				x = msg.x;
				y = msg.y;
			}
		}

		// 数据处理

		// 图像处理
		solidcircle(x, y, 20);
		FlushBatchDraw();


		//Sleep(10);
		cleardevice();
	}
	EndBatchDraw();
	closegraph();

	return 0;
}