/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 11:26
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int index = 0;
			for (int i = 0; i < nums.size(); ++i)
				if(nums[i] != 0) nums[index++] = nums[i];
			for(int j=index; j<nums.size(); ++j) nums[j] = 0;
		}
};


int main() {
	Solution s;

	return 0;
}
