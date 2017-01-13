/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-13 09:59
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<int> majorityElement(vector<int>& nums) {
			vector<int> ans;
			if(! nums.size()) return ans;
			int x1, x2, cnt1, cnt2;
			// x1, x2的值不能一样，否则会出现相等的结果，需要判断
			cnt1 = cnt2 = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if(x1 == nums[i]) ++cnt1;
				else if(x2 == nums[i]) ++cnt2;
				else if(cnt1 == 0) {
					x1 = nums[i];
					++cnt1;
				}
				else if(cnt2 == 0) {
					x2 = nums[i];
					++cnt2;
				}
				else {--cnt1; --cnt2;}
			}
			if(count(nums.begin(), nums.end(), x1) > int(nums.size()) / 3) ans.push_back(x1);
			if(x1 != x2 && count(nums.begin(), nums.end(), x2) > int(nums.size()) / 3) ans.push_back(x2);


			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
