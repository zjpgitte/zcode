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
		//ÿ�η����굱ǰ�ڵ���prev��ǣ�Ϊ��֤�ݹ�������²�ı�prev�ϲ���Ե�֪
		//��Ҫ�����ã���֤ÿ����һ����㶼����ͬһ��prev�������
	{
		if (cur == nullptr)
		{
			return;
		}

		// �����������֤������������
		_Convert(prev, cur->left);

		// �޸ĵ�ǰ�ڵ��ǰ���������ָ���ָ��
		if (prev)
		{
			//ǰ����㲻��null��˵����ǰ�ڵ㲻�ǵ�һ�����ʽ��
			prev->right = cur;
			cur->left = prev;
		}
		else
		{
			//ǰ�����ʱnull��˵����ǰ�ڵ��ǵ�һ�����ʽ��
			phead = cur;
		}

		//�޸���ǰ���͵�ǰ�ڵ��ָ��ָ��󣬸���ǰ����㡣
		prev = cur;

		_Convert(prev, cur->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree) {
		phead = nullptr; //�����������ĵ�һ�����

		TreeNode* prev = nullptr;  // �����������е�ǰ�ڵ����һ�����

		//ͨ����������޸�ÿ��ָ���ָ��
		_Convert(prev, pRootOfTree);

		return phead;
	}
};