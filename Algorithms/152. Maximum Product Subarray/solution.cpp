/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-12 09:54
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int maxN = nums[0];
			int minN = nums[0];
			int ans = nums[0];
			for(int i=1; i<nums.size(); ++i) {
				int maxNPrev = maxN;
				maxN = max(max(maxN * nums[i], minN * nums[i]), nums[i]);
				minN = min(min(maxNPrev * nums[i], minN * nums[i]), nums[i]);
				ans = max(maxN, ans);
			}
			return ans;
		}
};


int main() {
	int n[] = {-4, -3, -2};
	vector<int> nums(n, n+sizeof(n)/sizeof(int));
	Solution s;
	cout << s.maxProduct(nums) << endl;


	return 0;
}
