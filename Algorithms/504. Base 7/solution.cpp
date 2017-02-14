/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-14 10:21
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
	public:
		string convertToBase7(int num) {
			stack<int> s;
			bool flag = num>=0;
			string ans;
			if(!flag) num = -num;
			if(num == 0) return to_string(0);
			while(num) {
				ans.insert(ans.begin(), num%7+'0');
				num /= 7;
			}
			if(!flag) ans.insert(ans.begin(), '-');
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
