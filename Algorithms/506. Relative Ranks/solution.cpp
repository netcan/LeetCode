/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-05 11:13
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<string> rank;
			if(nums.empty()) return rank;
			vector<int> score = nums;
			sort(score.begin(), score.end(), greater<int>());
			unordered_map<int, string> hash;
			vector<string> top({
					"Gold Medal", "Silver Medal", "Bronze Medal"
					});

			for (int i = 0; i < score.size(); ++i) {
				if(i < top.size())
					hash[score[i]] = top[i];
				else hash[score[i]] = to_string(i+1);
			}

			for(int i=0; i<nums.size(); ++i)
				rank.push_back(hash[nums[i]]);
			return rank;
		}
};


int main() {
	Solution s;

	return 0;
}
