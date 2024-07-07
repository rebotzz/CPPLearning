#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "mybitset.h"
#include <time.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>
using namespace std;

// λͼӦ��
//
// 1. ����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�������
// λͼ����
// 100�� = 10^10, 1G = 8bit * 10^9 �����λ��
// 10^10 / (8bit * 10^9) = 10 / 8 = 1.25 G�ռ�
class question1
{
public:

	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 100000 - 1;
		vector<int> v(N + 1);
		for (int i = 0; i < N; ++i)
		{
			int num = rand() % 10000;
			v.push_back(num);
			insert(num);
		}

		insert(19999);
		v.push_back(19999);

		for (auto e : v)
		{
			if (testone(e))
			{
				cout << e << " ";
			}
		}
		cout << "\n";

	}

	void insert(int val)
	{
		size_t pos = val % _bs1.size();
		addone(pos);
	}

	bool testone(int val)
	{	// 01
		size_t pos = val % _bs1.size();
		return _bs1.test(pos) && !_bs2.test(pos);
	}

private:
	void addone(size_t pos)
	{
		// ...00
		if (_bs1.test(pos) == false)
		{
			_bs1.set(pos);
		}
		else if (_bs2.test(pos) == false)
		{	// ...10
			_bs2.set(pos);
			_bs1.reset(pos);
		}
		else // ...11
		{
			_bs1.set(pos);
			_bs2.set(pos);
		}
	}
private:
	// ������λͼ��ʾ����:0,1,2,3...
	kozen::bitset<100000> _bs1;
	kozen::bitset<100000> _bs2;
};

// 2. �������ļ����ֱ���100�ڸ�����������ֻ��1G�ڴ棬����ҵ������ļ�������
// 1G = 2^10 * 2^10 * 2^10 * 8 = 8 * 2^30 = 8,589,934,592 bit Լ���� 8*10^9
// 100�ڸ��� = 100 * 10^8; ��Ӧ����λ���: 10,000,000,000 bit Լ���� 10*10^9
// ÿ��int��bit���,��: 10 / 8 = 1.25G, �ڴ��������
// ��ʱ�����з��ļ�		���ݷ�Χ < ���ݸ��� -- ѡ�����ݷ�Χ
// ��������Ϊint, ���ݷ�Χ -2^31 ~ 2^31 - 1; �ܸ���2^32, 2^32 / (8 * 2^30(��2^33))  Լ0.5G
// ÿ��int��bit���: Լ0.5G ��Ҫ����bitλ����: 0.5*2^33 = 4,294,967,296
class question2
{
public:
	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 30000;		// ���ݸ���
		int modu = 1000000;	// ȡģ��
		vector<int> v1;		//��ǰresize�ᵼ��Ĭ��ֵ0������
		vector<int> v2;
		v1.reserve(N);		//reserve��ǰ�����ݻ�,������ʼ��
		v2.reserve(N);

		// �����ļ�,�������Ǵ��ļ���ȡ
		for (int i = 0; i < N; ++i)
		{
			int num = (rand() + i) % modu;
			//cout << num << " ";
			v1.push_back(num);
		}
		cout << endl;
		for (int i = 0; i < N; ++i)
		{
			int num = (rand() + i) % modu;
			//cout << num << " ";
			v2.push_back(num);
		}
		cout << endl;

		// �ҽ���: ��������������ļ�
		vector<int> out;
		for (auto e : v1)
		{
			// ��int --> size_t һһӳ��,�Ҳ����ϣ��ͻ
			_bs.set((size_t)e);
		}
		for (auto e : v2)
		{
			if (_bs.test((size_t)e))
			{
				out.push_back(e);
				//cout << e << " ";
			}
		}
		cout << endl;
		cout << "-----------" << endl;

		cout << "�������ݸ���:" << endl;
		cout << out.size() << endl;

		//for (auto e : out)
		//{
		//	cout << e << " ";
		//}
		//cout << endl << endl;

		//system("pause");

	}



private:
	// Լ0.5G ��Ҫ����bitλ����: 0.5*2^33 = 4294967296
	kozen::bitset<4400000000> _bs;
};

// 2.5 (��Ŀ����)�������ļ����ֱ���100000�ڸ�����(��������)������ֻ��1G�ڴ棬����ҵ������ļ�������
// �ڴ治��������,����������ռ�ռ�Ҳ���ܱȽϴ�
// ��ʱ�����з��ļ�
class question2_2
{
	// ����:�и��ļ�,ʹ���ڴ���Դ���
	// 1.��ͨ�����и�,��Ҫ1->n, 1���ļ�Ҫ��n���ļ��ȶ�
	// 
	// 2.��ϣ�и�,���չ�ϣӳ���и�,ֻ��1->1, һ���ļ�ֻ�úͶ�Ӧ�Ĺ�ϣ�ļ��ȶ�
	// ��������:�и����,�еĳ���:
	// a.�����ظ����³������� -- ����setȥ��,�ܴ��¾ͼ�������
	// b.�����ظ����³������� -- �޸��и����,����ϣ����,ֱ�����и�ΪС�ļ�
public:
	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 10000;		// ���ݸ���
		int modu = 500000;	// ȡģ��
		vector<int> v1;		//��ǰresize�ᵼ��Ĭ��ֵ0������
		vector<int> v2;
		v1.reserve(N);		//reserve��ǰ�����ݻ�,������ʼ��
		v2.reserve(N);
		// �����ļ�
		for (int i = 0; i < N; ++i)
		{
			int num = (rand() + i) % modu;
			//cout << num << " ";
			v1.push_back(num);
		}
		cout << endl;
		for (int i = 0; i < N; ++i)
		{
			int num = (rand() + i) % modu;
			//cout << num << " ";
			v2.push_back(num);
		}
		cout << endl;

		cout << "------------------" << endl;

		//// ������,����
		//sort(v1.begin(), v1.end());
		//sort(v2.begin(), v2.end());
		//for (auto num : v1)
		//{
		//	cout << num << " ";
		//}
		//cout << endl;
		//for (auto num : v2)
		//{
		//	cout << num << " ";
		//}
		//cout << endl;
		//cout << "------------------" << endl;

		//// ����: ȥ��,�ҽ���
		//unordered_set<int> sv1(v1.begin(), v1.end());
		//unordered_set<int> sv2(v2.begin(), v2.end());
		//vector<int> out;
		//for (int e : sv2)
		//{
		//	if (sv1.find(e) != sv1.end())
		//		out.push_back(e);
		//}
		//cout << out.size() << endl;
		//for (auto e : out)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

		// ��ϣ�з�
		int file_count = 11;	//���������
		vector<vector<int>> minfile1(file_count);
		vector<vector<int>> minfile2(file_count);
		// lambda,��ϣ��������
		auto hash = [file_count](int val)->size_t {
			return val % file_count;
			};
		// �з�
		for (auto e : v1)
		{
			size_t file_pos = hash(e);
			minfile1[file_pos].push_back(e);
		}
		for (auto e : v2)
		{
			size_t file_pos = hash(e);
			minfile2[file_pos].push_back(e);
		}

		// �鿴�зֺ�ÿ���ļ����ݸ���
		cout << "ÿ���ļ����ݸ���:" << endl;
		for (auto& v : minfile1)
		{
			//sort(v.begin(), v.end());
			cout << v.size() << " ";
		}
		cout << endl;

		for (auto& v : minfile2)
		{
			//sort(v.begin(), v.end());
			cout << v.size() << " ";
		}
		cout << endl;
		cout << "---------------" << endl;

		// ȥ��,�ҽ���,ʹ��set
		vector<int> ret;
		int i = 0;
		for (auto& v1 : minfile1)
		{
			// ע��������ļ������;ע��Ĭ�ϳ�ʼ����0����� -- ����ǰ���ٿռ��ʼ��,ʹ��reserve
			if (!v1.empty())
			{
				auto& v2 = minfile2[i++];
				unordered_set<int> st1(v1.begin(), v1.end());
				unordered_set<int> st2(v2.begin(), v2.end());
				if (!v2.empty())
				{
					for (auto num : st2)
					{
						if (st1.find(num) != st1.end())
							ret.push_back(num);
					}
				}
			}
			else
			{
				++i;
			}
		}

		cout << "intersection count:" << endl;
		cout << ret.size() << endl;

		//// ��ӡ����
		//for (auto e : ret)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

	}

};

// 3. λͼӦ�ñ��Σ�1���ļ���100�ڸ�int��1G�ڴ棬����㷨�ҵ����ִ���������2�ε���������
// ���Ƶ�1��
class question3
{
public:

	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 100000 - 1;
		vector<int> v(N + 1);
		for (int i = 0; i < N; ++i)
		{
			int num = rand() % 10000;
			v.push_back(num);
			insert(num);
		}

		insert(19999);
		insert(19999);
		v.push_back(19999);

		for (auto e : v)
		{
			if (test_two(e))
			{
				cout << e << " ";
			}
		}
		cout << "\n";

	}

	void insert(int val)
	{
		size_t pos = val % _bs1.size();
		addone(pos);
	}

	bool test_two(int val)
	{	// 10
		size_t pos = val % _bs1.size();
		return !_bs1.test(pos) && _bs2.test(pos);
	}

private:
	void addone(size_t pos)
	{
		// ...00
		if (_bs1.test(pos) == false)
		{
			_bs1.set(pos);
		}
		else if (_bs2.test(pos) == false)
		{	// ...10
			_bs2.set(pos);
			_bs1.reset(pos);
		}
		else // ...11
		{
			_bs1.set(pos);
			_bs2.set(pos);
		}
	}
private:
	// ������λͼ��ʾ����:0,1,2,3...
	kozen::bitset<100000> _bs1;
	kozen::bitset<100000> _bs2;
};


// ��ϣ�и�
// ��һ������100G��С��log file, log�д���IP��ַ, ����㷨�ҵ����ִ�������IP��ַ��
// ������������ͬ������ҵ�top K��IP�����ֱ����Linuxϵͳ����ʵ�֣�
class question4
{
	// �ļ�����,��Ҫ��ϣ�и�,��������:string
	// �зֺ���mapͳ�ƴ���
public:
	void solution()
	{
		srand((unsigned int)time(0));
		int N = 5000000;
		vector<string> v;
		v.reserve(N);
		// ����ip��ַ
		for (int i = 0; i < N; ++i)
		{
			string s = "218.26.";
			for (int j = 0; j < 3; ++j)
			{
				int num = rand() % 10;
				s += ('0' + num);
			}
			s += '.';
			for (int j = 0; j < 3; ++j)
			{
				int num = rand() % 10;
				s += ('0' + num);
			}

			v.push_back(s);
		}

		// ������
		string ip = "218.26.541.167";
		for(int i = 0; i < 20; ++i)
			v.push_back(ip);


		//// ��ӡip
		//for (auto& e : v)
		//{
		//	cout << e << endl;
		//}
		//cout << endl << "---------------" << endl;

		// �и��ļ�
		int div = 29;	// �и����
		auto hash = [](const string& str)->size_t {
			size_t index = 0;
			for (char ch : str)
			{
				index += ch * 31;
			}
			return index;
			};

		vector<vector<string>> file(div);	// div��С�ļ�
		for (string& s : v)
		{
			size_t fileid = hash(s) % div;
			file[fileid].push_back(s);
		}

		// �鿴ÿ���ļ�ip����
		cout << "ip count/file:" << endl;
		for (auto& e : file)
		{
			cout << e.size() << " ";
		}
		cout << endl << "-----------------" << endl;


		// �º���,С�ѱȽ�
		struct Greater
		{
			bool operator()(const pair<string, int>& x, const pair<string, int>& y)
			{
				return x.second > y.second;
			}
		};

		// �ҵ����ִ�������ip; 
		string maxip;
		int max = 0;
		int K = 10;
		unordered_map<string, int> m;
		// ��topK ��ip: С��,���ȼ�����: ��Сֵ�ٶѶ�,�ǿ��Ź�,������Ĳ��ܽ���
		priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> topK;

		for (auto& vstr : file)
		{
			for (string& s : vstr)
			{
				// ��ʼ��С��
				if (topK.size() < K)
				{
					topK.push(make_pair(s, 1));
				}

				int cnt = ++m[s];

				// ���ִ�������ip
				if (cnt > max)
				{
					max = cnt;
					maxip = s;
				}

			}

			// ����ȿ��Ź���,����,�����Ź�
			// ���ﲻ�ܰ���pair<>��ֵ�Ե�Ĭ�Ϲ���Ƚ�		
			auto it = m.begin();
			while (it != m.end())
			{	// debug: �ظ��ַ���ռ��λ�� -- ���:һ����ϣ�и��ļ�ͳ�ƽ�����topK
				if ((it->second) > topK.top().second)	
				{
					topK.pop();
					string tmp(it->first);
					topK.push(make_pair(tmp, it->second));
				}
				++it;
			}
			
			m.clear();
		}

		// ���ִ�������ip:
		cout << "maxip" << endl;
		cout << maxip << ": " << max << endl << "-------------" << endl;;

		// topK��ip:
		cout << "ip topK:" << endl;
		while (!topK.empty())
		{
			auto& e = topK.top();
			cout << e.first << ": " << e.second << endl;
			topK.pop();
		}
		cout << endl;
		

	}

};


void test_queue()
{
	priority_queue<int, vector<int>, greater<int>> que;
	int a[] = { 1,2,3,4,5 };
	for (auto e : a)
	{
		que.push(e);
	}

	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;


	struct Greater
	{
		bool operator()(const pair<string, int>& x, const pair<string, int>& y)
		{
			return x.second > y.second;
		}
	}; 
	priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> topK;

	topK.push(make_pair("baiduyun", 1));
	topK.push(make_pair("aliyun", 1));
	topK.push(make_pair("tecentyun", 1));
	topK.push(make_pair("mihoyo", 1));

	// topK��ip:
	cout << "ip topK:" << endl;
	while (!topK.empty())
	{
		auto& e = topK.top();
		cout << e.first << ": " << e.second << endl;
		topK.pop();
	}
	cout << endl;

}


// ��¡������
// 1. �������ļ����ֱ���100�ڸ�query������ֻ��1G�ڴ棬����ҵ������ļ��������ֱ����
// ��ȷ�㷨�ͽ����㷨
class question5
{
	// ����question2_2, �����㷨:ʹ�ò�¡������
public:
	void solution()
	{
		srand((unsigned int)time(0));
		int N = 1000000;
		int word_size = 4;
		// �����ļ�,����string
		vector<vector<string>> tmp(2);
		vector<string>& v1 = tmp[0];
		vector<string>& v2 = tmp[1];
		v1.reserve(N);		//reserve��ǰ�����ݻ�,������ʼ��
		v2.reserve(N);
		for (int vid = 0; vid < 2; ++vid)
		{
			vector<string>& v = tmp[vid];
			for (int i = 0; i < N; ++i)
			{
				string s = "what is your ";
				for (int j = 0; j < word_size; ++j)
				{
					char ch = rand() % 256;
					s += ch;
				}
				s += '?';
				v.push_back(s);
			}
		}


		//// ������
		string ip = "what is your id?";
		for (int i = 0; i < 20; ++i)
			v1.push_back(ip), v2.push_back(ip);


		//// ��ӡ
		//for (auto& e : v1)
		//{
		//	cout << e << endl;
		//}
		//cout << endl << "---------------" << endl;
		//for (auto& e : v2)
		//{
		//	cout << e << endl;
		//}
		//cout << endl << "---------------" << endl;

		// �и��ļ�
		int div = 53;	// �и����
		auto hash = [](const string& str)->size_t {
			size_t index = 0;
			for (char ch : str)
			{
				index += ch * 31;
			}
			return index;
			};

		vector<vector<string>> file1(div);	// div��С�ļ�
		vector<vector<string>> file2(div);	
		for (string& s : v1)
		{
			size_t fileid = hash(s) % div;
			file1[fileid].push_back(s);
		}
		for (string& s : v2)
		{
			size_t fileid = hash(s) % div;
			file2[fileid].push_back(s);
		}

		// �鿴ÿ���ļ�����
		cout << "count/file:" << endl;
		for (auto& e : file1)
		{
			cout << e.size() << " ";
		}
		for (auto& e : file2)
		{
			cout << e.size() << " ";
		}
		cout << endl << "-----------------" << endl;


		// �ҽ���
		unordered_set<string> ret;
		int i = 0;
		for (auto& v1 : file1)
		{
			if (!v1.empty())
			{
				// v1���벼¡������
				// 1G = 2^10 * 2^10 * 2^10 * 8 = 8 * 2^30 = 8,589,934,592 bit
				// 100�ڸ��� = 100 * 10^8; ��Ӧ����λ���: 10,000,000,000 bit
				// �и���53��,ƽ��ÿ��0.01G                   188,679,245 bit		
				// 1<<28 = 2^28								  268,435,456
				kozen::BloomFilter<1<<28> bf;
				for (string& s : v1)
				{
					bf.insert(s);
				}

				auto& v2 = file2[i++];
				for (string& s : v2)
				{
					if(bf.test(s))
					{
						ret.insert(s);
					}
				}
			}
			else
			{
				++i;
			}
		}

		cout << "intersection count:" << endl;
		cout << ret.size() << endl << "--------------" << endl;

		// ��ӡ����
		//for (auto e : ret)
		//{
		//	cout << e << endl;
		//}
		//cout << endl;

	}
};


int main()
{
	//question1().solution();
	//question2().solution();
	//question2_2().solution();
	//question3().solution();
	//question4().solution();
	//test_queue();
	//question5().solution();

	return 0;
}