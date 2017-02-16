/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-16 10:24
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
		ListNode* swapPairs(ListNode* head) {
			if(head == NULL || head->next == NULL) return head;
			ListNode *newHead = new ListNode(0), *p = newHead;
			newHead->next = head;
			while(p && p->next && p->next->next) {
				ListNode *t = p->next, *tt = t->next->next;

				p->next = t->next;
				t->next->next = t;
				t->next = tt;

				p = t;
			}
			return newHead->next;
		}
};


int main() {
	Solution s;

	return 0;
}
