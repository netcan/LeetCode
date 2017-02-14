/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-12 10:38
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
		void dfs(TreeNode *root, int &maxdepth, int &ans, int depth) {
			if(root == NULL) return;
			depth += 1;
			if(maxdepth < depth) {
				maxdepth = depth;
				ans = root->val;
			}
			dfs(root->left, maxdepth, ans, depth);
			dfs(root->right, maxdepth, ans, depth);
		}

		int findBottomLeftValue(TreeNode* root) {
			int ans = root->val;
			int depth = 0;
			int maxdepth = 0;
			dfs(root, maxdepth, ans, depth);
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
