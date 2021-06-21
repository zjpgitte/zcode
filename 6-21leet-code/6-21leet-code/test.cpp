
// 链表习题 : 链表习题需要注意的是，对于不带头的单链表插入和删除结点时要考虑头结点的情况。
// 1.删除倒数第N个结点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		// 快慢指针法
		ListNode* del = head;
		ListNode* prevDel = head;
		ListNode* last = head;
		for (int i = 0; i < n; i++) { // 快指针先向后走n步
			last = last->next;
		}

		while (last) { // 快指针走到null时，慢指针是倒数第N个结点
			prevDel = del;
			del = del->next;
			last = last->next;
		}

		if (del == head) {
			head = del->next;
		}
		else {
			prevDel->next = del->next;
		}
		delete del;

		return head;
	}
};


// 2.翻转链表
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* _reverseList(ListNode* prev, ListNode* cur)
	{
		if (cur == nullptr)
		{
			return prev;
		}

		ListNode* next = cur->next;
		cur->next = prev;
		return _reverseList(cur, next);
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr, *cur = head;
		return _reverseList(prev, cur);
	}
};


// 3.设计链表

class MyLinkedList {
public:
	struct ListNode {
		int val;
		ListNode* next;

		ListNode(int _val = 0) : val(_val), next(nullptr) {
		}
	};

	ListNode* head;
	int _size;

public:

	/** Initialize your data structure here. */
	MyLinkedList() : head(nullptr), _size(0) {

	}

	int size() {
		return _size;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		// 无效位置
		if (index < 0 || index >= size()) {
			return -1;
		}

		ListNode* cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		cout << cur->val << endl;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* newnode = new ListNode(val);
		newnode->next = head;
		head = newnode;
		++_size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* newnode = new ListNode(val);
		ListNode* tail = head;
		if (tail == nullptr) {
			addAtHead(val);
			++_size;
			return;
		}

		while (tail->next)
		{
			tail = tail->next;
		}

		tail->next = newnode;
		++_size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == size()) {
			addAtTail(val);
		}
		else if (index > size()) {
			return;
		}
		else if (index < 0) {
			addAtHead(val);
		}
		else {

			// 头插
			if (index == 0) {
				addAtHead(val);
				return;
			}

			//中间插
			ListNode* cur = head;
			ListNode* prev = head;
			for (int i = 0; i < index; i++)
			{
				prev = cur;
				cur = cur->next;
			}

			ListNode* newNode = new ListNode(val);
			newNode->next = cur;
			prev->next = newNode;
			++_size;

		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= 0 && index < size()) {
			// 头删
			if (index == 0) {
				ListNode* del = head;
				head = head->next;
				delete del;
				--_size;
				return;
			}
			ListNode* prev = head;
			ListNode* cur = head;
			for (int i = 0; i < index; i++)
			{
				prev = cur;
				cur = cur->next;
			}

			prev->next = cur->next;
			delete cur;
			--_size;
		}
	}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/

// 4.链表相交
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		// 定义两个指针，两个指针均是走完一个链表再走另一个链表
		// 两个指针一定是同时走完两个链表或者同时走到相交节点处，
		// 因为它俩走的路程是相同的。
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}
		ListNode* curA = headA;
		ListNode* curB = headB;

		while (curA != curB) {
			curA = curA->next;
			curB = curB->next;
			if (curA == nullptr && curA == curB) {
				return nullptr;
			}
			if (curA == nullptr) {
				curA = headB;
			}
			if (curB == nullptr) {
				curB = headA;
			}
		}

		return curA;

	}
};


// 1. 入环结点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// 快指针是慢指针速度的2倍
		// 同时从头开始走，当相遇时，满足 2(a + c) = a + (N-1)*(b + c) + c ,  a = (N-1)(b + c) + c
		// 此时再定义两个指针，分别从相遇点和head处开始走，这两个指针相遇位置就是入口点。(在环内走的指针可能是走了n圈)
		ListNode* fast = head, *slow = head;

		// 当没有环时循环退出
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) { // 相遇
				ListNode* begin = head; // 从头开始走,slow继续从当前位置开始走
				while (begin != slow) {
					begin = begin->next;
					slow = slow->next;
				}

				return begin;
			}
		}


		return nullptr;
	}
};