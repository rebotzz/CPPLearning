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
			_table.resize(N / 8 + 1, 0);	// 1 char = 8 bit; Ҳ������λ����:N>>3 + 1;
		}

		// posλ��Ϊ1
		void set(size_t pos)
		{
			if (pos > size())
				return;

			size_t i = pos / 8;
			size_t j = pos % 8;

			_table[i] |= (1 << j);	//����:��λ���λ�ƶ�
		}

		// posλ��Ϊ0
		void reset(size_t pos)
		{
			if (pos > size())
				return;

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
			if (pos > size())
				return false;

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


	// �ַ����Ĺ�ϣӳ�亯��
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
	// Ԫ�ظ���:N,�����ݻ�����:X;
	template<size_t N, size_t X = 5, class T = string,
		class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
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
			// ����λ��ֻҪһ������,��һ������
			size_t hs1 = Hash1()(str) % _bs.size();
			if (_bs.test(hs1) == false)
				return false;

			size_t hs2 = Hash2()(str) % _bs.size();
			if (_bs.test(hs2) == false)
				return false;

			size_t hs3 = Hash3()(str) % _bs.size();
			if (_bs.test(hs3) == false)
				return false;

			// ����λ�ö�Ϊ1�ſ�����,���ǲ���ȷ��
			return true;
		}

	private:
		bitset<N* X> _bs;
	};


	// ������¡������,֧��ɾ��
	template<size_t N, size_t X = 5, class T = string,
		class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
	class CountBloomFilter
	{
	public:
		void insert(const string& str)
		{
			// ����Ӧ��ϣӳ��λ�ü���+1
			size_t hs1 = Hash1()(str) % _bs1.size();
			size_t hs2 = Hash2()(str) % _bs1.size();
			size_t hs3 = Hash3()(str) % _bs1.size();

			cout << hs1 << " " << hs2 << " " << hs3 << endl;
			addone(hs1);
			addone(hs2);
			addone(hs3);
		}

		bool test(const string& str)
		{
			// ����λ��ֻҪһ������,��һ������
			size_t hs1 = Hash1()(str) % _bs1.size();
			if (count(hs1) == 0)
				return false;

			size_t hs2 = Hash2()(str) % _bs1.size();
			if (count(hs2) == 0)
				return false;

			size_t hs3 = Hash3()(str) % _bs1.size();
			if (count(hs3) == 0)
				return false;

			// ����λ�ö�Ϊ1�ſ�����,���ǲ���ȷ��
			return true;
		}

		void erase(const string& str)
		{
			// ����Ӧ��ϣӳ��λ�ü���-1
			size_t hs1 = Hash1()(str) % _bs1.size();
			size_t hs2 = Hash2()(str) % _bs1.size();
			size_t hs3 = Hash3()(str) % _bs1.size();

			cout << hs1 << " " << hs2 << " " << hs3 << endl;
			subone(hs1);
			subone(hs2);
			subone(hs3);
		}

	private:
		void addone(size_t pos)
		{
			// ...0
			if (_bs1.test(pos) == false)
			{
				_bs1.set(pos);
			}
			// ...01	==> ...10	
			else if (_bs2.test(pos) == false)
			{	  
				_bs2.set(pos);
				_bs1.reset(pos);
			}
			// ...011  ==> ...100
			else if (_bs3.test(pos) == false)
			{
				_bs3.set(pos);
				_bs2.reset(pos);
				_bs1.reset(pos);
			}
		}

		void subone(size_t pos)
		{
			// ...1
			if (_bs1.test(pos))
			{
				_bs1.reset(pos);
			}
			// ...10  ==> ...01
			else if (_bs2.test(pos))
			{	
				_bs2.reset(pos);
				_bs1.set(pos);
			}
			// ...100  ==> ...011
			else if (_bs3.test(pos))
			{
				_bs3.reset(pos);
				_bs2.set(pos);
				_bs1.set(pos);
			}
		}

		// ͳ��pos��������
		size_t count(size_t pos)
		{
			size_t cnt = 0;
			if (_bs1.test(pos))
			{
				cnt++;
			}
			if (_bs2.test(pos))
			{
				cnt += 2;
			}
			if (_bs3.test(pos))
			{
				cnt += 4;
			}

			return cnt;
		}

	private:
	//public:
		bitset<N* X> _bs1;	// �ܼ�¼8��״̬,������0,���ڸ���1,2,3...,7
		bitset<N* X> _bs2;	// �����Ҫ���Ӽ�¼����,����_bs
		bitset<N* X> _bs3;
	};
}
