/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-15 11:37
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
			if(head == NULL || head->next == NULL) return head;
			ListNode **p = &head;
			bool isDupclidate = false;
			while(*p) {
				if((*p)->next) {
					if((*p)->val == (*p)->next->val || isDupclidate) {
						if((*p)->val == (*p)->next->val)
							isDupclidate = true;
						else isDupclidate = false;
						ListNode *t = (*p)->next;
						**p = *(*p)->next;
						delete t;
					} else
						p = &(*p)->next;
				} else {
					if(isDupclidate) {
						ListNode *t = *p;
						*p = NULL;
						delete t;
					}
					break;
				}
			}
			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
