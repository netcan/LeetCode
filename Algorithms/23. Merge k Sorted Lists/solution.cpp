/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-16 11:23
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 合并k个升序的数组
// 两两合并
// 优先队列
class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			bool (*cmp)(ListNode *p, ListNode *q) = [](ListNode* p, ListNode* q) {
				return p->val > q->val;
			};
			priority_queue<ListNode*, vector<ListNode *>, decltype(cmp)> que(cmp);
			for(ListNode *p: lists)
				for(; p; p = p->next) que.push(p);
			ListNode *newHead = new ListNode(0), *tail = newHead;
			while(que.size()) {
				que.top()->next = tail->next;
				tail->next = que.top();
				tail = tail->next;
				que.pop();
			}
			return newHead->next;
		}
};


int main() {
	Solution s;

	return 0;
}
