#pragma once
#include "HashTable.h"


namespace kozen
{
	template<class T, class Hash = HashFunc<T>>
	class unordered_set
	{
		template<class T>
		struct GetKeyofV
		{
			const T& operator()(const T& data)
			{
				return data;
			}
		};

	public:
		typedef typename HashTable<T, T, GetKeyofV<T>, Hash>::const_iterator iterator;

		iterator begin()
		{
			return _table.begin();
		}

		iterator end()
		{
			return _table.end();
		}

		pair<iterator, bool> insert(const T& key)
		{
			return _table.Insert(key);
		}

		bool erase(const T& key)
		{
			return _table.Erase(key);
		}

		iterator find(const T& key)
		{
			return _table.Find(key);
		}

		int size()
		{
			return _table.size();
		}

		size_t count(const T& key)
		{
			return _table.Count(key);
		}

		void clear()
		{
			_table.Clear();
		}

		void swap(unordered_set<T, Hash>& set)
		{
			_table.Swap(set._table);
		}

	private:
		HashTable<T, T, GetKeyofV<T>, Hash> _table;
	};

}
