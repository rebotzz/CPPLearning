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
// 1G = 2^10 * 2^10 * 2^10 * 8 = 8 * 2^30 = 8,589,934,592 bit 约等于 8*10^9
// 100亿个数 = 100 * 10^8; 对应比特位标记: 10,000,000,000 bit 约等于 10*10^9
// 每个int用bit标记,则: 10 / 8 = 1.25G, 内存可以容纳
// 此时不用切分文件		数据范围 < 数据个数 -- 选用数据范围
// 数据类型为int, 数据范围 -2^31 ~ 2^31 - 1; 总个数2^32, 2^32 / (8 * 2^30(即2^33))  约0.5G
// 每个int用bit标记: 约0.5G 需要开辟bit位个数: 0.5*2^33 = 4,294,967,296
class question2
{
public:
	void solution()
	{
		srand((unsigned int)time(NULL));
		int N = 30000;		// 数据个数
		int modu = 1000000;	// 取模数
		vector<int> v1;		//提前resize会导致默认值0的问题
		vector<int> v2;
		v1.reserve(N);		//reserve提前开辟容积,但不初始化
		v2.reserve(N);

		// 两个文件,假设这是从文件读取
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

		// 找交集: 假设这是输出到文件
		vector<int> out;
		for (auto e : v1)
		{
			// 将int --> size_t 一一映射,且不会哈希冲突
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

		cout << "交集数据个数:" << endl;
		cout << out.size() << endl;

		//for (auto e : out)
		//{
		//	cout << e << " ";
		//}
		//cout << endl << endl;

		//system("pause");

	}



private:
	// 约0.5G 需要开辟bit位个数: 0.5*2^33 = 4294967296
	kozen::bitset<4400000000> _bs;
};

// 2.5 (题目变形)给两个文件，分别有100000亿个数据(任意类型)，我们只有1G内存，如何找到两个文件交集？
// 内存不可以容纳,单个数据所占空间也可能比较大
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


// 哈希切割
// 给一个超过100G大小的log file, log中存着IP地址, 设计算法找到出现次数最多的IP地址？
// 与上题条件相同，如何找到top K的IP？如何直接用Linux系统命令实现？
class question4
{
	// 文件过大,需要哈希切割,数据类型:string
	// 切分后用map统计次数
public:
	void solution()
	{
		srand((unsigned int)time(0));
		int N = 5000000;
		vector<string> v;
		v.reserve(N);
		// 生成ip地址
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

		// 测试用
		string ip = "218.26.541.167";
		for(int i = 0; i < 20; ++i)
			v.push_back(ip);


		//// 打印ip
		//for (auto& e : v)
		//{
		//	cout << e << endl;
		//}
		//cout << endl << "---------------" << endl;

		// 切割文件
		int div = 29;	// 切割份数
		auto hash = [](const string& str)->size_t {
			size_t index = 0;
			for (char ch : str)
			{
				index += ch * 31;
			}
			return index;
			};

		vector<vector<string>> file(div);	// div个小文件
		for (string& s : v)
		{
			size_t fileid = hash(s) % div;
			file[fileid].push_back(s);
		}

		// 查看每个文件ip个数
		cout << "ip count/file:" << endl;
		for (auto& e : file)
		{
			cout << e.size() << " ";
		}
		cout << endl << "-----------------" << endl;


		// 仿函数,小堆比较
		struct Greater
		{
			bool operator()(const pair<string, int>& x, const pair<string, int>& y)
			{
				return x.second > y.second;
			}
		};

		// 找到出现次数最多的ip; 
		string maxip;
		int max = 0;
		int K = 10;
		unordered_map<string, int> m;
		// 找topK 的ip: 小堆,优先级队列: 最小值再堆顶,是看门狗,比它大的才能进门
		priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> topK;

		for (auto& vstr : file)
		{
			for (string& s : vstr)
			{
				// 初始化小堆
				if (topK.size() < K)
				{
					topK.push(make_pair(s, 1));
				}

				int cnt = ++m[s];

				// 出现次数最多的ip
				if (cnt > max)
				{
					max = cnt;
					maxip = s;
				}

			}

			// 如果比看门狗大,进门,换看门狗
			// 这里不能按照pair<>键值对的默认规则比较		
			auto it = m.begin();
			while (it != m.end())
			{	// debug: 重复字符串占用位置 -- 解决:一个哈希切割文件统计结束再topK
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

		// 出现次数最多的ip:
		cout << "maxip" << endl;
		cout << maxip << ": " << max << endl << "-------------" << endl;;

		// topK的ip:
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

	// topK的ip:
	cout << "ip topK:" << endl;
	while (!topK.empty())
	{
		auto& e = topK.top();
		cout << e.first << ": " << e.second << endl;
		topK.pop();
	}
	cout << endl;

}


// 布隆过滤器
// 1. 给两个文件，分别有100亿个query，我们只有1G内存，如何找到两个文件交集？分别给出
// 精确算法和近似算法
class question5
{
	// 类似question2_2, 近似算法:使用布隆过滤器
public:
	void solution()
	{
		srand((unsigned int)time(0));
		int N = 1000000;
		int word_size = 4;
		// 两个文件,生成string
		vector<vector<string>> tmp(2);
		vector<string>& v1 = tmp[0];
		vector<string>& v2 = tmp[1];
		v1.reserve(N);		//reserve提前开辟容积,但不初始化
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


		//// 测试用
		string ip = "what is your id?";
		for (int i = 0; i < 20; ++i)
			v1.push_back(ip), v2.push_back(ip);


		//// 打印
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

		// 切割文件
		int div = 53;	// 切割份数
		auto hash = [](const string& str)->size_t {
			size_t index = 0;
			for (char ch : str)
			{
				index += ch * 31;
			}
			return index;
			};

		vector<vector<string>> file1(div);	// div个小文件
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

		// 查看每个文件个数
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


		// 找交集
		unordered_set<string> ret;
		int i = 0;
		for (auto& v1 : file1)
		{
			if (!v1.empty())
			{
				// v1插入布隆过滤器
				// 1G = 2^10 * 2^10 * 2^10 * 8 = 8 * 2^30 = 8,589,934,592 bit
				// 100亿个数 = 100 * 10^8; 对应比特位标记: 10,000,000,000 bit
				// 切割了53分,平均每份0.01G                   188,679,245 bit		
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

		// 打印交集
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