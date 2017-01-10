/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 12:25
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool isPalindrome(int x) {
			long long y = 0;
			int xx = x;
			while(xx) {
				y = y*10 + xx % 10;
				xx /= 10;
			}
			return x>=0 && x == y;
		}
};


int main() {
	Solution s;
	cout << s.isPalindrome(1) << endl;

	return 0;
}
