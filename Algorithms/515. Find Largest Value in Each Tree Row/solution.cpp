/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-12 10:38
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
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
		void dfs(TreeNode *root, vector<int>& ans, int depth) {
			if(root == NULL) return;
			depth += 1;
			if(ans.size() < depth) ans.push_back(root->val);
			else
				ans[depth - 1] = max(ans[depth - 1], root->val);

			dfs(root->left, ans, depth);
			dfs(root->right, ans, depth);
		}

		vector<int> largestValues(TreeNode* root) {
			if(root == NULL) return vector<int>({});
			vector<int> ans;
			int depth = 0;
			dfs(root, ans, depth);
			return ans;

		}
};


int main() {
	Solution s;

	return 0;
}
