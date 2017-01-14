/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-14 09:44
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> ans;
			int N = nums.size();
			if(N <= 0) return ans;
			for(int i=0; i<1<<N; ++i) {
				vector<int> p;
				for(int j=0; j<N; ++j)
					if(i & (1 << j)) p.push_back(nums[j]);
				ans.push_back(p);
			}
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
