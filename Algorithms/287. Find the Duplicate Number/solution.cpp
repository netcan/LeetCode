
/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-22 11:25
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int ans = 0;
			if(nums.empty()) return ans;
			int slow = nums[0];
			int fast = nums[nums[0]];
			while(slow != fast) {
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			fast = 0;
			while(fast != slow) {
				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
		}
};


int main() {
	Solution s;
	vector<int> nums(
			{1,2,3,4,5,5}
			);
	cout << s.findDuplicate(nums) << endl;
	return 0;
}
