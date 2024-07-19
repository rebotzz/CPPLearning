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
//
//int main()
//{
//    xlnt::workbook wb;
//    xlnt::worksheet ws = wb.active_sheet();
//    ws.cell("A1").value(5);
//    ws.cell("B2").value("string data");
//    ws.cell("C3").formula("=RAND()");
//    ws.merge_cells("C3:C4");
//    ws.freeze_panes("B2");
//    wb.save("example.xlsx");
//	return 0;
//}