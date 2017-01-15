/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-15 11:15
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int red = 0, white = 0, blue = 0;
			for(int i=0; i<nums.size(); ++i)
				if(nums[i] == 0) ++red;
				else if(nums[i] == 1) ++white;
				else ++blue;
			for(int i=0; i<nums.size(); ++i)
				if(i >= 0 && i < red) nums[i] = 0;
				else if(i>=red && i<red+white) nums[i] = 1;
				else nums[i] = 2;

		}

};


int main() {
	Solution s;

	return 0;
}
