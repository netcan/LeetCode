/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 09:44
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int N = nums.size();
			if(!N || N == 1) return;
			int i = N - 2, j = N-1;
			while(i>0 && !(nums[i] < nums[i+1])) --i;

			if(i == 0 && !(nums[i] < nums[i+1])) reverse(nums.begin(), nums.end());
			else {
				while(j > i && !(nums[i] < nums[j])) --j;
				swap(nums[i], nums[j]);
				reverse(nums.begin()+i+1, nums.end());
			}
		}
};


int main() {
	Solution s;
	vector<int> nums = {1,2};
	s.nextPermutation(nums);
	for (int i = 0; i < nums.size(); ++i) printf("%d ", nums[i]);
	puts("");

	return 0;
}
