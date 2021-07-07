#include "objpool.h"
#include <time.h>

class TreeNode {
private:
	int _val = 0;
	TreeNode* _left = nullptr;
	TreeNode* _right = nullptr;
};

void TestObj(){
	int n = 1000000;
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

	//int *a = (int*)malloc(sizeof(int));
	//int *b = (int*)calloc(4, sizeof(int)); // 分配四个int大小的内存,并初始化为0

	system("pause");

	return 0;
}