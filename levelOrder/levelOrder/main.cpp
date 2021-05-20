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
			// 叶子结点
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
		//层序遍历，使用队列保存根节点,没出一次根节点让其孩子结点入队。
		//使用两个记录当前层和下一层的个数的变量，使得可以每次让一层的节点出队。
		int height = treeHeight(root); // 求树的高度

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
				//访问当前层结点
				TreeNode* cur = q.front();
				ret[curI].push_back(cur->val);

				//该结点孩子结点入队
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

				//孩子结点入队后，父节点可以出队
				q.pop();
				//父节点出队后，当前层的结点数-1
				curLevel--;
			}

			//当前层结点全部出队完后,接着操作下层几点
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