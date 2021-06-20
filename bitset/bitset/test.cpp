#include "bitset.hpp"

void testBitSet(){
	zjp::bitset s;

	s.set(2);
	s.set(3);
	s.set(4);
	s.set(11);
	s.set(12);
	s.set(10);
	s.set(101);
	s.set(102);
	s.set(105);
	s.set(108);

	s.reset(3);

	bool ret = s.test(10);

	ret = s.test(11);

	size_t count = s.count();
}


int main(){

	testBitSet();

	system("pause");
	return 0;
}