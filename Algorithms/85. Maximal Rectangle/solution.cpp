/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-22 11:01
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	// 求最大矩形面积
	// S = (right[i][j] - left[i][j]) * height[i][j]
	// left[i][j] = max(left[i-1][j], cur_left)
	// right[i][j] = min(right[i-1][j], cur_right)
	// height[i][j] = 0 if matrix[i][j] == 0 else = height[i-1][j] + 1

	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
			if(matrix.empty()) return 0;
			int m = matrix.size(); // m行n列
			if(matrix[0].empty()) return 0;
			int n = matrix[0].size();

			int ans = 0;
			vector<int> left(n, 0), right(n, n), height(n, 0);
			for (int i = 0; i < m; ++i) {
				int cur_left = 0, cur_right = n;
				for (int j = 0; j < n; ++j) {
					if(matrix[i][j] == '1') {
						left[j] = max(left[j], cur_left);
						height[j] = height[j] + 1;
					} else {
						left[j] = 0;
						height[j] = 0;
						cur_left = j + 1;
					}

					if(matrix[i][n - 1 - j] == '1')
						right[n - 1 - j] = min(right[n - 1 - j], cur_right);
					else {
						right[n - 1 - j] = n;
						cur_right = n - 1 - j;
					}
				}

				for (int j = 0; j < n; ++j)
					ans = max(ans, (right[j]-left[j])*height[j]);
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<vector<char>> matrix({
			{'1','0','1','0','0'},
			{'1','0','1','1','1'},
			{'1','1','1','1','1'},
			{'1','0','0','1','0'},
			});
	cout << s.maximalRectangle(matrix) << endl;

	return 0;
}
