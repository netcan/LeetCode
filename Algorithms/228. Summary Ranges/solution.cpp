/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-12 19:44
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> ans;
			if(!nums.size()) return ans;
			int cur = 0;
			while(cur < nums.size()) {
				int begin = cur, end = cur;
				while(end + 1 < nums.size() && nums[end+1] == nums[end] + 1) ++end;
				if(end > begin) ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
				else ans.push_back(to_string(nums[begin]));
				cur = end + 1;
			}

			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
