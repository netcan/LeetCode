/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 11:25
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int judge(long long ans) {
			if(ans > numeric_limits<int>::max()) return numeric_limits<int>::max();
			else if(ans < numeric_limits<int>::min()) return numeric_limits<int>::min();
			else return ans;
		}
		int myAtoi(string str) {
			long long ans = 0;
			int sign = 1;
			int index = 0;
			while(str[index] == ' ' && ++index);
			if(str[index] == '-') sign = -1;
			for(size_t i=(str[index] == '-' || str[index] == '+')?index+1:index+0; i<str.length(); ++i) {
				int d = str[i] - '0';
				if(d < 0 || d > 9)
					return judge(ans*sign);

				if(ans*10 + d < ans) {// 溢出
					if(sign == 1) return numeric_limits<int>::max();
					else return numeric_limits<int>::min();
				}
				ans = ans*10 + d;
			}
			return judge(ans*sign);
		}
};


int main() {
	Solution s;
	cout << s.myAtoi("9223372036854775809") << endl;

	return 0;
}
