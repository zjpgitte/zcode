#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

// 仿函数
template <class K>
struct HASH
{
	size_t operator ()(const K& key, int size) //求地址
	{
		return key % size;
	}
};

namespace close // 闭散列解决冲突
{
	enum State
	{
		EMPTY,
		EXISTS,
		DELETE
	};

	template <class T>
	struct HashNode
	{
		T _t;
		State _state;
		HashNode(T t = T(), State state = EMPTY)
			:_t(t)
			, _state(state)
		{}
	};

	template <class K, class T, class KOfT, class HASHFUNC = HASH<K>>
	class HashTable
	{
	public:
	public:
		HashTable(int capacity = 3)
			:_size(0)
		{
			_table.resize(capacity);
		}

		size_t hashfunc(const K& key)
		{
			HASHFUNC hash;
			return hash(key, _table.size());
		}

		void CheckCapacity()
		{
			if (_size * 10 / _table.capacity() >= 7)
			{
				// 扩容
				int newsize = 2 * _table.size();
				// 扩容之后需重新计算每个元素在表中的新位置
				HashTable<K, T, KOfT, HASHFUNC> newhs;
				newhs._table.resize(newsize);
				for (auto& e: _table)
				{
					if (e._state == EXISTS)
					{
						newhs.insert(e._t);
					}
				}
				newhs._table.swap(_table);
			}
		}

		bool insert(const T& val)
		{
			KOfT kot;

			CheckCapacity();

			if (find(kot(val)) != -1)
			{
				return false;
			}
			
			// 走到这说明哈希表中没有与val重复结点
			int begin = hashfunc(kot(val)); //根据哈希函数计算val地址
			int i = 0;
			int index = begin + i;
			while (_table[index]._state == EXISTS)
			{
				i++;
				index = (begin + i) % _table.size();
			}

			// 找到EMPTY位置或DELETE位置可以插入
			_table[index]._state = EXISTS;
			_table[index]._t = val;
			_size++;
			return true;
		}

		int find(const K& key)
		{
			KOfT kot;
			int begin = hashfunc(key);
			int i = 0;
			int index = begin + i;
			while (_table[index]._state != EMPTY && kot(_table[index]._t) != key)
			{
				i++;
				index = (begin + i) % _table.size();
			}

			if (_table[index]._state == EMPTY)
			{
				return -1;
			}
			else
			{
				return index;
			}

		}

		bool erase(const K& key)
		{
			int index = find(key);
			if (index == -1)
			{
				return false;
			}
			_table[index]._state = DELETE;

			return true;
		}

		void swap(HashTable& ht)
		{
			_table.swap(ht._table);
			std::swap(_size, ht._size);
		}

	private:
		vector<HashNode<T>> _table;
		int _size;// 实际存储的元素个数
	};

}