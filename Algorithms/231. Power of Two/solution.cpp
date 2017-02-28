/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool isPowerOfTwo(int n) {
			if(n <= 0) return false;
			int flag = 0;
			while(n) {
				flag += n & 1;
				n >>= 1;
			}

			return flag == 1;
		}

};


int main() {
	Solution s;

	return 0;
}
