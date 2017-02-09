/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-09 11:23
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
		void deleteNode(ListNode* node) {
			ListNode *p = node->next;
			*node = *node->next;
			delete p;
		}
};


int main() {
	Solution s;

	return 0;
}
