/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-18 10:54
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		void dfs(vector<vector<int>> &ans, vector<int>& candidates, vector<int>&path, int target, int cur) {
			if(target == 0) {
				if(find(ans.begin(), ans.end(), path) == ans.end()) ans.push_back(path);
				return;
			} else if(target < 0 || cur >= candidates.size()) return;

			for (int i = cur; i < candidates.size(); ++i) {
				path.push_back(candidates[i]);
				dfs(ans, candidates, path, target - candidates[i], i+1);
				path.pop_back();
			}
		}

		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<vector<int>> ans;
			if(!candidates.size()) return ans;
			vector<int> path;
			sort(candidates.begin(), candidates.end());
			dfs(ans, candidates, path, target, 0);
			return ans;
		}

};


int main() {
	Solution s;
	vector<int> candidates({10,1,2,7,6,1,5});
	vector<vector<int>> ans = s.combinationSum2(candidates, 8);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}

	return 0;
}
