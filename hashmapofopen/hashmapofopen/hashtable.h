#pragma once
#include <iostream>
#include <vector>

using namespace std;



namespace open
{
	template <class K>
	struct HASH
	{
		int operator ()(const K& key, int size)
		{
			return key % size;
		}
	};

	// ģ���ػ�
	template<>
	struct HASH<string>
	{
		int operator()(const string& s, int size)
		{
			size_t sum = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				sum = sum * 131 + s[i];
			}

			return sum % size;
		}
	};

	// ģ�������
	template <class K, class T, class KOT, class HASHFUNC >
	class HashTable;

	template < class K, class T, class Ptr, class Ref, class KOT, class HASHFUNC>
	class HashIterator
	{
	public:
		typedef typename HashTable<K, T, KOT, HASHFUNC> HashTable;
		typedef typename HashTable::ListNode Node;

		// ������������Ϊ��Ԫ
		typedef HashIterator<K, T,  Ptr,  Ref,  KOT,  HASHFUNC> self;
	public:
		size_t hash(const K& key, int size)
		{
			HASHFUNC hf;
			return hf(key, size);
		}
	public:
		HashIterator(Node* node = nullptr, HashTable* pht = nullptr)
			:_node(node)
			, _pht(pht)
		{}

		HashIterator(const self& node)
			:_node(node._node)
		{}

		bool operator == (const self& it)
		{
			return _node == it._node;
		}

		bool operator != (const self& it)
		{
			return _node != it._node;
		}

		self& operator ++ ()
		{
			KOT kot;
			if (_node->_next != nullptr)
			{
				_node = _node->_next;			
			}
			else
			{
				size_t index = hash(kot(_node->_t), _pht->_table.size());
				for (size_t i = index + 1; i < _pht->_table.size(); i++)
				{
					if (_pht->_table[i] != nullptr)
					{
						_node = _pht->_table[i];
						return *this;
					}
				}

				_node = nullptr;
			}

			return *this;
		}

		// �������������Ҫ--

		Ref operator * ()
		{
			return _node->_t;
		}

		Ptr operator -> ()
		{
			return &_node->_t;
		}

	private:
		Node* _node;
		HashTable* _pht;
	};

	template <class K, class T, class KOT, class HASHFUNC = HASH<K>>
	class HashTable
	{
		
	public:
		struct ListNode
		{
			T _t;
			ListNode* _next;

			ListNode(const T& t = t())
				:_t(t)
				, _next(nullptr)
			{}
		};

		int hash(const K& key, int size)
		{
			HASHFUNC hf;
			return hf(key, size);
		}
	public:
		typedef ListNode Node;
		typedef typename HashIterator<K, T, T*, T&, KOT, HASHFUNC> HashIterator;
		//typedef typename HashIterator<K, T, const T*, const T&, KOT, HASHFUNC> Const_HashIterator;
		typedef typename HashIterator Iterator;
	//	typedef typename Const_HashIterator const_Iterator;
	public:
		friend HashIterator;
	public:
		HashTable(int capacity = 3)
			:_size(0)
		{
			_table.resize(capacity);
		}

		Iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i] != nullptr)
				{
					return Iterator(_table[i], this);
				}
			}

			return end();
		}

		Iterator end()
		{
			return Iterator(nullptr, this);
		}

		void check()
		{
			KOT kot;
			if (_size >= _table.capacity())
			{
				// ���Դ���һ���µĹ�ϣ��������ϣ������insert()��ʵ�ִ���ĸ��á�
				//���������ÿ��insert����һ�����������Ҫ�¿���㡣
				// ���Կ��ǵ������Ǵ����µ������ԭ���Ľ��ȡ�����ҵ��������¼��ɡ�
				int newsize = _size * 2;
				vector<Node*> newtable;
				newtable.resize(newsize);
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						//ȡ���ýڵ�
						Node* next = cur->_next;
						_table[i] = next;
						// ͷ�嵽��������
						int newindex = hash(kot(cur->_t), newsize);
						cur->_next = newtable[newindex];
						newtable[newindex] = cur;

						cur = next;
					}
				}
				newtable.swap(_table);
			}
		}

		pair<Iterator, bool> insert(const T& t)
		{
			KOT kot;
			// �������
			check();
			// �ж�ԭ��ϣ���Ƿ��и�Ԫ��,���з���false
			Node* findNode = find(kot(t));
			if (findNode)
			{
				return make_pair(findNode, false);
			}
			
			int index = hash(kot(t), _table.size());
			
			Node*& head = _table[index];
			Node* newnode = new Node(t);
			// ͷ��
			newnode->_next = head;
			head = newnode;
			_size++;
			
			return make_pair(Iterator(head), true);
		}

		Node* find(const K& key)
		{
			KOT kot;
			int index = hash(key, _table.size());
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
			
			int index = hash(key, _table.size()); // �ҵ�ͷ���
			Node* del = find(key);
			if (del == nullptr)
			{
				return false;
			}
			Node* prev = _table[index];
			if (prev == del)
			{
				// ͷɾ
				_table[index] = del->_next;
				delete del;
				--_size;
				return true;
			}
			// �м�ɾ
			while (prev->_next != del)
			{
				prev = prev->_next;
			}
			prev->_next = del->_next;
			delete del;
			--_size;
			return true;
		}

	private:
		size_t _size;
		vector<Node*> _table;
	};
}