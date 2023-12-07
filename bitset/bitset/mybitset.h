#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// λͼ: ��ϣӳ���һ��Ӧ��
// ��ÿһ������λ����ʶһ��״̬,����ʡ�ռ� 
// ��¡������:���ֹ�ϣӳ���Ӧ��,�ײ�λͼ
// 
namespace kozen
{
	// ������ģ�����
	template<size_t N>
	class bitset	// λͼ
	{
	public:
		bitset()
		{
			_table.resize(N / 8 + 1, 0);	// 1 char = 8 bit
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

	template<class T>
	class HashFunc1
	{
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	// ��ϣӳ��1
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

	// ��ϣӳ��2
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

	// ��ϣӳ��3
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


	// ��¡������:���ֹ�ϣӳ�� + λͼ  -- ����ֻӳ���ַ���
	template<size_t N, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
	class BloomFilter
	{
	public:

		void insert(const string& str)
		{
			// ����Ӧ��ϣӳ��λ������Ϊ1
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			_bs.set(hs1);
			_bs.set(hs2);
			_bs.set(hs3);
		}

		bool test(const string& str)
		{
			// ����λ�ö�Ϊ1�ſ�����,���ǲ���ȷ��
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			return _bs.test(hs1) && _bs.test(hs2) && _bs.test(hs3);
		}

		bool non_test(const string& str)
		{
			// ����λ��ֻҪһ������,��һ������
			size_t hs1 = Hash1()(str) % _bs.size();
			size_t hs2 = Hash2()(str) % _bs.size();
			size_t hs3 = Hash3()(str) % _bs.size();

			return !_bs.test(hs1) || !_bs.test(hs2) || !_bs.test(hs3);
		}

	private:
		bitset<N> _bs;
	};

}
