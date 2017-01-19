/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 13:19
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> ans;
			if(nums.empty()) return ans;
			int N = nums.size();
			sort(nums.begin(), nums.end());
			for (int i = 0; i < N-2; ++i) {
				int l = i+1, r = N-1;
				// printf("i=%d l=%d r=%d\n", i, l, r);
				while(l < r) {
					int s = nums[i] + nums[l] + nums[r];
					if(s > 0) --r;
					else if(s < 0) ++l;
					else {
						ans.push_back(vector<int>({nums[i], nums[l], nums[r]}));
						while(l < r && nums[r] == nums[r-1]) --r;
						--r;
					}
				}
				while(i+1 < N && nums[i] == nums[i+1]) ++i;
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<int> nums(
			{0, 0, 0}
			);
	vector<vector<int>> ans = s.threeSum(nums);
	for (int i = 0; i < nums.size(); ++i) {
		printf("%d ", nums[i]);
	}
	puts("");
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[0].size(); ++j) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}

	return 0;
}
