#pragma once
#include "hashtable.h"

namespace open
{



	template <class K, class V>
	class unordered_map
	{
	public:
		typedef ListNode<pair<K, V>> Node;
		class MAPKOT
		{
			const K& operator () (const pair<const K, V>& k)
			{
				return k.first;
			}
		};
		pair<Node*, bool> insert(const pair<const K, V> t)
		{
			return _ht.insert(t);
		}

	private:
		HashTable<K, pair<const K, V>, MAPKOT> _ht;
	};
}