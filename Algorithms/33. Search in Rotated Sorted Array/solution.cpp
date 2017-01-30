/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-30 09:38
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if(nums.empty()) return -1;
			int lb = 0, ub = nums.size(); // [lb, ub)
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				int x = nums[mid];
				// printf("lb = %d mid = %d ub = %d\n", lb, mid, ub);
				// printf("l = %d m = %d u = %d\n", nums[lb], nums[mid], nums[ub - 1]);

				if(x == target) return mid;
				if(x >= nums[lb] && x <= nums[ub - 1]) {
					if(x > target) ub = mid;
					else lb = mid;
				} else if(x >= nums[lb] && x >= nums[ub - 1]) {
					if(x > target) {
						if(target >= nums[lb]) ub = mid;
						else if(target <= nums[ub - 1]) lb = mid;
						else lb = mid;
					}
					else lb = mid;
				} else if(x <= nums[lb] && x <= nums[ub - 1]) {
					if(x > target) ub = mid;
					else {
						if(target <= nums[ub - 1]) lb = mid;
						else if(target >= nums[lb]) ub = mid;
						else lb = mid;
					}
				}
			}
			return nums[lb] == target?lb:-1;
		}
};


int main() {
	Solution s;
	vector<int> nums({3, 5, 1});
	cout << s.search(nums, 2) << endl;

	return 0;
}
