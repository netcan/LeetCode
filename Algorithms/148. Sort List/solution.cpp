/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-11 10:18
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
		ListNode* sortList(ListNode* head) {
			if(head == NULL || head->next == NULL) return head;
			ListNode *prev = NULL, *slow = head, *fast = head;
			while(fast && fast->next) {
				prev = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			prev->next = NULL; // 截断两半数组
			return mergeList(sortList(head), sortList(slow)); // 这里要注意了，是归并sortList后的!!
		}
		ListNode *mergeList(ListNode *l1, ListNode *l2) {
			ListNode *Head = new ListNode(0);
			ListNode *tail = Head;
			while(l1 && l2) {
				if(l1->val <= l2->val) {
					tail->next = l1;
					l1 = l1->next;
				} else {
					tail->next = l2;
					l2 = l2->next;
				}
				tail = tail->next;
			}
			tail->next = l1?l1:l2;
			return Head->next;
		}
};


int main() {
	Solution s;
	ListNode *l = new ListNode(5);
	ListNode *tail = l;
	tail->next = new ListNode(4);
	tail = tail->next;
	tail->next = new ListNode(3);
	tail = tail->next;
	tail->next = new ListNode(2);
	tail = tail->next;
	tail->next = new ListNode(1);
	tail = tail->next;
	tail->next = NULL;
	tail = tail->next;
	s.sortList(l);

	return 0;
}
