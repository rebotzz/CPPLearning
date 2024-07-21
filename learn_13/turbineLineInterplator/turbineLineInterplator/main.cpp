#include "extraplotion.hpp"

//void test1()
//{
//	MultiTurbineCharLine mtl(8000);
//	mtl.readData("data.txt");
//	mtl.getSurgeLine();
//
//	cout << endl << endl;
//	cout << "ת��: ";
//	for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
//	cout << "��������: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
//	cout << "����ѹ��: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
//	cout << "����Ч��: ";
//	for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;
//
//	TCHAR s[32] = { 0 };
//	vector<double> arrx(mtl.getTClines().size()), arry(mtl.getTClines().size()), arry_e(mtl.getTClines().size());
//	for (int i = 0; i < mtl.getTClines().size(); ++i) {
//		arrx[i] = mtl.getTClines()[i]._surge_flow;
//		arry[i] = mtl.getTClines()[i]._surge_pressure_ratio;
//		arry_e[i] = mtl.getTClines()[i]._surge_efficiencies;
//	}
//	_stprintf_s(s, _T("ԭʼ: ��������-����ѹ��"));
//	mtl.drawGraphLine(arrx, arry, s);
//	_stprintf_s(s, _T("ԭʼ: ��������-����Ч��"));
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
//	_stprintf_s(s, _T("��������: �ٱ�-��������"));
//	mtl.drawGraphLine(arrx, arry, s);
//
//
//
//	// ֻ����4800ת��
//	arrx.resize(0), arry.resize(0);
//	arrx.push_back(4800 / mtl._speed_design);
//	arry.push_back(mtl._surge_speedRatio_flow_ptr->operator()(arrx.back()));
//	mtl.extraplotion(4800);
//
//	cout << endl << endl;
//	cout << "�ٶ�: ";
//	for (auto& e : arrx) cout << e * mtl._speed_design << " "; cout << endl;
//	cout << "�ٱ�: ";
//	for (auto& e : arrx) cout << e << " "; cout << endl;
//	cout << "��������: ";
//	for (auto& e : arry) cout << e << " "; cout << endl;
//
//	cout << "����ѹ��: ";
//	for (auto& e : mtl.getTClinesNew()) cout << e._surge_pressure_ratio << " "; cout << endl;
//	cout << "����Ч��: ";
//	for (auto& e : mtl.getTClinesNew()) cout << e._surge_efficiencies << " "; cout << endl;
//
//	_stprintf_s(s, _T("4800: �ٱ�-��������"));
//	//mtl.drawGraphLine(arrx, arry, s);
//
//	mtl.saveFile();
//}

void test2()
{
	MultiTurbineCharLine mtl(8000);
	std::ifstream input("data.txt");
	mtl.readData(input);
	input.close();
	mtl.getSurgeLine();

	cout << endl << endl;
	cout << "ת��: ";
	for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
	cout << "��������: ";
	for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
	cout << "����ѹ��: ";
	for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
	cout << "����Ч��: ";
	for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;

	// ����ԭ����������֤,��� 7:3, һ��ʼ��7����������, ���3��������֤
	mtl.extraplotion(2500);
	printf("�ٶ�: %lf, ��������: %lf, ����ѹ��: %lf, ����Ч��: %lf\n",
		mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
		mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

	mtl.extraplotion(2300);
	printf("�ٶ�: %lf, ��������: %lf, ����ѹ��: %lf, ����Ч��: %lf\n",
		mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
		mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

	mtl.drawGraph(MultiTurbineCharLine::FLOW | MultiTurbineCharLine::PRESS);
	mtl.drawGraph(MultiTurbineCharLine::FLOW | MultiTurbineCharLine::EFFICIENT);

	string filename = "text";
	std::ofstream output(filename, std::ios::out | std::ios::trunc);
	mtl.saveFile(output);
	xlnt::workbook wb;
	mtl.saveExcelFile(wb);
}

int main()
{
	try
	{
		//string filename = "text";
		//std::ofstream output(filename, std::ios::out | std::ios::trunc);
		
		//test1();
		test2();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	return 0;
}