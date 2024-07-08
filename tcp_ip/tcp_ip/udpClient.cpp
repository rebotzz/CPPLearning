#pragma warning(disable: 4996)           //����C4996����
#pragma comment(lib, "ws2_32.lib")  // ���ؿ�
#include<winsock2.h>                 //socket��
#include <iostream>
#include <string>
#include <thread>
#include <cstdio>

using namespace std;
//������ip port
uint16_t port = 8080;
string ip = "118.25.20.143";    //118.25.20.143

void sendMsg(SOCKET clientSocket, sockaddr_in& dest)
{
	string sendMsg;
	cout << "������# ";

	while (true)
	{
		getline(cin, sendMsg);
		//�ƺ����뷽ʽ���ԣ��������ܵ��������룬utf-8��
		int n = sendto(clientSocket, sendMsg.c_str(), (int)sendMsg.size(), 0, (sockaddr*)&dest, sizeof(dest));
		if (n < 0)
		{
			cerr << "sendto error" << endl;
		}
		cout << "�������" << endl;
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
	// windows����
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA WSAData;
	if (WSAStartup(sockVersion, &WSAData) != 0)
	{
		return 1;
	}

	// 1.��socket�ļ�
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == clientSocket)
	{
		cerr << "socket error" << endl;
		return 2;
	}
	// 2.�ͻ��˲���Ҫ�Լ�bind���Զ�
	sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);
	dest.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	// 3.���ͺͽ�������
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

	// windows����
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}
