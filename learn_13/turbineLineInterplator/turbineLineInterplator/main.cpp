#include "extraplotion.hpp"


int main()
{
	try
	{
		MultiTurbineCharLine mtl(8000);
		mtl.readData("data.txt");
		mtl.getSurgeLine();

		cout << "喘震流量: ";
		for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
		

		cout << "\n\n开始外推:\n";
		for (int speed = 2800; speed >= 2500; speed -= 100) {
			auto& charline =  mtl.extraplotion(speed);
			cout << "速度:\t" << speed << endl;
			cout << "流量:\t" << endl;
			for (auto& flow : charline._flows) cout << flow << "\t"; cout << endl;
			cout << "效率:\t" << endl;
			for (auto& eff : charline._efficiencies) cout << eff << "\t"; cout << endl;
			cout << "压比:\t" << endl;
			for (auto& pres : charline._pressure_ratios) cout << pres << "\t"; cout << endl;
		}

		// 带入原有特性线验证,最好 7:3, 一开始用7层样本外推, 最后3层样本验证
		//mtl.extraplotion(4000);
		//mtl.extraplotion(4800);
		//mtl.extraplotion(5600);
		//mtl.extraplotion(6400);
		//mtl.extraplotion(8800);
		//mtl.extraplotion(9600);
		
		// 临时方案: 全部带入验证
		for (auto& charline : mtl.getTClines())
		{
			mtl.extraplotion(charline._speed);
		}

		mtl.drawGraph();
		mtl.saveFile();
		mtl.saveExcelFile();
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