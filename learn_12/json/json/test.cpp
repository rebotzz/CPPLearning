#include <iostream>
#include <fstream>
//#include "../jsoncpp/include/json/json.h"
//#include "../dist/json/json.h"
#include "json/json.h"

using namespace std;

//int main()
//{
//	//fstream file;
//	//file.open("json.txt", ios::out);
//
//	//Json::Value root;
//	//root["aa"] = 153;
//	//root["dd"] = 123.153;
//	//root["daa"] = '&';
//	//root["����"] = "hello world,����";
//	//Json::FastWriter writer;     // �Ѿ�����
//	////Json::StreamWriterBuilder writer;
//
//	////writer.write(root);
//	//string s = writer.write(root);
//	//file << s;
//
//	//file.close();
//
//	fstream infile("json.txt", ios::in);
//	char tmp[200];
//	infile.getline(tmp, 200 - 1);
//	//infile >> tmp;
//	cout << tmp << endl;
//	Json::Value root;
//	Json::Reader reader;
//	reader.parse(tmp, root);
//	cout << root["aa"].asInt() << endl;
//	cout << root["dd"].asFloat() << endl;
//	cout << (char)(root["daa"].asInt()) << endl;
//	cout << root["����"].asString() << endl;
//
//
//	//fstream out("ddddd.txt", ios::out);
//	//out << "-----------1-----------------------------" << endl;
//	//out << "------------3----------------------------" << endl;
//	//out << "-----------r-----------------------------" << endl;
//	//out << "---------2-------------------------------" << endl;
//	//out << "--------------f--------------------------" << endl;
//	//out.close();
//
//	return 0;
//}