#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

// avl �����
// (k, v)  left  right  parent  bf   // ����parent��bf��Ϊ�˷����ƽ�⡣
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

// �����ࣺavl��
// ��ɾ����,�ұ�֤��ÿ�����ӻ�ɾ������ͨ������(��ת)ʹ��
// ʹ��֮�������Ȼ��avl��

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
		// �ݹ����Ȼ�����
	}

	bool operator = (const AVLTree& root)
	{
		// �Ƚ�ԭ��������գ�Ȼ�����һ����
	}

	~AVLTree()
	{
		// ���������������нڵ�
	}
	//  30 parent
	//    50 subR
	//      60 
	void RotateL(TreeNode* parent)
	{
		assert(parent && parent->_right); // parent �� parent->_right ������Ϊnull
		
		TreeNode* subR = parent->_right;
		TreeNode* subRL = subR->_left;

		// ��ת
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

		// ����ƽ������
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
		
		// ��ת
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

		// ����ƽ������
		subL = parent = 0;
	}

	// avl������ɾ���
	pair<TreeNode*, bool> insert(const pair<K, V>& val)
	{
		// 1.��first��λ�ã�����first������,
		// 2.�ҵ�����λ�ò���
		// 3.�жϲ�����������Ƿ�ƽ�⣬��ƽ�����ɹ���
		// 4.ͨ����ת��ƽ��
		TreeNode* newNode = new TreeNode(val);

		//��������
		if (_root == nullptr)
		{
			_root = newNode;
			return make_pair (newNode, true);
		}

		// ��
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

		
		if (val.first > parent->_val.first) // newnode���뵽parent�ұ�
		{
			parent->_right = newNode;
			newNode->_parent = parent;
			cur = newNode;
			// �������Ƚ���ƽ������
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

				//������ƽ�������ж��Ƿ�ʧ��
				if (abs(parent->_bf) >= 2)
				{
					// ��ʧ���ƽ��Ȼ���˳�ѭ���������
					// ��ƽ���Ӧ�������
					//һ��  30 parent
					//		  60 cur
					//          70 
					if (cur == parent->_right)
					{
						// ����
						RotateL(parent);
					}
					else
						//��:   60 parent               60                    50
						//    30 cur 70       ����  50  70        �ҵ���  30    60
						// 40   50                   30 55                40    55  70     
						//        55              40
					{
						// ����˫��(�ȶ�cur��ѡ���ٶ�parent���ҵ���)
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
				else // ûʧ��������ϸ���ƽ������
				{
					cur = parent;
					parent = parent->_parent;
				}
			}
		}
		else // newnode ���뵽parent ���
		{
			//    60 
			//  50 parent
			//40 newNode
			parent->_left = newNode;
			newNode->_parent = parent;
			cur = newNode;
			
			// ����ƽ������
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

				// �������ж��Ƿ�ʧ��
				if (abs(parent->_bf) >= 2)
				{	//    60 parent
					//  50 cur
					//40 
					// ��ת
					if (cur == parent->_left)
					{
						// �ҵ���
						RotateR(cur);
					}
					else
						//   30 parent          30 parent
						//     50 cur         20  50 cur
						//   40                 40   60
                        //                        35     
					{
						// ����˫��
						TreeNode* curL = cur->_left;
						int bf = curL->_bf;
						RotateR(cur);
						RotateL(parent);
						// ����ƽ������
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