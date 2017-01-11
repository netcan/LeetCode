/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 18:52
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int findPeakElement(vector<int>& nums) {
			int lb = 0, ub = nums.size(); // [lb, ub)
			while(ub - lb > 1) {
				int mid = (ub + lb) >> 1;
				int prev = mid-1>=0?nums[mid-1]:numeric_limits<int>::min();
				int next = mid+1<nums.size()?nums[mid+1]:numeric_limits<int>::min();
				int cur = nums[mid];
				if(prev < cur && cur > next) return mid;
				else if(cur < next) lb = mid;
				else ub = mid;
			}
			return lb;
		}
};


int main() {
	int n[] = {1, 2, 3, 1};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	Solution s;
	cout << s.findPeakElement(nums) << endl;

	return 0;
}
