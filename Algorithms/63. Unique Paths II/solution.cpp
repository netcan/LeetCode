/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-16 17:37
************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		// [
		// [0,0,0],
		// [0,1,0],
		// [0,0,0]
		// ]
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int m = obstacleGrid.size(); // 行
			int n = obstacleGrid[0].size(); // 列
			if(m * n == 0) return 0;
			int dp[n];
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < m; ++i)
				for (int j = 0;j < n; ++j)
					if(obstacleGrid[i][j] == 1) dp[j] = 0;
					else if(i == 0 && j == 0) dp[j] = 1;
					else dp[j] = (j-1>=0?dp[j-1]:0) + dp[j];
			return dp[n-1];
		}
};


int main() {
	Solution s;
	vector<vector<int>> obstacleGrid = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};

	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}
