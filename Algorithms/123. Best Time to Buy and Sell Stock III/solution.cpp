/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-22 10:26
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int ans = 0;
			if(prices.empty()) return ans;
			int buy1 = numeric_limits<int>::min(); // 第一笔购买
			int sell1 = 0; // 第一笔卖出
			int buy2 = numeric_limits<int>::min(); // 第二笔购买
			int sell2 = 0; // 第二笔卖出
			for(auto &p: prices) {
				buy1 = max(buy1, -p);
				sell1 = max(sell1, buy1 + p);
				buy2 = max(buy2, sell1 - p);
				sell2 = max(sell2, buy2 + p);
			}
			return sell2;
		}
};


int main() {
	Solution s;

	return 0;
}
