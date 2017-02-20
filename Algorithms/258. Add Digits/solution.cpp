/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 09:06
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	// x = 9*k + d，求d, 1<=d<=9
	public:
		int addDigits(int num) {
			if(num == 0) return 0;
			if(num % 9 == 0) return 9;
			else return num % 9;
		}
};


int main() {
	Solution s;

	return 0;
}
