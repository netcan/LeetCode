/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-14 11:00
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			if(head == NULL) return NULL;

			unordered_map<RandomListNode *, int> pos; // 遍历得到链表的位置
			unordered_map<int, RandomListNode *> posr; // 遍历得到链表的位置
			unordered_map<int, int> random; // 遍历得到链表的随机位置关系

			int i = 0;
			for(RandomListNode *p = head; p != NULL; p = p->next, ++i)
				pos[p] = i;
			pos[NULL] = -1;

			i = 0;
			for(RandomListNode *p = head; p != NULL; p = p->next, ++i)
				random[i] = pos[p->random];

			i = 0;
			RandomListNode *newHead = new RandomListNode(head->label);
			posr[i++] = newHead;
			RandomListNode *tail = newHead;

			// 复制链表
			for(RandomListNode *p = head->next; p != NULL; p = p->next, ++i) {
				tail->next = new RandomListNode(p->label);
				tail = tail->next;
				posr[i] = tail;
			}

			// 复制随机指针
			i = 0;
			for(RandomListNode *p = newHead; p != NULL; p = p->next, ++i) {
				if(random[i] == -1) p->random = NULL;
				else p->random = posr[random[i]];
			}

			return newHead;
		}

};


int main() {
	Solution s;

	return 0;
}
