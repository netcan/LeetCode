/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-18 11:27
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> ans({-1, -1});
			if(!nums.size()) return ans;
			int lb = -1, ub = nums.size()-1; // (lb, ub]
			int l, r;
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				if(nums[mid] >= target) ub = mid;
				else lb = mid; // <
			}
			if(nums[ub] == target) l = ub;
			else return ans;

			lb = 0, ub = nums.size(); // [lb, ub)
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				if(nums[mid] > target) ub = mid;
				else lb = mid; // <=
			}
			if(nums[lb] == target) r = lb;
			else return ans;

			return vector<int>({l, r});
		}
};


int main() {
	Solution s;

	return 0;
}
