/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 22:16
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> triangle(numRows);
			if(numRows <= 0) return triangle;
			triangle[0].push_back(1);
			for(int i=1; i<numRows; ++i) {
				for(int j=0; j<=i; ++j) {
					if(j == 0 || j == i) triangle[i].push_back(1);
					else triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
				}
			}
			return triangle;
		}
};


int main() {
	Solution s;

	return 0;
}
