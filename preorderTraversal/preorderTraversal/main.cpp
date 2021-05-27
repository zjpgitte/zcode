#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	system("pause");
	return 0;
}
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;

		while (cur || !st.empty())
		{
			//访问当前节点的左单边树
			while (cur)
			{
				v.push_back(cur->val);
				st.push(cur);
				cur = cur->left;
			}

			cur = st.top()->right;
			st.pop();
		}

		return v;
	}
};