/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-13 11:16
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
		ListNode *detectCycle(ListNode *head) {
			if(head == NULL || head->next == NULL) return NULL;
			ListNode *slow = head, *fast = head;
			bool isCycled = false;
			while(fast && fast->next && !isCycled) {
				slow = slow->next;
				fast = fast->next->next;
				if(slow == fast) isCycled = true;
			}
			if(! isCycled) return NULL;
			fast = head;
			while(fast != slow) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
};


int main() {
	Solution s;

	return 0;
}
