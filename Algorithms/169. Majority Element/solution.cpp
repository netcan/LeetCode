/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 21:40
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			srand(time(0));
			int ans;
			do {
				ans = nums[random() % nums.size()];
			} while(count(nums.begin(), nums.end(), ans) <= int(nums.size()) >> 1);
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
