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

		// ������ڣ����Դ������������ڵ�
		TreeNode* newnode = new TreeNode(preorder[preI]);

		// �ҳ���ǰ�����ĸ��ڵ㣬��inorder�е�λ�ã�����ȷ�����������������䡣
		for (inRoot = 0; inRoot < inorder.size(); inRoot++)
		{
			if (inorder[inRoot] == preorder[preI])
			{
				break;
			}
		}
		++preI;

		// ����������, ����������[inLeft, inRoot - 1] 
		newnode->left = _buildTree(preorder, inorder, preI, inRoot, inLeft, inRoot - 1);

		// ����������, ����������[inRoot + 1, inRight]
		newnode->right = _buildTree(preorder, inorder, preI, inRoot, inRoot + 1, inRight);

		return newnode;
	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		int preI = 0, inRoot = 0;

		// �������ڵ㣬��������������㣬����������
		return _buildTree(preorder, inorder, preI, inRoot, 0, inorder.size() - 1);
	}
};