#pragma once

#include <iostream>

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

template <class K, class T, class KOfT> // ����װset��T = K�� ����װmap��T = pair<K, V>;
class RBTree
{
public:
	class RBTreeIterator
	{
	public:
		RBTreeIterator(TreeNode* temp = nullptr)
			:_it(temp)
		{}

	private:
		TreeNode* _it;
	};
public:
	typedef RBTreeNode<T> TreeNode;
	typedef RBTreeIterator iterator;
	RBTree()
		:_root(nullptr)
	{}

	pair<iterator, bool> insert(const T& t)
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
						RotateLeft(parent);
					}
					else
					{
						RotateRight(parent);
						RotateLeft(cur);
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

