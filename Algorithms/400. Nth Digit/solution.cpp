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
#include <cmath>
using namespace std;

class Solution {
	public:
		int findNthDigit(int n) {
			vector<int> base = {1};
			long long int t = 10, p = 1;
			while(t*10 < INT32_MAX) {
				base.push_back(base.back() + (t - t/10) * p);
				t*=10;
				++p;
			}
			p = upper_bound(base.begin(), base.end(), n) - base.begin() - 1; // 数字n的长度
			n -= (base[p] - 1); // 最终在某个区间第n个数字
			int digit = pow(10, p) - 1 + ceil(n/(p+1.0)); // 最终数字在digit中
			int m = n % (p+1); // 在digit中的第m个数字（从左往右数）
			if(m == 0) m = p+1;
			while(m < p+1) {
				digit/=10;
				++m;
			}
			return digit % 10;
		}

};


int main() {
	Solution s;
	cout << s.findNthDigit(10) << endl;

	return 0;
}
