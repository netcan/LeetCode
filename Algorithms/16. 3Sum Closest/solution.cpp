/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-19 11:56
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
	public:

		int threeSumClosest(vector<int>& nums, int target) {
			int sum = 0;
			if(nums.empty()) return sum;
			int N = nums.size();
			sort(nums.begin(), nums.end());
			if(N <= 3) return accumulate(nums.begin(), nums.end(), 0);

			sum = accumulate(nums.begin(), nums.begin() + 3, 0);
			for (int i = 0; i < N-2; ++i) {
				int l = i+1, r = N - 1;
				while(l < r) {
					int s = nums[i] + nums[l] + nums[r];
					if(abs(target - s) < abs(target - sum)) {
						sum = s;
						if(sum == target) return sum;
					}
					if(s < target) ++l;
					else --r;
				}
			}
			return sum;
		}
};


int main() {
	Solution s;
	vector<int> nums(
			{47,-48,-72,97,-78,50,-22,18,9,24,28,-53,44,-96,50,45,86,11,21,-44,67,83,55,-86,-33,0,-53,-94,-60,57,-72,-73,-27,13,91,80,18,-80,-29,-69,-74,-90,54,22,3,91,-47,-32,80,-55,69,-95,62,-92,4,-86,62,3,23,-30,-4,0,49,24,10,-32,79,-99,-66,-30,-83,-13,90,-27,9,-4,9,98,-70,-19,32,24,-77,83,11,-78,-94,4,41,61,20,96,-36,54,-46,-51,91,54,30,-42,82,0,9,24,-2,32,-16,-18,87,23,78,-10,-82,-67,68,-18,-61,91,-90,-53,67,-48,12,1,-71,-99,31,82,39,-56,23,-89,-58,19,-60,39,-23,-76,-85,67,-33,69,-74,-8,-99,52,-70,-71,85,-8,28,-3,-100,18,88,5,-16,17,91,-35,22,-76}
			);
	cout << s.threeSumClosest(nums, 298) << endl;
	for (int i = 0; i < nums.size(); ++i)
		printf("%d ", nums[i]);
	puts("");

	return 0;
}
