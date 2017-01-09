/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> index;
			map<int, size_t> hash;
			for(size_t i=0; i<nums.size(); ++i) {
				int j = target - nums[i];
				if(hash.count(j) && hash[j] != i) {
					index.push_back(hash[j]);
					index.push_back(i);
					return index;
				}
				hash[nums[i]] = i;
			}
			return index;
		}
};


int main() {
	Solution s;
	int n[] = {2, 7, 11, 15};
	vector<int> nums(n, n + sizeof(n)/ sizeof(n[0]));
	vector<int> index = s.twoSum(nums, 9);
	for(auto i: index)
		cout << i << endl;

	return 0;
}
