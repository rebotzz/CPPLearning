#define _CRT_SECURE_NO_WARNINGS
//#pragma execution_character_set("utf-8")	// 麻烦,算了
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

//// 测试结果: 将数据拷贝到xlnt生成的表格下, 且不要图片,只要存粹数据; 为了避免乱码,使用英文
//static void test()
//{
//	//setlocale(LC_ALL, "chs");//设置wcout输出中文
//	xlnt::workbook wb;
//	wb.load("./indata/test.xlsx");
//	xlnt::worksheet ws = wb.active_sheet();
//
//	// 只读4行
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
//		cout << "打开失败";
//		return 1;
//	}
//
//	//setlocale(LC_ALL, "chs");
//	//locale system("");
//	//locale::global(system);
//	//wcin.imbue(system);
//	//wcout.imbue(locale("zh_CN.UTF-8"));
//
//	// 设置locale为中文UTF-8
//	std::locale::global(std::locale("zh_CN.UTF-8"));
//	std::cout.imbue(locale());
//	std::wcout.imbue(locale());
//
//	char cbuff[128] = { 0 }; 
//	size_t cs = fread(cbuff, 1, sizeof(cbuff) - 1, fp);
//	cout << "read size: " << cs << endl;
//	cout << cbuff << endl;						// 读取正确,本身是utf8编码
//	cout << "----------------" << endl;
//	wstring tmp = string2wstring(string(cbuff));// 错误,本身是utf8编码,所以不用转码
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
//	while (getline(input, tmp)) {	// 读取正确, wfstream对应wstring
//		wcout << tmp << endl;
//	}
//	input.close();
//
//	return 0;
//}