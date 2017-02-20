/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 09:27
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
	// 找出最少步骤使得数组所有元素都相等，每步n-1个数+1，设初始和为sum，最小值为min，最终数为x，步数为s
	// sum + s*(n-1) = n * x
	// x = min + s
	// s = sum - n * min
	public:
		int minMoves(vector<int>& nums) {
			return accumulate(nums.begin(), nums.end(), 0ll) - nums.size() * *min_element(nums.begin(), nums.end());
		}

};


int main() {
	Solution s;

	return 0;
}
