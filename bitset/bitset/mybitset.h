#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 位图: 哈希映射的一种应用
// 用每一个比特位来标识一种状态,更节省空间 
//
namespace kozen
{
	// 非类型模板参数
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_table.resize(N / 8 + 1,0);	// 1 char = 8 bit
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
}
