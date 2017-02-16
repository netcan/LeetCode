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
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode *newHead = new ListNode(0), *tail = newHead;
			ListNode *p = head, *q = head;
			while(q) {
				int i;
				for(i=0; i<k && q; ++i) q = q->next;
				if(i < k) break;
				ListNode *ft = NULL;
				while(p != q) {
					ListNode *t = p->next;

					p->next = tail->next;
					tail->next = p;

					if(ft == NULL) ft = p;
					p = t;
				}
				tail = ft;
			}
			tail->next = p;
			return newHead->next;
		}

};


int main() {
	Solution s;

	return 0;
}
