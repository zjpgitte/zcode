#include "objpool.h"
#include <time.h>

class TreeNode {
private:
	int _val;
	TreeNode* _left;
	TreeNode* _right;
};

void TestObj(){
	int n = 10000000;
	ObjPool<TreeNode> obj;
	int begin1 = clock();
	for (int i = 0; i < n; i++) {
		TreeNode* cur = obj.New();
	}
	int end1 = clock();

	int begin2 = clock();
	for (int i = 0; i < n; i++) {
		TreeNode* cur = new TreeNode();
	}
	int end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}

int main(){

	TestObj();

	system("pause");

	return 0;
}