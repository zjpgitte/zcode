#pragma once

#include "rbtree.h"

template <class K>
class SetKOfT
{
public:
	const K& operator()(const K& key)
	{
		return key;
	}
};

template <class K>
class myset
{
public:
	typedef RBTree<K, const K, SetKOfT> RBTree;
	typedef RBTree::iterator iterator;

	pair<iterator, bool> insert(const K& key)
	{
		return _rb.insert(key);
	}

private:
	RBTree _rb;
};