/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-18 10:31
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void dfs(vector<vector<int>> &ans, vector<int>& candidates, vector<int>&path, int target, int cur) {
			if(target == 0) {
				ans.push_back(path);
			} else if(target < 0) return;

			for (int i = cur; i < candidates.size(); ++i) {
				path.push_back(candidates[i]);
				dfs(ans, candidates, path, target - candidates[i], i);
				path.pop_back();
			}
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<vector<int>> ans;
			vector<int> path;
			if(!candidates.size()) return ans;
			dfs(ans, candidates, path, target, 0);
			return ans;
		}

};


int main() {
	Solution s;
	vector<int> candidates({2,3,6,7});
	vector<vector<int>> ans = s.combinationSum(candidates, 7);

	return 0;
}
