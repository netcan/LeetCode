/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-14 11:14
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int cnt = 0;
			if(!nums.size()) return 0;
			int pos = 0;
			while(pos < nums.size()) {
				int end = pos;
				while(end + 1 < nums.size() && nums[end] == nums[end+1]) ++end;
				nums[cnt++] = nums[end];
				if(end - pos > 0) nums[cnt++] = nums[end];
				pos = end + 1;
			}
			return cnt;
		}
};


int main() {
	Solution s;
	int n[] = {1,1,1,2,2,3};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	cout << s.removeDuplicates(nums) << endl;

	return 0;
}
