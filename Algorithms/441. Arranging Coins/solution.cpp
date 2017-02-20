/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 09:39
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
	// (1+k)*k/2 = n, return floor(k)
	public:
		int arrangeCoins(int n) {
			return (-1.0+sqrt(8ll*n+1))/2;
		}

};


int main() {
	Solution s;

	return 0;
}
