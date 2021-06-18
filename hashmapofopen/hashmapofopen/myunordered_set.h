#pragma once
#include "hashtable.h"

#include "hashtable.h"

namespace open
{
	template <class K>
	class unordered_set
	{
		struct SETKOT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename HashTable<K, K, SETKOT> HashTable;
		typedef typename HashTable::Iterator iterator;
	public:
		
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.insert(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

	private:
		HashTable _ht;
	};
}