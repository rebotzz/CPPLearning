#include "extrapolation.hpp"

//void test1()
//{
//	MultiTurbineCharLine mtl(8000);
//	mtl.readData("./indata/data.txt");
//	mtl.getSurgeLine();
//
//	cout << endl << endl;
//	cout << "转速: ";
//	for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
//	cout << "喘震流量: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
//	cout << "喘震压比: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
//	cout << "喘震效率: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;
//
//	TCHAR s[32] = { 0 };
//	vector<double> arrx(mtl.getTClines().size()), arry(mtl.getTClines().size()), arry_e(mtl.getTClines().size());
//	for (int i = 0; i < mtl.getTClines().size(); ++i) {
//		arrx[i] = mtl.getTClines()[i]._surge_flow;
//		arry[i] = mtl.getTClines()[i]._surge_pressure_ratio;
//		arry_e[i] = mtl.getTClines()[i]._surge_efficiencies;
//	}
//	_stprintf_s(s, _T("原始: 喘震流量-喘震压比"));
//	mtl.drawGraphLine(arrx, arry, s);
//	_stprintf_s(s, _T("原始: 喘震流量-喘震效率"));
//	mtl.drawGraphLine(arrx, arry_e, s);
//
//	int size = 30;
//	arrx.resize(size), arry.resize(size), arry_e.resize(size);
//	for (int i = 0; i < size; ++i) {
//		double speed = 4000 + 100 * i;
//		arrx[i] = speed / mtl._speed_design;
//		arry[i] = mtl._surge_speedRatio_flow_ptr->operator()(arrx[i]);
//		//arry_e[i] = mtl._surge_speedRatio_flow_ptr->operator()(arrx[i]);
//	}
//	_stprintf_s(s, _T("测试外推: 速比-喘震流量"));
//	mtl.drawGraphLine(arrx, arry, s);
//
//
//
//	// 只外推4800转速
//	arrx.resize(0), arry.resize(0);
//	arrx.push_back(4800 / mtl._speed_design);
//	arry.push_back(mtl._surge_speedRatio_flow_ptr->operator()(arrx.back()));
//	mtl.extrapolation(4800);
//
//	cout << endl << endl;
//	cout << "速度: ";
//	for (auto& e : arrx) cout << e * mtl._speed_design << " "; cout << endl;
//	cout << "速比: ";
//	for (auto& e : arrx) cout << e << " "; cout << endl;
//	cout << "喘震流量: ";
//	for (auto& e : arry) cout << e << " "; cout << endl;
//
//	cout << "喘震压比: ";
//	for (auto& e : mtl.getTClinesNew()) cout << e._surge_pressure_ratio << " "; cout << endl;
//	cout << "喘震效率: ";
//	for (auto& e : mtl.getTClinesNew()) cout << e._surge_efficiencies << " "; cout << endl;
//
//	_stprintf_s(s, _T("4800: 速比-喘震流量"));
//	//mtl.drawGraphLine(arrx, arry, s);
//
//	mtl.saveFile();
//}

namespace TCLExtra
{

	void test2()
	{
		MultiTurbineCharLine mtl(8000);
		std::ifstream input("./indata/data.txt");
		mtl.readDataFromFile(input);
		input.close();
		mtl.getSurgeLine();

		cout << endl << endl;
		cout << "转速: ";
		for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
		cout << "喘震流量: ";
		for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
		cout << "喘震压比: ";
		for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
		cout << "喘震效率: ";
		for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;

		// 带入原有特性线验证,最好 7:3, 一开始用7层样本外推, 最后3层样本验证
		mtl.extrapolation(2500);
		printf("速度: %lf, 喘震流量: %lf, 喘震压比: %lf, 喘震效率: %lf\n",
			mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
			mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

		mtl.extrapolation(2300);
		printf("速度: %lf, 喘震流量: %lf, 喘震压比: %lf, 喘震效率: %lf\n",
			mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
			mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

		mtl.drawGraph(MultiTurbineCharLine::FLOW | MultiTurbineCharLine::PRESS);
		mtl.drawGraph(MultiTurbineCharLine::FLOW | MultiTurbineCharLine::EFFICIENT);

		string filename = "text";
		std::ofstream output(filename, std::ios::out | std::ios::trunc);
		mtl.saveFile(output);
		xlnt::workbook wb;
		mtl.saveExcelFile(wb, 1, true);
	}
}

void test_turb()
{
	//TCLExtra::MultiTurbineCharLine_PreRotations mtlp(8000);
	//mtlp.readDataFromFile("./indata/turb.txt", true, true);
	//mtlp.solution(std::vector<double>(), "./outdata/outcome2");

	TCLExtra::MultiTurbineCharLine mtl(8000);
	std::ifstream input("./indata/test.txt");
	mtl.readDataFromFile(input, true, true);
	input.close();
	//mtl.getSurgeLine();

	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::PRESS);
	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::EFFICIENT);


}


int main()
{
	try
	{
		//setlocale(LC_ALL, "chs");//设置wcout输出中文
		//TCLExtra::MultiTurbineCharLine_PreRotations mtlr(8000);
		//mtlr.readDataFromFile("./indata/data.txt", false);
		//mtlr.solution();

		test_turb();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	return 0;
}