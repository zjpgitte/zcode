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
	typedef RBTree<K, const K, SetKOfT<K>> RBTree;
	typedef RBTree::iterator iterator;

	pair<iterator, bool> insert(const K& key)
	{
		return _rb.insert(key);
	}

	iterator begin()
	{
		return _rb.begin();
	}

private:
	RBTree _rb;
};