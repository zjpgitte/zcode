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

// �º���
template <class K>
struct HASH
{
	size_t operator ()(const K& key, int size) //���ַ
	{
		return key % size;
	}
};

namespace close // ��ɢ�н����ͻ
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
				// ����
				int newsize = 2 * _table.size();
				// ����֮�������¼���ÿ��Ԫ���ڱ��е���λ��
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
			
			// �ߵ���˵����ϣ����û����val�ظ����
			int begin = hashfunc(kot(val)); //���ݹ�ϣ��������val��ַ
			int i = 0;
			int index = begin + i;
			while (_table[index]._state == EXISTS)
			{
				i++;
				index = (begin + i) % _table.size();
			}

			// �ҵ�EMPTYλ�û�DELETEλ�ÿ��Բ���
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
		int _size;// ʵ�ʴ洢��Ԫ�ظ���
	};

}