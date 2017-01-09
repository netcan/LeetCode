/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:45
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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *ansHead = new ListNode(-1);
			ListNode *p = l1, *q = l2, *cur = ansHead;
			int shift = 0; // 进位
			while(p || q) {
				int d = (p?p->val:0) + (q?q->val:0) + shift;
				shift = d / 10;
				ListNode *r = new ListNode(d % 10);
				cur->next = r;
				cur = r;
				if(p) p = p->next;
				if(q) q = q->next;
			}

			if(shift) {
				ListNode *r = new ListNode(shift);
				cur->next = r;
				cur = r;
			}

			return ansHead->next;
		}
};


int main() {

	return 0;
}
