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
		// it 走右子树
		if (_it->_right)
		{
			_it = _it->_right;
		}
		else
		{
			TreeNode* cur = _it;
			TreeNode* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_it = parent;
		}
	}

	// --it
	self operator -- ()
	{

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

private:
	TreeNode* _it;
};

template <class K, class T, class KOfT> // 若封装set，T = K； 若封装map，T = pair<K, V>;
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
		TreeNode* cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}

		return iterator(cur);
	}

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
		if (_root == cur)
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
		cur->_col = subR->_right->_col = RED;
	}

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
		subL->_left->_col = cur->_col = RED;
	}

	pair<iterator, bool> insert(T& t)
	{
		KOfT kot;
		K key = kot(t); // 插入元素的key
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
		// 判断是否将新节点插入到3结点或4结点的孩子(均是红色)结点下面
		while (parent && parent->_col == RED)
		{
			// 是调平衡, 调完后直接返回
			TreeNode* gFather = parent->_parent;
			TreeNode* uncle = gFather->_left;
			if (parent == gFather->_left)  // gFather一定存在，因为走到这说明父结点是红结点，
			{                             // 而在红黑树中，红色结点存在的意义就是配合黑色结点形成3结点和4结点
				uncle = gFather->_right;  // 所以gFather一定存在并且一定是黑结点
			}

			if (uncle && uncle->_col == RED)// 若插入到4 结点的孩子结点下面
			{
				// 分裂 4 结点的中间结点上升，左右两个结点变成两个独立的2结点
				gFather->_col = RED;
				uncle->_col = parent->_col = BLACK;
			}
			else// 插入到3结点的孩子结点下面
			{
				// 这时3结点变成了不满足条件的4结点,这时需要做的就是
				// 通过旋转将中间结点变成黑结点，左右孩子结点变成红结点
				if (gFather->_left == parent)
				{
					if (cur == parent->_left)
					{
						RotateLeft(parent);
					}
					else
					{
						RotateRight(parent);
						RotateLeft(gFather);
						cur->_col = BLACK;
						gFather->_col = parent->_col = RED;
					}
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateRight(parent);
					}
					else
					{
						RotateRight(parent);
						RotateLeft(cur);
						cur->_col = BLACK;
						gFather->_col = parent->_col = RED;
					}
				}

				return make_pair(newnode, true);
			}
		}

		_root->_col = BLACK; // 上面的调整过程有可能会把根节点的颜色改变

		// 2.插入到了2结点下面或3结点的父结点下面(均是黑色结点)不做任何调整
		return make_pair(iterator(newnode), true);
	}

private:
	TreeNode* _root;
};

