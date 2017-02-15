/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-15 12:25
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
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
			stack<int> n1, n2;
			ListNode *p = l1, *q = l2;

			while(p) {
				n1.push(p->val);
				p = p->next;
			}
			while(q) {
				n2.push(q->val);
				q = q->next;
			}

			ListNode *newHead = new ListNode(0);
			bool shift = 0;

			while(n1.size() && n2.size()) {
				ListNode *r = new ListNode((n1.top() + n2.top() + shift) % 10);
				r->next = newHead->next;
				newHead->next = r;
				shift = (n1.top() + n2.top() + shift)/10;
				n1.pop(); n2.pop();
			}

			stack<int> &s = n1.size()?n1:n2;

			while(s.size()) {
				ListNode *r = new ListNode((s.top() + shift) % 10);
				r->next = newHead->next;
				newHead->next = r;
				shift = (s.top() + shift)/10;
				s.pop();
			}
			if(shift) {
				ListNode *r = new ListNode(1);
				r->next = newHead->next;
				newHead->next = r;
			}
			return newHead->next;
		}
};


int main() {
	Solution s;

	return 0;
}
