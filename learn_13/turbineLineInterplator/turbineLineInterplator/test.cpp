//#pragma execution_character_set("utf-8")	// 麻烦,算了
#include <iostream>
#include <vector>
#include <xlnt/xlnt.hpp>
//#include "mytools.hpp"
using namespace std;

struct A {
	vector<double> a1, a2, a3;
	string b1;
};

// 测试结果: 将数据拷贝到xlnt生成的表格下, 且不要图片,只要存粹数据; 为了避免乱码,使用英文
static void test()
{
	//setlocale(LC_ALL, "chs");//设置wcout输出中文
	xlnt::workbook wb;
	wb.load("./indata/test.xlsx");
	xlnt::worksheet ws = wb.active_sheet();

	// 只读4行
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