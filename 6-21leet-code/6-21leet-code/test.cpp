
// ����ϰ�� : ����ϰ����Ҫע����ǣ����ڲ���ͷ�ĵ���������ɾ�����ʱҪ����ͷ���������
// 1.ɾ��������N�����
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

		// ����ָ�뷨
		ListNode* del = head;
		ListNode* prevDel = head;
		ListNode* last = head;
		for (int i = 0; i < n; i++) { // ��ָ���������n��
			last = last->next;
		}

		while (last) { // ��ָ���ߵ�nullʱ����ָ���ǵ�����N�����
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


// 2.��ת����
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


// 3.�������

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
		// ��Чλ��
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

			// ͷ��
			if (index == 0) {
				addAtHead(val);
				return;
			}

			//�м��
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
			// ͷɾ
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

// 4.�����ཻ
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

		// ��������ָ�룬����ָ���������һ������������һ������
		// ����ָ��һ����ͬʱ���������������ͬʱ�ߵ��ཻ�ڵ㴦��
		// ��Ϊ�����ߵ�·������ͬ�ġ�
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


// 1. �뻷���
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
		// ��ָ������ָ���ٶȵ�2��
		// ͬʱ��ͷ��ʼ�ߣ�������ʱ������ 2(a + c) = a + (N-1)*(b + c) + c ,  a = (N-1)(b + c) + c
		// ��ʱ�ٶ�������ָ�룬�ֱ���������head����ʼ�ߣ�������ָ������λ�þ�����ڵ㡣(�ڻ����ߵ�ָ�����������nȦ)
		ListNode* fast = head, *slow = head;

		// ��û�л�ʱѭ���˳�
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) { // ����
				ListNode* begin = head; // ��ͷ��ʼ��,slow�����ӵ�ǰλ�ÿ�ʼ��
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