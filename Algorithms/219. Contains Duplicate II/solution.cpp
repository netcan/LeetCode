/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 17:52
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			k = min(k, int(nums.size()) - 1);
			if(k <= 0) return false;
			set<int> s;
			for (int i = 0; i < nums.size(); ++i) {
				if(i > k) s.erase(nums[i-k-1]);
				if(s.find(nums[i]) != s.end()) return true;
				s.insert(nums[i]);
			}
			return false;
		}
};


int main() {
	Solution s;

	return 0;
}
