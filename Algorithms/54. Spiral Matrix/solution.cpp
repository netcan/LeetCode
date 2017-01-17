/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-17 10:34
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> ans;
			int m = matrix.size();
			if(m == 0) return ans;
			int n = matrix[0].size();
			if(m*n==0) return ans;
			vector<vector<bool>> mark(m, vector<bool>(n, false));

			int dx[] = {0, 1, 0, -1}; // 右，下，左，上
			int dy[] = {1, 0, -1, 0};
			int direct = 0;
			int x = 0, y = 0;
			int cur = 0;
			while(cur < m*n) {
				ans.push_back(matrix[x][y]);
				mark[x][y] = true;
				++cur;
				x += dx[direct]; y += dy[direct];
				if(x < 0 || y < 0 || x >= m || y >= n || mark[x][y]) {
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
	vector<vector<int>> matrix(
			{ {3},
			{2}
			});

	vector<int> ans = s.spiralOrder(matrix);
	for (int i = 0; i < ans.size(); ++i) printf("%2d ", ans[i]);
	puts("");
	return 0;
}
