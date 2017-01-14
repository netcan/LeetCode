/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-14 10:05
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			if(nums.size() <= 0) return false;
			int lb = 0, ub = nums.size(); // [lb, ub)
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				int left = nums[lb];
				int middle = nums[mid];
				int right = nums[ub - 1];
				if(middle == target) return true;
				if(middle > right) {
					if(middle > target && target >= left) ub = mid;
					else lb = mid;
				} else if(middle < right) {
					if(middle < target && target <= right) lb = mid;
					else ub = mid;
				} else --ub;
	 		}
			return nums[lb] == target;
		}
};


int main() {
	Solution s;

	return 0;
}
