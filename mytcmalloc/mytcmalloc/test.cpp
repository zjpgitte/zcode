
#include "ThreadCache.h"
#include "common.h"
#include "tcmalloc.h"

void Test(){
	void* a = tcmalloc(10);
}

int main(){

	Test();

	system("pause");
	return 0;
}