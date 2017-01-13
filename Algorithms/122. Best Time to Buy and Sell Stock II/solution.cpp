/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-13 11:07
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if(!prices.size()) return 0;
			int ans = 0;
			int minP = prices[0];
			int day = 0;
			int end = 0;
			while(day < prices.size()) {
				end = day;
				while(end + 1 < prices.size() && prices[end+1] >= prices[end]) ++end;
				ans += max(prices[end] - minP, 0);
				if(day < end + 1) day = end+1;
				else ++day;
				minP = prices[day];
			}
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
