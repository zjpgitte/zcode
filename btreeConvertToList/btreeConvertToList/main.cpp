/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* phead = nullptr;
	void _Convert(TreeNode*& prev, TreeNode* cur)
		//每次访问完当前节点用prev标记，为保证递归遍历中下层改变prev上层可以得知
		//需要传引用，保证每访问一个结点都是用同一个prev标记它。
	{
		if (cur == nullptr)
		{
			return;
		}

		// 中序遍历，保证生成有序链表
		_Convert(prev, cur->left);

		// 修改当前节点和前驱结点左右指针的指向。
		if (prev)
		{
			//前驱结点不是null，说明当前节点不是第一个访问结点
			prev->right = cur;
			cur->left = prev;
		}
		else
		{
			//前驱结点时null，说明当前节点是第一个访问结点
			phead = cur;
		}

		//修改完前驱和当前节点的指针指向后，更新前驱结点。
		prev = cur;

		_Convert(prev, cur->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree) {
		phead = nullptr; //标记中序遍历的第一个结点

		TreeNode* prev = nullptr;  // 标记中序遍历中当前节点的上一个结点

		//通过中序遍历修改每个指针的指向。
		_Convert(prev, pRootOfTree);

		return phead;
	}
};