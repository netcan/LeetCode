/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-15 11:37
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			int M = matrix.size();
			int N = matrix[0].size();
			bool col0 = false; // 第0列特殊处理
			if(M == 0 || N == 0) return;
			for (int i = 0; i < M; ++i) {
				if(matrix[i][0] == 0) col0 = true;
				for (int j = 1; j < N; ++j)
					if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
			}

			for (int i = M-1; i >= 0; --i) {
				for (int j = N-1; j >= 1; --j)
					if(matrix[i][0] == 0 || matrix[0][j] == 0)
						matrix[i][j] = 0;
				if(col0) matrix[i][0] = 0;
			}
		}

};


int main() {
	Solution s;
	vector<vector<int>> matrix = {
		{1,1,1},
		{0,1,2}
	};
	s.setZeroes(matrix);
	for(int i=0; i<matrix.size(); ++i) {
		for(int j=0; j<matrix[0].size(); ++j)
			printf("%2d", matrix[i][j]);
		puts("");
	}

	return 0;
}
