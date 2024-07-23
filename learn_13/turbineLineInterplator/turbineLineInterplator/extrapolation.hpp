#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <unordered_map>
#include <iomanip>
//#include <locale>							// ��������,windowsĬ��ʹ��ANSI����,��UTF8ת��
#include <xlnt/xlnt.hpp>					// ���������ͷ�ļ�(��������)��ͻ,�����ʼ
#include <boost/math/interpolators/barycentric_rational.hpp>
#include <boost/math/tools/roots.hpp>
#include "mytools.hpp"

#undef max
#undef min
using std::cin;
using std::cout;
using std::cerr;
using std::wcout;
using std::endl;
using std::vector;
using std::string;
using std::wstring;
using std::move;

namespace TCLExtra
{
	// ��������
	#define M_PI 3.14159265358979323846
	static const double PI = acos(-1.0);			// Բ���ʦ�
	static const double g_adiabaticIndex = 1.667;	// ����ָ�� �ݶ�1.667
	static size_t g_precision = 10;					// ������ݱ�������

	// ת��Ϊspeed��������
	class TurbineCharLine
	{
	public:
		vector<double> _flows;						// ����	
		vector<double> _efficiencies;				// Ч��
		vector<double> _pressRatios;				// ѹ��
		double _speed = 0.0;						// ת��
		double _surge_flow = 0.0;					// ��������
		double _surge_efficiencies = 0.0;			// ����Ч��
		double _surge_pressure_ratio = 0.0;			// ����ѹ��
	};

	// ��ͬת��speed��������
	class MultiTurbineCharLine
	{
	private:
		typedef boost::math::interpolators::barycentric_rational<double> Interpolator;
	private:
		//public:
			// todo���Ż�: ÿ���������Ա�������flows, ��һ��,��������
		vector<TurbineCharLine> _tclines;							// ��֪����,���е�������
		double _speed_design = 0.0;									// ���ת��
		string _preRotation = "Ԥ��";

		std::shared_ptr<Interpolator> _surge_speedRatio_flow_ptr;	// ��ֵ�õ�:(�����ٶ�/����ٶ�)-��������
		std::shared_ptr<Interpolator> _surge_flow_pressRatio_ptr;	// ��ֵ�õ�:��������-����ѹ��
		std::shared_ptr<Interpolator> _surge_flow_efficiency_ptr;	// ��ֵ�õ�:��������-����Ч��
		vector<TurbineCharLine> _tclines_new;						// ��ֵ����:�µ�������

	public:
		enum DrawGraphOption
		{
			FLOW = 1,
			PRESS = 2,
			EFFICIENT = 4
		};

	public:
		MultiTurbineCharLine(double speed_design = 8000, int length = 800) : _speed_design(speed_design)
		{}

		void setSpeedDesign(double speed_design) { _speed_design = speed_design; }
		vector<TurbineCharLine>& getTClines() { return _tclines; }
		vector<TurbineCharLine>& getTClinesNew() { return _tclines_new; }
		string& preRotation() { return _preRotation; }


		// todo: ������(����)�߽��� ���ֲ���; ��ǳ...,û������ָ��
		void getSurgeLineT()
		{}

		// ������(����)�߽���	ѹ��������
		void getSurgeLineP()
		{
			// ��ⲻͬת�ٵ������ߴ����
			vector<double> surge_flows, surge_press_ratios, surge_efficiencies, surge_speedRatio;
			for (auto& charline : _tclines) {
				// ��������:[����ʽҶ�ֻ�е���ۼ����-���]:P223
				// �ٶ���������Ϊ:ѹ��-������б��Ϊ��ĵ� 
				// ��ÿһ�������߲�ֵ,��б��Ϊ0�ĵ�
				auto& x_values = charline._flows;
				auto& y_values_press = charline._pressRatios;
				auto& y_values_eff = charline._efficiencies;

				auto getdfRoots = [&charline](Interpolator& inter)->double {
					// ���ֲ��Ҹ� f`(x)�ĸ�
					auto df = [&inter](double x) {return inter.prime(x); };
					// ��Ϊ��������(�Ա���)��������
					double min = charline._flows[0], max = charline._flows.back();
					// ������ҪС�ĸ�������û�и�,���߾�������
					auto tol = [](double left, double right) { return abs(left - right) < 1e-4; }; // ����
					std::pair<double, double> root;
					try { root = boost::math::tools::bisect(df, min, max, tol); }
					catch (const std::exception& e) {
						LOG(WARING, "�������, �ٶ�: " + std::to_string(charline._speed) + "\n" + e.what() + "\n");
						return 0.0;
					}
					catch (...) { LOG(WARING, "�������"); return 0.0;}

					// ����df����,ֻ��һ����
					return root.first;
					};

				// ��ֵ�õ�����-ѹ��,����-Ч�ʹ�ϵ f(x)
				Interpolator interPress(x_values.begin(), x_values.end(), y_values_press.begin());
				Interpolator interEff(x_values.begin(), x_values.end(), y_values_eff.begin());

				// ����-ѹ��:б��Ϊ��ĵ�->�����
				// �ݶ�:ֻ��������-ѹ�ȼ�ֵ��͹���, �õ���������, Ȼ���ֵ�õ�����Ч��; ���������-Ч�ʼ�ֵ��,����������ƥ��
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
		TurbineCharLine& extrapolation(double speed_new, double usersest_speed_ref = 0.0)
		{
			// ѡ�Ǹ�ת����������Ϊ��׼?
			// plan: 1.���ת��������(����)  2.���ٶ����ڽ���������
			int ref = _tclines.size() / 2;
			double gap = abs(_tclines[0]._speed - _tclines.back()._speed + 1);
			for (int i = 0; i < _tclines.size(); ++i) {
				if (abs(speed_new - _tclines[i]._speed) < gap && _tclines[i]._surge_flow != 0) {
					gap = abs(speed_new - _tclines[i]._speed);
					ref = i;
				}
			}

			// �û��Զ����׼��
			if (usersest_speed_ref != 0.0) {
				double gap = abs(_tclines[0]._speed - _tclines.back()._speed + 1);
				for (int i = 0; i < _tclines.size(); ++i) {
					if (abs(usersest_speed_ref - _tclines[i]._speed) < gap && _tclines[i]._surge_flow != 0) {
						gap = abs(usersest_speed_ref - _tclines[i]._speed);
						ref = i;
					}
				}
			}

			LOG(NOTICE, "�����ٶ�: " + std::to_string(int(speed_new)) + "-->���ƻ�׼�������ٶ�: " + std::to_string(int(_tclines[ref]._speed)));

			// ��ʼ��
			_tclines_new.push_back(TurbineCharLine());
			auto& tcline = _tclines_new.back();	// ��Ҫ���Ƶ�������
			size_t size = _tclines[ref]._flows.size();
			tcline._flows.resize(size);
			tcline._pressRatios.resize(size);
			tcline._efficiencies.resize(size);
			tcline._speed = speed_new;

			auto& tcline_ref = _tclines[ref];
			double speed_ref = tcline_ref._speed;
			double surge_pressure_ratio_ref = tcline_ref._surge_pressure_ratio;
			double surge_flow_ref = tcline_ref._surge_flow;
			double surge_efficiency_ref = tcline_ref._surge_efficiencies;
			double adiabaticIndex = g_adiabaticIndex;	// ����ָ��

			// todo: ��֤������ȷ��
			// ���ô�����ֵ�õ��Ĺ�ϵ -> ���µ�ת�ٶ�Ӧ�Ĵ����
			// f(x): (�����ٶ�/����ٶ�)�ٱ�-�������� ��������-����ѹ�� ��������-����Ч��
			// ����flows, ѹ��pressure_ratio, Ч��efficiencies 
			double surge_flow_new = _surge_speedRatio_flow_ptr->operator()(speed_new / _speed_design);	// debug: �����ٱ���new/design
			double surge_pressure_ratio_new = _surge_flow_pressRatio_ptr->operator()(surge_flow_new);
			double surge_efficiency_new = _surge_flow_efficiency_ptr->operator()(surge_efficiency_ref);
			tcline._surge_flow = surge_flow_new;
			tcline._surge_pressure_ratio = surge_pressure_ratio_new;
			tcline._surge_efficiencies = surge_efficiency_new;

			// ���ֵ�ı���ϵ��
			double speed_ratio = speed_new / speed_ref;		// ������������ٶ�(��׼)֮��
			double indexFlow = getIndexFlow(surge_flow_new, surge_flow_ref, speed_ratio);
			double indexPressureRatio = getIndexPressureRatio(surge_pressure_ratio_new, surge_pressure_ratio_ref, speed_ratio, adiabaticIndex);
			double indexEfficient = getIndexEfficiency(surge_efficiency_new, surge_efficiency_ref, speed_ratio);

			// ������������ת��speed_new��Ӧ��������
			double flow_similar = pow(speed_ratio, indexFlow);
			double pressRatio_similar = pow(speed_ratio, indexPressureRatio);
			double efficiencie_similar = pow(speed_ratio, indexEfficient);
			double ks = (adiabaticIndex - 1) / adiabaticIndex, kb = adiabaticIndex / (adiabaticIndex - 1);
			for (int i = 0; i < size; ++i) {
				tcline._flows[i] = tcline_ref._flows[i] * flow_similar;
				tcline._pressRatios[i] = pow(1 + (pow(tcline_ref._pressRatios[i], ks) - 1) * pressRatio_similar, kb);
				tcline._efficiencies[i] = tcline_ref._efficiencies[i] * efficiencie_similar;
			}

			return tcline;
		}

		// �������߻���: x-y��ϵ����
		static void drawGraph(const vector<vector<double>>& arrxs, const vector<vector<double>>& arrys, const vector<wstring>& comment, wstring outfile, bool closeimg = true, int length = 800)
		{
			// ��������
			Coordinate _coord(length);
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			double minx = arrxs[0][0], miny = arrys[0][0];
			double maxx = minx, maxy = miny;
			for (const auto& arr : arrxs) {
				for (const auto& e : arr) {
					minx = std::min(e, minx);
					maxx = std::max(e, maxx);
				}
			}
			for (const auto& arr : arrys) {
				for (const auto& e : arr) {
					miny = std::min(e, miny);
					maxy = std::max(e, maxy);
				}
			}

			_coord.setxScope(minx, maxx);
			_coord.setyScope(miny, maxy);
			_coord.drawCoordinate();
			int n = arrxs.size();
			for (int i = 0; i < n; ++i) {
				_coord.drawLine(arrxs[i], arrys[i], comment[i]);
			}

			if (outfile.find(L"./outdata/") == wstring::npos) outfile = L"./outdata/" + outfile;
			if (outfile.find(L".jpg") == wstring::npos) outfile += L".jpg";
			saveimage(outfile.c_str());
			LOG(NOTICE, "����ͼƬ: " + wstring2string(outfile));
			if (closeimg) {
				_coord.closeGraph();
			}
		}

		// ����-ѹ�� or ����-Ч��
		void drawGraph(int option = FLOW | PRESS, std::wstring outfile = L"", bool closeimg = true, int length = 800)
		{
			// ��������
			Coordinate _coord(length);

			// ����ԭ����������
			_coord.initGraph();
			int margin = length * 0.05;
			_coord.setOrigin(margin, length - margin);
			double minx = _tclines[0]._flows[0], maxx = _tclines[0]._flows[0];
			for (auto& charline : _tclines) {
				minx = std::min(minx, charline._flows[0]);
				maxx = std::max(maxx, charline._flows.back());
			}
			_coord.setxScope(minx, maxx);

			bool press = false, effi = false;

			if (outfile.find(L"./outdata/image/") == wstring::npos) outfile = L"./outdata/image/" + outfile;
			std::wstring imagename = outfile;

			if ((option & FLOW) && (option & PRESS)) {
				_coord.setyScope(1, 3);	// ѹ�ȷ�Χ��� 1 ~ 3	
				press = true;
				imagename += L"����-ѹ��.jpg";
			}
			else if ((option & FLOW) && (option & EFFICIENT)) {
				_coord.setyScope(0, 1);	// Ч�ʷ�Χ��� 0 ~ 1
				effi = true;
				imagename += L"����-Ч��.jpg";
			}
			else {
				LOG(WARING, "ѡ�����");
				throw std::invalid_argument("ѡ�����, ʾ��:todo...");
			}

			_coord.drawCoordinate();
			for (auto& charline : _tclines) {
				std::wstring s = L"�ٶ�:";
				s += std::to_wstring(int(charline._speed));
				if (press) _coord.drawLine(charline._flows, charline._pressRatios, s);
				if (effi) _coord.drawLine(charline._flows, charline._efficiencies, s);
			}

			// ���ƴ���߽���
			vector<double> surgeX, surgeY;
			for (auto& charline : _tclines) {
				if (charline._surge_flow != 0) {	// ����û�ҵ��Ĵ����
					surgeX.push_back(charline._surge_flow);
					if (press) surgeY.push_back(charline._surge_pressure_ratio);
					if (effi) surgeY.push_back(charline._surge_efficiencies);
				}
			}
			_coord.drawLine(surgeX, surgeY, L"����߽���");

			// ����������������������
			for (auto& charline : _tclines_new) {
				std::wstring s = L"�����ٶ�:";
				s += std::to_wstring(int(charline._speed));
				if (press) _coord.drawLine(charline._flows, charline._pressRatios, s);
				if (effi) _coord.drawLine(charline._flows, charline._efficiencies, s);
			}

			saveimage(imagename.c_str());
			LOG(NOTICE, "����ͼƬ: " + wstring2string(imagename));
			if (closeimg) {
				_coord.closeGraph();
			}
		}

		// ������
		void checkExtraError(string outfile = "")
		{
			// todo:�޳�����֤�ٶ���ϵĴ����
			getSurgeLineP();

			// ���һ��, ��������һ��ת������ 
			vector<int> checkarr;
			for (int i = 0; i < _tclines.size() - 1; i += 2) {
				double speed_new = _tclines[i]._speed;
				double speed_ref = _tclines[i + 1]._speed;
				extrapolation(speed_new, speed_ref);
				checkarr.push_back(i);
			}

			// �������
			struct ERR {
				vector<double> _errp;
				vector<double> _erre;
				vector<double> _arrx;
				double _id;
			};
			vector<ERR> errs;
			int extraid = 0;
			for (auto i : checkarr) {
				errs.push_back(ERR());
				auto& err = errs.back();				// ���
				auto& extra = _tclines_new[extraid++];	// ���Ƶ�
				auto& origin = _tclines[i];				// ԭ����
				err._id = origin._speed;
				// ��Ϊ���Ƶ�������ԭʼ��ͬ,������Ҫ��ֵ
				Interpolator interp(extra._flows.begin(), extra._flows.end(), extra._pressRatios.begin());
				Interpolator intere(extra._flows.begin(), extra._flows.end(), extra._efficiencies.begin());
				err._arrx = extra._flows;
				size_t n = err._arrx.size();
				err._errp.resize(n);
				err._erre.resize(n);
				for (int j = 0; j < n; ++j) {
					double x = origin._flows[j];
					double yp = origin._pressRatios[j], ye = origin._pressRatios[j];
					err._errp[j] = abs(interp(x) - yp) / yp;
					err._erre[j] = abs(intere(x) - ye) / ye;
				}
			}

			// ���ݳ־û�
			string oldname = outfile;
			if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
			std::ofstream output(outfile + "���У��.txt", std::ios::trunc | std::ios::binary);
			output << u8"���ԭ������У�����\n";
			if (output.is_open()) {
				for (auto& err : errs) {
					output << u8"����ٶ�: " << err._id << endl;
					output << u8"����:\n";
					for (auto x : err._arrx) output << std::setprecision(g_precision) << x << "\t"; output << endl;
					output << u8"ѹ��������:\n";
					for (auto y : err._errp) output << std::setprecision(g_precision) << y << "\t"; output << endl;
					output << u8"Ч��������:\n";
					for (auto y : err._erre) output << std::setprecision(g_precision) << y << "\t"; output << endl;
					output << "\n";
				}
				output.close();
				LOG(NOTICE, "�����ļ�: " + outfile + "���У��.txt");
			}

			// ͼƬ�־û�
			vector<vector<double>> arrxs, arryes, arryps;
			vector<wstring> msg;
			for (auto& err : errs) {
				arrxs.push_back(std::move(err._arrx));
				arryes.push_back(std::move(err._erre));
				arryps.push_back(std::move(err._errp));
				msg.push_back(L"ת��:" + std::to_wstring(err._id));
			}

			outfile = oldname;
			if (outfile.find("./outdata/image/") == string::npos) outfile = "./outdata/image/" + outfile;
			std::wstring file = string2wstring(outfile);
			drawGraph(arrxs, arryps, msg, file + L"����-ѹ��������.jpg");
			drawGraph(arrxs, arryes, msg, file + L"����-Ч��������.jpg");
			LOG(NOTICE, "У��������,���ݳ־û����.");
			// ���У������
			_tclines_new.clear();
		}

		void readDataFromFile(std::ifstream& input, bool check = false)
		{
			if (!input.is_open()) {
				LOG(FATAL, "�ļ���ʧ��");
				return;
			}
			string beginLine, tmp;
			while (std::getline(input, beginLine))	// �涨ֻҪ�����µ�һ��,��ô��������������: С�Ķ���س�
			{
				if (beginLine[0] == '\t') {			// ��β��־,Ϊ�˼���excelճ�������±�
					break;
				}

				// �����µ�һ������
				_tclines.push_back(TurbineCharLine());
				auto& flows = _tclines.back()._flows;
				auto& efficiencies = _tclines.back()._efficiencies;
				auto& pressRatios = _tclines.back()._pressRatios;
				auto& speed = _tclines.back()._speed;
				std::istringstream issbegin(beginLine);
				issbegin >> speed;

				// ���ٿռ�
				int count = 0;
				for (char ch : beginLine) {
					if (ch == '\t') count++;
				}
				vector<double> arr1(count), arr2(count), arr3(count);
				std::unordered_map<std::string, std::vector<double>*> hash;

				// ��ȡ����
				// Э�鶨��: ��������,Ч�ʺ�ѹ��(���ͱ�)ʹ������"flow","efficiency","pressRatio"
				input >> tmp;
				for (auto& e : arr1) input >> e;
				hash[tmp] = &arr1;
				input >> tmp;
				for (auto& e : arr2) input >> e;
				hash[tmp] = &arr2;
				input >> tmp;
				for (auto& e : arr3) input >> e;
				hash[tmp] = &arr3;
				std::getline(input, beginLine);		// ��ȡʣ��� "\n"

				if (hash.count("flow") && hash.count("efficiency") && hash.count("pressRatio")) {
					flows.swap(*hash["flow"]);
					efficiencies.swap(*hash["efficiency"]);
					pressRatios.swap(*hash["pressRatio"]);
				}
				else {
					LOG(FATAL, "��������,Ч�ʺ�ѹ����������.��ȷЭ����: flow,efficiency,pressRatio");
					return;
				}

				// ����ȡ
				if (check) {
					cout << "ת��: " << speed << endl;
					cout << "����: ";
					for (auto x : flows) cout << x << " ";
					cout << endl;
					cout << "Ч��: ";
					for (auto x : efficiencies) cout << x << " ";
					cout << endl;
					cout << "ѹ��/���ͱ�: ";
					for (auto x : pressRatios) cout << x << " ";
					cout << endl;
					cout << endl << "------------------------------" << endl;
				}
			}
			if(check) cout << "\n\n";
		}

		void saveFile(std::ofstream& output)
		{
			if (!output.is_open()) {
				LOG(ERR, "�ļ���ʧ��");
				return;
			}

			output << _preRotation << endl;
			output << u8"ԭʼ���ݼ���[�����]: " << endl;
			output << u8"ת��:\t";
			for (auto& e : _tclines) output << e._speed << "\t"; output << endl;
			output << u8"��������:\t";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_flow << "\t"; output << endl;
			output << u8"����ѹ��: ";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_pressure_ratio << "\t"; output << endl;
			output << u8"����Ч��: ";
			for (auto& e : _tclines) output << std::setprecision(g_precision) << e._surge_efficiencies << "\t"; output << endl;
			output << u8"tip:������������Ϊ0�ĵ�" << endl;
			output << "\n";

			output << u8"\n���ƽ��[�����]:\n";
			output << u8"ת��: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._speed << "\t"; output << endl;
			output << u8"��������: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_flow << "\t"; output << endl;
			output << u8"����ѹ��: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_pressure_ratio << "\t"; output << endl;
			output << u8"����Ч��: ";
			for (auto& charline : _tclines_new) output << std::setprecision(g_precision) << charline._surge_efficiencies << "\t"; output << endl;

			output << u8"\n���ƽ��[������]:\n";
			for (auto& charline : _tclines_new) {
				output << u8"ת��: " << charline._speed << endl;
				output << u8"����: ";
				for (auto& e : charline._flows) output << std::setprecision(g_precision) << e << "\t"; output << endl;
				output << u8"ѹ��: ";
				for (auto& e : charline._pressRatios) output << std::setprecision(g_precision) << e << "\t"; output << endl;
				output << u8"Ч��: ";
				for (auto& e : charline._efficiencies) output << std::setprecision(g_precision) << e << "\t"; output << endl;
			}
			output << "\n\n";
		}

		int saveExcelFile(xlnt::workbook& wb, int beginRow = 1, bool save = false, string outfile = "./outdata/outcome.xlsx")
		{
			xlnt::worksheet ws = wb.active_sheet();
			int row = std::max(beginRow, 1);
			for (auto& charline : _tclines_new) {
				int n = charline._flows.size();
				string str = "speed:" + std::to_string(int(charline._speed));
				ws.cell(1, row).value(str);
				// ������Ҫ����utf8����
				ws.cell(1, row + 1).value(u8"����");		// "flow"
				ws.cell(1, row + 2).value(u8"Ч��");		// "efficiency"
				ws.cell(1, row + 3).value(u8"ѹ��");		// "pressRatio"

				for (int col = 0; col < n; ++col) {
					ws.cell(col + 2, row + 1).value(charline._flows[col]);	// [��, ��]
					ws.cell(col + 2, row + 2).value(charline._efficiencies[col]);
					ws.cell(col + 2, row + 3).value(charline._pressRatios[col]);
				}
				row += 4;
			}

			if (save) {
				if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
				wb.save(outfile);
				LOG(NOTICE, "�����ļ�: " + outfile);
			}
			return row;		// ��һ�δ洢������ʼ��
		}

		// Э��:һ��4������ speed flow efficiency pressRatio ����䲻������; ��ͬԤ���ò�ͬsheet����,sheet����ΪԤ����С
		// Ϊ�˼���Ϊ��excel�߰汾,���Խ����ݿ�����xlnt���ɵı����, �Ҳ�ҪͼƬ,ֻҪ�������; 
		// Ϊ�˱�������,ʹ��Ӣ��; ����:����֧��
		void readDataFromExcel(string file, bool check = false)
		{
			xlnt::workbook wb;
			try { wb.load(file); }
			catch (const std::exception&) { LOG(FATAL, "����Э��:ʹ�ô�����excel���,�ο�example.xlsx"); throw; }
			catch (...) { throw; }
			xlnt::worksheet ws = wb.active_sheet();
			readDataFromExcel(ws, check);
		}
		void readDataFromExcel(xlnt::workbook& wb, bool check = false)
		{
			xlnt::worksheet ws = wb.active_sheet();
			readDataFromExcel(ws, check);
		}
		void readDataFromExcel(const xlnt::worksheet& ws, bool check = false)
		{
			_preRotation = ws.title();
			for (const xlnt::cell_vector& cells : ws) {
				auto itcell = cells.begin();
				auto& cellbegin = *itcell;
				if (cellbegin.has_value() == false) break;	// ��,����

				TurbineCharLine* charline = nullptr;
				if (_tclines.size() != 0) charline = &_tclines.back();
				string tmp = cellbegin.to_string();
				if (tmp.find("speed") != string::npos || tmp.find(u8"ת��") != string::npos) {
					// ��һ������,���ٿռ�
					_tclines.push_back(TurbineCharLine());
					std::stringstream ss(tmp);
					ss >> _tclines.back()._speed;
					continue;
				}
				else if (tmp.find("flow") != string::npos || tmp.find(u8"����") != string::npos) {
					int i = 0;	// �����׸�����ַ�
					for (auto& cell : cells) {
						if (i++) charline->_flows.push_back(std::stod(cell.to_string()));
					}
				}
				else if (tmp.find("efficiency") != string::npos || tmp.find(u8"Ч��") != string::npos) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++) charline->_efficiencies.push_back(std::stod(cell.to_string()));
					}
				}
				else if (tmp.find("pressRatio") != string::npos || tmp.find(u8"ѹ��") != string::npos) {
					int i = 0;
					for (auto& cell : cells) {
						if (i++) charline->_pressRatios.push_back(std::stod(cell.to_string()));
					}
				}
				else {
					LOG(FATAL, "��ʽ����, ����Э��,�ο�example.xlsx");
					return;
				}
			}

			if (check) {
				for (auto& tcline : _tclines) {
					cout << "ת��: " << tcline._speed << endl;
					cout << "����: ";
					for (auto x : tcline._flows) cout << x << " ";
					cout << endl;
					cout << "Ч��: ";
					for (auto x : tcline._efficiencies) cout << x << " ";
					cout << endl;
					cout << "ѹ��/���ͱ�: ";
					for (auto x : tcline._pressRatios) cout << x << " "; /*printf("%.7lf ", x);*/
					cout << endl;
					cout << endl << "------------------------------" << endl;
				}
			}
		}

	private:
		// ���������ƹ�ϵϵ��
		double getIndexFlow(double flow_new, double flow_ref, double speed_ratio)
		{
			return log(flow_new / flow_ref) / log(speed_ratio);
		}

		// ѹ�ȵ����ƹ�ϵϵ��
		double getIndexPressureRatio(double pressure_ratio_new, double pressure_ratio_ref, double speed_ratio, double adiabaticIndex)
		{
			double k = (adiabaticIndex - 1) / adiabaticIndex;
			double tmp1 = pow(pressure_ratio_new, k) - 1;
			double tmp2 = pow(pressure_ratio_ref, k) - 1;
			return log(tmp1 / tmp2) / log(speed_ratio);
		}

		// Ч�ʵ����ƹ�ϵϵ��
		double getIndexEfficiency(double efficiency_new, double efficiency_ref, double speed_ratio)
		{
			return log(efficiency_new / efficiency_ref) / log(speed_ratio);
		}
	};


	class MultiTurbineCharLine_PreRotations
	{
	private:
		vector<MultiTurbineCharLine> _mtcls;
		double _speed_design = 0.0;
	public:
		MultiTurbineCharLine_PreRotations(double speed_design) :_speed_design(speed_design)
		{}
		vector<MultiTurbineCharLine>& getMultiTurbineCharLines() { return _mtcls; }

		// �������ٶ�	����: ����������ת�� ����ļ��� �Ƿ������ݶ�ȡ �Ƿ�رջ�ͼ����(���ڼ���ImGui)
		void solution(vector<int> speeds = vector<int>(), string outfile = "./outdata/outcome", bool check = false, bool closeimg = true)
		{
			vector<double> copy(speeds.size());
			for (int i = 0; i < copy.size(); ++i) copy[i] = speeds[i];
			solution(copy, outfile, check, closeimg);
		}
		void solution(vector<double> speeds, string outfile = "./outdata/outcome", bool check = false, bool closeimg = true)
		{
			if (check) cout << "��ͬԤѡ����:" << _mtcls.size() << endl;
			if (outfile.find("./outdata/") == string::npos) outfile = "./outdata/" + outfile;
			std::ofstream output(outfile + ".txt", std::ios::trunc | std::ios::binary);
			xlnt::workbook wb;
			int beginrow = 1;
			for (auto& mtl : _mtcls) {
				mtl.getSurgeLineP();

				if (check) {
					cout << endl << endl;
					cout << "ת��: ";
					for (auto& e : mtl.getTClines()) cout << e._speed << " "; cout << endl;
					cout << "��������: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_flow << " "; cout << endl;
					cout << "����ѹ��: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_pressure_ratio << " "; cout << endl;
					cout << "����Ч��: ";
					for (auto& e : mtl.getTClines()) cout << e._surge_efficiencies << " "; cout << endl;
				}

				// ������ת�ٵ�������
				for (auto speed : speeds) {
					if(speed != 0.0) mtl.extrapolation(speed);
				}

				wstring img = utf8_to_wstring(mtl.preRotation());
				mtl.drawGraph(3, img, closeimg);	// ����-ѹ��	
				mtl.drawGraph(5, img, closeimg);	// ����-Ч��
				//system("pause");

				xlnt::worksheet ws = wb.active_sheet();
				ws.cell(1, beginrow++).value(mtl.preRotation());
				beginrow = mtl.saveExcelFile(wb, beginrow) + 1;
				mtl.saveFile(output);
				cout << endl;
			}
			output.close();
			wb.save(outfile + ".xlsx");
			LOG(NOTICE, "�����ļ�: " + outfile);
		}

		void readDataFromFile(string file, bool check = false)
		{
			std::ifstream input(file.c_str());
			string tmp;
			while (std::getline(input, tmp)) {
				if (check) cout << "----Ԥ��ת: " << utf8_to_ansi(tmp) << endl;

				_mtcls.push_back(MultiTurbineCharLine(_speed_design));
				auto& tclines = _mtcls.back();
				auto pos = tmp.find("\t");
				tclines.preRotation() = tmp.substr(0, pos);
				tclines.readDataFromFile(input, check);
			}
			input.close();
		}

		void readDataFromExcel(string file, bool check = false)
		{
			xlnt::workbook wb;
			try { wb.load(file); }
			catch (const std::exception&) { LOG(FATAL, "����Э��:ʹ�ô�����excel���,�ο�example.xlsx"); throw; }
			catch (...) {throw;}

			for (const xlnt::worksheet& ws : wb)
			{
				_mtcls.push_back(MultiTurbineCharLine(_speed_design));
				auto& tclines = _mtcls.back();
				tclines.preRotation() = ws.title();
				if (check) cout << "----Ԥ��ת: " << utf8_to_ansi(ws.title()) << endl;
				tclines.readDataFromExcel(ws, check);
			}
		}

		void checkExtraError()
		{
			for (auto& tclines : _mtcls) {
				tclines.checkExtraError(tclines.preRotation());
				cout << endl;
			}
		}

	private:
		// todo...
	};
}

