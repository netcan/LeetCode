/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 20:59
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> ans;
			bool exist[nums.size() + 1];
			memset(exist, 0, sizeof(exist));
			for (size_t i = 0; i < nums.size(); ++i) exist[nums[i]] = true;
			for(size_t i=1; i<=nums.size(); ++i) if(!exist[i]) ans.push_back(i);
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
