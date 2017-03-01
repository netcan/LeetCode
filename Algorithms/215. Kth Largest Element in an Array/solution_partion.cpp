/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int partion(vector<int>& nums, int left, int right) {
			// int pivot = nums[left];
			int l = left + 1, r = right;
			while(l <= r) {
				while(l<=r && nums[l] >= nums[left]) ++l;
				while(r>=l && nums[r] <= nums[left]) --r;
				if(l <= r) swap(nums[l], nums[r]);
			}
			swap(nums[r], nums[left]);
			return r;
		}

		int findKthLargest(vector<int>& nums, int k) {
			if(nums.empty()) return -1;
			int left = 0, right = nums.size() - 1;
			while(true) {
				int pos = partion(nums, left, right);
				if(pos + 1 == k) return nums[pos];
				else if(pos + 1 > k) right = pos - 1;
				else left = pos + 1;
			}
		}
};


int main() {
	Solution s;

	return 0;
}
