/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 10:32
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int N = nums.size();
			vector<vector<int>> ans;
			if(!N) return ans;
			sort(nums.begin(), nums.end());
			unordered_multimap<int, pair<int, int>> hash;

			for (int i = 0; i < N; ++i)
				for (int j = i+1; j < N; ++j)
					hash.insert(pair<int, pair<int, int>>(nums[i]+nums[j], pair<int, int>(i, j)));

			pair<unordered_multimap<int, pair<int, int>>::iterator, unordered_multimap<int, pair<int, int>>::iterator> f;
			for (int i = 0; i < N; ++i)
				for (int j = i+1; j < N; ++j) {
					int d = target - nums[i] - nums[j];
					f = hash.equal_range(d);
					if(f.first != hash.end())
						for(auto k=f.first; k!=f.second; ++k) {
							vector<int> p({nums[i], nums[j], nums[k->second.first], nums[k->second.second]});
							if(k->second.second < i && find(ans.begin(), ans.end(), p) == ans.end())
								ans.push_back(p);
						}
				}

			return ans;
		}
};


int main() {
	Solution s;
	vector<int> nums({1,0,-1,0,-2,2});
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
