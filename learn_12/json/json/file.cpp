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
//    // 以写模式打开文件
//    ofstream outfile;
//    outfile.open("afile.dat");
//
//    cout << "Writing to the file" << endl;
//    cout << "Enter your name: ";
//    cin.getline(data, 100);
//
//    // 向文件写入用户输入的数据
//    outfile << data << endl;
//
//    cout << "Enter your age: ";
//    cin >> data;
//    cin.ignore();
//
//    // 再次向文件写入用户输入的数据
//    outfile << data << endl;
//
//    // 关闭打开的文件
//    outfile.close();
//
//    // 以读模式打开文件
//    ifstream infile;
//    infile.open("afile.dat");
//
//    cout << "Reading from the file" << endl;
//    infile >> data;
//
//    // 在屏幕上写入数据
//    cout << data << endl;
//
//    // 再次从文件读取数据，并显示它
//    infile >> data;
//    cout << data << endl;
//
//    // 关闭打开的文件
//    infile.close();
//
//    return 0;
//}


//int main()
//{
//	FILE* fp = fopen("wwwwwwwwww.txt", "w");
//	string buff = "叫我加法减法 劲儿啊啊放假啊；茧房ij；偶尔加法减法；阿吉啊飞机；";
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
//	// 设置控制台，就不乱码了
//	SetConsoleOutputCP(CP_UTF8);
//	setvbuf(stdout, nullptr, _IONBF, 0);
//
//	//ifstream file("test.html");
//	ifstream file("test.html", ios::binary);
//	if (!file) cout << "read error" << endl;
//
//	cout << u8"送 据洛杉矶发 Greek: αβγδ\n" << endl;
//
//	string tmp;
//	//file >> tmp;	// 遇到空格/换行失败
//	//char buff[10240] = { 0 };
//	//file.getline(buff, 10240);	// 行读取还是失败
//	//tmp += buff;
//
//	// 方法1
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
//	//string gg = "骄傲佛i骄傲 茧房；啊欸姐安静家具；二级if就发发发发";
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
//	// 测试结果：编码方式为 GB2312 不会乱码
//	// 改为 UTF-8编码 会出现乱码
//	// 当 UTF-8 转化为 GB2312 中文是会出现乱码，删掉乱码，
//	// 使用 GB2312编码输入中文，再次读取，不是乱码
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