/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-18 11:15
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			if(!nums.size()) return 0;
			int lb=0, ub=nums.size(); // [lb, ub)
			if(target <= nums[0]) return 0;
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				if(nums[mid] > target) ub = mid;
				else lb = mid; // <=target
			}
			if(nums[lb] == target) return lb;
			return ub;
		}
};


int main() {
	Solution s;

	return 0;
}
