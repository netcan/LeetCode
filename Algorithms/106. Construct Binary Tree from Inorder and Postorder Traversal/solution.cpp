/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-13 11:26
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		// 中序后序遍历构造二叉树
		// [4,6,2,1,3,5]
		// [6,4,2,5,3,1]
		TreeNode* build(vector<int>& inorder, vector<int>& postorder, int iStart, int iEnd, int pStart, int pEnd) { // [iStart, iNnd) [pStart, pEnd)
			TreeNode *p = new TreeNode(postorder[pEnd - 1]);
			if(pStart + 1 == pEnd) return p;
			else if(pStart >= pEnd || iStart >= iEnd) return NULL;
			int mid = 0;
			while(inorder[mid] != postorder[pEnd - 1]) ++mid;
			// printf("iStart = %d iEnd=%d mid=%d pStart=%d pEnd=%d\n", iStart, iEnd, mid, pStart, pEnd);

			// puts("left");
			p->left = build(inorder, postorder, iStart, mid, pStart, pEnd - iEnd + mid);
			// puts("right");
			p->right = build(inorder, postorder, mid + 1, iEnd, pEnd - iEnd + mid, pEnd-1);
			return p;
		}
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			int N = inorder.size();
			if(! N) return NULL;
			TreeNode *tree = build(inorder, postorder, 0, N, 0, N);
			return tree;
		}
};


int main() {
	Solution s;
	int i[] = {4,6,2,1,3,5};
	int p[] = {6,4,2,5,3,1};
	vector<int> inorder(i, i+sizeof(i)/sizeof(int));
	vector<int> postorder(p, i+sizeof(p)/sizeof(int));
	TreeNode *tree = s.buildTree(inorder, postorder);

	return 0;
}
