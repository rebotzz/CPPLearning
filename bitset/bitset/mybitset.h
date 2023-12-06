#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// λͼ: ��ϣӳ���һ��Ӧ��
// ��ÿһ������λ����ʶһ��״̬,����ʡ�ռ� 
//
namespace kozen
{
	// ������ģ�����
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_table.resize(N / 8 + 1,0);	// 1 char = 8 bit
		}

		// posλ��Ϊ1
		void set(size_t pos)
		{
			size_t i = pos / 8;
			size_t j = pos % 8;

			_table[i] |= (1 << j);	//����:��λ���λ�ƶ�
		}

		// posλ��Ϊ0
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
		// size_tû�и���,����i > 0
		for (size_t i = bs.size() - 1; i > 0; --i)
		{
			out << bs.test(i);
		}
		out << bs.test(0) << endl;
		return out;
	}
}
