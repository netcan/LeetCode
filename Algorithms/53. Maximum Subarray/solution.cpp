/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-17 11:12
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int n = nums[0];
			int sum = 0;
			for (int i = 0; i < nums.size(); ++i) {
				sum += nums[i];
				sum = max(nums[i], sum);
				n = max(max(nums[i], sum), n);
				// printf("sum=%d ", sum);
				// printf("asum=%d\n", sum);
			}
			return n;
		}
};


int main() {
	Solution s;
	vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
	cout << s.maxSubArray(nums) << endl;

	return 0;
}
