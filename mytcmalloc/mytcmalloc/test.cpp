
#include "ThreadCache.h"
#include "common.h"
#include "tcmalloc.h"

void Test(){
	void* a = tcmalloc(8);
	void* b = tcmalloc(8);
	void* c = tcmalloc(8);
}

int main(){

	Test();

	system("pause");
	return 0;
}