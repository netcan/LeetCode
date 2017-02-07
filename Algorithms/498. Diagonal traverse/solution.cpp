/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-05 11:20
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
			vector<int> ans;
			// M行N列
			int M = matrix.size();
			if(! M) return ans;
			int N = matrix[0].size();
			if(! N) return ans;
			bool direct = true; // 右上
			int i = 0, j = 0;
			while(!(i == M && j == N)) {
				if(i < M && j < N)
					ans.push_back(matrix[i][j]);
				if(direct) { // 右上
					--i, ++j;
					if(i < 0) {
						i = 0;
						direct = false;
					}
				} else { // 左下
					--j, ++i;
					if(j < 0) {
						j = 0;
						direct = true;
					}
				}
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<vector<int>> matrix({
			{1,2,3},
			{4,5,6},
			{7,8,9},
			{10,11,12}
			});
	vector<int> ans = s.findDiagonalOrder(matrix);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}
