/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 18:42
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> ans;
			for (int i = 0; i < numbers.size(); ++i) {
				int d = target - numbers[i];
				int j = lower_bound(numbers.begin() + i + 1, numbers.end(), d) - numbers.begin();
				if(numbers[j] == d) {
					ans.push_back(i+1);
					ans.push_back(j+1);
					break;
				}
			}
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
