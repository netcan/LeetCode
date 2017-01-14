/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-14 09:26
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>> ans;
			sort(nums.begin(), nums.end());
			int N = nums.size();
			if(N <= 0) return ans;
			for(int i=0; i<1<<N; ++i) {
				vector<int> p;
				for(int j=0; j<N; ++j)
					if(i & (1<<j)) p.push_back(nums[j]);
				if(find(ans.begin(), ans.end(), p) == ans.end()) ans.push_back(p);
			}

			return ans;
		}
};


int main() {
	Solution s;
	int n[] = {1, 2, 3};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	s.subsetsWithDup(nums);

	return 0;
}
