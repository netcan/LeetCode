/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
	public: // 变成中位数即可
		int steps(vector<int>&nums, int x) {
			int ret = 0;
			for(auto &n: nums) ret += abs(x-n);
			return ret;
		}
		int minMoves2(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			return steps(nums, nums[nums.size() / 2]);
		}

};


int main() {
	Solution s;

	return 0;
}
