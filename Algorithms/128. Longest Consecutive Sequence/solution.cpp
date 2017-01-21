/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-21 10:14
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			int ans = 0;
			int N = nums.size();
			if(!N) return ans;
			unordered_map<int, int>hash; // 记录区间内n的长度
			for(auto &n: nums) {
				if(! hash.count(n)) {
					int left = hash.count(n-1)?hash[n-1]:0;
					int right = hash.count(n+1)?hash[n+1]:0;
					int cnt = left + right + 1;
					ans = max(ans, cnt);
					hash[n] = cnt;
					hash[n-left] = cnt; // 更新端点
					hash[n+right] = cnt;
				}
			}
			return ans;
		}

};


int main() {
	Solution s;

	return 0;
}
