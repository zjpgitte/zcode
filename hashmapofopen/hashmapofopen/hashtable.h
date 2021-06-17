#pragma once
#include <iostream>
#include <vector>

using namespace std;



namespace open
{
	template <class K>
	class HASH
	{
		int operator ()(const K& key, int size)
		{
			return key % size;
		}
	};

	// 模板特化
	template<>
	class HASH<string>
	{
		int operator()(const string& s, int size)
		{
			int sum = 0;
			for (int i = 0; i < s.size(); i++)
			{
				sum = sum * 131 + s[i];
			}

			return sum % size;
		}
	};

	template <class T>
	struct ListNode
	{
		T _t;
		ListNode<T>* _next;

		ListNode(const T& t = t())
			:_t(t)
			, _next(nullptr)
		{}

	};

	template <class K, class T, class KOT, class HASHFUNC = HASH<K>>
	class HashTable
	{
	public:
		typedef ListNode<T> Node;
	public:
		HashTable(int capacity = 3)
			:_size(0)
		{
			_table.resize(capacity);
		}

		int hash(const K& key, int size)
		{
			HASHFUNC hf;
			return hf(key, size);
		}

		void check()
		{
			KOT kot;
			if (_size >= _table.capacity())
			{
				// 可以创建一个新的哈希表，遍历哈希表，调用insert()，实现代码的复用。
				//但是这里的每次insert都是一次深拷贝，都需要新开结点。
				// 可以考虑的做法是创建新的数组把原来的结点取下来挂到新数组下即可。
				int newsize = _size * 2;
				vector<Node*> newtable;
				newtable.resize(newsize);
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						//取出该节点
						Node* next = cur->_next;
						_table[i] = next;
						// 头插到新链表中
						int newindex = hash(kot(cur->_t), newsize);
						cur->_next = newtable[newindex];
						newtable[newindex] = cur;
					}
				}
			}
		}

		pair<Node*, bool> insert(const T& t)
		{
			// 检查扩容
			check();
			// 判断原哈希表是否有该元素,若有返回false
			Node* findNode = find(t);
			if (findNode)
			{
				return make_pair(findNode, false);
			}
			KOT kot;
			int index = hash(kot(t), _table.size());
			
			Node*& head = _table[index];
			Node* newnode = new Node(t);
			// 头插
			newnode->_next = head;
			head = newnode;
			_size++;
			
			return make_pair(head, true);
		}

		Node* find(const K& key)
		{
			KOT kot;
			int index = hash(key);
			Node* cur = _table[index];

			while (cur)
			{
				if (kot(cur->_t) == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		bool erase(const K& key)
		{
			
			int index = hash(key); // 找到头结点
			Node* del = find(key);
			if (del == nullptr)
			{
				return false;
			}
			Node* prev = _table[index];
			if (prev == del)
			{
				// 头删
				_table[index] = del->_next;
				delete del;
				return true;
			}
			// 中间删
			while (prev->_next != del)
			{
				prev = prev->_next;
			}
			prev->_next = del->_next;
			delete del;
			return true;
		}

	private:
		size_t _size;
		vector<ListNode<T>*> _table;
	};
}