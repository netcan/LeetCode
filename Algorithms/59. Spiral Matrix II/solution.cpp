/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-16 18:53
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans(n, vector<int>(n, 0));
			int dx[] = {0, 1, 0, -1};
			int dy[] = {1, 0, -1, 0};
			int direct = 0;
			int x = 0, y = 0;
			int cur = 1;
			while(cur <= n*n) {
				ans[x][y] = cur++;
				x += dx[direct]; y += dy[direct];
				if(x < 0 || y < 0 || x >= n || y >= n || ans[x][y]) {
					x -= dx[direct]; y -= dy[direct];
					direct = (++direct)%4;
					x += dx[direct]; y += dy[direct];
				}
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<vector<int>> ans = s.generateMatrix(4);

	return 0;
}
