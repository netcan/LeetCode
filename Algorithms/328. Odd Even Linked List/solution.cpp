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
		ListNode* oddEvenList(ListNode* head) {
			if(head == NULL || head->next == NULL) return head;
			ListNode *preOdd = NULL, *odd = head, *even = new ListNode(0), *evenTail = even;
			while(odd && odd->next) {
				ListNode *t = odd->next->next;

				odd->next->next = evenTail->next;
				evenTail->next = odd->next;
				evenTail = evenTail->next;

				odd->next = t;
				preOdd = odd;
				odd = odd->next;
			}
			if(!odd) preOdd->next = even->next;
			else odd->next = even->next;
			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
