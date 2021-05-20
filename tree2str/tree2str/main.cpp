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

		//���ʸ��ڵ�
		ret += to_string(root->val);

		//�������ڷ��������������������������ڷ���������
		if (root->left || root->right)
		{
			//����������֮ǰ����������
			ret.push_back('(');
			// ����������
			_tree2str(ret, root->left);
			//������������֮�����������
			ret.push_back(')');
		}

		//�������ڷ���
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