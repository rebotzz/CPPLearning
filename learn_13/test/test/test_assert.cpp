#include <iostream>
//#include <cassert>
#include <assert.h>
using namespace std;

void f(int x) {
	cout << x << endl;
}

//int main()
//{
//	//assert(false);
//	f(2);
//	(*f)(3);
//	return 0;
//}


//#include <xlnt/xlnt.hpp>
//#include <ctime>
//int main()
//{
//    xlnt::workbook wb;
//    xlnt::worksheet ws = wb.active_sheet();
//    ws.cell("A1").value(5);
//    ws.cell("B2").value("string data");
//    ws.cell("C3").formula("=RAND()");
//    ws.merge_cells("C3:C4");
//    ws.freeze_panes("B2");
//
//    srand(time(nullptr));
//    vector<int> arr1(20);
//    vector<double> arr2(24);
//    for (auto& e : arr1) e = rand() % 1000;
//    for (auto& e : arr2) e = rand() % 1000 + 0.001 * (rand() % 1000);
//
//    for (int i = 1; i < arr1.size(); ++i) {
//        ws.cell(i, 5).value(arr1[i]);   // 第i列,第5行
//    }
//
//    for (int i = 1; i < arr2.size(); ++i) {
//        ws.cell(i, 6).value(arr2[i]);   // 第i列,第5行
//
//    }
//
//    wb.save("test.xlsx");
//	return 0;
//}