#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

//int main()
//{
//
//    char data[100];
//
//    // ��дģʽ���ļ�
//    ofstream outfile;
//    outfile.open("afile.dat");
//
//    cout << "Writing to the file" << endl;
//    cout << "Enter your name: ";
//    cin.getline(data, 100);
//
//    // ���ļ�д���û����������
//    outfile << data << endl;
//
//    cout << "Enter your age: ";
//    cin >> data;
//    cin.ignore();
//
//    // �ٴ����ļ�д���û����������
//    outfile << data << endl;
//
//    // �رմ򿪵��ļ�
//    outfile.close();
//
//    // �Զ�ģʽ���ļ�
//    ifstream infile;
//    infile.open("afile.dat");
//
//    cout << "Reading from the file" << endl;
//    infile >> data;
//
//    // ����Ļ��д������
//    cout << data << endl;
//
//    // �ٴδ��ļ���ȡ���ݣ�����ʾ��
//    infile >> data;
//    cout << data << endl;
//
//    // �رմ򿪵��ļ�
//    infile.close();
//
//    return 0;
//}


//int main()
//{
//	FILE* fp = fopen("wwwwwwwwww.txt", "w");
//	string buff = "���Ҽӷ����� ���������żٰ����뷿ij��ż���ӷ��������������ɻ���";
//	buff += "ddddddddddasef eaef aa  fjao;ij a;jfaj ;aj ";
//	fwrite(buff.c_str(), 1, buff.size(), fp);
//	fclose(fp);
//
//
//	fstream out;
//	out.open("ddddd.txt", ios::out);
//	out << "-----------1-----------------------------" << endl;
//	out << "------------3----------------------------" << endl;
//	out << "-----------r-----------------------------" << endl;
//	out << "---------2-------------------------------" << endl;
//	out << "--------------f--------------------------" << endl;
//	out.close();
//
//	cout << "******************" << endl;
//	return 0;
//}

//#include <Windows.h>
//int main()
//{
//	// ���ÿ���̨���Ͳ�������
//	SetConsoleOutputCP(CP_UTF8);
//	setvbuf(stdout, nullptr, _IONBF, 0);
//
//	//ifstream file("test.html");
//	ifstream file("test.html", ios::binary);
//	if (!file) cout << "read error" << endl;
//
//	cout << u8"�� ����ɼ�� Greek: ���¦æ�\n" << endl;
//
//	string tmp;
//	//file >> tmp;	// �����ո�/����ʧ��
//	//char buff[10240] = { 0 };
//	//file.getline(buff, 10240);	// �ж�ȡ����ʧ��
//	//tmp += buff;
//
//	// ����1
//	stringstream buff;
//	buff << file.rdbuf();
//	tmp = buff.str();
//	printf(u8"%s\n", tmp.c_str());
//
//	//// 2.0
//	//file.seekg(0, ios::end);
//	//int len = file.tellg();
//	//file.seekg(0, ios::beg);
//
//	//char* buff = new char[len] {0};
//	//file.read(buff, len);
//	//tmp = buff;
//	//delete buff;
//
//	//cout << tmp << endl;
//
//
//
//	//string gg = "������i���� �뷿�����G�㰲���Ҿߣ�����if�ͷ�������";
//	//cout << gg << endl;
//	//ofstream out("out.txt");
//	//out << gg << endl;
//	//out.close();
//
//	cout << "write done---------------------------" << endl;
//
//	ifstream in("out.txt");
//	if (!in) cout << "read error" << endl;
//	char inbuf[1024] = { 0 };
//	in.getline(inbuf, 1024);
//	cout << inbuf << endl;
//	in.close();
//
//	// ���Խ�������뷽ʽΪ GB2312 ��������
//	// ��Ϊ UTF-8���� ���������
//	// �� UTF-8 ת��Ϊ GB2312 �����ǻ�������룬ɾ�����룬
//	// ʹ�� GB2312�����������ģ��ٴζ�ȡ����������
//
//	return 0;
//}


class A
{
public:
	operator bool()
	{
		if (_a == 0)
			return false;
		else
			return true;
	}

	int _a;
};

//int main()
//{
//	A aa;
//	aa._a = 1;
//	if (aa)
//	{
//		cout << "operator bool()" << endl;
//	}
//
//	aa._a = 0;
//	if (aa)
//	{
//		cout << "false" << endl;
//	}
//
//	// 89
//	cout << strlen(" ") << endl;
//	cout << strlen("\n") << endl;
//	cout << strlen("user=aaaaaaaaaa&password=22222222222222222&%E6%8F%90%E4%BA%A4%E9%94%AE=%E6%8F%90%E4%BA%A4") << endl;
//
//
//	//string ss = "123456789";
//	//cout << ss << endl;
//	//ss.erase(3, 1);
//	//cout << ss << endl;
//	//ss.erase(3, 15);
//	//cout << ss << endl;
//
//	return 0;
//}