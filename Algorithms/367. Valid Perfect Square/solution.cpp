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
	public:
		bool isPerfectSquare(int num) {
			if(num <= 1) return true;
			int lb = 0, ub = num;
			while(ub - lb > 1) { // [lb, ub)
				int mid = (lb + ub) >> 1;
				if((long long)mid * mid <= num) lb = mid;
				else ub = mid;
			}
			return lb * lb == num;
		}
};


int main() {
	Solution s;
	cout << s.isPerfectSquare(808201) << endl;

	return 0;
}
