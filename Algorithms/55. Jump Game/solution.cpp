/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-17 10:15
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int N = nums.size();
			if(!N) return false;
			bool jump[N];
			memset(jump, 0, sizeof(jump));
			jump[0] = true;
			for (int i = 0; i < N; ++i) {
				if(jump[i]) {
					if(nums[i] + i >= N - 1) return true;
					else for (int j = 1;j <= nums[i]; ++j) jump[i+j] = true;
				}
			}
			return jump[N-1];
		}
};


int main() {
	Solution s;
	vector<int> nums({5,4,0,2,0,1,0,1,0});
	cout << s.canJump(nums) << endl;

	return 0;
}
