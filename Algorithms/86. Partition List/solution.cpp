/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-15 11:15:03
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
		ListNode* partition(ListNode* head, int x) {
			if(head == NULL || head->next == NULL)  return head;
			ListNode *lessHead = new ListNode(0); // 最后存放的是<x的元素
			ListNode *greaterHead = new ListNode(0); // 最后存放的是>=x的元素
			greaterHead->next = head;
			ListNode *tail = lessHead, *p = greaterHead;

			while(p->next) {
				if(p->next->val < x) {
					ListNode *t = p->next->next;

					p->next->next = tail->next;
					tail->next = p->next;
					tail = tail->next;

					p->next = t;
				}
				else p = p->next;
			}
			tail->next = greaterHead->next; // 连接起来

			return lessHead->next;
		}

};


int main() {
	Solution s;

	return 0;
}
