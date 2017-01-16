/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-16 19:21
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
	public:
		int missingNumber(vector<int>& nums) {
			int N = nums.size();
			if(!N) return 0;
			int sum =  0;
			for (int i = 0; i < N; ++i) sum += nums[i];
			return (N*(N+1) >> 1) - sum;
		}
};


int main() {
	Solution s;
	vector<int> n{26,64,7,83,86,73,45,15,56,84,82,38,48,76,1,0,28,77,47,24,42,19,46,57,79,35,50,74,99,11,17,13,95,55,81,18,34,70,67,75,66,2,96,49,53,30,78,25,52,89,58,80,16,31,43,85,51,61,62,8,44,10,4,98,90,97,68,37,59,69,63,33,72,21,88,27,39,94,14,87,22,41,65,3,9,60,23,12,40,93,36,92,6,32,29,71,5,91,20};
	cout << s.missingNumber(n) << endl;

	return 0;
}
