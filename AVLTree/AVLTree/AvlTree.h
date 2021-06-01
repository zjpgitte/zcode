#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

// avl 树结点
// (k, v)  left  right  parent  bf   // 增加parent和bf是为了方便调平衡。
template <class K, class V>
struct AVLTreeNode
{
	typedef  AVLTreeNode<K, V> TreeNode;

	pair<K, V> _val;
	TreeNode *_left;
	TreeNode *_right;
	TreeNode *_parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& val = val())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

// 定义类：avl树
// 增删查结点,且保证在每次增加或删除结点后，通过调整(旋转)使得
// 使得之后的数仍然是avl树

template<class K, class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> TreeNode;

	AVLTree()
		:_root(nullptr)
	{}

	AVLTree(const AVLTree& root)
	{
		// 递归遍历然后深拷贝
	}

	bool operator = (const AVLTree& root)
	{
		// 先将原来的树清空，然后深拷贝一个树
	}

	~AVLTree()
	{
		// 遍历销毁树的所有节点
	}
	//  30 parent
	//    50 subR
	//      60 
	void RotateL(TreeNode* parent)
	{
		assert(parent && parent->_right); // parent 和 parent->_right 不可能为null
		
		TreeNode* subR = parent->_right;
		TreeNode* subRL = subR->_left;

		// 旋转
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		TreeNode* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		subR->_parent = parentParent;
		if (_root == parent)// 
		{
			_root = subR;
		}
		else if (parent == parentParent->_left)
		{
			parentParent->_left = subR;
		}
		else
		{
			parentParent->_right = subR;
		}

		// 更新平衡因子
		parent->_bf = 0;
		subR->_bf = 0;	
	}

	//      60 parent
	//    50 subL
	//  40    subLR
	void RotateR(TreeNode* parent)
	{
		TreeNode* subL = parent->_left;
		TreeNode* subLR = subL->_right;
		
		// 旋转
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		TreeNode* parentParent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		subL->_parent = parentParent;
		if (_root == parent)
		{
			_root = subL;
		}
		else if (parent == parentParent->_left)
		{
			parentParent->_left = subL;
		}
		else
		{
			parentParent->_right = subL;
		}

		// 更新平衡因子
		subL = parent = 0;
	}

	// avl树的增删查改
	pair<TreeNode*, bool> insert(const pair<K, V>& val)
	{
		// 1.找first的位置，若有first不插入,
		// 2.找到合适位置插入
		// 3.判断插入结点的祖先是否平衡，若平衡插入成功，
		// 4.通过旋转调平衡
		TreeNode* newNode = new TreeNode(val);

		//树不存在
		if (_root == nullptr)
		{
			_root = newNode;
			return make_pair (newNode, true);
		}

		// 找
		TreeNode* cur = _root;
		TreeNode* parent = cur;
		while (cur)
		{
			if (val.first > cur->_val.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val.first < cur->_val.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, true);
			}
		}

		
		if (val.first > parent->_val.first) // newnode插入到parent右边
		{
			parent->_right = newNode;
			newNode->_parent = parent;
			cur = newNode;
			// 更新祖先结点的平衡因子
			while (parent)
			{
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else
				{
					parent->_bf--;
				}

				//更新完平衡因子判断是否失衡
				if (abs(parent->_bf) >= 2)
				{
					// 若失衡调平衡然后退出循环插入结束
					// 调平衡对应两种情况
					//一：  30 parent
					//		  60 cur
					//          70 
					if (cur == parent->_right)
					{
						// 左单旋
						RotateL(parent);
					}
					else
						//二:   60 parent               60                    50
						//    30 cur 70       左单旋  50  70        右单旋  30    60
						// 40   50                   30 55                40    55  70     
						//        55              40
					{
						// 左右双旋(先对cur左单选，再对parent做右单旋)
						TreeNode* curR = cur->_right;
						int bf = curR->_bf;
						RotateL(cur);
						RotateR(parent);
						if (bf == 1)
						{
							cur->_bf = -1;
							parent = 0;
							curR->_bf = 0;
						}
						else if (bf == -1)
						{
							cur->_bf = 0;
							parent->_bf = 1;
							curR->_bf = 0;
						}
						else
						{
							assert(false);
						}
					}
					break;
				}
				else // 没失衡继续向上更新平衡因子
				{
					cur = parent;
					parent = parent->_parent;
				}
			}
		}
		else // newnode 插入到parent 左边
		{
			//    60 
			//  50 parent
			//40 newNode
			parent->_left = newNode;
			newNode->_parent = parent;
			cur = newNode;
			
			// 更新平衡因子
			while (parent)
			{
				if (cur == parent->_left)  
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				// 更新完判断是否失衡
				if (abs(parent->_bf) >= 2)
				{	//    60 parent
					//  50 cur
					//40 
					// 旋转
					if (cur == parent->_left)
					{
						// 右单旋
						RotateR(cur);
					}
					else
						//   30 parent          30 parent
						//     50 cur         20  50 cur
						//   40                 40   60
                        //                        35     
					{
						// 右左双旋
						TreeNode* curL = cur->_left;
						int bf = curL->_bf;
						RotateR(cur);
						RotateL(parent);
						// 更新平衡因子
						if (bf == 1)
						{
							curL->_bf = 0;
							parent->_bf = -1;
							cur->_bf = 0;
						}
						else if (bf == -1)
						{
							curL->_bf = 0;
							parent->_bf = 0;
							cur->_bf = 1;
						}
						else
						{
							assert(false);
						}
						
					}
					break;
				}
				else
				{
					cur = parent;
					parent = parent->_parent;
				}
			}
		}

		return make_pair(newNode, true);
	}
	void _inorder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_inorder(root->_left);
		cout << root->_val.first << "bf:" << root->_bf << endl;
		_inorder(root->_right);
	}
	void inorder()
	{
		_inorder(_root);
	}

	bool _isBalanced(TreeNode* root, int& height)
	{
		if (root == nullptr)
		{
			height = 0;
			return true;
		}

		bool left = _isBalanced(root->_left, height);
		int leftHeight = height;
		bool right = _isBalanced(root->_right, height);
		int rightHeight = height;

		if (left && right && abs(leftHeight - rightHeight) < 2)
		{
			height = max(leftHeight, rightHeight) + 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isBalanced() {
		int height = 0;
		return _isBalanced(_root, height);
	}


private:
	TreeNode* _root;

};