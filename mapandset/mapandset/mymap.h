#pragma once

#include "rbtree.h"

template <class K, class V>
class MapKOfT
{
public:
	const K& operator()(const pair<K, V>& a)
	{
		return a.first;
	}
};

template <class K, class V>
class mymap
{
public:
	typedef RBTree<K, pair<const K, V>, MapKOfT> RBTree;
	typedef RBTree::iterator iterator;

	pair<iterator, bool> insert(const pair<K, V>& key)
	{
		return _rb.insert(key);
	}

private:
	RBTree _rb;
};