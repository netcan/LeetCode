/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 18:19
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		int minimumTotal(vector<vector<int>>& triangle) {
			int H = triangle.size();
			if(H <= 0) return 0;
			int dp[H];
			for(int j=triangle[H - 1].size() - 1; j>=0; --j) dp[j] = triangle[H-1][j];
			for(int i=H-2; i>=0; --i)
				for(int j=0; j<=i; ++j)
					dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
			return dp[0];
		}
};


int main() {
	Solution s;

	return 0;
}
