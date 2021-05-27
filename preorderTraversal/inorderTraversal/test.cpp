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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;

		while (cur || !st.empty())
		{
			// 当前节点左子树入栈
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}

			TreeNode* top = st.top();
			v.push_back(top->val);
			cur = top->right;
			st.pop();
		}

		return v;
	}
};