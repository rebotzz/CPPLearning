#pragma once
#include <xlnt/xlnt.hpp>	// ���������ͷ�ļ���ͻ,�����ʼ

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include <boost/math/interpolators/barycentric_rational.hpp>
#include <boost/math/tools/roots.hpp>
#include "graph.hpp"

#undef max
#undef min

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::move;

#define M_PI 3.14159265358979323846
static const double PI = acos(-1.0);		// Բ���ʦ�
static const double g_adiabaticIndex = 1.4;	// ����ָ�� �ݶ�1.4


// ת��Ϊspeed��������
class TurbineCharLine
{
public:
	vector<double> _flows;				// ����
	vector<double> _efficiencies;		// Ч��
	vector<double> _pressure_ratios;	// ѹ��
	double _speed = 0.0;				// ת��
	double _surge_flow = 0.0;			// ��������
	double _surge_efficiencies = 0.0;	// ����Ч��
	double _surge_pressure_ratio = 0.0; // ����ѹ��
};

//// ѹ����������������	bug: ����ȷ, ����
//inline double getSurgeFlow(double speed_operating, double speed_design)
//{
//	return 1.225 * pow(((1 - (0.1576 * PI - 0.1418) * (1 - speed_operating / speed_design)) / (1 - 1.4805 * PI + 0.5854 * PI * PI)), 2);
//}

// ��ͬת��speed��������
class MultiTurbineCharLine
{
private:
	typedef boost::math::interpolators::barycentric_rational<double> Interpolator;
private:
	// todo���Ż�: ÿ���������Ա�������flows, ��һ��,��������
	vector<TurbineCharLine> _tclines;							// ��֪����,���е�������
	double _speed_design = 0.0;									// ���ת��

	std::shared_ptr<Interpolator> _surge_speedRatio_flow_ptr;	// ��ֵ�õ�:(�����ٶ�/����ٶ�)-��������
	std::shared_ptr<Interpolator> _surge_flow_pressRatio_ptr;	// ��ֵ�õ�:��������-����ѹ��
	std::shared_ptr<Interpolator> _surge_flow_efficiency_ptr;	// ��ֵ�õ�:��������-����Ч��
	vector<TurbineCharLine> _tclines_new;						// ��ֵ����:�µ�������

public:
	MultiTurbineCharLine(double speed_design, int length = 800) : _speed_design(speed_design)
	{}

	vector<TurbineCharLine>& getTClines() { return _tclines; }
	vector<TurbineCharLine>& getTClinesNew() { return _tclines_new; }

	void readData(string filename)
	{
		std::ifstream input(filename);
		if (!input.is_open()) {
			cerr << "open failed" << endl;
		}

		string beginLine, tmp;
		while (std::getline(input, beginLine))	// �涨ֻҪ�����µ�һ��,��ô��������������
		{
			// �����µ�һ������
			_tclines.push_back(TurbineCharLine());
			auto& flows = _tclines.back()._flows;
			auto& efficiencies = _tclines.back()._efficiencies;
			auto& pressure_ratios = _tclines.back()._pressure_ratios;
			auto& speed = _tclines.back()._speed;

			std::istringstream issbegin(beginLine);
			issbegin >> speed;

			// ���ٿռ�
			int count = 0;
			for (char ch : beginLine) {
				if (ch == '\t') count++;
			}
			flows.resize(count);
			efficiencies.resize(count);
			pressure_ratios.resize(count);

			// ��ȡ����
			input >> tmp;
			for (auto& e : flows) {
				input >> e;
			}
			input >> tmp;
			for (auto& e : efficiencies) {
				input >> e;
			}
			input >> tmp;
			for (auto& e : pressure_ratios) {
				input >> e;
			}
			std::getline(input, beginLine);		// ��ȡʣ��� "\n"

			// ����ȡ
			cout << "ת��: " << speed << endl;
			cout << "����: ";
			for (auto x : flows) cout << x << " ";
			cout << endl;
			cout << "Ч��: ";
			for (auto x : efficiencies) cout << x << " ";
			cout << endl;
			cout << "ѹ��: ";
			for (auto x : pressure_ratios) cout << x << " ";
			cout << endl;
			cout << endl << "------------------------------" << endl;
			//system("pause");
		}
		cout << endl << endl << endl;
		input.close();
	}

	// ������(����)�߽���
	void getSurgeLine()
	{
		// ��ⲻͬת�ٵ������ߴ����
		vector<double> surge_flows, surge_press_ratios, surge_efficiencies, surge_speedRatio;
		for (auto& charline : _tclines) {
			// �ٶ���������Ϊ:ѹ��-������б��Ϊ��ĵ� 
			// ��ÿһ�������߲�ֵ,��б��Ϊ0�ĵ�
			auto& x_values = charline._flows;
			auto& y_values_press = charline._pressure_ratios;
			auto& y_values_eff = charline._efficiencies;

			auto getdfRoots = [&charline](Interpolator& inter)->double {
				// ���ֲ��Ҹ� f`(x)�ĸ�
				auto df = [&inter](double x) {return inter.prime(x); };
				// ��Ϊ��������(�Ա���)��������
				double min = charline._flows[0], max = charline._flows.back();
				// ������ҪС�ĸ�������û�и�,���߾�������
				auto tol = [](double left, double right) { return abs(left - right) < 1e-4; }; // ����
				std::pair<double, double> root;
				try
				{
					root = boost::math::tools::bisect(df, min, max, tol);
					printf("speed: %lf, root: %lf %lf\n", charline._speed, root.first, root.second);
				}
				catch (const std::exception&)
				{
					printf("charline [speed]: %lf, not find root!\n", charline._speed);
					return 0.0;
				}
				catch (...)
				{
					throw;
				}

				// ����df����,ֻ��һ����
				return root.first;
				};

			// ��ֵ�õ�����-ѹ��,����-Ч�ʹ�ϵ f(x)
			// �ƺ�ֻ������-ѹ�Ⱦ͹���, �õ���������, Ȼ���ֵ�õ�����Ч��
			Interpolator interPress(x_values.begin(), x_values.end(), y_values_press.begin());
			Interpolator interEff(x_values.begin(), x_values.end(), y_values_eff.begin());

			// ����-ѹ��:б��Ϊ��ĵ�  �����
			charline._surge_flow = getdfRoots(interPress);	// ���������Ҳ�����,��Ϊ0
			if (charline._surge_flow != 0) {
				charline._surge_pressure_ratio = interPress(charline._surge_flow);
				charline._surge_efficiencies = interEff(charline._surge_flow);
			}

			// �޳���Ч��
			if (charline._surge_flow != 0) {
				surge_flows.push_back(charline._surge_flow);
				surge_press_ratios.push_back(charline._surge_pressure_ratio);
				surge_efficiencies.push_back(charline._surge_efficiencies);
				surge_speedRatio.push_back(charline._speed / _speed_design);
			}
		}

		// ��ֵ�õ���������: ��������-����ѹ��, ��������-����Ч��, �ٱ�(�����ٶ�/����ٶ�)-��������
		std::shared_ptr<Interpolator> surge_flow_press(new Interpolator(surge_flows.begin(), surge_flows.end(), surge_press_ratios.begin()));
		std::shared_ptr<Interpolator> surge_flow_efficiency(new Interpolator(surge_flows.begin(), surge_flows.end(), surge_efficiencies.begin()));
		std::shared_ptr<Interpolator> surge_speedRatio_flow(new Interpolator(surge_speedRatio.begin(), surge_speedRatio.end(), surge_flows.begin()));
		_surge_flow_pressRatio_ptr = surge_flow_press;
		_surge_flow_efficiency_ptr = surge_flow_efficiency;
		_surge_speedRatio_flow_ptr = surge_speedRatio_flow;
	}

	// ����ת��speed_new��Ӧ��������
	// ����: [���շ������߾��Ƚ�ģ�������ܷ����о�-�߳���]:P45
	TurbineCharLine& extraplotion(double speed_new)
	{
		// ��ʼ��
		_tclines_new.push_back(TurbineCharLine());
		auto& tcline = _tclines_new.back();	// ��Ҫ���Ƶ�������
		int mid = _tclines.size() / 2;
		size_t size = _tclines[mid]._flows.size();
		tcline._flows.resize(size);
		tcline._pressure_ratios.resize(size);
		tcline._efficiencies.resize(size);
		tcline._speed = speed_new;

		// �ݶ�ʹ���м�һ����������Ϊ��׼
		auto& tcline_ref = _tclines[mid];
		double speed_ref = tcline_ref._speed;
		double surge_pressure_ratio_ref = tcline_ref._surge_pressure_ratio;
		double surge_flow_ref = tcline_ref._surge_flow;
		double surge_efficiency_ref = tcline_ref._surge_efficiencies;
		double adiabaticIndex = g_adiabaticIndex;	// ����ָ��

		// todo: ��֤������ȷ��
		// �ٶ����ô�����ֵ�õ��Ĺ�ϵ:
		// f(x): (�����ٶ�/����ٶ�)�ٱ�-�������� ��������-����ѹ�� ��������-����Ч��
		// ��ֵ�õ��µ�ת��speed_new��Ӧ�Ĵ�������:
		// ����flows,ѹ��pressure_ratio,Ч��efficiencies 
		double surge_flow_new = _surge_speedRatio_flow_ptr->operator()(speed_new / speed_ref);
		double surge_pressure_ratio_new = _surge_flow_pressRatio_ptr->operator()(surge_flow_new);
		double surge_efficiency_new = _surge_flow_efficiency_ptr->operator()(surge_efficiency_ref);

		// ���ֵ�ı���ϵ��
		double speed_ratio = speed_new / speed_ref;
		double indexPressureRatio = getIndexPressureRatio(surge_pressure_ratio_new, surge_pressure_ratio_ref, speed_ratio, adiabaticIndex);
		double indexFlow = getIndexFlow(surge_flow_new, surge_flow_ref, speed_ratio);
		double indexEfficient = getIndexEfficiency(surge_efficiency_new, surge_efficiency_ref, speed_ratio);

		// ������������ת��speed_new��Ӧ��������
		double flow_similar = pow(speed_ratio, indexFlow);
		double pressure_ratios_similar = pow(speed_ratio, indexPressureRatio);
		double efficiencie_similar = pow(speed_ratio, indexEfficient);
		double ks = (adiabaticIndex - 1) / adiabaticIndex, kb = adiabaticIndex / (adiabaticIndex - 1);
		for (int i = 0; i < size; ++i) {
			tcline._flows[i] = tcline_ref._flows[i] * flow_similar;
			tcline._pressure_ratios[i] = pow(1 + (pow(tcline_ref._pressure_ratios[i], ks) - 1) * pressure_ratios_similar, kb);
			tcline._efficiencies[i] = tcline_ref._efficiencies[i] * efficiencie_similar;
		}
		
		return tcline;
	}

	// ���������ƹ�ϵϵ��
	double getIndexFlow(double flow_new, double flow_ref, double speed_ratio)
	{
		return log(flow_new / flow_ref) / log(speed_ratio);
	}

	// ѹ�ȵ����ƹ�ϵϵ��
	double getIndexPressureRatio(double pressure_ratio_new, double pressure_ratio_ref, double speed_ratio, double adiabaticIndex)
	{
		double k = (adiabaticIndex - 1) / adiabaticIndex;
		return log( pow(pressure_ratio_new, k) / pow(pressure_ratio_ref, k) ) / log(speed_ratio);
	}

	// Ч�ʵ����ƹ�ϵϵ��
	double getIndexEfficiency(double efficiency_new, double efficiency_ref, double speed_ratio)
	{
		return log(efficiency_new / efficiency_ref) / log(speed_ratio);
	}

	void drawGraph(int length = 800)
	{
		// ��������
		Coordinate _coord(length);

		// ����ԭ����������
		_coord.initGraph();
		int margin = length * 0.05;
		_coord.setOrigin(margin, length - margin);
		_coord.setxScope(_tclines[0]._flows[0], _tclines[0]._flows.back());
		_coord.setyScope(1, 3);	// ѹ�ȷ�Χ��� 1 ~ 3
		_coord.drawCoordinate();
		for (auto& charline : _tclines) {
			TCHAR s[32] = { 0 };
			_stprintf_s(s, _T("�ٶ�:%.0lf"), charline._speed);
			_coord.drawLine(charline._flows, charline._pressure_ratios, s);
		}

		// ���ƴ���߽���
		vector<double> surgeX(_tclines.size()), surgeY(_tclines.size());
		for (int i = 0; i < surgeX.size(); ++i) {
			surgeX[i] = _tclines[i]._surge_flow;
			surgeY[i] = _tclines[i]._surge_pressure_ratio;
		}
		TCHAR s[32] = { 0 };
		_stprintf_s(s, _T("����߽���"));
		_coord.drawLine(surgeX, surgeY, s);


		system("pause");

		// ����������������������
		for (auto& charline : _tclines_new) {
			TCHAR s[32] = { 0 };
			_stprintf_s(s, _T("�����ٶ�:%.0lf"), charline._speed);
			_coord.drawLine(charline._flows, charline._pressure_ratios, s);
		}

		system("pause");
		_coord.closeGraph();
	}

	void saveFile(string filename = "outcome.txt")
	{
		std::ofstream output(filename, std::ios::out | std::ios::trunc);
		if (!output.is_open()) {
			cerr << "�ļ���ʧ��: " << filename << endl;
			return;
		}

		output << "��ֵ��ʧ�ܵ�����: ��������Ϊ0, ����" << endl;
		output << "��������: ";
		for (auto& e : _tclines) output << e._surge_flow << " "; cout << endl;

		output << "\n\n���ƽ��:\n";
		for (auto& charline : _tclines_new) {
			output << "�ٶ�:\t" << charline._speed << endl;
			output << "����:\t" << endl;
			for (auto& flow : charline._flows) output << flow << "\t"; output << endl;
			output << "Ч��:\t" << endl;
			for (auto& eff : charline._efficiencies) output << eff << "\t"; output << endl;
			output << "ѹ��:\t" << endl;
			for (auto& pres : charline._pressure_ratios) output << pres << "\t"; output << endl;
		}
		output.close();
	}

	void saveExcelFile(string filename = "outcome.xlsx")
	{
		xlnt::workbook wb;
		xlnt::worksheet ws = wb.active_sheet();		
	
		int row = 1;
		for (auto& charline : _tclines_new) {
			int n = charline._flows.size();
			string str = "speed:" + std::to_string(int(charline._speed));
			ws.cell(1, row).value(str);
			// ������Ҫ����utf8����
			ws.cell(1, row + 1).value("flow");				// ("����");
			ws.cell(1, row + 2).value("efficiency");		// ("Ч��");
			ws.cell(1, row + 3).value("presure_ratio");		// ("ѹ��");
			
			for (int col = 0; col < n; ++col) {
				ws.cell(col + 2, row + 1).value(charline._flows[col]);	// [��, ��]
				ws.cell(col + 2, row + 2).value(charline._efficiencies[col]);
				ws.cell(col + 2, row + 3).value(charline._pressure_ratios[col]);
			}
			row += 4;
		}

		wb.save(filename);
	}
};
