#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;


int main(){
	condition_variable c1;
	condition_variable c2;
	mutex m1;
	mutex m2;
	int i = 1;
	thread t1([&](){
		while (i < 100) {
			c1.wait(unique_lock<mutex>(m1));
			cout << i << endl;
			i++;
			c2.notify_one();
		}
	});
	thread t2([&](){
		while (i < 100) {
			c2.wait(unique_lock<mutex>(m2));
			cout << i << endl;
			i++;
			c1.notify_one();
		}
	});
	
	c1.notify_one();

	t1.join();
	t2.join();

	system("pause");
	return 0;
}