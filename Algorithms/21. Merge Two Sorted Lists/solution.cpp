/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode *head = new ListNode(0);
			ListNode *p = l1, *q = l2, *r = head;
			while(p && q) {
				if(p->val <= q->val) {
					r->next = p;
					p = p->next;
				} else {
					r->next = q;
					q = q->next;
				}
				r = r->next;
			}
			r->next = p?p:q;
			return head->next;
		}
};


int main() {
	Solution s;

	return 0;
}
