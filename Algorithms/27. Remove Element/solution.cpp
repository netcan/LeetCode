/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 11:39
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		/*
		 * [3, 2, 2, 3]
		 * 3
		 */
		int removeElement(vector<int>& nums, int val) {
			if(nums.size() == 0) return 0;
			int index = 0;
			for (int i = 0; i < nums.size(); ++i)
				if(nums[i] != val) nums[index++] = nums[i];
			return index;
		}

};


int main() {
	int n[] = {1,0,2,3,4,0};
	vector<int> nums(n, n+sizeof(n)/sizeof(n[0]));
	Solution s;
	int N = s.removeElement(nums, 5);
	for(int i=0; i<N; ++i)
		printf("%2d", nums[i]);
	puts("");

	return 0;
}
