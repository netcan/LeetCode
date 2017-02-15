/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-15 10:46
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
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if(head == NULL || head->next == NULL || m == n) return head;
			ListNode *newHead = new ListNode(0);
			newHead->next = head;
			ListNode *p = newHead;
			for(int i = 0; i < m - 1; ++i) p = p->next;
			ListNode *q = p->next;

			for(int i = m; i<=n; ++i) q = q->next;
			ListNode *t = p->next;
			p->next = q;
			q = t;

			for(int i = m; i<=n; ++i) {
				ListNode *t = q->next;
				q->next = p->next;
				p->next = q;
				q = t;
			}

			return newHead->next;
		}
};


int main() {
	Solution s;

	return 0;
}
