/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-13 12:55
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
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
		// 先序中序遍历构造二叉树
		// [1,2,4,3,5,6]
		// [4,2,1,3,6,5]
		TreeNode* build(unordered_map<int, int>& hash, vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd) { // [pStart, pNnd) [iStart, iEnd)
			TreeNode *p = new TreeNode(preorder[pStart]);
			if(pStart + 1 == pEnd) return p;
			else if(pStart >= pEnd || iStart >= iEnd) return NULL;
			int mid = hash[preorder[pStart]];
			p->left = build(hash, preorder, inorder, pStart + 1, pStart + 1 + mid - iStart, iStart, mid);
			p->right = build(hash, preorder, inorder, pStart + 1 + mid - iStart, pEnd, mid + 1, iEnd);
			return p;
		}
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int N = preorder.size();
			if(! N) return NULL;
			unordered_map<int, int> hash;
			for (size_t i = 0; i < inorder.size(); ++i) hash[inorder[i]] = i;
			TreeNode *tree = build(hash, preorder, inorder, 0, N, 0, N);
			return tree;
		}
};


int main() {
	Solution s;
	int p[] = {1,2,4,3,5,6};
	int i[] = {4,2,1,3,6,5};
	vector<int> preorder(p, p+sizeof(p)/sizeof(int));
	vector<int> inorder(i, i+sizeof(i)/sizeof(int));
	TreeNode *tree = s.buildTree(preorder, inorder);

	return 0;
}
