/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-20 09:41
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxArea(vector<int>& height) {
			int ans = 0;
			int l = 0, r = height.size() - 1;
			while(l < r) {
				ans = max(ans, (r-l) * min(height[l], height[r]));
				if(height[l] < height[r]) ++l;
				else --r;
			}
			return ans;
		}

};


int main() {
	Solution s;

	return 0;
}
