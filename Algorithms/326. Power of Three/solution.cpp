/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
	public:
		bool isPowerOfThree(int n) {
			if(n <= 0) return false;
			const int MAX3POWER =  1162261467; // 3^19
			return MAX3POWER % n == 0;
		}

};


int main() {
	Solution s;
	cout << s.isPowerOfThree(1000) << endl;

	return 0;
}
