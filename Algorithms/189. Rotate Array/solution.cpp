/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 20:28
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		void rotate(vector<int>& nums, int k) {
			int N = nums.size();
			k %= N;
			if(k <= 0) return;
			reverse(nums.begin(), nums.begin() + N-k);
			reverse(nums.begin() + N-k, nums.end());
			reverse(nums.begin(), nums.end());
		}
};


int main() {
	Solution s;

	return 0;
}
