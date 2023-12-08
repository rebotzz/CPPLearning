#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "mybitset.h"
#include <time.h>
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
// 10^10 / (10^9) = 10G��int, ÿ��int��bit���,��: 10G / 8 = 1.25G, �ڴ��������
// ��ʱ�����з��ļ�
class question2
{
	void sulotion()
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

		// ����: ȥ��,�ҽ���
		unordered_set<int> sv1(v1.begin(), v1.end());
		unordered_set<int> sv2(v2.begin(), v2.end());
		vector<int> out;


	}



private:
	// ����1.1G�Ŀռ�
	kozen::bitset<1100000000> _bs1;
	kozen::bitset<1100000000> _bs2;
};

// 2.5 (��Ŀ����)�������ļ����ֱ���100000�ڸ�����������ֻ��1G�ڴ棬����ҵ������ļ�������
// ��ʱ10^13 /  (10^9) = 10000G��int, ÿ��int��bit���,��: 10000G / 8 = 1250G, �ڴ治��������
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
			if(!v1.empty())
			{
				auto& v2 = minfile2[i++];
				unordered_set<int> st1(v1.begin(), v1.end());
				unordered_set<int> st2(v2.begin(), v2.end());
				if(!v2.empty())
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


int main()
{
	//question1().solution();
	//question2().solution();
	question3().solution();

	return 0;
}