#define _CRT_SECURE_NO_WARNINGS
//#pragma execution_character_set("utf-8")	// �鷳,����
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include <xlnt/xlnt.hpp>
//#include "mytools.hpp"
using namespace std;

struct A {
	vector<double> a1, a2, a3;
	string b1;
};

//// ���Խ��: �����ݿ�����xlnt���ɵı����, �Ҳ�ҪͼƬ,ֻҪ�������; Ϊ�˱�������,ʹ��Ӣ��
//static void test()
//{
//	//setlocale(LC_ALL, "chs");//����wcout�������
//	xlnt::workbook wb;
//	wb.load("./indata/test.xlsx");
//	xlnt::worksheet ws = wb.active_sheet();
//
//	// ֻ��4��
//	for (const xlnt::cell_vector& cells : ws) {
//		for (auto& cell : cells) {
//			if (cell.has_value()) {
//				cout << cell.to_string() << " ";
//			}
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	system("pause");
//}




//int main()
//{
//	try
//	{
//		test();
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...) {
//		cout << "other exception" << endl;
//	}
//	return 0;
//}

#include <cstdlib>
#include <locale>
#include "mytools.hpp"
//int main()
//{
//	wstring a;
//	//fstream input("test.txt", std::ios::in | std::ios::binary);
//	FILE* fp = fopen("test.txt", "rb");
//	if (nullptr == fp) {
//		cout << "��ʧ��";
//		return 1;
//	}
//
//	//setlocale(LC_ALL, "chs");
//	//locale system("");
//	//locale::global(system);
//	//wcin.imbue(system);
//	//wcout.imbue(locale("zh_CN.UTF-8"));
//
//	// ����localeΪ����UTF-8
//	std::locale::global(std::locale("zh_CN.UTF-8"));
//	std::cout.imbue(locale());
//	std::wcout.imbue(locale());
//
//	char cbuff[128] = { 0 }; 
//	size_t cs = fread(cbuff, 1, sizeof(cbuff) - 1, fp);
//	cout << "read size: " << cs << endl;
//	cout << cbuff << endl;						// ��ȡ��ȷ,������utf8����
//	cout << "----------------" << endl;
//	wstring tmp = string2wstring(string(cbuff));// ����,������utf8����,���Բ���ת��
//	cout << "tmp size: " << tmp.size() << endl;
//	wcout << tmp << endl;
//
//	fclose(fp);
//
//	cout << "-----------------\nc++" << endl;
//
//	//wcout.imbue(locale("en_US.UTF-8"));
//	wfstream input("test.txt", std::ios::in | std::ios::binary);
//	//input >> tmp;
//	while (getline(input, tmp)) {	// ��ȡ��ȷ, wfstream��Ӧwstring
//		wcout << tmp << endl;
//	}
//	input.close();
//
//	return 0;
//}