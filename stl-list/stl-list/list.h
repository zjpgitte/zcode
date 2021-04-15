#pragma once
#include <iostream>
using namespace std;


namespace zjp
{
	template<class T>
	struct node
	{
		T _val;
		node<T>* _prev;
		node<T>* _next;

		//结点的构造函数，创建一个结点时可以直接初始化。 
		// new node(2);
		node<T>(const T& val = T()) 
			:_val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};


	//Ref->T&   Ptr->T*
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		//对于模板类而言模板参数也是类类型的一部分,为了便于使用我们进行下面的类型重命名
		typedef node<T> node; 
		//typedef _list_iterator<T, Ref, Ptr> _list_iterator; 

		node* _list_ptr; //迭代器的成员变量是一个结点类型的指针,链表可以通过指针遍历和访问结点

		//迭代器的构造函数,指针初始化
		_list_iterator(node* ptr = nullptr)
			:_list_ptr(ptr)
		{}

		//迭代器是让它内部的指针指向一个结点，不需要开空间，属于浅拷贝
		//使用默认的拷贝构造函数、赋值运算符重载、析构函数即可。

		//*it,stl中结点的值不同过 *it 来改变，要用const修饰，这样const变量和非const变量均可使用
		Ref operator * () const
		{
			return _list_ptr->_val;
		}

		//it->
		Ptr operator ->() const
		{
			return &_list_ptr->_val;
		}
		
		//++it，不改变结点的值用const修饰
		_list_iterator& operator ++ () 
		{
			_list_ptr = _list_ptr->_next;
			return *this;
		}

		//it++
		_list_iterator operator ++ (int) 
		{
			node* temp = _list_ptr;
			_list_ptr = _list_ptr->_next;
			return _list_iterator(temp);
		}

		//--it
		_list_iterator operator --() 
		{
			_list_ptr = _list_ptr->_prev
				;
			return _list_iterator(_list_ptr);
		}

		//it--
		_list_iterator operator --(int) 
		{
			node* temp = _list_ptr;
			_list_ptr = _list_ptr->_prev;
			return _list_iterator(temp);
		}

		// it != l.end()
		bool operator != (_list_iterator it) const 
		{
			return _list_ptr != it._list_ptr;
		}
	};

	template <class T>
	class list
	{
	public:
		//typedef list<T> list;
		typedef node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		//构造函数
		list()
			:_head(nullptr)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//使用一段迭代器区间的构造函数
		list(iterator start, iterator end)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			while (start != end)
			{
				push_back(*start);
				start++;
			}
		}

		//拷贝构造
		list(const list& l)
			:_head(nullptr)
		{
			list temp(l.begin(), l.end());

			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			node* first = temp._head->_next;
			node* last = temp._head->_prev;
			_head->_next = first;
			first->_prev = _head;
			_head->_prev = last;
			last->_next = _head;

			temp._head->_next = temp._head;
			temp._head->_prev = temp._head;
		}

		~list()
		{
			clear();

			delete _head;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				iterator del = it;
				it++;
				delete del._list_ptr;
			}
		}

		//begin()   it = l.begin()
		iterator begin() 
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		//it.end()
		iterator end() 
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		//增  l.push_back(2)
		void push_back(const T& val = T())
		{
			/*node* tail = _head->_prev;
			node* newNode = new node(val);
			tail->_next = newNode;
			newNode->_prev = tail;
			_head->_prev = newNode;
			newNode->_next = _head;*/
			insert(end(), val);
		}

		//  l.insert(it, 3)
		iterator insert(const iterator& it, const T& val)
		{
			node* newNode = new node(val);
			
			node* prev = it._list_ptr->_prev;
			newNode->_next = it._list_ptr;
			it._list_ptr->_prev = newNode;
			newNode->_prev = prev;
			prev->_next = newNode;
			
			return iterator(newNode);
		}
		// push_front(0)
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		//删 l1.erase(it)
		iterator erase(const iterator& it)
		{
			node* pre = it._list_ptr->_prev;
			node* next = it._list_ptr->_next;
			pre->_next = next;
			next->_prev = pre;

			delete it._list_ptr;

			return iterator(next);
		}
		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}
		//改
	private:
		node* _head;
	};

}