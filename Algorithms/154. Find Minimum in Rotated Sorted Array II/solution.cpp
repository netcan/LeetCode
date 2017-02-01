/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 2017-02-01 10:32
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findMin(vector<int>& nums) {
			if(nums.empty()) return 0;
			if(nums.size() == 1) return nums[0];
			int lb = 0, ub = nums.size() - 1; // [lb, ub]

			while(ub - lb > 0) {
				int mid = (ub + lb) >> 1;
				int left = nums[lb];
				int middle = nums[mid];
				int right = nums[ub];
				if(middle > right) lb = mid + 1;
				else if(middle < right) ub = mid;
				else --ub;
				// printf("lb=%d mid=%d ub=%d\n", lb, mid, ub);
			}
			return nums[lb];
		}
};


int main() {
	Solution s;
	vector<int> nums({3,1});
	cout << s.findMin(nums) << endl;

	return 0;
}
