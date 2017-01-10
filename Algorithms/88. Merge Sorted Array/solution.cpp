/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 21:13
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		for(int cur=m+n-1; cur>=0; --cur) {
			if(j >= 0 && i >= 0)
				nums1[cur] = (nums1[i] > nums2[j])?nums1[i--]:nums2[j--];
			else if(j>=0)
				nums1[cur] = nums2[j--];
			else if(i>=0)
				nums1[cur] = nums1[i--];
			else break;
		}
    }
};


int main() {
	Solution s;

	return 0;
}
