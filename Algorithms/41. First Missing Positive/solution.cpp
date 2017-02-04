/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-04 10:35
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			int N = nums.size();
			if(!N) return 1;
			for (int i = 0; i < N; ++i)
				while(nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i])
					swap(nums[nums[i] - 1] ,nums[i]);

			for (int i = 0; i < N; ++i)
				if(nums[i] != i+1) return i+1;
			return N+1;
		}
};


int main() {
	Solution s;

	return 0;
}
