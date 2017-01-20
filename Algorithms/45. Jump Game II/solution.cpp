/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-20 10:15
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
	public:
		int jump(vector<int>& nums) {
			int step = 0;
			int N = nums.size();
			if(nums.empty() || N < 2) return step;
			int curMaxStep = 0;
			int nextMaxStep = 0;
			int i = 0;
			while(curMaxStep - i + 1 > 0) {
				++step; // 下一步
				for (; i<= curMaxStep; i++) {
					nextMaxStep = max(nextMaxStep, nums[i] + i);
					if(nextMaxStep >= N-1) return step;
				}
				curMaxStep = nextMaxStep;
			}


			return step;
		}

};


int main() {
	Solution s;
	vector<int> nums(
			{7,8,4,2,0,6,4,1,8,7,1,7,4,1,4,1,2,8,2,7,3,7,8,2,4,4,5,3,5,6,8,5,4,4,7,4,3,4,8,1,1,9,0,8,2}
			);
	cout << s.jump(nums) << endl;

	return 0;
}
