#include "extraplotion.hpp"


int main()
{
	try
	{
		MultiTurbineCharLine mtl(8000);
		mtl.readData("data.txt");
		mtl.getSurgeLine();

		cout << "��������: ";
		for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
		

		cout << "\n\n��ʼ����:\n";
		for (int speed = 2800; speed >= 2500; speed -= 100) {
			auto& charline =  mtl.extraplotion(speed);
			cout << "�ٶ�:\t" << speed << endl;
			cout << "����:\t" << endl;
			for (auto& flow : charline._flows) cout << flow << "\t"; cout << endl;
			cout << "Ч��:\t" << endl;
			for (auto& eff : charline._efficiencies) cout << eff << "\t"; cout << endl;
			cout << "ѹ��:\t" << endl;
			for (auto& pres : charline._pressure_ratios) cout << pres << "\t"; cout << endl;
		}

		// ����ԭ����������֤,��� 7:3, һ��ʼ��7����������, ���3��������֤
		//mtl.extraplotion(4000);
		//mtl.extraplotion(4800);
		//mtl.extraplotion(5600);
		//mtl.extraplotion(6400);
		//mtl.extraplotion(8800);
		//mtl.extraplotion(9600);
		
		// ��ʱ����: ȫ��������֤
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
		cout << "δ֪�쳣" << endl;
	}



	return 0;
}