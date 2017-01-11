/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 20:09
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findMin(vector<int>& nums) {
			int N = nums.size();
			int lb = 0, ub = N;
			if(nums[ub-1] >= nums[lb]) return nums[lb];
			while(ub - lb > 1) {
				int mid = (lb + ub) >> 1;
				if(nums[mid] > nums[lb]) lb = mid;
				else ub = mid;

			}
			return nums[ub];
		}
};


int main() {
	int n[] = {1};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	Solution s;
	cout << s.findMin(nums) << endl;

	return 0;
}
