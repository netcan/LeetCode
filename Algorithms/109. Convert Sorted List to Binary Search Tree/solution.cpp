/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-15 10:26
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

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* sortedListToBST(ListNode* head) {
			return toBST(head, NULL);
		}
		TreeNode* toBST(ListNode *head, ListNode *tail) { // [head, tail)
			if(head == tail) return NULL;
			if(head->next == tail)
				return new TreeNode(head->val);
			ListNode *mid = head, *fast = head; // 寻找中间节点
			while(fast != tail && fast->next != tail) {
				mid = mid->next;
				fast = fast->next->next;
			}
			TreeNode *root = new TreeNode(mid->val);
			root->left = toBST(head, mid);
			root->right = toBST(mid->next, tail);
			return root;
		}

};


int main() {
	Solution s;

	return 0;
}
