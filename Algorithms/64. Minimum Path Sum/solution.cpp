/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-12 10:16
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int n = grid.size();
			int m = grid[0].size();
			int dp[n][m];
			for(int i=0; i<n; ++i)
				for (int j = 0; j < m; ++j) {
					int up = i-1>=0?dp[i-1][j]:numeric_limits<int>::max();
					int left = j-1>=0?dp[i][j-1]:numeric_limits<int>::max();
					dp[i][j] = (i==0&&j ==0 ?0:min(left, up)) + grid[i][j];
				}
			return dp[n-1][m-1];
		}
};


int main() {
	Solution s;

	return 0;
}
