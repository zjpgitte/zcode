#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
	int treeHeight(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			// Ҷ�ӽ��
			return 1;
		}
		else
		{
			int lefth = treeHeight(root->left);
			int righth = treeHeight(root->right);
			return max(lefth, righth) + 1;
		}
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//���������ʹ�ö��б�����ڵ�,û��һ�θ��ڵ����亢�ӽ����ӡ�
		//ʹ��������¼��ǰ�����һ��ĸ����ı�����ʹ�ÿ���ÿ����һ��Ľڵ���ӡ�
		int height = treeHeight(root); // �����ĸ߶�

		vector<vector<int>> ret;
		ret.resize(height);
		int curI = 0;
		if (root == nullptr)
		{
			return ret;
		}

		queue<TreeNode*> q;
		q.push(root);
		int curLevel = 1, nextLevel = 0;
		while (!q.empty())
		{
			while (curLevel > 0)
			{
				//���ʵ�ǰ����
				TreeNode* cur = q.front();
				ret[curI].push_back(cur->val);

				//�ý�㺢�ӽ�����
				if (cur->left)
				{
					q.push(cur->left);
					nextLevel++;
				}
				if (cur->right)
				{
					q.push(cur->right);
					nextLevel++;
				}

				//���ӽ����Ӻ󣬸��ڵ���Գ���
				q.pop();
				//���ڵ���Ӻ󣬵�ǰ��Ľ����-1
				curLevel--;
			}

			//��ǰ����ȫ���������,���Ų����²㼸��
			curLevel = nextLevel;
			nextLevel = 0;
			curI++;
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};


int main()
{
	
	
	
	system("pause");
	return 0;
}