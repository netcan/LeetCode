/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-15 11:27
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		// 把二维矩阵看成一维的，然后二分就可以啦
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int M = matrix.size();
			if(! M) return false;
			int N = matrix[0].size();
			if(! N) return false;
			int lb = 0, ub = M*N; // [lb, ub)
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1; // mid = i*N + j
				int i = mid/N;
				int j = mid%N;
				if(matrix[i][j] == target) return true;
				else if(matrix[i][j] > target) ub = mid;
				else lb = mid;
			}
			return matrix[lb/N][lb%N] == target;
		}

};


int main() {
	Solution s;

	return 0;
}
