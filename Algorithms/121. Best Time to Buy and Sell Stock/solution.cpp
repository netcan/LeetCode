/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 17:29
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int ans = 0;
			int minp = numeric_limits<int>::max();
			for(size_t i=0; i<prices.size(); ++i) {
				minp = min(minp, prices[i]);
				ans = max(prices[i] - minp, ans);
			}
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
