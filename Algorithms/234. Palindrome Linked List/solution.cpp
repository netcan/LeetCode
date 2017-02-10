/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-10 11:34
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
	// 反置另一半，然后重头开始判断是否相等，就知道是否回文
	public:
		bool isPalindrome(ListNode* head) {
			if(head==NULL || head->next == NULL) return true;
			ListNode* slow = head;
			ListNode* fast = head;
			while(fast && fast->next && fast->next->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			slow->next = reverseList(slow->next);
			slow = slow->next;
			while(slow) {
				if(slow->val != head->val) return false;
				slow = slow->next;
				head = head->next;
			}
			return true;
		}

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
