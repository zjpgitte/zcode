#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		pushSt.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (popSt.empty())
		{
			while (!pushSt.empty())
			{
				popSt.push(pushSt.top());
				pushSt.pop();
			}
		}

		int x = popSt.top();
		popSt.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (popSt.empty())
		{
			while (!pushSt.empty())
			{
				popSt.push(pushSt.top());
				pushSt.pop();
			}
		}

		return popSt.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return pushSt.empty() && popSt.empty();
	}

	stack<int> pushSt;
	stack<int> popSt;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/

int main()
{
	
	
	
	system("pause");
	return 0;
}