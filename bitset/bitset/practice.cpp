#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "mybitset.h"
#include <time.h>
using namespace std;

// 位图应用
//
// 1. 给定100亿个整数，设计算法找到只出现一次的整数？
// 位图处理
// 100亿 = 10^10, 1G = 8bit * 10^9 个标记位置
// 10^10 / (8bit * 10^9) = 10 / 8 = 1.25 G空间
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
	// 用两个位图表示个数:0,1,2,3...
	kozen::bitset<100000> _bs1;
	kozen::bitset<100000> _bs2;
};

// 2. 给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集？
// 10^10 / (10^9) = 10G的int, 每个int用bit标记,则: 10G / 8 = 1.25G, 内存可以容纳
// 此时不用切分文件
class question2
{
	void sulotion()
	{
		srand((unsigned int)time(NULL));
		int N = 10000;		// 数据个数
		int modu = 500000;	// 取模数
		vector<int> v1;		//提前resize会导致默认值0的问题
		vector<int> v2;
		v1.reserve(N);		//reserve提前开辟容积,但不初始化
		v2.reserve(N);
		// 两个文件
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

		// 测试: 去重,找交集
		unordered_set<int> sv1(v1.begin(), v1.end());
		unordered_set<int> sv2(v2.begin(), v2.end());
		vector<int> out;


	}



private:
	// 开辟1.1G的空间
	kozen::bitset<1100000000> _bs1;
	kozen::bitset<1100000000> _bs2;
};

// 2.5 (题目变形)给两个文件，分别有100000亿个整数，我们只有1G内存，如何找到两个文件交集？
// 这时10^13 /  (10^9) = 10000G的int, 每个int用bit标记,则: 10000G / 8 = 1250G, 内存不可以容纳
// 此时必须切分文件
class question2_2
{
	// 分析:切割文件,使得内存可以处理
	// 1.普通均匀切割,需要1->n, 1个文件要和n个文件比对
	// 
	// 2.哈希切割,按照哈希映射切割,只用1->1, 一个文件只用和对应的哈希文件比对
	// 可能问题:切割不均匀,有的超容:
	// a.大量重复导致超过容量 -- 存入set去重,能存下就继续处理
	// b.少量重复导致超过容量 -- 修改切割份数,换哈希函数,直到能切割为小文件
public:
	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 10000;		// 数据个数
		int modu = 500000;	// 取模数
		vector<int> v1;		//提前resize会导致默认值0的问题
		vector<int> v2;
		v1.reserve(N);		//reserve提前开辟容积,但不初始化
		v2.reserve(N);
		// 两个文件
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

		//// 测试用,排序
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

		//// 测试: 去重,找交集
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

		// 哈希切分
		int file_count = 11;	//最好是质数
		vector<vector<int>> minfile1(file_count);
		vector<vector<int>> minfile2(file_count);
		// lambda,哈希函数对象
		auto hash = [file_count](int val)->size_t {
			return val % file_count;
			};
		// 切分
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

		// 查看切分后每个文件数据个数
		cout << "每个文件数据个数:" << endl;
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

		// 去重,找交集,使用set
		vector<int> ret;
		int i = 0;
		for (auto& v1 : minfile1)
		{
			// 注意提出空文件的情况;注意默认初始化是0的情况 -- 不提前开辟空间初始化,使用reserve
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

		//// 打印交集
		//for (auto e : ret)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

	}

};

// 3. 位图应用变形：1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
// 类似第1题
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
	// 用两个位图表示个数:0,1,2,3...
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