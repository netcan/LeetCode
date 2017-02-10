/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-10 11:25
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
		ListNode* reverseList(ListNode* head) {
			ListNode *rHead = new ListNode(0);
			ListNode *p = head;
			while(p) {
				ListNode *q = p->next;
				p->next = rHead->next;
				rHead->next = p;
				p = q;
			}
			return rHead->next;
		}

};


int main() {
	Solution s;

	return 0;
}
