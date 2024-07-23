#include "extrapolation.hpp"


void test_all();

// comman line interface 简单,方便被别的程序调用
void CLI();

// 图形交互界面
void ImGUI()
{

}

int main()
{
	try
	{
		// 中文支持: 打印日志
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
		cout << "未知异常" << endl;
	}

	return 0;
}





// comman line interface 简单,方便被别的程序调用
void CLI()
{
	int choice_file = 0, choice_check = 0, choice_err = 0, speed_design = 0, num = 0;
	cout << "燃气轮机特性线外插程序" << endl;
	cout << "tips: 选项输入方式,输入对应数字并回车.注意: 其余数字无效" << endl;
	cout << "选择数据读取方式[indata目录下/input文件]:\n" << "1. excel(.xlsx)文件\t" << "2. 记事本(.txt)文件" << endl;
	cin >> choice_file;
	cout << "选择是否检查数据读取:\n" << "1. 检查\t" << "0. 不检查" << endl;
	cin >> choice_check;
	cout << "选择是否校验误差:\n" << "1. 校验\t" << "0. 不校验" << endl;
	cin >> choice_err;
	cout << "输入设计转速: " << endl;
	cin >> speed_design;
	cout << "最后,输入要外插的速度:\n" << "[格式: 速度组数 空格 速度1 速度2 ...]" << endl;
	cout << "例如, 外插4组速度: 4 2500 2600 2700 2800\n" << "请输入:" << endl;
	cin >> num;
	vector<double> speeds(num);
	for (auto& e : speeds) cin >> e;
	cout << "输入结束,开始计算.输出结果[outdata目录下]" << endl;

	TCLExtra::MultiTurbineCharLine_PreRotations mtlr(speed_design);
	if (choice_file == 1) mtlr.readDataFromExcel("./indata/input.xlsx", choice_check == 1);
	else if (choice_file == 2) mtlr.readDataFromFile("./indata/input.txt", choice_check == 1);
	if (choice_check == 1) mtlr.checkExtraError();
	mtlr.solution(speeds);
	cout << "程序结束!\nbye!";
}





// 这里是示例, 也是功能测试
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

