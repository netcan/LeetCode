/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-09 10:53
 ************************************************************************/

#include <iostream>

#include <vector>
using namespace std;

// Definition for singly-linked list.
//
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		bool hasCycle(ListNode *head) {
			if(! head) return false;

			ListNode *slow = head;
			ListNode *fast = head;
			while(slow && fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
				if(slow == fast) return true;
			}
			return false;
		}
};

int main() {
	Solution s;
	return 0;
}
