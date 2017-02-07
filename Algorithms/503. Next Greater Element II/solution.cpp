/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-05 11:13
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<int> nextGreaterElements(vector<int>& nums) {
			if(nums.empty()) return vector<int>();
			int N = nums.size();
			vector<int> ans(N, -1);
			stack<int> s; // 维护一个降序序列
			for (int i = 0; i < N * 2; ++i) {
				while(s.size() && nums[s.top()] < nums[i % N]) {
					ans[s.top()] = nums[i % N];
					s.pop();
				}
				if(i < N) s.push(i);
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<int> nums({
			1,2,1
			});
	vector<int> ans = s.nextGreaterElements(nums);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}
