/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ans;
			if(nums.empty()) return ans;
			sort(nums.begin(), nums.end());
			int N = nums.size();
			for (int i = 0; i < N; ++i) {
				for (int j = i+1; j < N; ++j) {
					int d = nums[i] + nums[j];
					int l=j+1, h=N-1;
					while(l < h) {
						int s = nums[l] + nums[h];
						if(s + d > target) --h;
						else if(s+d < target) ++l;
						else {
							ans.push_back(vector<int>({nums[i], nums[j], nums[l], nums[h]}));
							--h;
						}
						while(l < h && h+1<N && nums[h] == nums[h+1]) --h;
						// while(l < h && nums[l] == nums[l+1]) ++l;
					}

					while(j+1 < N && nums[j] == nums[j+1]) ++j;
				}
				while(i+1 < N && nums[i] == nums[i+1]) ++i;
			}
			return ans;
		}

};


int main() {
	Solution s;
	vector<int> nums({1,4,-3,0,0,0,5,0});
	vector<vector<int>> ans = s.fourSum(nums, 0);
	for (int i = 0; i < nums.size(); ++i)
		printf("%d ", nums[i]);
	puts("");

	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}


	return 0;
}
