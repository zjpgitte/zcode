
#include "ThreadCache.h"
#include "common.h"
#include "tcmalloc.h"
#include <windows.h>
#include <time.h>
#include <thread>

void testmalloc(int n){

	size_t begin1 = clock();
	void** arr = new void*[n];
	for (int i = 1; i < n; i++) {
		arr[i] = (void*)malloc(i);
	}
	for (int i = 1; i < n; i++) {
		free(arr[i]);
	}
	size_t end1 = clock();

	cout << "malloc:" << (end1 - begin1) <<endl;
}
void testtcmalloc(int n){

	size_t begin1 = clock();
	void** arr = new void*[n];
	for (int i = 1; i < n; i++) {
		arr[i] = (void*)tcmalloc(i);
	}
	for (int i = 1; i < n; i++) {
		if (i == 192)
			cout << endl;
		tcfree(arr[i]);
	}
	size_t end1 = clock();

	cout << "tcmalloc:" << (end1 - begin1) << endl;
}

void Test1() {
	int n = 100000;
	testmalloc(n);
	testtcmalloc(n);
}

void Test2() {
	
}

int main(){

	Test1();
	//Test2();
	system("pause");
	return 0;
}