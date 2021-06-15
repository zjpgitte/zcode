#pragma once

#include <iostream>
#include <cassert>

using namespace std;

enum COLOR
{
	RED,
	BLACK
};

template <class T>
struct RBTreeNode
{
	T _t; 
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	COLOR _col;

	RBTreeNode(const T& t = T())
		:_t(t)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template <class T, class Ref, class Ptr>
class RBTreeIterator
{
public:
	typedef RBTreeNode<T> TreeNode;
	typedef RBTreeIterator<T, Ref, Ptr> self;
public:
	RBTreeIterator(TreeNode* temp = nullptr)
		:_it(temp)
	{}

	// ++it
	self operator ++ ()
	{
		assert(_it);
		//�Ҵ���,����������������
		if (_it->_right)
		{
			TreeNode* left = _it->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_it = left;
		}
		else // �Ҳ�����������
		{
			TreeNode* cur = _it;
			TreeNode* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}

			_it = parent;
		}
		return _it;
	}

	// --it
	self operator -- ()
	{
		assert(_it); // _it Ϊnull��ʱ��˵���ߵ�end()������Ӧ����++
		if (_it->_left) // ���������������������ұ���
		{
			TreeNode* right = _it->_left;
			while (right->_right)
			{
				right = right->_right;
			}

			_it = right;
		}
		else // ����������������
		{
			TreeNode* parent = _it->_parent;
			TreeNode* cur = _it;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_it = parent;
		}
		return _it;
	}
	// *it
	Ref operator * () 
	{
		return _it->_t;
	}

	// it->
	Ptr operator ->()
	{
		return &_it->_t;
	}

	bool operator == (const self& it)
	{
		return _it == it._it;
	}

	bool operator != (const self& it)
	{
		return _it != it._it;
	}

private:
	TreeNode* _it;
};

template <class K, class T, class KOfT> // ����װset��T = K�� ����װmap��T = pair<K, V>;
class RBTree
{
public:
	typedef RBTreeNode<T> TreeNode;
	typedef RBTreeIterator<T, T&, T*> iterator;
public:
	RBTree()
		:_root(nullptr)
	{}

	// begin()
	iterator begin()
	{
		TreeNode* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	// end()
	iterator end()
	{
		return iterator(nullptr);
	}


	//   1
	//     2
	//       3
	void RotateLeft(TreeNode* cur)
	{
		TreeNode* subR = cur->_right;
		TreeNode* subRL = subR->_left;

		cur->_right = subRL;
		if (subRL)
		{
			subRL->_parent = cur;
		}

		TreeNode* curParent = cur->_parent;
		subR->_left = cur;
		cur->_parent = subR;
		subR->_parent = curParent;
		if (curParent == nullptr)
		{
			_root = subR;
		}
		else if (cur == curParent->_left)
		{
			curParent->_left = subR;
		}
		else if (cur == curParent->_right)
		{
			curParent->_right = subR;
		}
		else
		{
			assert(false);
		}

		subR->_col = BLACK;
		cur->_col = RED;
		if (subR->_right)
		{
			subR->_right->_col = RED;
		}
	}

	//      4
	//    3
	//   1
	void RotateRight(TreeNode* cur)
	{
		TreeNode* subL = cur->_left;
		TreeNode* subLR = subL->_right;

		cur->_left = subLR;
		if (subLR)
		{
			subLR->_parent = cur;
		}

		TreeNode* curParent = cur->_parent;
		subL->_right = cur;
		cur->_parent = subL;
		
		subL->_parent = curParent;
		if (curParent == nullptr)
		{
			_root = subL;
		}
		else if (curParent->_left == cur)
		{
			curParent->_left = subL;
		}
		else if (curParent->_right == cur)
		{
			curParent->_right = subL;
		}
		else
		{
			assert(false);
		}

		subL->_col = BLACK;
		if (subL->_left )
		{
			subL->_left->_col = RED;
		}
		cur->_col = RED;
	}

	pair<iterator, bool> insert(T& t)
	{
		KOfT kot;
		K key = kot(t); // ����Ԫ�ص�key
		TreeNode* newnode = new TreeNode(t);
		if (_root == nullptr)
		{
			_root = newnode;
			_root->_col = BLACK;
			return make_pair(newnode, true);
		}
		TreeNode* cur = _root;
		TreeNode* parent = _root;
		while (cur)
		{
			if (key > kot(cur->_t))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < kot(cur->_t))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair((nullptr), false);
			}
		}

		if (key > kot(parent->_t))
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;
		// �ж��Ƿ��½ڵ���뵽3����4���ĺ���(���Ǻ�ɫ)�������
		while (parent && parent->_col == RED)
		{
			// �ǵ�ƽ��, �����ֱ�ӷ���
			TreeNode* gFather = parent->_parent;
			TreeNode* uncle = gFather->_left;
			if (parent == gFather->_left)  // gFatherһ�����ڣ���Ϊ�ߵ���˵��������Ǻ��㣬
			{                             // ���ں�����У���ɫ�����ڵ����������Ϻ�ɫ����γ�3����4���
				uncle = gFather->_right;  // ����gFatherһ�����ڲ���һ���Ǻڽ��
			}

			if (uncle && uncle->_col == RED)// �����뵽4 ���ĺ��ӽ������
			{
				// ���� 4 �����м��������������������������������2���
				gFather->_col = RED;
				uncle->_col = parent->_col = BLACK;
			}
			else// ���뵽3���ĺ��ӽ������
			{
				// ��ʱ3������˲�����������4���,��ʱ��Ҫ���ľ���
				// ͨ����ת���м����ɺڽ�㣬���Һ��ӽ���ɺ���
				
				if (gFather->_left == parent)
				{
					if (cur == parent->_left)
					{
						//    4
						//  3
						// 1
						RotateLeft(gFather);
					}
					else
					{
						//   5
						// 3
						//  4
						RotateLeft(parent);
						RotateRight(gFather);
						cur->_col = BLACK;
						gFather->_col = parent->_col = RED;
					}
				}
				else
				{
					if (cur == parent->_right)
					{
						//  1
						//    2
						 //     3
						RotateLeft(gFather);
					}
					else
					{
						//   1 
						//     3
						//   2
						RotateRight(parent);
						RotateLeft(gFather);
						cur->_col = BLACK;
						gFather->_col = parent->_col = RED;
					}
				}

				return make_pair(newnode, true);
			}
		}

		_root->_col = BLACK; // ����ĵ��������п��ܻ�Ѹ��ڵ����ɫ�ı�

		// 2.���뵽��2��������3���ĸ��������(���Ǻ�ɫ���)�����κε���
		return make_pair(iterator(newnode), true);
	}

private:
	TreeNode* _root;
};

