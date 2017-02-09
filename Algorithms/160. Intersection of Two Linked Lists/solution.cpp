/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-09 11:39
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

// 求2个链表的公共部分
/* 解法一：
 * 2个for循环，A链表每移动一位，B链表遍历一遍检查是否有重合的。
 */

/* 解法二
 * 求两个链表的长度lA, lB
 * 假设B比A长，那么B先移动lB-lA位，然后和A,B同时移动，判断是否有重合的
 */

/* 解法三
 * 和解法二类似，无需求lA, lB
 * 两个链表同时移动，到末尾了就交换遍历到另一个链表开头
 * 假设B比A长，当B移动到末尾时，A正在B链表开头的lB-lA位置，紧接着B交换到A链表的开头，然后同时移动，判断是否有重合的。
 * 具体实现见代码
 */
class Solution {
	public:

		 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			ListNode *p = headA;
			ListNode *q = headB;
			if(p == NULL || q == NULL) return NULL;
			while(p != q) {
				p = p?p->next:headB;
				q = q?q->next:headA;
			}
			return p;
		}
};


int main() {
	Solution s;

	return 0;
}
