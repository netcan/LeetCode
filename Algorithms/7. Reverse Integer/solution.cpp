/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 11:10
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int reverse(int x) {
			long long ans = 0;
			while(x) {
				ans = ans * 10 + x%10;
				x /= 10;
			}
			if(ans > numeric_limits<int>::max() || ans < numeric_limits<int>::min()) return 0;
			return ans;
		}
};


int main() {
	Solution s;
	cout << s.reverse(1534236469) << endl;

	return 0;
}
