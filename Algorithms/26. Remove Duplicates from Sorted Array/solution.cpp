/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 18:12
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			if(nums.size() <= 0) return 0;
			int index = 1;
			for(int i=1; i<nums.size(); ++i)
				if(nums[i] != nums[i-1]) nums[index++] = nums[i];
			return index;
		}
};


int main() {
	Solution s;

	return 0;
}
