/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-10 10:49
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
		ListNode* removeElements(ListNode* head, int val) {
			ListNode **p = &head;
			while(*p) {
				if((*p)->val == val) {
					ListNode *q = (*p);
					*p = (*p)->next;
					delete q;
				} else
					p = &(*p)->next;
			}
			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
