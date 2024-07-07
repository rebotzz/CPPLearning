#include <iostream>
#include "easyx.h"
//#include "graphics.h"

//using namespace std;
//int main()
//{
//	initgraph(1200, 800);
//	int x = 300, y = 300;
//	int circleSize = 20;
//	ExMessage msg;
//	bool running = true;
//	bool draw = false, erase = false;
//	BeginBatchDraw();	// 渲染缓冲区
//	while (running)
//	{
//
//		// 读取操作
//		while (peekmessage(&msg))
//		{
//			if (msg.message == WM_MOUSEMOVE)
//			{
//				x = msg.x;
//				y = msg.y;
//			}
//			if (msg.message == WM_LBUTTONDOWN)	// 鼠标点击左键绘制
//				draw = true;
//			else if (msg.message == WM_LBUTTONUP)
//				draw = false;
//			else if (msg.message == WM_RBUTTONDOWN)	// 右键清除
//				erase = true;
//			else if (msg.message == WM_KEYDOWN)
//			{
//				if(msg.vkcode == VK_ESCAPE)	// 按键退出程序
//					running = false;
//				else if (msg.vkcode == VK_UP && circleSize < 100)
//					circleSize += 5;
//				else if (msg.vkcode == VK_DOWN && circleSize > 5)
//					circleSize -= 5;
//			}
//		}
//
//		// 处理数据
//
//		// 绘制画面
//		if (draw)
//		{
//			solidcircle(x, y, circleSize);
//			FlushBatchDraw();
//		}
//
//
//		if (erase)
//		{
//			cleardevice();
//			FlushBatchDraw();
//			erase = false;
//		}
//		//Sleep(10);
//	}
//	EndBatchDraw();
//	closegraph();
//
//	return 0;
//}