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
		//�ݹ���ֹ
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

		// root�Ȳ���pҲ����q
		// �ж�root�������Ľ��
		if (left && right)
		{
			// �������������ڣ�˵��û�������������
			// root����
			return root;
		}
		else if (left)
		{
			// ���������������ڣ��������ڷ����������
			return left;
		}
		else if (right)
		{
			// �������ڷ����������
			return right;
		}
		else
		{
			// �����淵��nullptr
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

		// ���������ǵ�·���Ľڵ㡣
		// �������ж��У���������������������û�ҵ�k��
		// ˵���ýڵ㲻�ǴӸ���k·���ϵĽڵ㣬��root����
		path.push_back(root);

		// ���жϸ��ڵ��ǲ���k
		if (root == k)
		{
			return true;
		}

		//���ڵ㲻��k��������������
		if (findPath(root->left, k, path) == true)
		{
			return true;
		}

		// ���ڵ㣬��������û�ҵ�,����������
		if (findPath(root->right, k, path) == true)
		{
			return true;
		}

		//��û�ҵ�������false;������
		path.pop_back();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// �ֱ��ҳ��Ӹ��ڵ㵽p��q��·��

		vector<TreeNode*> pPath;
		vector<TreeNode*> qPath;
		// �ҴӸ���p��·��, ���ҵ���·����ÿ����㱣�浽vector�У�������true
		// ��û�ҵ�����false;
		findPath(root, p, pPath);
		// �ҴӸ��ڵ㵽q
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