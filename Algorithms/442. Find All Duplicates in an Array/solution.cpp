/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-13 20:16
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		vector<int> findDuplicates(vector<int>& nums) {
			// 或者每个元素设为相反数，当遇到负数，就说明出现2次
			vector<int> ans;
			int times[nums.size() + 1];
			memset(times, 0, sizeof(times));
			for(int i=0; i<nums.size(); ++i) {
				++times[nums[i]];
				if(times[nums[i]] == 2) ans.push_back(nums[i]);
			}
			return ans;
		}

};


int main() {
	Solution s;

	return 0;
}
