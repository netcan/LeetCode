/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-16 10:37
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		// 寻找最长连续的1的长度，数组只有0，1
		int findMaxConsecutiveOnes(vector<int>& nums) {
			if(!nums.size()) return 0;
			int cnt = 0;
			int t = 0;
			for(auto &n: nums) {
				t = (t+n) * n;
				cnt = max(cnt, t);
			}
			return cnt;
		}
};


int main() {
	Solution s;

	return 0;
}
