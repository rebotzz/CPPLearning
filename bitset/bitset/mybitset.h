#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 位图: 哈希映射的一种应用
// 用每一个比特位来标识一种状态,更节省空间 
// 布隆过滤器:多种哈希映射的应用,底层位图
// 
namespace kozen
{
	// 非类型模板参数
	template<size_t N>
	class bitset	// 位图
	{
	public:
		bitset()
		{
			_table.resize(N / 8 + 1, 0);	// 1 char = 8 bit
		}

		// pos位置为1
		void set(size_t pos)
		{
			size_t i = pos / 8;
			size_t j = pos % 8;

			_table[i] |= (1 << j);	//左移:低位向高位移动
		}

		// pos位置为0
		void reset(size_t pos)
		{
			size_t i = pos / 8;
			size_t j = pos % 8;

			_table[i] &= ~(1 << j);
		}

		size_t size()
		{
			return _table.size() * 8;
		}

		bool test(size_t pos)
		{
			size_t i = pos / 8;
			size_t j = pos % 8; 
			return (_table[i] >> j) & 1;
		}

	private:
		vector<char> _table;
	};

	template<size_t N>
	ostream& operator<<(ostream& out, bitset<N>& bs)
	{	
		// size_t没有负数,所以i > 0
		for (size_t i = bs.size() - 1; i > 0; --i)
		{
			out << bs.test(i);
		}
		out << bs.test(0) << endl;
		return out;
	}

	template<class T>
	class HashFunc1
	{
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	// 哈希映射1
	class BKDRHash
	{
	public:
		size_t operator()(const string& str)
		{
			size_t hashi = 0;
			for (char ch : str)
			{
				hashi += ch * 31;
			}
			return hashi;
		}
	};

	// 哈希映射2
	class APHash
	{
	public:
		size_t operator()(const string& str)
		{
			size_t hash = 0;
			size_t ch;
			for (int i = 0; i < str.size(); i++)
			{
				ch = str[i];
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	// 哈希映射3
	class DJBHash
	{
	public:
		size_t operator()(const string& str)
		{
			unsigned int hash = 5381;
			for (char ch : str)
			{
				hash += (hash << 5) + (ch++);

			}
			return (hash & 0x7FFFFFFF);
		}
	};


	// 布隆过滤器:多种哈希映射 + 位图  -- 这里只映射字符串
	template<size_t N, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
	class BloomFilter
	{
	public:

		void insert(const string& str)
		{
			// 将对应哈希映射位置设置为1
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			_bs.set(hs1);
			_bs.set(hs2);
			_bs.set(hs3);
		}

		bool test(const string& str)
		{
			// 三个位置都为1才可能在,但是不能确定
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			return _bs.test(hs1) && _bs.test(hs2) && _bs.test(hs3);
		}

		bool non_test(const string& str)
		{
			// 三个位置只要一个不在,就一定不在
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			return !_bs.test(hs1) || !_bs.test(hs2) || !_bs.test(hs3);
		}

	private:
		bitset<N> _bs;
	};

}
