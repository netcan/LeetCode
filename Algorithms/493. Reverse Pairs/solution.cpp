/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		// 求逆序对，归并排序
		int reversePairsCnt(vector<long long>::iterator s, vector<long long>::iterator e) {
			if(e - s < 2) return 0;
			vector<long long>::iterator m = s + distance(s, e)/2;
			int cnt = reversePairsCnt(s, m) + reversePairsCnt(m, e);
			sort(s, m); // 排序左半部分
			for(auto i = m; i < e; ++i)
				cnt += m - upper_bound(s, m, 2 * *i);
			return cnt;
		}

		int reversePairs(vector<int>& nums) {
			vector<long long> a(nums.begin(), nums.end());
			return reversePairsCnt(a.begin(), a.end());
		}

};


int main() {
	Solution s;
	vector<int> nums({
			2,4,3,5,1
			});
	cout << s.reversePairs(nums) << endl;

	return 0;
}
