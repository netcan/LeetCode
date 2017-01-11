/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 12:27
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int thirdMax(vector<int>& nums) {
			long long first, second, third;
			first = second = third = numeric_limits<long long>::min();

			if(nums.size() < 3) {
				for (int i = 0; i < nums.size(); ++i)
					third = max(nums[i], int(third));
				return third;
			}

			for (int i = 0; i < nums.size(); ++i) {
				if(nums[i] > first) {
					third = second;
					second = first;
					first = nums[i];
				} else if(nums[i] > second && nums[i] != first) {
					third = second;
					second = nums[i];
				} else if(nums[i] > third && nums[i] != second && nums[i] != first)
					third = nums[i];
			}
			if(third == numeric_limits<long long>::min()) return first;
			else return third;
		}

};


int main() {
	Solution s;

	return 0;
}
