/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-12 17:41
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool dfs(vector<vector<int>> &ans, vector<int>& path, int k, int n, int prevSum, int cur) {
			if(k <= 0 && prevSum + cur == n) {
				ans.push_back(path);
				return true;
			} else if(k <= 0) return false;
			prevSum += cur;

			for (int i = cur + 1; i < 10; ++i) {
				if(prevSum + i <= n) {
					path.push_back(i);
					dfs(ans, path, k-1, n, prevSum, i);
					path.pop_back();
				}
				else break;
			}

			return false;
		}

		vector<vector<int>> combinationSum3(int k, int n) {
			vector<vector<int>> ans;
			vector<int> path;
			if(k > n || k<=0) return ans;
			dfs(ans, path, k, n, 0, 0);
			return ans;
		}
};


int main() {
	Solution s;
	vector<vector<int>> ans = s.combinationSum3(2, 18);
	return 0;
}
