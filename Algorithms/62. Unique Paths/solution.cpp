/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-16 17:23
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		// 走迷宫，从左上到右下的路径数目
		int uniquePaths(int m, int n) {
			if(m == 0 || n == 0) return 0;
			// int dp[m][n];
			int dp[n];
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					if(i == 0 && j == 0) dp[i] = 1;
					else // dp[i][j] = (i-1>=0?dp[i-1][j]:0) + (j-1>=0?dp[i][j-1]:0);
						dp[j] = dp[j] + (j-1>=0?dp[j-1]:0);
			// return dp[m-1][n-1];
			return dp[n-1];
		}
};


int main() {
	Solution s;
	cout << s.uniquePaths(2, 1) << endl;

	return 0;
}
