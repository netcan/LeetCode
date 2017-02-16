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
		// 删除倒数第n个节点，只要维护2个指针，间隔为n+1，当另一个指针到达末尾即可
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			if(head == NULL) return NULL;
			ListNode **first = &head, *second = head;
			int i;
			for(i=0; i<n && second; ++i) second = second->next;
			if(i < n || *first == second) return head;

			while(second) {
				first = &(*first)->next;
				second = second->next;
			}
			if((*first)->next)
				**first = *(*first)->next; // 删除当前节点
			else *first = NULL;


			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
