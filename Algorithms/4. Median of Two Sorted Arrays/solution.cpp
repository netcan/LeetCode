/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 21:00
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int N = nums1.size() + nums2.size();
			vector<int> merged(N);
			// 归并
			merge(nums1.begin(), nums1.end(),
					nums2.begin(), nums2.end(),
					merged.begin());
			// 返回中位数
			if(N&1) return merged[N >> 1];
			else return (merged[N >> 1] + merged[(N>>1) - 1]) / 2.0;
		}
};


int main() {
	Solution s;
	int n1[] = {1, 2, 3};
	int n2[] = {7,8};
	vector<int> nums1(n1, n1+sizeof(n1)/sizeof(n1[0]));
	vector<int> nums2(n2, n2+sizeof(n2)/sizeof(n2[0]));
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}
