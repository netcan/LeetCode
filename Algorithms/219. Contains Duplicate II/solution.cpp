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
#include <unordered_map>
using namespace std;

class Solution {
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_map<int,int> hash;
			for (int i = 0; i < nums.size(); ++i) {
				if(hash.count(nums[i]) && abs(i - hash[nums[i]]) <= k) return true;
				hash[nums[i]] = i;
			}
			return false;
		}
};


int main() {
	Solution s;

	return 0;
}
