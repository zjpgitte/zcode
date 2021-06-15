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
	typedef typename RBTree<K, pair<const K, V>, MapKOfT<K, V>> RBTree;
	typedef typename RBTree::iterator iterator;

	pair<iterator, bool> insert(const pair<K, V>& key)
	{
		return _rb.insert(key);
	}

	iterator begin()
	{
		return _rb.begin();
	}

	iterator end()
	{
		return _rb.end();
	}

private:
	RBTree _rb;
};