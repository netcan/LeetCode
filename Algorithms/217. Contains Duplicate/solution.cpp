/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 22:31
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		bool containsDuplicate(vector<int>& nums) {
			unordered_map<int, bool> exist;
			for (int i = 0; i < nums.size(); i++)
				if(exist[nums[i]]) return true;
				else exist[nums[i]] = true;
			return false;
		}

};


int main() {
	Solution s;

	return 0;
}
