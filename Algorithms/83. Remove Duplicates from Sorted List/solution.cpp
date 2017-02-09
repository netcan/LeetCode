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
		ListNode* deleteDuplicates(ListNode* head) {
			if(! head) return head;
			ListNode *p = head;
			while(p && p->next) {
				ListNode *q = p->next;
				if(p->val == q->val) {
					p->next = q->next;
					delete q;
				}
				else
					p = p->next;
			}
			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
