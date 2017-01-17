/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-17 11:31
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		// 矩阵顺时针旋转90度
		// 沿着横线翻转
		// 沿主对角线翻转
		void rotate(vector<vector<int>>& matrix) {
			reverse(matrix.begin(), matrix.end());
			for (int i = 0; i < matrix.size(); ++i)
				for (int j = i+1;j < matrix.size(); ++j)
					swap(matrix[i][j], matrix[j][i]);
		}
};


int main() {
	Solution s;
	vector<vector<int>>matrix({
			{1,2,3},
			{4,5,6},
			{7,8,9}
			});
	s.rotate(matrix);
	return 0;
}
