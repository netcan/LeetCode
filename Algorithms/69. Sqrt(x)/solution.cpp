/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	// 求sqrt(x)，牛顿迭代法
	public:
		int mySqrt(int x) {
			if(x == 0) return x;
			long long r = x;
			while(r * r > x) r = (r+x/r) / 2;
			return r;
		}
};


int main() {
	Solution s;

	return 0;
}
