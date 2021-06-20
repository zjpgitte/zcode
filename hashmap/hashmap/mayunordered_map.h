#include "hashtable.hpp"

namespace close
{
	
	template <class K, class V>
	class myunordered_map
	{
		struct MAPKOT
		{
			const K& operator ()(const pair<K, V>& k)
			{
				return k.first;
			}
		};
	private:
		HashTable<K, pair<K, V>, MAPKOT> _ht;
	public:
		
		bool insert(const pair<K, V>& p)
		{
			return _ht.insert(p);
		}

		int find(const K& key)
		{
			return _ht.find(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

		void swap(myunordered_map& m)
		{
			_ht.swap(m._ht);
		}

	};
}
