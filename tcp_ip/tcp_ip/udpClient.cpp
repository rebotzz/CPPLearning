#pragma warning(disable: 4996)           //禁用C4996报错
#pragma comment(lib, "ws2_32.lib")  // 加载库
#include<winsock2.h>                 //socket库
#include <iostream>
#include <string>
#include <thread>
#include <cstdio>

using namespace std;
//服务器ip port
uint16_t port = 8080;
string ip = "118.25.20.143";    //118.25.20.143

void sendMsg(SOCKET clientSocket, sockaddr_in& dest)
{
	string sendMsg;
	cout << "请输入# ";

	while (true)
	{
		getline(cin, sendMsg);
		//似乎编码方式不对，服务器受到中文乱码，utf-8？
		int n = sendto(clientSocket, sendMsg.c_str(), (int)sendMsg.size(), 0, (sockaddr*)&dest, sizeof(dest));
		if (n < 0)
		{
			cerr << "sendto error" << endl;
		}
		cout << "发送完成" << endl;
	}
}

void receive(SOCKET clientSocket)
{
	sockaddr_in src;
	int slen = sizeof(src); 
	char buff[1024];
	while (true)
	{
		int s = recvfrom(clientSocket, buff, sizeof(buff), 0, (sockaddr*)&src, &slen);
		if (s > 0 && s < 1024)
		{
			buff[s] = '\0';
			cout << buff << endl;
		}
	}
}

int main()
{
	// windows独有
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA WSAData;
	if (WSAStartup(sockVersion, &WSAData) != 0)
	{
		return 1;
	}

	// 1.打开socket文件
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == clientSocket)
	{
		cerr << "socket error" << endl;
		return 2;
	}
	// 2.客户端不需要自己bind，自动
	sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);
	dest.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	// 3.发送和接受数据
	//thread tRead(receive, clientSocket);
	//thread tSend(sendMsg, clientSocket, dest);
	thread tRead([clientSocket]() {
		receive(clientSocket);
		});
	thread tSend([&dest, clientSocket]() {
		sendMsg(clientSocket, dest);
		});

	tRead.join();
	tSend.join();

	// windows独有
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}
