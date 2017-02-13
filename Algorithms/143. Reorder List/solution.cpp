/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-13 10:42
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		// 前插法
		void reorderList(ListNode* head) {
			if(head == NULL || head->next == NULL) return;
			ListNode *slow = head, *fast = head;
			while(fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			ListNode *reverseHead = new ListNode(0);
			while(slow->next) {
				ListNode *t = slow->next->next;
				slow->next->next = reverseHead->next;
				reverseHead->next = slow->next;
				slow->next = t;
			}
			ListNode *p = head, *q = reverseHead->next;
			while(p && q) {
				ListNode *tp = p->next, *tq = q->next;
				q->next = p->next;
				p->next = q;
				p = tp;
				q = tq;
			}

		}
};


int main() {
	Solution s;

	return 0;
}
