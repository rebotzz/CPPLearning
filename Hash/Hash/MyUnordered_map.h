#pragma once
#include "HashTable.h"

namespace kozen
{
	template<class Key, class Value, class Hash = HashFunc<Key>>
	class unordered_map
	{
		template<class Key, class Value>
		struct GetKeyofV
		{
			const Key& operator()(const pair<const Key, Value>& data)
			{
				return data.first;
			}
		};
	public:
		typedef typename HashTable<Key, pair<const Key, Value>, GetKeyofV<Key, Value>, Hash>::iterator iterator;

		iterator begin()
		{
			return _table.begin();
		}

		iterator end()
		{
			return _table.end();
		}

		pair<iterator, bool> insert(const pair<Key, Value>& data)
		{
			return _table.Insert(data);
		}

		iterator find(const Key& key)
		{
			return _table.Find(key);
		}

		bool erase(const Key& key)
		{
			return _table.Erase(key);
		}

		Value& operator[](const Key& key)
		{
			pair<iterator, bool> ret = _table.Insert(make_pair(key, Value()));
			return ret.first->second;
		}

		int size()
		{
			return _table.size();
		}

	private:
		HashTable<Key, pair<const Key, Value>, GetKeyofV<Key, Value>, Hash> _table;
	};
}