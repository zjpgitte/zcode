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
	void _tree2str(string& ret, TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		//访问根节点
		ret += to_string(root->val);

		//左树存在访问左树或左树不存在右树存在访问左树。
		if (root->left || root->right)
		{
			//遍历左子树之前带上左括号
			ret.push_back('(');
			// 遍历左子树
			_tree2str(ret, root->left);
			//左子树遍历完之后带上右括号
			ret.push_back(')');
		}

		//右树存在访问
		if (root->right)
		{
			ret.push_back('(');
			_tree2str(ret, root->right);
			ret.push_back(')');
		}
	}

	string tree2str(TreeNode* root) {
		string ret;
		_tree2str(ret, root);
		return ret;
	}
};