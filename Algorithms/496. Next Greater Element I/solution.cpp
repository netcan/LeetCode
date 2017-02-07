/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-05 10:34
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
			vector<int> ans;
			if(findNums.empty() || nums.empty()) return ans;
			stack<int> s; // 栈维护一个降序序列
			unordered_map<int, int> hash;
			for (int i = 0; i < nums.size(); ++i) {
				while(s.size() && s.top() < nums[i]) {
					hash[s.top()] = nums[i];
					s.pop();
				}
				s.push(nums[i]);
			}
			for(auto &x: findNums)
				if(hash.count(x)) ans.push_back(hash[x]);
				else ans.push_back(-1);

			return ans;
		}
};


int main() {
	Solution s;
	vector<int> findNums({
			2,4
			});
	vector<int> nums({
			1,2,3,4
			});
	vector<int> ans = s.nextGreaterElement(findNums, nums);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}
