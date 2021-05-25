/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& preI, int inRoot, int inLeft, int inRight)
	{
		if (inLeft > inRight)
		{
			return nullptr;
		}

		// 区间存在，可以创建该子树根节点
		TreeNode* newnode = new TreeNode(preorder[preI]);

		// 找出当前创建的根节点，在inorder中的位置，便于确定其左右子树的区间。
		for (inRoot = 0; inRoot < inorder.size(); inRoot++)
		{
			if (inorder[inRoot] == preorder[preI])
			{
				break;
			}
		}
		++preI;

		// 创建左子树, 左子树区间[inLeft, inRoot - 1] 
		newnode->left = _buildTree(preorder, inorder, preI, inRoot, inLeft, inRoot - 1);

		// 创建右子树, 右子树区间[inRoot + 1, inRight]
		newnode->right = _buildTree(preorder, inorder, preI, inRoot, inRoot + 1, inRight);

		return newnode;
	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		int preI = 0, inRoot = 0;

		// 创建根节点，创建根左子树结点，创建右子树
		return _buildTree(preorder, inorder, preI, inRoot, 0, inorder.size() - 1);
	}
};