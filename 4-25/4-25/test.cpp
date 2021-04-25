
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		queue<int>* nEmptyQ = &q1;
		if (q1.empty())
		{
			nEmptyQ = &q2;
		}

		nEmptyQ->push(x);

	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int>* emptyQ = &q1;
		queue<int>* nEmptyQ = &q2;
		if (!q1.empty())
		{
			swap(emptyQ, nEmptyQ);
		}

		//将非空队列元素导到空队列中,最后一个元素不导入
		while (true)
		{
			int x = nEmptyQ->front();
			nEmptyQ->pop();

			if (nEmptyQ->empty())
			{
				return x;
			}

			emptyQ->push(x);
		}

		return 1;

	}

	/** Get the top element. */
	int top() {
		queue<int>* emptyQ = &q1;
		queue<int>* nEmptyQ = &q2;
		if (!q1.empty())
		{
			swap(emptyQ, nEmptyQ);
		}

		//将非空队列元素导到空队列中,最后一个元素不导入
		while (true)
		{
			int x = nEmptyQ->front();
			nEmptyQ->pop();

			emptyQ->push(x);

			if (nEmptyQ->empty())
			{
				return x;
			}
		}

		return 1;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1;
	queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/