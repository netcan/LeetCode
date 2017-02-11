/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-11 11:10
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
		// 插入排序，先新建一个链表保证有序
		ListNode* insertionSortList(ListNode* head) {
			if(head == NULL || head->next == NULL) return head;
			ListNode *newHead = new ListNode(0);
			ListNode *p = newHead, *cur = head;
			while(cur) {
				ListNode *next = cur->next;
				while(p->next && p->next->val < cur->val) p = p->next;
				cur->next = p->next;
				p->next = cur;
				p = newHead;
				cur = next;
			}
			return newHead->next;
		}
};


int main() {
	Solution s;

	return 0;
}
