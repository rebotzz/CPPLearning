//#pragma execution_character_set("utf-8")	// �鷳,����
#include <iostream>
#include <vector>
#include <xlnt/xlnt.hpp>
//#include "mytools.hpp"
using namespace std;

struct A {
	vector<double> a1, a2, a3;
	string b1;
};

// ���Խ��: �����ݿ�����xlnt���ɵı����, �Ҳ�ҪͼƬ,ֻҪ�������; Ϊ�˱�������,ʹ��Ӣ��
static void test()
{
	//setlocale(LC_ALL, "chs");//����wcout�������
	xlnt::workbook wb;
	wb.load("./indata/test.xlsx");
	xlnt::worksheet ws = wb.active_sheet();

	// ֻ��4��
	for (const xlnt::cell_vector& cells : ws) {
		for (auto& cell : cells) {
			if (cell.has_value()) {
				cout << cell.to_string() << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}




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