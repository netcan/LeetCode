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
		ListNode* rotateRight(ListNode* head, int k) {
			int len = 0;
			ListNode *q = head;
			while(q) {
				++len;
				q = q->next;
			}
			if(len == 0) return head;
			k = k%len;
			if(k == 0) return head;
			q = head;
			for(int i=0; i<len-k-1; ++i) q = q->next; // 向后移动len-k格
			ListNode *p = q;
			q = q->next;
			p->next = NULL; // 切断
			p = q;
			while(p->next) p = p->next; // p指向末尾
			p->next = head; // 链接起来
			head = q;
			return head;
		}
};


int main() {
	Solution s;

	return 0;
}
