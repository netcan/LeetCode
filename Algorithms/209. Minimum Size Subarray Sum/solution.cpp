/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 19:27
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int N = nums.size();
			if(N <= 0) return 0;
			int sum[N + 1];
			sum[0] = 0; // [l, r)
			for (int i = 1; i <= N; ++i) sum[i] = sum[i-1] + nums[i-1];

			int ans = numeric_limits<int>::max();
			for(int i=0; i<N; ++i) {
				int j = lower_bound(sum+i, sum+N+1, sum[i]+s) - sum;
				if(j <= N && sum[j] - sum[i] >= s) {
					ans = min(ans, j-i);
				}
			}
			return ans == numeric_limits<int>::max()?0: ans;
		}
};


int main() {
	int n[] = {};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	Solution s;
	cout << s.minSubArrayLen(5, nums) << endl;

	return 0;
}
