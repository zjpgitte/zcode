#pragma once
#include "hashtable.h"

namespace open
{
	template <class K, class V>
	class unordered_map
	{
	public:
		struct MAPKOT
		{
			const K& operator () (const pair<const K, V>& k)
			{
				return k.first;
			}
		};

	public:
		typedef HashTable<K, pair<const K, V>, MAPKOT> HashTable;

		typedef typename HashTable::Iterator iterator;

	public:
		
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<const K, V> t)
		{
			return _ht.insert(t);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

		iterator find(const K& key)
		{
			return iterator(_ht.find(key), &_ht);
		}

	private:
		HashTable _ht;
	};
}