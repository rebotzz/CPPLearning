#include "extrapolation.hpp"


void test_all();

// comman line interface ��,���㱻��ĳ������
void CLI();

// ͼ�ν�������
void ImGUI()
{

}

int main()
{
	try
	{
		// ����֧��: ��ӡ��־
 		//std::locale::global(std::locale("zh_CN.UTF-8"));
		//std::cout.imbue(std::locale());
		//std::wcout.imbue(std::locale());
		//CLI();
		test_all();
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





// comman line interface ��,���㱻��ĳ������
void CLI()
{
	int choice_file = 0, choice_check = 0, choice_err = 0, speed_design = 0, num = 0;
	cout << "ȼ���ֻ�������������" << endl;
	cout << "tips: ѡ�����뷽ʽ,�����Ӧ���ֲ��س�.ע��: ����������Ч" << endl;
	cout << "ѡ�����ݶ�ȡ��ʽ[indataĿ¼��/input�ļ�]:\n" << "1. excel(.xlsx)�ļ�\t" << "2. ���±�(.txt)�ļ�" << endl;
	cin >> choice_file;
	cout << "ѡ���Ƿ������ݶ�ȡ:\n" << "1. ���\t" << "0. �����" << endl;
	cin >> choice_check;
	cout << "ѡ���Ƿ�У�����:\n" << "1. У��\t" << "0. ��У��" << endl;
	cin >> choice_err;
	cout << "�������ת��: " << endl;
	cin >> speed_design;
	cout << "���,����Ҫ�����ٶ�:\n" << "[��ʽ: �ٶ����� �ո� �ٶ�1 �ٶ�2 ...]" << endl;
	cout << "����, ���4���ٶ�: 4 2500 2600 2700 2800\n" << "������:" << endl;
	cin >> num;
	vector<double> speeds(num);
	for (auto& e : speeds) cin >> e;
	cout << "�������,��ʼ����.������[outdataĿ¼��]" << endl;

	TCLExtra::MultiTurbineCharLine_PreRotations mtlr(speed_design);
	if (choice_file == 1) mtlr.readDataFromExcel("./indata/input.xlsx", choice_check == 1);
	else if (choice_file == 2) mtlr.readDataFromFile("./indata/input.txt", choice_check == 1);
	if (choice_check == 1) mtlr.checkExtraError();
	mtlr.solution(speeds);
	cout << "�������!\nbye!";
}





// ������ʾ��, Ҳ�ǹ��ܲ���
void test_all()
{
	TCLExtra::MultiTurbineCharLine_PreRotations mtlr(8000);
	//mtlr.readDataFromFile("./indata/example.txt", false);
	mtlr.readDataFromExcel("./indata/example.xlsx", true);
	vector<double> spnew = { 2500, 2600, 2700, 2800 };
	mtlr.solution(spnew);
	//mtlr.checkExtraError();
}

void test_one()
{
	TCLExtra::MultiTurbineCharLine mtl(8000);
	std::ifstream input("./indata/example2.txt");
	mtl.readDataFromFile(input);
	input.close();
	mtl.getSurgeLineP();

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
	mtl.extrapolation(2500);
	printf("�ٶ�: %lf, ��������: %lf, ����ѹ��: %lf, ����Ч��: %lf\n",
		mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
		mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

	mtl.extrapolation(2300);
	printf("�ٶ�: %lf, ��������: %lf, ����ѹ��: %lf, ����Ч��: %lf\n",
		mtl.getTClinesNew().back()._speed, mtl.getTClinesNew().back()._surge_flow,
		mtl.getTClinesNew().back()._surge_pressure_ratio, mtl.getTClinesNew().back()._surge_efficiencies);

	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::PRESS);
	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::EFFICIENT);

	string filename = "text";
	std::ofstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
	mtl.saveFile(output);
	xlnt::workbook wb;
	mtl.saveExcelFile(wb, 1, true);
}

void test_turb()
{
	//TCLExtra::MultiTurbineCharLine_PreRotations mtlp(8000);
	//mtlp.readDataFromFile("./indata/turb.txt", true, true);
	//mtlp.solution(std::vector<double>(), "./outdata/outcome2");

	TCLExtra::MultiTurbineCharLine mtl(8000);
	std::ifstream input("./indata/test.txt");
	mtl.readDataFromFile(input, true);
	input.close();
	//mtl.getSurgeLine();

	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::PRESS);
	mtl.drawGraph(TCLExtra::MultiTurbineCharLine::FLOW | TCLExtra::MultiTurbineCharLine::EFFICIENT);
}

void test_err()
{
	TCLExtra::MultiTurbineCharLine mtl(8000);
	std::ifstream input("./indata/pres.txt");
	mtl.readDataFromFile(input, true);
	input.close();

	mtl.checkExtraError();
}

void test_readexcel()
{
	TCLExtra::MultiTurbineCharLine mtl(8000);
	//std::ifstream input("./indata/pres.txt");
	//mtl.readDataFromFile(input, true);
	//input.close();

	TCLExtra::MultiTurbineCharLine_PreRotations mtlr(8000);
	mtlr.readDataFromExcel("./indata/test.xlsx", true);
	mtlr.solution();
}

