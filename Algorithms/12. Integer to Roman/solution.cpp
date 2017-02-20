/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 10:37
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		string intToRoman(int num) {
			vector<pair<string, int>> roman({
					{"M", 1000},
					{"CM", 900},
					{"D", 500},
					{"CD", 400},
					{"C", 100},
					{"XC", 90},
					{"L", 50},
					{"XL", 40},
					{"X", 10},
					{"IX", 9},
					{"V", 5},
					{"IV", 4},
					{"I", 1},
					});
			string ans;
			int i = 0;
			while(i < roman.size() && num) {
				while(num >= roman[i].second) {
					ans += roman[i].first;
					num -= roman[i].second;
				}
				++i;
			}
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
