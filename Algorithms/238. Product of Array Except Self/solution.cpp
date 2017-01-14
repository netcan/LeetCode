/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-14 09:49
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> output(nums.size(), 1);
			for (int i = 1; i < nums.size(); ++i)
				output[i] = output[i-1] * nums[i-1];
			int rightProduct = 1;
			for(int i=nums.size() - 1; i>=0; --i) {
				output[i] *= rightProduct;
				rightProduct *= nums[i];
			}
			return output;
		}
};


int main() {
	Solution s;

	return 0;
}
