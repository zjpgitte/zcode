/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//递归终止
		if (root == nullptr)
		{
			return nullptr;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);

		TreeNode* right = lowestCommonAncestor(root->right, p, q);


		if (root == p || root == q)
		{
			return root;
		}

		// root既不是p也不是q
		// 判断root的子树的结果
		if (left && right)
		{
			// 左右子树都存在，说明没找最近公共祖先
			// root就是
			return root;
		}
		else if (left)
		{
			// 左右子树不都存在，左树存在返回左树结果
			return left;
		}
		else if (right)
		{
			// 右树存在返回右树结果
			return right;
		}
		else
		{
			// 都不存返回nullptr
			return nullptr;
		}


	}
};




class Solution {
public:
	bool findPath(TreeNode* root, TreeNode* k, vector<TreeNode*>& path)
	{
		if (root == nullptr)
		{
			return false;
		}

		// 假设根结点是到路径的节点。
		// 若后序判断中，根，左子树，右子树均没找到k。
		// 说明该节点不是从根到k路径上的节点，将root弹出
		path.push_back(root);

		// 先判断根节点是不是k
		if (root == k)
		{
			return true;
		}

		//根节点不是k，从左子树中找
		if (findPath(root->left, k, path) == true)
		{
			return true;
		}

		// 根节点，左子树均没找到,到右子树找
		if (findPath(root->right, k, path) == true)
		{
			return true;
		}

		//都没找到，返回false;弹出根
		path.pop_back();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 分别找出从根节点到p、q的路径

		vector<TreeNode*> pPath;
		vector<TreeNode*> qPath;
		// 找从根到p的路径, 若找到将路径的每个结点保存到vector中，并返回true
		// 若没找到返回false;
		findPath(root, p, pPath);
		// 找从根节点到q
		findPath(root, q, qPath);

		int i = 0;
		for (i = 0; i < pPath.size() && i < qPath.size(); i++)
		{
			if (pPath[i] != qPath[i])
			{
				return pPath[i - 1];
			}
		}

		if (i == pPath.size())
		{
			return pPath[i - 1];
		}
		if (i == qPath.size())
		{
			return qPath[i - 1];
		}
		return nullptr;
	}
};