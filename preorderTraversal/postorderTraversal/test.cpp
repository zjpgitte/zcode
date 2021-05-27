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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* prev = nullptr; //��¼��һ�����ʹ��������ĸ�
		TreeNode* cur = root; // ��¼��ǰҪ���ʵ������ĸ�

		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();

			if (cur->right == nullptr || prev == cur->right)
			{
				v.push_back(cur->val);
				prev = cur;
				st.pop();
				cur = nullptr;
			}
			else
			{
				cur = cur->right;
			}
		}

		return v;
	}
};