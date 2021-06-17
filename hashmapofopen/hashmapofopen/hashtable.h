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

	// ģ���ػ�
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
				// ���Դ���һ���µĹ�ϣ��������ϣ������insert()��ʵ�ִ���ĸ��á�
				//���������ÿ��insert����һ�����������Ҫ�¿���㡣
				// ���Կ��ǵ������Ǵ����µ������ԭ���Ľ��ȡ�����ҵ��������¼��ɡ�
				int newsize = _size * 2;
				vector<Node*> newtable;
				newtable.resize(newsize);
				for (int i = 0; i < _table.size(); i++)
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
					}
				}
			}
		}

		pair<Node*, bool> insert(const T& t)
		{
			// �������
			check();
			// �ж�ԭ��ϣ���Ƿ��и�Ԫ��,���з���false
			Node* findNode = find(t);
			if (findNode)
			{
				return make_pair(findNode, false);
			}
			KOT kot;
			int index = hash(kot(t), _table.size());
			
			Node*& head = _table[index];
			Node* newnode = new Node(t);
			// ͷ��
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
			
			int index = hash(key); // �ҵ�ͷ���
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
				return true;
			}
			// �м�ɾ
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