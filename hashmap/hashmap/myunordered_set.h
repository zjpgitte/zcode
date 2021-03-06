#include "hashtable.hpp"
namespace close
{
	template <class K>
	struct SETKOT
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	template <class K>
	class myunordered_set
	{
	public:
		bool insert(const K& key)
		{
			return _ht.insert(key);
		}

		int find(const K& key)
		{
			return _ht.find(key);
		}

		bool erase(const K& key)
		{
			return _ht.erase(key);
		}

	private:
		close::HashTable<K, K, SETKOT<K>> _ht;
	};
}