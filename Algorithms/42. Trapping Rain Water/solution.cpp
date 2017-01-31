/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-31 10:29
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int trap(vector<int>& height) {
			if(height.empty()) return 0;
			int ans = 0;
			int l = 0, r = height.size() - 1;
			int maxl=0, maxr=0;
			while(l <= r) {
				if(height[l] <= height[r]) {
					if(maxl <= height[l]) maxl = height[l];
					else ans += maxl - height[l];
					++l;
				} else {
					if(maxr <= height[r]) maxr = height[r];
					else ans += maxr - height[r];
					--r;
				}
			}
			return ans;
		}

};


int main() {
	Solution s;
	vector<int> height({0,1,0,2,1,0,1,3,2,1,2,1});
	cout << s.trap(height) << endl;

	return 0;
}
